/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MINIKIN_FONT_COLLECTION_H
#define MINIKIN_FONT_COLLECTION_H

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <gtest/gtest_prod.h>

#include "minikin/Buffer.h"
#include "minikin/Font.h"
#include "minikin/FontFamily.h"
#include "minikin/MinikinFont.h"
#include "minikin/U16StringPiece.h"

namespace minikin {

// The maximum number of font families.
constexpr uint32_t MAX_FAMILY_COUNT = 254;

class FontCollection {
public:
    explicit FontCollection(const std::vector<std::shared_ptr<FontFamily>>& typefaces);
    explicit FontCollection(std::shared_ptr<FontFamily>&& typeface);

    template <Font::TypefaceReader typefaceReader>
    static std::vector<std::shared_ptr<FontCollection>> readVector(BufferReader* reader) {
        uint32_t allFontFamiliesCount = reader->read<uint32_t>();
        std::vector<std::shared_ptr<FontFamily>> allFontFamilies;
        allFontFamilies.reserve(allFontFamiliesCount);
        for (uint32_t i = 0; i < allFontFamiliesCount; i++) {
            allFontFamilies.push_back(FontFamily::readFrom<typefaceReader>(reader));
        }
        uint32_t fontCollectionsCount = reader->read<uint32_t>();
        std::vector<std::shared_ptr<FontCollection>> fontCollections;
        fontCollections.reserve(fontCollectionsCount);
        for (uint32_t i = 0; i < fontCollectionsCount; i++) {
            fontCollections.emplace_back(new FontCollection(reader, allFontFamilies));
        }
        return fontCollections;
    }

    template <Font::TypefaceWriter typefaceWriter>
    static void writeVector(BufferWriter* writer,
                            const std::vector<std::shared_ptr<FontCollection>>& fontCollections) {
        std::vector<std::shared_ptr<FontFamily>> allFontFamilies;
        // Note: operator== for shared_ptr compares raw pointer values.
        std::unordered_map<std::shared_ptr<FontFamily>, uint32_t> fontFamilyToIndexMap;
        collectAllFontFamilies(fontCollections, &allFontFamilies, &fontFamilyToIndexMap);

        writer->write<uint32_t>(allFontFamilies.size());
        for (const auto& fontFamily : allFontFamilies) {
            fontFamily->writeTo<typefaceWriter>(writer);
        }
        writer->write<uint32_t>(fontCollections.size());
        for (const auto& fontCollection : fontCollections) {
            fontCollection->writeTo(writer, fontFamilyToIndexMap);
        }
    }

    // Helper class for representing font family match result in packed bits.
    struct FamilyMatchResult {
    public:
        struct Builder {
        public:
            Builder() : mSize(0), mBits(0) {}

            Builder& add(uint8_t x) {
                if (mSize >= 7) [[unlikely]] {
                        return *this;
                    }
                mBits = mBits | (static_cast<uint64_t>(x) << (8 * mSize));
                mSize++;
                return *this;
            }

            Builder& reset() {
                mSize = 0;
                mBits = 0;
                return *this;
            }

            uint8_t size() const { return mSize; }

            bool empty() const { return size() == 0; }

            FamilyMatchResult build() {
                return FamilyMatchResult(mBits | (static_cast<uint64_t>(mSize) << 56));
            }

        private:
            uint8_t mSize;
            uint64_t mBits;
        };

        // Helper class for iterating FamilyMatchResult
        class iterator {
        public:
            inline bool operator==(const iterator& o) const {
                return mOffset == o.mOffset && mResult == o.mResult;
            }

            inline bool operator!=(const iterator& o) const { return !(*this == o); }
            inline uint8_t operator*() const { return mResult[mOffset]; }
            inline iterator& operator++() {
                mOffset++;
                return *this;
            }

        private:
            friend struct FamilyMatchResult;
            iterator(const FamilyMatchResult& result, uint32_t offset)
                    : mResult(result), mOffset(offset) {}
            const FamilyMatchResult& mResult;
            uint32_t mOffset;
        };

        // Create empty FamilyMatchResult.
        FamilyMatchResult() : mBits(0) {}

        inline uint8_t size() const { return static_cast<uint8_t>(mBits >> 56); }

        inline uint8_t operator[](uint32_t pos) const {
            return static_cast<uint8_t>(mBits >> (pos * 8));
        }

        inline bool empty() const { return size() == 0; }

        inline bool operator==(const FamilyMatchResult& o) const { return mBits == o.mBits; }

        // Returns the common family indices between l and r.
        static FamilyMatchResult intersect(FamilyMatchResult l, FamilyMatchResult r);

        // Iterator
        inline iterator begin() const { return iterator(*this, 0); }
        inline iterator end() const { return iterator(*this, size()); }

        FamilyMatchResult(const FamilyMatchResult& o) = default;
        FamilyMatchResult& operator=(const FamilyMatchResult& o) = default;

    private:
        explicit FamilyMatchResult(uint64_t bits) : mBits(bits) {}
        uint64_t mBits;
    };

    struct Run {
        FamilyMatchResult familyMatch;
        int start;
        int end;
    };

    FakedFont getBestFont(U16StringPiece textBuf, const Run& run, FontStyle style);

    // Perform the itemization until given max runs.
    std::vector<Run> itemize(U16StringPiece text, FontStyle style, uint32_t localeListId,
                             FamilyVariant familyVariant, uint32_t runMax) const;

    // Perform the itemization until end of the text.
    std::vector<Run> itemize(U16StringPiece text, FontStyle style, uint32_t localeListId,
                             FamilyVariant familyVariant) const {
        return itemize(text, style, localeListId, familyVariant, text.size());
    }

    // Returns true if there is a glyph for the code point and variation selector pair.
    // Returns false if no fonts have a glyph for the code point and variation
    // selector pair, or invalid variation selector is passed.
    bool hasVariationSelector(uint32_t baseCodepoint, uint32_t variationSelector) const;

    // Get base font with fakery information (fake bold could affect metrics)
    FakedFont baseFontFaked(FontStyle style);

    // Creates new FontCollection based on this collection while applying font variations. Returns
    // nullptr if none of variations apply to this collection.
    std::shared_ptr<FontCollection> createCollectionWithVariation(
            const std::vector<FontVariation>& variations);

    const std::unordered_set<AxisTag>& getSupportedTags() const { return mSupportedAxes; }

    uint32_t getId() const;

    const std::vector<std::shared_ptr<FontFamily>>& getFamilies() const { return mFamilies; }

private:
    FRIEND_TEST(FontCollectionTest, bufferTest);

    FontCollection(BufferReader* reader,
                   const std::vector<std::shared_ptr<FontFamily>>& allFontFamilies);
    // Write fields of the instance, using fontFamilyToIndexMap for finding
    // indices for FontFamily.
    void writeTo(BufferWriter* writer,
                 const std::unordered_map<std::shared_ptr<FontFamily>, uint32_t>&
                         fontFamilyToIndexMap) const;
    static void collectAllFontFamilies(
            const std::vector<std::shared_ptr<FontCollection>>& fontCollections,
            std::vector<std::shared_ptr<FontFamily>>* outAllFontFamilies,
            std::unordered_map<std::shared_ptr<FontFamily>, uint32_t>* outFontFamilyToIndexMap);

    static const int kLogCharsPerPage = 8;
    static const int kPageMask = (1 << kLogCharsPerPage) - 1;

    // mFamilyVec holds the indices of the mFamilies and mRanges holds the range of indices of
    // mFamilyVec. The maximum number of pages is 0x10FF (U+10FFFF >> 8). The maximum number of
    // the fonts is 0xFF. Thus, technically the maximum length of mFamilyVec is 0x10EE01
    // (0x10FF * 0xFF). However, in practice, 16-bit integers are enough since most fonts supports
    // only limited range of code points.
    struct Range {
        uint16_t start;
        uint16_t end;
    };

    // Initialize the FontCollection.
    void init(const std::vector<std::shared_ptr<FontFamily>>& typefaces);

    FamilyMatchResult getFamilyForChar(uint32_t ch, uint32_t vs, uint32_t localeListId,
                                       FamilyVariant variant) const;

    uint32_t calcFamilyScore(uint32_t ch, uint32_t vs, FamilyVariant variant, uint32_t localeListId,
                             const std::shared_ptr<FontFamily>& fontFamily) const;

    uint32_t calcCoverageScore(uint32_t ch, uint32_t vs, uint32_t localeListId,
                               const std::shared_ptr<FontFamily>& fontFamily) const;

    static uint32_t calcLocaleMatchingScore(uint32_t userLocaleListId,
                                            const FontFamily& fontFamily);

    static uint32_t calcVariantMatchingScore(FamilyVariant variant, const FontFamily& fontFamily);

    // unique id for this font collection (suitable for cache key)
    uint32_t mId;

    // Highest UTF-32 code point that can be mapped
    uint32_t mMaxChar;

    // This vector has pointers to the all font family instances in this collection.
    // This vector can't be empty.
    std::vector<std::shared_ptr<FontFamily>> mFamilies;

    // Following two vectors are pre-calculated tables for resolving coverage faster.
    // For example, to iterate over all fonts which support Unicode code point U+XXYYZZ,
    // iterate font families index from mFamilyVec[mRanges[0xXXYY].start] to
    // mFamilyVec[mRange[0xXXYY].end] instead of whole mFamilies.
    // This vector contains indices into mFamilies.
    // This vector can't be empty.
    uint32_t mRangesCount;
    const Range* mRanges;
    uint32_t mFamilyVecCount;
    const uint8_t* mFamilyVec;

    // This vector has pointers to the font family instances which have cmap 14 subtables.
    std::vector<std::shared_ptr<FontFamily>> mVSFamilyVec;

    // Set of supported axes in this collection.
    std::unordered_set<AxisTag> mSupportedAxes;

    // Owns allocated memory if this class is created from font families, otherwise these are
    // nullptr.
    std::unique_ptr<Range[]> mOwnedRanges;
    std::vector<uint8_t> mOwnedFamilyVec;
};

}  // namespace minikin

#endif  // MINIKIN_FONT_COLLECTION_H

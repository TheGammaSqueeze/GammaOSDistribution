/*
 * Copyright (C) 2011 The Android Open Source Project
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

#include "image_writer.h"

#include <lz4.h>
#include <lz4hc.h>
#include <sys/stat.h>
#include <zlib.h>

#include <memory>
#include <numeric>
#include <vector>

#include "art_field-inl.h"
#include "art_method-inl.h"
#include "base/callee_save_type.h"
#include "base/enums.h"
#include "base/globals.h"
#include "base/logging.h"  // For VLOG.
#include "base/stl_util.h"
#include "base/unix_file/fd_file.h"
#include "class_linker-inl.h"
#include "class_root-inl.h"
#include "compiled_method.h"
#include "dex/dex_file-inl.h"
#include "dex/dex_file_types.h"
#include "driver/compiler_options.h"
#include "elf/elf_utils.h"
#include "elf_file.h"
#include "entrypoints/entrypoint_utils-inl.h"
#include "gc/accounting/card_table-inl.h"
#include "gc/accounting/heap_bitmap.h"
#include "gc/accounting/space_bitmap-inl.h"
#include "gc/collector/concurrent_copying.h"
#include "gc/heap-visit-objects-inl.h"
#include "gc/heap.h"
#include "gc/space/large_object_space.h"
#include "gc/space/region_space.h"
#include "gc/space/space-inl.h"
#include "gc/verification.h"
#include "handle_scope-inl.h"
#include "image-inl.h"
#include "imt_conflict_table.h"
#include "intern_table-inl.h"
#include "jni/jni_internal.h"
#include "linear_alloc.h"
#include "lock_word.h"
#include "mirror/array-inl.h"
#include "mirror/class-inl.h"
#include "mirror/class_ext-inl.h"
#include "mirror/class_loader.h"
#include "mirror/dex_cache-inl.h"
#include "mirror/dex_cache.h"
#include "mirror/executable.h"
#include "mirror/method.h"
#include "mirror/object-inl.h"
#include "mirror/object-refvisitor-inl.h"
#include "mirror/object_array-alloc-inl.h"
#include "mirror/object_array-inl.h"
#include "mirror/string-inl.h"
#include "nterp_helpers.h"
#include "oat.h"
#include "oat_file.h"
#include "oat_file_manager.h"
#include "optimizing/intrinsic_objects.h"
#include "runtime.h"
#include "scoped_thread_state_change-inl.h"
#include "subtype_check.h"
#include "well_known_classes.h"

using ::art::mirror::Class;
using ::art::mirror::DexCache;
using ::art::mirror::Object;
using ::art::mirror::ObjectArray;
using ::art::mirror::String;

namespace art {
namespace linker {

// The actual value of `kImageClassTableMinLoadFactor` is irrelevant because image class tables
// are never resized, but we still need to pass a reasonable value to the constructor.
constexpr double kImageClassTableMinLoadFactor = 0.5;
// We use `kImageClassTableMaxLoadFactor` to determine the buffer size for image class tables
// to make them full. We never insert additional elements to them, so we do not want to waste
// extra memory. And unlike runtime class tables, we do not want this to depend on runtime
// properties (see `Runtime::GetHashTableMaxLoadFactor()` checking for low memory mode).
constexpr double kImageClassTableMaxLoadFactor = 0.7;

// The actual value of `kImageInternTableMinLoadFactor` is irrelevant because image intern tables
// are never resized, but we still need to pass a reasonable value to the constructor.
constexpr double kImageInternTableMinLoadFactor = 0.5;
// We use `kImageInternTableMaxLoadFactor` to determine the buffer size for image intern tables
// to make them full. We never insert additional elements to them, so we do not want to waste
// extra memory. And unlike runtime intern tables, we do not want this to depend on runtime
// properties (see `Runtime::GetHashTableMaxLoadFactor()` checking for low memory mode).
constexpr double kImageInternTableMaxLoadFactor = 0.7;

static ArrayRef<const uint8_t> MaybeCompressData(ArrayRef<const uint8_t> source,
                                                 ImageHeader::StorageMode image_storage_mode,
                                                 /*out*/ std::vector<uint8_t>* storage) {
  const uint64_t compress_start_time = NanoTime();

  switch (image_storage_mode) {
    case ImageHeader::kStorageModeLZ4: {
      storage->resize(LZ4_compressBound(source.size()));
      size_t data_size = LZ4_compress_default(
          reinterpret_cast<char*>(const_cast<uint8_t*>(source.data())),
          reinterpret_cast<char*>(storage->data()),
          source.size(),
          storage->size());
      storage->resize(data_size);
      break;
    }
    case ImageHeader::kStorageModeLZ4HC: {
      // Bound is same as non HC.
      storage->resize(LZ4_compressBound(source.size()));
      size_t data_size = LZ4_compress_HC(
          reinterpret_cast<const char*>(const_cast<uint8_t*>(source.data())),
          reinterpret_cast<char*>(storage->data()),
          source.size(),
          storage->size(),
          LZ4HC_CLEVEL_MAX);
      storage->resize(data_size);
      break;
    }
    case ImageHeader::kStorageModeUncompressed: {
      return source;
    }
    default: {
      LOG(FATAL) << "Unsupported";
      UNREACHABLE();
    }
  }

  DCHECK(image_storage_mode == ImageHeader::kStorageModeLZ4 ||
         image_storage_mode == ImageHeader::kStorageModeLZ4HC);
  VLOG(compiler) << "Compressed from " << source.size() << " to " << storage->size() << " in "
                 << PrettyDuration(NanoTime() - compress_start_time);
  if (kIsDebugBuild) {
    std::vector<uint8_t> decompressed(source.size());
    const size_t decompressed_size = LZ4_decompress_safe(
        reinterpret_cast<char*>(storage->data()),
        reinterpret_cast<char*>(decompressed.data()),
        storage->size(),
        decompressed.size());
    CHECK_EQ(decompressed_size, decompressed.size());
    CHECK_EQ(memcmp(source.data(), decompressed.data(), source.size()), 0) << image_storage_mode;
  }
  return ArrayRef<const uint8_t>(*storage);
}

// Separate objects into multiple bins to optimize dirty memory use.
static constexpr bool kBinObjects = true;

ObjPtr<mirror::ObjectArray<mirror::Object>> AllocateBootImageLiveObjects(
    Thread* self, Runtime* runtime) REQUIRES_SHARED(Locks::mutator_lock_) {
  ClassLinker* class_linker = runtime->GetClassLinker();
  // The objects used for the Integer.valueOf() intrinsic must remain live even if references
  // to them are removed using reflection. Image roots are not accessible through reflection,
  // so the array we construct here shall keep them alive.
  StackHandleScope<1> hs(self);
  Handle<mirror::ObjectArray<mirror::Object>> integer_cache =
      hs.NewHandle(IntrinsicObjects::LookupIntegerCache(self, class_linker));
  size_t live_objects_size =
      enum_cast<size_t>(ImageHeader::kIntrinsicObjectsStart) +
      ((integer_cache != nullptr) ? (/* cache */ 1u + integer_cache->GetLength()) : 0u);
  ObjPtr<mirror::ObjectArray<mirror::Object>> live_objects =
      mirror::ObjectArray<mirror::Object>::Alloc(
          self, GetClassRoot<mirror::ObjectArray<mirror::Object>>(class_linker), live_objects_size);
  int32_t index = 0u;
  auto set_entry = [&](ImageHeader::BootImageLiveObjects entry,
                       ObjPtr<mirror::Object> value) REQUIRES_SHARED(Locks::mutator_lock_) {
    DCHECK_EQ(index, enum_cast<int32_t>(entry));
    live_objects->Set</*kTransacrionActive=*/ false>(index, value);
    ++index;
  };
  set_entry(ImageHeader::kOomeWhenThrowingException,
            runtime->GetPreAllocatedOutOfMemoryErrorWhenThrowingException());
  set_entry(ImageHeader::kOomeWhenThrowingOome,
            runtime->GetPreAllocatedOutOfMemoryErrorWhenThrowingOOME());
  set_entry(ImageHeader::kOomeWhenHandlingStackOverflow,
            runtime->GetPreAllocatedOutOfMemoryErrorWhenHandlingStackOverflow());
  set_entry(ImageHeader::kNoClassDefFoundError, runtime->GetPreAllocatedNoClassDefFoundError());
  set_entry(ImageHeader::kClearedJniWeakSentinel, runtime->GetSentinel().Read());

  DCHECK_EQ(index, enum_cast<int32_t>(ImageHeader::kIntrinsicObjectsStart));
  if (integer_cache != nullptr) {
    live_objects->Set(index++, integer_cache.Get());
    for (int32_t i = 0, length = integer_cache->GetLength(); i != length; ++i) {
      live_objects->Set(index++, integer_cache->Get(i));
    }
  }
  CHECK_EQ(index, live_objects->GetLength());

  if (kIsDebugBuild && integer_cache != nullptr) {
    CHECK_EQ(integer_cache.Get(), IntrinsicObjects::GetIntegerValueOfCache(live_objects));
    for (int32_t i = 0, len = integer_cache->GetLength(); i != len; ++i) {
      CHECK_EQ(integer_cache->GetWithoutChecks(i),
               IntrinsicObjects::GetIntegerValueOfObject(live_objects, i));
    }
  }
  return live_objects;
}

ObjPtr<mirror::ClassLoader> ImageWriter::GetAppClassLoader() const
    REQUIRES_SHARED(Locks::mutator_lock_) {
  return compiler_options_.IsAppImage()
      ? ObjPtr<mirror::ClassLoader>::DownCast(Thread::Current()->DecodeJObject(app_class_loader_))
      : nullptr;
}

bool ImageWriter::IsImageDexCache(ObjPtr<mirror::DexCache> dex_cache) const {
  // For boot image, we keep all dex caches.
  if (compiler_options_.IsBootImage()) {
    return true;
  }
  // Dex caches already in the boot image do not belong to the image being written.
  if (IsInBootImage(dex_cache.Ptr())) {
    return false;
  }
  // Dex caches for the boot class path components that are not part of the boot image
  // cannot be garbage collected in PrepareImageAddressSpace() but we do not want to
  // include them in the app image.
  if (!ContainsElement(compiler_options_.GetDexFilesForOatFile(), dex_cache->GetDexFile())) {
    return false;
  }
  return true;
}

static void ClearDexFileCookies() REQUIRES_SHARED(Locks::mutator_lock_) {
  auto visitor = [](Object* obj) REQUIRES_SHARED(Locks::mutator_lock_) {
    DCHECK(obj != nullptr);
    Class* klass = obj->GetClass();
    if (klass == WellKnownClasses::ToClass(WellKnownClasses::dalvik_system_DexFile)) {
      ArtField* field = jni::DecodeArtField(WellKnownClasses::dalvik_system_DexFile_cookie);
      // Null out the cookie to enable determinism. b/34090128
      field->SetObject</*kTransactionActive*/false>(obj, nullptr);
    }
  };
  Runtime::Current()->GetHeap()->VisitObjects(visitor);
}

bool ImageWriter::PrepareImageAddressSpace(TimingLogger* timings) {
  target_ptr_size_ = InstructionSetPointerSize(compiler_options_.GetInstructionSet());

  Thread* const self = Thread::Current();

  gc::Heap* const heap = Runtime::Current()->GetHeap();
  {
    ScopedObjectAccess soa(self);
    {
      TimingLogger::ScopedTiming t("PruneNonImageClasses", timings);
      PruneNonImageClasses();  // Remove junk
    }

    if (compiler_options_.IsAppImage()) {
      TimingLogger::ScopedTiming t("ClearDexFileCookies", timings);
      // Clear dex file cookies for app images to enable app image determinism. This is required
      // since the cookie field contains long pointers to DexFiles which are not deterministic.
      // b/34090128
      ClearDexFileCookies();
    }
  }

  {
    TimingLogger::ScopedTiming t("CollectGarbage", timings);
    heap->CollectGarbage(/* clear_soft_references */ false);  // Remove garbage.
  }

  if (kIsDebugBuild) {
    ScopedObjectAccess soa(self);
    CheckNonImageClassesRemoved();
  }

  {
    // All remaining weak interns are referenced. Promote them to strong interns. Whether a
    // string was strongly or weakly interned, we shall make it strongly interned in the image.
    TimingLogger::ScopedTiming t("PromoteInterns", timings);
    ScopedObjectAccess soa(self);
    Runtime::Current()->GetInternTable()->PromoteWeakToStrong();
  }

  {
    TimingLogger::ScopedTiming t("CalculateNewObjectOffsets", timings);
    ScopedObjectAccess soa(self);
    CalculateNewObjectOffsets();
  }

  // This needs to happen after CalculateNewObjectOffsets since it relies on intern_table_bytes_ and
  // bin size sums being calculated.
  TimingLogger::ScopedTiming t("AllocMemory", timings);
  return AllocMemory();
}

void ImageWriter::CopyMetadata() {
  DCHECK(compiler_options_.IsAppImage());
  CHECK_EQ(image_infos_.size(), 1u);

  const ImageInfo& image_info = image_infos_.back();
  std::vector<ImageSection> image_sections = image_info.CreateImageSections().second;

  auto* sfo_section_base = reinterpret_cast<AppImageReferenceOffsetInfo*>(
      image_info.image_.Begin() +
      image_sections[ImageHeader::kSectionStringReferenceOffsets].Offset());

  std::copy(image_info.string_reference_offsets_.begin(),
            image_info.string_reference_offsets_.end(),
            sfo_section_base);
}

bool ImageWriter::IsInternedAppImageStringReference(ObjPtr<mirror::Object> referred_obj) const {
  return referred_obj != nullptr &&
         !IsInBootImage(referred_obj.Ptr()) &&
         referred_obj->IsString() &&
         referred_obj == Runtime::Current()->GetInternTable()->LookupStrong(
             Thread::Current(), referred_obj->AsString());
}

// Helper class that erases the image file if it isn't properly flushed and closed.
class ImageWriter::ImageFileGuard {
 public:
  ImageFileGuard() noexcept = default;
  ImageFileGuard(ImageFileGuard&& other) noexcept = default;
  ImageFileGuard& operator=(ImageFileGuard&& other) noexcept = default;

  ~ImageFileGuard() {
    if (image_file_ != nullptr) {
      // Failure, erase the image file.
      image_file_->Erase();
    }
  }

  void reset(File* image_file) {
    image_file_.reset(image_file);
  }

  bool operator==(std::nullptr_t) {
    return image_file_ == nullptr;
  }

  bool operator!=(std::nullptr_t) {
    return image_file_ != nullptr;
  }

  File* operator->() const {
    return image_file_.get();
  }

  bool WriteHeaderAndClose(const std::string& image_filename, const ImageHeader* image_header) {
    // The header is uncompressed since it contains whether the image is compressed or not.
    if (!image_file_->PwriteFully(image_header, sizeof(ImageHeader), 0)) {
      PLOG(ERROR) << "Failed to write image file header " << image_filename;
      return false;
    }

    // FlushCloseOrErase() takes care of erasing, so the destructor does not need
    // to do that whether the FlushCloseOrErase() succeeds or fails.
    std::unique_ptr<File> image_file = std::move(image_file_);
    if (image_file->FlushCloseOrErase() != 0) {
      PLOG(ERROR) << "Failed to flush and close image file " << image_filename;
      return false;
    }

    return true;
  }

 private:
  std::unique_ptr<File> image_file_;
};

bool ImageWriter::Write(int image_fd,
                        const std::vector<std::string>& image_filenames,
                        size_t component_count) {
  // If image_fd or oat_fd are not File::kInvalidFd then we may have empty strings in
  // image_filenames or oat_filenames.
  CHECK(!image_filenames.empty());
  if (image_fd != File::kInvalidFd) {
    CHECK_EQ(image_filenames.size(), 1u);
  }
  DCHECK(!oat_filenames_.empty());
  CHECK_EQ(image_filenames.size(), oat_filenames_.size());

  Thread* const self = Thread::Current();
  {
    ScopedObjectAccess soa(self);
    for (size_t i = 0; i < oat_filenames_.size(); ++i) {
      CreateHeader(i, component_count);
      CopyAndFixupNativeData(i);
    }
  }

  {
    // TODO: heap validation can't handle these fix up passes.
    ScopedObjectAccess soa(self);
    Runtime::Current()->GetHeap()->DisableObjectValidation();
    CopyAndFixupObjects();
  }

  if (compiler_options_.IsAppImage()) {
    CopyMetadata();
  }

  // Primary image header shall be written last for two reasons. First, this ensures
  // that we shall not end up with a valid primary image and invalid secondary image.
  // Second, its checksum shall include the checksums of the secondary images (XORed).
  // This way only the primary image checksum needs to be checked to determine whether
  // any of the images or oat files are out of date. (Oat file checksums are included
  // in the image checksum calculation.)
  ImageHeader* primary_header = reinterpret_cast<ImageHeader*>(image_infos_[0].image_.Begin());
  ImageFileGuard primary_image_file;
  for (size_t i = 0; i < image_filenames.size(); ++i) {
    const std::string& image_filename = image_filenames[i];
    ImageInfo& image_info = GetImageInfo(i);
    ImageFileGuard image_file;
    if (image_fd != File::kInvalidFd) {
      // Ignore image_filename, it is supplied only for better diagnostic.
      image_file.reset(new File(image_fd, unix_file::kCheckSafeUsage));
      // Empty the file in case it already exists.
      if (image_file != nullptr) {
        TEMP_FAILURE_RETRY(image_file->SetLength(0));
        TEMP_FAILURE_RETRY(image_file->Flush());
      }
    } else {
      image_file.reset(OS::CreateEmptyFile(image_filename.c_str()));
    }

    if (image_file == nullptr) {
      LOG(ERROR) << "Failed to open image file " << image_filename;
      return false;
    }

    // Make file world readable if we have created it, i.e. when not passed as file descriptor.
    if (image_fd == -1 && !compiler_options_.IsAppImage() && fchmod(image_file->Fd(), 0644) != 0) {
      PLOG(ERROR) << "Failed to make image file world readable: " << image_filename;
      return false;
    }

    // Image data size excludes the bitmap and the header.
    ImageHeader* const image_header = reinterpret_cast<ImageHeader*>(image_info.image_.Begin());

    // Block sources (from the image).
    const bool is_compressed = image_storage_mode_ != ImageHeader::kStorageModeUncompressed;
    std::vector<std::pair<uint32_t, uint32_t>> block_sources;
    std::vector<ImageHeader::Block> blocks;

    // Add a set of solid blocks such that no block is larger than the maximum size. A solid block
    // is a block that must be decompressed all at once.
    auto add_blocks = [&](uint32_t offset, uint32_t size) {
      while (size != 0u) {
        const uint32_t cur_size = std::min(size, compiler_options_.MaxImageBlockSize());
        block_sources.emplace_back(offset, cur_size);
        offset += cur_size;
        size -= cur_size;
      }
    };

    add_blocks(sizeof(ImageHeader), image_header->GetImageSize() - sizeof(ImageHeader));

    // Checksum of compressed image data and header.
    uint32_t image_checksum = adler32(0L, Z_NULL, 0);
    image_checksum = adler32(image_checksum,
                             reinterpret_cast<const uint8_t*>(image_header),
                             sizeof(ImageHeader));
    // Copy and compress blocks.
    size_t out_offset = sizeof(ImageHeader);
    for (const std::pair<uint32_t, uint32_t> block : block_sources) {
      ArrayRef<const uint8_t> raw_image_data(image_info.image_.Begin() + block.first,
                                             block.second);
      std::vector<uint8_t> compressed_data;
      ArrayRef<const uint8_t> image_data =
          MaybeCompressData(raw_image_data, image_storage_mode_, &compressed_data);

      if (!is_compressed) {
        // For uncompressed, preserve alignment since the image will be directly mapped.
        out_offset = block.first;
      }

      // Fill in the compressed location of the block.
      blocks.emplace_back(ImageHeader::Block(
          image_storage_mode_,
          /*data_offset=*/ out_offset,
          /*data_size=*/ image_data.size(),
          /*image_offset=*/ block.first,
          /*image_size=*/ block.second));

      // Write out the image + fields + methods.
      if (!image_file->PwriteFully(image_data.data(), image_data.size(), out_offset)) {
        PLOG(ERROR) << "Failed to write image file data " << image_filename;
        image_file->Erase();
        return false;
      }
      out_offset += image_data.size();
      image_checksum = adler32(image_checksum, image_data.data(), image_data.size());
    }

    // Write the block metadata directly after the image sections.
    // Note: This is not part of the mapped image and is not preserved after decompressing, it's
    // only used for image loading. For this reason, only write it out for compressed images.
    if (is_compressed) {
      // Align up since the compressed data is not necessarily aligned.
      out_offset = RoundUp(out_offset, alignof(ImageHeader::Block));
      CHECK(!blocks.empty());
      const size_t blocks_bytes = blocks.size() * sizeof(blocks[0]);
      if (!image_file->PwriteFully(&blocks[0], blocks_bytes, out_offset)) {
        PLOG(ERROR) << "Failed to write image blocks " << image_filename;
        image_file->Erase();
        return false;
      }
      image_header->blocks_offset_ = out_offset;
      image_header->blocks_count_ = blocks.size();
      out_offset += blocks_bytes;
    }

    // Data size includes everything except the bitmap.
    image_header->data_size_ = out_offset - sizeof(ImageHeader);

    // Update and write the bitmap section. Note that the bitmap section is relative to the
    // possibly compressed image.
    ImageSection& bitmap_section = image_header->GetImageSection(ImageHeader::kSectionImageBitmap);
    // Align up since data size may be unaligned if the image is compressed.
    out_offset = RoundUp(out_offset, kPageSize);
    bitmap_section = ImageSection(out_offset, bitmap_section.Size());

    if (!image_file->PwriteFully(image_info.image_bitmap_.Begin(),
                                 bitmap_section.Size(),
                                 bitmap_section.Offset())) {
      PLOG(ERROR) << "Failed to write image file bitmap " << image_filename;
      return false;
    }

    int err = image_file->Flush();
    if (err < 0) {
      PLOG(ERROR) << "Failed to flush image file " << image_filename << " with result " << err;
      return false;
    }

    // Calculate the image checksum of the remaining data.
    image_checksum = adler32(image_checksum,
                             reinterpret_cast<const uint8_t*>(image_info.image_bitmap_.Begin()),
                             bitmap_section.Size());
    image_header->SetImageChecksum(image_checksum);

    if (VLOG_IS_ON(compiler)) {
      const size_t separately_written_section_size = bitmap_section.Size();
      const size_t total_uncompressed_size = image_info.image_size_ +
          separately_written_section_size;
      const size_t total_compressed_size = out_offset + separately_written_section_size;

      VLOG(compiler) << "Dex2Oat:uncompressedImageSize = " << total_uncompressed_size;
      if (total_uncompressed_size != total_compressed_size) {
        VLOG(compiler) << "Dex2Oat:compressedImageSize = " << total_compressed_size;
      }
    }

    CHECK_EQ(bitmap_section.End(), static_cast<size_t>(image_file->GetLength()))
        << "Bitmap should be at the end of the file";

    // Write header last in case the compiler gets killed in the middle of image writing.
    // We do not want to have a corrupted image with a valid header.
    // Delay the writing of the primary image header until after writing secondary images.
    if (i == 0u) {
      primary_image_file = std::move(image_file);
    } else {
      if (!image_file.WriteHeaderAndClose(image_filename, image_header)) {
        return false;
      }
      // Update the primary image checksum with the secondary image checksum.
      primary_header->SetImageChecksum(primary_header->GetImageChecksum() ^ image_checksum);
    }
  }
  DCHECK(primary_image_file != nullptr);
  if (!primary_image_file.WriteHeaderAndClose(image_filenames[0], primary_header)) {
    return false;
  }

  return true;
}

size_t ImageWriter::GetImageOffset(mirror::Object* object, size_t oat_index) const {
  BinSlot bin_slot = GetImageBinSlot(object, oat_index);
  const ImageInfo& image_info = GetImageInfo(oat_index);
  size_t offset = image_info.GetBinSlotOffset(bin_slot.GetBin()) + bin_slot.GetOffset();
  DCHECK_LT(offset, image_info.image_end_);
  return offset;
}

void ImageWriter::SetImageBinSlot(mirror::Object* object, BinSlot bin_slot) {
  DCHECK(object != nullptr);
  DCHECK(!IsImageBinSlotAssigned(object));

  // Before we stomp over the lock word, save the hash code for later.
  LockWord lw(object->GetLockWord(false));
  switch (lw.GetState()) {
    case LockWord::kFatLocked:
      FALLTHROUGH_INTENDED;
    case LockWord::kThinLocked: {
      std::ostringstream oss;
      bool thin = (lw.GetState() == LockWord::kThinLocked);
      oss << (thin ? "Thin" : "Fat")
          << " locked object " << object << "(" << object->PrettyTypeOf()
          << ") found during object copy";
      if (thin) {
        oss << ". Lock owner:" << lw.ThinLockOwner();
      }
      LOG(FATAL) << oss.str();
      UNREACHABLE();
    }
    case LockWord::kUnlocked:
      // No hash, don't need to save it.
      break;
    case LockWord::kHashCode:
      DCHECK(saved_hashcode_map_.find(object) == saved_hashcode_map_.end());
      saved_hashcode_map_.insert(std::make_pair(object, lw.GetHashCode()));
      break;
    default:
      LOG(FATAL) << "Unreachable.";
      UNREACHABLE();
  }
  object->SetLockWord(LockWord::FromForwardingAddress(bin_slot.Uint32Value()),
                      /*as_volatile=*/ false);
  DCHECK_EQ(object->GetLockWord(false).ReadBarrierState(), 0u);
  DCHECK(IsImageBinSlotAssigned(object));
}

ImageWriter::Bin ImageWriter::AssignImageBinSlot(mirror::Object* object, size_t oat_index) {
  DCHECK(object != nullptr);

  // The magic happens here. We segregate objects into different bins based
  // on how likely they are to get dirty at runtime.
  //
  // Likely-to-dirty objects get packed together into the same bin so that
  // at runtime their page dirtiness ratio (how many dirty objects a page has) is
  // maximized.
  //
  // This means more pages will stay either clean or shared dirty (with zygote) and
  // the app will use less of its own (private) memory.
  Bin bin = Bin::kRegular;

  if (kBinObjects) {
    //
    // Changing the bin of an object is purely a memory-use tuning.
    // It has no change on runtime correctness.
    //
    // Memory analysis has determined that the following types of objects get dirtied
    // the most:
    //
    // * Class'es which are verified [their clinit runs only at runtime]
    //   - classes in general [because their static fields get overwritten]
    //   - initialized classes with all-final statics are unlikely to be ever dirty,
    //     so bin them separately
    // * Art Methods that are:
    //   - native [their native entry point is not looked up until runtime]
    //   - have declaring classes that aren't initialized
    //            [their interpreter/quick entry points are trampolines until the class
    //             becomes initialized]
    //
    // We also assume the following objects get dirtied either never or extremely rarely:
    //  * Strings (they are immutable)
    //  * Art methods that aren't native and have initialized declared classes
    //
    // We assume that "regular" bin objects are highly unlikely to become dirtied,
    // so packing them together will not result in a noticeably tighter dirty-to-clean ratio.
    //
    if (object->IsClass()) {
      bin = Bin::kClassVerified;
      ObjPtr<mirror::Class> klass = object->AsClass();

      // Move known dirty objects into their own sections. This includes:
      //   - classes with dirty static fields.
      auto is_dirty = [&](ObjPtr<mirror::Class> k) REQUIRES_SHARED(Locks::mutator_lock_) {
        std::string temp;
        std::string_view descriptor = k->GetDescriptor(&temp);
        return dirty_image_objects_->find(descriptor) != dirty_image_objects_->end();
      };
      if (dirty_image_objects_ != nullptr && is_dirty(klass)) {
        bin = Bin::kKnownDirty;
      } else if (klass->GetStatus() == ClassStatus::kVisiblyInitialized) {
        bin = Bin::kClassInitialized;

        // If the class's static fields are all final, put it into a separate bin
        // since it's very likely it will stay clean.
        uint32_t num_static_fields = klass->NumStaticFields();
        if (num_static_fields == 0) {
          bin = Bin::kClassInitializedFinalStatics;
        } else {
          // Maybe all the statics are final?
          bool all_final = true;
          for (uint32_t i = 0; i < num_static_fields; ++i) {
            ArtField* field = klass->GetStaticField(i);
            if (!field->IsFinal()) {
              all_final = false;
              break;
            }
          }

          if (all_final) {
            bin = Bin::kClassInitializedFinalStatics;
          }
        }
      }
    } else if (object->GetClass<kVerifyNone>()->IsStringClass()) {
      bin = Bin::kString;  // Strings are almost always immutable (except for object header).
    } else if (object->GetClass<kVerifyNone>() == GetClassRoot<mirror::Object>()) {
      // Instance of java lang object, probably a lock object. This means it will be dirty when we
      // synchronize on it.
      bin = Bin::kMiscDirty;
    } else if (object->IsDexCache()) {
      // Dex file field becomes dirty when the image is loaded.
      bin = Bin::kMiscDirty;
    }
    // else bin = kBinRegular
  }

  AssignImageBinSlot(object, oat_index, bin);
  return bin;
}

void ImageWriter::AssignImageBinSlot(mirror::Object* object, size_t oat_index, Bin bin) {
  DCHECK(object != nullptr);
  size_t object_size = object->SizeOf();

  // Assign the oat index too.
  if (IsMultiImage()) {
    DCHECK(oat_index_map_.find(object) == oat_index_map_.end());
    oat_index_map_.insert(std::make_pair(object, oat_index));
  } else {
    DCHECK(oat_index_map_.empty());
  }

  ImageInfo& image_info = GetImageInfo(oat_index);

  size_t offset_delta = RoundUp(object_size, kObjectAlignment);  // 64-bit alignment
  // How many bytes the current bin is at (aligned).
  size_t current_offset = image_info.GetBinSlotSize(bin);
  // Move the current bin size up to accommodate the object we just assigned a bin slot.
  image_info.IncrementBinSlotSize(bin, offset_delta);

  BinSlot new_bin_slot(bin, current_offset);
  SetImageBinSlot(object, new_bin_slot);

  image_info.IncrementBinSlotCount(bin, 1u);

  // Grow the image closer to the end by the object we just assigned.
  image_info.image_end_ += offset_delta;
}

bool ImageWriter::WillMethodBeDirty(ArtMethod* m) const {
  if (m->IsNative()) {
    return true;
  }
  ObjPtr<mirror::Class> declaring_class = m->GetDeclaringClass();
  // Initialized is highly unlikely to dirty since there's no entry points to mutate.
  return declaring_class == nullptr ||
         declaring_class->GetStatus() != ClassStatus::kVisiblyInitialized;
}

bool ImageWriter::IsImageBinSlotAssigned(mirror::Object* object) const {
  DCHECK(object != nullptr);

  // We always stash the bin slot into a lockword, in the 'forwarding address' state.
  // If it's in some other state, then we haven't yet assigned an image bin slot.
  if (object->GetLockWord(false).GetState() != LockWord::kForwardingAddress) {
    return false;
  } else if (kIsDebugBuild) {
    LockWord lock_word = object->GetLockWord(false);
    size_t offset = lock_word.ForwardingAddress();
    BinSlot bin_slot(offset);
    size_t oat_index = GetOatIndex(object);
    const ImageInfo& image_info = GetImageInfo(oat_index);
    DCHECK_LT(bin_slot.GetOffset(), image_info.GetBinSlotSize(bin_slot.GetBin()))
        << "bin slot offset should not exceed the size of that bin";
  }
  return true;
}

ImageWriter::BinSlot ImageWriter::GetImageBinSlot(mirror::Object* object, size_t oat_index) const {
  DCHECK(object != nullptr);
  DCHECK(IsImageBinSlotAssigned(object));

  LockWord lock_word = object->GetLockWord(false);
  size_t offset = lock_word.ForwardingAddress();  // TODO: ForwardingAddress should be uint32_t
  DCHECK_LE(offset, std::numeric_limits<uint32_t>::max());

  BinSlot bin_slot(static_cast<uint32_t>(offset));
  DCHECK_LT(bin_slot.GetOffset(), GetImageInfo(oat_index).GetBinSlotSize(bin_slot.GetBin()));

  return bin_slot;
}

void ImageWriter::UpdateImageBinSlotOffset(mirror::Object* object,
                                           size_t oat_index,
                                           size_t new_offset) {
  BinSlot old_bin_slot = GetImageBinSlot(object, oat_index);
  DCHECK_LT(new_offset, GetImageInfo(oat_index).GetBinSlotSize(old_bin_slot.GetBin()));
  BinSlot new_bin_slot(old_bin_slot.GetBin(), new_offset);
  object->SetLockWord(LockWord::FromForwardingAddress(new_bin_slot.Uint32Value()),
                      /*as_volatile=*/ false);
  DCHECK_EQ(object->GetLockWord(false).ReadBarrierState(), 0u);
  DCHECK(IsImageBinSlotAssigned(object));
}

bool ImageWriter::AllocMemory() {
  for (ImageInfo& image_info : image_infos_) {
    const size_t length = RoundUp(image_info.CreateImageSections().first, kPageSize);

    std::string error_msg;
    image_info.image_ = MemMap::MapAnonymous("image writer image",
                                             length,
                                             PROT_READ | PROT_WRITE,
                                             /*low_4gb=*/ false,
                                             &error_msg);
    if (UNLIKELY(!image_info.image_.IsValid())) {
      LOG(ERROR) << "Failed to allocate memory for image file generation: " << error_msg;
      return false;
    }

    // Create the image bitmap, only needs to cover mirror object section which is up to image_end_.
    CHECK_LE(image_info.image_end_, length);
    image_info.image_bitmap_ = gc::accounting::ContinuousSpaceBitmap::Create(
        "image bitmap", image_info.image_.Begin(), RoundUp(image_info.image_end_, kPageSize));
    if (!image_info.image_bitmap_.IsValid()) {
      LOG(ERROR) << "Failed to allocate memory for image bitmap";
      return false;
    }
  }
  return true;
}

static bool IsBootClassLoaderClass(ObjPtr<mirror::Class> klass)
    REQUIRES_SHARED(Locks::mutator_lock_) {
  return klass->GetClassLoader() == nullptr;
}

bool ImageWriter::IsBootClassLoaderNonImageClass(mirror::Class* klass) {
  return IsBootClassLoaderClass(klass) && !IsInBootImage(klass);
}

// This visitor follows the references of an instance, recursively then prune this class
// if a type of any field is pruned.
class ImageWriter::PruneObjectReferenceVisitor {
 public:
  PruneObjectReferenceVisitor(ImageWriter* image_writer,
                        bool* early_exit,
                        HashSet<mirror::Object*>* visited,
                        bool* result)
      : image_writer_(image_writer), early_exit_(early_exit), visited_(visited), result_(result) {}

  ALWAYS_INLINE void VisitRootIfNonNull(
      mirror::CompressedReference<mirror::Object>* root ATTRIBUTE_UNUSED) const
      REQUIRES_SHARED(Locks::mutator_lock_) { }

  ALWAYS_INLINE void VisitRoot(
      mirror::CompressedReference<mirror::Object>* root ATTRIBUTE_UNUSED) const
      REQUIRES_SHARED(Locks::mutator_lock_) { }

  ALWAYS_INLINE void operator() (ObjPtr<mirror::Object> obj,
                                 MemberOffset offset,
                                 bool is_static ATTRIBUTE_UNUSED) const
      REQUIRES_SHARED(Locks::mutator_lock_) {
    mirror::Object* ref =
        obj->GetFieldObject<mirror::Object, kVerifyNone, kWithoutReadBarrier>(offset);
    if (ref == nullptr || visited_->find(ref) != visited_->end()) {
      return;
    }

    ObjPtr<mirror::ObjectArray<mirror::Class>> class_roots =
        Runtime::Current()->GetClassLinker()->GetClassRoots();
    ObjPtr<mirror::Class> klass = ref->IsClass() ? ref->AsClass() : ref->GetClass();
    if (klass == GetClassRoot<mirror::Method>(class_roots) ||
        klass == GetClassRoot<mirror::Constructor>(class_roots)) {
      // Prune all classes using reflection because the content they held will not be fixup.
      *result_ = true;
    }

    if (ref->IsClass()) {
      *result_ = *result_ ||
          image_writer_->PruneImageClassInternal(ref->AsClass(), early_exit_, visited_);
    } else {
      // Record the object visited in case of circular reference.
      visited_->insert(ref);
      *result_ = *result_ ||
          image_writer_->PruneImageClassInternal(klass, early_exit_, visited_);
      ref->VisitReferences(*this, *this);
      // Clean up before exit for next call of this function.
      auto it = visited_->find(ref);
      DCHECK(it != visited_->end());
      visited_->erase(it);
    }
  }

  ALWAYS_INLINE void operator() (ObjPtr<mirror::Class> klass ATTRIBUTE_UNUSED,
                                 ObjPtr<mirror::Reference> ref) const
      REQUIRES_SHARED(Locks::mutator_lock_) {
    operator()(ref, mirror::Reference::ReferentOffset(), /* is_static */ false);
  }

 private:
  ImageWriter* image_writer_;
  bool* early_exit_;
  HashSet<mirror::Object*>* visited_;
  bool* const result_;
};


bool ImageWriter::PruneImageClass(ObjPtr<mirror::Class> klass) {
  bool early_exit = false;
  HashSet<mirror::Object*> visited;
  return PruneImageClassInternal(klass, &early_exit, &visited);
}

bool ImageWriter::PruneImageClassInternal(
    ObjPtr<mirror::Class> klass,
    bool* early_exit,
    HashSet<mirror::Object*>* visited) {
  DCHECK(early_exit != nullptr);
  DCHECK(visited != nullptr);
  DCHECK(compiler_options_.IsAppImage() || compiler_options_.IsBootImageExtension());
  if (klass == nullptr || IsInBootImage(klass.Ptr())) {
    return false;
  }
  auto found = prune_class_memo_.find(klass.Ptr());
  if (found != prune_class_memo_.end()) {
    // Already computed, return the found value.
    return found->second;
  }
  // Circular dependencies, return false but do not store the result in the memoization table.
  if (visited->find(klass.Ptr()) != visited->end()) {
    *early_exit = true;
    return false;
  }
  visited->insert(klass.Ptr());
  bool result = IsBootClassLoaderClass(klass);
  std::string temp;
  // Prune if not an image class, this handles any broken sets of image classes such as having a
  // class in the set but not it's superclass.
  result = result || !compiler_options_.IsImageClass(klass->GetDescriptor(&temp));
  bool my_early_exit = false;  // Only for ourselves, ignore caller.
  // Remove classes that failed to verify since we don't want to have java.lang.VerifyError in the
  // app image.
  if (klass->IsErroneous()) {
    result = true;
  } else {
    ObjPtr<mirror::ClassExt> ext(klass->GetExtData());
    CHECK(ext.IsNull() || ext->GetVerifyError() == nullptr) << klass->PrettyClass();
  }
  if (!result) {
    // Check interfaces since these wont be visited through VisitReferences.)
    ObjPtr<mirror::IfTable> if_table = klass->GetIfTable();
    for (size_t i = 0, num_interfaces = klass->GetIfTableCount(); i < num_interfaces; ++i) {
      result = result || PruneImageClassInternal(if_table->GetInterface(i),
                                                 &my_early_exit,
                                                 visited);
    }
  }
  if (klass->IsObjectArrayClass()) {
    result = result || PruneImageClassInternal(klass->GetComponentType(),
                                               &my_early_exit,
                                               visited);
  }
  // Check static fields and their classes.
  if (klass->IsResolved() && klass->NumReferenceStaticFields() != 0) {
    size_t num_static_fields = klass->NumReferenceStaticFields();
    // Presumably GC can happen when we are cross compiling, it should not cause performance
    // problems to do pointer size logic.
    MemberOffset field_offset = klass->GetFirstReferenceStaticFieldOffset(
        Runtime::Current()->GetClassLinker()->GetImagePointerSize());
    for (size_t i = 0u; i < num_static_fields; ++i) {
      mirror::Object* ref = klass->GetFieldObject<mirror::Object>(field_offset);
      if (ref != nullptr) {
        if (ref->IsClass()) {
          result = result || PruneImageClassInternal(ref->AsClass(), &my_early_exit, visited);
        } else {
          mirror::Class* type = ref->GetClass();
          result = result || PruneImageClassInternal(type, &my_early_exit, visited);
          if (!result) {
            // For non-class case, also go through all the types mentioned by it's fields'
            // references recursively to decide whether to keep this class.
            bool tmp = false;
            PruneObjectReferenceVisitor visitor(this, &my_early_exit, visited, &tmp);
            ref->VisitReferences(visitor, visitor);
            result = result || tmp;
          }
        }
      }
      field_offset = MemberOffset(field_offset.Uint32Value() +
                                  sizeof(mirror::HeapReference<mirror::Object>));
    }
  }
  result = result || PruneImageClassInternal(klass->GetSuperClass(), &my_early_exit, visited);
  // Remove the class if the dex file is not in the set of dex files. This happens for classes that
  // are from uses-library if there is no profile. b/30688277
  ObjPtr<mirror::DexCache> dex_cache = klass->GetDexCache();
  if (dex_cache != nullptr) {
    result = result ||
        dex_file_oat_index_map_.find(dex_cache->GetDexFile()) == dex_file_oat_index_map_.end();
  }
  // Erase the element we stored earlier since we are exiting the function.
  auto it = visited->find(klass.Ptr());
  DCHECK(it != visited->end());
  visited->erase(it);
  // Only store result if it is true or none of the calls early exited due to circular
  // dependencies. If visited is empty then we are the root caller, in this case the cycle was in
  // a child call and we can remember the result.
  if (result == true || !my_early_exit || visited->empty()) {
    prune_class_memo_.Overwrite(klass.Ptr(), result);
  }
  *early_exit |= my_early_exit;
  return result;
}

bool ImageWriter::KeepClass(ObjPtr<mirror::Class> klass) {
  if (klass == nullptr) {
    return false;
  }
  if (IsInBootImage(klass.Ptr())) {
    // Already in boot image, return true.
    DCHECK(!compiler_options_.IsBootImage());
    return true;
  }
  std::string temp;
  if (!compiler_options_.IsImageClass(klass->GetDescriptor(&temp))) {
    return false;
  }
  if (compiler_options_.IsAppImage()) {
    // For app images, we need to prune classes that
    // are defined by the boot class path we're compiling against but not in
    // the boot image spaces since these may have already been loaded at
    // run time when this image is loaded. Keep classes in the boot image
    // spaces we're compiling against since we don't want to re-resolve these.
    return !PruneImageClass(klass);
  }
  return true;
}

class ImageWriter::PruneClassesVisitor : public ClassVisitor {
 public:
  PruneClassesVisitor(ImageWriter* image_writer, ObjPtr<mirror::ClassLoader> class_loader)
      : image_writer_(image_writer),
        class_loader_(class_loader),
        classes_to_prune_(),
        defined_class_count_(0u) { }

  bool operator()(ObjPtr<mirror::Class> klass) override REQUIRES_SHARED(Locks::mutator_lock_) {
    if (!image_writer_->KeepClass(klass.Ptr())) {
      classes_to_prune_.insert(klass.Ptr());
      if (klass->GetClassLoader() == class_loader_) {
        ++defined_class_count_;
      }
    }
    return true;
  }

  size_t Prune() REQUIRES_SHARED(Locks::mutator_lock_) {
    ClassTable* class_table =
        Runtime::Current()->GetClassLinker()->ClassTableForClassLoader(class_loader_);
    for (mirror::Class* klass : classes_to_prune_) {
      std::string storage;
      const char* descriptor = klass->GetDescriptor(&storage);
      bool result = class_table->Remove(descriptor);
      DCHECK(result);
      DCHECK(!class_table->Remove(descriptor)) << descriptor;
    }
    return defined_class_count_;
  }

 private:
  ImageWriter* const image_writer_;
  const ObjPtr<mirror::ClassLoader> class_loader_;
  HashSet<mirror::Class*> classes_to_prune_;
  size_t defined_class_count_;
};

class ImageWriter::PruneClassLoaderClassesVisitor : public ClassLoaderVisitor {
 public:
  explicit PruneClassLoaderClassesVisitor(ImageWriter* image_writer)
      : image_writer_(image_writer), removed_class_count_(0) {}

  void Visit(ObjPtr<mirror::ClassLoader> class_loader) override
      REQUIRES_SHARED(Locks::mutator_lock_) {
    PruneClassesVisitor classes_visitor(image_writer_, class_loader);
    ClassTable* class_table =
        Runtime::Current()->GetClassLinker()->ClassTableForClassLoader(class_loader);
    class_table->Visit(classes_visitor);
    removed_class_count_ += classes_visitor.Prune();
  }

  size_t GetRemovedClassCount() const {
    return removed_class_count_;
  }

 private:
  ImageWriter* const image_writer_;
  size_t removed_class_count_;
};

void ImageWriter::VisitClassLoaders(ClassLoaderVisitor* visitor) {
  WriterMutexLock mu(Thread::Current(), *Locks::classlinker_classes_lock_);
  visitor->Visit(nullptr);  // Visit boot class loader.
  Runtime::Current()->GetClassLinker()->VisitClassLoaders(visitor);
}

void ImageWriter::ClearDexCache(ObjPtr<mirror::DexCache> dex_cache) {
  // Clear methods.
  mirror::MethodDexCacheType* resolved_methods = dex_cache->GetResolvedMethods();
  for (size_t slot_idx = 0, num = dex_cache->NumResolvedMethods(); slot_idx != num; ++slot_idx) {
    mirror::MethodDexCachePair invalid(nullptr,
                                       mirror::MethodDexCachePair::InvalidIndexForSlot(slot_idx));
    mirror::DexCache::SetNativePair(resolved_methods, slot_idx, invalid);
  }
  // Clear fields.
  mirror::FieldDexCacheType* resolved_fields = dex_cache->GetResolvedFields();
  for (size_t slot_idx = 0, num = dex_cache->NumResolvedFields(); slot_idx != num; ++slot_idx) {
    mirror::FieldDexCachePair invalid(nullptr,
                                      mirror::FieldDexCachePair::InvalidIndexForSlot(slot_idx));
    mirror::DexCache::SetNativePair(resolved_fields, slot_idx, invalid);
  }
  // Clear types.
  mirror::TypeDexCacheType* resolved_types = dex_cache->GetResolvedTypes();
  for (size_t slot_idx = 0, num = dex_cache->NumResolvedTypes(); slot_idx != num; ++slot_idx) {
    mirror::TypeDexCachePair invalid(nullptr,
                                     mirror::TypeDexCachePair::InvalidIndexForSlot(slot_idx));
    resolved_types[slot_idx].store(invalid, std::memory_order_relaxed);
  }
  // Clear strings.
  mirror::StringDexCacheType* resolved_strings = dex_cache->GetStrings();
  for (size_t slot_idx = 0, num = dex_cache->NumStrings(); slot_idx != num; ++slot_idx) {
    mirror::StringDexCachePair invalid(nullptr,
                                       mirror::StringDexCachePair::InvalidIndexForSlot(slot_idx));
    resolved_strings[slot_idx].store(invalid, std::memory_order_relaxed);
  }
  // Clear method types.
  mirror::MethodTypeDexCacheType* resolved_method_types = dex_cache->GetResolvedMethodTypes();
  size_t num_resolved_method_types = dex_cache->NumResolvedMethodTypes();
  for (size_t slot_idx = 0; slot_idx != num_resolved_method_types; ++slot_idx) {
    mirror::MethodTypeDexCachePair invalid(
        nullptr, mirror::MethodTypeDexCachePair::InvalidIndexForSlot(slot_idx));
    resolved_method_types[slot_idx].store(invalid, std::memory_order_relaxed);
  }
  // Clear call sites.
  std::fill_n(dex_cache->GetResolvedCallSites(),
              dex_cache->NumResolvedCallSites(),
              GcRoot<mirror::CallSite>(nullptr));
}

void ImageWriter::PruneNonImageClasses() {
  Runtime* runtime = Runtime::Current();
  ClassLinker* class_linker = runtime->GetClassLinker();
  Thread* self = Thread::Current();
  ScopedAssertNoThreadSuspension sa(__FUNCTION__);

  // Prune uses-library dex caches. Only prune the uses-library dex caches since we want to make
  // sure the other ones don't get unloaded before the OatWriter runs.
  class_linker->VisitClassTables(
      [&](ClassTable* table) REQUIRES_SHARED(Locks::mutator_lock_) {
    table->RemoveStrongRoots(
        [&](GcRoot<mirror::Object> root) REQUIRES_SHARED(Locks::mutator_lock_) {
      ObjPtr<mirror::Object> obj = root.Read();
      if (obj->IsDexCache()) {
        // Return true if the dex file is not one of the ones in the map.
        return dex_file_oat_index_map_.find(obj->AsDexCache()->GetDexFile()) ==
            dex_file_oat_index_map_.end();
      }
      // Return false to avoid removing.
      return false;
    });
  });

  // Remove the undesired classes from the class roots.
  {
    PruneClassLoaderClassesVisitor class_loader_visitor(this);
    VisitClassLoaders(&class_loader_visitor);
    VLOG(compiler) << "Pruned " << class_loader_visitor.GetRemovedClassCount() << " classes";
  }

  // Completely clear DexCaches.
  std::vector<ObjPtr<mirror::DexCache>> dex_caches = FindDexCaches(self);
  for (ObjPtr<mirror::DexCache> dex_cache : dex_caches) {
    ClearDexCache(dex_cache);
  }

  // Drop the array class cache in the ClassLinker, as these are roots holding those classes live.
  class_linker->DropFindArrayClassCache();

  // Clear to save RAM.
  prune_class_memo_.clear();
}

std::vector<ObjPtr<mirror::DexCache>> ImageWriter::FindDexCaches(Thread* self) {
  std::vector<ObjPtr<mirror::DexCache>> dex_caches;
  ClassLinker* class_linker = Runtime::Current()->GetClassLinker();
  ReaderMutexLock mu2(self, *Locks::dex_lock_);
  dex_caches.reserve(class_linker->GetDexCachesData().size());
  for (const ClassLinker::DexCacheData& data : class_linker->GetDexCachesData()) {
    if (self->IsJWeakCleared(data.weak_root)) {
      continue;
    }
    dex_caches.push_back(self->DecodeJObject(data.weak_root)->AsDexCache());
  }
  return dex_caches;
}

void ImageWriter::CheckNonImageClassesRemoved() {
  auto visitor = [&](Object* obj) REQUIRES_SHARED(Locks::mutator_lock_) {
    if (obj->IsClass() && !IsInBootImage(obj)) {
      ObjPtr<Class> klass = obj->AsClass();
      if (!KeepClass(klass)) {
        DumpImageClasses();
        CHECK(KeepClass(klass))
            << Runtime::Current()->GetHeap()->GetVerification()->FirstPathFromRootSet(klass);
      }
    }
  };
  gc::Heap* heap = Runtime::Current()->GetHeap();
  heap->VisitObjects(visitor);
}

void ImageWriter::DumpImageClasses() {
  for (const std::string& image_class : compiler_options_.GetImageClasses()) {
    LOG(INFO) << " " << image_class;
  }
}

ObjPtr<mirror::ObjectArray<mirror::Object>> ImageWriter::CollectDexCaches(Thread* self,
                                                                          size_t oat_index) const {
  HashSet<const DexFile*> image_dex_files;
  for (auto& pair : dex_file_oat_index_map_) {
    const DexFile* image_dex_file = pair.first;
    size_t image_oat_index = pair.second;
    if (oat_index == image_oat_index) {
      image_dex_files.insert(image_dex_file);
    }
  }

  // build an Object[] of all the DexCaches used in the source_space_.
  // Since we can't hold the dex lock when allocating the dex_caches
  // ObjectArray, we lock the dex lock twice, first to get the number
  // of dex caches first and then lock it again to copy the dex
  // caches. We check that the number of dex caches does not change.
  ClassLinker* class_linker = Runtime::Current()->GetClassLinker();
  size_t dex_cache_count = 0;
  {
    ReaderMutexLock mu(self, *Locks::dex_lock_);
    // Count number of dex caches not in the boot image.
    for (const ClassLinker::DexCacheData& data : class_linker->GetDexCachesData()) {
      ObjPtr<mirror::DexCache> dex_cache =
          ObjPtr<mirror::DexCache>::DownCast(self->DecodeJObject(data.weak_root));
      if (dex_cache == nullptr) {
        continue;
      }
      const DexFile* dex_file = dex_cache->GetDexFile();
      if (IsImageDexCache(dex_cache)) {
        dex_cache_count += image_dex_files.find(dex_file) != image_dex_files.end() ? 1u : 0u;
      }
    }
  }
  ObjPtr<ObjectArray<Object>> dex_caches = ObjectArray<Object>::Alloc(
      self, GetClassRoot<ObjectArray<Object>>(class_linker), dex_cache_count);
  CHECK(dex_caches != nullptr) << "Failed to allocate a dex cache array.";
  {
    ReaderMutexLock mu(self, *Locks::dex_lock_);
    size_t non_image_dex_caches = 0;
    // Re-count number of non image dex caches.
    for (const ClassLinker::DexCacheData& data : class_linker->GetDexCachesData()) {
      ObjPtr<mirror::DexCache> dex_cache =
          ObjPtr<mirror::DexCache>::DownCast(self->DecodeJObject(data.weak_root));
      if (dex_cache == nullptr) {
        continue;
      }
      const DexFile* dex_file = dex_cache->GetDexFile();
      if (IsImageDexCache(dex_cache)) {
        non_image_dex_caches += image_dex_files.find(dex_file) != image_dex_files.end() ? 1u : 0u;
      }
    }
    CHECK_EQ(dex_cache_count, non_image_dex_caches)
        << "The number of non-image dex caches changed.";
    size_t i = 0;
    for (const ClassLinker::DexCacheData& data : class_linker->GetDexCachesData()) {
      ObjPtr<mirror::DexCache> dex_cache =
          ObjPtr<mirror::DexCache>::DownCast(self->DecodeJObject(data.weak_root));
      if (dex_cache == nullptr) {
        continue;
      }
      const DexFile* dex_file = dex_cache->GetDexFile();
      if (IsImageDexCache(dex_cache) &&
          image_dex_files.find(dex_file) != image_dex_files.end()) {
        dex_caches->Set<false>(i, dex_cache.Ptr());
        ++i;
      }
    }
  }
  return dex_caches;
}

ObjPtr<ObjectArray<Object>> ImageWriter::CreateImageRoots(
    size_t oat_index,
    Handle<mirror::ObjectArray<mirror::Object>> boot_image_live_objects) const {
  Runtime* runtime = Runtime::Current();
  ClassLinker* class_linker = runtime->GetClassLinker();
  Thread* self = Thread::Current();
  StackHandleScope<2> hs(self);

  Handle<ObjectArray<Object>> dex_caches(hs.NewHandle(CollectDexCaches(self, oat_index)));

  // build an Object[] of the roots needed to restore the runtime
  int32_t image_roots_size = ImageHeader::NumberOfImageRoots(compiler_options_.IsAppImage());
  Handle<ObjectArray<Object>> image_roots(hs.NewHandle(ObjectArray<Object>::Alloc(
      self, GetClassRoot<ObjectArray<Object>>(class_linker), image_roots_size)));
  image_roots->Set<false>(ImageHeader::kDexCaches, dex_caches.Get());
  image_roots->Set<false>(ImageHeader::kClassRoots, class_linker->GetClassRoots());
  if (!compiler_options_.IsAppImage()) {
    DCHECK(boot_image_live_objects != nullptr);
    image_roots->Set<false>(ImageHeader::kBootImageLiveObjects, boot_image_live_objects.Get());
  } else {
    DCHECK(boot_image_live_objects == nullptr);
    image_roots->Set<false>(ImageHeader::kAppImageClassLoader, GetAppClassLoader());
  }
  for (int32_t i = 0; i != image_roots_size; ++i) {
    CHECK(image_roots->Get(i) != nullptr);
  }
  return image_roots.Get();
}

void ImageWriter::RecordNativeRelocations(ObjPtr<mirror::Class> klass, size_t oat_index) {
  // Visit and assign offsets for fields and field arrays.
  DCHECK_EQ(oat_index, GetOatIndexForClass(klass));
  DCHECK(!klass->IsErroneous()) << klass->GetStatus();
  if (compiler_options_.IsAppImage()) {
    // Extra consistency check: no boot loader classes should be left!
    CHECK(!IsBootClassLoaderClass(klass)) << klass->PrettyClass();
  }
  LengthPrefixedArray<ArtField>* fields[] = {
      klass->GetSFieldsPtr(), klass->GetIFieldsPtr(),
  };
  ImageInfo& image_info = GetImageInfo(oat_index);
  for (LengthPrefixedArray<ArtField>* cur_fields : fields) {
    // Total array length including header.
    if (cur_fields != nullptr) {
      // Forward the entire array at once.
      size_t offset = image_info.GetBinSlotSize(Bin::kArtField);
      DCHECK(!IsInBootImage(cur_fields));
      bool inserted =
          native_object_relocations_.insert(std::make_pair(
              cur_fields,
              NativeObjectRelocation {
                  oat_index, offset, NativeObjectRelocationType::kArtFieldArray
              })).second;
      CHECK(inserted) << "Field array " << cur_fields << " already forwarded";
      const size_t size = LengthPrefixedArray<ArtField>::ComputeSize(cur_fields->size());
      offset += size;
      image_info.IncrementBinSlotSize(Bin::kArtField, size);
      DCHECK_EQ(offset, image_info.GetBinSlotSize(Bin::kArtField));
    }
  }
  // Visit and assign offsets for methods.
  size_t num_methods = klass->NumMethods();
  if (num_methods != 0) {
    bool any_dirty = false;
    for (auto& m : klass->GetMethods(target_ptr_size_)) {
      if (WillMethodBeDirty(&m)) {
        any_dirty = true;
        break;
      }
    }
    NativeObjectRelocationType type = any_dirty
        ? NativeObjectRelocationType::kArtMethodDirty
        : NativeObjectRelocationType::kArtMethodClean;
    Bin bin_type = BinTypeForNativeRelocationType(type);
    // Forward the entire array at once, but header first.
    const size_t method_alignment = ArtMethod::Alignment(target_ptr_size_);
    const size_t method_size = ArtMethod::Size(target_ptr_size_);
    const size_t header_size = LengthPrefixedArray<ArtMethod>::ComputeSize(0,
                                                                           method_size,
                                                                           method_alignment);
    LengthPrefixedArray<ArtMethod>* array = klass->GetMethodsPtr();
    size_t offset = image_info.GetBinSlotSize(bin_type);
    DCHECK(!IsInBootImage(array));
    bool inserted =
        native_object_relocations_.insert(std::make_pair(
            array,
            NativeObjectRelocation {
                  oat_index,
                  offset,
                  any_dirty ? NativeObjectRelocationType::kArtMethodArrayDirty
                            : NativeObjectRelocationType::kArtMethodArrayClean
              })).second;
    CHECK(inserted) << "Method array " << array << " already forwarded";
    image_info.IncrementBinSlotSize(bin_type, header_size);
    for (auto& m : klass->GetMethods(target_ptr_size_)) {
      AssignMethodOffset(&m, type, oat_index);
    }
    (any_dirty ? dirty_methods_ : clean_methods_) += num_methods;
  }
  // Assign offsets for all runtime methods in the IMT since these may hold conflict tables
  // live.
  if (klass->ShouldHaveImt()) {
    ImTable* imt = klass->GetImt(target_ptr_size_);
    if (TryAssignImTableOffset(imt, oat_index)) {
      // Since imt's can be shared only do this the first time to not double count imt method
      // fixups.
      for (size_t i = 0; i < ImTable::kSize; ++i) {
        ArtMethod* imt_method = imt->Get(i, target_ptr_size_);
        DCHECK(imt_method != nullptr);
        if (imt_method->IsRuntimeMethod() &&
            !IsInBootImage(imt_method) &&
            !NativeRelocationAssigned(imt_method)) {
          AssignMethodOffset(imt_method, NativeObjectRelocationType::kRuntimeMethod, oat_index);
        }
      }
    }
  }
}

bool ImageWriter::NativeRelocationAssigned(void* ptr) const {
  return native_object_relocations_.find(ptr) != native_object_relocations_.end();
}

bool ImageWriter::TryAssignImTableOffset(ImTable* imt, size_t oat_index) {
  // No offset, or already assigned.
  if (imt == nullptr || IsInBootImage(imt) || NativeRelocationAssigned(imt)) {
    return false;
  }
  // If the method is a conflict method we also want to assign the conflict table offset.
  ImageInfo& image_info = GetImageInfo(oat_index);
  const size_t size = ImTable::SizeInBytes(target_ptr_size_);
  native_object_relocations_.insert(std::make_pair(
      imt,
      NativeObjectRelocation {
          oat_index,
          image_info.GetBinSlotSize(Bin::kImTable),
          NativeObjectRelocationType::kIMTable
      }));
  image_info.IncrementBinSlotSize(Bin::kImTable, size);
  return true;
}

void ImageWriter::TryAssignConflictTableOffset(ImtConflictTable* table, size_t oat_index) {
  // No offset, or already assigned.
  if (table == nullptr || NativeRelocationAssigned(table)) {
    return;
  }
  CHECK(!IsInBootImage(table));
  // If the method is a conflict method we also want to assign the conflict table offset.
  ImageInfo& image_info = GetImageInfo(oat_index);
  const size_t size = table->ComputeSize(target_ptr_size_);
  native_object_relocations_.insert(std::make_pair(
      table,
      NativeObjectRelocation {
          oat_index,
          image_info.GetBinSlotSize(Bin::kIMTConflictTable),
          NativeObjectRelocationType::kIMTConflictTable
      }));
  image_info.IncrementBinSlotSize(Bin::kIMTConflictTable, size);
}

void ImageWriter::AssignMethodOffset(ArtMethod* method,
                                     NativeObjectRelocationType type,
                                     size_t oat_index) {
  DCHECK(!IsInBootImage(method));
  CHECK(!NativeRelocationAssigned(method)) << "Method " << method << " already assigned "
      << ArtMethod::PrettyMethod(method);
  if (method->IsRuntimeMethod()) {
    TryAssignConflictTableOffset(method->GetImtConflictTable(target_ptr_size_), oat_index);
  }
  ImageInfo& image_info = GetImageInfo(oat_index);
  Bin bin_type = BinTypeForNativeRelocationType(type);
  size_t offset = image_info.GetBinSlotSize(bin_type);
  native_object_relocations_.insert(
      std::make_pair(method, NativeObjectRelocation { oat_index, offset, type }));
  image_info.IncrementBinSlotSize(bin_type, ArtMethod::Size(target_ptr_size_));
}

class ImageWriter::LayoutHelper {
 public:
  explicit LayoutHelper(ImageWriter* image_writer)
      : image_writer_(image_writer) {
    bin_objects_.resize(image_writer_->image_infos_.size());
    for (auto& inner : bin_objects_) {
      inner.resize(enum_cast<size_t>(Bin::kMirrorCount));
    }
  }

  void ProcessDexFileObjects(Thread* self) REQUIRES_SHARED(Locks::mutator_lock_);
  void ProcessRoots(VariableSizedHandleScope* handles) REQUIRES_SHARED(Locks::mutator_lock_);
  void FinalizeInternTables() REQUIRES_SHARED(Locks::mutator_lock_);

  void VerifyImageBinSlotsAssigned() REQUIRES_SHARED(Locks::mutator_lock_);

  void FinalizeBinSlotOffsets() REQUIRES_SHARED(Locks::mutator_lock_);

  /*
   * Collects the string reference info necessary for loading app images.
   *
   * Because AppImages may contain interned strings that must be deduplicated
   * with previously interned strings when loading the app image, we need to
   * visit references to these strings and update them to point to the correct
   * string. To speed up the visiting of references at load time we include
   * a list of offsets to string references in the AppImage.
   */
  void CollectStringReferenceInfo() REQUIRES_SHARED(Locks::mutator_lock_);

 private:
  class CollectClassesVisitor;
  class CollectRootsVisitor;
  class CollectStringReferenceVisitor;
  class VisitReferencesVisitor;

  void ProcessInterns(Thread* self) REQUIRES_SHARED(Locks::mutator_lock_);
  void ProcessWorkQueue() REQUIRES_SHARED(Locks::mutator_lock_);

  using WorkQueue = std::deque<std::pair<ObjPtr<mirror::Object>, size_t>>;

  void VisitReferences(ObjPtr<mirror::Object> obj, size_t oat_index)
      REQUIRES_SHARED(Locks::mutator_lock_);
  bool TryAssignBinSlot(ObjPtr<mirror::Object> obj, size_t oat_index)
      REQUIRES_SHARED(Locks::mutator_lock_);

  ImageWriter* const image_writer_;

  // Work list of <object, oat_index> for objects. Everything in the queue must already be
  // assigned a bin slot.
  WorkQueue work_queue_;

  // Objects for individual bins. Indexed by `oat_index` and `bin`.
  // Cannot use ObjPtr<> because of invalidation in Heap::VisitObjects().
  dchecked_vector<dchecked_vector<dchecked_vector<mirror::Object*>>> bin_objects_;

  // Interns that do not have a corresponding StringId in any of the input dex files.
  // These shall be assigned to individual images based on the `oat_index` that we
  // see as we visit them during the work queue processing.
  dchecked_vector<mirror::String*> non_dex_file_interns_;
};

class ImageWriter::LayoutHelper::CollectClassesVisitor : public ClassVisitor {
 public:
  explicit CollectClassesVisitor(ImageWriter* image_writer)
      : image_writer_(image_writer),
        dex_files_(image_writer_->compiler_options_.GetDexFilesForOatFile()) {}

  bool operator()(ObjPtr<mirror::Class> klass) override REQUIRES_SHARED(Locks::mutator_lock_) {
    if (!image_writer_->IsInBootImage(klass.Ptr())) {
      ObjPtr<mirror::Class> component_type = klass;
      size_t dimension = 0u;
      while (component_type->IsArrayClass()) {
        ++dimension;
        component_type = component_type->GetComponentType();
      }
      DCHECK(!component_type->IsProxyClass());
      size_t dex_file_index;
      uint32_t class_def_index = 0u;
      if (UNLIKELY(component_type->IsPrimitive())) {
        DCHECK(image_writer_->compiler_options_.IsBootImage());
        dex_file_index = 0u;
        class_def_index = enum_cast<uint32_t>(component_type->GetPrimitiveType());
      } else {
        auto it = std::find(dex_files_.begin(), dex_files_.end(), &component_type->GetDexFile());
        DCHECK(it != dex_files_.end()) << klass->PrettyDescriptor();
        dex_file_index = std::distance(dex_files_.begin(), it) + 1u;  // 0 is for primitive types.
        class_def_index = component_type->GetDexClassDefIndex();
      }
      klasses_.push_back({klass, dex_file_index, class_def_index, dimension});
    }
    return true;
  }

  WorkQueue ProcessCollectedClasses(Thread* self) REQUIRES_SHARED(Locks::mutator_lock_) {
    std::sort(klasses_.begin(), klasses_.end());

    ImageWriter* image_writer = image_writer_;
    WorkQueue work_queue;
    size_t last_dex_file_index = static_cast<size_t>(-1);
    size_t last_oat_index = static_cast<size_t>(-1);
    for (const ClassEntry& entry : klasses_) {
      if (last_dex_file_index != entry.dex_file_index) {
        if (UNLIKELY(entry.dex_file_index == 0u)) {
          last_oat_index = GetDefaultOatIndex();  // Primitive type.
        } else {
          uint32_t dex_file_index = entry.dex_file_index - 1u;  // 0 is for primitive types.
          last_oat_index = image_writer->GetOatIndexForDexFile(dex_files_[dex_file_index]);
        }
        last_dex_file_index = entry.dex_file_index;
      }
      // Count the number of classes for class tables.
      image_writer->image_infos_[last_oat_index].class_table_size_ += 1u;
      work_queue.emplace_back(entry.klass, last_oat_index);
    }
    klasses_.clear();

    // Prepare image class tables.
    std::vector<mirror::Class*> boot_image_classes;
    if (image_writer->compiler_options_.IsAppImage()) {
      DCHECK_EQ(image_writer->image_infos_.size(), 1u);
      ImageInfo& image_info = image_writer->image_infos_[0];
      // Log the non-boot image class count for app image for debugging purposes.
      VLOG(compiler) << "Dex2Oat:AppImage:classCount = " << image_info.class_table_size_;
      // Collect boot image classes referenced by app class loader's class table.
      ClassTable* app_class_table = image_writer->GetAppClassLoader()->GetClassTable();
      ReaderMutexLock lock(self, app_class_table->lock_);
      DCHECK_EQ(app_class_table->classes_.size(), 1u);
      const ClassTable::ClassSet& app_class_set = app_class_table->classes_[0];
      DCHECK_GE(app_class_set.size(), image_info.class_table_size_);
      boot_image_classes.reserve(app_class_set.size() - image_info.class_table_size_);
      for (const ClassTable::TableSlot& slot : app_class_set) {
        mirror::Class* klass = slot.Read<kWithoutReadBarrier>().Ptr();
        if (image_writer->IsInBootImage(klass)) {
          boot_image_classes.push_back(klass);
        }
      }
      DCHECK_EQ(app_class_set.size() - image_info.class_table_size_, boot_image_classes.size());
      // Increase the app class table size to include referenced boot image classes.
      image_info.class_table_size_ = app_class_set.size();
    }
    for (ImageInfo& image_info : image_writer->image_infos_) {
      if (image_info.class_table_size_ != 0u) {
        // Make sure the class table shall be full by allocating a buffer of the right size.
        size_t buffer_size = static_cast<size_t>(
            ceil(image_info.class_table_size_ / kImageClassTableMaxLoadFactor));
        image_info.class_table_buffer_.reset(new ClassTable::TableSlot[buffer_size]);
        DCHECK(image_info.class_table_buffer_ != nullptr);
        image_info.class_table_.emplace(kImageClassTableMinLoadFactor,
                                        kImageClassTableMaxLoadFactor,
                                        image_info.class_table_buffer_.get(),
                                        buffer_size);
      }
    }
    for (const auto& pair : work_queue) {
      ObjPtr<mirror::Class> klass = pair.first->AsClass();
      size_t oat_index = pair.second;
      DCHECK(image_writer->image_infos_[oat_index].class_table_.has_value());
      ClassTable::ClassSet& class_table = *image_writer->image_infos_[oat_index].class_table_;
      uint32_t hash = ClassTable::TableSlot::HashDescriptor(klass);
      bool inserted = class_table.InsertWithHash(ClassTable::TableSlot(klass, hash), hash).second;
      DCHECK(inserted) << "Class " << klass->PrettyDescriptor()
          << " (" << klass.Ptr() << ") already inserted";
    }
    if (image_writer->compiler_options_.IsAppImage()) {
      DCHECK_EQ(image_writer->image_infos_.size(), 1u);
      ImageInfo& image_info = image_writer->image_infos_[0];
      if (image_info.class_table_size_ != 0u) {
        // Insert boot image class references to the app class table.
        // The order of insertion into the app class loader's ClassTable is non-deterministic,
        // so sort the boot image classes by the boot image address to get deterministic table.
        std::sort(boot_image_classes.begin(), boot_image_classes.end());
        DCHECK(image_info.class_table_.has_value());
        ClassTable::ClassSet& table = *image_info.class_table_;
        for (mirror::Class* klass : boot_image_classes) {
          uint32_t hash = ClassTable::TableSlot::HashDescriptor(klass);
          bool inserted = table.InsertWithHash(ClassTable::TableSlot(klass, hash), hash).second;
          DCHECK(inserted) << "Boot image class " << klass->PrettyDescriptor()
              << " (" << klass << ") already inserted";
        }
        DCHECK_EQ(table.size(), image_info.class_table_size_);
      }
    }
    for (ImageInfo& image_info : image_writer->image_infos_) {
      DCHECK_EQ(image_info.class_table_bytes_, 0u);
      if (image_info.class_table_size_ != 0u) {
        DCHECK(image_info.class_table_.has_value());
        DCHECK_EQ(image_info.class_table_->size(), image_info.class_table_size_);
        image_info.class_table_bytes_ = image_info.class_table_->WriteToMemory(nullptr);
        DCHECK_NE(image_info.class_table_bytes_, 0u);
      } else {
        DCHECK(!image_info.class_table_.has_value());
      }
    }

    return work_queue;
  }

 private:
  struct ClassEntry {
    ObjPtr<mirror::Class> klass;
    // We shall sort classes by dex file, class def index and array dimension.
    size_t dex_file_index;
    uint32_t class_def_index;
    size_t dimension;

    bool operator<(const ClassEntry& other) const {
      return std::tie(dex_file_index, class_def_index, dimension) <
             std::tie(other.dex_file_index, other.class_def_index, other.dimension);
    }
  };

  ImageWriter* const image_writer_;
  ArrayRef<const DexFile* const> dex_files_;
  std::deque<ClassEntry> klasses_;
};

class ImageWriter::LayoutHelper::CollectRootsVisitor {
 public:
  CollectRootsVisitor() = default;

  std::vector<ObjPtr<mirror::Object>> ReleaseRoots() {
    std::vector<ObjPtr<mirror::Object>> roots;
    roots.swap(roots_);
    return roots;
  }

  void VisitRootIfNonNull(StackReference<mirror::Object>* ref) {
    if (!ref->IsNull()) {
      roots_.push_back(ref->AsMirrorPtr());
    }
  }

 private:
  std::vector<ObjPtr<mirror::Object>> roots_;
};

class ImageWriter::LayoutHelper::CollectStringReferenceVisitor {
 public:
  explicit CollectStringReferenceVisitor(
      const ImageWriter* image_writer,
      size_t oat_index,
      std::vector<AppImageReferenceOffsetInfo>* const string_reference_offsets,
      ObjPtr<mirror::Object> current_obj)
      : image_writer_(image_writer),
        oat_index_(oat_index),
        string_reference_offsets_(string_reference_offsets),
        current_obj_(current_obj) {}

  void VisitRootIfNonNull(mirror::CompressedReference<mirror::Object>* root) const
      REQUIRES_SHARED(Locks::mutator_lock_) {
    if (!root->IsNull()) {
      VisitRoot(root);
    }
  }

  void VisitRoot(mirror::CompressedReference<mirror::Object>* root) const
      REQUIRES_SHARED(Locks::mutator_lock_)  {
    // Only dex caches have native String roots. These are collected separately.
    DCHECK(current_obj_->IsDexCache() ||
           !image_writer_->IsInternedAppImageStringReference(root->AsMirrorPtr()))
        << mirror::Object::PrettyTypeOf(current_obj_);
  }

  // Collects info for managed fields that reference managed Strings.
  void operator() (ObjPtr<mirror::Object> obj,
                   MemberOffset member_offset,
                   bool is_static ATTRIBUTE_UNUSED) const
      REQUIRES_SHARED(Locks::mutator_lock_) {
    ObjPtr<mirror::Object> referred_obj =
        obj->GetFieldObject<mirror::Object, kVerifyNone, kWithoutReadBarrier>(member_offset);

    if (image_writer_->IsInternedAppImageStringReference(referred_obj)) {
      size_t base_offset = image_writer_->GetImageOffset(current_obj_.Ptr(), oat_index_);
      string_reference_offsets_->emplace_back(base_offset, member_offset.Uint32Value());
    }
  }

  ALWAYS_INLINE
  void operator() (ObjPtr<mirror::Class> klass ATTRIBUTE_UNUSED,
                   ObjPtr<mirror::Reference> ref) const
      REQUIRES_SHARED(Locks::mutator_lock_) {
    operator()(ref, mirror::Reference::ReferentOffset(), /* is_static */ false);
  }

 private:
  const ImageWriter* const image_writer_;
  const size_t oat_index_;
  std::vector<AppImageReferenceOffsetInfo>* const string_reference_offsets_;
  const ObjPtr<mirror::Object> current_obj_;
};

class ImageWriter::LayoutHelper::VisitReferencesVisitor {
 public:
  VisitReferencesVisitor(LayoutHelper* helper, size_t oat_index)
      : helper_(helper), oat_index_(oat_index) {}

  // Fix up separately since we also need to fix up method entrypoints.
  ALWAYS_INLINE void VisitRootIfNonNull(mirror::CompressedReference<mirror::Object>* root) const
      REQUIRES_SHARED(Locks::mutator_lock_) {
    if (!root->IsNull()) {
      VisitRoot(root);
    }
  }

  ALWAYS_INLINE void VisitRoot(mirror::CompressedReference<mirror::Object>* root) const
      REQUIRES_SHARED(Locks::mutator_lock_) {
    root->Assign(VisitReference(root->AsMirrorPtr()));
  }

  ALWAYS_INLINE void operator() (ObjPtr<mirror::Object> obj,
                                 MemberOffset offset,
                                 bool is_static ATTRIBUTE_UNUSED) const
      REQUIRES_SHARED(Locks::mutator_lock_) {
    mirror::Object* ref =
        obj->GetFieldObject<mirror::Object, kVerifyNone, kWithoutReadBarrier>(offset);
    obj->SetFieldObject</*kTransactionActive*/false>(offset, VisitReference(ref));
  }

  ALWAYS_INLINE void operator() (ObjPtr<mirror::Class> klass ATTRIBUTE_UNUSED,
                                 ObjPtr<mirror::Reference> ref) const
      REQUIRES_SHARED(Locks::mutator_lock_) {
    operator()(ref, mirror::Reference::ReferentOffset(), /* is_static */ false);
  }

 private:
  mirror::Object* VisitReference(mirror::Object* ref) const REQUIRES_SHARED(Locks::mutator_lock_) {
    if (helper_->TryAssignBinSlot(ref, oat_index_)) {
      // Remember how many objects we're adding at the front of the queue as we want
      // to reverse that range to process these references in the order of addition.
      helper_->work_queue_.emplace_front(ref, oat_index_);
    }
    if (ClassLinker::kAppImageMayContainStrings &&
        helper_->image_writer_->compiler_options_.IsAppImage() &&
        helper_->image_writer_->IsInternedAppImageStringReference(ref)) {
      helper_->image_writer_->image_infos_[oat_index_].num_string_references_ += 1u;
    }
    return ref;
  }

  LayoutHelper* const helper_;
  const size_t oat_index_;
};

// Visit method pointer arrays in `klass` that were not inherited from its superclass.
template <typename Visitor>
static void VisitNewMethodPointerArrays(ObjPtr<mirror::Class> klass, Visitor&& visitor)
    REQUIRES_SHARED(Locks::mutator_lock_) {
  ObjPtr<mirror::Class> super = klass->GetSuperClass<kVerifyNone, kWithoutReadBarrier>();
  ObjPtr<mirror::PointerArray> vtable = klass->GetVTable<kVerifyNone, kWithoutReadBarrier>();
  if (vtable != nullptr &&
      (super == nullptr || vtable != super->GetVTable<kVerifyNone, kWithoutReadBarrier>())) {
    visitor(vtable);
  }
  int32_t iftable_count = klass->GetIfTableCount();
  int32_t super_iftable_count = (super != nullptr) ? super->GetIfTableCount() : 0;
  ObjPtr<mirror::IfTable> iftable = klass->GetIfTable<kVerifyNone, kWithoutReadBarrier>();
  ObjPtr<mirror::IfTable> super_iftable =
      (super != nullptr) ? super->GetIfTable<kVerifyNone, kWithoutReadBarrier>() : nullptr;
  for (int32_t i = 0; i < iftable_count; ++i) {
    ObjPtr<mirror::PointerArray> methods =
        iftable->GetMethodArrayOrNull<kVerifyNone, kWithoutReadBarrier>(i);
    ObjPtr<mirror::PointerArray> super_methods = (i < super_iftable_count)
        ? super_iftable->GetMethodArrayOrNull<kVerifyNone, kWithoutReadBarrier>(i)
        : nullptr;
    if (methods != super_methods) {
      DCHECK(methods != nullptr);
      if (i < super_iftable_count) {
        DCHECK(super_methods != nullptr);
        DCHECK_EQ(methods->GetLength(), super_methods->GetLength());
      }
      visitor(methods);
    }
  }
}

void ImageWriter::LayoutHelper::ProcessDexFileObjects(Thread* self) {
  Runtime* runtime = Runtime::Current();
  ClassLinker* class_linker = runtime->GetClassLinker();

  // To ensure deterministic output, populate the work queue with objects in a pre-defined order.
  // Note: If we decide to implement a profile-guided layout, this is the place to do so.

  // Get initial work queue with the image classes and assign their bin slots.
  CollectClassesVisitor visitor(image_writer_);
  class_linker->VisitClasses(&visitor);
  DCHECK(work_queue_.empty());
  work_queue_ = visitor.ProcessCollectedClasses(self);
  for (const std::pair<ObjPtr<mirror::Object>, size_t>& entry : work_queue_) {
    DCHECK(entry.first != nullptr);
    ObjPtr<mirror::Class> klass = entry.first->AsClass();
    size_t oat_index = entry.second;
    DCHECK(!image_writer_->IsInBootImage(klass.Ptr()));
    DCHECK(!image_writer_->IsImageBinSlotAssigned(klass.Ptr()));
    image_writer_->RecordNativeRelocations(klass, oat_index);
    Bin klass_bin = image_writer_->AssignImageBinSlot(klass.Ptr(), oat_index);
    bin_objects_[oat_index][enum_cast<size_t>(klass_bin)].push_back(klass.Ptr());

    auto method_pointer_array_visitor =
        [&](ObjPtr<mirror::PointerArray> pointer_array) REQUIRES_SHARED(Locks::mutator_lock_) {
          Bin bin = kBinObjects ? Bin::kMethodPointerArray : Bin::kRegular;
          image_writer_->AssignImageBinSlot(pointer_array.Ptr(), oat_index, bin);
          bin_objects_[oat_index][enum_cast<size_t>(bin)].push_back(pointer_array.Ptr());
          // No need to add to the work queue. The class reference, if not in the boot image
          // (that is, when compiling the primary boot image), is already in the work queue.
        };
    VisitNewMethodPointerArrays(klass, method_pointer_array_visitor);
  }

  // Assign bin slots to dex caches.
  for (const DexFile* dex_file : image_writer_->compiler_options_.GetDexFilesForOatFile()) {
    auto it = image_writer_->dex_file_oat_index_map_.find(dex_file);
    DCHECK(it != image_writer_->dex_file_oat_index_map_.end()) << dex_file->GetLocation();
    const size_t oat_index = it->second;
    // Assign bin slot to this file's dex cache and add it to the end of the work queue.
    ObjPtr<mirror::DexCache> dex_cache = class_linker->FindDexCache(self, *dex_file);
    DCHECK(dex_cache != nullptr);
    bool assigned = TryAssignBinSlot(dex_cache, oat_index);
    DCHECK(assigned);
    work_queue_.emplace_back(dex_cache, oat_index);
  }

  // Assign interns to images depending on the first dex file they appear in.
  // Record those that do not have a StringId in any dex file.
  ProcessInterns(self);

  // Since classes and dex caches have been assigned to their bins, when we process a class
  // we do not follow through the class references or dex caches, so we correctly process
  // only objects actually belonging to that class before taking a new class from the queue.
  // If multiple class statics reference the same object (directly or indirectly), the object
  // is treated as belonging to the first encountered referencing class.
  ProcessWorkQueue();
}

void ImageWriter::LayoutHelper::ProcessRoots(VariableSizedHandleScope* handles) {
  // Assing bin slots to the image objects referenced by `handles`, add them to the work queue
  // and process the work queue. These objects are the image roots and boot image live objects
  // and they reference other objects needed for the image, for example the array of dex cache
  // references, or the pre-allocated exceptions for the boot image.
  DCHECK(work_queue_.empty());
  CollectRootsVisitor visitor;
  handles->VisitRoots(visitor);
  for (ObjPtr<mirror::Object> root : visitor.ReleaseRoots()) {
    if (TryAssignBinSlot(root, GetDefaultOatIndex())) {
      work_queue_.emplace_back(root, GetDefaultOatIndex());
    }
  }
  ProcessWorkQueue();
}

void ImageWriter::LayoutHelper::ProcessInterns(Thread* self) {
  // String bins are empty at this point.
  DCHECK(std::all_of(bin_objects_.begin(),
                     bin_objects_.end(),
                     [](const auto& bins) {
                       return bins[enum_cast<size_t>(Bin::kString)].empty();
                     }));

  // There is only one non-boot image intern table and it's the last one.
  InternTable* const intern_table = Runtime::Current()->GetInternTable();
  MutexLock mu(self, *Locks::intern_table_lock_);
  DCHECK_EQ(std::count_if(intern_table->strong_interns_.tables_.begin(),
                          intern_table->strong_interns_.tables_.end(),
                          [](const InternTable::Table::InternalTable& table) {
                            return !table.IsBootImage();
                          }),
            1);
  DCHECK(!intern_table->strong_interns_.tables_.back().IsBootImage());
  const InternTable::UnorderedSet& intern_set = intern_table->strong_interns_.tables_.back().set_;

  // Assign bin slots to all interns with a corresponding StringId in one of the input dex files.
  ImageWriter* image_writer = image_writer_;
  for (const DexFile* dex_file : image_writer->compiler_options_.GetDexFilesForOatFile()) {
    auto it = image_writer->dex_file_oat_index_map_.find(dex_file);
    DCHECK(it != image_writer->dex_file_oat_index_map_.end()) << dex_file->GetLocation();
    const size_t oat_index = it->second;
    // Assign bin slots for strings defined in this dex file in StringId (lexicographical) order.
    auto& string_bin_objects = bin_objects_[oat_index][enum_cast<size_t>(Bin::kString)];
    for (size_t i = 0, count = dex_file->NumStringIds(); i != count; ++i) {
      uint32_t utf16_length;
      const char* utf8_data = dex_file->StringDataAndUtf16LengthByIdx(dex::StringIndex(i),
                                                                      &utf16_length);
      int32_t hash = ComputeUtf16HashFromModifiedUtf8(utf8_data, utf16_length);
      InternTable::Utf8String utf8_string(utf16_length, utf8_data, hash);
      auto intern_it = intern_set.find(utf8_string);
      if (intern_it != intern_set.end()) {
        mirror::String* string = intern_it->Read<kWithoutReadBarrier>();
        DCHECK(string != nullptr);
        DCHECK(!image_writer->IsInBootImage(string));
        if (!image_writer->IsImageBinSlotAssigned(string)) {
          Bin bin = image_writer->AssignImageBinSlot(string, oat_index);
          DCHECK_EQ(bin, Bin::kString);
          string_bin_objects.push_back(string);
        } else {
          // We have already seen this string in a previous dex file.
          DCHECK(dex_file != image_writer->compiler_options_.GetDexFilesForOatFile().front());
        }
      }
    }
  }

  // String bins have been filled with dex file interns. Record their numbers in image infos.
  DCHECK_EQ(bin_objects_.size(), image_writer_->image_infos_.size());
  size_t total_dex_file_interns = 0u;
  for (size_t oat_index = 0, size = bin_objects_.size(); oat_index != size; ++oat_index) {
    size_t num_dex_file_interns = bin_objects_[oat_index][enum_cast<size_t>(Bin::kString)].size();
    ImageInfo& image_info = image_writer_->GetImageInfo(oat_index);
    DCHECK_EQ(image_info.intern_table_size_, 0u);
    image_info.intern_table_size_ = num_dex_file_interns;
    total_dex_file_interns += num_dex_file_interns;
  }

  // Collect interns that do not have a corresponding StringId in any of the input dex files.
  non_dex_file_interns_.reserve(intern_set.size() - total_dex_file_interns);
  for (const GcRoot<mirror::String>& root : intern_set) {
    mirror::String* string = root.Read<kWithoutReadBarrier>();
    if (!image_writer->IsImageBinSlotAssigned(string)) {
      non_dex_file_interns_.push_back(string);
    }
  }
  DCHECK_EQ(intern_set.size(), total_dex_file_interns + non_dex_file_interns_.size());
}

void ImageWriter::LayoutHelper::FinalizeInternTables() {
  // Remove interns that do not have a bin slot assigned. These correspond
  // to the DexCache locations excluded in VerifyImageBinSlotsAssigned().
  ImageWriter* image_writer = image_writer_;
  auto retained_end = std::remove_if(
      non_dex_file_interns_.begin(),
      non_dex_file_interns_.end(),
      [=](mirror::String* string) REQUIRES_SHARED(Locks::mutator_lock_) {
        return !image_writer->IsImageBinSlotAssigned(string);
      });
  non_dex_file_interns_.resize(std::distance(non_dex_file_interns_.begin(), retained_end));

  // Sort `non_dex_file_interns_` based on oat index and bin offset.
  ArrayRef<mirror::String*> non_dex_file_interns(non_dex_file_interns_);
  std::sort(non_dex_file_interns.begin(),
            non_dex_file_interns.end(),
            [=](mirror::String* lhs, mirror::String* rhs) REQUIRES_SHARED(Locks::mutator_lock_) {
              size_t lhs_oat_index = image_writer->GetOatIndex(lhs);
              size_t rhs_oat_index = image_writer->GetOatIndex(rhs);
              if (lhs_oat_index != rhs_oat_index) {
                return lhs_oat_index < rhs_oat_index;
              }
              BinSlot lhs_bin_slot = image_writer->GetImageBinSlot(lhs, lhs_oat_index);
              BinSlot rhs_bin_slot = image_writer->GetImageBinSlot(rhs, rhs_oat_index);
              return lhs_bin_slot < rhs_bin_slot;
            });

  // Allocate and fill intern tables.
  size_t ndfi_index = 0u;
  DCHECK_EQ(bin_objects_.size(), image_writer->image_infos_.size());
  for (size_t oat_index = 0, size = bin_objects_.size(); oat_index != size; ++oat_index) {
    // Find the end of `non_dex_file_interns` for this oat file.
    size_t ndfi_end = ndfi_index;
    while (ndfi_end != non_dex_file_interns.size() &&
           image_writer->GetOatIndex(non_dex_file_interns[ndfi_end]) == oat_index) {
      ++ndfi_end;
    }

    // Calculate final intern table size.
    ImageInfo& image_info = image_writer->GetImageInfo(oat_index);
    DCHECK_EQ(image_info.intern_table_bytes_, 0u);
    size_t num_dex_file_interns = image_info.intern_table_size_;
    size_t num_non_dex_file_interns = ndfi_end - ndfi_index;
    image_info.intern_table_size_ = num_dex_file_interns + num_non_dex_file_interns;
    if (image_info.intern_table_size_ != 0u) {
      // Make sure the intern table shall be full by allocating a buffer of the right size.
      size_t buffer_size = static_cast<size_t>(
          ceil(image_info.intern_table_size_ / kImageInternTableMaxLoadFactor));
      image_info.intern_table_buffer_.reset(new GcRoot<mirror::String>[buffer_size]);
      DCHECK(image_info.intern_table_buffer_ != nullptr);
      image_info.intern_table_.emplace(kImageInternTableMinLoadFactor,
                                       kImageInternTableMaxLoadFactor,
                                       image_info.intern_table_buffer_.get(),
                                       buffer_size);

      // Fill the intern table. Dex file interns are at the start of the bin_objects[.][kString].
      InternTable::UnorderedSet& table = *image_info.intern_table_;
      const auto& oat_file_strings = bin_objects_[oat_index][enum_cast<size_t>(Bin::kString)];
      DCHECK_LE(num_dex_file_interns, oat_file_strings.size());
      ArrayRef<mirror::Object* const> dex_file_interns(
          oat_file_strings.data(), num_dex_file_interns);
      for (mirror::Object* string : dex_file_interns) {
        bool inserted = table.insert(GcRoot<mirror::String>(string->AsString())).second;
        DCHECK(inserted) << "String already inserted: " << string->AsString()->ToModifiedUtf8();
      }
      ArrayRef<mirror::String*> current_non_dex_file_interns =
          non_dex_file_interns.SubArray(ndfi_index, num_non_dex_file_interns);
      for (mirror::String* string : current_non_dex_file_interns) {
        bool inserted = table.insert(GcRoot<mirror::String>(string)).second;
        DCHECK(inserted) << "String already inserted: " << string->ToModifiedUtf8();
      }

      // Record the intern table size in bytes.
      image_info.intern_table_bytes_ = table.WriteToMemory(nullptr);
    }

    ndfi_index = ndfi_end;
  }
}

void ImageWriter::LayoutHelper::ProcessWorkQueue() {
  while (!work_queue_.empty()) {
    std::pair<ObjPtr<mirror::Object>, size_t> pair = work_queue_.front();
    work_queue_.pop_front();
    VisitReferences(/*obj=*/ pair.first, /*oat_index=*/ pair.second);
  }
}

void ImageWriter::LayoutHelper::VerifyImageBinSlotsAssigned() {
  std::vector<mirror::Object*> carveout;
  if (image_writer_->compiler_options_.IsAppImage()) {
    // Exclude boot class path dex caches that are not part of the boot image.
    // Also exclude their locations if they have not been visited through another path.
    ClassLinker* class_linker = Runtime::Current()->GetClassLinker();
    Thread* self = Thread::Current();
    ReaderMutexLock mu(self, *Locks::dex_lock_);
    for (const ClassLinker::DexCacheData& data : class_linker->GetDexCachesData()) {
      ObjPtr<mirror::DexCache> dex_cache =
          ObjPtr<mirror::DexCache>::DownCast(self->DecodeJObject(data.weak_root));
      if (dex_cache == nullptr ||
          image_writer_->IsInBootImage(dex_cache.Ptr()) ||
          ContainsElement(image_writer_->compiler_options_.GetDexFilesForOatFile(),
                          dex_cache->GetDexFile())) {
        continue;
      }
      CHECK(!image_writer_->IsImageBinSlotAssigned(dex_cache.Ptr()));
      carveout.push_back(dex_cache.Ptr());
      ObjPtr<mirror::String> location = dex_cache->GetLocation();
      if (!image_writer_->IsImageBinSlotAssigned(location.Ptr())) {
        carveout.push_back(location.Ptr());
      }
    }
  }

  std::vector<mirror::Object*> missed_objects;
  auto ensure_bin_slots_assigned = [&](mirror::Object* obj)
      REQUIRES_SHARED(Locks::mutator_lock_) {
    if (!image_writer_->IsInBootImage(obj)) {
      if (!UNLIKELY(image_writer_->IsImageBinSlotAssigned(obj))) {
        // Ignore the `carveout` objects.
        if (ContainsElement(carveout, obj)) {
          return;
        }
        // Ignore finalizer references for the dalvik.system.DexFile objects referenced by
        // the app class loader.
        if (obj->IsFinalizerReferenceInstance()) {
          ArtField* ref_field =
              obj->GetClass()->FindInstanceField("referent", "Ljava/lang/Object;");
          CHECK(ref_field != nullptr);
          ObjPtr<mirror::Object> ref = ref_field->GetObject(obj);
          CHECK(ref != nullptr);
          CHECK(image_writer_->IsImageBinSlotAssigned(ref.Ptr()));
          ObjPtr<mirror::Class> klass = ref->GetClass();
          CHECK(klass == WellKnownClasses::ToClass(WellKnownClasses::dalvik_system_DexFile));
          // Note: The app class loader is used only for checking against the runtime
          // class loader, the dex file cookie is cleared and therefore we do not need
          // to run the finalizer even if we implement app image objects collection.
          ArtField* field = jni::DecodeArtField(WellKnownClasses::dalvik_system_DexFile_cookie);
          CHECK(field->GetObject(ref) == nullptr);
          return;
        }
        if (obj->IsString()) {
          // Ignore interned strings. These may come from reflection interning method names.
          // TODO: Make dex file strings weak interns and GC them before writing the image.
          Runtime* runtime = Runtime::Current();
          ObjPtr<mirror::String> interned =
              runtime->GetInternTable()->LookupStrong(Thread::Current(), obj->AsString());
          if (interned == obj) {
            return;
          }
        }
        missed_objects.push_back(obj);
      }
    }
  };
  Runtime::Current()->GetHeap()->VisitObjects(ensure_bin_slots_assigned);
  if (!missed_objects.empty()) {
    const gc::Verification* v = Runtime::Current()->GetHeap()->GetVerification();
    size_t num_missed_objects = missed_objects.size();
    size_t num_paths = std::min<size_t>(num_missed_objects, 5u);  // Do not flood the output.
    ArrayRef<mirror::Object*> missed_objects_head =
        ArrayRef<mirror::Object*>(missed_objects).SubArray(/*pos=*/ 0u, /*length=*/ num_paths);
    for (mirror::Object* obj : missed_objects_head) {
      LOG(ERROR) << "Image object without assigned bin slot: "
          << mirror::Object::PrettyTypeOf(obj) << " " << obj
          << " " << v->FirstPathFromRootSet(obj);
    }
    LOG(FATAL) << "Found " << num_missed_objects << " objects without assigned bin slots.";
  }
}

void ImageWriter::LayoutHelper::FinalizeBinSlotOffsets() {
  // Calculate bin slot offsets and adjust for region padding if needed.
  const size_t region_size = image_writer_->region_size_;
  const size_t num_image_infos = image_writer_->image_infos_.size();
  for (size_t oat_index = 0; oat_index != num_image_infos; ++oat_index) {
    ImageInfo& image_info = image_writer_->image_infos_[oat_index];
    size_t bin_offset = image_writer_->image_objects_offset_begin_;

    for (size_t i = 0; i != kNumberOfBins; ++i) {
      Bin bin = enum_cast<Bin>(i);
      switch (bin) {
        case Bin::kArtMethodClean:
        case Bin::kArtMethodDirty: {
          bin_offset = RoundUp(bin_offset, ArtMethod::Alignment(image_writer_->target_ptr_size_));
          break;
        }
        case Bin::kImTable:
        case Bin::kIMTConflictTable: {
          bin_offset = RoundUp(bin_offset, static_cast<size_t>(image_writer_->target_ptr_size_));
          break;
        }
        default: {
          // Normal alignment.
        }
      }
      image_info.bin_slot_offsets_[i] = bin_offset;

      // If the bin is for mirror objects, we may need to add region padding and update offsets.
      if (i < enum_cast<size_t>(Bin::kMirrorCount) && region_size != 0u) {
        const size_t offset_after_header = bin_offset - sizeof(ImageHeader);
        size_t remaining_space =
            RoundUp(offset_after_header + 1u, region_size) - offset_after_header;
        // Exercise the loop below in debug builds to get coverage.
        if (kIsDebugBuild || remaining_space < image_info.bin_slot_sizes_[i]) {
          // The bin crosses a region boundary. Add padding if needed.
          size_t object_offset = 0u;
          size_t padding = 0u;
          for (mirror::Object* object : bin_objects_[oat_index][i]) {
            BinSlot bin_slot = image_writer_->GetImageBinSlot(object, oat_index);
            DCHECK_EQ(enum_cast<size_t>(bin_slot.GetBin()), i);
            DCHECK_EQ(bin_slot.GetOffset() + padding, object_offset);
            size_t object_size = RoundUp(object->SizeOf<kVerifyNone>(), kObjectAlignment);

            auto add_padding = [&](bool tail_region) {
              DCHECK_NE(remaining_space, 0u);
              DCHECK_LT(remaining_space, region_size);
              DCHECK_ALIGNED(remaining_space, kObjectAlignment);
              // TODO When copying to heap regions, leave the tail region padding zero-filled.
              if (!tail_region || true) {
                image_info.padding_offsets_.push_back(bin_offset + object_offset);
              }
              image_info.bin_slot_sizes_[i] += remaining_space;
              padding += remaining_space;
              object_offset += remaining_space;
              remaining_space = region_size;
            };
            if (object_size > remaining_space) {
              // Padding needed if we're not at region boundary (with a multi-region object).
              if (remaining_space != region_size) {
                // TODO: Instead of adding padding, we should consider reordering the bins
                // or objects to reduce wasted space.
                add_padding(/*tail_region=*/ false);
              }
              DCHECK_EQ(remaining_space, region_size);
              // For huge objects, adjust the remaining space to hold the object and some more.
              if (object_size > region_size) {
                remaining_space = RoundUp(object_size + 1u, region_size);
              }
            } else if (remaining_space == object_size) {
              // Move to the next region, no padding needed.
              remaining_space += region_size;
            }
            DCHECK_GT(remaining_space, object_size);
            remaining_space -= object_size;
            image_writer_->UpdateImageBinSlotOffset(object, oat_index, object_offset);
            object_offset += object_size;
            // Add padding to the tail region of huge objects if not region-aligned.
            if (object_size > region_size && remaining_space != region_size) {
              DCHECK(!IsAlignedParam(object_size, region_size));
              add_padding(/*tail_region=*/ true);
            }
          }
          image_writer_->region_alignment_wasted_ += padding;
          image_info.image_end_ += padding;
        }
      }
      bin_offset += image_info.bin_slot_sizes_[i];
    }
    // NOTE: There may be additional padding between the bin slots and the intern table.
    DCHECK_EQ(
        image_info.image_end_,
        image_info.GetBinSizeSum(Bin::kMirrorCount) + image_writer_->image_objects_offset_begin_);
  }

  VLOG(image) << "Space wasted for region alignment " << image_writer_->region_alignment_wasted_;
}

void ImageWriter::LayoutHelper::CollectStringReferenceInfo() {
  size_t total_string_refs = 0u;

  const size_t num_image_infos = image_writer_->image_infos_.size();
  for (size_t oat_index = 0; oat_index != num_image_infos; ++oat_index) {
    ImageInfo& image_info = image_writer_->image_infos_[oat_index];
    DCHECK(image_info.string_reference_offsets_.empty());
    image_info.string_reference_offsets_.reserve(image_info.num_string_references_);

    for (size_t i = 0; i < enum_cast<size_t>(Bin::kMirrorCount); ++i) {
      for (mirror::Object* obj : bin_objects_[oat_index][i]) {
        CollectStringReferenceVisitor visitor(image_writer_,
                                              oat_index,
                                              &image_info.string_reference_offsets_,
                                              obj);
        /*
         * References to managed strings can occur either in the managed heap or in
         * native memory regions. Information about managed references is collected
         * by the CollectStringReferenceVisitor and directly added to the image info.
         *
         * Native references to managed strings can only occur through DexCache
         * objects. This is verified by the visitor in debug mode and the references
         * are collected separately below.
         */
        obj->VisitReferences</*kVisitNativeRoots=*/ kIsDebugBuild,
                             kVerifyNone,
                             kWithoutReadBarrier>(visitor, visitor);
      }
    }

    total_string_refs += image_info.string_reference_offsets_.size();

    // Check that we collected the same number of string references as we saw in the previous pass.
    CHECK_EQ(image_info.string_reference_offsets_.size(), image_info.num_string_references_);
  }

  VLOG(compiler) << "Dex2Oat:AppImage:stringReferences = " << total_string_refs;
}

void ImageWriter::LayoutHelper::VisitReferences(ObjPtr<mirror::Object> obj, size_t oat_index) {
  size_t old_work_queue_size = work_queue_.size();
  VisitReferencesVisitor visitor(this, oat_index);
  // Walk references and assign bin slots for them.
  obj->VisitReferences</*kVisitNativeRoots=*/ true, kVerifyNone, kWithoutReadBarrier>(
      visitor,
      visitor);
  // Put the added references in the queue in the order in which they were added.
  // The visitor just pushes them to the front as it visits them.
  DCHECK_LE(old_work_queue_size, work_queue_.size());
  size_t num_added = work_queue_.size() - old_work_queue_size;
  std::reverse(work_queue_.begin(), work_queue_.begin() + num_added);
}

bool ImageWriter::LayoutHelper::TryAssignBinSlot(ObjPtr<mirror::Object> obj, size_t oat_index) {
  if (obj == nullptr || image_writer_->IsInBootImage(obj.Ptr())) {
    // Object is null or already in the image, there is no work to do.
    return false;
  }
  bool assigned = false;
  if (!image_writer_->IsImageBinSlotAssigned(obj.Ptr())) {
    Bin bin = image_writer_->AssignImageBinSlot(obj.Ptr(), oat_index);
    bin_objects_[oat_index][enum_cast<size_t>(bin)].push_back(obj.Ptr());
    assigned = true;
  }
  return assigned;
}

static ObjPtr<ObjectArray<Object>> GetBootImageLiveObjects() REQUIRES_SHARED(Locks::mutator_lock_) {
  gc::Heap* heap = Runtime::Current()->GetHeap();
  DCHECK(!heap->GetBootImageSpaces().empty());
  const ImageHeader& primary_header = heap->GetBootImageSpaces().front()->GetImageHeader();
  return ObjPtr<ObjectArray<Object>>::DownCast(
      primary_header.GetImageRoot<kWithReadBarrier>(ImageHeader::kBootImageLiveObjects));
}

void ImageWriter::CalculateNewObjectOffsets() {
  Thread* const self = Thread::Current();
  Runtime* const runtime = Runtime::Current();
  VariableSizedHandleScope handles(self);
  MutableHandle<ObjectArray<Object>> boot_image_live_objects = handles.NewHandle(
      compiler_options_.IsBootImage()
          ? AllocateBootImageLiveObjects(self, runtime)
          : (compiler_options_.IsBootImageExtension() ? GetBootImageLiveObjects() : nullptr));
  std::vector<Handle<ObjectArray<Object>>> image_roots;
  for (size_t i = 0, size = oat_filenames_.size(); i != size; ++i) {
    image_roots.push_back(handles.NewHandle(CreateImageRoots(i, boot_image_live_objects)));
  }

  gc::Heap* const heap = runtime->GetHeap();

  // Leave space for the header, but do not write it yet, we need to
  // know where image_roots is going to end up
  image_objects_offset_begin_ = RoundUp(sizeof(ImageHeader), kObjectAlignment);  // 64-bit-alignment

  // Write the image runtime methods.
  image_methods_[ImageHeader::kResolutionMethod] = runtime->GetResolutionMethod();
  image_methods_[ImageHeader::kImtConflictMethod] = runtime->GetImtConflictMethod();
  image_methods_[ImageHeader::kImtUnimplementedMethod] = runtime->GetImtUnimplementedMethod();
  image_methods_[ImageHeader::kSaveAllCalleeSavesMethod] =
      runtime->GetCalleeSaveMethod(CalleeSaveType::kSaveAllCalleeSaves);
  image_methods_[ImageHeader::kSaveRefsOnlyMethod] =
      runtime->GetCalleeSaveMethod(CalleeSaveType::kSaveRefsOnly);
  image_methods_[ImageHeader::kSaveRefsAndArgsMethod] =
      runtime->GetCalleeSaveMethod(CalleeSaveType::kSaveRefsAndArgs);
  image_methods_[ImageHeader::kSaveEverythingMethod] =
      runtime->GetCalleeSaveMethod(CalleeSaveType::kSaveEverything);
  image_methods_[ImageHeader::kSaveEverythingMethodForClinit] =
      runtime->GetCalleeSaveMethod(CalleeSaveType::kSaveEverythingForClinit);
  image_methods_[ImageHeader::kSaveEverythingMethodForSuspendCheck] =
      runtime->GetCalleeSaveMethod(CalleeSaveType::kSaveEverythingForSuspendCheck);
  // Visit image methods first to have the main runtime methods in the first image.
  for (auto* m : image_methods_) {
    CHECK(m != nullptr);
    CHECK(m->IsRuntimeMethod());
    DCHECK_EQ(!compiler_options_.IsBootImage(), IsInBootImage(m))
        << "Trampolines should be in boot image";
    if (!IsInBootImage(m)) {
      AssignMethodOffset(m, NativeObjectRelocationType::kRuntimeMethod, GetDefaultOatIndex());
    }
  }

  // Deflate monitors before we visit roots since deflating acquires the monitor lock. Acquiring
  // this lock while holding other locks may cause lock order violations.
  {
    auto deflate_monitor = [](mirror::Object* obj) REQUIRES_SHARED(Locks::mutator_lock_) {
      Monitor::Deflate(Thread::Current(), obj);
    };
    heap->VisitObjects(deflate_monitor);
  }

  // From this point on, there shall be no GC anymore and no objects shall be allocated.
  // We can now assign a BitSlot to each object and store it in its lockword.

  LayoutHelper layout_helper(this);
  layout_helper.ProcessDexFileObjects(self);
  layout_helper.ProcessRoots(&handles);
  layout_helper.FinalizeInternTables();

  // Verify that all objects have assigned image bin slots.
  layout_helper.VerifyImageBinSlotsAssigned();

  // Finalize bin slot offsets. This may add padding for regions.
  layout_helper.FinalizeBinSlotOffsets();

  // Collect string reference info for app images.
  if (ClassLinker::kAppImageMayContainStrings && compiler_options_.IsAppImage()) {
    layout_helper.CollectStringReferenceInfo();
  }

  // Calculate image offsets.
  size_t image_offset = 0;
  for (ImageInfo& image_info : image_infos_) {
    image_info.image_begin_ = global_image_begin_ + image_offset;
    image_info.image_offset_ = image_offset;
    image_info.image_size_ = RoundUp(image_info.CreateImageSections().first, kPageSize);
    // There should be no gaps until the next image.
    image_offset += image_info.image_size_;
  }

  size_t i = 0;
  for (ImageInfo& image_info : image_infos_) {
    image_info.image_roots_address_ = PointerToLowMemUInt32(GetImageAddress(image_roots[i].Get()));
    i++;
  }

  // Update the native relocations by adding their bin sums.
  for (auto& pair : native_object_relocations_) {
    NativeObjectRelocation& relocation = pair.second;
    Bin bin_type = BinTypeForNativeRelocationType(relocation.type);
    ImageInfo& image_info = GetImageInfo(relocation.oat_index);
    relocation.offset += image_info.GetBinSlotOffset(bin_type);
  }

  // Remember the boot image live objects as raw pointer. No GC can happen anymore.
  boot_image_live_objects_ = boot_image_live_objects.Get();
}

std::pair<size_t, std::vector<ImageSection>> ImageWriter::ImageInfo::CreateImageSections() const {
  std::vector<ImageSection> sections(ImageHeader::kSectionCount);

  // Do not round up any sections here that are represented by the bins since it
  // will break offsets.

  /*
   * Objects section
   */
  sections[ImageHeader::kSectionObjects] =
      ImageSection(0u, image_end_);

  /*
   * Field section
   */
  sections[ImageHeader::kSectionArtFields] =
      ImageSection(GetBinSlotOffset(Bin::kArtField), GetBinSlotSize(Bin::kArtField));

  /*
   * Method section
   */
  sections[ImageHeader::kSectionArtMethods] =
      ImageSection(GetBinSlotOffset(Bin::kArtMethodClean),
                   GetBinSlotSize(Bin::kArtMethodClean) +
                   GetBinSlotSize(Bin::kArtMethodDirty));

  /*
   * IMT section
   */
  sections[ImageHeader::kSectionImTables] =
      ImageSection(GetBinSlotOffset(Bin::kImTable), GetBinSlotSize(Bin::kImTable));

  /*
   * Conflict Tables section
   */
  sections[ImageHeader::kSectionIMTConflictTables] =
      ImageSection(GetBinSlotOffset(Bin::kIMTConflictTable), GetBinSlotSize(Bin::kIMTConflictTable));

  /*
   * Runtime Methods section
   */
  sections[ImageHeader::kSectionRuntimeMethods] =
      ImageSection(GetBinSlotOffset(Bin::kRuntimeMethod), GetBinSlotSize(Bin::kRuntimeMethod));

  /*
   * Interned Strings section
   */

  // Round up to the alignment the string table expects. See HashSet::WriteToMemory.
  size_t cur_pos = RoundUp(sections[ImageHeader::kSectionRuntimeMethods].End(), sizeof(uint64_t));

  const ImageSection& interned_strings_section =
      sections[ImageHeader::kSectionInternedStrings] =
          ImageSection(cur_pos, intern_table_bytes_);

  /*
   * Class Table section
   */

  // Obtain the new position and round it up to the appropriate alignment.
  cur_pos = RoundUp(interned_strings_section.End(), sizeof(uint64_t));

  const ImageSection& class_table_section =
      sections[ImageHeader::kSectionClassTable] =
          ImageSection(cur_pos, class_table_bytes_);

  /*
   * String Field Offsets section
   */

  // Round up to the alignment of the offsets we are going to store.
  cur_pos = RoundUp(class_table_section.End(), sizeof(uint32_t));

  // The size of string_reference_offsets_ can't be used here because it hasn't
  // been filled with AppImageReferenceOffsetInfo objects yet.  The
  // num_string_references_ value is calculated separately, before we can
  // compute the actual offsets.
  const ImageSection& string_reference_offsets =
      sections[ImageHeader::kSectionStringReferenceOffsets] =
          ImageSection(cur_pos, sizeof(string_reference_offsets_[0]) * num_string_references_);

  /*
   * Metadata section.
   */

  // Round up to the alignment of the offsets we are going to store.
  cur_pos = RoundUp(string_reference_offsets.End(), sizeof(uint32_t));

  const ImageSection& metadata_section =
      sections[ImageHeader::kSectionMetadata] =
          ImageSection(cur_pos, GetBinSlotSize(Bin::kMetadata));

  // Return the number of bytes described by these sections, and the sections
  // themselves.
  return make_pair(metadata_section.End(), std::move(sections));
}

void ImageWriter::CreateHeader(size_t oat_index, size_t component_count) {
  ImageInfo& image_info = GetImageInfo(oat_index);
  const uint8_t* oat_file_begin = image_info.oat_file_begin_;
  const uint8_t* oat_file_end = oat_file_begin + image_info.oat_loaded_size_;
  const uint8_t* oat_data_end = image_info.oat_data_begin_ + image_info.oat_size_;

  uint32_t image_reservation_size = image_info.image_size_;
  DCHECK_ALIGNED(image_reservation_size, kPageSize);
  uint32_t current_component_count = 1u;
  if (compiler_options_.IsAppImage()) {
    DCHECK_EQ(oat_index, 0u);
    DCHECK_EQ(component_count, current_component_count);
  } else {
    DCHECK(image_infos_.size() == 1u || image_infos_.size() == component_count)
        << image_infos_.size() << " " << component_count;
    if (oat_index == 0u) {
      const ImageInfo& last_info = image_infos_.back();
      const uint8_t* end = last_info.oat_file_begin_ + last_info.oat_loaded_size_;
      DCHECK_ALIGNED(image_info.image_begin_, kPageSize);
      image_reservation_size =
          dchecked_integral_cast<uint32_t>(RoundUp(end - image_info.image_begin_, kPageSize));
      current_component_count = component_count;
    } else {
      image_reservation_size = 0u;
      current_component_count = 0u;
    }
  }

  // Compute boot image checksums for the primary component, leave as 0 otherwise.
  uint32_t boot_image_components = 0u;
  uint32_t boot_image_checksums = 0u;
  if (oat_index == 0u) {
    const std::vector<gc::space::ImageSpace*>& image_spaces =
        Runtime::Current()->GetHeap()->GetBootImageSpaces();
    DCHECK_EQ(image_spaces.empty(), compiler_options_.IsBootImage());
    for (size_t i = 0u, size = image_spaces.size(); i != size; ) {
      const ImageHeader& header = image_spaces[i]->GetImageHeader();
      boot_image_components += header.GetComponentCount();
      boot_image_checksums ^= header.GetImageChecksum();
      DCHECK_LE(header.GetImageSpaceCount(), size - i);
      i += header.GetImageSpaceCount();
    }
  }

  // Create the image sections.
  auto section_info_pair = image_info.CreateImageSections();
  const size_t image_end = section_info_pair.first;
  std::vector<ImageSection>& sections = section_info_pair.second;

  // Finally bitmap section.
  const size_t bitmap_bytes = image_info.image_bitmap_.Size();
  auto* bitmap_section = &sections[ImageHeader::kSectionImageBitmap];
  *bitmap_section = ImageSection(RoundUp(image_end, kPageSize), RoundUp(bitmap_bytes, kPageSize));
  if (VLOG_IS_ON(compiler)) {
    LOG(INFO) << "Creating header for " << oat_filenames_[oat_index];
    size_t idx = 0;
    for (const ImageSection& section : sections) {
      LOG(INFO) << static_cast<ImageHeader::ImageSections>(idx) << " " << section;
      ++idx;
    }
    LOG(INFO) << "Methods: clean=" << clean_methods_ << " dirty=" << dirty_methods_;
    LOG(INFO) << "Image roots address=" << std::hex << image_info.image_roots_address_ << std::dec;
    LOG(INFO) << "Image begin=" << std::hex << reinterpret_cast<uintptr_t>(global_image_begin_)
              << " Image offset=" << image_info.image_offset_ << std::dec;
    LOG(INFO) << "Oat file begin=" << std::hex << reinterpret_cast<uintptr_t>(oat_file_begin)
              << " Oat data begin=" << reinterpret_cast<uintptr_t>(image_info.oat_data_begin_)
              << " Oat data end=" << reinterpret_cast<uintptr_t>(oat_data_end)
              << " Oat file end=" << reinterpret_cast<uintptr_t>(oat_file_end);
  }

  // Create the header, leave 0 for data size since we will fill this in as we are writing the
  // image.
  new (image_info.image_.Begin()) ImageHeader(
      image_reservation_size,
      current_component_count,
      PointerToLowMemUInt32(image_info.image_begin_),
      image_end,
      sections.data(),
      image_info.image_roots_address_,
      image_info.oat_checksum_,
      PointerToLowMemUInt32(oat_file_begin),
      PointerToLowMemUInt32(image_info.oat_data_begin_),
      PointerToLowMemUInt32(oat_data_end),
      PointerToLowMemUInt32(oat_file_end),
      boot_image_begin_,
      boot_image_size_,
      boot_image_components,
      boot_image_checksums,
      static_cast<uint32_t>(target_ptr_size_));
}

ArtMethod* ImageWriter::GetImageMethodAddress(ArtMethod* method) {
  NativeObjectRelocation relocation = GetNativeRelocation(method);
  const ImageInfo& image_info = GetImageInfo(relocation.oat_index);
  CHECK_GE(relocation.offset, image_info.image_end_) << "ArtMethods should be after Objects";
  return reinterpret_cast<ArtMethod*>(image_info.image_begin_ + relocation.offset);
}

const void* ImageWriter::GetIntrinsicReferenceAddress(uint32_t intrinsic_data) {
  DCHECK(compiler_options_.IsBootImage());
  switch (IntrinsicObjects::DecodePatchType(intrinsic_data)) {
    case IntrinsicObjects::PatchType::kIntegerValueOfArray: {
      const uint8_t* base_address =
          reinterpret_cast<const uint8_t*>(GetImageAddress(boot_image_live_objects_));
      MemberOffset data_offset =
          IntrinsicObjects::GetIntegerValueOfArrayDataOffset(boot_image_live_objects_);
      return base_address + data_offset.Uint32Value();
    }
    case IntrinsicObjects::PatchType::kIntegerValueOfObject: {
      uint32_t index = IntrinsicObjects::DecodePatchIndex(intrinsic_data);
      ObjPtr<mirror::Object> value =
          IntrinsicObjects::GetIntegerValueOfObject(boot_image_live_objects_, index);
      return GetImageAddress(value.Ptr());
    }
  }
  LOG(FATAL) << "UNREACHABLE";
  UNREACHABLE();
}


class ImageWriter::FixupRootVisitor : public RootVisitor {
 public:
  explicit FixupRootVisitor(ImageWriter* image_writer) : image_writer_(image_writer) {
  }

  void VisitRoots(mirror::Object*** roots ATTRIBUTE_UNUSED,
                  size_t count ATTRIBUTE_UNUSED,
                  const RootInfo& info ATTRIBUTE_UNUSED)
      override REQUIRES_SHARED(Locks::mutator_lock_) {
    LOG(FATAL) << "Unsupported";
  }

  void VisitRoots(mirror::CompressedReference<mirror::Object>** roots,
                  size_t count,
                  const RootInfo& info ATTRIBUTE_UNUSED)
      override REQUIRES_SHARED(Locks::mutator_lock_) {
    for (size_t i = 0; i < count; ++i) {
      // Copy the reference. Since we do not have the address for recording the relocation,
      // it needs to be recorded explicitly by the user of FixupRootVisitor.
      ObjPtr<mirror::Object> old_ptr = roots[i]->AsMirrorPtr();
      roots[i]->Assign(image_writer_->GetImageAddress(old_ptr.Ptr()));
    }
  }

 private:
  ImageWriter* const image_writer_;
};

void ImageWriter::CopyAndFixupImTable(ImTable* orig, ImTable* copy) {
  for (size_t i = 0; i < ImTable::kSize; ++i) {
    ArtMethod* method = orig->Get(i, target_ptr_size_);
    void** address = reinterpret_cast<void**>(copy->AddressOfElement(i, target_ptr_size_));
    CopyAndFixupPointer(address, method);
    DCHECK_EQ(copy->Get(i, target_ptr_size_), NativeLocationInImage(method));
  }
}

void ImageWriter::CopyAndFixupImtConflictTable(ImtConflictTable* orig, ImtConflictTable* copy) {
  const size_t count = orig->NumEntries(target_ptr_size_);
  for (size_t i = 0; i < count; ++i) {
    ArtMethod* interface_method = orig->GetInterfaceMethod(i, target_ptr_size_);
    ArtMethod* implementation_method = orig->GetImplementationMethod(i, target_ptr_size_);
    CopyAndFixupPointer(copy->AddressOfInterfaceMethod(i, target_ptr_size_), interface_method);
    CopyAndFixupPointer(
        copy->AddressOfImplementationMethod(i, target_ptr_size_), implementation_method);
    DCHECK_EQ(copy->GetInterfaceMethod(i, target_ptr_size_),
              NativeLocationInImage(interface_method));
    DCHECK_EQ(copy->GetImplementationMethod(i, target_ptr_size_),
              NativeLocationInImage(implementation_method));
  }
}

void ImageWriter::CopyAndFixupNativeData(size_t oat_index) {
  const ImageInfo& image_info = GetImageInfo(oat_index);
  // Copy ArtFields and methods to their locations and update the array for convenience.
  for (auto& pair : native_object_relocations_) {
    NativeObjectRelocation& relocation = pair.second;
    // Only work with fields and methods that are in the current oat file.
    if (relocation.oat_index != oat_index) {
      continue;
    }
    auto* dest = image_info.image_.Begin() + relocation.offset;
    DCHECK_GE(dest, image_info.image_.Begin() + image_info.image_end_);
    DCHECK(!IsInBootImage(pair.first));
    switch (relocation.type) {
      case NativeObjectRelocationType::kRuntimeMethod:
      case NativeObjectRelocationType::kArtMethodClean:
      case NativeObjectRelocationType::kArtMethodDirty: {
        CopyAndFixupMethod(reinterpret_cast<ArtMethod*>(pair.first),
                           reinterpret_cast<ArtMethod*>(dest),
                           oat_index);
        break;
      }
      case NativeObjectRelocationType::kArtFieldArray: {
        // Copy and fix up the entire field array.
        auto* src_array = reinterpret_cast<LengthPrefixedArray<ArtField>*>(pair.first);
        auto* dest_array = reinterpret_cast<LengthPrefixedArray<ArtField>*>(dest);
        size_t size = src_array->size();
        memcpy(dest_array, src_array, LengthPrefixedArray<ArtField>::ComputeSize(size));
        for (size_t i = 0; i != size; ++i) {
          CopyAndFixupReference(
              dest_array->At(i).GetDeclaringClassAddressWithoutBarrier(),
              src_array->At(i).GetDeclaringClass());
        }
        break;
      }
      case NativeObjectRelocationType::kArtMethodArrayClean:
      case NativeObjectRelocationType::kArtMethodArrayDirty: {
        // For method arrays, copy just the header since the elements will
        // get copied by their corresponding relocations.
        size_t size = ArtMethod::Size(target_ptr_size_);
        size_t alignment = ArtMethod::Alignment(target_ptr_size_);
        memcpy(dest, pair.first, LengthPrefixedArray<ArtMethod>::ComputeSize(0, size, alignment));
        // Clear padding to avoid non-deterministic data in the image.
        // Historical note: We also did that to placate Valgrind.
        reinterpret_cast<LengthPrefixedArray<ArtMethod>*>(dest)->ClearPadding(size, alignment);
        break;
      }
      case NativeObjectRelocationType::kIMTable: {
        ImTable* orig_imt = reinterpret_cast<ImTable*>(pair.first);
        ImTable* dest_imt = reinterpret_cast<ImTable*>(dest);
        CopyAndFixupImTable(orig_imt, dest_imt);
        break;
      }
      case NativeObjectRelocationType::kIMTConflictTable: {
        auto* orig_table = reinterpret_cast<ImtConflictTable*>(pair.first);
        CopyAndFixupImtConflictTable(
            orig_table,
            new(dest)ImtConflictTable(orig_table->NumEntries(target_ptr_size_), target_ptr_size_));
        break;
      }
      case NativeObjectRelocationType::kGcRootPointer: {
        auto* orig_pointer = reinterpret_cast<GcRoot<mirror::Object>*>(pair.first);
        auto* dest_pointer = reinterpret_cast<GcRoot<mirror::Object>*>(dest);
        CopyAndFixupReference(dest_pointer->AddressWithoutBarrier(), orig_pointer->Read());
        break;
      }
    }
  }
  // Fixup the image method roots.
  auto* image_header = reinterpret_cast<ImageHeader*>(image_info.image_.Begin());
  for (size_t i = 0; i < ImageHeader::kImageMethodsCount; ++i) {
    ArtMethod* method = image_methods_[i];
    CHECK(method != nullptr);
    CopyAndFixupPointer(
        reinterpret_cast<void**>(&image_header->image_methods_[i]), method, PointerSize::k32);
  }
  FixupRootVisitor root_visitor(this);

  // Write the intern table into the image.
  if (image_info.intern_table_bytes_ > 0) {
    const ImageSection& intern_table_section = image_header->GetInternedStringsSection();
    DCHECK(image_info.intern_table_.has_value());
    const InternTable::UnorderedSet& intern_table = *image_info.intern_table_;
    uint8_t* const intern_table_memory_ptr =
        image_info.image_.Begin() + intern_table_section.Offset();
    const size_t intern_table_bytes = intern_table.WriteToMemory(intern_table_memory_ptr);
    CHECK_EQ(intern_table_bytes, image_info.intern_table_bytes_);
    // Fixup the pointers in the newly written intern table to contain image addresses.
    InternTable temp_intern_table;
    // Note that we require that ReadFromMemory does not make an internal copy of the elements so
    // that the VisitRoots() will update the memory directly rather than the copies.
    // This also relies on visit roots not doing any verification which could fail after we update
    // the roots to be the image addresses.
    temp_intern_table.AddTableFromMemory(intern_table_memory_ptr,
                                         VoidFunctor(),
                                         /*is_boot_image=*/ false);
    CHECK_EQ(temp_intern_table.Size(), intern_table.size());
    temp_intern_table.VisitRoots(&root_visitor, kVisitRootFlagAllRoots);

    if (kIsDebugBuild) {
      MutexLock lock(Thread::Current(), *Locks::intern_table_lock_);
      CHECK(!temp_intern_table.strong_interns_.tables_.empty());
      // The UnorderedSet was inserted at the beginning.
      CHECK_EQ(temp_intern_table.strong_interns_.tables_[0].Size(), intern_table.size());
    }
  }

  // Write the class table(s) into the image. class_table_bytes_ may be 0 if there are multiple
  // class loaders. Writing multiple class tables into the image is currently unsupported.
  if (image_info.class_table_bytes_ > 0u) {
    const ImageSection& class_table_section = image_header->GetClassTableSection();
    uint8_t* const class_table_memory_ptr =
        image_info.image_.Begin() + class_table_section.Offset();

    DCHECK(image_info.class_table_.has_value());
    const ClassTable::ClassSet& table = *image_info.class_table_;
    CHECK_EQ(table.size(), image_info.class_table_size_);
    const size_t class_table_bytes = table.WriteToMemory(class_table_memory_ptr);
    CHECK_EQ(class_table_bytes, image_info.class_table_bytes_);

    // Fixup the pointers in the newly written class table to contain image addresses. See
    // above comment for intern tables.
    ClassTable temp_class_table;
    temp_class_table.ReadFromMemory(class_table_memory_ptr);
    CHECK_EQ(temp_class_table.NumReferencedZygoteClasses(), table.size());
    UnbufferedRootVisitor visitor(&root_visitor, RootInfo(kRootUnknown));
    temp_class_table.VisitRoots(visitor);

    if (kIsDebugBuild) {
      ReaderMutexLock lock(Thread::Current(), temp_class_table.lock_);
      CHECK(!temp_class_table.classes_.empty());
      // The ClassSet was inserted at the beginning.
      CHECK_EQ(temp_class_table.classes_[0].size(), table.size());
    }
  }
}

void ImageWriter::CopyAndFixupMethodPointerArray(mirror::PointerArray* arr) {
  // Pointer arrays are processed early and each is visited just once.
  // Therefore we know that this array has not been copied yet.
  mirror::Object* dst = CopyObject</*kCheckIfDone=*/ false>(arr);
  DCHECK(dst != nullptr);
  DCHECK(arr->IsIntArray() || arr->IsLongArray()) << arr->GetClass()->PrettyClass() << " " << arr;
  // Fixup int and long pointers for the ArtMethod or ArtField arrays.
  const size_t num_elements = arr->GetLength();
  CopyAndFixupReference(
      dst->GetFieldObjectReferenceAddr<kVerifyNone>(Class::ClassOffset()), arr->GetClass());
  auto* dest_array = down_cast<mirror::PointerArray*>(dst);
  for (size_t i = 0, count = num_elements; i < count; ++i) {
    void* elem = arr->GetElementPtrSize<void*>(i, target_ptr_size_);
    if (kIsDebugBuild && elem != nullptr && !IsInBootImage(elem)) {
      auto it = native_object_relocations_.find(elem);
      if (UNLIKELY(it == native_object_relocations_.end())) {
        auto* method = reinterpret_cast<ArtMethod*>(elem);
        LOG(FATAL) << "No relocation entry for ArtMethod " << method->PrettyMethod() << " @ "
                   << method << " idx=" << i << "/" << num_elements << " with declaring class "
                   << Class::PrettyClass(method->GetDeclaringClass());
        UNREACHABLE();
      }
    }
    CopyAndFixupPointer(dest_array->ElementAddress(i, target_ptr_size_), elem);
  }
}

void ImageWriter::CopyAndFixupObject(Object* obj) {
  if (!IsImageBinSlotAssigned(obj)) {
    return;
  }
  // Some objects (such as method pointer arrays) may have been processed before.
  mirror::Object* dst = CopyObject</*kCheckIfDone=*/ true>(obj);
  if (dst != nullptr) {
    FixupObject(obj, dst);
  }
}

template <bool kCheckIfDone>
inline Object* ImageWriter::CopyObject(Object* obj) {
  size_t oat_index = GetOatIndex(obj);
  size_t offset = GetImageOffset(obj, oat_index);
  ImageInfo& image_info = GetImageInfo(oat_index);
  auto* dst = reinterpret_cast<Object*>(image_info.image_.Begin() + offset);
  DCHECK_LT(offset, image_info.image_end_);
  const auto* src = reinterpret_cast<const uint8_t*>(obj);

  bool done = image_info.image_bitmap_.Set(dst);  // Mark the obj as live.
  // Check if the object was already copied, unless the caller indicated that it was not.
  if (kCheckIfDone && done) {
    return nullptr;
  }
  DCHECK(!done);

  const size_t n = obj->SizeOf();

  if (kIsDebugBuild && region_size_ != 0u) {
    const size_t offset_after_header = offset - sizeof(ImageHeader);
    const size_t next_region = RoundUp(offset_after_header, region_size_);
    if (offset_after_header != next_region) {
      // If the object is not on a region bondary, it must not be cross region.
      CHECK_LT(offset_after_header, next_region)
          << "offset_after_header=" << offset_after_header << " size=" << n;
      CHECK_LE(offset_after_header + n, next_region)
          << "offset_after_header=" << offset_after_header << " size=" << n;
    }
  }
  DCHECK_LE(offset + n, image_info.image_.Size());
  memcpy(dst, src, n);

  // Write in a hash code of objects which have inflated monitors or a hash code in their monitor
  // word.
  const auto it = saved_hashcode_map_.find(obj);
  dst->SetLockWord(it != saved_hashcode_map_.end() ?
      LockWord::FromHashCode(it->second, 0u) : LockWord::Default(), false);
  if (kUseBakerReadBarrier && gc::collector::ConcurrentCopying::kGrayDirtyImmuneObjects) {
    // Treat all of the objects in the image as marked to avoid unnecessary dirty pages. This is
    // safe since we mark all of the objects that may reference non immune objects as gray.
    CHECK(dst->AtomicSetMarkBit(0, 1));
  }
  return dst;
}

// Rewrite all the references in the copied object to point to their image address equivalent
class ImageWriter::FixupVisitor {
 public:
  FixupVisitor(ImageWriter* image_writer, Object* copy)
      : image_writer_(image_writer), copy_(copy) {
  }

  // Ignore class roots since we don't have a way to map them to the destination. These are handled
  // with other logic.
  void VisitRootIfNonNull(mirror::CompressedReference<mirror::Object>* root ATTRIBUTE_UNUSED)
      const {}
  void VisitRoot(mirror::CompressedReference<mirror::Object>* root ATTRIBUTE_UNUSED) const {}

  void operator()(ObjPtr<Object> obj, MemberOffset offset, bool is_static ATTRIBUTE_UNUSED) const
      REQUIRES_SHARED(Locks::mutator_lock_) REQUIRES(Locks::heap_bitmap_lock_) {
    ObjPtr<Object> ref = obj->GetFieldObject<Object, kVerifyNone>(offset);
    // Copy the reference and record the fixup if necessary.
    image_writer_->CopyAndFixupReference(
        copy_->GetFieldObjectReferenceAddr<kVerifyNone>(offset), ref);
  }

  // java.lang.ref.Reference visitor.
  void operator()(ObjPtr<mirror::Class> klass ATTRIBUTE_UNUSED,
                  ObjPtr<mirror::Reference> ref) const
      REQUIRES_SHARED(Locks::mutator_lock_) REQUIRES(Locks::heap_bitmap_lock_) {
    operator()(ref, mirror::Reference::ReferentOffset(), /* is_static */ false);
  }

 protected:
  ImageWriter* const image_writer_;
  mirror::Object* const copy_;
};

void ImageWriter::CopyAndFixupObjects() {
  // Copy and fix up pointer arrays first as they require special treatment.
  auto method_pointer_array_visitor =
      [&](ObjPtr<mirror::PointerArray> pointer_array) REQUIRES_SHARED(Locks::mutator_lock_) {
        CopyAndFixupMethodPointerArray(pointer_array.Ptr());
      };
  for (ImageInfo& image_info : image_infos_) {
    if (image_info.class_table_size_ != 0u) {
      DCHECK(image_info.class_table_.has_value());
      for (const ClassTable::TableSlot slot : *image_info.class_table_) {
        ObjPtr<mirror::Class> klass = slot.Read<kWithoutReadBarrier>();
        DCHECK(klass != nullptr);
        // Do not process boot image classes present in app image class table.
        DCHECK(!IsInBootImage(klass.Ptr()) || compiler_options_.IsAppImage());
        if (!IsInBootImage(klass.Ptr())) {
          // Do not fix up method pointer arrays inherited from superclass. If they are part
          // of the current image, they were or shall be copied when visiting the superclass.
          VisitNewMethodPointerArrays(klass, method_pointer_array_visitor);
        }
      }
    }
  }

  auto visitor = [&](Object* obj) REQUIRES_SHARED(Locks::mutator_lock_) {
    DCHECK(obj != nullptr);
    CopyAndFixupObject(obj);
  };
  Runtime::Current()->GetHeap()->VisitObjects(visitor);

  // Fill the padding objects since they are required for in order traversal of the image space.
  for (ImageInfo& image_info : image_infos_) {
    for (const size_t start_offset : image_info.padding_offsets_) {
      const size_t offset_after_header = start_offset - sizeof(ImageHeader);
      size_t remaining_space =
          RoundUp(offset_after_header + 1u, region_size_) - offset_after_header;
      DCHECK_NE(remaining_space, 0u);
      DCHECK_LT(remaining_space, region_size_);
      Object* dst = reinterpret_cast<Object*>(image_info.image_.Begin() + start_offset);
      ObjPtr<Class> object_class = GetClassRoot<mirror::Object, kWithoutReadBarrier>();
      DCHECK_ALIGNED_PARAM(remaining_space, object_class->GetObjectSize());
      Object* end = dst + remaining_space / object_class->GetObjectSize();
      Class* image_object_class = GetImageAddress(object_class.Ptr());
      while (dst != end) {
        dst->SetClass<kVerifyNone>(image_object_class);
        dst->SetLockWord<kVerifyNone>(LockWord::Default(), /*as_volatile=*/ false);
        image_info.image_bitmap_.Set(dst);  // Mark the obj as live.
        ++dst;
      }
    }
  }

  // We no longer need the hashcode map, values have already been copied to target objects.
  saved_hashcode_map_.clear();
}

class ImageWriter::FixupClassVisitor final : public FixupVisitor {
 public:
  FixupClassVisitor(ImageWriter* image_writer, Object* copy)
      : FixupVisitor(image_writer, copy) {}

  void operator()(ObjPtr<Object> obj, MemberOffset offset, bool is_static ATTRIBUTE_UNUSED) const
      REQUIRES(Locks::mutator_lock_, Locks::heap_bitmap_lock_) {
    DCHECK(obj->IsClass());
    FixupVisitor::operator()(obj, offset, /*is_static*/false);
  }

  void operator()(ObjPtr<mirror::Class> klass ATTRIBUTE_UNUSED,
                  ObjPtr<mirror::Reference> ref ATTRIBUTE_UNUSED) const
      REQUIRES_SHARED(Locks::mutator_lock_) REQUIRES(Locks::heap_bitmap_lock_) {
    LOG(FATAL) << "Reference not expected here.";
  }
};

ImageWriter::NativeObjectRelocation ImageWriter::GetNativeRelocation(void* obj) {
  DCHECK(obj != nullptr);
  DCHECK(!IsInBootImage(obj));
  auto it = native_object_relocations_.find(obj);
  CHECK(it != native_object_relocations_.end()) << obj << " spaces "
      << Runtime::Current()->GetHeap()->DumpSpaces();
  return it->second;
}

template <typename T>
std::string PrettyPrint(T* ptr) REQUIRES_SHARED(Locks::mutator_lock_) {
  std::ostringstream oss;
  oss << ptr;
  return oss.str();
}

template <>
std::string PrettyPrint(ArtMethod* method) REQUIRES_SHARED(Locks::mutator_lock_) {
  return ArtMethod::PrettyMethod(method);
}

template <typename T>
T* ImageWriter::NativeLocationInImage(T* obj) {
  if (obj == nullptr || IsInBootImage(obj)) {
    return obj;
  } else {
    NativeObjectRelocation relocation = GetNativeRelocation(obj);
    const ImageInfo& image_info = GetImageInfo(relocation.oat_index);
    return reinterpret_cast<T*>(image_info.image_begin_ + relocation.offset);
  }
}

class ImageWriter::NativeLocationVisitor {
 public:
  explicit NativeLocationVisitor(ImageWriter* image_writer)
      : image_writer_(image_writer) {}

  template <typename T>
  T* operator()(T* ptr, void** dest_addr) const REQUIRES_SHARED(Locks::mutator_lock_) {
    if (ptr != nullptr) {
      image_writer_->CopyAndFixupPointer(dest_addr, ptr);
    }
    // TODO: The caller shall overwrite the value stored by CopyAndFixupPointer()
    // with the value we return here. We should try to avoid the duplicate work.
    return image_writer_->NativeLocationInImage(ptr);
  }

 private:
  ImageWriter* const image_writer_;
};

void ImageWriter::FixupClass(mirror::Class* orig, mirror::Class* copy) {
  orig->FixupNativePointers(copy, target_ptr_size_, NativeLocationVisitor(this));
  FixupClassVisitor visitor(this, copy);
  ObjPtr<mirror::Object>(orig)->VisitReferences(visitor, visitor);

  if (kBitstringSubtypeCheckEnabled && !compiler_options_.IsBootImage()) {
    // When we call SubtypeCheck::EnsureInitialize, it Assigns new bitstring
    // values to the parent of that class.
    //
    // Every time this happens, the parent class has to mutate to increment
    // the "Next" value.
    //
    // If any of these parents are in the boot image, the changes [in the parents]
    // would be lost when the app image is reloaded.
    //
    // To prevent newly loaded classes (not in the app image) from being reassigned
    // the same bitstring value as an existing app image class, uninitialize
    // all the classes in the app image.
    //
    // On startup, the class linker will then re-initialize all the app
    // image bitstrings. See also ClassLinker::AddImageSpace.
    //
    // FIXME: Deal with boot image extensions.
    MutexLock subtype_check_lock(Thread::Current(), *Locks::subtype_check_lock_);
    // Lock every time to prevent a dcheck failure when we suspend with the lock held.
    SubtypeCheck<mirror::Class*>::ForceUninitialize(copy);
  }

  // Remove the clinitThreadId. This is required for image determinism.
  copy->SetClinitThreadId(static_cast<pid_t>(0));
  // We never emit kRetryVerificationAtRuntime, instead we mark the class as
  // resolved and the class will therefore be re-verified at runtime.
  if (orig->ShouldVerifyAtRuntime()) {
    copy->SetStatusInternal(ClassStatus::kResolved);
  }
}

void ImageWriter::FixupObject(Object* orig, Object* copy) {
  DCHECK(orig != nullptr);
  DCHECK(copy != nullptr);
  if (kUseBakerReadBarrier) {
    orig->AssertReadBarrierState();
  }
  if (orig->IsClass()) {
    FixupClass(orig->AsClass<kVerifyNone>().Ptr(), down_cast<mirror::Class*>(copy));
  } else {
    ObjPtr<mirror::ObjectArray<mirror::Class>> class_roots =
        Runtime::Current()->GetClassLinker()->GetClassRoots();
    ObjPtr<mirror::Class> klass = orig->GetClass();
    if (klass == GetClassRoot<mirror::Method>(class_roots) ||
        klass == GetClassRoot<mirror::Constructor>(class_roots)) {
      // Need to go update the ArtMethod.
      auto* dest = down_cast<mirror::Executable*>(copy);
      auto* src = down_cast<mirror::Executable*>(orig);
      ArtMethod* src_method = src->GetArtMethod();
      CopyAndFixupPointer(dest, mirror::Executable::ArtMethodOffset(), src_method);
    } else if (klass == GetClassRoot<mirror::DexCache>(class_roots)) {
      down_cast<mirror::DexCache*>(copy)->ResetNativeFields();
    } else if (klass->IsClassLoaderClass()) {
      mirror::ClassLoader* copy_loader = down_cast<mirror::ClassLoader*>(copy);
      // If src is a ClassLoader, set the class table to null so that it gets recreated by the
      // ClassLoader.
      copy_loader->SetClassTable(nullptr);
      // Also set allocator to null to be safe. The allocator is created when we create the class
      // table. We also never expect to unload things in the image since they are held live as
      // roots.
      copy_loader->SetAllocator(nullptr);
    }
    FixupVisitor visitor(this, copy);
    orig->VisitReferences(visitor, visitor);
  }
}

const uint8_t* ImageWriter::GetOatAddress(StubType type) const {
  DCHECK_LE(type, StubType::kLast);
  // If we are compiling a boot image extension or app image,
  // we need to use the stubs of the primary boot image.
  if (!compiler_options_.IsBootImage()) {
    // Use the current image pointers.
    const std::vector<gc::space::ImageSpace*>& image_spaces =
        Runtime::Current()->GetHeap()->GetBootImageSpaces();
    DCHECK(!image_spaces.empty());
    const OatFile* oat_file = image_spaces[0]->GetOatFile();
    CHECK(oat_file != nullptr);
    const OatHeader& header = oat_file->GetOatHeader();
    switch (type) {
      // TODO: We could maybe clean this up if we stored them in an array in the oat header.
      case StubType::kQuickGenericJNITrampoline:
        return static_cast<const uint8_t*>(header.GetQuickGenericJniTrampoline());
      case StubType::kJNIDlsymLookupTrampoline:
        return static_cast<const uint8_t*>(header.GetJniDlsymLookupTrampoline());
      case StubType::kJNIDlsymLookupCriticalTrampoline:
        return static_cast<const uint8_t*>(header.GetJniDlsymLookupCriticalTrampoline());
      case StubType::kQuickIMTConflictTrampoline:
        return static_cast<const uint8_t*>(header.GetQuickImtConflictTrampoline());
      case StubType::kQuickResolutionTrampoline:
        return static_cast<const uint8_t*>(header.GetQuickResolutionTrampoline());
      case StubType::kQuickToInterpreterBridge:
        return static_cast<const uint8_t*>(header.GetQuickToInterpreterBridge());
      case StubType::kNterpTrampoline:
        return static_cast<const uint8_t*>(header.GetNterpTrampoline());
      default:
        UNREACHABLE();
    }
  }
  const ImageInfo& primary_image_info = GetImageInfo(0);
  return GetOatAddressForOffset(primary_image_info.GetStubOffset(type), primary_image_info);
}

const uint8_t* ImageWriter::GetQuickCode(ArtMethod* method, const ImageInfo& image_info) {
  DCHECK(!method->IsResolutionMethod()) << method->PrettyMethod();
  DCHECK_NE(method, Runtime::Current()->GetImtConflictMethod()) << method->PrettyMethod();
  DCHECK(!method->IsImtUnimplementedMethod()) << method->PrettyMethod();
  DCHECK(method->IsInvokable()) << method->PrettyMethod();
  DCHECK(!IsInBootImage(method)) << method->PrettyMethod();

  // Use original code if it exists. Otherwise, set the code pointer to the resolution
  // trampoline.

  // Quick entrypoint:
  const void* quick_oat_entry_point =
      method->GetEntryPointFromQuickCompiledCodePtrSize(target_ptr_size_);
  const uint8_t* quick_code;

  if (UNLIKELY(IsInBootImage(method->GetDeclaringClass().Ptr()))) {
    DCHECK(method->IsCopied());
    // If the code is not in the oat file corresponding to this image (e.g. default methods)
    quick_code = reinterpret_cast<const uint8_t*>(quick_oat_entry_point);
  } else {
    uint32_t quick_oat_code_offset = PointerToLowMemUInt32(quick_oat_entry_point);
    quick_code = GetOatAddressForOffset(quick_oat_code_offset, image_info);
  }

  bool needs_clinit_check = NeedsClinitCheckBeforeCall(method) &&
      !method->GetDeclaringClass()->IsVisiblyInitialized();

  if (quick_code == nullptr) {
    // If we don't have code, use generic jni / interpreter.
    if (method->IsNative()) {
      // The generic JNI trampolines performs class initialization check if needed.
      quick_code = GetOatAddress(StubType::kQuickGenericJNITrampoline);
    } else if (CanMethodUseNterp(method, compiler_options_.GetInstructionSet())) {
      // The nterp trampoline doesn't do initialization checks, so install the
      // resolution stub if needed.
      if (needs_clinit_check) {
        quick_code = GetOatAddress(StubType::kQuickResolutionTrampoline);
      } else {
        quick_code = GetOatAddress(StubType::kNterpTrampoline);
      }
    } else {
      // The interpreter brige performs class initialization check if needed.
      quick_code = GetOatAddress(StubType::kQuickToInterpreterBridge);
    }
  } else if (needs_clinit_check) {
    // If we do have code but the method needs a class initialization check before calling
    // that code, install the resolution stub that will perform the check.
    quick_code = GetOatAddress(StubType::kQuickResolutionTrampoline);
  }
  return quick_code;
}

void ImageWriter::CopyAndFixupMethod(ArtMethod* orig,
                                     ArtMethod* copy,
                                     size_t oat_index) {
  if (orig->IsAbstract()) {
    // Ignore the single-implementation info for abstract method.
    // Do this on orig instead of copy, otherwise there is a crash due to methods
    // are copied before classes.
    // TODO: handle fixup of single-implementation method for abstract method.
    orig->SetHasSingleImplementation(false);
    orig->SetSingleImplementation(
        nullptr, Runtime::Current()->GetClassLinker()->GetImagePointerSize());
  }

  memcpy(copy, orig, ArtMethod::Size(target_ptr_size_));

  CopyAndFixupReference(
      copy->GetDeclaringClassAddressWithoutBarrier(), orig->GetDeclaringClassUnchecked());

  // OatWriter replaces the code_ with an offset value. Here we re-adjust to a pointer relative to
  // oat_begin_

  // The resolution method has a special trampoline to call.
  Runtime* runtime = Runtime::Current();
  const void* quick_code;
  if (orig->IsRuntimeMethod()) {
    ImtConflictTable* orig_table = orig->GetImtConflictTable(target_ptr_size_);
    if (orig_table != nullptr) {
      // Special IMT conflict method, normal IMT conflict method or unimplemented IMT method.
      quick_code = GetOatAddress(StubType::kQuickIMTConflictTrampoline);
      CopyAndFixupPointer(copy, ArtMethod::DataOffset(target_ptr_size_), orig_table);
    } else if (UNLIKELY(orig == runtime->GetResolutionMethod())) {
      quick_code = GetOatAddress(StubType::kQuickResolutionTrampoline);
      // Set JNI entrypoint for resolving @CriticalNative methods called from compiled code .
      const void* jni_code = GetOatAddress(StubType::kJNIDlsymLookupCriticalTrampoline);
      copy->SetEntryPointFromJniPtrSize(jni_code, target_ptr_size_);
    } else {
      bool found_one = false;
      for (size_t i = 0; i < static_cast<size_t>(CalleeSaveType::kLastCalleeSaveType); ++i) {
        auto idx = static_cast<CalleeSaveType>(i);
        if (runtime->HasCalleeSaveMethod(idx) && runtime->GetCalleeSaveMethod(idx) == orig) {
          found_one = true;
          break;
        }
      }
      CHECK(found_one) << "Expected to find callee save method but got " << orig->PrettyMethod();
      CHECK(copy->IsRuntimeMethod());
      CHECK(copy->GetEntryPointFromQuickCompiledCode() == nullptr);
      quick_code = nullptr;
    }
  } else {
    // We assume all methods have code. If they don't currently then we set them to the use the
    // resolution trampoline. Abstract methods never have code and so we need to make sure their
    // use results in an AbstractMethodError. We use the interpreter to achieve this.
    if (UNLIKELY(!orig->IsInvokable())) {
      quick_code = GetOatAddress(StubType::kQuickToInterpreterBridge);
    } else {
      const ImageInfo& image_info = image_infos_[oat_index];
      quick_code = GetQuickCode(orig, image_info);

      // JNI entrypoint:
      if (orig->IsNative()) {
        // The native method's pointer is set to a stub to lookup via dlsym.
        // Note this is not the code_ pointer, that is handled above.
        StubType stub_type = orig->IsCriticalNative() ? StubType::kJNIDlsymLookupCriticalTrampoline
                                                      : StubType::kJNIDlsymLookupTrampoline;
        copy->SetEntryPointFromJniPtrSize(GetOatAddress(stub_type), target_ptr_size_);
      } else if (!orig->HasCodeItem()) {
        CHECK(copy->GetDataPtrSize(target_ptr_size_) == nullptr);
      } else {
        CHECK(copy->GetDataPtrSize(target_ptr_size_) != nullptr);
      }
    }
  }
  if (quick_code != nullptr) {
    copy->SetEntryPointFromQuickCompiledCodePtrSize(quick_code, target_ptr_size_);
  }
}

size_t ImageWriter::ImageInfo::GetBinSizeSum(Bin up_to) const {
  DCHECK_LE(static_cast<size_t>(up_to), kNumberOfBins);
  return std::accumulate(&bin_slot_sizes_[0],
                         &bin_slot_sizes_[0] + static_cast<size_t>(up_to),
                         /*init*/ static_cast<size_t>(0));
}

ImageWriter::BinSlot::BinSlot(uint32_t lockword) : lockword_(lockword) {
  // These values may need to get updated if more bins are added to the enum Bin
  static_assert(kBinBits == 3, "wrong number of bin bits");
  static_assert(kBinShift == 27, "wrong number of shift");
  static_assert(sizeof(BinSlot) == sizeof(LockWord), "BinSlot/LockWord must have equal sizes");

  DCHECK_LT(GetBin(), Bin::kMirrorCount);
  DCHECK_ALIGNED(GetOffset(), kObjectAlignment);
}

ImageWriter::BinSlot::BinSlot(Bin bin, uint32_t index)
    : BinSlot(index | (static_cast<uint32_t>(bin) << kBinShift)) {
  DCHECK_EQ(index, GetOffset());
}

ImageWriter::Bin ImageWriter::BinSlot::GetBin() const {
  return static_cast<Bin>((lockword_ & kBinMask) >> kBinShift);
}

uint32_t ImageWriter::BinSlot::GetOffset() const {
  return lockword_ & ~kBinMask;
}

ImageWriter::Bin ImageWriter::BinTypeForNativeRelocationType(NativeObjectRelocationType type) {
  switch (type) {
    case NativeObjectRelocationType::kArtFieldArray:
      return Bin::kArtField;
    case NativeObjectRelocationType::kArtMethodClean:
    case NativeObjectRelocationType::kArtMethodArrayClean:
      return Bin::kArtMethodClean;
    case NativeObjectRelocationType::kArtMethodDirty:
    case NativeObjectRelocationType::kArtMethodArrayDirty:
      return Bin::kArtMethodDirty;
    case NativeObjectRelocationType::kRuntimeMethod:
      return Bin::kRuntimeMethod;
    case NativeObjectRelocationType::kIMTable:
      return Bin::kImTable;
    case NativeObjectRelocationType::kIMTConflictTable:
      return Bin::kIMTConflictTable;
    case NativeObjectRelocationType::kGcRootPointer:
      return Bin::kMetadata;
  }
  UNREACHABLE();
}

size_t ImageWriter::GetOatIndex(mirror::Object* obj) const {
  if (!IsMultiImage()) {
    DCHECK(oat_index_map_.empty());
    return GetDefaultOatIndex();
  }
  auto it = oat_index_map_.find(obj);
  DCHECK(it != oat_index_map_.end()) << obj;
  return it->second;
}

size_t ImageWriter::GetOatIndexForDexFile(const DexFile* dex_file) const {
  if (!IsMultiImage()) {
    return GetDefaultOatIndex();
  }
  auto it = dex_file_oat_index_map_.find(dex_file);
  DCHECK(it != dex_file_oat_index_map_.end()) << dex_file->GetLocation();
  return it->second;
}

size_t ImageWriter::GetOatIndexForClass(ObjPtr<mirror::Class> klass) const {
  while (klass->IsArrayClass()) {
    klass = klass->GetComponentType();
  }
  if (UNLIKELY(klass->IsPrimitive())) {
    DCHECK(klass->GetDexCache() == nullptr);
    return GetDefaultOatIndex();
  } else {
    DCHECK(klass->GetDexCache() != nullptr);
    return GetOatIndexForDexFile(&klass->GetDexFile());
  }
}

void ImageWriter::UpdateOatFileLayout(size_t oat_index,
                                      size_t oat_loaded_size,
                                      size_t oat_data_offset,
                                      size_t oat_data_size) {
  DCHECK_GE(oat_loaded_size, oat_data_offset);
  DCHECK_GE(oat_loaded_size - oat_data_offset, oat_data_size);

  const uint8_t* images_end = image_infos_.back().image_begin_ + image_infos_.back().image_size_;
  DCHECK(images_end != nullptr);  // Image space must be ready.
  for (const ImageInfo& info : image_infos_) {
    DCHECK_LE(info.image_begin_ + info.image_size_, images_end);
  }

  ImageInfo& cur_image_info = GetImageInfo(oat_index);
  cur_image_info.oat_file_begin_ = images_end + cur_image_info.oat_offset_;
  cur_image_info.oat_loaded_size_ = oat_loaded_size;
  cur_image_info.oat_data_begin_ = cur_image_info.oat_file_begin_ + oat_data_offset;
  cur_image_info.oat_size_ = oat_data_size;

  if (compiler_options_.IsAppImage()) {
    CHECK_EQ(oat_filenames_.size(), 1u) << "App image should have no next image.";
    return;
  }

  // Update the oat_offset of the next image info.
  if (oat_index + 1u != oat_filenames_.size()) {
    // There is a following one.
    ImageInfo& next_image_info = GetImageInfo(oat_index + 1u);
    next_image_info.oat_offset_ = cur_image_info.oat_offset_ + oat_loaded_size;
  }
}

void ImageWriter::UpdateOatFileHeader(size_t oat_index, const OatHeader& oat_header) {
  ImageInfo& cur_image_info = GetImageInfo(oat_index);
  cur_image_info.oat_checksum_ = oat_header.GetChecksum();

  if (oat_index == GetDefaultOatIndex()) {
    // Primary oat file, read the trampolines.
    cur_image_info.SetStubOffset(StubType::kJNIDlsymLookupTrampoline,
                                 oat_header.GetJniDlsymLookupTrampolineOffset());
    cur_image_info.SetStubOffset(StubType::kJNIDlsymLookupCriticalTrampoline,
                                 oat_header.GetJniDlsymLookupCriticalTrampolineOffset());
    cur_image_info.SetStubOffset(StubType::kQuickGenericJNITrampoline,
                                 oat_header.GetQuickGenericJniTrampolineOffset());
    cur_image_info.SetStubOffset(StubType::kQuickIMTConflictTrampoline,
                                 oat_header.GetQuickImtConflictTrampolineOffset());
    cur_image_info.SetStubOffset(StubType::kQuickResolutionTrampoline,
                                 oat_header.GetQuickResolutionTrampolineOffset());
    cur_image_info.SetStubOffset(StubType::kQuickToInterpreterBridge,
                                 oat_header.GetQuickToInterpreterBridgeOffset());
    cur_image_info.SetStubOffset(StubType::kNterpTrampoline,
                                 oat_header.GetNterpTrampolineOffset());
  }
}

ImageWriter::ImageWriter(
    const CompilerOptions& compiler_options,
    uintptr_t image_begin,
    ImageHeader::StorageMode image_storage_mode,
    const std::vector<std::string>& oat_filenames,
    const HashMap<const DexFile*, size_t>& dex_file_oat_index_map,
    jobject class_loader,
    const HashSet<std::string>* dirty_image_objects)
    : compiler_options_(compiler_options),
      boot_image_begin_(Runtime::Current()->GetHeap()->GetBootImagesStartAddress()),
      boot_image_size_(Runtime::Current()->GetHeap()->GetBootImagesSize()),
      global_image_begin_(reinterpret_cast<uint8_t*>(image_begin)),
      image_objects_offset_begin_(0),
      target_ptr_size_(InstructionSetPointerSize(compiler_options.GetInstructionSet())),
      image_infos_(oat_filenames.size()),
      dirty_methods_(0u),
      clean_methods_(0u),
      app_class_loader_(class_loader),
      boot_image_live_objects_(nullptr),
      image_storage_mode_(image_storage_mode),
      oat_filenames_(oat_filenames),
      dex_file_oat_index_map_(dex_file_oat_index_map),
      dirty_image_objects_(dirty_image_objects) {
  DCHECK(compiler_options.IsBootImage() ||
         compiler_options.IsBootImageExtension() ||
         compiler_options.IsAppImage());
  DCHECK_EQ(compiler_options.IsBootImage(), boot_image_begin_ == 0u);
  DCHECK_EQ(compiler_options.IsBootImage(), boot_image_size_ == 0u);
  CHECK_NE(image_begin, 0U);
  std::fill_n(image_methods_, arraysize(image_methods_), nullptr);
  CHECK_EQ(compiler_options.IsBootImage(),
           Runtime::Current()->GetHeap()->GetBootImageSpaces().empty())
      << "Compiling a boot image should occur iff there are no boot image spaces loaded";
  if (compiler_options_.IsAppImage()) {
    // Make sure objects are not crossing region boundaries for app images.
    region_size_ = gc::space::RegionSpace::kRegionSize;
  }
}

ImageWriter::ImageInfo::ImageInfo()
    : intern_table_(),
      class_table_() {}

template <typename DestType>
void ImageWriter::CopyAndFixupReference(DestType* dest, ObjPtr<mirror::Object> src) {
  static_assert(std::is_same<DestType, mirror::CompressedReference<mirror::Object>>::value ||
                    std::is_same<DestType, mirror::HeapReference<mirror::Object>>::value,
                "DestType must be a Compressed-/HeapReference<Object>.");
  dest->Assign(GetImageAddress(src.Ptr()));
}

void ImageWriter::CopyAndFixupPointer(void** target, void* value, PointerSize pointer_size) {
  void* new_value = NativeLocationInImage(value);
  if (pointer_size == PointerSize::k32) {
    *reinterpret_cast<uint32_t*>(target) = reinterpret_cast32<uint32_t>(new_value);
  } else {
    *reinterpret_cast<uint64_t*>(target) = reinterpret_cast64<uint64_t>(new_value);
  }
  DCHECK(value != nullptr);
}

void ImageWriter::CopyAndFixupPointer(void** target, void* value)
    REQUIRES_SHARED(Locks::mutator_lock_) {
  CopyAndFixupPointer(target, value, target_ptr_size_);
}

void ImageWriter::CopyAndFixupPointer(
    void* object, MemberOffset offset, void* value, PointerSize pointer_size) {
  void** target =
      reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(object) + offset.Uint32Value());
  return CopyAndFixupPointer(target, value, pointer_size);
}

void ImageWriter::CopyAndFixupPointer(void* object, MemberOffset offset, void* value) {
  return CopyAndFixupPointer(object, offset, value, target_ptr_size_);
}

}  // namespace linker
}  // namespace art

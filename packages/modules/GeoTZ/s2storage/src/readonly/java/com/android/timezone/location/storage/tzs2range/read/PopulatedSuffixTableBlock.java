package com.android.timezone.location.storage.tzs2range.read;

import static com.android.timezone.location.storage.s2.S2Support.MAX_FACE_ID;
import static com.android.timezone.location.storage.s2.S2Support.cellIdToString;
import static com.android.timezone.location.storage.util.Conditions.checkStateInRange;

import com.android.timezone.location.storage.table.packed.read.IntValueTypedPackedTable;
import com.android.timezone.location.storage.table.reader.IntValueTable;
import com.android.timezone.location.storage.tzs2range.SuffixTableRange;
import com.android.timezone.location.storage.tzs2range.SuffixTableSharedData;
import com.android.timezone.location.storage.tzs2range.TzS2RangeFileFormat;

import java.util.Objects;

/**
 * An implementation of {@link SuffixTableBlock.SuffixTableBlockDelegate} for tables that are backed
 * by real block data, i.e. have one or more entries.
 *
 * <p>Logically, each populated suffix table block holds one or more entries for S2 ranges that
 * have an associated set of time zone IDs, e.g.:
 * <pre>
 *     startCellId=X, endCellId=Y, tzIdSet={"America/Los_Angeles", "America/Phoenix"}
 * </pre>
 *
 * <p>The storage of the range entries is as follows:
 * <ul>
 *     <li>The prefix bits are all the same so need not be stored in the individual entries. Only
 *     the suffix bits of X are stored. The prefix determines the block ID when first locating the
 *     suffix table, but it is also (redundantly) stored in the table's header for simplicity /
 *     easy debugging.</li>
 *     <li>Each range is expected to be relatively short, so Y is stored as a offset adjustment to
 *     X, i.e. Y is calculated by advancing X by {length of range} cell IDs.</li>
 *     <li>The "tzIdSet" is stored by referring to a "set ID" from a {@link
 *     com.android.timezone.location.storage.tzs2range.BankedTzIdSets.Bank} read from the file's
 *     header. The specific bank to use for a table is held in the suffix table's header. This means
 *     that identifying the set ID for each range can be done using a comparatively small number of
 *     bits.</li>
 * </ul>
 */
final class PopulatedSuffixTableBlock implements SuffixTableBlock.SuffixTableBlockDelegate {

    private final TzS2RangeFileFormat mFileFormat;

    private final IntValueTypedPackedTable mPackedTable;

    private final SuffixTableSharedData mSuffixTableSharedData;

    private final int mPrefix;

    PopulatedSuffixTableBlock(
            TzS2RangeFileFormat fileFormat, IntValueTypedPackedTable packedTable) {
        mFileFormat = Objects.requireNonNull(fileFormat);
        mPackedTable = Objects.requireNonNull(packedTable);
        mSuffixTableSharedData = SuffixTableSharedData.fromBytes(packedTable.getSharedData());

        // Obtain the prefix. All cellIds in this table will share the same prefix except for end
        // range values (which are exclusive so can be for mPrefix + 1 with a suffix value of 0).
        mPrefix = mSuffixTableSharedData.getTablePrefix();
    }

    @Override
    public int getPrefix() {
        return mPrefix;
    }

    @Override
    public SuffixTableBlock.Entry findEntryByCellId(long cellId) {
        int suffixValue = mFileFormat.extractSuffixValueFromCellId(cellId);
        S2CellMatcher matcher = new S2CellMatcher(mFileFormat, suffixValue);
        return findEntryWithMatcher(matcher);
    }

    @Override
    public SuffixTableBlock.Entry findEntryByIndex(int i) {
        return new Entry(mPackedTable.getEntryByIndex(i));
    }

    @Override
    public int getEntryCount() {
        return mPackedTable.getEntryCount();
    }

    @Override
    public int getTzIdSetBank() {
        return mSuffixTableSharedData.getTzIdSetBank();
    }

    /**
     * Returns an entry that matches the supplied matcher. If multiple entries match, an arbitrary
     * matching entry is returned. If no entries match then {@code null} is returned.
     */
    private SuffixTableBlock.Entry findEntryWithMatcher(
            IntValueTable.IntValueEntryMatcher matcher) {
        IntValueTable.TableEntry suffixTableEntry = mPackedTable.findEntry(matcher);
        if (suffixTableEntry == null) {
            return null;
        }
        return new Entry(suffixTableEntry);
    }

    /**
     * An {@link IntValueTable.IntValueEntryMatcher} capable of interpreting and matching the
     * key/value from the underlying table against a search suffix value.
     */
    private static final class S2CellMatcher implements IntValueTable.IntValueEntryMatcher {

        private final TzS2RangeFileFormat mFileFormat;

        private final int mSuffixSearchValue;

        public S2CellMatcher(TzS2RangeFileFormat fileFormat, int suffixSearchValue) {
            mFileFormat = Objects.requireNonNull(fileFormat);
            mSuffixSearchValue = suffixSearchValue;
        }

        @Override
        public int compare(int key, int value) {
            int rangeStartCellIdOffset = key;
            if (mSuffixSearchValue < rangeStartCellIdOffset) {
                return -1;
            } else {
                int rangeLength = mFileFormat.extractRangeLengthFromTableEntryValue(value);
                int rangeEndCellIdOffset = rangeStartCellIdOffset + rangeLength;
                if (mSuffixSearchValue >= rangeEndCellIdOffset) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }

    /**
     * An entry from the {@link SuffixTableBlock}. Use {@link #getSuffixTableRange()} to get the
     * full, interpreted entry data.
     */
    public final class Entry extends SuffixTableBlock.Entry {

        private final IntValueTable.TableEntry mSuffixTableEntry;

        private SuffixTableRange suffixTableRange;

        Entry(IntValueTable.TableEntry suffixTableEntry) {
            mSuffixTableEntry = Objects.requireNonNull(suffixTableEntry);
        }

        @Override
        public int getIndex() {
            return mSuffixTableEntry.getIndex();
        }

        @Override
        public int getTzIdSetBank() {
            return mSuffixTableSharedData.getTzIdSetBank();
        }

        /** Returns the data for this entry. */
        @Override
        public SuffixTableRange getSuffixTableRange() {
            // Creating SuffixTableRange is relatively expensive so it is created lazily and
            // memoized.
            if (suffixTableRange == null) {
                // Create the range to return.
                int startCellIdSuffix = mSuffixTableEntry.getKey();
                checkStateInRange("startCellIdSuffixBits", startCellIdSuffix,
                        "minSuffixValue", 0, "maxSuffixValue", mFileFormat.getMaxSuffixValue());
                long startCellId = mFileFormat.createCellId(mPrefix, startCellIdSuffix);

                int value = mSuffixTableEntry.getValue();
                int rangeLength = mFileFormat.extractRangeLengthFromTableEntryValue(value);
                checkStateInRange("rangeLength", rangeLength, "minRangeLength", 0, "maxRangeLength",
                        mFileFormat.getTableEntryMaxRangeLengthValue());
                int endCellIdSuffix = startCellIdSuffix + rangeLength;

                int endCellPrefixValue = mPrefix;
                if (endCellIdSuffix > mFileFormat.getMaxSuffixValue()) {
                    // Handle the special case where the range ends in the next prefix. This is
                    // because the range end is exclusive, so the end value is allowed to be first
                    // cell ID from the next prefix.
                    if (endCellIdSuffix != mFileFormat.getMaxSuffixValue() + 1) {
                        throw new IllegalStateException("Range exceeds allowable cell IDs:"
                                + " startCellId=" + cellIdToString(startCellId)
                                + ", rangeLength=" + rangeLength);
                    }
                    endCellPrefixValue += 1;

                    // Check to see if the face ID has overflowed, and wrap to face zero if it has.
                    if (mFileFormat.extractFaceIdFromPrefix(endCellPrefixValue) > MAX_FACE_ID) {
                        endCellPrefixValue = 0;
                    }
                    endCellIdSuffix = 0;
                }
                long endCellId = mFileFormat.createCellId(endCellPrefixValue, endCellIdSuffix);

                int tzIdSetId = mFileFormat.extractTzIdSetIdFromTableEntryValue(value);
                suffixTableRange = new SuffixTableRange(startCellId, endCellId, tzIdSetId);
            }
            return suffixTableRange;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Entry entry = (Entry) o;
            return mSuffixTableEntry.equals(entry.mSuffixTableEntry);
        }

        @Override
        public int hashCode() {
            return Objects.hash(mSuffixTableEntry);
        }

        @Override
        public String toString() {
            return "Entry{"
                    + "mSuffixTableEntry=" + mSuffixTableEntry
                    + '}';
        }
    }
}

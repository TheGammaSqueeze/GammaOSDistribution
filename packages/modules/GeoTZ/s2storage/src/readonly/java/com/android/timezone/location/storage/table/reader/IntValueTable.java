/*
 * Copyright (C) 2020 The Android Open Source Project
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

package com.android.timezone.location.storage.table.reader;

/**
 * A type for tables where the value can be expressed as a Java int; i.e. not long, but perhaps
 * where the value is actually smaller than int.
 */
public interface IntValueTable extends Table<IntValueTable.TableEntry> {

    /**
     * Finds an entry using the supplied matcher via a binary search. If multiple entries match, an
     * arbitrary matching entry is returned. Returns {@code null} if no entries match.
     */
    TableEntry findEntry(IntValueEntryMatcher matcher);

    /**
     * A type for entries in {@link IntValueTable}.
     */
    interface TableEntry extends Table.TableEntry<TableEntry> {

        /**
         * Returns the entry's value.
         */
        int getValue();

        /**
         * Finds an entry using the supplied matcher via a binary search. If multiple entries match,
         * an arbitrary matching entry is returned. Returns {@code null} if no entry matches.
         * Like {@link IntValueTable#findEntry(IntValueEntryMatcher)} but uses this entry as a
         * starting point.
         */
        TableEntry findNearbyEntry(IntValueEntryMatcher matcher);

        /** A helper method for implementing {@link TableEntry#equals(Object)}. */
        static boolean equal(TableEntry one, Object two) {
            if (one == null && two == null) {
                return true;
            }
            if (!(two instanceof TableEntry) || one == null || one.getClass() != two.getClass()) {
                return false;
            }
            TableEntry other = (TableEntry) two;
            return (one.getKey() == other.getKey() && one.getValue() == other.getValue());
        }

        /** A helper method for implementing {@link TableEntry#toString()}. */
        static String toString(TableEntry entry) {
            return "TableEntry{key=" + entry.getKey() + ", value=" + entry.getValue() + "}";
        }
    }

    /**
     * A matcher that can be used with {@link IntValueTable}s to find entries in the table.
     */
    interface IntValueEntryMatcher {

        /**
         * Returns &lt; 0 if the entry sought is lower than one with the values provided, &gt; 0
         * if the entry sought is higher than one with the values provided, and exactly zero if it
         * is the entry sought.
         */
        int compare(int key, int value);
    }
}

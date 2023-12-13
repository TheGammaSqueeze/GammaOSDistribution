/*
 * Copyright (C) 2021 The Android Open Source Project
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

package android.graphics.fonts;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.channels.FileChannel;
import java.nio.charset.StandardCharsets;

public class FontFileTestUtil {
    private static final int SFNT_VERSION_1 = 0x00010000;
    private static final int SFNT_VERSION_OTTO = 0x4F54544F;
    private static final int TTC_TAG = 0x74746366;
    private static final int NAME_TAG = 0x6E616D65;
    private static final int META_TAG = 0x6D657461;
    private static final int EMJI_TAG = 0x456D6A69;

    public static String getPostScriptName(File file) throws IOException {
        try (FileInputStream fis = new FileInputStream(file)) {
            final FileChannel fc = fis.getChannel();
            long size = fc.size();
            ByteBuffer buffer = fc.map(FileChannel.MapMode.READ_ONLY, 0, size)
                    .order(ByteOrder.BIG_ENDIAN);

            int magicNumber = buffer.getInt(0);

            int fontOffset = 0;
            if (magicNumber == TTC_TAG) {
                fontOffset = buffer.getInt(12);  // 0th offset
                magicNumber = buffer.getInt(fontOffset);
                if (magicNumber != SFNT_VERSION_1 && magicNumber != SFNT_VERSION_OTTO) {
                    throw new IOException("Unknown magic number at 0th font: #" + magicNumber);
                }
            } else if (magicNumber != SFNT_VERSION_1 && magicNumber != SFNT_VERSION_OTTO) {
                throw new IOException("Unknown magic number: #" + magicNumber);
            }

            int numTables = buffer.getShort(fontOffset + 4);  // offset to number of table
            int nameTableOffset = 0;
            for (int i = 0; i < numTables; ++i) {
                int tableEntryOffset = fontOffset + 12 + i * 16;
                int tableTag = buffer.getInt(tableEntryOffset);
                if (tableTag == NAME_TAG) {
                    nameTableOffset = buffer.getInt(tableEntryOffset + 8);
                    break;
                }
            }

            if (nameTableOffset == 0) {
                throw new IOException("name table not found.");
            }

            int nameTableCount = buffer.getShort(nameTableOffset + 2);
            int storageOffset = buffer.getShort(nameTableOffset + 4);

            for (int i = 0; i < nameTableCount; ++i) {
                int platformID = buffer.getShort(nameTableOffset + 6 + i * 12);
                int encodingID = buffer.getShort(nameTableOffset + 6 + i * 12 + 2);
                int languageID = buffer.getShort(nameTableOffset + 6 + i * 12 + 4);
                int nameID = buffer.getShort(nameTableOffset + 6 + i * 12 + 6);
                int length = buffer.getShort(nameTableOffset + 6 + i * 12 + 8);
                int stringOffset = buffer.getShort(nameTableOffset + 6 + i * 12 + 10);

                if (nameID == 6 && platformID == 3 && encodingID == 1 && languageID == 1033) {
                    byte[] name = new byte[length];
                    ByteBuffer slice = buffer.slice();
                    slice.position(nameTableOffset + storageOffset + stringOffset);
                    slice.get(name);
                    // encoded in UTF-16BE for platform ID = 3
                    return new String(name, StandardCharsets.UTF_16BE);
                }
            }
        }
        return null;
    }

    public static boolean containsEmojiCompatMetadata(File file) throws IOException {
        try (FileInputStream fis = new FileInputStream(file)) {
            final FileChannel fc = fis.getChannel();
            long size = fc.size();
            ByteBuffer buffer = fc.map(FileChannel.MapMode.READ_ONLY, 0, size)
                    .order(ByteOrder.BIG_ENDIAN);

            int magicNumber = buffer.getInt(0);

            int fontOffset = 0;
            if (magicNumber == TTC_TAG) {
                throw new IOException("Emoji font is not expected to be in a font collection.");
            } else if (magicNumber != SFNT_VERSION_1 && magicNumber != SFNT_VERSION_OTTO) {
                throw new IOException("Unknown magic number: #" + magicNumber);
            }

            int numTables = buffer.getShort(fontOffset + 4);  // offset to number of table
            int metaTableOffset = 0;
            for (int i = 0; i < numTables; ++i) {
                int tableEntryOffset = fontOffset + 12 + i * 16;
                int tableTag = buffer.getInt(tableEntryOffset);
                if (tableTag == META_TAG) {
                    metaTableOffset = buffer.getInt(tableEntryOffset + 8);
                    break;
                }
            }

            if (metaTableOffset == 0) {
                throw new IOException("name table not found.");
            }

            int dataMapsCount = buffer.getInt(metaTableOffset + 12);

            for (int i = 0; i < dataMapsCount; ++i) {
                int tag = buffer.getInt(metaTableOffset + 16 + 12 * i);
                int offset = buffer.getInt(metaTableOffset + 16 + 12 * i + 4);
                int dataLength = buffer.getInt(metaTableOffset + 16 + 12 * i + 8);

                if (tag == EMJI_TAG && dataLength != 0) {
                    return true;
                }
            }
        }
        return false;
    }
}

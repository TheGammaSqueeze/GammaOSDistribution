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

import java.nio.channels.FileChannel;
import java.nio.file.*;
import java.nio.Buffer;
import java.nio.MappedByteBuffer;

public class Main {
    public static void main(String[] args) throws Exception {
        System.loadLibrary(args[0]);

        FileChannel channel = FileChannel.open(Paths.get("/dev", "null"),
                                               StandardOpenOption.READ);
        MappedByteBuffer buffer = channel.map(FileChannel.MapMode.READ_ONLY, 0, 0);
        checkBufferCapacity(buffer, 0);
    }

    static native void checkBufferCapacity(Buffer buffer, int expectedCapacity);
}

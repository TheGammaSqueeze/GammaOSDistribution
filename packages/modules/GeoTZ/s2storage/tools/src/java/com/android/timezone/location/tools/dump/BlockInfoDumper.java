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

package com.android.timezone.location.tools.dump;

import com.android.timezone.location.storage.block.read.BlockInfo;

import java.io.File;
import java.util.Arrays;

/** A {@link BlockInfo.BlockInfoVisitor} that dumps information to a file. */
public final class BlockInfoDumper extends SingleFileDumper implements BlockInfo.BlockInfoVisitor {

    public BlockInfoDumper(File file) {
        super(file);
    }

    public void visit(BlockInfo blockInfo) throws VisitException {
        println("id=" + blockInfo.getId());
        println("type=" + blockInfo.getType());
        println("extraBytes=" + Arrays.toString(blockInfo.getExtraBytes()));
        println("blockStateByteOffset=" + blockInfo.getBlockStartByteOffset());
        println("blockSizeBytes=" + blockInfo.getBlockSizeBytes());
    }
}
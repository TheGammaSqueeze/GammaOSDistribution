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

package com.android.cts.packagemanager.stats.device;

import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import android.app.Instrumentation;
import android.os.Bundle;

import androidx.test.InstrumentationRegistry;

import org.apache.commons.compress.archivers.zip.ZipArchiveEntry;
import org.apache.commons.compress.archivers.zip.ZipFile;
import org.junit.Test;

import java.io.File;
import java.io.IOException;

public class IncrementalAppErrorStatsTestsHelper {
    private static final String HELPER_ARG = "remoteApkPath";
    private static final String PAGE_INDEX_TO_BLOCK = "pageIndexToBlock";
    // The apk contains a video resource file which has 9 pages. We only need to block 1 page
    // such that the loading progress is never completed.
    private static final String FILE_PAGE_TO_BLOCK = "res/raw/colors_video.mp4";
    private static final int BLOCK_SIZE = 4096;
    // Instrumentation status code used to write resolution to metrics
    private static final int INST_STATUS_IN_PROGRESS = 2;

    @Test
    public void getPageIndexToBlock() throws IOException {
        final Bundle testArgs = InstrumentationRegistry.getArguments();
        final String apkPath = (String) testArgs.get(HELPER_ARG);
        assertNotNull(apkPath);
        assertTrue(new File(apkPath).exists());
        ZipFile zip = new ZipFile(apkPath);
        final ZipArchiveEntry info = zip.getEntry(FILE_PAGE_TO_BLOCK);
        assertTrue(info.getSize() > BLOCK_SIZE);
        assertTrue(info.getDataOffset() > BLOCK_SIZE * 2);
        final int pageToBlock = (int) info.getDataOffset() / 4096 + 1;
        // Pass data to the host-side test
        Instrumentation inst = InstrumentationRegistry.getInstrumentation();
        Bundle bundle = new Bundle();
        bundle.putString(PAGE_INDEX_TO_BLOCK, String.valueOf(pageToBlock));
        inst.sendStatus(INST_STATUS_IN_PROGRESS, bundle);
    }
}

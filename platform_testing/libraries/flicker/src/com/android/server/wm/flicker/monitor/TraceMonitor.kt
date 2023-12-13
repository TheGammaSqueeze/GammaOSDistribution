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

package com.android.server.wm.flicker.monitor

import androidx.annotation.VisibleForTesting
import com.android.compatibility.common.util.SystemUtil
import com.android.server.wm.flicker.FlickerRunResult
import java.nio.file.Files
import java.nio.file.Path

/**
 * Base class for monitors containing common logic to read the trace as a byte array and save the
 * trace to another location.
 */
abstract class TraceMonitor internal constructor(
    @VisibleForTesting var outputPath: Path,
    protected var sourceTraceFilePath: Path
) : ITransitionMonitor {
    abstract val isEnabled: Boolean

    abstract fun setResult(flickerRunResultBuilder: FlickerRunResult.Builder, traceFile: Path)

    override fun save(testTag: String, flickerRunResultBuilder: FlickerRunResult.Builder) {
        outputPath.toFile().mkdirs()
        val savedTrace = outputPath.resolve("${testTag}_${sourceTraceFilePath.fileName}")
        moveFile(sourceTraceFilePath, savedTrace)
        require(Files.exists(savedTrace)) { "Unable to save trace file $savedTrace" }

        setResult(flickerRunResultBuilder, savedTrace)
    }

    fun save(testTag: String) {
        outputPath.toFile().mkdirs()
        val savedTrace = outputPath.resolve("${testTag}_${sourceTraceFilePath.fileName}")
        moveFile(sourceTraceFilePath, savedTrace)
        require(Files.exists(savedTrace)) { "Unable to save trace file $savedTrace" }
    }

    private fun moveFile(src: Path, dst: Path) {
        // Move the  file to the output directory
        // Note: Due to b/141386109, certain devices do not allow moving the files between
        //       directories with different encryption policies, so manually copy and then
        //       remove the original file
        //       Moreover, the copied trace file may end up with different permissions, resulting
        //       in b/162072200, to prevent this, ensure the files are readable after copying
        SystemUtil.runShellCommand("cp $src $dst")
        SystemUtil.runShellCommand("chmod a+r $dst")
        SystemUtil.runShellCommand("rm $src")
    }
}

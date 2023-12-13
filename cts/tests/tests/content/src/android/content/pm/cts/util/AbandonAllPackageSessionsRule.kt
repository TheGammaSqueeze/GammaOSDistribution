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

package android.content.pm.cts.util

import androidx.test.platform.app.InstrumentationRegistry
import org.junit.rules.TestRule
import org.junit.runner.Description
import org.junit.runners.model.Statement

/**
 * Abandons all sessions for the instrumentation package after the test has finished.
 */
class AbandonAllPackageSessionsRule : TestRule {
    override fun apply(base: Statement, description: Description?) = object : Statement() {
        override fun evaluate() {
            try {
                base.evaluate()
            } finally {
                val packageInstaller = InstrumentationRegistry.getInstrumentation()
                        .getContext().packageManager.packageInstaller
                packageInstaller.mySessions.forEach {
                    try {
                        packageInstaller.abandonSession(it.sessionId)
                    } catch (ignored: Exception) {
                    }
                }
            }
        }
    }
}

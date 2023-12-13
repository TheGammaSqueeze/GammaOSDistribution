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

package com.android.server.wm.flicker.windowmanager

import com.android.server.wm.flicker.readTestFile
import com.android.server.wm.flicker.readWmTraceFromFile
import com.android.server.wm.traces.common.windowmanager.WindowManagerTrace
import com.android.server.wm.traces.common.windowmanager.WindowManagerState
import com.android.server.wm.traces.common.windowmanager.windows.WindowContainer
import com.android.server.wm.traces.parser.windowmanager.WindowManagerTraceParser
import com.google.common.truth.Truth.assertThat
import com.google.common.truth.Truth.assertWithMessage
import org.junit.FixMethodOrder
import org.junit.Test
import org.junit.runners.MethodSorters
import java.lang.reflect.Modifier

/**
 * Contains [WindowManagerTrace] tests. To run this test: `atest
 * FlickerLibTest:WindowManagerTraceTest`
 */
@FixMethodOrder(MethodSorters.NAME_ASCENDING)
class WindowManagerTraceTest {
    private val trace: WindowManagerTrace by lazy {
        readWmTraceFromFile("wm_trace_openchrome.pb")
    }

    @Test
    fun canParseAllEntries() {
        val firstEntry = trace.entries[0]
        assertThat(firstEntry.timestamp).isEqualTo(9213763541297L)
        assertThat(firstEntry.windowStates.size).isEqualTo(10)
        assertThat(firstEntry.visibleWindows.size).isEqualTo(5)
        assertThat(trace.entries[trace.entries.size - 1].timestamp)
                .isEqualTo(9216093628925L)
    }

    @Test
    fun canDetectAppWindow() {
        val appWindows = trace.getEntry(9213763541297L).appWindows
        assertWithMessage("Unable to detect app windows").that(appWindows.size).isEqualTo(2)
    }

    @Test
    fun canParseFromDump() {
        val trace = try {
            WindowManagerTraceParser.parseFromDump(
                readTestFile("wm_trace_dump.pb"))
        } catch (e: Exception) {
            throw RuntimeException(e)
        }
        assertWithMessage("Unable to parse dump").that(trace).hasSize(1)
    }

    /**
     * Access all public methods and invokes all public getters from the object
     * to check that all lazy properties contain valid values
     */
    private fun <T> Class<T>.accessProperties(obj: Any) {
        val propertyValues = this.declaredFields
            .filter { Modifier.isPublic(it.modifiers) }
            .map { kotlin.runCatching { Pair(it.name, it.get(obj)) } }
            .filter { it.isFailure }

        assertWithMessage("The following properties could not be read: " +
            propertyValues.joinToString("\n"))
            .that(propertyValues)
            .isEmpty()

        val getterValues = this.declaredMethods
            .filter {
                Modifier.isPublic(it.modifiers) &&
                    it.name.startsWith("get") &&
                    it.parameterCount == 0
            }
            .map { kotlin.runCatching { Pair(it.name, it.invoke(obj)) } }
            .filter { it.isFailure }

        assertWithMessage("The following methods could not be invoked: " +
            getterValues.joinToString("\n"))
            .that(getterValues)
            .isEmpty()

        this.superclass?.accessProperties(obj)
        if (obj is WindowContainer) {
            obj.children.forEach { it::class.java.accessProperties(it) }
        }
    }

    /**
     * Tests if all properties of the flicker objects are accessible. This is necessary because
     * most values are lazy initialized and only trigger errors when being accessed for the
     * first time.
     */
    @Test
    fun canAccessAllProperties() {
        arrayOf("wm_trace_activity_transition.pb", "wm_trace_openchrome2.pb").forEach { traceName ->
            val trace = readWmTraceFromFile(traceName)
            assertWithMessage("Unable to parse dump")
                .that(trace.entries.size)
                .isGreaterThan(1)

            trace.entries.forEach { entry: WindowManagerState ->
                entry::class.java.accessProperties(entry)
                entry.displays.forEach { it::class.java.accessProperties(it) }
            }
        }
    }

    @Test
    fun canDetectValidState() {
        val entry = trace.getEntry(9213763541297)
        assertWithMessage("${entry.timestamp}: ${entry.getIsIncompleteReason()}")
            .that(entry.isIncomplete())
            .isFalse()
    }

    @Test
    fun canDetectInvalidState() {
        val entry = trace.getEntry(9215511235586)
        assertWithMessage("${entry.timestamp}: ${entry.getIsIncompleteReason()}")
            .that(entry.isIncomplete())
            .isTrue()

        assertThat(entry.getIsIncompleteReason())
            .contains("No resumed activities found")
    }

    @Test
    fun canFilter() {
        val splitWmTrace = trace.filter(9215895891561, 9216093628925)

        assertThat(splitWmTrace).isNotEmpty()

        assertThat(splitWmTrace.entries.first().timestamp).isEqualTo(9215895891561)
        assertThat(splitWmTrace.entries.last().timestamp).isEqualTo(9216093628925)
    }

    @Test
    fun canFilter_wrongTimestamps() {
        val splitWmTrace = trace.filter(71607477186189, 71607812120180)

        assertThat(splitWmTrace).isEmpty()
    }
}

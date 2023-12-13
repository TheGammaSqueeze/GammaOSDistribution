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

package com.android.server.wm.flicker.traces

import com.android.server.wm.flicker.assertions.Assertion
import com.android.server.wm.flicker.assertions.AssertionsChecker
import com.android.server.wm.flicker.assertions.FlickerSubject
import com.android.server.wm.traces.common.prettyTimestamp
import com.google.common.truth.Fact
import com.google.common.truth.FailureMetadata

/**
 * Base subject for flicker trace assertions
 */
abstract class FlickerTraceSubject<EntrySubject : FlickerSubject>(
    fm: FailureMetadata,
    data: Any?
) : FlickerSubject(fm, data) {
    override val timestamp: Long get() = subjects.first().timestamp
    override val selfFacts by lazy {
        val firstTimestamp = subjects.firstOrNull()?.timestamp ?: 0L
        val lastTimestamp = subjects.lastOrNull()?.timestamp ?: 0L
        val first = "${prettyTimestamp(firstTimestamp)} (timestamp=$firstTimestamp)"
        val last = "${prettyTimestamp(lastTimestamp)} (timestamp=$lastTimestamp)"
        listOf(Fact.fact("Trace start", first),
                Fact.fact("Trace end", last))
    }

    protected val assertionsChecker = AssertionsChecker<EntrySubject>()
    private var newAssertionBlock = true

    abstract val subjects: List<EntrySubject>

    /**
     * Adds a new assertion block (if preceded by [then]) or appends an assertion to the
     * latest existing assertion block
     *
     * @param name Assertion name
     * @param isOptional If this assertion is optional or must pass
     */
    protected fun addAssertion(
        name: String,
        isOptional: Boolean = false,
        assertion: Assertion<EntrySubject>
    ) {
        if (newAssertionBlock) {
            assertionsChecker.add(name, isOptional, assertion)
        } else {
            assertionsChecker.append(name, isOptional, assertion)
        }
        newAssertionBlock = false
    }

    /**
     * Run the assertions for all trace entries
     */
    fun forAllEntries() {
        assertionsChecker.test(subjects)
    }

    /**
     * User-defined entry point for the first trace entry
     */
    fun first(): EntrySubject = subjects.first()

    /**
     * User-defined entry point for the last trace entry
     */
    fun last(): EntrySubject = subjects.last()

    /**
     * Signal that the last assertion set is complete. The next assertion added will start a new
     * set of assertions.
     *
     * E.g.: checkA().then().checkB()
     *
     * Will produce two sets of assertions (checkA) and (checkB) and checkB will only be checked
     * after checkA passes.
     */
    open fun then(): FlickerTraceSubject<EntrySubject> = apply {
        startAssertionBlock()
    }

    /**
     * Ignores the first entries in the trace, until the first assertion passes. If it reaches the
     * end of the trace without passing any assertion, return a failure with the name/reason from
     * the first assertion
     *
     * @return
     */
    open fun skipUntilFirstAssertion(): FlickerTraceSubject<EntrySubject> =
        apply { assertionsChecker.skipUntilFirstAssertion() }

    /**
     * Signal that the last assertion set is complete. The next assertion added will start a new
     * set of assertions.
     *
     * E.g.: checkA().then().checkB()
     *
     * Will produce two sets of assertions (checkA) and (checkB) and checkB will only be checked
     * after checkA passes.
     */
    private fun startAssertionBlock() {
        newAssertionBlock = true
    }

    /**
     * Checks whether all the trace entries on the list are visible for more than one consecutive
     * entry
     *
     * @param [visibleEntriesProvider] a list of all the entries with their name and index
     */
    protected fun visibleEntriesShownMoreThanOneConsecutiveTime(
        visibleEntriesProvider: (EntrySubject) -> Set<String>
    ) {
        if (subjects.isEmpty()) {
            return
        }
        var lastVisible = visibleEntriesProvider(subjects.first())
        val lastNew = lastVisible.toMutableSet()

        subjects.drop(1).forEachIndexed { index, entrySubject ->
            val currentVisible = visibleEntriesProvider(entrySubject)
            val newVisible = currentVisible.filter { it !in lastVisible }
            lastNew.removeAll(currentVisible)

            if (lastNew.isNotEmpty()) {
                val prevEntry = subjects[index]
                prevEntry.fail("$lastNew is not visible for 2 entries")
            }
            lastNew.addAll(newVisible)
            lastVisible = currentVisible
        }

        if (lastNew.isNotEmpty()) {
            val lastEntry = subjects.last()
            lastEntry.fail("$lastNew is not visible for 2 entries")
        }
    }

    override fun toString(): String = "${this::class.simpleName}" +
            "(${subjects.firstOrNull()?.timestamp ?: 0},${subjects.lastOrNull()?.timestamp ?: 0})"
}
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

package com.android.server.wm.traces.common

/**
 * The utility class to wait a condition with customized options.
 * The default retry policy is 5 times with interval 1 second.
 *
 * @param <T> The type of the object to validate.
 *
 * <p>Sample:</p>
 * <pre>
 * // Simple case.
 * if (Condition.waitFor("true value", () -> true)) {
 *     println("Success");
 * }
 * // Wait for customized result with customized validation.
 * String result = WaitForCondition.Builder(supplier = () -> "Result string")
 *         .withCondition(str -> str.equals("Expected string"))
 *         .withRetryIntervalMs(500)
 *         .withRetryLimit(3)
 *         .onFailure(str -> println("Failed on " + str)))
 *         .build()
 *         .waitFor()
 * </pre>

 * @param condition If it returns true, that means the condition is satisfied.
 */
class WaitCondition<T> private constructor(
    private val supplier: () -> T,
    private val condition: Condition<T>,
    private val retryLimit: Int,
    private val onLog: ((String) -> Unit)?,
    private val onFailure: ((T) -> Any)?,
    private val onRetry: ((T) -> Any)?,
    private val onSuccess: ((T) -> Any)?
) {
    /**
     * @return `false` if the condition does not satisfy within the time limit.
     */
    fun waitFor(): Boolean {
        onLog?.invoke("***Waiting for $condition")
        var currState: T? = null
        for (i in 0..retryLimit) {
            currState = supplier.invoke()
            if (condition.isSatisfied(currState)) {
                onLog?.invoke("***Waiting for $condition ... Success!")
                onSuccess?.invoke(currState)
                return true
            } else {
                val detailedMessage = condition.getMessage(currState)
                onLog?.invoke("***Waiting for $detailedMessage... retry=${i + 1}")
                if (i < retryLimit) {
                    onRetry?.invoke(currState)
                }
            }
        }

        val detailedMessage = if (currState != null) {
            condition.getMessage(currState)
        } else {
            condition.toString()
        }
        onLog?.invoke("***Waiting for $detailedMessage ... Failed!")
        if (onFailure != null) {
            require(currState != null) { "Missing last result for failure notification" }
            onFailure.invoke(currState)
        }
        return false
    }

    class Builder<T>(
        private val supplier: () -> T,
        private var retryLimit: Int
    ) {
        private val conditions = mutableListOf<Condition<T>>()
        private var onFailure: ((T) -> Any)? = null
        private var onRetry: ((T) -> Any)? = null
        private var onSuccess: ((T) -> Any)? = null
        private var onLog: ((String) -> Unit)? = null

        fun withCondition(condition: Condition<T>) =
            apply { conditions.add(condition) }

        fun withCondition(message: String, condition: (T) -> Boolean) =
            apply { withCondition(Condition(message, condition)) }

        private fun spreadConditionList(): List<Condition<T>> =
            conditions.flatMap {
                if (it is ConditionList<T>) {
                    it.conditions
                } else {
                    listOf(it)
                }
            }

        /**
         * Executes the action when the condition does not satisfy within the time limit. The passed
         * object to the consumer will be the last result from the supplier.
         */
        fun onFailure(onFailure: (T) -> Any): Builder<T> =
            apply { this.onFailure = onFailure }

        fun onLog(onLog: (String) -> Unit): Builder<T> =
            apply { this.onLog = onLog }

        fun onRetry(onRetry: ((T) -> Any)? = null): Builder<T> =
            apply { this.onRetry = onRetry }

        fun onSuccess(onRetry: ((T) -> Any)? = null): Builder<T> =
            apply { this.onSuccess = onRetry }

        fun build(): WaitCondition<T> =
            WaitCondition(supplier, ConditionList(spreadConditionList()), retryLimit,
                onLog, onFailure, onRetry, onSuccess)
    }

    companion object {
        // TODO(b/112837428): Implement a incremental retry policy to reduce the unnecessary
        // constant time, currently keep the default as 5*1s because most of the original code
        // uses it, and some tests might be sensitive to the waiting interval.
        const val DEFAULT_RETRY_LIMIT = 10
        const val DEFAULT_RETRY_INTERVAL_MS = 500L
    }
}
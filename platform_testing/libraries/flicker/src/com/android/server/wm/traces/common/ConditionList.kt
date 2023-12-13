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
 * The utility class to validate a set of conditions
 *
 * This class is used to easily integrate multiple conditions into a single
 * verification, for example, during [WaitCondition], while keeping the individual
 * conditions separate for better reuse
 *
 * @param conditions conditions to be checked
 */
class ConditionList<T>(
    val conditions: List<Condition<T>>
) : Condition<T>("", { false }) {
    override val message: String
        get() = conditions.joinToString(" and ") { it.toString() }

    override val condition: (T) -> Boolean
        get() = {
            conditions.all { condition -> condition.isSatisfied(it) }
        }

    override fun getMessage(value: T): String = conditions
        .joinToString(" and ") { it.getMessage(value) }
}
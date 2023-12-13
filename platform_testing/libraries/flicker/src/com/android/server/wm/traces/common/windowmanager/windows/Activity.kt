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

package com.android.server.wm.traces.common.windowmanager.windows

/**
 * Represents an activity in the window manager hierarchy
 *
 * This is a generic object that is reused by both Flicker and Winscope and cannot
 * access internal Java/Android functionality
 *
 **/
open class Activity(
    name: String,
    val state: String,
    visible: Boolean,
    val frontOfTask: Boolean,
    val procId: Int,
    val isTranslucent: Boolean,
    windowContainer: WindowContainer
) : WindowContainer(windowContainer, name, visible) {
    /**
     * Checks if the activity contains a window with title containing [partialWindowTitle]
     *
     * @param partialWindowTitle window title to search
     */
    fun hasWindow(partialWindowTitle: String): Boolean {
        return collectDescendants<WindowState> { it.title.contains(partialWindowTitle) }
                .isNotEmpty()
    }

    override fun toString(): String {
        return "${this::class.simpleName}: {$token $title} state=$state visible=$isVisible"
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (other !is Activity) return false

        if (state != other.state) return false
        if (frontOfTask != other.frontOfTask) return false
        if (procId != other.procId) return false
        if (isTranslucent != other.isTranslucent) return false
        if (orientation != other.orientation) return false
        if (title != other.title) return false
        if (token != other.token) return false

        return true
    }

    override fun hashCode(): Int {
        var result = super.hashCode()
        result = 31 * result + state.hashCode()
        result = 31 * result + frontOfTask.hashCode()
        result = 31 * result + procId
        result = 31 * result + isTranslucent.hashCode()
        return result
    }
}
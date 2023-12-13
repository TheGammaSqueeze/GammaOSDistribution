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
 * Represents a display area in the window manager hierarchy
 *
 * This is a generic object that is reused by both Flicker and Winscope and cannot
 * access internal Java/Android functionality
 *
 */
open class DisplayArea(
    val isTaskDisplayArea: Boolean,
    windowContainer: WindowContainer
) : WindowContainer(windowContainer) {
    val activities: Array<Activity>
        get() = if (isTaskDisplayArea) {
            this.collectDescendants()
        } else {
            emptyArray()
        }

    fun containsActivity(activityName: String): Boolean {
        return if (!isTaskDisplayArea) {
            false
        } else {
            activities.any { it.title == activityName }
        }
    }

    override fun toString(): String {
        return "${this::class.simpleName} {$token $title} isTaskArea=$isTaskDisplayArea"
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (other !is DisplayArea) return false

        if (isTaskDisplayArea != other.isTaskDisplayArea) return false
        if (isVisible != other.isVisible) return false
        if (orientation != other.orientation) return false
        if (title != other.title) return false
        if (token != other.token) return false

        return true
    }

    override fun hashCode(): Int {
        var result = super.hashCode()
        result = 31 * result + isTaskDisplayArea.hashCode()
        return result
    }
}
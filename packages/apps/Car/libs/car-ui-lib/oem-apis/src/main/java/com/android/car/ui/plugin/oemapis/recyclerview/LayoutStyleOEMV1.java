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
package com.android.car.ui.plugin.oemapis.recyclerview;

/**
 * Class for storing recyclerview layout style information.
 */
public interface LayoutStyleOEMV1 {

    int LAYOUT_TYPE_LINEAR = 0;
    int LAYOUT_TYPE_GRID = 1;

    int ORIENTATION_HORIZONTAL = 0;
    int ORIENTATION_VERTICAL = 1;

    /** Returns number of recyclerview spans */
    int getSpanCount();

    /** Returns LAYOUT_TYPE_LINEAR vs LAYOUT_TYPE_GRID */
    int getLayoutType();

    /** Returns layout direction 0 for VERTICAL, 1 for HORIZONTAL */
    int getOrientation();

    /** Returns true if layout is reversed */
    boolean getReverseLayout();

    /** {@link androidx.recyclerview.widget.GridLayoutManager.SpanSizeLookup#getSpanSize} */
    default int getSpanSize(int position) {
        return 1;
    }
}

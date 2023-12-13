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
package com.android.car.ui.plugin.oemapis.recyclerview;

import android.graphics.drawable.Drawable;

/**
 * Set of attributes passed from UI/layout to the oem implementation
 */
public interface RecyclerViewAttributesOEMV1 {

    int SIZE_SMALL = 0;
    int SIZE_MEDIUM = 1;
    int SIZE_LARGE = 2;

    /** Returns if rotary scroll is enabled */
    boolean isRotaryScrollEnabled();

    /** Describes the expected relative size of the
     * {@link androidx.recyclerview.widget.RecyclerView}. The list may be rendered differently for
     * each expected size.
     */
    int getSize();

    /** Returns information regarding the layout style */
    LayoutStyleOEMV1 getLayoutStyle();

    /** Returns requested width of the list view */
    int getLayoutWidth();

    /** Returns requested height of the list view */
    int getLayoutHeight();

    /** Returns requested minimum width of the list view */
    int geMinWidth();

    /** Returns requested minimum height of the list view */
    int getMinHeight();

    /** Returns requested left padding for the list view */
    int getPaddingLeft();

    /** Returns requested right padding for the list view */
    int getPaddingRight();

    /** Returns requested top padding for the list view */
    int getPaddingTop();

    /** Returns requested bottom padding for the list view */
    int getPaddingBottom();

    /** Returns requested left margin for the list view */
    int getMarginLeft();

    /** Returns requested right margin for the list view */
    int getMarginRight();

    /** Returns requested top margin for the list view */
    int getMarginTop();

    /** Returns requested bottom margin for the list view */
    int getMarginBottom();

    /** Returns background specified for the list view */
    Drawable getBackground();
}

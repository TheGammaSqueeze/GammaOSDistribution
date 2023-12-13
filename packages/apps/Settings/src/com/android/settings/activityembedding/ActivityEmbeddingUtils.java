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

package com.android.settings.activityembedding;

import android.app.Activity;
import android.app.ActivityTaskManager;
import android.content.Context;
import android.graphics.Rect;
import android.util.DisplayMetrics;
import android.util.FeatureFlagUtils;
import android.util.Log;
import android.util.TypedValue;

import androidx.window.embedding.SplitController;

/** An util class collecting all common methods for the embedding activity features. */
public class ActivityEmbeddingUtils {
    public static final float SPLIT_RATIO = 0.5f;
    // The smallest value of current width of the window when the split should be used.
    private static final float MIN_CURRENT_SCREEN_SPLIT_WIDTH_DP = 720f;
    // The smallest value of the smallest-width (sw) of the window in any rotation when
    // the split should be used.
    private static final float MIN_SMALLEST_SCREEN_SPLIT_WIDTH_DP = 600f;
    private static final String TAG = "ActivityEmbeddingUtils";

    /** Get the smallest pixel value of width of the window when the split should be used. */
    public static int getMinCurrentScreenSplitWidthPx(Context context) {
        final DisplayMetrics dm = context.getResources().getDisplayMetrics();
        return (int) TypedValue.applyDimension(
                TypedValue.COMPLEX_UNIT_DIP, MIN_CURRENT_SCREEN_SPLIT_WIDTH_DP, dm);
    }

    /**
     * Get the smallest pixel value of the smallest-width (sw) of the window in any rotation when
     * the split should be used.
     */
    public static int getMinSmallestScreenSplitWidthPx(Context context) {
        final DisplayMetrics dm = context.getResources().getDisplayMetrics();
        return (int) TypedValue.applyDimension(
                TypedValue.COMPLEX_UNIT_DIP, MIN_SMALLEST_SCREEN_SPLIT_WIDTH_DP, dm);
    }

    /** Whether to support embedding activity feature. */
    public static boolean isEmbeddingActivityEnabled(Context context) {
        final boolean isFlagEnabled = FeatureFlagUtils.isEnabled(context,
                FeatureFlagUtils.SETTINGS_SUPPORT_LARGE_SCREEN);
        final boolean isSplitSupported = SplitController.getInstance().isSplitSupported();

        Log.d(TAG, "isFlagEnabled = " + isFlagEnabled);
        Log.d(TAG, "isSplitSupported = " + isSplitSupported);

        return isFlagEnabled && isSplitSupported;
    }

    /** Whether the screen meets two-pane resolution. */
    public static boolean isTwoPaneResolution(Activity activity) {
        final Rect currentTaskBounds =
                ActivityTaskManager.getInstance().getTaskBounds(activity.getTaskId());

        return currentTaskBounds.width() >= getMinCurrentScreenSplitWidthPx(activity)
                && currentTaskBounds.height() >= getMinSmallestScreenSplitWidthPx(activity);
    }
}

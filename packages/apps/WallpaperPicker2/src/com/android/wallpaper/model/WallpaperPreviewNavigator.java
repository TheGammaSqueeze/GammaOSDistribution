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
package com.android.wallpaper.model;

import com.android.wallpaper.model.WallpaperInfo;

/**
 * Navigates to a wallpaper preview activity.
 */
public interface WallpaperPreviewNavigator {
    /**
     * Navigates full screen wallpaper preview
     *
     * @param wallpaperInfo the wallpaper to preview
     * @param isViewAsHome  {@code true} if it's home wallpaper preview, {@code false} if it's
     *                      lock screen wallpaper preview
     */
    void showViewOnlyPreview(WallpaperInfo wallpaperInfo, boolean isViewAsHome);
}

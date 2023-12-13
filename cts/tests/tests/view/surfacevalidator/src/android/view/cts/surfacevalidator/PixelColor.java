/*
 * Copyright (C) 2016 The Android Open Source Project
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
package android.view.cts.surfacevalidator;

public class PixelColor {
    public static final int BLACK = 0xFF000000;
    public static final int RED = 0xFF0000FF;
    public static final int GREEN = 0xFF00FF00;
    public static final int BLUE = 0xFFFF0000;
    public static final int YELLOW = 0xFF00FFFF;
    public static final int MAGENTA = 0xFFFF00FF;
    public static final int WHITE = 0xFFFFFFFF;

    public static final int TRANSPARENT_RED = 0x7F0000FF;
    public static final int TRANSPARENT_BLUE = 0x7FFF0000;
    public static final int TRANSPARENT = 0x00000000;

    // Default to black
    public short mMinAlpha;
    public short mMaxAlpha;
    public short mMinRed;
    public short mMaxRed;
    public short mMinBlue;
    public short mMaxBlue;
    public short mMinGreen;
    public short mMaxGreen;

    public short mAlpha;
    public short mRed;
    public short mGreen;
    public short mBlue;

    public PixelColor(int color) {
        mAlpha = (short) ((color >> 24) & 0xFF);
        mBlue = (short) ((color >> 16) & 0xFF);
        mGreen = (short) ((color >> 8) & 0xFF);
        mRed = (short) (color & 0xFF);

        mMinAlpha = (short) getMinValue(mAlpha);
        mMaxAlpha = (short) getMaxValue(mAlpha);
        mMinRed = (short) getMinValue(mRed);
        mMaxRed = (short) getMaxValue(mRed);
        mMinBlue = (short) getMinValue(mBlue);
        mMaxBlue = (short) getMaxValue(mBlue);
        mMinGreen = (short) getMinValue(mGreen);
        mMaxGreen = (short) getMaxValue(mGreen);
    }

    public PixelColor() {
        this(BLACK);
    }

    private int getMinValue(short color) {
        return Math.max(color - 4, 0);
    }

    private int getMaxValue(short color) {
        return Math.min(color + 4, 0xFF);
    }
}

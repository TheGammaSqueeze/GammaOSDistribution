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

package android.view.cts.surfacevalidator;

import static androidx.test.platform.app.InstrumentationRegistry.getInstrumentation;

import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import android.app.Activity;
import android.app.Instrumentation;
import android.app.UiAutomation;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.Rect;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.Gravity;
import android.view.PointerIcon;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.view.WindowManager;
import android.widget.FrameLayout;

import androidx.annotation.NonNull;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

public class ASurfaceControlTestActivity extends Activity {
    private static final String TAG = "ASurfaceControlTestActivity";
    private static final boolean DEBUG = true;

    private static final int DEFAULT_LAYOUT_WIDTH = 100;
    private static final int DEFAULT_LAYOUT_HEIGHT = 100;
    private static final int OFFSET_X = 100;
    private static final int OFFSET_Y = 100;
    private static final long WAIT_TIMEOUT_S = 5;

    private final Handler mHandler = new Handler(Looper.getMainLooper());
    private volatile boolean mOnWatch;

    private SurfaceView mSurfaceView;
    private FrameLayout.LayoutParams mLayoutParams;
    private FrameLayout mParent;

    private Bitmap mScreenshot;

    private Instrumentation mInstrumentation;

    private final CountDownLatch mReadyToStart = new CountDownLatch(1);

    @Override
    public void onEnterAnimationComplete() {
        mReadyToStart.countDown();
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        final PackageManager packageManager = getPackageManager();
        mOnWatch = packageManager.hasSystemFeature(PackageManager.FEATURE_WATCH);
        if (mOnWatch) {
            // Don't try and set up test/capture infrastructure - they're not supported
            return;
        }

        getWindow().getDecorView().setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_HIDE_NAVIGATION | View.SYSTEM_UI_FLAG_FULLSCREEN);
        // Set the NULL pointer icon so that it won't obstruct the captured image.
        getWindow().getDecorView().setPointerIcon(
                PointerIcon.getSystemIcon(this, PointerIcon.TYPE_NULL));
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        mLayoutParams = new FrameLayout.LayoutParams(DEFAULT_LAYOUT_WIDTH, DEFAULT_LAYOUT_HEIGHT,
                Gravity.LEFT | Gravity.TOP);

        mLayoutParams.topMargin = OFFSET_Y;
        mLayoutParams.leftMargin = OFFSET_X;
        mSurfaceView = new SurfaceView(this);
        mSurfaceView.getHolder().setFixedSize(DEFAULT_LAYOUT_WIDTH, DEFAULT_LAYOUT_HEIGHT);

        mParent = findViewById(android.R.id.content);

        mInstrumentation = getInstrumentation();
    }

    public void verifyTest(SurfaceHolder.Callback surfaceHolderCallback,
            PixelChecker pixelChecker) {
        try {
            mReadyToStart.await(5, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
        }

        if (mOnWatch) {
            /**
             * Watch devices not supported, since they may not support:
             *    1) displaying unmasked windows
             *    2) RenderScript
             *    3) Video playback
             */
            return;
        }

        final SurfaceHolderCallback surfaceHolderCallbackWrapper =
                new SurfaceHolderCallback(surfaceHolderCallback);
        mHandler.post(() -> {
            mSurfaceView.getHolder().addCallback(surfaceHolderCallbackWrapper);
            mParent.addView(mSurfaceView, mLayoutParams);
        });
        mInstrumentation.waitForIdleSync();
        surfaceHolderCallbackWrapper.waitForSurfaceCreated();

        final CountDownLatch countDownLatch = new CountDownLatch(1);
        UiAutomation uiAutomation = mInstrumentation.getUiAutomation();
        mHandler.post(() -> {
            mScreenshot = uiAutomation.takeScreenshot(getWindow());
            mParent.removeAllViews();
            countDownLatch.countDown();
        });

        try {
            countDownLatch.await(WAIT_TIMEOUT_S, TimeUnit.SECONDS);
        } catch (Exception e) {
        }

        assertNotNull(mScreenshot);

        Bitmap swBitmap = mScreenshot.copy(Bitmap.Config.ARGB_8888, false);
        mScreenshot.recycle();

        int numMatchingPixels = pixelChecker.getNumMatchingPixels(swBitmap);
        Rect bounds = pixelChecker.getBoundsToCheck(swBitmap);
        boolean success = pixelChecker.checkPixels(numMatchingPixels, swBitmap.getWidth(),
                swBitmap.getHeight());
        swBitmap.recycle();

        assertTrue("Actual matched pixels:" + numMatchingPixels
                + " Bitmap size:" + bounds.width() + "x" + bounds.height(), success);
    }

    public SurfaceView getSurfaceView() {
        return mSurfaceView;
    }

    public abstract static class MultiRectChecker extends RectChecker {
        public MultiRectChecker(Rect boundsToCheck) {
            super(boundsToCheck);
        }

        public abstract PixelColor getExpectedColor(int x, int y);
    }

    public static class RectChecker extends PixelChecker {
        private final Rect mBoundsToCheck;

        public RectChecker(Rect boundsToCheck) {
            super();
            mBoundsToCheck = boundsToCheck;
        }

        public RectChecker(Rect boundsToCheck, int expectedColor) {
            super(expectedColor);
            mBoundsToCheck = boundsToCheck;
        }

        public boolean checkPixels(int matchingPixelCount, int width, int height) {
            int expectedPixelCountMin = mBoundsToCheck.width() * mBoundsToCheck.height() - 100;
            int expectedPixelCountMax = mBoundsToCheck.width() * mBoundsToCheck.height();
            return matchingPixelCount > expectedPixelCountMin
                    && matchingPixelCount <= expectedPixelCountMax;
        }

        @Override
        public Rect getBoundsToCheck(Bitmap bitmap) {
            return mBoundsToCheck;
        }
    }

    public abstract static class PixelChecker {
        private final PixelColor mPixelColor;
        private final boolean mLogWhenNoMatch;

        public PixelChecker() {
            this(Color.BLACK, true);
        }

        public PixelChecker(int color) {
            this(color, true);
        }

        public PixelChecker(int color, boolean logWhenNoMatch) {
            mPixelColor = new PixelColor(color);
            mLogWhenNoMatch = logWhenNoMatch;
        }

        int getNumMatchingPixels(Bitmap bitmap) {
            int numMatchingPixels = 0;
            int numErrorsLogged = 0;
            Rect boundsToCheck = getBoundsToCheck(bitmap);
            for (int x = boundsToCheck.left; x < boundsToCheck.right; x++) {
                for (int y = boundsToCheck.top; y < boundsToCheck.bottom; y++) {
                    int color = bitmap.getPixel(x + OFFSET_X, y + OFFSET_Y);
                    if (matchesColor(getExpectedColor(x, y), color)) {
                        numMatchingPixels++;
                    } else if (DEBUG && mLogWhenNoMatch && numErrorsLogged < 100) {
                        // We don't want to spam the logcat with errors if something is really
                        // broken. Only log the first 100 errors.
                        PixelColor expected = getExpectedColor(x, y);
                        int expectedColor = Color.argb(expected.mAlpha, expected.mRed,
                                expected.mGreen, expected.mBlue);
                        Log.e(TAG, String.format(
                                "Failed to match (%d, %d) color=0x%08X expected=0x%08X", x, y,
                                color, expectedColor));
                        numErrorsLogged++;
                    }
                }
            }
            return numMatchingPixels;
        }

        boolean matchesColor(PixelColor expectedColor, int color) {
            final float red = Color.red(color);
            final float green = Color.green(color);
            final float blue = Color.blue(color);
            final float alpha = Color.alpha(color);

            return alpha <= expectedColor.mMaxAlpha
                    && alpha >= expectedColor.mMinAlpha
                    && red <= expectedColor.mMaxRed
                    && red >= expectedColor.mMinRed
                    && green <= expectedColor.mMaxGreen
                    && green >= expectedColor.mMinGreen
                    && blue <= expectedColor.mMaxBlue
                    && blue >= expectedColor.mMinBlue;
        }

        public abstract boolean checkPixels(int matchingPixelCount, int width, int height);

        public Rect getBoundsToCheck(Bitmap bitmap) {
            return new Rect(1, 1, DEFAULT_LAYOUT_WIDTH - 1, DEFAULT_LAYOUT_HEIGHT - 1);
        }

        public PixelColor getExpectedColor(int x, int y) {
            return mPixelColor;
        }
    }

    public static class SurfaceHolderCallback implements SurfaceHolder.Callback {
        private final SurfaceHolder.Callback mTestCallback;
        private final CountDownLatch mSurfaceCreatedLatch;

        SurfaceHolderCallback(SurfaceHolder.Callback callback) {
            mTestCallback = callback;
            mSurfaceCreatedLatch = new CountDownLatch(1);
        }

        @Override
        public void surfaceCreated(@NonNull SurfaceHolder holder) {
            mTestCallback.surfaceCreated(holder);
            mSurfaceCreatedLatch.countDown();
        }

        @Override
        public void surfaceChanged(@NonNull SurfaceHolder holder, int format, int width,
                int height) {
            mTestCallback.surfaceChanged(holder, format, width, height);
        }

        @Override
        public void surfaceDestroyed(@NonNull SurfaceHolder holder) {
            mTestCallback.surfaceDestroyed(holder);
        }

        public void waitForSurfaceCreated() {
            try {
                mSurfaceCreatedLatch.await(WAIT_TIMEOUT_S, TimeUnit.SECONDS);
            } catch (InterruptedException e) {
            }
        }
    }
}

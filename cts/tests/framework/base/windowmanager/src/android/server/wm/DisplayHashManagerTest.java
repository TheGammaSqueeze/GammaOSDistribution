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

package android.server.wm;

import static android.view.WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS;
import static android.view.displayhash.DisplayHashResultCallback.DISPLAY_HASH_ERROR_INVALID_BOUNDS;
import static android.view.displayhash.DisplayHashResultCallback.DISPLAY_HASH_ERROR_INVALID_HASH_ALGORITHM;
import static android.view.displayhash.DisplayHashResultCallback.DISPLAY_HASH_ERROR_NOT_VISIBLE_ON_SCREEN;
import static android.view.displayhash.DisplayHashResultCallback.DISPLAY_HASH_ERROR_TOO_MANY_REQUESTS;
import static android.widget.LinearLayout.VERTICAL;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import android.app.Activity;
import android.app.Instrumentation;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.Point;
import android.graphics.Rect;
import android.os.Bundle;
import android.platform.test.annotations.Presubmit;
import android.view.Gravity;
import android.view.View;
import android.view.ViewTreeObserver;
import android.view.WindowManager;
import android.view.displayhash.DisplayHash;
import android.view.displayhash.DisplayHashManager;
import android.view.displayhash.DisplayHashResultCallback;
import android.view.displayhash.VerifiedDisplayHash;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

import androidx.annotation.NonNull;
import androidx.test.platform.app.InstrumentationRegistry;
import androidx.test.rule.ActivityTestRule;

import com.android.compatibility.common.util.SystemUtil;

import org.junit.After;
import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Set;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.Executor;
import java.util.concurrent.TimeUnit;

@Presubmit
public class DisplayHashManagerTest {
    //TODO (b/195136026): There's currently know way to know when the buffer has been drawn in
    // SurfaceFlinger. Use sleep for now to make sure it's been drawn. Once b/195136026 is
    // completed, port this code to listen for the transaction complete so we can be sure the buffer
    // has been latched.
    private static final int SLEEP_TIME_MS = 1000;

    private final Point mTestViewSize = new Point(200, 300);

    private Instrumentation mInstrumentation;
    private RelativeLayout mMainView;
    private TestActivity mActivity;

    private View mTestView;

    private DisplayHashManager mDisplayHashManager;
    private String mPhashAlgorithm;

    private Executor mExecutor;

    private SyncDisplayHashResultCallback mSyncDisplayHashResultCallback;

    @Rule
    public ActivityTestRule<TestActivity> mActivityRule =
            new ActivityTestRule<>(TestActivity.class);

    @Before
    public void setUp() throws Exception {
        mInstrumentation = InstrumentationRegistry.getInstrumentation();
        Context context = mInstrumentation.getContext();
        Intent intent = new Intent(Intent.ACTION_MAIN);
        intent.setClass(context, TestActivity.class);
        mActivity = mActivityRule.getActivity();

        mActivity.runOnUiThread(() -> {
            mMainView = new RelativeLayout(mActivity);
            mActivity.setContentView(mMainView);
        });
        mInstrumentation.waitForIdleSync();
        mDisplayHashManager = context.getSystemService(DisplayHashManager.class);

        Set<String> algorithms = mDisplayHashManager.getSupportedHashAlgorithms();
        assertNotNull(algorithms);
        assertNotEquals(0, algorithms.size());
        for (String algorithm : algorithms) {
            if ("pHash".equalsIgnoreCase(algorithm)) {
                mPhashAlgorithm = algorithm;
                break;
            }
        }
        assertNotNull(mPhashAlgorithm);

        mExecutor = context.getMainExecutor();
        mSyncDisplayHashResultCallback = new SyncDisplayHashResultCallback();
        SystemUtil.runWithShellPermissionIdentity(
                () -> mDisplayHashManager.setDisplayHashThrottlingEnabled(false));
    }

    @After
    public void tearDown() {
        SystemUtil.runWithShellPermissionIdentity(
                () -> mDisplayHashManager.setDisplayHashThrottlingEnabled(true));
    }

    @Test
    public void testGenerateAndVerifyDisplayHash() {
        setupChildView();

        // A solid color image has expected hash of all 0s
        byte[] expectedImageHash = new byte[8];

        DisplayHash displayHash = generateDisplayHash(null);
        VerifiedDisplayHash verifiedDisplayHash = mDisplayHashManager.verifyDisplayHash(
                displayHash);
        assertNotNull(verifiedDisplayHash);

        assertEquals(mTestViewSize.x, verifiedDisplayHash.getBoundsInWindow().width());
        assertEquals(mTestViewSize.y, verifiedDisplayHash.getBoundsInWindow().height());
        assertArrayEquals(expectedImageHash, verifiedDisplayHash.getImageHash());
    }

    @Test
    public void testGenerateAndVerifyDisplayHash_BoundsInView() {
        setupChildView();

        Rect bounds = new Rect(10, 20, mTestViewSize.x / 2, mTestViewSize.y / 2);
        DisplayHash displayHash = generateDisplayHash(new Rect(bounds));

        VerifiedDisplayHash verifiedDisplayHash = mDisplayHashManager.verifyDisplayHash(
                displayHash);
        assertNotNull(verifiedDisplayHash);
        assertEquals(bounds.width(), verifiedDisplayHash.getBoundsInWindow().width());
        assertEquals(bounds.height(), verifiedDisplayHash.getBoundsInWindow().height());
    }

    @Test
    public void testGenerateAndVerifyDisplayHash_EmptyBounds() {
        setupChildView();

        mTestView.generateDisplayHash(mPhashAlgorithm, new Rect(), mExecutor,
                mSyncDisplayHashResultCallback);

        int errorCode = mSyncDisplayHashResultCallback.getError();
        assertEquals(DISPLAY_HASH_ERROR_INVALID_BOUNDS, errorCode);
    }

    @Test
    public void testGenerateAndVerifyDisplayHash_BoundsBiggerThanView() {
        setupChildView();

        Rect bounds = new Rect(0, 0, mTestViewSize.x + 100, mTestViewSize.y + 100);

        DisplayHash displayHash = generateDisplayHash(new Rect(bounds));

        VerifiedDisplayHash verifiedDisplayHash = mDisplayHashManager.verifyDisplayHash(
                displayHash);
        assertNotNull(verifiedDisplayHash);
        assertEquals(mTestViewSize.x, verifiedDisplayHash.getBoundsInWindow().width());
        assertEquals(mTestViewSize.y, verifiedDisplayHash.getBoundsInWindow().height());
    }

    @Test
    public void testGenerateDisplayHash_BoundsOutOfView() {
        setupChildView();

        Rect bounds = new Rect(mTestViewSize.x + 1, mTestViewSize.y + 1, mTestViewSize.x + 100,
                mTestViewSize.y + 100);

        mTestView.generateDisplayHash(mPhashAlgorithm, new Rect(bounds),
                mExecutor, mSyncDisplayHashResultCallback);
        int errorCode = mSyncDisplayHashResultCallback.getError();
        assertEquals(DISPLAY_HASH_ERROR_NOT_VISIBLE_ON_SCREEN, errorCode);
    }

    @Test
    public void testGenerateDisplayHash_ViewOffscreen() {
        final CountDownLatch viewLayoutLatch = new CountDownLatch(2);
        mInstrumentation.runOnMainSync(() -> {
            final RelativeLayout.LayoutParams p = new RelativeLayout.LayoutParams(mTestViewSize.x,
                    mTestViewSize.y);
            mTestView = new View(mActivity);
            mTestView.setBackgroundColor(Color.BLUE);
            mTestView.setX(-mTestViewSize.x);

            ViewTreeObserver viewTreeObserver = mTestView.getViewTreeObserver();
            viewTreeObserver.addOnGlobalLayoutListener(viewLayoutLatch::countDown);
            viewTreeObserver.registerFrameCommitCallback(viewLayoutLatch::countDown);

            mMainView.addView(mTestView, p);
            mMainView.invalidate();
        });
        mInstrumentation.waitForIdleSync();
        try {
            viewLayoutLatch.await(5, TimeUnit.SECONDS);
            Thread.sleep(SLEEP_TIME_MS);
        } catch (InterruptedException e) {
        }

        mTestView.generateDisplayHash(mPhashAlgorithm, null, mExecutor,
                mSyncDisplayHashResultCallback);

        int errorCode = mSyncDisplayHashResultCallback.getError();
        assertEquals(DISPLAY_HASH_ERROR_NOT_VISIBLE_ON_SCREEN, errorCode);
    }

    @Test
    public void testGenerateDisplayHash_WindowOffscreen() {
        final WindowManager wm = mActivity.getWindowManager();
        final WindowManager.LayoutParams windowParams = new WindowManager.LayoutParams();

        final CountDownLatch viewLayoutLatch = new CountDownLatch(2);
        mInstrumentation.runOnMainSync(() -> {
            mMainView = new RelativeLayout(mActivity);
            windowParams.width = mTestViewSize.x;
            windowParams.height = mTestViewSize.y;
            windowParams.gravity = Gravity.LEFT | Gravity.TOP;
            windowParams.flags = FLAG_LAYOUT_NO_LIMITS;
            mActivity.addWindow(mMainView, windowParams);

            final RelativeLayout.LayoutParams p = new RelativeLayout.LayoutParams(mTestViewSize.x,
                    mTestViewSize.y);
            mTestView = new View(mActivity);
            mTestView.setBackgroundColor(Color.BLUE);

            ViewTreeObserver viewTreeObserver = mTestView.getViewTreeObserver();
            viewTreeObserver.addOnGlobalLayoutListener(viewLayoutLatch::countDown);
            viewTreeObserver.registerFrameCommitCallback(viewLayoutLatch::countDown);

            mMainView.addView(mTestView, p);
        });
        mInstrumentation.waitForIdleSync();
        try {
            viewLayoutLatch.await(5, TimeUnit.SECONDS);
            Thread.sleep(SLEEP_TIME_MS);
        } catch (InterruptedException e) {
        }

        generateDisplayHash(null);

        mInstrumentation.runOnMainSync(() -> {
            int[] mainViewLocationOnScreen = new int[2];
            mMainView.getLocationOnScreen(mainViewLocationOnScreen);

            windowParams.x = -mTestViewSize.x - mainViewLocationOnScreen[0];
            wm.updateViewLayout(mMainView, windowParams);
        });
        mInstrumentation.waitForIdleSync();

        mSyncDisplayHashResultCallback.reset();
        mTestView.generateDisplayHash(mPhashAlgorithm, null, mExecutor,
                mSyncDisplayHashResultCallback);

        int errorCode = mSyncDisplayHashResultCallback.getError();
        assertEquals(DISPLAY_HASH_ERROR_NOT_VISIBLE_ON_SCREEN, errorCode);
    }

    @Test
    public void testGenerateDisplayHash_InvalidHashAlgorithm() {
        setupChildView();

        mTestView.generateDisplayHash("fake hash", null, mExecutor,
                mSyncDisplayHashResultCallback);
        int errorCode = mSyncDisplayHashResultCallback.getError();
        assertEquals(DISPLAY_HASH_ERROR_INVALID_HASH_ALGORITHM, errorCode);
    }

    @Test
    public void testVerifyDisplayHash_ValidDisplayHash() {
        setupChildView();

        DisplayHash displayHash = generateDisplayHash(null);
        VerifiedDisplayHash verifiedDisplayHash = mDisplayHashManager.verifyDisplayHash(
                displayHash);

        assertNotNull(verifiedDisplayHash);
        assertEquals(displayHash.getTimeMillis(), verifiedDisplayHash.getTimeMillis());
        assertEquals(displayHash.getBoundsInWindow(), verifiedDisplayHash.getBoundsInWindow());
        assertEquals(displayHash.getHashAlgorithm(), verifiedDisplayHash.getHashAlgorithm());
        assertArrayEquals(displayHash.getImageHash(), verifiedDisplayHash.getImageHash());
    }

    @Test
    public void testVerifyDisplayHash_InvalidDisplayHash() {
        setupChildView();

        DisplayHash displayHash = generateDisplayHash(null);
        DisplayHash fakeDisplayHash = new DisplayHash(
                displayHash.getTimeMillis(), displayHash.getBoundsInWindow(),
                displayHash.getHashAlgorithm(), new byte[32], displayHash.getHmac());
        VerifiedDisplayHash verifiedDisplayHash = mDisplayHashManager.verifyDisplayHash(
                fakeDisplayHash);

        assertNull(verifiedDisplayHash);
    }

    @Test
    public void testVerifiedDisplayHash() {
        long timeMillis = 1000;
        Rect boundsInWindow = new Rect(0, 0, 50, 100);
        String hashAlgorithm = "hashAlgorithm";
        byte[] imageHash = new byte[]{2, 4, 1, 5, 6, 2};
        VerifiedDisplayHash verifiedDisplayHash = new VerifiedDisplayHash(timeMillis,
                boundsInWindow, hashAlgorithm, imageHash);

        assertEquals(timeMillis, verifiedDisplayHash.getTimeMillis());
        assertEquals(boundsInWindow, verifiedDisplayHash.getBoundsInWindow());
        assertEquals(hashAlgorithm, verifiedDisplayHash.getHashAlgorithm());
        assertArrayEquals(imageHash, verifiedDisplayHash.getImageHash());
    }

    @Test
    public void testGenerateDisplayHash_Throttle() {
        SystemUtil.runWithShellPermissionIdentity(
                () -> mDisplayHashManager.setDisplayHashThrottlingEnabled(true));

        setupChildView();

        mTestView.generateDisplayHash(mPhashAlgorithm, null, mExecutor,
                mSyncDisplayHashResultCallback);
        mSyncDisplayHashResultCallback.getDisplayHash();
        mSyncDisplayHashResultCallback.reset();
        // Generate a second display hash right away.
        mTestView.generateDisplayHash(mPhashAlgorithm, null, mExecutor,
                mSyncDisplayHashResultCallback);
        int errorCode = mSyncDisplayHashResultCallback.getError();
        assertEquals(DISPLAY_HASH_ERROR_TOO_MANY_REQUESTS, errorCode);
    }

    @Test
    public void testGenerateAndVerifyDisplayHash_MultiColor() {
        final CountDownLatch viewLayoutLatch = new CountDownLatch(2);
        mInstrumentation.runOnMainSync(() -> {
            final RelativeLayout.LayoutParams p = new RelativeLayout.LayoutParams(mTestViewSize.x,
                    mTestViewSize.y);
            LinearLayout linearLayout = new LinearLayout(mActivity);
            linearLayout.setOrientation(VERTICAL);
            LinearLayout.LayoutParams blueParams = new LinearLayout.LayoutParams(mTestViewSize.x,
                    mTestViewSize.y / 2);
            View blueView = new View(mActivity);
            blueView.setBackgroundColor(Color.BLUE);
            LinearLayout.LayoutParams redParams = new LinearLayout.LayoutParams(mTestViewSize.x,
                    mTestViewSize.y / 2);
            View redView = new View(mActivity);
            redView.setBackgroundColor(Color.RED);

            linearLayout.addView(blueView, blueParams);
            linearLayout.addView(redView, redParams);
            mTestView = linearLayout;

            ViewTreeObserver viewTreeObserver = mTestView.getViewTreeObserver();
            viewTreeObserver.addOnGlobalLayoutListener(viewLayoutLatch::countDown);
            viewTreeObserver.registerFrameCommitCallback(viewLayoutLatch::countDown);

            mMainView.addView(mTestView, p);
            mMainView.invalidate();
        });
        mInstrumentation.waitForIdleSync();
        try {
            viewLayoutLatch.await(5, TimeUnit.SECONDS);
            Thread.sleep(SLEEP_TIME_MS);
        } catch (InterruptedException e) {
        }

        byte[] expectedImageHash = new byte[]{-1, -1, 127, -1, -1, -1, 127, 127};

        DisplayHash displayHash = generateDisplayHash(null);
        VerifiedDisplayHash verifiedDisplayHash = mDisplayHashManager.verifyDisplayHash(
                displayHash);
        assertNotNull(verifiedDisplayHash);

        assertEquals(mTestViewSize.x, verifiedDisplayHash.getBoundsInWindow().width());
        assertEquals(mTestViewSize.y, verifiedDisplayHash.getBoundsInWindow().height());
        assertArrayEquals(expectedImageHash, verifiedDisplayHash.getImageHash());
    }

    private DisplayHash generateDisplayHash(Rect bounds) {
        mTestView.generateDisplayHash(mPhashAlgorithm, bounds, mExecutor,
                mSyncDisplayHashResultCallback);
        DisplayHash displayHash = mSyncDisplayHashResultCallback.getDisplayHash();

        assertNotNull(displayHash);
        return displayHash;
    }

    private void setupChildView() {
        final CountDownLatch viewLayoutLatch = new CountDownLatch(2);
        mInstrumentation.runOnMainSync(() -> {
            final RelativeLayout.LayoutParams p = new RelativeLayout.LayoutParams(mTestViewSize.x,
                    mTestViewSize.y);
            mTestView = new View(mActivity);
            mTestView.setBackgroundColor(Color.BLUE);
            ViewTreeObserver viewTreeObserver = mTestView.getViewTreeObserver();
            viewTreeObserver.addOnGlobalLayoutListener(viewLayoutLatch::countDown);
            viewTreeObserver.registerFrameCommitCallback(viewLayoutLatch::countDown);
            mMainView.addView(mTestView, p);
            mMainView.invalidate();
        });
        mInstrumentation.waitForIdleSync();
        try {
            viewLayoutLatch.await(5, TimeUnit.SECONDS);
            Thread.sleep(SLEEP_TIME_MS);
        } catch (InterruptedException e) {
        }
    }

    public static class TestActivity extends Activity {
        private final ArrayList<View> mViews = new ArrayList<>();

        @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
        }

        void addWindow(View view, WindowManager.LayoutParams attrs) {
            getWindowManager().addView(view, attrs);
            mViews.add(view);
        }

        void removeAllWindows() {
            for (View view : mViews) {
                getWindowManager().removeViewImmediate(view);
            }
            mViews.clear();
        }

        @Override
        protected void onPause() {
            super.onPause();
            removeAllWindows();
        }
    }

    private static class SyncDisplayHashResultCallback implements DisplayHashResultCallback {
        private static final int SCREENSHOT_WAIT_TIME_S = 1;
        private DisplayHash mDisplayHash;
        private int mError;
        private CountDownLatch mCountDownLatch = new CountDownLatch(1);

        public void reset() {
            mCountDownLatch = new CountDownLatch(1);
        }

        public DisplayHash getDisplayHash() {
            try {
                mCountDownLatch.await(SCREENSHOT_WAIT_TIME_S, TimeUnit.SECONDS);
            } catch (Exception e) {
            }
            return mDisplayHash;
        }

        public int getError() {
            try {
                mCountDownLatch.await(SCREENSHOT_WAIT_TIME_S, TimeUnit.SECONDS);
            } catch (Exception e) {
            }
            return mError;
        }

        @Override
        public void onDisplayHashResult(@NonNull DisplayHash displayHash) {
            mDisplayHash = displayHash;
            mCountDownLatch.countDown();
        }

        @Override
        public void onDisplayHashError(int errorCode) {
            mError = errorCode;
            mCountDownLatch.countDown();
        }
    }
}

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

package android.server.wm.jetpack.utils;

import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.getActivityBounds;
import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.getMaximumActivityBounds;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;
import static org.junit.Assume.assumeFalse;
import static org.junit.Assume.assumeTrue;

import android.app.Activity;
import android.graphics.Rect;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.window.extensions.WindowExtensions;
import androidx.window.extensions.WindowExtensionsProvider;
import androidx.window.extensions.layout.DisplayFeature;
import androidx.window.extensions.layout.FoldingFeature;
import androidx.window.extensions.layout.WindowLayoutComponent;
import androidx.window.extensions.layout.WindowLayoutInfo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeoutException;
import java.util.stream.Collectors;

/**
 * Utility class for extensions tests, providing methods for checking if a device supports
 * extensions, retrieving and validating the extension version, and getting the instance of
 * {@link WindowExtensions}.
 */
public class ExtensionUtil {

    private static final String EXTENSION_TAG = "Extension";

    public static final Version MINIMUM_EXTENSION_VERSION = new Version(1, 0, 0, "");

    @NonNull
    public static Version getExtensionVersion() {
        try {
            WindowExtensions extensions = getWindowExtensions();
            if (extensions != null) {
                return new Version(extensions.getVendorApiLevel() /* major */, 0 /* minor */,
                        0 /* patch */, "" /* description */);
            }
        } catch (NoClassDefFoundError e) {
            Log.d(EXTENSION_TAG, "Extension version not found");
        } catch (UnsupportedOperationException e) {
            Log.d(EXTENSION_TAG, "Stub Extension");
        }
        return Version.UNKNOWN;
    }

    public static boolean isExtensionVersionValid() {
        final Version version = getExtensionVersion();
        // Check that the extension version on the device is at least the minimum valid version.
        return version.compareTo(MINIMUM_EXTENSION_VERSION) >= 0;
    }

    @Nullable
    public static WindowExtensions getWindowExtensions() {
        try {
            return WindowExtensionsProvider.getWindowExtensions();
        } catch (NoClassDefFoundError e) {
            Log.d(EXTENSION_TAG, "Extension implementation not found");
        } catch (UnsupportedOperationException e) {
            Log.d(EXTENSION_TAG, "Stub Extension");
        }
        return null;
    }

    public static void assumeExtensionSupportedDevice() {
        final boolean extensionNotNull = getWindowExtensions() != null;
        assumeTrue("Device does not support extensions", extensionNotNull);
        // If extensions are on the device, make sure that the version is valid.
        assertTrue("Extension version is invalid, must be at least "
                + MINIMUM_EXTENSION_VERSION.toString(), isExtensionVersionValid());
    }

    @Nullable
    public static WindowLayoutComponent getExtensionWindowLayoutComponent() {
        WindowExtensions extension = getWindowExtensions();
        if (extension == null) {
            return null;
        }
        return extension.getWindowLayoutComponent();
    }

    @Nullable
    public static WindowLayoutInfo getExtensionWindowLayoutInfo(Activity activity)
            throws ExecutionException, InterruptedException, TimeoutException {
        WindowLayoutComponent windowLayoutComponent = getExtensionWindowLayoutComponent();
        if (windowLayoutComponent == null) {
            return null;
        }
        TestValueCountConsumer<WindowLayoutInfo> windowLayoutInfoConsumer =
                new TestValueCountConsumer<>();
        windowLayoutComponent.addWindowLayoutInfoListener(activity, windowLayoutInfoConsumer);
        return windowLayoutInfoConsumer.waitAndGet();
    }

    @NonNull
    public static int[] getExtensionDisplayFeatureTypes(Activity activity)
            throws ExecutionException, InterruptedException, TimeoutException {
        WindowLayoutInfo windowLayoutInfo = getExtensionWindowLayoutInfo(activity);
        if (windowLayoutInfo == null) {
            return new int[0];
        }
        List<DisplayFeature> displayFeatureList = windowLayoutInfo.getDisplayFeatures();
        return displayFeatureList
                .stream()
                .filter(d -> d instanceof FoldingFeature)
                .map(d -> ((FoldingFeature) d).getType())
                .mapToInt(i -> i.intValue())
                .toArray();
    }

    /**
     * Returns whether the device reports at least one display feature.
     */
    public static void assumeHasDisplayFeatures(WindowLayoutInfo windowLayoutInfo) {
        // If WindowLayoutComponent is implemented, then WindowLayoutInfo and the list of display
        // features cannot be null. However the list can be empty if the device does not report
        // any display features.
        assertNotNull(windowLayoutInfo);
        assertNotNull(windowLayoutInfo.getDisplayFeatures());
        assumeFalse(windowLayoutInfo.getDisplayFeatures().isEmpty());
    }

    /**
     * Checks that display features are consistent across portrait and landscape orientations.
     * It is possible for the display features to be different between portrait and landscape
     * orientations because only display features within the activity bounds are provided to the
     * activity and the activity may be letterboxed if orientation requests are ignored. So, only
     * check that display features that are within both portrait and landscape activity bounds
     * are consistent. To be consistent, the feature bounds must be the same (potentially rotated if
     * orientation requests are respected) and their type and state must be the same.
     */
    public static void assertEqualWindowLayoutInfo(
            @NonNull WindowLayoutInfo portraitWindowLayoutInfo,
            @NonNull WindowLayoutInfo landscapeWindowLayoutInfo,
            @NonNull Rect portraitBounds, @NonNull Rect landscapeBounds,
            boolean doesDisplayRotateForOrientation) {
        // Compute the portrait and landscape features that are within both the portrait and
        // landscape activity bounds.
        final List<DisplayFeature> portraitFeaturesWithinBoth = getMutualDisplayFeatures(
                portraitWindowLayoutInfo, portraitBounds, landscapeBounds);
        List<DisplayFeature> landscapeFeaturesWithinBoth = getMutualDisplayFeatures(
                landscapeWindowLayoutInfo, landscapeBounds, portraitBounds);
        assertEquals(portraitFeaturesWithinBoth.size(), landscapeFeaturesWithinBoth.size());
        final int nFeatures = portraitFeaturesWithinBoth.size();
        if (nFeatures == 0) {
            return;
        }

        // If the display rotates to respect orientation, then to make the landscape display
        // features comparable to the portrait display features rotate the landscape features.
        if (doesDisplayRotateForOrientation) {
            landscapeFeaturesWithinBoth = landscapeFeaturesWithinBoth
                    .stream()
                    .map(d -> {
                        if (!(d instanceof FoldingFeature)) {
                            return d;
                        }
                        final FoldingFeature f = (FoldingFeature) d;
                        final Rect oldBounds = d.getBounds();
                        // Rotate the bounds by 90 degrees
                        final Rect newBounds = new Rect(oldBounds.top, oldBounds.left,
                                oldBounds.bottom, oldBounds.right);
                        return new FoldingFeature(newBounds, f.getType(), f.getState());
                    })
                    .collect(Collectors.toList());
        }

        // Check that the list of features are the same
        final boolean[] portraitFeatureMatched = new boolean[nFeatures];
        final boolean[] landscapeFeatureMatched = new boolean[nFeatures];
        for (int portraitIndex = 0; portraitIndex < nFeatures; portraitIndex++) {
            if (portraitFeatureMatched[portraitIndex]) {
                // A match has already been found for this portrait display feature
                continue;
            }
            final DisplayFeature portraitDisplayFeature = portraitFeaturesWithinBoth
                    .get(portraitIndex);
            for (int landscapeIndex = 0; landscapeIndex < nFeatures; landscapeIndex++) {
                if (landscapeFeatureMatched[landscapeIndex]) {
                    // A match has already been found for this landscape display feature
                    continue;
                }
                final DisplayFeature landscapeDisplayFeature = landscapeFeaturesWithinBoth
                        .get(landscapeIndex);
                // Only continue comparing if both display features are the same type of display
                // feature (e.g. FoldingFeature) and they have the same bounds
                if (!portraitDisplayFeature.getClass().equals(landscapeDisplayFeature.getClass())
                        || !portraitDisplayFeature.getBounds().equals(
                                landscapeDisplayFeature.getBounds())) {
                    continue;
                }
                // If both are folding features, then only continue comparing if the type and state
                // match
                if (portraitDisplayFeature instanceof FoldingFeature) {
                    FoldingFeature portraitFoldingFeature = (FoldingFeature) portraitDisplayFeature;
                    FoldingFeature landscapeFoldingFeature =
                            (FoldingFeature) landscapeDisplayFeature;
                    if (portraitFoldingFeature.getType() != landscapeFoldingFeature.getType()
                            || portraitFoldingFeature.getState()
                            != landscapeFoldingFeature.getState()) {
                        continue;
                    }
                }
                // The display features match
                portraitFeatureMatched[portraitIndex] = true;
                landscapeFeatureMatched[landscapeIndex] = true;
            }
        }

        // Check that a match was found for each display feature
        for (int i = 0; i < nFeatures; i++) {
            assertTrue(portraitFeatureMatched[i] && landscapeFeatureMatched[i]);
        }
    }

    /**
     * Returns the subset of {@param windowLayoutInfo} display features that are shared by the
     * activity bounds in the current orientation and the activity bounds in the other orientation.
     */
    private static List<DisplayFeature> getMutualDisplayFeatures(
            @NonNull WindowLayoutInfo windowLayoutInfo, @NonNull Rect currentOrientationBounds,
            @NonNull Rect otherOrientationBounds) {
        return windowLayoutInfo
                .getDisplayFeatures()
                .stream()
                .map(d -> {
                    if (!(d instanceof FoldingFeature)) {
                        return d;
                    }
                    // The display features are positioned relative to the activity bounds, so
                    // re-position them absolutely within the task.
                    final FoldingFeature f = (FoldingFeature) d;
                    final Rect r = f.getBounds();
                    r.offset(currentOrientationBounds.left, currentOrientationBounds.top);
                    return new FoldingFeature(r, f.getType(), f.getState());
                })
                .filter(d -> otherOrientationBounds.contains(d.getBounds()))
                .collect(Collectors.toList());
    }
}

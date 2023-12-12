/*
 * Copyright (C) 2011 The Android Open Source Project
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

package com.android.cts.verifier;

import static com.android.cts.verifier.TestListActivity.sCurrentDisplayMode;
import static com.android.cts.verifier.TestListActivity.sInitialLaunch;

import android.content.Context;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.content.res.Resources;
import android.os.Bundle;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.widget.ListView;

import com.android.cts.verifier.TestListActivity.DisplayMode;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * {@link TestListAdapter} that populates the {@link TestListActivity}'s {@link ListView} by
 * reading data from the CTS Verifier's AndroidManifest.xml.
 * <p>
 * Making a new test activity to appear in the list requires the following steps:
 *
 * <ol>
 *     <li>REQUIRED: Add an activity to the AndroidManifest.xml with an intent filter with a
 *         main action and the MANUAL_TEST category.
 *         <pre>
 *             <intent-filter>
 *                <action android:name="android.intent.action.MAIN" />
 *                <category android:name="android.cts.intent.category.MANUAL_TEST" />
 *             </intent-filter>
 *         </pre>
 *     </li>
 *     <li>REQUIRED: Add a meta data attribute to indicate which display modes of tests the activity
 *         should belong to. "single_display_mode" indicates a test is only needed to run on the
 *         main display mode (i.e. unfolded), and "multi_display_mode" indicates a test is required
 *         to run under both modes (i.e. both folded and unfolded).If you don't add this attribute,
 *         your test will show up in both unfolded and folded modes.
 *         <pre>
 *             <meta-data android:name="display_mode" android:value="multi_display_mode" />
 *         </pre>
 *     </li>
 *     <li>OPTIONAL: Add a meta data attribute to indicate what category of tests the activity
 *         should belong to. If you don't add this attribute, your test will show up in the
 *         "Other" tests category.
 *         <pre>
 *             <meta-data android:name="test_category" android:value="@string/test_category_security" />
 *         </pre>
 *     </li>
 *     <li>OPTIONAL: Add a meta data attribute to indicate whether this test has a parent test.
 *         <pre>
 *             <meta-data android:name="test_parent" android:value="com.android.cts.verifier.bluetooth.BluetoothTestActivity" />
 *         </pre>
 *     </li>
 *     <li>OPTIONAL: Add a meta data attribute to indicate what features are required to run the
 *         test. If the device does not have all of the required features then it will not appear
 *         in the test list. Use a colon (:) to specify multiple required features.
 *         <pre>
 *             <meta-data android:name="test_required_features" android:value="android.hardware.sensor.accelerometer" />
 *         </pre>
 *     </li>
 *     <li>OPTIONAL: Add a meta data attribute to indicate features such that, if any present, the
 *         test gets excluded from being shown. If the device has any of the excluded features then
 *         the test will not appear in the test list. Use a colon (:) to specify multiple features
 *         to exclude for the test. Note that the colon means "or" in this case.
 *         <pre>
 *             <meta-data android:name="test_excluded_features" android:value="android.hardware.type.television" />
 *         </pre>
 *     </li>
 *     <li>OPTIONAL: Add a meta data attribute to indicate features such that, if any present,
 *         the test is applicable to run. If the device has any of the applicable features then
 *         the test will appear in the test list. Use a colon (:) to specify multiple features
 *         <pre>
 *             <meta-data android:name="test_applicable_features" android:value="android.hardware.sensor.compass" />
 *         </pre>
 *     </li>
 *     <li>OPTIONAL: Add a meta data attribute to indicate which intent actions are required to run
 *         the test. If the device does not have activities that handle all those actions, then it
 *         will not appear in the test list. Use a colon (:) to specify multiple required intent actions.
 *         <pre>
 *             <meta-data android:name="test_required_actions" android:value="android.app.action.ADD_DEVICE_ADMIN" />
 *         </pre>
 *     </li>
 *
 * </ol>
 */
public class ManifestTestListAdapter extends TestListAdapter {
    private static final String LOG_TAG = "ManifestTestListAdapter";

    private static final String TEST_CATEGORY_META_DATA = "test_category";

    private static final String TEST_PARENT_META_DATA = "test_parent";

    private static final String TEST_REQUIRED_FEATURES_META_DATA = "test_required_features";

    private static final String TEST_EXCLUDED_FEATURES_META_DATA = "test_excluded_features";

    private static final String TEST_APPLICABLE_FEATURES_META_DATA = "test_applicable_features";

    private static final String TEST_REQUIRED_CONFIG_META_DATA = "test_required_configs";

    private static final String TEST_REQUIRED_ACTIONS_META_DATA = "test_required_actions";

    private static final String TEST_DISPLAY_MODE_META_DATA = "display_mode";

    private static final String CONFIG_NO_EMULATOR = "config_no_emulator";

    private static final String CONFIG_VOICE_CAPABLE = "config_voice_capable";

    private static final String CONFIG_HAS_RECENTS = "config_has_recents";

    private static final String CONFIG_HDMI_SOURCE = "config_hdmi_source";

    private static final String CONFIG_QUICK_SETTINGS_SUPPORTED = "config_quick_settings_supported";

    /** The config to represent that a test is only needed to run in the main display mode
     * (i.e. unfolded) */
    private static final String SINGLE_DISPLAY_MODE = "single_display_mode";

    /** The config to represent that a test is needed to run in the multiple display modes
     * (i.e. both unfolded and folded) */
    private static final String MULTIPLE_DISPLAY_MODE = "multi_display_mode";

    private final HashSet<String> mDisabledTests;

    private Context mContext;

    private String mTestParent;

    public ManifestTestListAdapter(Context context, String testParent, String[] disabledTestArray) {
        super(context);
        mContext = context;
        mTestParent = testParent;
        mDisabledTests = new HashSet<>(disabledTestArray.length);
        for (int i = 0; i < disabledTestArray.length; i++) {
            mDisabledTests.add(disabledTestArray[i]);
        }
    }

    public ManifestTestListAdapter(Context context, String testParent) {
        this(context, testParent, context.getResources().getStringArray(R.array.disabled_tests));
    }

    @Override
    protected List<TestListItem> getRows() {
        List<TestListItem> allRows = new ArrayList<TestListItem>();

        // When launching at the first time or after killing the process, needs to fetch the
        // test items of all display modes as the bases for switching.
        if (mDisplayModesTests.isEmpty()) {
            for (DisplayMode mode : DisplayMode.values()) {
                allRows = getRowsWithDisplayMode(mode.toString());
                mDisplayModesTests.put(mode.toString(), allRows);
            }
        }

        if (!sInitialLaunch) {
            return getRowsWithDisplayMode(sCurrentDisplayMode);
        }
        return allRows;
    }

    /**
     * Gets all rows based on the specific display mode.
     *
     * @param mode Given display mode.
     * @return A list containing all test itmes in the given display mode.
     */
    private List<TestListItem> getRowsWithDisplayMode (String mode) {
        /*
         * 1. Get all the tests belonging to the test parent.
         * 2. Get all the tests keyed by their category.
         * 3. Flatten the tests and categories into one giant list for the list view.
         */
        List<TestListItem> allRows = new ArrayList<TestListItem>();
        List<ResolveInfo> infos = getResolveInfosForParent();
        Map<String, List<TestListItem>> testsByCategory = getTestsByCategory(infos);

        List<String> testCategories = new ArrayList<String>(testsByCategory.keySet());
        Collections.sort(testCategories);
        for (String testCategory : testCategories) {
            List<TestListItem> tests = filterTests(testsByCategory.get(testCategory), mode);
            if (!tests.isEmpty()) {
                allRows.add(TestListItem.newCategory(testCategory));
                Collections.sort(tests, Comparator.comparing(item -> item.title));
                allRows.addAll(tests);
            }
        }
        return allRows;
    }

    List<ResolveInfo> getResolveInfosForParent() {
        Intent mainIntent = new Intent(Intent.ACTION_MAIN);
        mainIntent.addCategory(CATEGORY_MANUAL_TEST);
        mainIntent.setPackage(mContext.getPackageName());

        PackageManager packageManager = mContext.getPackageManager();
        List<ResolveInfo> list = packageManager.queryIntentActivities(mainIntent,
                PackageManager.GET_ACTIVITIES | PackageManager.GET_META_DATA);
        int size = list.size();

        List<ResolveInfo> matchingList = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            ResolveInfo info = list.get(i);
            String parent = getTestParent(info.activityInfo.metaData);
            if ((mTestParent == null && parent == null)
                    || (mTestParent != null && mTestParent.equals(parent))) {
                matchingList.add(info);
            }
        }
        return matchingList;
    }

    Map<String, List<TestListItem>> getTestsByCategory(List<ResolveInfo> list) {
        Map<String, List<TestListItem>> testsByCategory = new HashMap<>();

        int size = list.size();
        for (int i = 0; i < size; i++) {
            ResolveInfo info = list.get(i);
            if (info.activityInfo == null || mDisabledTests.contains(info.activityInfo.name)) {
                Log.w(LOG_TAG, "ignoring disabled test: " + info.activityInfo.name);
                continue;
            }
            String title = getTitle(mContext, info.activityInfo);
            String testName = info.activityInfo.name;
            Intent intent = getActivityIntent(info.activityInfo);
            String[] requiredFeatures = getRequiredFeatures(info.activityInfo.metaData);
            String[] requiredConfigs = getRequiredConfigs(info.activityInfo.metaData);
            String[] requiredActions = getRequiredActions(info.activityInfo.metaData);
            String[] excludedFeatures = getExcludedFeatures(info.activityInfo.metaData);
            String[] applicableFeatures = getApplicableFeatures(info.activityInfo.metaData);
            String displayMode = getDisplayMode(info.activityInfo.metaData);

            TestListItem item = TestListItem.newTest(title, testName, intent, requiredFeatures,
                     requiredConfigs, requiredActions, excludedFeatures, applicableFeatures,
                     displayMode);

            String testCategory = getTestCategory(mContext, info.activityInfo.metaData);
            addTestToCategory(testsByCategory, testCategory, item);
        }

        return testsByCategory;
    }

    static String getTestCategory(Context context, Bundle metaData) {
        String testCategory = null;
        if (metaData != null) {
            testCategory = metaData.getString(TEST_CATEGORY_META_DATA);
        }
        if (testCategory != null) {
            return testCategory;
        } else {
            return context.getString(R.string.test_category_other);
        }
    }

    static String getTestParent(Bundle metaData) {
        return metaData != null ? metaData.getString(TEST_PARENT_META_DATA) : null;
    }

    static String[] getRequiredFeatures(Bundle metaData) {
        if (metaData == null) {
            return null;
        } else {
            String value = metaData.getString(TEST_REQUIRED_FEATURES_META_DATA);
            if (value == null) {
                return null;
            } else {
                return value.split(":");
            }
        }
    }

    static String[] getRequiredActions(Bundle metaData) {
        if (metaData == null) {
            return null;
        } else {
            String value = metaData.getString(TEST_REQUIRED_ACTIONS_META_DATA);
            if (value == null) {
                return null;
            } else {
                return value.split(":");
            }
        }
    }

    static String[] getRequiredConfigs(Bundle metaData) {
        if (metaData == null) {
            return null;
        } else {
            String value = metaData.getString(TEST_REQUIRED_CONFIG_META_DATA);
            if (value == null) {
                return null;
            } else {
                return value.split(":");
            }
        }
    }

    static String[] getExcludedFeatures(Bundle metaData) {
        if (metaData == null) {
            return null;
        } else {
            String value = metaData.getString(TEST_EXCLUDED_FEATURES_META_DATA);
            if (value == null) {
                return null;
            } else {
                return value.split(":");
            }
        }
    }

    static String[] getApplicableFeatures(Bundle metaData) {
        if (metaData == null) {
            return null;
        } else {
            String value = metaData.getString(TEST_APPLICABLE_FEATURES_META_DATA);
            if (value == null) {
                return null;
            } else {
                return value.split(":");
            }
        }
    }

    /**
     * Gets the configuration of the display mode per test. The default value is multi_display_mode.
     *
     * @param metaData Given metadata of the display mode.
     * @return A string representing the display mode of the test.
     */
    static String getDisplayMode(Bundle metaData) {
        if (metaData == null) {
            return MULTIPLE_DISPLAY_MODE;
        }
        String displayMode = metaData.getString(TEST_DISPLAY_MODE_META_DATA);
        return displayMode == null ? MULTIPLE_DISPLAY_MODE : displayMode;
    }

    static String getTitle(Context context, ActivityInfo activityInfo) {
        if (activityInfo.labelRes != 0) {
            return context.getString(activityInfo.labelRes);
        } else {
            return activityInfo.name;
        }
    }

    static Intent getActivityIntent(ActivityInfo activityInfo) {
        Intent intent = new Intent();
        intent.setClassName(activityInfo.packageName, activityInfo.name);
        return intent;
    }

    static void addTestToCategory(Map<String, List<TestListItem>> testsByCategory,
            String testCategory, TestListItem item) {
        List<TestListItem> tests;
        if (testsByCategory.containsKey(testCategory)) {
            tests = testsByCategory.get(testCategory);
        } else {
            tests = new ArrayList<TestListItem>();
        }
        testsByCategory.put(testCategory, tests);
        tests.add(item);
    }

    private boolean hasAnyFeature(String[] features) {
        if (features != null) {
            PackageManager packageManager = mContext.getPackageManager();
            for (String feature : features) {
                if (packageManager.hasSystemFeature(feature)) {
                    return true;
                }
            }
            Log.v(LOG_TAG, "Missing features " + Arrays.toString(features));
        }
        return false;
    }

    private boolean hasAllFeatures(String[] features) {
        if (features != null) {
            PackageManager packageManager = mContext.getPackageManager();
            for (String feature : features) {
                if (!packageManager.hasSystemFeature(feature)) {
                    Log.v(LOG_TAG, "Missing feature " + feature);
                    return false;
                }
            }
        }
        return true;
    }

    private boolean hasAllActions(String[] actions) {
        if (actions != null) {
            PackageManager packageManager = mContext.getPackageManager();
            for (String action : actions) {
                Intent intent = new Intent(action);
                if (packageManager.queryIntentActivities(intent, /* flags= */ 0).isEmpty()) {
                    Log.v(LOG_TAG, "Missing action " + action);
                    return false;
                }
            }
        }
        return true;
    }

    private boolean matchAllConfigs(String[] configs) {
        if (configs != null) {
            for (String config : configs) {
                switch (config) {
                    case CONFIG_NO_EMULATOR:
                        try {
                            Method getStringMethod = ClassLoader.getSystemClassLoader()
                                .loadClass("android.os.SystemProperties")
                                .getMethod("get", String.class);
                            String emulatorKernel = (String) getStringMethod.invoke("0",
                                    "ro.boot.qemu");
                            if (emulatorKernel.equals("1")) {
                                return false;
                            }
                        } catch (Exception e) {
                            Log.e(LOG_TAG, "Exception while checking for emulator support.", e);
                        }
                        break;
                    case CONFIG_VOICE_CAPABLE:
                        TelephonyManager telephonyManager = mContext.getSystemService(
                                TelephonyManager.class);
                        if (!telephonyManager.isVoiceCapable()) {
                            return false;
                        }
                        break;
                    case CONFIG_HAS_RECENTS:
                        if (!getSystemResourceFlag("config_hasRecents")) {
                            return false;
                        }
                        break;
                    case CONFIG_HDMI_SOURCE:
                        final int DEVICE_TYPE_HDMI_SOURCE = 4;
                        try {
                            if (!getHdmiDeviceType().contains(DEVICE_TYPE_HDMI_SOURCE)) {
                                return false;
                            }
                        } catch (Exception exception) {
                            Log.e(
                                    LOG_TAG,
                                    "Exception while looking up HDMI device type.",
                                    exception);
                        }
                        break;
                    case CONFIG_QUICK_SETTINGS_SUPPORTED:
                        if (!getSystemResourceFlag("config_quickSettingsSupported")) {
                            return false;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        return true;
    }

    /**
     * Check if the test should be ran by the given display mode.
     *
     * @param mode Configs of the display mode.
     * @param currentMode Given display mode.
     * @return True if the given display mode matches the configs, otherwise, return false;
     */
    private boolean matchDisplayMode(String mode, String currentMode) {
        if (mode == null) {
            return false;
        }
        switch (mode) {
            case SINGLE_DISPLAY_MODE:
                return currentMode.equals(DisplayMode.UNFOLDED.toString());
            case MULTIPLE_DISPLAY_MODE:
                return true;
            default:
                return false;
        }
    }

    private boolean getSystemResourceFlag(String key) {
        final Resources systemRes = mContext.getResources().getSystem();
        final int id = systemRes.getIdentifier(key, "bool", "android");
        if (id == Resources.ID_NULL) {
            // The flag being queried should exist in
            // frameworks/base/core/res/res/values/config.xml.
            throw new RuntimeException("System resource flag " + key + " not found");
        }
        return systemRes.getBoolean(id);
    }

    private static List<Integer> getHdmiDeviceType()
            throws InvocationTargetException, IllegalAccessException, ClassNotFoundException,
                    NoSuchMethodException {
        Method getStringMethod =
                ClassLoader.getSystemClassLoader()
                        .loadClass("android.os.SystemProperties")
                        .getMethod("get", String.class);
        String deviceTypesStr = (String) getStringMethod.invoke(null, "ro.hdmi.device_type");
        if (deviceTypesStr.equals("")) {
            return new ArrayList<>();
        }
        return Arrays.stream(deviceTypesStr.split(","))
                .map(Integer::parseInt)
                .collect(Collectors.toList());
    }

    List<TestListItem> filterTests(List<TestListItem> tests, String mode) {
        List<TestListItem> filteredTests = new ArrayList<>();
        for (TestListItem test : tests) {
            if (!hasAnyFeature(test.excludedFeatures) && hasAllFeatures(test.requiredFeatures)
                    && hasAllActions(test.requiredActions)
                    && matchAllConfigs(test.requiredConfigs)
                    && matchDisplayMode(test.displayMode, mode)) {
                if (test.applicableFeatures == null || hasAnyFeature(test.applicableFeatures)) {
                    // Add suffix in test name if the test is in the folded mode.
                    test.testName = setTestNameSuffix(mode, test.testName);
                    filteredTests.add(test);
                } else {
                    Log.d(LOG_TAG, "Skipping " + test.testName + " due to metadata filtering");
                }
            } else {
                Log.d(LOG_TAG, "Skipping " + test.testName + " due to metadata filtering");
            }
        }
        return filteredTests;
    }

    @Override
    public int getCount() {
        if (!sInitialLaunch && mTestParent == null) {
            return mDisplayModesTests.getOrDefault(sCurrentDisplayMode, new ArrayList<>()).size();
        }
        return super.getCount();
    }

    @Override
    public TestListItem getItem(int position) {
        if (mTestParent == null) {
            return mDisplayModesTests.get(sCurrentDisplayMode).get(position);
        }
        return super.getItem(position);
    }

    @Override
    public void loadTestResults() {
        if (mTestParent == null) {
            new RefreshTestResultsTask(true).execute();
        } else {
            super.loadTestResults();
        }
    }
}

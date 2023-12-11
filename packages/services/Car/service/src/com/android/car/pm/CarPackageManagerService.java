/*
 * Copyright (C) 2015 The Android Open Source Project
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

package com.android.car.pm;

import static android.Manifest.permission.QUERY_ALL_PACKAGES;

import android.annotation.NonNull;
import android.annotation.Nullable;
import android.annotation.UserIdInt;
import android.app.ActivityManager;
import android.app.ActivityTaskManager.RootTaskInfo;
import android.app.PendingIntent;
import android.car.Car;
import android.car.content.pm.AppBlockingPackageInfo;
import android.car.content.pm.CarAppBlockingPolicy;
import android.car.content.pm.CarAppBlockingPolicyService;
import android.car.content.pm.CarPackageManager;
import android.car.content.pm.ICarPackageManager;
import android.car.drivingstate.CarUxRestrictions;
import android.car.drivingstate.ICarUxRestrictionsChangeListener;
import android.car.hardware.power.CarPowerPolicy;
import android.car.hardware.power.CarPowerPolicyFilter;
import android.car.hardware.power.ICarPowerPolicyListener;
import android.car.hardware.power.PowerComponent;
import android.car.user.CarUserManager;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.pm.ResolveInfo;
import android.content.pm.ServiceInfo;
import android.content.pm.Signature;
import android.content.res.Resources;
import android.hardware.display.DisplayManager;
import android.os.Binder;
import android.os.Build;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.IBinder;
import android.os.Looper;
import android.os.Message;
import android.os.ParcelFileDescriptor;
import android.os.Process;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.os.ServiceSpecificException;
import android.os.SystemProperties;
import android.os.UserHandle;
import android.text.TextUtils;
import android.util.ArraySet;
import android.util.IndentingPrintWriter;
import android.util.LocalLog;
import android.util.Log;
import android.util.Pair;
import android.util.Slog;
import android.util.SparseArray;
import android.view.Display;
import android.view.DisplayAddress;

import com.android.car.CarLocalServices;
import com.android.car.CarLog;
import com.android.car.CarServiceBase;
import com.android.car.CarServiceUtils;
import com.android.car.CarUxRestrictionsManagerService;
import com.android.car.R;
import com.android.car.SystemActivityMonitoringService;
import com.android.car.SystemActivityMonitoringService.TopTaskInfoContainer;
import com.android.car.power.CarPowerManagementService;
import com.android.car.user.CarUserService;
import com.android.internal.annotations.GuardedBy;
import com.android.internal.annotations.VisibleForTesting;
import com.android.server.utils.Slogf;

import com.google.android.collect.Sets;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Objects;
import java.util.Set;

public class CarPackageManagerService extends ICarPackageManager.Stub implements CarServiceBase {

    static final boolean DBG = false;

    private static final String TAG = CarLog.tagFor(CarPackageManagerService.class);

    // Delimiters to parse packages and activities in the configuration XML resource.
    private static final String PACKAGE_DELIMITER = ",";
    private static final String PACKAGE_ACTIVITY_DELIMITER = "/";
    private static final int LOG_SIZE = 20;
    private static final String[] WINDOW_DUMP_ARGUMENTS = new String[]{"windows"};

    private static final String PROPERTY_RO_DRIVING_SAFETY_REGION =
            "ro.android.car.drivingsafetyregion";

    private final Context mContext;
    private final SystemActivityMonitoringService mSystemActivityMonitoringService;
    private final PackageManager mPackageManager;
    private final ActivityManager mActivityManager;
    private final DisplayManager mDisplayManager;
    private final IBinder mWindowManagerBinder;

    private final HandlerThread mHandlerThread = CarServiceUtils.getHandlerThread(
            getClass().getSimpleName());
    private final PackageHandler mHandler  = new PackageHandler(mHandlerThread.getLooper(), this);
    private final Object mLock = new Object();

    // For dumpsys logging.
    private final LocalLog mBlockedActivityLogs = new LocalLog(LOG_SIZE);

    // Store the allowlist and blocklist strings from the resource file.
    private String mConfiguredAllowlist;
    private String mConfiguredSystemAllowlist;
    private String mConfiguredBlocklist;
    @GuardedBy("mLock")
    private Map<String, Set<String>> mConfiguredAllowlistMap;
    @GuardedBy("mLock")
    private Map<String, Set<String>> mConfiguredBlocklistMap;

    private final List<String> mAllowedAppInstallSources;

    @GuardedBy("mLock")
    private final SparseArray<ComponentName> mTopActivityWithDialogPerDisplay = new SparseArray<>();

    /**
     * Hold policy set from policy service or client.
     * Key: packageName of policy service
     */
    @GuardedBy("mLock")
    private final HashMap<String, ClientPolicy> mClientPolicies = new HashMap<>();
    @GuardedBy("mLock")
    private HashMap<String, AppBlockingPackageInfoWrapper> mActivityAllowlistMap = new HashMap<>();
    @GuardedBy("mLock")
    private  HashSet<String> mActivityDenylistPackages = new HashSet<String>();

    @GuardedBy("mLock")
    private LinkedList<AppBlockingPolicyProxy> mProxies;

    @GuardedBy("mLock")
    private final LinkedList<CarAppBlockingPolicy> mWaitingPolicies = new LinkedList<>();

    @GuardedBy("mLock")
    private String mCurrentDrivingSafetyRegion = CarPackageManager.DRIVING_SAFETY_REGION_ALL;
    // Package name + '/' + className format
    @GuardedBy("mLock")
    private final ArraySet<String> mTempAllowedActivities = new ArraySet<>();

    private final CarUxRestrictionsManagerService mCarUxRestrictionsService;
    private final boolean mEnableActivityBlocking;

    private final ComponentName mActivityBlockingActivity;
    private final boolean mPreventTemplatedAppsFromShowingDialog;
    private final String mTemplateActivityClassName;

    private final ActivityLaunchListener mActivityLaunchListener = new ActivityLaunchListener();

    // K: (logical) display id of a physical display, V: UXR change listener of this display.
    // For multi-display, monitor UXR change on each display.
    private final SparseArray<UxRestrictionsListener> mUxRestrictionsListeners =
            new SparseArray<>();
    private final VendorServiceController mVendorServiceController;

    // Information related to when the installed packages should be parsed for building a allow and
    // block list
    private final Set<String> mPackageManagerActions = Sets.newArraySet(
            Intent.ACTION_PACKAGE_ADDED,
            Intent.ACTION_PACKAGE_CHANGED,
            Intent.ACTION_PACKAGE_REMOVED,
            Intent.ACTION_PACKAGE_REPLACED);

    private final PackageParsingEventReceiver mPackageParsingEventReceiver =
            new PackageParsingEventReceiver();

    /**
     * Name of blocked activity.
     *
     * @hide
     */
    public static final String BLOCKING_INTENT_EXTRA_BLOCKED_ACTIVITY_NAME = "blocked_activity";
    /**
     * int task id of the blocked task.
     *
     * @hide
     */
    public static final String BLOCKING_INTENT_EXTRA_BLOCKED_TASK_ID = "blocked_task_id";
    /**
     * Name of root activity of blocked task.
     *
     * @hide
     */
    public static final String BLOCKING_INTENT_EXTRA_ROOT_ACTIVITY_NAME = "root_activity_name";
    /**
     * Boolean indicating whether the root activity is distraction-optimized (DO).
     * Blocking screen should show a button to restart the task if {@code true}.
     *
     * @hide
     */
    public static final String BLOCKING_INTENT_EXTRA_IS_ROOT_ACTIVITY_DO = "is_root_activity_do";

    /**
     * int display id of the blocked task.
     *
     * @hide
     */
    public static final String BLOCKING_INTENT_EXTRA_DISPLAY_ID = "display_id";

    private final CarUserManager.UserLifecycleListener mUserLifecycleListener =
            new CarUserManager.UserLifecycleListener() {
                @Override
                public void onEvent(CarUserManager.UserLifecycleEvent event) {
                    if (event.getEventType()
                            == CarUserManager.USER_LIFECYCLE_EVENT_TYPE_SWITCHING) {
                        synchronized (mLock) {
                            resetTempAllowedActivitiesLocked();
                        }
                    }
                }
            };

    private final ICarPowerPolicyListener mDisplayPowerPolicyListener =
            new ICarPowerPolicyListener.Stub() {
                @Override
                public void onPolicyChanged(CarPowerPolicy policy,
                        CarPowerPolicy accumulatedPolicy) {
                    if (!policy.isComponentEnabled(PowerComponent.DISPLAY)) {
                        synchronized (mLock) {
                            resetTempAllowedActivitiesLocked();
                        }
                    }
                }
            };

    public CarPackageManagerService(Context context,
            CarUxRestrictionsManagerService uxRestrictionsService,
            SystemActivityMonitoringService systemActivityMonitoringService) {
        mContext = context;
        mCarUxRestrictionsService = uxRestrictionsService;
        mSystemActivityMonitoringService = systemActivityMonitoringService;
        mPackageManager = mContext.getPackageManager();
        mActivityManager = mContext.getSystemService(ActivityManager.class);
        mDisplayManager = mContext.getSystemService(DisplayManager.class);
        mWindowManagerBinder = ServiceManager.getService(Context.WINDOW_SERVICE);
        Resources res = context.getResources();
        mEnableActivityBlocking = res.getBoolean(R.bool.enableActivityBlockingForSafety);
        String blockingActivity = res.getString(R.string.activityBlockingActivity);
        mActivityBlockingActivity = ComponentName.unflattenFromString(blockingActivity);
        if (mEnableActivityBlocking && mActivityBlockingActivity == null) {
            Slogf.wtf(TAG, "mActivityBlockingActivity can't be null when enabled");
        }
        mAllowedAppInstallSources = Arrays.asList(
                res.getStringArray(R.array.allowedAppInstallSources));
        mVendorServiceController = new VendorServiceController(
                mContext, mHandler.getLooper());
        mPreventTemplatedAppsFromShowingDialog =
                res.getBoolean(R.bool.config_preventTemplatedAppsFromShowingDialog);
        mTemplateActivityClassName = res.getString(R.string.config_template_activity_class_name);
    }


    @Override
    public void setAppBlockingPolicy(String packageName, CarAppBlockingPolicy policy, int flags) {
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Slog.d(TAG, "policy setting from binder call, client:" + packageName);
        }
        doSetAppBlockingPolicy(packageName, policy, flags);
    }

    /**
     * Restarts the requested task. If task with {@code taskId} does not exist, do nothing.
     */
    @Override
    public void restartTask(int taskId) {
        if (mContext.checkCallingOrSelfPermission(android.Manifest.permission.REAL_GET_TASKS)
                != PackageManager.PERMISSION_GRANTED) {
            throw new SecurityException(
                    "requires permission " + android.Manifest.permission.REAL_GET_TASKS);
        }
        mSystemActivityMonitoringService.restartTask(taskId);
    }

    @Override
    public String getCurrentDrivingSafetyRegion() {
        assertAppBlockingOrDrivingStatePermission();
        synchronized (mLock) {
            return mCurrentDrivingSafetyRegion;
        }
    }

    private String getComponentNameString(String packageName, String className) {
        return packageName + '/' + className;
    }

    @Override
    public void controlOneTimeActivityBlockingBypassingAsUser(String packageName,
            String activityClassName, boolean bypass, @UserIdInt int userId) {
        assertAppBlockingPermission();
        if (!callerCanQueryPackage(packageName)) {
            throw new SecurityException("cannot query other package");
        }
        try {
            // Read this to check the validity of pkg / activity name. Not checking this can allow
            // bad apps to be allowed later.
            CarAppMetadataReader.getSupportedDrivingSafetyRegionsForActivityAsUser(mContext,
                    packageName, activityClassName, userId);
        } catch (NameNotFoundException e) {
            throw new ServiceSpecificException(CarPackageManager.ERROR_CODE_NO_PACKAGE,
                    e.getMessage());
        }
        String componentName = getComponentNameString(packageName, activityClassName);
        synchronized (mLock) {
            if (bypass) {
                mTempAllowedActivities.add(componentName);
            } else {
                mTempAllowedActivities.remove(componentName);
            }
        }
        if (!bypass) { // block top activities if bypassing is disabled.
            blockTopActivitiesIfNecessary();
        }
    }

    @GuardedBy("mLock")
    private void resetTempAllowedActivitiesLocked() {
        mTempAllowedActivities.clear();
    }

    @Override
    public List<String> getSupportedDrivingSafetyRegionsForActivityAsUser(String packageName,
            String activityClassName, @UserIdInt int userId) {
        assertAppBlockingOrDrivingStatePermission();
        if (!callerCanQueryPackage(packageName)) {
            throw new SecurityException("cannot query other package");
        }
        long token = Binder.clearCallingIdentity();
        try {
            return CarAppMetadataReader.getSupportedDrivingSafetyRegionsForActivityAsUser(mContext,
                    packageName, activityClassName, userId);
        } catch (NameNotFoundException e) {
            throw new ServiceSpecificException(CarPackageManager.ERROR_CODE_NO_PACKAGE,
                    e.getMessage());
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    private void assertAppBlockingOrDrivingStatePermission() {
        if (mContext.checkCallingOrSelfPermission(Car.PERMISSION_CONTROL_APP_BLOCKING)
                != PackageManager.PERMISSION_GRANTED && mContext.checkCallingOrSelfPermission(
                Car.PERMISSION_CAR_DRIVING_STATE) != PackageManager.PERMISSION_GRANTED) {
            throw new SecurityException(
                    "requires permission " + Car.PERMISSION_CONTROL_APP_BLOCKING + " or "
                            + Car.PERMISSION_CAR_DRIVING_STATE);
        }
    }

    private void assertAppBlockingPermission() {
        if (mContext.checkCallingOrSelfPermission(Car.PERMISSION_CONTROL_APP_BLOCKING)
                != PackageManager.PERMISSION_GRANTED) {
            throw new SecurityException(
                    "requires permission " + Car.PERMISSION_CONTROL_APP_BLOCKING);
        }
    }

    private void doSetAppBlockingPolicy(String packageName, CarAppBlockingPolicy policy,
            int flags) {
        assertAppBlockingPermission();
        CarServiceUtils.assertPackageName(mContext, packageName);
        if (policy == null) {
            throw new IllegalArgumentException("policy cannot be null");
        }
        if ((flags & CarPackageManager.FLAG_SET_POLICY_ADD) != 0 &&
                (flags & CarPackageManager.FLAG_SET_POLICY_REMOVE) != 0) {
            throw new IllegalArgumentException(
                    "Cannot set both FLAG_SET_POLICY_ADD and FLAG_SET_POLICY_REMOVE flag");
        }
        synchronized (mLock) {
            if ((flags & CarPackageManager.FLAG_SET_POLICY_WAIT_FOR_CHANGE) != 0) {
                mWaitingPolicies.add(policy);
            }
        }
        mHandler.requestUpdatingPolicy(packageName, policy, flags);
        if ((flags & CarPackageManager.FLAG_SET_POLICY_WAIT_FOR_CHANGE) != 0) {
            synchronized (mLock) {
                try {
                    while (mWaitingPolicies.contains(policy)) {
                        mLock.wait();
                    }
                } catch (InterruptedException e) {
                    // Pass it over binder call
                    throw new IllegalStateException(
                            "Interrupted while waiting for policy completion", e);
                }
            }
        }
    }

    @Override
    public boolean isActivityDistractionOptimized(String packageName, String className) {
        if (!callerCanQueryPackage(packageName)) return false;
        assertPackageAndClassName(packageName, className);
        synchronized (mLock) {
            if (Log.isLoggable(TAG, Log.DEBUG)) {
                Slog.d(TAG, "isActivityDistractionOptimized" + dumpPoliciesLocked(false));
            }

            if (mTempAllowedActivities.contains(getComponentNameString(packageName,
                    className))) {
                return true;
            }

            for (int i = mTopActivityWithDialogPerDisplay.size() - 1; i >= 0; i--) {
                ComponentName activityWithDialog = mTopActivityWithDialogPerDisplay.get(
                        mTopActivityWithDialogPerDisplay.keyAt(i));
                if (activityWithDialog.getClassName().equals(className)
                        && activityWithDialog.getPackageName().equals(packageName)) {
                    return false;
                }
            }

            if (searchFromClientPolicyBlocklistsLocked(packageName)) {
                return false;
            }

            if (isActivityInClientPolicyAllowlistsLocked(packageName, className)) {
                return true;
            }

            // Check deny and allow list
            boolean packageBlocked = mActivityDenylistPackages.contains(packageName);
            AppBlockingPackageInfoWrapper infoWrapper = mActivityAllowlistMap.get(packageName);
            if (!packageBlocked && infoWrapper == null) {
                // Update cache
                updateActivityAllowlistAndDenylistMap(packageName);
                packageBlocked = mActivityDenylistPackages.contains(packageName);
                infoWrapper = mActivityAllowlistMap.get(packageName);
            }

            if (packageBlocked
                    || !isActivityInMapAndMatching(infoWrapper, packageName, className)) {
                return false;
            }

            return true;
        }
    }

    @VisibleForTesting
    boolean callerCanQueryPackage(String packageName) {
        int callingUid = Binder.getCallingUid();
        if (hasPermissionGranted(QUERY_ALL_PACKAGES, callingUid)) {
            return true;
        }
        String[] packages = mPackageManager.getPackagesForUid(callingUid);
        if (packages != null && packages.length > 0) {
            for (int i = 0; i < packages.length; i++) {
                if (Objects.equals(packageName, packages[i])) {
                    return true;
                }
            }
        }

        Slog.w(TAG, QUERY_ALL_PACKAGES + " permission is needed to query other packages.");

        return false;
    }

    private static boolean hasPermissionGranted(String permission, int uid) {
        return ActivityManager.checkComponentPermission(permission, uid,
                /* owningUid= */ Process.INVALID_UID,
                /* exported= */ true) == PackageManager.PERMISSION_GRANTED;
    }

    @Override
    public boolean isPendingIntentDistractionOptimized(PendingIntent pendingIntent) {
        ResolveInfo info = mPackageManager.resolveActivity(
                pendingIntent.getIntent(), PackageManager.MATCH_DEFAULT_ONLY);
        if (info == null) return false;
        ActivityInfo activityInfo = info.activityInfo;
        return isActivityDistractionOptimized(activityInfo.packageName, activityInfo.name);
    }

    @Override
    public boolean isServiceDistractionOptimized(String packageName, String className) {
        if (!callerCanQueryPackage(packageName)) return false;

        if (packageName == null) {
            throw new IllegalArgumentException("Package name null");
        }
        synchronized (mLock) {
            if (Log.isLoggable(TAG, Log.DEBUG)) {
                Slog.d(TAG, "isServiceDistractionOptimized" + dumpPoliciesLocked(false));
            }

            if (searchFromClientPolicyBlocklistsLocked(packageName)) {
                return false;
            }

            if (searchFromClientPolicyAllowlistsLocked(packageName)) {
                return true;
            }

            // Check deny and allow list
            boolean packageBlocked = mActivityDenylistPackages.contains(packageName);
            AppBlockingPackageInfoWrapper infoWrapper = mActivityAllowlistMap.get(packageName);
            if (!packageBlocked && infoWrapper == null) {
                // Update cache
                updateActivityAllowlistAndDenylistMap(packageName);
                packageBlocked = mActivityDenylistPackages.contains(packageName);
                infoWrapper = mActivityAllowlistMap.get(packageName);
            }

            if (packageBlocked || infoWrapper == null || infoWrapper.info == null) {
                return false;
            }

            return true;
        }
    }

    @Override
    public boolean isActivityBackedBySafeActivity(ComponentName activityName) {
        if (activityName == null) return false;
        if (!callerCanQueryPackage(activityName.getPackageName())) return false;

        RootTaskInfo info = mSystemActivityMonitoringService.getFocusedStackForTopActivity(
                activityName);
        if (info == null) { // not top in focused stack
            return true;
        }
        if (!isUxRestrictedOnDisplay(info.displayId)) {
            return true;
        }
        if (info.childTaskNames.length <= 1) { // nothing below this.
            return false;
        }
        ComponentName activityBehind = ComponentName.unflattenFromString(
                info.childTaskNames[info.childTaskNames.length - 2]);
        return isActivityDistractionOptimized(activityBehind.getPackageName(),
                activityBehind.getClassName());
    }

    public Looper getLooper() {
        return mHandlerThread.getLooper();
    }

    private void assertPackageAndClassName(String packageName, String className) {
        if (packageName == null) {
            throw new IllegalArgumentException("Package name null");
        }
        if (className == null) {
            throw new IllegalArgumentException("Class name null");
        }
    }

    @GuardedBy("mLock")
    private boolean searchFromClientPolicyBlocklistsLocked(String packageName) {
        for (ClientPolicy policy : mClientPolicies.values()) {
            AppBlockingPackageInfoWrapper wrapper = policy.mBlocklistsMap.get(packageName);
            if (wrapper != null && wrapper.isMatching && wrapper.info != null) {
                return true;
            }
        }

        return false;
    }

    @GuardedBy("mLock")
    private boolean searchFromClientPolicyAllowlistsLocked(String packageName) {
        for (ClientPolicy policy : mClientPolicies.values()) {
            AppBlockingPackageInfoWrapper wrapper = policy.mAllowlistsMap.get(packageName);
            if (wrapper != null && wrapper.isMatching && wrapper.info != null) {
                return true;
            }
        }
        return false;
    }

    @GuardedBy("mLock")
    private boolean isActivityInClientPolicyAllowlistsLocked(String packageName, String className) {
        for (ClientPolicy policy : mClientPolicies.values()) {
            if (isActivityInMapAndMatching(policy.mAllowlistsMap.get(packageName), packageName,
                    className)) {
                return true;
            }
        }
        return false;
    }

    private boolean isActivityInMapAndMatching(AppBlockingPackageInfoWrapper wrapper,
            String packageName, String className) {
        if (wrapper == null || !wrapper.isMatching) {
            if (Log.isLoggable(TAG, Log.DEBUG)) {
                Slog.d(TAG, "Pkg not in allowlist:" + packageName);
            }
            return false;
        }
        return wrapper.info.isActivityCovered(className);
    }

    @Override
    public void init() {
        String safetyRegion = SystemProperties.get(PROPERTY_RO_DRIVING_SAFETY_REGION, "");
        synchronized (mLock) {
            setDrivingSafetyRegionWithCheckLocked(safetyRegion);
            mHandler.requestInit();
        }
        CarLocalServices.getService(CarUserService.class).addUserLifecycleListener(
                mUserLifecycleListener);
        CarLocalServices.getService(CarPowerManagementService.class).addPowerPolicyListener(
                new CarPowerPolicyFilter.Builder().setComponents(PowerComponent.DISPLAY).build(),
                mDisplayPowerPolicyListener);
    }

    @Override
    public void release() {
        CarLocalServices.getService(CarPowerManagementService.class).removePowerPolicyListener(
                mDisplayPowerPolicyListener);
        CarLocalServices.getService(CarUserService.class).removeUserLifecycleListener(
                mUserLifecycleListener);
        synchronized (mLock) {
            mHandler.requestRelease();
            // wait for release do be done. This guarantees that init is done.
            try {
                mLock.wait();
            } catch (InterruptedException e) {
                Slog.e(TAG, "Interrupted wait during release");
                Thread.currentThread().interrupt();
            }
            mActivityAllowlistMap.clear();
            mActivityDenylistPackages.clear();
            mClientPolicies.clear();
            if (mProxies != null) {
                for (AppBlockingPolicyProxy proxy : mProxies) {
                    proxy.disconnect();
                }
                mProxies.clear();
            }
            mWaitingPolicies.clear();
            resetTempAllowedActivitiesLocked();
            mLock.notifyAll();
        }
        mContext.unregisterReceiver(mPackageParsingEventReceiver);
        mSystemActivityMonitoringService.registerActivityLaunchListener(null);
        for (int i = 0; i < mUxRestrictionsListeners.size(); i++) {
            UxRestrictionsListener listener = mUxRestrictionsListeners.valueAt(i);
            mCarUxRestrictionsService.unregisterUxRestrictionsChangeListener(listener);
        }
    }

    @GuardedBy("mLock")
    private void setDrivingSafetyRegionWithCheckLocked(String region) {
        if (region.isEmpty()) {
            mCurrentDrivingSafetyRegion = CarPackageManager.DRIVING_SAFETY_REGION_ALL;
        } else {
            mCurrentDrivingSafetyRegion = region;
        }
    }

    /**
     * Reset driving stat and all dynamically added allow list so that region information for
     * all packages are reset. This also resets one time allow list.
     */
    public void resetDrivingSafetyRegion(@NonNull String region) {
        synchronized (mLock) {
            setDrivingSafetyRegionWithCheckLocked(region);
            resetTempAllowedActivitiesLocked();
            mActivityAllowlistMap.clear();
            mActivityDenylistPackages.clear();
        }
    }

    // run from HandlerThread
    private void doHandleInit() {
        startAppBlockingPolicies();
        IntentFilter pkgParseIntent = new IntentFilter();
        for (String action : mPackageManagerActions) {
            pkgParseIntent.addAction(action);
        }
        pkgParseIntent.addDataScheme("package");
        mContext.registerReceiverAsUser(mPackageParsingEventReceiver, UserHandle.ALL,
                pkgParseIntent, null, null);

        List<Display> physicalDisplays = getPhysicalDisplays();

        // Assume default display (display 0) is always a physical display.
        Display defaultDisplay = mDisplayManager.getDisplay(Display.DEFAULT_DISPLAY);
        if (!physicalDisplays.contains(defaultDisplay)) {
            if (Log.isLoggable(TAG, Log.INFO)) {
                Slog.i(TAG, "Adding default display to physical displays.");
            }
            physicalDisplays.add(defaultDisplay);
        }
        for (Display physicalDisplay : physicalDisplays) {
            int displayId = physicalDisplay.getDisplayId();
            UxRestrictionsListener listener = new UxRestrictionsListener(mCarUxRestrictionsService);
            mUxRestrictionsListeners.put(displayId, listener);
            mCarUxRestrictionsService.registerUxRestrictionsChangeListener(listener, displayId);
        }
        mVendorServiceController.init();
        mSystemActivityMonitoringService.registerActivityLaunchListener(mActivityLaunchListener);
    }

    private void doParseInstalledPackage(String packageName) {
        // Delete the package from allowlist and denylist mapping
        synchronized (mLock) {
            mActivityDenylistPackages.remove(packageName);
            mActivityAllowlistMap.remove(packageName);
        }

        // Generate allowlist and denylist mapping for the package
        updateActivityAllowlistAndDenylistMap(packageName);
        blockTopActivitiesIfNecessary();
    }

    private void doHandleRelease() {
        synchronized (mLock) {
            mVendorServiceController.release();
            mLock.notifyAll();
        }
    }

    private void doUpdatePolicy(String packageName, CarAppBlockingPolicy policy, int flags) {
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Slog.d(TAG, "setting policy from:" + packageName + ",policy:" + policy + ",flags:0x"
                    + Integer.toHexString(flags));
        }
        AppBlockingPackageInfoWrapper[] blocklistWrapper = verifyList(policy.blacklists);
        AppBlockingPackageInfoWrapper[] allowlistWrapper = verifyList(policy.whitelists);
        synchronized (mLock) {
            ClientPolicy clientPolicy = mClientPolicies.get(packageName);
            if (clientPolicy == null) {
                clientPolicy = new ClientPolicy();
                mClientPolicies.put(packageName, clientPolicy);
            }
            if ((flags & CarPackageManager.FLAG_SET_POLICY_ADD) != 0) {
                clientPolicy.addToBlocklists(blocklistWrapper);
                clientPolicy.addToAllowlists(allowlistWrapper);
            } else if ((flags & CarPackageManager.FLAG_SET_POLICY_REMOVE) != 0) {
                clientPolicy.removeBlocklists(blocklistWrapper);
                clientPolicy.removeAllowlists(allowlistWrapper);
            } else { //replace.
                clientPolicy.replaceBlocklists(blocklistWrapper);
                clientPolicy.replaceAllowlists(allowlistWrapper);
            }
            if ((flags & CarPackageManager.FLAG_SET_POLICY_WAIT_FOR_CHANGE) != 0) {
                mWaitingPolicies.remove(policy);
                mLock.notifyAll();
            }
            if (Log.isLoggable(TAG, Log.DEBUG)) {
                Slog.d(TAG, "policy set:" + dumpPoliciesLocked(false));
            }
        }
        blockTopActivitiesIfNecessary();
    }

    private AppBlockingPackageInfoWrapper[] verifyList(AppBlockingPackageInfo[] list) {
        if (list == null) {
            return null;
        }
        LinkedList<AppBlockingPackageInfoWrapper> wrappers = new LinkedList<>();
        for (int i = 0; i < list.length; i++) {
            AppBlockingPackageInfo info = list[i];
            if (info == null) {
                continue;
            }
            boolean isMatching = isInstalledPackageMatching(info);
            wrappers.add(new AppBlockingPackageInfoWrapper(info, isMatching));
        }
        return wrappers.toArray(new AppBlockingPackageInfoWrapper[wrappers.size()]);
    }

    boolean isInstalledPackageMatching(AppBlockingPackageInfo info) {
        PackageInfo packageInfo;
        try {
            packageInfo = mPackageManager.getPackageInfo(info.packageName,
                    PackageManager.GET_SIGNATURES);
        } catch (NameNotFoundException e) {
            return false;
        }
        if (packageInfo == null) {
            return false;
        }
        // if it is system app and client specified the flag, do not check signature
        if ((info.flags & AppBlockingPackageInfo.FLAG_SYSTEM_APP) == 0 ||
                (!packageInfo.applicationInfo.isSystemApp() &&
                        !packageInfo.applicationInfo.isUpdatedSystemApp())) {
            Signature[] signatures = packageInfo.signatures;
            if (!isAnySignatureMatching(signatures, info.signatures)) {
                return false;
            }
        }
        int version = packageInfo.versionCode;
        if (info.minRevisionCode == 0) {
            if (info.maxRevisionCode == 0) { // all versions
                return true;
            } else { // only max version matters
                return info.maxRevisionCode > version;
            }
        } else { // min version matters
            if (info.maxRevisionCode == 0) {
                return info.minRevisionCode < version;
            } else {
                return (info.minRevisionCode < version) && (info.maxRevisionCode > version);
            }
        }
    }

    /**
     * Any signature from policy matching with package's signatures is treated as matching.
     */
    boolean isAnySignatureMatching(Signature[] fromPackage, Signature[] fromPolicy) {
        if (fromPackage == null) {
            return false;
        }
        if (fromPolicy == null) {
            return false;
        }
        ArraySet<Signature> setFromPackage = new ArraySet<Signature>();
        for (Signature sig : fromPackage) {
            setFromPackage.add(sig);
        }
        for (Signature sig : fromPolicy) {
            if (setFromPackage.contains(sig)) {
                return true;
            }
        }
        return false;
    }

    private AppBlockingPackageInfoWrapper getPackageInfoWrapperForUser(String packageName,
            @UserIdInt int userId, Map<String, Set<String>> configAllowlist,
            Map<String, Set<String>> configBlocklist) {
        PackageInfo info;
        try {
            info = mPackageManager.getPackageInfoAsUser(packageName,
                    PackageManager.GET_SIGNATURES | PackageManager.GET_ACTIVITIES
                            | PackageManager.MATCH_DIRECT_BOOT_AWARE
                            | PackageManager.MATCH_DIRECT_BOOT_UNAWARE
                            | PackageManager.MATCH_DISABLED_COMPONENTS,
                    userId);
        } catch (NameNotFoundException e) {
            Slog.w(TAG, packageName + " not installed! User Id: " + userId);
            return null;
        }


        if (info == null || info.applicationInfo == null) {
            return null;
        }

        int flags = 0;
        Set<String> activities = new ArraySet<>();

        if (info.applicationInfo.isSystemApp()
                || info.applicationInfo.isUpdatedSystemApp()) {
            flags = AppBlockingPackageInfo.FLAG_SYSTEM_APP;
        }

        /* 1. Check if all or some of this app is in the <activityAllowlist> or
              <systemActivityAllowlist> in config.xml */
        Set<String> configActivitiesForPackage = configAllowlist.get(info.packageName);
        if (configActivitiesForPackage != null) {
            if (Log.isLoggable(TAG, Log.DEBUG)) {
                Slog.d(TAG, info.packageName + " allowlisted");
            }

            if (configActivitiesForPackage.isEmpty()) {
                // Whole Pkg has been allowlisted
                flags |= AppBlockingPackageInfo.FLAG_WHOLE_ACTIVITY;
                // Add all activities to the allowlist
                List<String> activitiesForPackage = getActivitiesInPackage(info);
                if (activitiesForPackage != null) {
                    activities.addAll(activitiesForPackage);
                } else {
                    if (Log.isLoggable(TAG, Log.DEBUG)) {
                        Slog.d(TAG, info.packageName + ": Activities null");
                    }
                }
            } else {
                if (Log.isLoggable(TAG, Log.DEBUG)) {
                    Slog.d(TAG, "Partially Allowlisted. WL Activities: "
                            + configActivitiesForPackage);
                }
                activities.addAll(configActivitiesForPackage);
            }
        }
        /* 2. If app is not listed in the config.xml check their Manifest meta-data to
          see if they have any Distraction Optimized(DO) activities.
          For non system apps, we check if the app install source was a permittable
          source. This prevents side-loaded apps to fake DO.  Bypass the check
          for debug builds for development convenience. */
        if (!isDebugBuild()
                && !info.applicationInfo.isSystemApp()
                && !info.applicationInfo.isUpdatedSystemApp()) {
            try {
                if (mAllowedAppInstallSources != null) {
                    String installerName = mPackageManager.getInstallerPackageName(
                            info.packageName);
                    if (installerName == null || (installerName != null
                            && !mAllowedAppInstallSources.contains(installerName))) {
                        Slog.w(TAG,
                                info.packageName + " not installed from permitted sources "
                                        + (installerName == null ? "NULL" : installerName));
                        return null;
                    }
                }
            } catch (IllegalArgumentException e) {
                Slog.w(TAG, info.packageName + " not installed!");
                return null;
            }
        }

        try {
            String[] doActivities = findDistractionOptimizedActivitiesAsUser(info.packageName,
                    userId);
            if (doActivities != null) {
                // Some of the activities in this app are Distraction Optimized.
                if (Log.isLoggable(TAG, Log.DEBUG)) {
                    for (String activity : doActivities) {
                        Slog.d(TAG, "adding " + activity + " from " + info.packageName
                                + " to allowlist");
                    }
                }

                activities.addAll(Arrays.asList(doActivities));
            }
        } catch (NameNotFoundException e) {
            Slog.w(TAG, "Error reading metadata: " + info.packageName);
            return null;
        }

        // Nothing to add to allowlist
        if (activities.isEmpty()) {
            return null;
        }

        /* 3. Check if parsed activity is in <activityBlocklist> in config.xml. Anything
              in blocklist should not be allowlisted, either as D.O. or by config. */
        if (configBlocklist.containsKey(info.packageName)) {
            Set<String> configBlocklistActivities = configBlocklist.get(info.packageName);
            if (configBlocklistActivities.isEmpty()) {
                // Whole package should be blocklisted.
                return null;
            }
            activities.removeAll(configBlocklistActivities);
        }

        Signature[] signatures;
        signatures = info.signatures;
        AppBlockingPackageInfo appBlockingInfo = new AppBlockingPackageInfo(info.packageName,
                /* minRevisionCode = */ 0, /* maxRevisionCode = */ 0, flags, signatures,
                activities.toArray(new String[activities.size()]));
        AppBlockingPackageInfoWrapper wrapper = new AppBlockingPackageInfoWrapper(
                appBlockingInfo, true);
        return wrapper;
    }

    /**
     * Update map of allowlisted packages and activities of the form {pkgName, Allowlisted
     * activities} and set of denylisted packages. The information can come from a configuration XML
     * resource or from the apps marking their activities as distraction optimized.
     */
    private void updateActivityAllowlistAndDenylistMap(String packageName) {
        int userId = mActivityManager.getCurrentUser();
        Slog.d(TAG, "Updating allowlist and denylist mapping for package: " + packageName
                + " for UserId: " + userId);
        // Get the apps/activities that are allowlisted in the configuration XML resources.
        Map<String, Set<String>> configAllowlist = generateConfigAllowlist();
        Map<String, Set<String>> configBlocklist = generateConfigBlocklist();

        AppBlockingPackageInfoWrapper wrapper =
                getPackageInfoWrapperForUser(packageName, userId, configAllowlist, configBlocklist);

        if (wrapper == null && userId != UserHandle.USER_SYSTEM) {
            Slog.d(TAG, "Updating allowlist and denylist mapping for package: " + packageName
                    + " for UserId: " + UserHandle.USER_SYSTEM);
            // check package for system user, in case package is disabled for current user
            wrapper = getPackageInfoWrapperForUser(packageName, UserHandle.USER_SYSTEM,
                    configAllowlist, configBlocklist);
        }

        synchronized (mLock) {
            if (wrapper != null) {
                if (DBG) {
                    Slog.d(TAG, "Package: " + packageName + " added in allowlist.");
                }
                mActivityAllowlistMap.put(packageName, wrapper);
            } else {
                if (DBG) {
                    Slog.d(TAG, "Package: " + packageName + " added in denylist.");
                }
                mActivityDenylistPackages.add(packageName);
            }
        }
    }

    private Map<String, Set<String>> generateConfigAllowlist() {
        synchronized (mLock) {
            if (mConfiguredAllowlistMap != null) return mConfiguredAllowlistMap;

            Map<String, Set<String>> configAllowlist = new HashMap<>();
            mConfiguredAllowlist = mContext.getString(R.string.activityAllowlist);
            if (mConfiguredAllowlist == null) {
                Slog.w(TAG, "Allowlist is null.");
            }
            parseConfigList(mConfiguredAllowlist, configAllowlist);

            mConfiguredSystemAllowlist = mContext.getString(R.string.systemActivityAllowlist);
            if (mConfiguredSystemAllowlist == null) {
                Slog.w(TAG, "System allowlist is null.");
            }
            parseConfigList(mConfiguredSystemAllowlist, configAllowlist);

            // Add the blocking overlay activity to the allowlist, since that needs to run in a
            // restricted state to communicate the reason an app was blocked.
            Set<String> defaultActivity = new ArraySet<>();
            if (mActivityBlockingActivity != null) {
                defaultActivity.add(mActivityBlockingActivity.getClassName());
                configAllowlist.put(mActivityBlockingActivity.getPackageName(), defaultActivity);
            }

            mConfiguredAllowlistMap = configAllowlist;
            return configAllowlist;
        }
    }

    private Map<String, Set<String>> generateConfigBlocklist() {
        synchronized (mLock) {
            if (mConfiguredBlocklistMap != null) return mConfiguredBlocklistMap;

            Map<String, Set<String>> configBlocklist = new HashMap<>();
            mConfiguredBlocklist = mContext.getString(R.string.activityDenylist);
            if (mConfiguredBlocklist == null) {
                if (Log.isLoggable(TAG, Log.DEBUG)) {
                    Slog.d(TAG, "Null blocklist in config");
                }
            }
            parseConfigList(mConfiguredBlocklist, configBlocklist);

            mConfiguredBlocklistMap = configBlocklist;
            return configBlocklist;
        }
    }

    private boolean isDebugBuild() {
        return Build.IS_USERDEBUG || Build.IS_ENG;
    }

    /**
     * Parses the given resource and updates the input map of packages and activities.
     *
     * Key is package name and value is list of activities. Empty set implies whole package is
     * included.
     *
     * When there are multiple entries regarding one package, the entry with
     * greater scope wins. Namely if there were 2 entries such that one allowlists
     * an activity, and the other allowlists the entire package of the activity,
     * the package is allowlisted, regardless of input order.
     */
    @VisibleForTesting
    /* package */ void parseConfigList(String configList,
            @NonNull Map<String, Set<String>> packageToActivityMap) {
        if (configList == null) {
            return;
        }
        String[] entries = configList.split(PACKAGE_DELIMITER);
        for (String entry : entries) {
            String[] packageActivityPair = entry.split(PACKAGE_ACTIVITY_DELIMITER);
            Set<String> activities = packageToActivityMap.get(packageActivityPair[0]);
            boolean newPackage = false;
            if (activities == null) {
                activities = new ArraySet<>();
                newPackage = true;
                packageToActivityMap.put(packageActivityPair[0], activities);
            }
            if (packageActivityPair.length == 1) { // whole package
                activities.clear();
            } else if (packageActivityPair.length == 2) {
                // add class name only when the whole package is not allowlisted.
                if (newPackage || (activities.size() > 0)) {
                    activities.add(packageActivityPair[1]);
                }
            }
        }
    }

    @Nullable
    private List<String> getActivitiesInPackage(PackageInfo info) {
        if (info == null || info.activities == null) {
            return null;
        }
        List<String> activityList = new ArrayList<>();
        for (ActivityInfo aInfo : info.activities) {
            activityList.add(aInfo.name);
        }
        return activityList;
    }

    /**
     * Checks if there are any {@link CarAppBlockingPolicyService} and creates a proxy to
     * bind to them and retrieve the {@link CarAppBlockingPolicy}
     */
    @VisibleForTesting
    public void startAppBlockingPolicies() {
        Intent policyIntent = new Intent();
        policyIntent.setAction(CarAppBlockingPolicyService.SERVICE_INTERFACE);
        List<ResolveInfo> policyInfos = mPackageManager.queryIntentServices(policyIntent, 0);
        if (policyInfos == null) { //no need to wait for service binding and retrieval.
            return;
        }
        LinkedList<AppBlockingPolicyProxy> proxies = new LinkedList<>();
        for (ResolveInfo resolveInfo : policyInfos) {
            ServiceInfo serviceInfo = resolveInfo.serviceInfo;
            if (serviceInfo == null) {
                continue;
            }
            if (serviceInfo.isEnabled()) {
                if (mPackageManager.checkPermission(Car.PERMISSION_CONTROL_APP_BLOCKING,
                        serviceInfo.packageName) != PackageManager.PERMISSION_GRANTED) {
                    continue;
                }
                Slog.i(TAG, "found policy holding service:" + serviceInfo);
                AppBlockingPolicyProxy proxy = new AppBlockingPolicyProxy(this, mContext,
                        serviceInfo);
                proxy.connect();
                proxies.add(proxy);
            }
        }
        synchronized (mLock) {
            mProxies = proxies;
        }
    }

    public void onPolicyConnectionAndSet(AppBlockingPolicyProxy proxy,
            CarAppBlockingPolicy policy) {
        doHandlePolicyConnection(proxy, policy);
    }

    public void onPolicyConnectionFailure(AppBlockingPolicyProxy proxy) {
        doHandlePolicyConnection(proxy, null);
    }

    private void doHandlePolicyConnection(AppBlockingPolicyProxy proxy,
            CarAppBlockingPolicy policy) {
        synchronized (mLock) {
            if (mProxies == null) {
                proxy.disconnect();
                return;
            }
            mProxies.remove(proxy);
            if (mProxies.size() == 0) {
                mProxies = null;
            }
        }
        try {
            if (policy != null) {
                if (Log.isLoggable(TAG, Log.DEBUG)) {
                    Slog.d(TAG, "policy setting from policy service:" + proxy.getPackageName());
                }
                doSetAppBlockingPolicy(proxy.getPackageName(), policy, 0);
            }
        } finally {
            proxy.disconnect();
        }
    }

    @Override
    public void dump(IndentingPrintWriter writer) {
        synchronized (mLock) {
            writer.println("*CarPackageManagerService*");
            writer.println("mEnableActivityBlocking:" + mEnableActivityBlocking);
            writer.println("mPreventTemplatedAppsFromShowingDialog:"
                    + mPreventTemplatedAppsFromShowingDialog);
            writer.println("mTemplateActivityClassName:" + mTemplateActivityClassName);
            List<String> restrictions = new ArrayList<>(mUxRestrictionsListeners.size());
            for (int i = 0; i < mUxRestrictionsListeners.size(); i++) {
                int displayId = mUxRestrictionsListeners.keyAt(i);
                UxRestrictionsListener listener = mUxRestrictionsListeners.valueAt(i);
                restrictions.add(String.format("Display %d is %s",
                        displayId, (listener.isRestricted() ? "restricted" : "unrestricted")));
            }
            writer.println("Display Restrictions:\n" + String.join("\n", restrictions));
            writer.println(" Blocked activity log:");
            mBlockedActivityLogs.dump(writer);
            writer.print(dumpPoliciesLocked(true));
            writer.print("mCurrentDrivingSafetyRegion:");
            writer.println(mCurrentDrivingSafetyRegion);
            writer.print("mTempAllowedActivities:");
            writer.println(mTempAllowedActivities);
        }
    }

    @GuardedBy("mLock")
    private String dumpPoliciesLocked(boolean dumpAll) {
        StringBuilder sb = new StringBuilder();
        if (dumpAll) {
            sb.append("**System allowlist**\n");
            for (AppBlockingPackageInfoWrapper wrapper : mActivityAllowlistMap.values()) {
                sb.append(wrapper.toString() + "\n");
            }
        }
        sb.append("**Client Policies**\n");
        for (Entry<String, ClientPolicy> entry : mClientPolicies.entrySet()) {
            sb.append("Client:" + entry.getKey() + "\n");
            sb.append("  allowlists:\n");
            for (AppBlockingPackageInfoWrapper wrapper : entry.getValue().mAllowlistsMap.values()) {
                sb.append(wrapper.toString() + "\n");
            }
            sb.append("  blocklists:\n");
            for (AppBlockingPackageInfoWrapper wrapper : entry.getValue().mBlocklistsMap.values()) {
                sb.append(wrapper.toString() + "\n");
            }
        }
        sb.append("**Unprocessed policy services**\n");
        if (mProxies != null) {
            for (AppBlockingPolicyProxy proxy : mProxies) {
                sb.append(proxy.toString() + "\n");
            }
        }
        sb.append("**Allowlist string in resource**\n");
        sb.append(mConfiguredAllowlist + "\n");

        sb.append("**System allowlist string in resource**\n");
        sb.append(mConfiguredSystemAllowlist + "\n");

        sb.append("**Blocklist string in resource**\n");
        sb.append(mConfiguredBlocklist + "\n");

        sb.append("**Allowlist map from resource**\n");
        sb.append(mConfiguredAllowlistMap + "\n");

        sb.append("**Blocklist from resource**\n");
        sb.append(mConfiguredBlocklist + "\n");

        return sb.toString();
    }

    /**
     * Returns display with physical address.
     */
    private List<Display> getPhysicalDisplays() {
        List<Display> displays = new ArrayList<>();
        for (Display display : mDisplayManager.getDisplays()) {
            if (display.getAddress() instanceof DisplayAddress.Physical) {
                displays.add(display);
            }
        }
        return displays;
    }

    /**
     * Returns whether UX restrictions is required for display.
     *
     * Non-physical display will use restrictions for {@link Display#DEFAULT_DISPLAY}.
     */
    private boolean isUxRestrictedOnDisplay(int displayId) {
        UxRestrictionsListener listenerForTopTaskDisplay;
        if (mUxRestrictionsListeners.indexOfKey(displayId) < 0) {
            listenerForTopTaskDisplay = mUxRestrictionsListeners.get(Display.DEFAULT_DISPLAY);
            if (listenerForTopTaskDisplay == null) {
                // This should never happen.
                Slog.e(TAG, "Missing listener for default display.");
                return true;
            }
        } else {
            listenerForTopTaskDisplay = mUxRestrictionsListeners.get(displayId);
        }

        return listenerForTopTaskDisplay.isRestricted();
    }

    private void blockTopActivitiesIfNecessary() {
        List<TopTaskInfoContainer> topTasks = mSystemActivityMonitoringService.getTopTasks();
        for (TopTaskInfoContainer topTask : topTasks) {
            if (topTask == null) {
                Slog.e(TAG, "Top tasks contains null.");
                continue;
            }
            blockTopActivityIfNecessary(topTask);
        }
    }

    private void blockTopActivityIfNecessary(TopTaskInfoContainer topTask) {
        synchronized (mLock) {
            if (!Objects.equals(mActivityBlockingActivity, topTask.topActivity)
                    && mTopActivityWithDialogPerDisplay.contains(topTask.displayId)
                    && !topTask.topActivity.equals(
                            mTopActivityWithDialogPerDisplay.get(topTask.displayId))) {
                // Clear top activity-with-dialog if the activity has changed on this display.
                mTopActivityWithDialogPerDisplay.remove(topTask.displayId);
            }
        }
        if (isUxRestrictedOnDisplay(topTask.displayId)) {
            doBlockTopActivityIfNotAllowed(topTask);
        }
    }

    private void doBlockTopActivityIfNotAllowed(TopTaskInfoContainer topTask) {
        if (topTask.topActivity == null) {
            return;
        }
        boolean allowed = isActivityAllowed(topTask);
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Slog.d(TAG, "new activity:" + topTask.toString() + " allowed:" + allowed);
        }
        if (allowed) {
            return;
        }
        if (!mEnableActivityBlocking) {
            Slog.d(TAG, "Current activity " + topTask.topActivity
                    + " not allowed, blocking disabled. Number of tasks in stack:"
                    + topTask.taskInfo.childTaskIds.length);
            return;
        }
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Slog.d(TAG, "Current activity " + topTask.topActivity
                    + " not allowed, will block, number of tasks in stack:"
                    + topTask.taskInfo.childTaskIds.length);
        }

        // Figure out the root activity of blocked task.
        String taskRootActivity = null;
        for (int i = 0; i < topTask.taskInfo.childTaskIds.length; i++) {
            // topTask.taskId is the task that should be blocked.
            if (topTask.taskInfo.childTaskIds[i] == topTask.taskId) {
                // stackInfo represents an ActivityStack. Its fields taskIds and taskNames
                // are 1:1 mapped, where taskNames is the name of root activity in this task.
                taskRootActivity = topTask.taskInfo.childTaskNames[i];
                break;
            }
        }

        boolean isRootDO = false;
        if (taskRootActivity != null) {
            ComponentName taskRootComponentName =
                    ComponentName.unflattenFromString(taskRootActivity);
            isRootDO = isActivityDistractionOptimized(
                    taskRootComponentName.getPackageName(), taskRootComponentName.getClassName());
        }

        Intent newActivityIntent = createBlockingActivityIntent(
                mActivityBlockingActivity, topTask.displayId,
                topTask.topActivity.flattenToShortString(), topTask.taskId, taskRootActivity,
                isRootDO);

        // Intent contains all info to debug what is blocked - log into both logcat and dumpsys.
        String log = "Starting blocking activity with intent: " + newActivityIntent.toUri(0);
        if (Log.isLoggable(TAG, Log.INFO)) {
            Slog.i(TAG, log);
        }
        mBlockedActivityLogs.log(log);
        mSystemActivityMonitoringService.blockActivity(topTask, newActivityIntent);
    }

    private boolean isActivityAllowed(TopTaskInfoContainer topTaskInfoContainer) {
        ComponentName activityName = topTaskInfoContainer.topActivity;
        boolean isDistractionOptimized = isActivityDistractionOptimized(
                activityName.getPackageName(),
                activityName.getClassName());
        if (!isDistractionOptimized) {
            return false;
        }
        return !(mPreventTemplatedAppsFromShowingDialog
                && isTemplateActivity(activityName)
                && isActivityShowingADialogOnDisplay(activityName, topTaskInfoContainer.displayId));
    }

    private boolean isTemplateActivity(ComponentName activityName) {
        // TODO(b/191263486): Finalise on how to detect the templated activities.
        return activityName.getClassName().equals(mTemplateActivityClassName);
    }

    private boolean isActivityShowingADialogOnDisplay(ComponentName activityName, int displayId) {
        String output = dumpWindows();
        List<WindowDumpParser.Window> appWindows =
                WindowDumpParser.getParsedAppWindows(output, activityName.getPackageName());
        // TODO(b/192354699): Handle case where an activity can have multiple instances on the same
        //  display.
        int totalAppWindows = appWindows.size();
        String firstActivityRecord = null;
        int numTopActivityAppWindowsOnDisplay = 0;
        for (int i = 0; i < totalAppWindows; i++) {
            WindowDumpParser.Window appWindow = appWindows.get(i);
            if (appWindow.getDisplayId() != displayId) {
                continue;
            }
            if (TextUtils.isEmpty(appWindow.getActivityRecord())) {
                continue;
            }
            if (firstActivityRecord == null) {
                firstActivityRecord = appWindow.getActivityRecord();
            }
            if (firstActivityRecord.equals(appWindow.getActivityRecord())) {
                numTopActivityAppWindowsOnDisplay++;
            }
        }
        Slogf.d(TAG, "Top activity =  " + activityName);
        Slogf.d(TAG, "Number of app widows of top activity = " + numTopActivityAppWindowsOnDisplay);
        boolean isShowingADialog = numTopActivityAppWindowsOnDisplay > 1;
        synchronized (mLock) {
            if (isShowingADialog) {
                mTopActivityWithDialogPerDisplay.put(displayId, activityName);
            } else {
                mTopActivityWithDialogPerDisplay.remove(displayId);
            }
        }
        return isShowingADialog;
    }

    private String dumpWindows() {
        try {
            ParcelFileDescriptor[] fileDescriptors = ParcelFileDescriptor.createSocketPair();
            mWindowManagerBinder.dump(
                    fileDescriptors[0].getFileDescriptor(), WINDOW_DUMP_ARGUMENTS);
            fileDescriptors[0].close();
            StringBuilder outputBuilder = new StringBuilder();
            BufferedReader reader = new BufferedReader(
                    new FileReader(fileDescriptors[1].getFileDescriptor()));
            String line;
            while ((line = reader.readLine()) != null) {
                outputBuilder.append(line).append("\n");
            }
            reader.close();
            fileDescriptors[1].close();
            return outputBuilder.toString();
        } catch (IOException | RemoteException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Creates an intent to start blocking activity.
     *
     * @param blockingActivity the activity to launch
     * @param blockedActivity  the activity being blocked
     * @param blockedTaskId    the blocked task id, which contains the blocked activity
     * @param taskRootActivity root activity of the blocked task
     * @param isRootDo         denotes if the root activity is distraction optimised
     * @return an intent to launch the blocking activity.
     */
    private static Intent createBlockingActivityIntent(ComponentName blockingActivity,
            int displayId, String blockedActivity, int blockedTaskId, String taskRootActivity,
            boolean isRootDo) {
        Intent newActivityIntent = new Intent();
        newActivityIntent.setFlags(Intent.FLAG_ACTIVITY_MULTIPLE_TASK);
        newActivityIntent.setComponent(blockingActivity);
        newActivityIntent.putExtra(
                BLOCKING_INTENT_EXTRA_DISPLAY_ID, displayId);
        newActivityIntent.putExtra(
                BLOCKING_INTENT_EXTRA_BLOCKED_ACTIVITY_NAME, blockedActivity);
        newActivityIntent.putExtra(
                BLOCKING_INTENT_EXTRA_BLOCKED_TASK_ID, blockedTaskId);
        newActivityIntent.putExtra(
                BLOCKING_INTENT_EXTRA_ROOT_ACTIVITY_NAME, taskRootActivity);
        newActivityIntent.putExtra(
                BLOCKING_INTENT_EXTRA_IS_ROOT_ACTIVITY_DO, isRootDo);

        return newActivityIntent;
    }

    /**
     * Enable/Disable activity blocking by correspondingly enabling/disabling broadcasting UXR
     * changes in {@link CarUxRestrictionsManagerService}. This is only available in
     * engineering builds for development convenience.
     */
    @Override
    public void setEnableActivityBlocking(boolean enable) {
        if (!isDebugBuild()) {
            Slog.e(TAG, "Cannot enable/disable activity blocking");
            return;
        }

        // Check if the caller has the same signature as that of the car service.
        if (mPackageManager.checkSignatures(Process.myUid(), Binder.getCallingUid())
                != PackageManager.SIGNATURE_MATCH) {
            throw new SecurityException(
                    "Caller " + mPackageManager.getNameForUid(Binder.getCallingUid())
                    + " does not have the right signature");
        }
        mCarUxRestrictionsService.setUxRChangeBroadcastEnabled(enable);
    }

    /**
     * Get the distraction optimized activities for the given package.
     *
     * @param pkgName Name of the package
     * @return Array of the distraction optimized activities in the package
     */
    @Nullable
    public String[] getDistractionOptimizedActivities(String pkgName) {
        try {
            return findDistractionOptimizedActivitiesAsUser(pkgName,
                    mActivityManager.getCurrentUser());
        } catch (NameNotFoundException e) {
            return null;
        }
    }

    private String[] findDistractionOptimizedActivitiesAsUser(String pkgName, int userId)
            throws NameNotFoundException {
        String regionString;
        synchronized (mLock) {
            regionString = mCurrentDrivingSafetyRegion;
        }
        return CarAppMetadataReader.findDistractionOptimizedActivitiesAsUser(mContext, pkgName,
                userId, regionString);
    }

    /**
     * Reading policy and setting policy can take time. Run it in a separate handler thread.
     */
    private static final class PackageHandler extends Handler {
        private static final String TAG = CarLog.tagFor(CarPackageManagerService.class);

        private static final int MSG_INIT = 0;
        private static final int MSG_PARSE_PKG = 1;
        private static final int MSG_UPDATE_POLICY = 2;
        private static final int MSG_RELEASE = 3;

        private final WeakReference<CarPackageManagerService> mService;

        private PackageHandler(Looper looper, CarPackageManagerService service) {
            super(looper);
            mService = new WeakReference<CarPackageManagerService>(service);
        }

        private void requestInit() {
            Message msg = obtainMessage(MSG_INIT);
            sendMessage(msg);
        }

        private void requestRelease() {
            removeMessages(MSG_UPDATE_POLICY);
            Message msg = obtainMessage(MSG_RELEASE);
            sendMessage(msg);
        }

        private void requestUpdatingPolicy(String packageName, CarAppBlockingPolicy policy,
                int flags) {
            Pair<String, CarAppBlockingPolicy> pair = new Pair<>(packageName, policy);
            Message msg = obtainMessage(MSG_UPDATE_POLICY, flags, 0, pair);
            sendMessage(msg);
        }

        private void requestParsingInstalledPkg(String packageName) {
            Message msg = obtainMessage(MSG_PARSE_PKG, packageName);
            sendMessage(msg);
        }

        @Override
        public void handleMessage(Message msg) {
            CarPackageManagerService service = mService.get();
            if (service == null) {
                Slog.i(TAG, "handleMessage null service");
                return;
            }
            switch (msg.what) {
                case MSG_INIT:
                    service.doHandleInit();
                    break;
                case MSG_PARSE_PKG:
                    service.doParseInstalledPackage((String) msg.obj);
                    break;
                case MSG_UPDATE_POLICY:
                    Pair<String, CarAppBlockingPolicy> pair =
                            (Pair<String, CarAppBlockingPolicy>) msg.obj;
                    service.doUpdatePolicy(pair.first, pair.second, msg.arg1);
                    break;
                case MSG_RELEASE:
                    service.doHandleRelease();
                    break;
            }
        }
    }

    private static class AppBlockingPackageInfoWrapper {
        private final AppBlockingPackageInfo info;
        /**
         * Whether the current info is matching with the target package in system. Mismatch can
         * happen for version out of range or signature mismatch.
         */
        private boolean isMatching;

        private AppBlockingPackageInfoWrapper(AppBlockingPackageInfo info, boolean isMatching) {
            this.info = info;
            this.isMatching = isMatching;
        }

        @Override
        public String toString() {
            return "AppBlockingPackageInfoWrapper [info=" + info + ", isMatching=" + isMatching +
                    "]";
        }
    }

    /**
     * Client policy holder per each client. Should be accessed with CarpackageManagerService.this
     * held.
     */
    private static class ClientPolicy {
        private final HashMap<String, AppBlockingPackageInfoWrapper> mAllowlistsMap =
                new HashMap<>();
        private final HashMap<String, AppBlockingPackageInfoWrapper> mBlocklistsMap =
                new HashMap<>();

        private void replaceAllowlists(AppBlockingPackageInfoWrapper[] allowlists) {
            mAllowlistsMap.clear();
            addToAllowlists(allowlists);
        }

        private void addToAllowlists(AppBlockingPackageInfoWrapper[] allowlists) {
            if (allowlists == null) {
                return;
            }
            for (AppBlockingPackageInfoWrapper wrapper : allowlists) {
                if (wrapper != null) {
                    mAllowlistsMap.put(wrapper.info.packageName, wrapper);
                }
            }
        }

        private void removeAllowlists(AppBlockingPackageInfoWrapper[] allowlists) {
            if (allowlists == null) {
                return;
            }
            for (AppBlockingPackageInfoWrapper wrapper : allowlists) {
                if (wrapper != null) {
                    mAllowlistsMap.remove(wrapper.info.packageName);
                }
            }
        }

        private void replaceBlocklists(AppBlockingPackageInfoWrapper[] blocklists) {
            mBlocklistsMap.clear();
            addToBlocklists(blocklists);
        }

        private void addToBlocklists(AppBlockingPackageInfoWrapper[] blocklists) {
            if (blocklists == null) {
                return;
            }
            for (AppBlockingPackageInfoWrapper wrapper : blocklists) {
                if (wrapper != null) {
                    mBlocklistsMap.put(wrapper.info.packageName, wrapper);
                }
            }
        }

        private void removeBlocklists(AppBlockingPackageInfoWrapper[] blocklists) {
            if (blocklists == null) {
                return;
            }
            for (AppBlockingPackageInfoWrapper wrapper : blocklists) {
                if (wrapper != null) {
                    mBlocklistsMap.remove(wrapper.info.packageName);
                }
            }
        }
    }

    private class ActivityLaunchListener
            implements SystemActivityMonitoringService.ActivityLaunchListener {
        @Override
        public void onActivityLaunch(TopTaskInfoContainer topTask) {
            if (topTask == null) {
                Slog.e(TAG, "Received callback with null top task.");
                return;
            }
            blockTopActivityIfNecessary(topTask);
        }
    }

    /**
     * Listens to the UX restrictions from {@link CarUxRestrictionsManagerService} and initiates
     * checking if the foreground Activity should be blocked.
     */
    private class UxRestrictionsListener extends ICarUxRestrictionsChangeListener.Stub {
        @GuardedBy("mLock")
        @Nullable
        private CarUxRestrictions mCurrentUxRestrictions;
        private final CarUxRestrictionsManagerService uxRestrictionsService;

        public UxRestrictionsListener(CarUxRestrictionsManagerService service) {
            uxRestrictionsService = service;
        }

        @Override
        public void onUxRestrictionsChanged(CarUxRestrictions restrictions) {
            if (Log.isLoggable(TAG, Log.DEBUG)) {
                Slog.d(TAG, "Received uxr restrictions: "
                        + restrictions.isRequiresDistractionOptimization() + " : "
                        + restrictions.getActiveRestrictions());
            }

            synchronized (mLock) {
                mCurrentUxRestrictions = new CarUxRestrictions(restrictions);
            }
            checkIfTopActivityNeedsBlocking();
        }

        private void checkIfTopActivityNeedsBlocking() {
            boolean shouldCheck = false;
            synchronized (mLock) {
                if (mCurrentUxRestrictions != null
                        && mCurrentUxRestrictions.isRequiresDistractionOptimization()) {
                    shouldCheck = true;
                }
            }
            if (Log.isLoggable(TAG, Log.DEBUG)) {
                Slog.d(TAG, "Should check top tasks?: " + shouldCheck);
            }
            if (shouldCheck) {
                // Loop over all top tasks to ensure tasks on virtual display can also be blocked.
                blockTopActivitiesIfNecessary();
            }
        }

        private boolean isRestricted() {
            // if current restrictions is null, try querying the service, once.
            synchronized (mLock) {
                if (mCurrentUxRestrictions == null) {
                    mCurrentUxRestrictions = uxRestrictionsService.getCurrentUxRestrictions();
                }
                if (mCurrentUxRestrictions != null) {
                    return mCurrentUxRestrictions.isRequiresDistractionOptimization();
                }
            }

            // If restriction information is still not available (could happen during bootup),
            // return not restricted.  This maintains parity with previous implementation but needs
            // a revisit as we test more.
            return false;
        }
    }

    /**
     * Called when a window change event is received by the {@link CarSafetyAccessibilityService}.
     */
    @VisibleForTesting
    void onWindowChangeEvent() {
        Slogf.d(TAG, "onWindowChange event received");
        mHandlerThread.getThreadHandler().post(() -> blockTopActivitiesIfNecessary());
    }

    /**
     * Listens to the package install/uninstall events to know when to initiate parsing
     * installed packages.
     */
    private class PackageParsingEventReceiver extends BroadcastReceiver {
        @Override
        public void onReceive(Context context, Intent intent) {
            if (intent == null || intent.getAction() == null) {
                return;
            }
            if (Log.isLoggable(TAG, Log.DEBUG)) {
                Slog.d(TAG, "PackageParsingEventReceiver Received " + intent.getAction());
            }
            String action = intent.getAction();
            if (isPackageManagerAction(action)) {
                // send a delayed message so if we received multiple related intents, we parse
                // only once.
                logEventChange(intent);
                String packageName = getPackageName(intent);
                mHandler.requestParsingInstalledPkg(packageName);
            }
        }

        private String getPackageName(Intent intent) {
            // For mPackageManagerActions, data should contain package name.
            String dataString = intent.getDataString();
            if (dataString == null) return null;

            String scheme = intent.getScheme();
            if (!scheme.equals("package")) return null;

            String[] splitData = intent.getDataString().split(":");
            if (splitData.length < 2) return null;

            return splitData[1];
        }

        private boolean isPackageManagerAction(String action) {
            return mPackageManagerActions.contains(action);
        }

        /**
         * Convenience log function to log what changed.  Logs only when more debug logs
         * are needed - DBG_POLICY_CHECK needs to be true
         */
        private void logEventChange(Intent intent) {
            if (intent == null) {
                return;
            }
            if (Log.isLoggable(TAG, Log.DEBUG)) {
                String packageName = intent.getData().getSchemeSpecificPart();
                Slog.d(TAG, "Pkg Changed:" + packageName);
                String action = intent.getAction();
                if (action == null) {
                    return;
                }
                if (action.equals(Intent.ACTION_PACKAGE_CHANGED)) {
                    Slog.d(TAG, "Changed components");
                    String[] cc = intent
                            .getStringArrayExtra(Intent.EXTRA_CHANGED_COMPONENT_NAME_LIST);
                    if (cc != null) {
                        for (String c : cc) {
                            Slog.d(TAG, c);
                        }
                    }
                } else if (action.equals(Intent.ACTION_PACKAGE_REMOVED)
                        || action.equals(Intent.ACTION_PACKAGE_ADDED)) {
                    Slog.d(TAG, action + " Replacing?: "
                            + intent.getBooleanExtra(Intent.EXTRA_REPLACING, false));
                }
            }
        }
    }
}

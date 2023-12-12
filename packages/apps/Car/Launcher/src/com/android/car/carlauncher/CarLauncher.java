/*
 * Copyright (C) 2018 The Android Open Source Project
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

package com.android.car.carlauncher;

import static android.app.ActivityTaskManager.INVALID_TASK_ID;
import static android.car.user.CarUserManager.USER_LIFECYCLE_EVENT_TYPE_SWITCHING;
import static android.view.WindowManager.LayoutParams.PRIVATE_FLAG_TRUSTED_OVERLAY;

import android.app.ActivityManager;
import android.app.ActivityOptions;
import android.app.ActivityTaskManager;
import android.app.PendingIntent;
import android.app.TaskInfo;
import android.app.TaskStackListener;
import android.car.Car;
import android.car.user.CarUserManager;
import android.car.user.CarUserManager.UserLifecycleListener;
import android.content.ActivityNotFoundException;
import android.content.ComponentName;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.util.Log;
import android.view.Display;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.window.TaskAppearedInfo;

import androidx.annotation.NonNull;
import androidx.collection.ArraySet;
import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentTransaction;
import androidx.lifecycle.ViewModelProvider;

import com.android.car.carlauncher.homescreen.HomeCardModule;
import com.android.car.carlauncher.homescreen.MapsHealthMonitor;
import com.android.car.carlauncher.taskstack.TaskStackChangeListeners;
import com.android.car.internal.common.UserHelperLite;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.TaskView;
import com.android.wm.shell.common.HandlerExecutor;

import java.util.List;
import java.util.Set;

/**
 * Basic Launcher for Android Automotive which demonstrates the use of {@link TaskView} to host
 * maps content and uses a Model-View-Presenter structure to display content in cards.
 *
 * <p>Implementations of the Launcher that use the given layout of the main activity
 * (car_launcher.xml) can customize the home screen cards by providing their own
 * {@link HomeCardModule} for R.id.top_card or R.id.bottom_card. Otherwise, implementations that
 * use their own layout should define their own activity rather than using this one.
 *
 * <p>Note: On some devices, the TaskView may render with a width, height, and/or aspect
 * ratio that does not meet Android compatibility definitions. Developers should work with content
 * owners to ensure content renders correctly when extending or emulating this class.
 */
public class CarLauncher extends FragmentActivity {
    public static final String TAG = "CarLauncher";
    private static final boolean DEBUG = false;

    private ActivityManager mActivityManager;
    private CarUserManager mCarUserManager;
    private ShellTaskOrganizer mShellTaskOrganizer;
    private TaskViewManager mTaskViewManager;

    private TaskView mTaskView;
    private boolean mTaskViewReady;
    // Tracking this to check if the task in TaskView has crashed in the background.
    private int mTaskViewTaskId = INVALID_TASK_ID;
    private int mCarLauncherTaskId = INVALID_TASK_ID;
    private Set<HomeCardModule> mHomeCardModules;

    /** Set to {@code true} once we've logged that the Activity is fully drawn. */
    private boolean mIsReadyLogged;

    private boolean mUseSmallCanvasOptimizedMap;

    // The callback methods in {@code mTaskViewListener} are running under MainThread.
    private final TaskView.Listener mTaskViewListener = new TaskView.Listener() {
        @Override
        public void onInitialized() {
            if (DEBUG) Log.d(TAG, "onInitialized(" + getUserId() + ")");
            mTaskViewReady = true;
            startMapsInTaskView();
            maybeLogReady();
        }

        @Override
        public void onReleased() {
            if (DEBUG) Log.d(TAG, "onReleased(" + getUserId() + ")");
            mTaskViewReady = false;
        }

        @Override
        public void onTaskCreated(int taskId, ComponentName name) {
            if (DEBUG) Log.d(TAG, "onTaskCreated: taskId=" + taskId);
            mTaskViewTaskId = taskId;
            if (isResumed()) {
                maybeBringEmbeddedTaskToForeground();
            }
        }

        @Override
        public void onTaskRemovalStarted(int taskId) {
            if (DEBUG) Log.d(TAG, "onTaskRemovalStarted: taskId=" + taskId);
            mTaskViewTaskId = INVALID_TASK_ID;
            // Don't restart the crashed Maps automatically, because it hinders lots of MultiXXX
            // CTS tests which cleans up all tasks but Home, then monitor Activity state
            // changes. If it restarts Maps, which causes unexpected Activity state changes.
        }
    };

    private final TaskStackListener mTaskStackListener = new TaskStackListener() {
        @Override
        public void onTaskFocusChanged(int taskId, boolean focused) {
            boolean launcherFocused = taskId == mCarLauncherTaskId && focused;
            if (DEBUG) {
                Log.d(TAG, "onTaskFocusChanged: taskId=" + taskId
                        + ", launcherFocused=" + launcherFocused
                        + ", mTaskViewTaskId=" + mTaskViewTaskId);
            }
            if (!launcherFocused) {
                return;
            }
            if (mTaskViewTaskId == INVALID_TASK_ID) {
                // If the task in TaskView is crashed during CarLauncher is background,
                // We'd like to restart it when CarLauncher becomes foreground and focused.
                startMapsInTaskView();
            }
        }

        @Override
        public void onActivityRestartAttempt(ActivityManager.RunningTaskInfo task,
                boolean homeTaskVisible, boolean clearedTask, boolean wasVisible) {
            if (DEBUG) {
                Log.d(TAG, "onActivityRestartAttempt: taskId=" + task.taskId
                        + ", homeTaskVisible=" + homeTaskVisible + ", wasVisible=" + wasVisible);
            }
            if (!mUseSmallCanvasOptimizedMap
                    && !homeTaskVisible
                    && mTaskViewTaskId == task.taskId) {
                // The embedded map component received an intent, therefore forcibly bringing the
                // launcher to the foreground.
                bringToForeground();
                return;
            }
            if (homeTaskVisible && mCarLauncherTaskId == task.taskId
                    && mTaskViewTaskId == INVALID_TASK_ID) {
                // Interprets Home Intent while CarLauncher is foreground and Maps is crashed
                // as restarting Maps.
                startMapsInTaskView();
            }
        }
    };

    private final UserLifecycleListener mUserLifecyleListener = new UserLifecycleListener() {
        @Override
        public void onEvent(@NonNull CarUserManager.UserLifecycleEvent event) {
            if (event.getEventType() == USER_LIFECYCLE_EVENT_TYPE_SWITCHING) {
                // When user-switching, onDestroy in the previous user's CarLauncher isn't called.
                // So tries to release the resource explicitly.
                release();
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        if (CarLauncherUtils.isCustomDisplayPolicyDefined(this)) {
            Intent controlBarIntent = new Intent(this, ControlBarActivity.class);
            controlBarIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            startActivity(controlBarIntent);
            startActivity(
                    CarLauncherUtils.getMapsIntent(this).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK));
            // Register health check monitor for maps.
            MapsHealthMonitor.getInstance(this).register();
            finish();
            return;
        }

        mUseSmallCanvasOptimizedMap =
                CarLauncherUtils.isSmallCanvasOptimizedMapIntentConfigured(this);

        Car.createCar(getApplicationContext(), /* handler= */ null,
                Car.CAR_WAIT_TIMEOUT_WAIT_FOREVER,
                (car, ready) -> {
                    if (!ready) return;
                    mCarUserManager = (CarUserManager) car.getCarManager(Car.CAR_USER_SERVICE);
                    mCarUserManager.addListener(getMainExecutor(), mUserLifecyleListener);
                });

        mActivityManager = getSystemService(ActivityManager.class);
        mCarLauncherTaskId = getTaskId();
        TaskStackChangeListeners.getInstance().registerTaskStackListener(mTaskStackListener);

        // Setting as trusted overlay to let touches pass through.
        getWindow().addPrivateFlags(PRIVATE_FLAG_TRUSTED_OVERLAY);
        // To pass touches to the underneath task.
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL);

        // Don't show the maps panel in multi window mode.
        // NOTE: CTS tests for split screen are not compatible with activity views on the default
        // activity of the launcher
        if (isInMultiWindowMode() || isInPictureInPictureMode()) {
            setContentView(R.layout.car_launcher_multiwindow);
        } else {
            setContentView(R.layout.car_launcher);
            // We don't want to show Map card unnecessarily for the headless user 0.
            if (!UserHelperLite.isHeadlessSystemUser(getUserId())) {
                ViewGroup mapsCard = findViewById(R.id.maps_card);
                if (mapsCard != null) {
                    setUpTaskView(mapsCard);
                }
            }
        }
        initializeCards();
    }

    private static void cleanUpExistingTaskViewTasks(List<TaskAppearedInfo> taskAppearedInfos) {
        ActivityTaskManager atm = ActivityTaskManager.getInstance();
        for (TaskAppearedInfo taskAppearedInfo : taskAppearedInfos) {
            TaskInfo taskInfo = taskAppearedInfo.getTaskInfo();
            try {
                atm.removeTask(taskInfo.taskId);
            } catch (Exception e) {
                if (DEBUG) {
                    Log.d(TAG, "failed to remove task likely b/c it no longer exists " + taskInfo);
                }
            }
        }
    }

    private void setUpTaskView(ViewGroup parent) {
        mTaskViewManager = new TaskViewManager(this,
                new HandlerExecutor(getMainThreadHandler()));
        mTaskViewManager.createTaskView(taskView -> {
            taskView.setListener(getMainExecutor(), mTaskViewListener);
            parent.addView(taskView);
            mTaskView = taskView;
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        maybeLogReady();
        if (DEBUG) {
            Log.d(TAG, "onResume: mTaskViewTaskId=" + mTaskViewTaskId);
        }
    }

    @Override
    public void onTopResumedActivityChanged(boolean isTopResumed) {
        super.onTopResumedActivityChanged(isTopResumed);
        if (DEBUG) {
            Log.d(TAG, "onTopResumedActivityChanged: isTopResumed=" + isTopResumed);
        }
        if (!isTopResumed) {
            return;
        }
        maybeBringEmbeddedTaskToForeground();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        TaskStackChangeListeners.getInstance().unregisterTaskStackListener(mTaskStackListener);
        release();
    }

    private void release() {
        if (mTaskView != null && mTaskViewReady) {
            mTaskView.release();
            mTaskView = null;
        }
        if (mTaskViewManager != null) {
            mTaskViewManager.release();
        }
    }

    private void startMapsInTaskView() {
        if (mTaskView == null || !mTaskViewReady) {
            return;
        }
        // If we happen to be be resurfaced into a multi display mode we skip launching content
        // in the activity view as we will get recreated anyway.
        if (isInMultiWindowMode() || isInPictureInPictureMode()) {
            return;
        }
        // Don't start Maps when the display is off for ActivityVisibilityTests.
        if (getDisplay().getState() != Display.STATE_ON) {
            return;
        }
        try {
            ActivityOptions options = ActivityOptions.makeCustomAnimation(this,
                    /* enterResId= */ 0, /* exitResId= */ 0);
            Intent mapIntent = mUseSmallCanvasOptimizedMap
                    ? CarLauncherUtils.getSmallCanvasOptimizedMapIntent(this)
                    : CarLauncherUtils.getMapsIntent(this);
            mTaskView.startActivity(
                    PendingIntent.getActivity(this, /* requestCode= */ 0,
                            mapIntent,
                            PendingIntent.FLAG_IMMUTABLE | PendingIntent.FLAG_UPDATE_CURRENT),
                    /* fillInIntent= */ null, options, null /* launchBounds */);
        } catch (ActivityNotFoundException e) {
            Log.w(TAG, "Maps activity not found", e);
        }
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        if (CarLauncherUtils.isCustomDisplayPolicyDefined(this)) {
            return;
        }
        initializeCards();
    }

    private void initializeCards() {
        if (mHomeCardModules == null) {
            mHomeCardModules = new ArraySet<>();
            for (String providerClassName : getResources().getStringArray(
                    R.array.config_homeCardModuleClasses)) {
                try {
                    long reflectionStartTime = System.currentTimeMillis();
                    HomeCardModule cardModule = (HomeCardModule) Class.forName(
                            providerClassName).newInstance();
                    cardModule.setViewModelProvider(new ViewModelProvider( /* owner= */this));
                    mHomeCardModules.add(cardModule);
                    if (DEBUG) {
                        long reflectionTime = System.currentTimeMillis() - reflectionStartTime;
                        Log.d(TAG, "Initialization of HomeCardModule class " + providerClassName
                                + " took " + reflectionTime + " ms");
                    }
                } catch (IllegalAccessException | InstantiationException |
                        ClassNotFoundException e) {
                    Log.w(TAG, "Unable to create HomeCardProvider class " + providerClassName, e);
                }
            }
        }
        FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
        for (HomeCardModule cardModule : mHomeCardModules) {
            transaction.replace(cardModule.getCardResId(), cardModule.getCardView());
        }
        transaction.commitNow();
    }

    /** Logs that the Activity is ready. Used for startup time diagnostics. */
    private void maybeLogReady() {
        boolean isResumed = isResumed();
        if (DEBUG) {
            Log.d(TAG, "maybeLogReady(" + getUserId() + "): activityReady=" + mTaskViewReady
                    + ", started=" + isResumed + ", alreadyLogged: " + mIsReadyLogged);
        }
        if (mTaskViewReady && isResumed) {
            // We should report every time - the Android framework will take care of logging just
            // when it's effectively drawn for the first time, but....
            reportFullyDrawn();
            if (!mIsReadyLogged) {
                // ... we want to manually check that the Log.i below (which is useful to show
                // the user id) is only logged once (otherwise it would be logged every time the
                // user taps Home)
                Log.i(TAG, "Launcher for user " + getUserId() + " is ready");
                mIsReadyLogged = true;
            }
        }
    }

    /** Brings embedded task to front, if the task view is created and the task is launched. */
    private void maybeBringEmbeddedTaskToForeground() {
        if (mTaskViewTaskId != INVALID_TASK_ID) {
            // The task in TaskView should be in top to make it visible.
            // NOTE: Tried setTaskAlwaysOnTop before, the flag has some side effect to hinder
            // AccessibilityService from finding the correct window geometry: b/197247311
            mActivityManager.moveTaskToFront(mTaskViewTaskId, /* flags= */ 0);
        }
    }

    /** Brings the Car Launcher to the foreground. */
    private void bringToForeground() {
        if (mCarLauncherTaskId != INVALID_TASK_ID) {
            mActivityManager.moveTaskToFront(mCarLauncherTaskId,  /* flags= */ 0);
        }
    }
}

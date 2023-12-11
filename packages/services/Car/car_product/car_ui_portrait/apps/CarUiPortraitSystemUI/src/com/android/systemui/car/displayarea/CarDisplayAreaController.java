/*
 * Copyright (C) 2022 The Android Open Source Project
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

package com.android.systemui.car.displayarea;

import static android.window.DisplayAreaOrganizer.FEATURE_DEFAULT_TASK_CONTAINER;
import static android.window.DisplayAreaOrganizer.FEATURE_IME_PLACEHOLDER;
import static android.window.DisplayAreaOrganizer.FEATURE_ROOT;
import static android.window.DisplayAreaOrganizer.FEATURE_UNDEFINED;
import static android.window.DisplayAreaOrganizer.KEY_ROOT_DISPLAY_AREA_ID;

import static com.android.systemui.car.displayarea.CarDisplayAreaOrganizer.BACKGROUND_TASK_CONTAINER;
import static com.android.systemui.car.displayarea.CarDisplayAreaOrganizer.CONTROL_BAR_DISPLAY_AREA;
import static com.android.systemui.car.displayarea.CarDisplayAreaOrganizer.FEATURE_TITLE_BAR;
import static com.android.systemui.car.displayarea.CarDisplayAreaOrganizer.FEATURE_VOICE_PLATE;
import static com.android.systemui.car.displayarea.CarDisplayAreaOrganizer.FOREGROUND_DISPLAY_AREA_ROOT;
import static com.android.systemui.car.displayarea.CarFullscreenTaskListener.MAPS;
import static com.android.systemui.car.displayarea.DisplayAreaComponent.DISPLAY_AREA_VISIBILITY_CHANGED;
import static com.android.systemui.car.displayarea.DisplayAreaComponent.FOREGROUND_DA_STATE.CONTROL_BAR;
import static com.android.systemui.car.displayarea.DisplayAreaComponent.FOREGROUND_DA_STATE.DEFAULT;
import static com.android.systemui.car.displayarea.DisplayAreaComponent.INTENT_EXTRA_IS_DISPLAY_AREA_VISIBLE;
import static com.android.wm.shell.ShellTaskOrganizer.TASK_LISTENER_TYPE_FULLSCREEN;

import android.app.ActivityManager;
import android.app.ActivityTaskManager;
import android.app.TaskStackListener;
import android.app.UiModeManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.graphics.PixelFormat;
import android.graphics.Rect;
import android.os.Binder;
import android.os.Build;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.ArraySet;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Display;
import android.view.Gravity;
import android.view.IWindowManager;
import android.view.LayoutInflater;
import android.view.SurfaceControl;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowInsets;
import android.view.WindowManager;
import android.view.WindowManagerGlobal;
import android.window.DisplayAreaAppearedInfo;
import android.window.DisplayAreaInfo;
import android.window.WindowContainerToken;
import android.window.WindowContainerTransaction;

import androidx.annotation.Nullable;
import androidx.localbroadcastmanager.content.LocalBroadcastManager;

import com.android.internal.app.AssistUtils;
import com.android.systemui.R;
import com.android.systemui.qs.QSHost;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.common.HandlerExecutor;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

import javax.inject.Inject;

/**
 * Controls the bounds of the home background, audio bar and application displays. This is a
 * singleton class as there should be one controller used to register and control the DA's
 */
public class CarDisplayAreaController implements ConfigurationController.ConfigurationListener {

    // Layer index of how display areas should be placed. Keeping a gap of 100 if we want to
    // add some other display area layers in between in the future.
    static final int FOREGROUND_LAYER_INDEX = 0;
    static final int BACKGROUND_LAYER_INDEX = 100;
    static final int CONTROL_BAR_LAYER_INDEX = 200;
    static final int VOICE_PLATE_LAYER_SHOWN_INDEX = 300;
    private static final String TAG = "CarDisplayAreaController";
    private static final boolean DEBUG = Build.IS_DEBUGGABLE;
    private static final int TITLE_BAR_WINDOW_TYPE =
            WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;

    private final Rect mControlBarDisplayBounds = new Rect();
    private final Rect mForegroundApplicationDisplayBounds = new Rect();
    private final Rect mTitleBarDisplayBounds = new Rect();
    private final Rect mVoicePlateDisplayBounds = new Rect();
    private final Rect mBackgroundApplicationDisplayBounds = new Rect();
    private final Rect mNavBarBounds = new Rect();
    private final IBinder mWindowToken = new Binder();

    private final SyncTransactionQueue mSyncQueue;
    private final CarDisplayAreaOrganizer mOrganizer;
    private final CarFullscreenTaskListener mCarFullscreenTaskListener;
    private final String mControlBarActivityComponent;
    private final HashMap<String, Boolean> mForegroundDAComponentsVisibilityMap;
    private final ArraySet<ComponentName> mIgnoreOpeningForegroundDAComponentsSet;
    private final int mTitleBarDragThreshold;
    private final ShellExecutor mShellExecutor;
    private final int mEnterExitAnimationDurationMs;
    // height of DA hosting the control bar.
    private final int mControlBarDisplayHeight;
    private final ComponentName mAssistantVoicePlateActivityName;
    private final int mDpiDensity;
    private final int mTotalScreenWidth;
    // height of DA hosting default apps and covering the maps fully.
    private final int mFullDisplayHeight;
    // height of DA hosting default apps and covering the maps to default height.
    private final int mDefaultDisplayHeight;
    private final int mTitleBarHeight;
    private final int mScreenHeightWithoutNavBar;
    private final int mTotalScreenHeight;
    private final CarDisplayAreaTouchHandler mCarDisplayAreaTouchHandler;
    private final Context mApplicationContext;
    private final int mForegroundDisplayTop;
    private final AssistUtils mAssistUtils;
    private HashSet<Integer> mActiveTasksOnForegroundDA;
    private final ConfigurationController mConfigurationController;
    private final UiModeManager mUiModeManager;
    private DisplayAreaAppearedInfo mForegroundApplicationsDisplay;
    private DisplayAreaAppearedInfo mTitleBarDisplay;
    private DisplayAreaAppearedInfo mVoicePlateDisplay;
    private DisplayAreaAppearedInfo mBackgroundApplicationDisplay;
    private DisplayAreaAppearedInfo mControlBarDisplay;
    private DisplayAreaAppearedInfo mImeContainerDisplayArea;
    private boolean mIsHostingDefaultApplicationDisplayAreaVisible;
    private WindowManager mTitleBarWindowManager;
    private View mTitleBarView;
    private boolean mIsForegroundDaVisible = false;
    private final TaskStackListener mOnActivityRestartAttemptListener = new TaskStackListener() {
        @Override
        public void onActivityRestartAttempt(ActivityManager.RunningTaskInfo task,
                boolean homeTaskVisible, boolean clearedTask, boolean wasVisible)
                throws RemoteException {
            super.onActivityRestartAttempt(task, homeTaskVisible, clearedTask, wasVisible);
            updateForegroundDaVisibility(task.topActivity, -1);
        }

        @Override
        public void onTaskMovedToFront(ActivityManager.RunningTaskInfo taskInfo)
                throws RemoteException {
            super.onTaskMovedToFront(taskInfo);
            updateForegroundDaVisibility(taskInfo.topActivityInfo.getComponentName(),
                    taskInfo.taskId);
        }

        @Override
        public void onTaskRemoved(int taskId) throws RemoteException {
            super.onTaskRemoved(taskId);
            if (mActiveTasksOnForegroundDA == null) {
                return;
            }
            mActiveTasksOnForegroundDA.remove(taskId);
            if (mActiveTasksOnForegroundDA.isEmpty()) {
                logIfDebuggable("onTaskRemoved: no more tasks left in foreground DA ");
                startAnimation(CONTROL_BAR);
            }
        }
    };
    private boolean mIsUiModeNight = false;
    /**
     * The WindowContext that is registered with {@link #mTitleBarWindowManager} with options to
     * specify the {@link RootDisplayArea} to attach the confirmation window.
     */
    @Nullable
    private Context mTitleBarWindowContext;

    /**
     * Initializes the controller
     */
    @Inject
    public CarDisplayAreaController(Context applicationContext, SyncTransactionQueue syncQueue,
            CarFullscreenTaskListener carFullscreenTaskListener,
            ShellExecutor shellExecutor,
            ConfigurationController configurationController,
            QSHost host,
            CarDisplayAreaOrganizer organizer) {
        mApplicationContext = applicationContext;
        mSyncQueue = syncQueue;
        mOrganizer = organizer;
        mShellExecutor = shellExecutor;
        mCarFullscreenTaskListener = carFullscreenTaskListener;
        mConfigurationController = configurationController;
        mUiModeManager = host.getUserContext().getSystemService(UiModeManager.class);
        mConfigurationController.addCallback(this);
        mDpiDensity = mOrganizer.getDpiDensity();
        mTotalScreenHeight = applicationContext.getResources().getDimensionPixelSize(
                R.dimen.total_screen_height);
        mTotalScreenWidth = applicationContext.getResources().getDimensionPixelSize(
                R.dimen.total_screen_width);
        mControlBarDisplayHeight = applicationContext.getResources().getDimensionPixelSize(
                R.dimen.control_bar_height);
        mFullDisplayHeight = applicationContext.getResources().getDimensionPixelSize(
                R.dimen.full_app_display_area_height);
        mDefaultDisplayHeight = applicationContext.getResources().getDimensionPixelSize(
                R.dimen.default_app_display_area_height);
        mCarDisplayAreaTouchHandler = new CarDisplayAreaTouchHandler(
                new HandlerExecutor(applicationContext.getMainThreadHandler()));
        mControlBarActivityComponent = applicationContext.getResources().getString(
                R.string.config_controlBarActivity);
        mAssistantVoicePlateActivityName = ComponentName.unflattenFromString(
                applicationContext.getResources().getString(
                        R.string.config_assistantVoicePlateActivity));
        mAssistUtils = new AssistUtils(applicationContext);

        // Get bottom nav bar height.
        Resources resources = applicationContext.getResources();
        int navBarHeight = resources.getDimensionPixelSize(
                com.android.internal.R.dimen.navigation_bar_height);
        if (navBarHeight > 0) {
            mNavBarBounds.set(0, mTotalScreenHeight - navBarHeight, mTotalScreenWidth,
                    mTotalScreenHeight);
        }

        // Get left nav bar width.
        int leftNavBarWidthResId = resources
                .getIdentifier("car_left_system_bar_width", "dimen", "android");
        int leftNavBarWidth = 0;
        if (leftNavBarWidthResId > 0) {
            leftNavBarWidth = resources.getDimensionPixelSize(leftNavBarWidthResId);
            mNavBarBounds.set(0, 0, leftNavBarWidth, mTotalScreenHeight);
        }

        // Get right nav bar width.
        int rightNavBarWidthResId = resources
                .getIdentifier("car_right_system_bar_width", "dimen", "android");
        int rightNavBarWidth = 0;
        if (rightNavBarWidthResId > 0) {
            rightNavBarWidth = resources.getDimensionPixelSize(rightNavBarWidthResId);
            mNavBarBounds.set(mTotalScreenWidth - rightNavBarWidth, 0, mTotalScreenWidth,
                    mTotalScreenHeight);
        }

        mScreenHeightWithoutNavBar = mTotalScreenHeight - mNavBarBounds.height();
        mTitleBarHeight = resources.getDimensionPixelSize(R.dimen.title_bar_display_area_height);
        mEnterExitAnimationDurationMs = applicationContext.getResources().getInteger(
                R.integer.enter_exit_animation_foreground_display_area_duration_ms);
        mTitleBarDragThreshold = applicationContext.getResources().getDimensionPixelSize(
                R.dimen.title_bar_display_area_touch_drag_threshold);
        mForegroundDisplayTop = mScreenHeightWithoutNavBar - mDefaultDisplayHeight;

        mForegroundDAComponentsVisibilityMap = new HashMap<>();
        for (String component : mApplicationContext.getResources().getStringArray(
                R.array.config_foregroundDAComponents)) {
            mForegroundDAComponentsVisibilityMap.put(component, false);
        }

        String[] ignoreOpeningForegroundDACmp = mApplicationContext.getResources().getStringArray(
                R.array.config_ignoreOpeningForegroundDA);
        mIgnoreOpeningForegroundDAComponentsSet = new ArraySet<>();
        for (String component : ignoreOpeningForegroundDACmp) {
            ComponentName componentName = ComponentName.unflattenFromString(component);
            mIgnoreOpeningForegroundDAComponentsSet.add(componentName);
        }
    }

    /**
     * Returns options that specify the {@link RootDisplayArea} to attach the confirmation window.
     * {@code null} if the {@code rootDisplayAreaId} is {@link FEATURE_UNDEFINED}.
     */
    @Nullable
    private static Bundle getOptionWithRootDisplayArea(int rootDisplayAreaId) {
        // In case we don't care which root display area the window manager is specifying.
        if (rootDisplayAreaId == FEATURE_UNDEFINED) {
            return null;
        }

        Bundle options = new Bundle();
        options.putInt(KEY_ROOT_DISPLAY_AREA_ID, rootDisplayAreaId);
        return options;
    }

    private static void logIfDebuggable(String message) {
        if (DEBUG) {
            Log.d(TAG, message);
        }
    }

    boolean shouldIgnoreOpeningForegroundDA(ActivityManager.RunningTaskInfo taskInfo) {
        return taskInfo.baseIntent != null && mIgnoreOpeningForegroundDAComponentsSet.contains(
                taskInfo.baseIntent.getComponent());
    }

    /**
     * Show the title bar within a targeted display area using the rootDisplayAreaId.
     */
    void showTitleBar() {
        if (mTitleBarView != null) {
            mTitleBarView.setVisibility(View.VISIBLE);
            return;
        }

        hideTitleBar();
        createTitleBar();
    }

    private void createTitleBar() {
        LayoutInflater inflater = LayoutInflater.from(mApplicationContext);
        mTitleBarView = inflater.inflate(R.layout.title_bar_display_area_view, null, true);
        mTitleBarView.setVisibility(View.VISIBLE);

        // Show the confirmation.
        WindowManager.LayoutParams lp = getTitleBarWindowLayoutParams();
        getWindowManager().addView(mTitleBarView, lp);
    }

    private WindowManager getWindowManager() {
        Bundle options = getOptionWithRootDisplayArea(FOREGROUND_DISPLAY_AREA_ROOT);
        if (mTitleBarWindowManager == null || mTitleBarWindowContext == null) {
            // Create window context to specify the RootDisplayArea
            mTitleBarWindowContext = mApplicationContext.createWindowContext(
                    TITLE_BAR_WINDOW_TYPE, options);
            mTitleBarWindowManager = mTitleBarWindowContext.getSystemService(WindowManager.class);
            return mTitleBarWindowManager;
        }

        // Update the window context and window manager to specify the RootDisplayArea
        IWindowManager wms = WindowManagerGlobal.getWindowManagerService();
        try {
            wms.attachWindowContextToDisplayArea(mTitleBarWindowContext.getWindowContextToken(),
                    TITLE_BAR_WINDOW_TYPE, mApplicationContext.getDisplayId(), options);
        } catch (RemoteException e) {
            throw e.rethrowAsRuntimeException();
        }

        return mTitleBarWindowManager;
    }

    /**
     * Hide the title bar view
     */
    public void hideTitleBar() {
        if (mTitleBarView != null) {
            mTitleBarView.setVisibility(View.INVISIBLE);
        }
    }

    /**
     * Remove the title bar view
     */
    public void removeTitleBar() {
        if (mTitleBarView != null) {
            mTitleBarWindowManager.removeView(mTitleBarView);
        }
    }

    private WindowManager.LayoutParams getTitleBarWindowLayoutParams() {
        WindowManager.LayoutParams lp = new WindowManager.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                mTitleBarHeight,
                TITLE_BAR_WINDOW_TYPE,
                WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN
                        | WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED
                        | WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL
                        | WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE,
                PixelFormat.TRANSLUCENT);
        lp.setFitInsetsTypes(lp.getFitInsetsTypes() & ~WindowInsets.Type.statusBars());
        // Trusted overlay so touches outside the touchable area are allowed to pass through
        lp.privateFlags |= WindowManager.LayoutParams.SYSTEM_FLAG_SHOW_FOR_ALL_USERS
                | WindowManager.LayoutParams.PRIVATE_FLAG_TRUSTED_OVERLAY;
        lp.setTitle("TitleBar");
        lp.gravity = Gravity.TOP;
        lp.token = mWindowToken;
        return lp;
    }

    /**
     * Returns if display area hosting default application is visible to user or not.
     */
    public boolean isHostingDefaultApplicationDisplayAreaVisible() {
        return mIsHostingDefaultApplicationDisplayAreaVisible;
    }

    boolean isDisplayAreaAnimating() {
        return mOrganizer != null && mOrganizer.isDisplayAreaAnimating();
    }

    /** Registers the DA organizer. */
    public void register() {
        // add CarFullscreenTaskListener to control the foreground DA when the task appears.
        mCarFullscreenTaskListener.registerOnTaskChangeListener(
                new CarFullscreenTaskListener.OnTaskChangeListener() {
                    @Override
                    public void onTaskAppeared(ActivityManager.RunningTaskInfo taskInfo) {
                        if (taskInfo.displayAreaFeatureId == FEATURE_VOICE_PLATE) {
                            showVoicePlateDisplayArea();
                            return;
                        }

                        if (taskInfo.displayAreaFeatureId == FEATURE_DEFAULT_TASK_CONTAINER
                                && taskInfo.isVisible()
                                && !shouldIgnoreOpeningForegroundDA(taskInfo)) {
                            if (!isHostingDefaultApplicationDisplayAreaVisible()) {
                                logIfDebuggable("opening DA on request for: " + taskInfo);
                                startAnimation(DEFAULT);
                            }
                        }
                    }

                    @Override
                    public void onTaskVanished(ActivityManager.RunningTaskInfo taskInfo) {
                        if (taskInfo.displayAreaFeatureId == FEATURE_VOICE_PLATE) {
                            resetVoicePlateDisplayArea();
                        }
                    }
                });

        ShellTaskOrganizer taskOrganizer = new ShellTaskOrganizer(mShellExecutor,
                mApplicationContext);
        taskOrganizer.addListenerForType(mCarFullscreenTaskListener, TASK_LISTENER_TYPE_FULLSCREEN);

        // Register DA organizer.
        registerOrganizer();

        // Pre-calculate the foreground and background display bounds for different configs.
        setDefaultBounds();

        // show the title bar window
        showTitleBar();

        mCarDisplayAreaTouchHandler.registerOnClickListener((x, y) -> {
            // Check if the click is outside the bounds of default display. If so, close the
            // display area.
            if (mIsHostingDefaultApplicationDisplayAreaVisible
                    && y < (mForegroundDisplayTop)) {
                // TODO: closing logic goes here, something like: startAnimation(CONTROL_BAR);
            }
        });

        mCarDisplayAreaTouchHandler.registerTouchEventListener(
                new CarDisplayAreaTouchHandler.OnDragDisplayAreaListener() {

                    float mCurrentPos = -1;

                    @Override
                    public void onStart(float x, float y) {
                        mCurrentPos = mScreenHeightWithoutNavBar - mDefaultDisplayHeight
                                - mControlBarDisplayHeight;
                    }

                    @Override
                    public void onMove(float x, float y) {
                        if (y <= mScreenHeightWithoutNavBar - mDefaultDisplayHeight
                                - mControlBarDisplayHeight) {
                            return;
                        }
                        animateToControlBarState((int) mCurrentPos, (int) y, 0);
                        mCurrentPos = y;
                    }

                    @Override
                    public void onFinish(float x, float y) {
                        if (y >= mTitleBarDragThreshold) {
                            animateToControlBarState((int) y,
                                    mScreenHeightWithoutNavBar + mTitleBarHeight, 0);
                            mCarDisplayAreaTouchHandler.updateTitleBarVisibility(false);
                            Intent intent = new Intent(DISPLAY_AREA_VISIBILITY_CHANGED);
                            intent.putExtra(INTENT_EXTRA_IS_DISPLAY_AREA_VISIBLE, false);
                            LocalBroadcastManager.getInstance(mApplicationContext).sendBroadcast(
                                    intent);
                        } else {
                            animateToDefaultState((int) y,
                                    mScreenHeightWithoutNavBar - mDefaultDisplayHeight
                                            - mControlBarDisplayHeight, 0);
                        }
                    }
                });
        mCarDisplayAreaTouchHandler.enable(true);

        ActivityTaskManager.getInstance().registerTaskStackListener(
                mOnActivityRestartAttemptListener);
    }

    @Override
    public void onConfigChanged(Configuration newConfig) {
        int currentNightMode = newConfig.uiMode & Configuration.UI_MODE_NIGHT_MASK;
        if (currentNightMode == Configuration.UI_MODE_NIGHT_YES && !mIsUiModeNight) {
            removeTitleBar();
            mUiModeManager.setNightModeActivated(true);
            createTitleBar();
            mIsUiModeNight = true;
        } else if (currentNightMode == Configuration.UI_MODE_NIGHT_NO && mIsUiModeNight) {
            removeTitleBar();
            mUiModeManager.setNightModeActivated(false);
            createTitleBar();
            mIsUiModeNight = false;
        }
    }

    private void updateForegroundDaVisibility(ComponentName componentName, int taskId) {
        if (componentName == null || isDisplayAreaAnimating()) {
            return;
        }

        String packageName = componentName.getPackageName();
        boolean isMaps = packageName.contains(MAPS);
        boolean ignoreOpeningForegroundDA = mIgnoreOpeningForegroundDAComponentsSet.contains(
                componentName);

        // Voice plate will be shown as the top most layer. Also, we don't want to change the
        // state of the DA's when voice plate is shown.
        boolean isVoicePlate = componentName.equals(mAssistantVoicePlateActivityName);
        if (isVoicePlate) {
            showVoicePlateDisplayArea();
            return;
        }
        if (isMaps) {
            return;
        }

        // Check is there is an existing session running for assist, cancel it.
        if (mAssistUtils.isSessionRunning()) {
            mAssistUtils.hideCurrentSession();
        }

        String name = componentName.flattenToShortString();

        if (isHostingDefaultApplicationDisplayAreaVisible()) {
            if (mForegroundDAComponentsVisibilityMap.containsKey(name)
                    && mForegroundDAComponentsVisibilityMap.get(name)) {
                startAnimation(CONTROL_BAR);
            }
            if (!ignoreOpeningForegroundDA) {
                addTaskToActiveMap(taskId);
            }
        } else if (!ignoreOpeningForegroundDA) {
            logIfDebuggable("opening DA on request for cmp: " + componentName);
            startAnimation(DEFAULT);
            addTaskToActiveMap(taskId);
        }

        if (ignoreOpeningForegroundDA || name.equals(mControlBarActivityComponent)) {
            return;
        }
        mForegroundDAComponentsVisibilityMap.replaceAll((n, v) -> name.equals(n));
    }

    private void addTaskToActiveMap(int taskId) {
        if (mActiveTasksOnForegroundDA == null) {
            mActiveTasksOnForegroundDA = new HashSet<>();
        }
        if (taskId != -1) {
            logIfDebuggable("adding task to foreground DA: " + taskId);
            mActiveTasksOnForegroundDA.add(taskId);
        }
    }

    void showVoicePlateDisplayArea() {
        SurfaceControl.Transaction tx = new SurfaceControl.Transaction();
        // Reset the layer for voice plate. This is needed as when the tasks are launched on
        // other DA's those are brought to the top.
        tx.setLayer(mVoicePlateDisplay.getLeash(), VOICE_PLATE_LAYER_SHOWN_INDEX);
        tx.show(mVoicePlateDisplay.getLeash());
        tx.apply(true);
    }

    void resetVoicePlateDisplayArea() {
        SurfaceControl.Transaction tx = new SurfaceControl.Transaction();
        tx.hide(mVoicePlateDisplay.getLeash());
        tx.apply(true);
    }

    /** Registers DA organizer. */
    private void registerOrganizer() {
        List<DisplayAreaAppearedInfo> foregroundDisplayAreaInfos =
                mOrganizer.registerOrganizer(FOREGROUND_DISPLAY_AREA_ROOT);
        if (foregroundDisplayAreaInfos.size() != 1) {
            throw new IllegalStateException("Can't find display to launch default applications");
        }

        List<DisplayAreaAppearedInfo> titleBarDisplayAreaInfo =
                mOrganizer.registerOrganizer(FEATURE_TITLE_BAR);
        if (titleBarDisplayAreaInfo.size() != 1) {
            throw new IllegalStateException("Can't find display to launch title bar");
        }

        List<DisplayAreaAppearedInfo> voicePlateDisplayAreaInfo =
                mOrganizer.registerOrganizer(FEATURE_VOICE_PLATE);
        if (voicePlateDisplayAreaInfo.size() != 1) {
            throw new IllegalStateException("Can't find display to launch voice plate");
        }

        List<DisplayAreaAppearedInfo> backgroundDisplayAreaInfos =
                mOrganizer.registerOrganizer(BACKGROUND_TASK_CONTAINER);
        if (backgroundDisplayAreaInfos.size() != 1) {
            throw new IllegalStateException("Can't find display to launch activity in background");
        }

        List<DisplayAreaAppearedInfo> controlBarDisplayAreaInfos =
                mOrganizer.registerOrganizer(CONTROL_BAR_DISPLAY_AREA);
        if (controlBarDisplayAreaInfos.size() != 1) {
            throw new IllegalStateException("Can't find display to launch audio control");
        }

        // Get the IME display area attached to the root hierarchy.
        List<DisplayAreaAppearedInfo> imeDisplayAreaInfos =
                mOrganizer.registerOrganizer(FEATURE_IME_PLACEHOLDER);
        for (DisplayAreaAppearedInfo info : imeDisplayAreaInfos) {
            DisplayAreaInfo daInfo = info.getDisplayAreaInfo();
            // Need to check the display for the multi displays platform.
            if (daInfo.rootDisplayAreaId == FEATURE_ROOT
                    && daInfo.displayId == Display.DEFAULT_DISPLAY) {
                mImeContainerDisplayArea = info;
            }
        }
        // As we have only 1 display defined for each display area feature get the 0th index.
        mForegroundApplicationsDisplay = foregroundDisplayAreaInfos.get(0);
        mTitleBarDisplay = titleBarDisplayAreaInfo.get(0);
        mVoicePlateDisplay = voicePlateDisplayAreaInfo.get(0);
        mBackgroundApplicationDisplay = backgroundDisplayAreaInfos.get(0);
        mControlBarDisplay = controlBarDisplayAreaInfos.get(0);

        SurfaceControl.Transaction tx = new SurfaceControl.Transaction();
        // TODO(b/188102153): replace to set mForegroundApplicationsDisplay to top.
        tx.setLayer(mBackgroundApplicationDisplay.getLeash(), BACKGROUND_LAYER_INDEX);
        tx.setLayer(mForegroundApplicationsDisplay.getLeash(), FOREGROUND_LAYER_INDEX);
        tx.setLayer(mTitleBarDisplay.getLeash(), FOREGROUND_LAYER_INDEX);
        tx.setLayer(mVoicePlateDisplay.getLeash(), VOICE_PLATE_LAYER_SHOWN_INDEX);
        tx.setLayer(mControlBarDisplay.getLeash(), CONTROL_BAR_LAYER_INDEX);

        tx.hide(mVoicePlateDisplay.getLeash());
        tx.hide(mForegroundApplicationsDisplay.getLeash());
        tx.apply(true);
    }

    /** Un-Registers DA organizer. */
    public void unregister() {
        mOrganizer.resetWindowsOffset();
        mOrganizer.unregisterOrganizer();
        mForegroundApplicationsDisplay = null;
        mTitleBarDisplay = null;
        mBackgroundApplicationDisplay = null;
        mControlBarDisplay = null;
        mVoicePlateDisplay = null;
        mImeContainerDisplayArea = null;
        mCarDisplayAreaTouchHandler.enable(false);
        ActivityTaskManager.getInstance()
                .unregisterTaskStackListener(mOnActivityRestartAttemptListener);
        mTitleBarView.setVisibility(View.GONE);
    }

    /**
     * This method should be called after the registration of DA's are done. The method expects a
     * target state as an argument, according to which the animations will take place. For example,
     * if the target state is {@link DisplayAreaComponent.FOREGROUND_DA_STATE#DEFAULT} then the
     * foreground
     * DA hosting default applications will animate to the default set height.
     */
    public void startAnimation(DisplayAreaComponent.FOREGROUND_DA_STATE toState) {
        // TODO: currently the animations are only bottom/up. Make it more generic animations here.
        int fromPos = 0;
        int toPos = 0;

        switch (toState) {
            case CONTROL_BAR:
                // Foreground DA closes.
                fromPos = mScreenHeightWithoutNavBar - mDefaultDisplayHeight
                        - mControlBarDisplayHeight;
                toPos = mScreenHeightWithoutNavBar + mTitleBarHeight;
                animateToControlBarState(fromPos, toPos, mEnterExitAnimationDurationMs);
                mCarDisplayAreaTouchHandler.updateTitleBarVisibility(false);
                break;
            case FULL:
                // TODO: Implement this.
                break;
            default:
                // Foreground DA opens to default height.
                // update the bounds to expand the foreground display area before starting
                // animations.
                fromPos = mScreenHeightWithoutNavBar + mTitleBarHeight;
                toPos = mScreenHeightWithoutNavBar - mDefaultDisplayHeight
                        - mControlBarDisplayHeight;
                animateToDefaultState(fromPos, toPos, mEnterExitAnimationDurationMs);
        }
    }

    private void animateToControlBarState(int fromPos, int toPos, int durationMs) {
        mBackgroundApplicationDisplayBounds.bottom =
                mScreenHeightWithoutNavBar - mControlBarDisplayHeight;
        animate(fromPos, toPos, CONTROL_BAR, durationMs);
        mIsHostingDefaultApplicationDisplayAreaVisible = false;
    }

    private void animateToDefaultState(int fromPos, int toPos, int durationMs) {
        if (!isForegroundDaVisible()) {
            makeForegroundDaVisible(true);
            showTitleBar();
        }
        mBackgroundApplicationDisplayBounds.bottom = toPos - mTitleBarHeight;
        animate(fromPos, toPos, DEFAULT, durationMs);
        mIsHostingDefaultApplicationDisplayAreaVisible = true;
        if (mCarDisplayAreaTouchHandler != null) {
            mCarDisplayAreaTouchHandler.updateTitleBarVisibility(true);
        }
    }

    private void animate(int fromPos, int toPos, DisplayAreaComponent.FOREGROUND_DA_STATE toState,
            int durationMs) {
        if (mOrganizer != null) {
            mOrganizer.scheduleOffset(fromPos, toPos, mBackgroundApplicationDisplayBounds,
                    mBackgroundApplicationDisplay, mForegroundApplicationsDisplay,
                    mControlBarDisplay, toState, durationMs);
        }
    }

    void makeForegroundDaVisible(boolean isVisible) {
        logIfDebuggable("make foregroundDA visible? " + isVisible);
        SurfaceControl.Transaction tx = new SurfaceControl.Transaction();
        if (isVisible) {
            tx.show(mForegroundApplicationsDisplay.getLeash());
            mIsForegroundDaVisible = true;
        } else {
            tx.hide(mForegroundApplicationsDisplay.getLeash());
            mIsForegroundDaVisible = false;
        }
        tx.apply(true);

    }

    boolean isForegroundDaVisible() {
        return mIsForegroundDaVisible;
    }

    /** Pre-calculates the display bounds for different DA's. */
    void setDefaultBounds() {
        logIfDebuggable("setting default bounds for all the DA's");
        int controlBarTop = mScreenHeightWithoutNavBar - mControlBarDisplayHeight;
        int foregroundTop =
                mScreenHeightWithoutNavBar - mDefaultDisplayHeight - mControlBarDisplayHeight;

        // Bottom nav bar. Bottom nav bar height will be 0 if the nav bar is present on the sides.
        Rect backgroundBounds = new Rect(0, 0, mTotalScreenWidth, controlBarTop);
        Rect controlBarBounds = new Rect(0, controlBarTop, mTotalScreenWidth,
                mScreenHeightWithoutNavBar);
        Rect foregroundBounds = new Rect(0,
                foregroundTop, mTotalScreenWidth,
                mScreenHeightWithoutNavBar - mControlBarDisplayHeight);
        Rect voicePlateBounds = new Rect(0, 0, mTotalScreenWidth,
                mScreenHeightWithoutNavBar - mControlBarDisplayHeight);
        Rect titleBarBounds = new Rect(0,
                foregroundTop - mTitleBarHeight, mTotalScreenWidth, foregroundTop);

        // Adjust the bounds based on the nav bar.
        // TODO: account for the case where nav bar is at the top.

        // Populate the bounds depending on where the nav bar is.
        if (mNavBarBounds.left == 0 && mNavBarBounds.top == 0) {
            // Left nav bar.
            backgroundBounds.left = mNavBarBounds.right;
            controlBarBounds.left = mNavBarBounds.right;
            foregroundBounds.left = mNavBarBounds.right;
            titleBarBounds.left = mNavBarBounds.right;
        } else if (mNavBarBounds.top == 0) {
            // Right nav bar.
            backgroundBounds.right = mNavBarBounds.left;
            controlBarBounds.right = mNavBarBounds.left;
            foregroundBounds.right = mNavBarBounds.left;
            titleBarBounds.right = mNavBarBounds.left;
        }

        mBackgroundApplicationDisplayBounds.set(backgroundBounds);
        mControlBarDisplayBounds.set(controlBarBounds);
        mForegroundApplicationDisplayBounds.set(foregroundBounds);
        mTitleBarDisplayBounds.set(titleBarBounds);
        mVoicePlateDisplayBounds.set(voicePlateBounds);
        mCarDisplayAreaTouchHandler.setTitleBarBounds(titleBarBounds);

        // Set the initial bounds for first and second displays.
        WindowContainerTransaction wct = new WindowContainerTransaction();
        updateBounds(wct);
        mOrganizer.applyTransaction(wct);
    }

    /** Updates the default and background display bounds for the given config. */
    private void updateBounds(WindowContainerTransaction wct) {
        Rect foregroundApplicationDisplayBound = mForegroundApplicationDisplayBounds;
        Rect titleBarDisplayBounds = mTitleBarDisplayBounds;
        Rect voicePlateDisplayBounds = mVoicePlateDisplayBounds;
        Rect backgroundApplicationDisplayBound = mBackgroundApplicationDisplayBounds;
        Rect controlBarDisplayBound = mControlBarDisplayBounds;

        WindowContainerToken foregroundDisplayToken =
                mForegroundApplicationsDisplay.getDisplayAreaInfo().token;
        WindowContainerToken imeRootDisplayToken =
                mImeContainerDisplayArea.getDisplayAreaInfo().token;
        WindowContainerToken titleBarDisplayToken =
                mTitleBarDisplay.getDisplayAreaInfo().token;
        WindowContainerToken voicePlateDisplayToken =
                mVoicePlateDisplay.getDisplayAreaInfo().token;
        WindowContainerToken backgroundDisplayToken =
                mBackgroundApplicationDisplay.getDisplayAreaInfo().token;
        WindowContainerToken controlBarDisplayToken =
                mControlBarDisplay.getDisplayAreaInfo().token;

        // Default TDA
        int foregroundDisplayWidthDp =
                foregroundApplicationDisplayBound.width() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        int foregroundDisplayHeightDp =
                foregroundApplicationDisplayBound.height() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        wct.setBounds(foregroundDisplayToken, foregroundApplicationDisplayBound);
        wct.setScreenSizeDp(foregroundDisplayToken, foregroundDisplayWidthDp,
                foregroundDisplayHeightDp);
        wct.setSmallestScreenWidthDp(foregroundDisplayToken, foregroundDisplayWidthDp);

        // Title bar
        int titleBarDisplayWidthDp =
                titleBarDisplayBounds.width() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        int titleBarDisplayHeightDp =
                titleBarDisplayBounds.height() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        wct.setBounds(titleBarDisplayToken, titleBarDisplayBounds);
        wct.setScreenSizeDp(titleBarDisplayToken, titleBarDisplayWidthDp,
                titleBarDisplayHeightDp);
        wct.setSmallestScreenWidthDp(titleBarDisplayToken, titleBarDisplayWidthDp);

        // voice plate
        int voicePlateDisplayWidthDp =
                voicePlateDisplayBounds.width() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        int voicePlateDisplayHeightDp =
                voicePlateDisplayBounds.height() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        wct.setBounds(voicePlateDisplayToken, voicePlateDisplayBounds);
        wct.setScreenSizeDp(voicePlateDisplayToken, voicePlateDisplayWidthDp,
                voicePlateDisplayHeightDp);
        wct.setSmallestScreenWidthDp(voicePlateDisplayToken, voicePlateDisplayWidthDp);

        // background TDA
        int backgroundDisplayWidthDp =
                backgroundApplicationDisplayBound.width() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        int backgroundDisplayHeightDp =
                backgroundApplicationDisplayBound.height() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        wct.setBounds(backgroundDisplayToken, backgroundApplicationDisplayBound);
        wct.setScreenSizeDp(backgroundDisplayToken, backgroundDisplayWidthDp,
                backgroundDisplayHeightDp);
        wct.setSmallestScreenWidthDp(backgroundDisplayToken, backgroundDisplayWidthDp);

        // Change the bounds of the IME attached to the root display to be same as the background DA
        wct.setBounds(imeRootDisplayToken, backgroundApplicationDisplayBound);
        wct.setScreenSizeDp(imeRootDisplayToken, backgroundDisplayWidthDp,
                backgroundDisplayHeightDp);
        wct.setSmallestScreenWidthDp(imeRootDisplayToken, backgroundDisplayWidthDp);

        // control bar
        int controlBarDisplayWidthDp =
                controlBarDisplayBound.width() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        int controlBarDisplayHeightDp =
                controlBarDisplayBound.height() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        wct.setBounds(controlBarDisplayToken, controlBarDisplayBound);
        wct.setScreenSizeDp(controlBarDisplayToken, controlBarDisplayWidthDp,
                controlBarDisplayHeightDp);
        wct.setSmallestScreenWidthDp(controlBarDisplayToken, controlBarDisplayWidthDp);

        mSyncQueue.runInSync(t -> {
            t.setPosition(mForegroundApplicationsDisplay.getLeash(),
                    foregroundApplicationDisplayBound.left,
                    foregroundApplicationDisplayBound.top);
            t.setPosition(mVoicePlateDisplay.getLeash(),
                    voicePlateDisplayBounds.left,
                    voicePlateDisplayBounds.top);
            t.setPosition(mTitleBarDisplay.getLeash(),
                    titleBarDisplayBounds.left, -mTitleBarHeight);
            t.setPosition(mBackgroundApplicationDisplay.getLeash(),
                    backgroundApplicationDisplayBound.left,
                    backgroundApplicationDisplayBound.top);
            t.setPosition(mImeContainerDisplayArea.getLeash(),
                    backgroundApplicationDisplayBound.left,
                    backgroundApplicationDisplayBound.top);
            t.setPosition(mControlBarDisplay.getLeash(),
                    controlBarDisplayBound.left,
                    controlBarDisplayBound.top);
        });
    }

    /**
     * Update the bounds of foreground DA to cover full screen.
     */
    void makeForegroundDAFullScreen() {
        logIfDebuggable("make foregroundDA fullscreen");
        WindowContainerTransaction wct = new WindowContainerTransaction();
        Rect foregroundApplicationDisplayBounds = new Rect(0, 0, mTotalScreenWidth,
                mTotalScreenHeight);
        WindowContainerToken foregroundDisplayToken =
                mForegroundApplicationsDisplay.getDisplayAreaInfo().token;

        int foregroundDisplayWidthDp =
                foregroundApplicationDisplayBounds.width() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        int foregroundDisplayHeightDp =
                foregroundApplicationDisplayBounds.height() * DisplayMetrics.DENSITY_DEFAULT
                        / mDpiDensity;
        wct.setBounds(foregroundDisplayToken, foregroundApplicationDisplayBounds);
        wct.setScreenSizeDp(foregroundDisplayToken, foregroundDisplayWidthDp,
                foregroundDisplayHeightDp);
        wct.setSmallestScreenWidthDp(foregroundDisplayToken,
                Math.min(foregroundDisplayWidthDp, foregroundDisplayHeightDp));

        mSyncQueue.runInSync(t -> {
            t.setPosition(mForegroundApplicationsDisplay.getLeash(), 0, 0);
        });

        mOrganizer.applyTransaction(wct);
    }
}

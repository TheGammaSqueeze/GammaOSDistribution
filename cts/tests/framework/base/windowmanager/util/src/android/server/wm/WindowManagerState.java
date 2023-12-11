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
 * limitations under the License
 */

package android.server.wm;

import static android.app.WindowConfiguration.ACTIVITY_TYPE_DREAM;
import static android.app.WindowConfiguration.ACTIVITY_TYPE_HOME;
import static android.app.WindowConfiguration.ACTIVITY_TYPE_RECENTS;
import static android.app.WindowConfiguration.ACTIVITY_TYPE_STANDARD;
import static android.app.WindowConfiguration.ACTIVITY_TYPE_UNDEFINED;
import static android.app.WindowConfiguration.WINDOWING_MODE_UNDEFINED;
import static android.server.wm.ComponentNameUtils.getActivityName;
import static android.server.wm.ProtoExtractors.extract;
import static android.server.wm.StateLogger.log;
import static android.server.wm.StateLogger.logE;
import static android.server.wm.TestTaskOrganizer.INVALID_TASK_ID;
import static android.util.DisplayMetrics.DENSITY_DEFAULT;
import static android.view.Display.DEFAULT_DISPLAY;

import static androidx.test.InstrumentationRegistry.getInstrumentation;

import static com.google.common.truth.Truth.assertWithMessage;

import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import android.app.ActivityTaskManager;
import android.content.ComponentName;
import android.content.res.Configuration;
import android.graphics.Point;
import android.graphics.Rect;
import android.os.ParcelFileDescriptor;
import android.os.SystemClock;
import android.util.SparseArray;
import android.view.WindowManager;
import android.view.nano.DisplayInfoProto;
import android.view.nano.ViewProtoEnums;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.android.server.wm.nano.ActivityRecordProto;
import com.android.server.wm.nano.AppTransitionProto;
import com.android.server.wm.nano.ConfigurationContainerProto;
import com.android.server.wm.nano.DisplayAreaProto;
import com.android.server.wm.nano.DisplayContentProto;
import com.android.server.wm.nano.DisplayFramesProto;
import com.android.server.wm.nano.DisplayRotationProto;
import com.android.server.wm.nano.IdentifierProto;
import com.android.server.wm.nano.KeyguardControllerProto;
import com.android.server.wm.nano.PinnedTaskControllerProto;
import com.android.server.wm.nano.RootWindowContainerProto;
import com.android.server.wm.nano.TaskFragmentProto;
import com.android.server.wm.nano.TaskProto;
import com.android.server.wm.nano.WindowContainerChildProto;
import com.android.server.wm.nano.WindowContainerProto;
import com.android.server.wm.nano.WindowFramesProto;
import com.android.server.wm.nano.WindowManagerServiceDumpProto;
import com.android.server.wm.nano.WindowStateAnimatorProto;
import com.android.server.wm.nano.WindowStateProto;
import com.android.server.wm.nano.WindowSurfaceControllerProto;
import com.android.server.wm.nano.WindowTokenProto;

import com.google.protobuf.nano.InvalidProtocolBufferNanoException;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.function.Consumer;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class WindowManagerState {

    public static final String STATE_INITIALIZING = "INITIALIZING";
    public static final String STATE_STARTED = "STARTED";
    public static final String STATE_RESUMED = "RESUMED";
    public static final String STATE_PAUSED = "PAUSED";
    public static final String STATE_STOPPED = "STOPPED";
    public static final String STATE_DESTROYED = "DESTROYED";
    public static final String TRANSIT_ACTIVITY_OPEN = "TRANSIT_ACTIVITY_OPEN";
    public static final String TRANSIT_ACTIVITY_CLOSE = "TRANSIT_ACTIVITY_CLOSE";
    public static final String TRANSIT_TASK_OPEN = "TRANSIT_TASK_OPEN";
    public static final String TRANSIT_TASK_CLOSE = "TRANSIT_TASK_CLOSE";
    public static final String TRANSIT_WALLPAPER_OPEN = "TRANSIT_WALLPAPER_OPEN";
    public static final String TRANSIT_WALLPAPER_CLOSE = "TRANSIT_WALLPAPER_CLOSE";
    public static final String TRANSIT_WALLPAPER_INTRA_OPEN = "TRANSIT_WALLPAPER_INTRA_OPEN";
    public static final String TRANSIT_WALLPAPER_INTRA_CLOSE = "TRANSIT_WALLPAPER_INTRA_CLOSE";
    public static final String TRANSIT_KEYGUARD_GOING_AWAY = "TRANSIT_KEYGUARD_GOING_AWAY";
    public static final String TRANSIT_KEYGUARD_GOING_AWAY_ON_WALLPAPER =
            "TRANSIT_KEYGUARD_GOING_AWAY_ON_WALLPAPER";
    public static final String TRANSIT_KEYGUARD_OCCLUDE = "TRANSIT_KEYGUARD_OCCLUDE";
    public static final String TRANSIT_KEYGUARD_UNOCCLUDE = "TRANSIT_KEYGUARD_UNOCCLUDE";
    public static final String TRANSIT_TRANSLUCENT_ACTIVITY_OPEN =
            "TRANSIT_TRANSLUCENT_ACTIVITY_OPEN";
    public static final String TRANSIT_TRANSLUCENT_ACTIVITY_CLOSE =
            "TRANSIT_TRANSLUCENT_ACTIVITY_CLOSE";
    public static final String APP_STATE_IDLE = "APP_STATE_IDLE";
    public static final String APP_STATE_RUNNING = "APP_STATE_RUNNING";

    private static final String DUMPSYS_WINDOW = "dumpsys window -a --proto";
    private static final String STARTING_WINDOW_PREFIX = "Starting ";
    private static final String DEBUGGER_WINDOW_PREFIX = "Waiting For Debugger: ";
    /** @see WindowManager.LayoutParams */
    private static final int TYPE_NAVIGATION_BAR = 2019;
    /** @see WindowManager.LayoutParams */
    private static final int TYPE_NAVIGATION_BAR_PANEL = 2024;
    /** @see WindowManager.LayoutParams */
    private static final int TYPE_NOTIFICATION_SHADE = 2040;

    private RootWindowContainer mRoot = null;
    // Displays in z-order with the top most at the front of the list, starting with primary.
    private final List<DisplayContent> mDisplays = new ArrayList<>();
    /**
     * Root tasks in z-order with the top most at the front of the list, starting with primary
     * display.
     */
    private final List<Task> mRootTasks = new ArrayList<>();
    // Windows in z-order with the top most at the front of the list.
    private final List<WindowState> mWindowStates = new ArrayList<>();
    private KeyguardControllerState mKeyguardControllerState;
    private final List<String> mPendingActivities = new ArrayList<>();
    private int mTopFocusedTaskId = -1;
    private int mFocusedDisplayId = DEFAULT_DISPLAY;
    private String mFocusedWindow = null;
    private String mFocusedApp = null;
    private Boolean mIsHomeRecentsComponent;
    private int mDefaultMinSizeOfResizableTaskDp;
    private String mTopResumedActivityRecord = null;
    final List<String> mResumedActivitiesInRootTasks = new ArrayList<>();
    final List<String> mResumedActivitiesInDisplays = new ArrayList<>();
    private Rect mDefaultPinnedStackBounds = new Rect();
    private Rect mPinnedStackMovementBounds = new Rect();
    private String mInputMethodWindowAppToken = null;
    private boolean mDisplayFrozen;
    private boolean mSanityCheckFocusedWindow = true;

    static String appStateToString(int appState) {
        switch (appState) {
            case AppTransitionProto.APP_STATE_IDLE:
                return "APP_STATE_IDLE";
            case AppTransitionProto.APP_STATE_READY:
                return "APP_STATE_READY";
            case AppTransitionProto.APP_STATE_RUNNING:
                return "APP_STATE_RUNNING";
            case AppTransitionProto.APP_STATE_TIMEOUT:
                return "APP_STATE_TIMEOUT";
            default:
                fail("Invalid AppTransitionState");
                return null;
        }
    }

    static String appTransitionToString(int transition) {
        switch (transition) {
            case ViewProtoEnums.TRANSIT_UNSET: {
                return "TRANSIT_UNSET";
            }
            case ViewProtoEnums.TRANSIT_NONE: {
                return "TRANSIT_NONE";
            }
            case ViewProtoEnums.TRANSIT_ACTIVITY_OPEN: {
                return TRANSIT_ACTIVITY_OPEN;
            }
            case ViewProtoEnums.TRANSIT_ACTIVITY_CLOSE: {
                return TRANSIT_ACTIVITY_CLOSE;
            }
            case ViewProtoEnums.TRANSIT_TASK_OPEN: {
                return TRANSIT_TASK_OPEN;
            }
            case ViewProtoEnums.TRANSIT_TASK_CLOSE: {
                return TRANSIT_TASK_CLOSE;
            }
            case ViewProtoEnums.TRANSIT_TASK_TO_FRONT: {
                return "TRANSIT_TASK_TO_FRONT";
            }
            case ViewProtoEnums.TRANSIT_TASK_TO_BACK: {
                return "TRANSIT_TASK_TO_BACK";
            }
            case ViewProtoEnums.TRANSIT_WALLPAPER_CLOSE: {
                return TRANSIT_WALLPAPER_CLOSE;
            }
            case ViewProtoEnums.TRANSIT_WALLPAPER_OPEN: {
                return TRANSIT_WALLPAPER_OPEN;
            }
            case ViewProtoEnums.TRANSIT_WALLPAPER_INTRA_OPEN: {
                return TRANSIT_WALLPAPER_INTRA_OPEN;
            }
            case ViewProtoEnums.TRANSIT_WALLPAPER_INTRA_CLOSE: {
                return TRANSIT_WALLPAPER_INTRA_CLOSE;
            }
            case ViewProtoEnums.TRANSIT_TASK_OPEN_BEHIND: {
                return "TRANSIT_TASK_OPEN_BEHIND";
            }
            case ViewProtoEnums.TRANSIT_ACTIVITY_RELAUNCH: {
                return "TRANSIT_ACTIVITY_RELAUNCH";
            }
            case ViewProtoEnums.TRANSIT_DOCK_TASK_FROM_RECENTS: {
                return "TRANSIT_DOCK_TASK_FROM_RECENTS";
            }
            case ViewProtoEnums.TRANSIT_KEYGUARD_GOING_AWAY: {
                return TRANSIT_KEYGUARD_GOING_AWAY;
            }
            case ViewProtoEnums.TRANSIT_KEYGUARD_GOING_AWAY_ON_WALLPAPER: {
                return TRANSIT_KEYGUARD_GOING_AWAY_ON_WALLPAPER;
            }
            case ViewProtoEnums.TRANSIT_KEYGUARD_OCCLUDE: {
                return TRANSIT_KEYGUARD_OCCLUDE;
            }
            case ViewProtoEnums.TRANSIT_KEYGUARD_UNOCCLUDE: {
                return TRANSIT_KEYGUARD_UNOCCLUDE;
            }
            case ViewProtoEnums.TRANSIT_TRANSLUCENT_ACTIVITY_OPEN: {
                return TRANSIT_TRANSLUCENT_ACTIVITY_OPEN;
            }
            case ViewProtoEnums.TRANSIT_TRANSLUCENT_ACTIVITY_CLOSE: {
                return TRANSIT_TRANSLUCENT_ACTIVITY_CLOSE;
            }
            case ViewProtoEnums.TRANSIT_CRASHING_ACTIVITY_CLOSE: {
                return "TRANSIT_CRASHING_ACTIVITY_CLOSE";
            }
            default: {
                fail("Invalid lastUsedAppTransition");
                return null;
            }
        }
    }

    static boolean isValidNavBarType(WindowState navState) {
        return TYPE_NAVIGATION_BAR == navState.getType();
    }

    /**
     * For a given WindowContainer, traverse down the hierarchy and add all children of type
     * {@code T} to {@code outChildren}.
     */
    private static <T extends WindowContainer> void collectDescendantsOfType(Class<T> clazz,
            WindowContainer root, List<T> outChildren) {
        collectDescendantsOfTypeIf(clazz, t -> true, root, outChildren);
    }

    /**
     * For a given WindowContainer, traverse down the hierarchy and add all children of type
     * {@code T} to {@code outChildren} if the child passes the test {@code predicate}.
     */
    private static <T extends WindowContainer> void collectDescendantsOfTypeIf(Class<T> clazz,
            Predicate<T> predicate, WindowContainer root, List<T> outChildren) {
        // Traverse top to bottom
        for (int i = root.mChildren.size()-1; i >= 0; i--) {
            final WindowContainer child = root.mChildren.get(i);
            if (clazz.isInstance(child)) {
                if(predicate.test(clazz.cast(child))) {
                    outChildren.add(clazz.cast(child));
                }
            }
            collectDescendantsOfTypeIf(clazz, predicate, child, outChildren);
        }
    }

    /**
     * For a given WindowContainer, traverse down the hierarchy and add all immediate children of
     * type {@code T} to {@code outChildren}.
     */
    private static <T extends WindowContainer> void collectChildrenOfType(Class<T> clazz,
            WindowContainer root, List<T> outChildren) {
        for (int i = root.mChildren.size()-1; i >= 0; i--) {
            final WindowContainer child = root.mChildren.get(i);
            if (clazz.isInstance(child)) {
                outChildren.add(clazz.cast(child));
            }
        }
    }

    /** Enable/disable the mFocusedWindow check during the computeState.*/
    void setSanityCheckWithFocusedWindow(boolean sanityCheckFocusedWindow) {
        mSanityCheckFocusedWindow = sanityCheckFocusedWindow;
    }

    public void computeState() {
        // It is possible the system is in the middle of transition to the right state when we get
        // the dump. We try a few times to get the information we need before giving up.
        int retriesLeft = 3;
        boolean retry = false;
        byte[] dump = null;

        log("==============================");
        log("     WindowManagerState     ");
        log("==============================");

        do {
            if (retry) {
                log("***Incomplete AM state. Retrying...");
                // Wait half a second between retries for activity manager to finish transitioning.
                SystemClock.sleep(500);
            }

            dump = executeShellCommand(DUMPSYS_WINDOW);
            try {
                parseSysDumpProto(dump);
            } catch (InvalidProtocolBufferNanoException ex) {
                throw new RuntimeException("Failed to parse dumpsys:\n"
                        + new String(dump, StandardCharsets.UTF_8), ex);
            }

            retry = mRootTasks.isEmpty() || mTopFocusedTaskId == -1 || mWindowStates.isEmpty()
                    || mFocusedApp == null || (mSanityCheckFocusedWindow && mFocusedWindow == null)
                    || (mTopResumedActivityRecord == null
                    || mResumedActivitiesInRootTasks.isEmpty())
                    && !mKeyguardControllerState.keyguardShowing;
        } while (retry && retriesLeft-- > 0);

        if (mRootTasks.isEmpty()) {
            logE("No root tasks found...");
        }
        if (mTopFocusedTaskId == -1) {
            logE("No focused task found...");
        }
        if (mTopResumedActivityRecord == null) {
            logE("No focused activity found...");
        }
        if (mResumedActivitiesInRootTasks.isEmpty()) {
            logE("No resumed activities found...");
        }
        if (mWindowStates.isEmpty()) {
            logE("No Windows found...");
        }
        if (mFocusedWindow == null) {
            logE("No Focused Window...");
        }
        if (mFocusedApp == null) {
            logE("No Focused App...");
        }
    }

    private byte[] executeShellCommand(String cmd) {
        try {
            ParcelFileDescriptor pfd = getInstrumentation().getUiAutomation()
                    .executeShellCommand(cmd);
            byte[] buf = new byte[512];
            int bytesRead;
            FileInputStream fis = new ParcelFileDescriptor.AutoCloseInputStream(pfd);
            ByteArrayOutputStream stdout = new ByteArrayOutputStream();
            while ((bytesRead = fis.read(buf)) != -1) {
                stdout.write(buf, 0, bytesRead);
            }
            fis.close();
            return stdout.toByteArray();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    /** Update WindowManagerState state for a newly added DisplayContent. */
    private void updateForDisplayContent(DisplayContent display) {
        if (display.mResumedActivity != null) {
            mResumedActivitiesInDisplays.add(display.mResumedActivity);
        }

        for (int i = 0; i < display.mRootTasks.size(); i++) {
            Task task = display.mRootTasks.get(i);
            mRootTasks.add(task);
            addResumedActivity(task);
        }

        if (display.mDefaultPinnedStackBounds != null) {
            mDefaultPinnedStackBounds = display.mDefaultPinnedStackBounds;
            mPinnedStackMovementBounds = display.mPinnedStackMovementBounds;
        }
    }

    private void addResumedActivity(Task task) {
        final int numChildTasks = task.mTasks.size();
        if (numChildTasks > 0) {
            for (int i = numChildTasks - 1; i >=0; i--) {
                addResumedActivity(task.mTasks.get(i));
            }
        } else if (task.mResumedActivity != null) {
            mResumedActivitiesInRootTasks.add(task.mResumedActivity);
        }
    }

    private void parseSysDumpProto(byte[] sysDump) throws InvalidProtocolBufferNanoException {
        reset();

        WindowManagerServiceDumpProto state = WindowManagerServiceDumpProto.parseFrom(sysDump);
        final RootWindowContainerProto root = state.rootWindowContainer;
        if (state.focusedWindow != null) {
            mFocusedWindow = state.focusedWindow.title;
        }
        mRoot = new RootWindowContainer(root);
        collectDescendantsOfType(DisplayContent.class, mRoot, mDisplays);
        for (int i = 0; i < mDisplays.size(); i++) {
            DisplayContent display = mDisplays.get(i);
            updateForDisplayContent(display);
        }
        mKeyguardControllerState = new KeyguardControllerState(root.keyguardController);
        mFocusedApp = state.focusedApp;
        mFocusedDisplayId = state.focusedDisplayId;
        final DisplayContent focusedDisplay = getDisplay(mFocusedDisplayId);
        if (focusedDisplay != null) {
            mTopFocusedTaskId = focusedDisplay.mFocusedRootTaskId;
            mTopResumedActivityRecord = focusedDisplay.mResumedActivity;
        }
        mIsHomeRecentsComponent = new Boolean(root.isHomeRecentsComponent);
        mDefaultMinSizeOfResizableTaskDp = root.defaultMinSizeResizableTask;

        for (int i = 0; i < root.pendingActivities.length; i++) {
            mPendingActivities.add(root.pendingActivities[i].title);
        }

        collectDescendantsOfType(WindowState.class, mRoot, mWindowStates);

        if (state.inputMethodWindow != null) {
            mInputMethodWindowAppToken = Integer.toHexString(state.inputMethodWindow.hashCode);
        }
        mDisplayFrozen = state.displayFrozen;
    }

    private void reset() {
        mRoot = null;
        mDisplays.clear();
        mRootTasks.clear();
        mWindowStates.clear();
        mTopFocusedTaskId = -1;
        mFocusedDisplayId = DEFAULT_DISPLAY;
        mFocusedWindow = null;
        mFocusedApp = null;
        mTopResumedActivityRecord = null;
        mResumedActivitiesInRootTasks.clear();
        mResumedActivitiesInDisplays.clear();
        mKeyguardControllerState = null;
        mIsHomeRecentsComponent = null;
        mPendingActivities.clear();
        mDefaultPinnedStackBounds.setEmpty();
        mPinnedStackMovementBounds.setEmpty();
        mInputMethodWindowAppToken = null;
        mDisplayFrozen = false;
    }

    public String getFocusedApp() {
        return mFocusedApp;
    }

    public String getFocusedWindow() {
        return mFocusedWindow;
    }

    /** @return Whether the home activity is the recents component. */
    boolean isHomeRecentsComponent() {
        if (mIsHomeRecentsComponent == null) {
            computeState();
        }
        return mIsHomeRecentsComponent;
    }

    DisplayContent getDisplay(int displayId) {
        for (DisplayContent display : mDisplays) {
            if (display.mId == displayId) {
                return display;
            }
        }
        return null;
    }

    @Nullable
    DisplayArea getTaskDisplayArea(ComponentName activityName) {
        final List<DisplayArea> result = new ArrayList<>();
        for (DisplayContent display : mDisplays) {
            final DisplayArea tda = display.getTaskDisplayArea(activityName);
            if (tda != null) {
                result.add(tda);
            }
        }
        assertWithMessage("There must be exactly one activity among all TaskDisplayAreas.")
                .that(result.size()).isAtMost(1);

        return result.stream().findFirst().orElse(null);
    }

    @Nullable
    DisplayArea getDisplayArea(String windowName) {
        final List<DisplayArea> result = new ArrayList<>();
        for (DisplayContent display : mDisplays) {
            final DisplayArea da = display.getDisplayArea(windowName);
            if (da != null) {
                result.add(da);
            }
        }
        assertWithMessage("There must be exactly one window among all DisplayAreas.")
                .that(result.size()).isAtMost(1);

        return result.stream().findFirst().orElse(null);
    }

    int getFrontRootTaskId(int displayId) {
        return getDisplay(displayId).mRootTasks.get(0).mRootTaskId;
    }

    public int getFrontRootTaskActivityType(int displayId) {
        return getDisplay(displayId).mRootTasks.get(0).getActivityType();
    }

    public int getFrontRootTaskWindowingMode(int displayId) {
        return getDisplay(displayId).mRootTasks.get(0).getWindowingMode();
    }

    public String getTopActivityName(int displayId) {
        if (!getDisplay(displayId).mRootTasks.isEmpty()) {
            final Task topRootTask = getDisplay(displayId).mRootTasks.get(0);
            final Task topTask = topRootTask.getTopTask();
            if (!topTask.mActivities.isEmpty()) {
                return topTask.mActivities.get(0).name;
            }
        }
        return null;
    }

    int getFocusedTaskId() {
        return mTopFocusedTaskId;
    }

    public int getFocusedRootTaskActivityType() {
        final Task rootTask = getRootTask(mTopFocusedTaskId);
        return rootTask != null ? rootTask.getActivityType() : ACTIVITY_TYPE_UNDEFINED;
    }

    public int getFocusedRootTaskWindowingMode() {
        final Task rootTask = getRootTask(mTopFocusedTaskId);
        return rootTask != null ? rootTask.getWindowingMode() : WINDOWING_MODE_UNDEFINED;
    }

    public String getFocusedActivity() {
        return mTopResumedActivityRecord;
    }

    public int getResumedActivitiesCount() {
        return mResumedActivitiesInRootTasks.size();
    }

    public int getResumedActivitiesCountInPackage(String packageName) {
        final String componentPrefix = packageName + "/";
        int count = 0;
        for (int i = mDisplays.size() - 1; i >= 0; --i) {
            final ArrayList<Task> rootTasks = mDisplays.get(i).getRootTasks();
            for (int j = rootTasks.size() - 1; j >= 0; --j) {
                final String resumedActivity = rootTasks.get(j).mResumedActivity;
                if (resumedActivity != null && resumedActivity.startsWith(componentPrefix)) {
                    count++;
                }
            }
        }
        return count;
    }

    public String getResumedActivityOnDisplay(int displayId) {
        return getDisplay(displayId).mResumedActivity;
    }

    public KeyguardControllerState getKeyguardControllerState() {
        return mKeyguardControllerState;
    }

    public boolean containsRootTasks(int windowingMode, int activityType) {
        return countRootTasks(windowingMode, activityType) > 0;
    }

    public int countRootTasks(int windowingMode, int activityType) {
        int count = 0;
        for (Task rootTask : mRootTasks) {
            if (activityType != ACTIVITY_TYPE_UNDEFINED
                    && activityType != rootTask.getActivityType()) {
                continue;
            }
            if (windowingMode != WINDOWING_MODE_UNDEFINED
                    && windowingMode != rootTask.getWindowingMode()) {
                continue;
            }
            ++count;
        }
        return count;
    }

    public Task getRootTask(int taskId) {
        for (Task rootTask : mRootTasks) {
            if (taskId == rootTask.mRootTaskId) {
                return rootTask;
            }
        }
        return null;
    }

    public Task getRootTaskByActivityType(int activityType) {
        for (Task rootTask : mRootTasks) {
            if (activityType == rootTask.getActivityType()) {
                return rootTask;
            }
        }
        return null;
    }

    public int getStandardTaskCountByWindowingMode(int windowingMode) {
        int count = 0;
        for (Task rootTask : mRootTasks) {
            if (rootTask.getActivityType() != ACTIVITY_TYPE_STANDARD) {
                continue;
            }
            if (rootTask.getWindowingMode() == windowingMode) {
                count += rootTask.mTasks.isEmpty() ? 1 : rootTask.mTasks.size();
            }
        }
        return count;
    }

    /** Gets the position of root task on its display with the given {@code activityType}. */
    int getRootTaskIndexByActivityType(int activityType) {
        for (DisplayContent display : mDisplays) {
            for (int i = 0; i < display.mRootTasks.size(); i++) {
                if (activityType == display.mRootTasks.get(i).getActivityType()) {
                    return i;
                }
            }
        }
        return -1;
    }

    /** Gets the root task on its display with the given {@code activityName}. */
    @Nullable
    Task getRootTaskByActivity(ComponentName activityName) {
        for (DisplayContent display : mDisplays) {
            for (int i = display.mRootTasks.size() - 1; i >= 0; --i) {
                final Task rootTask = display.mRootTasks.get(i);
                if (rootTask.containsActivity(activityName)) return rootTask;
            }
        }
        return null;
    }

    /** Get display id by activity on it. */
    public int getDisplayByActivity(ComponentName activityComponent) {
        final Task task = getTaskByActivity(activityComponent);
        if (task == null) {
            return -1;
        }
        return getRootTask(task.mRootTaskId).mDisplayId;
    }

    List<DisplayContent> getDisplays() {
        return new ArrayList<>(mDisplays);
    }

    public List<Task> getRootTasks() {
        return new ArrayList<>(mRootTasks);
    }

    public int getRootTaskCount() {
        return mRootTasks.size();
    }

    public int getDisplayCount() {
        return mDisplays.size();
    }

    public boolean containsActivity(ComponentName activityName) {
        for (Task rootTask : mRootTasks) {
            if (rootTask.containsActivity(activityName)) return true;
        }
        return false;
    }

    public boolean containsNoneOf(Iterable<ComponentName> activityNames) {
        for (ComponentName activityName : activityNames) {
            for (Task rootTask : mRootTasks) {
                if (rootTask.containsActivity(activityName)) return false;
            }
        }
        return true;
    }

    public boolean containsActivityInWindowingMode(ComponentName activityName, int windowingMode) {
        for (Task rootTask : mRootTasks) {
            final Activity activity = rootTask.getActivity(activityName);
            if (activity != null && activity.getWindowingMode() == windowingMode) {
                return true;
            }
        }
        return false;
    }

    public boolean isActivityVisible(ComponentName activityName) {
        for (Task rootTask : mRootTasks) {
            final Activity activity = rootTask.getActivity(activityName);
            if (activity != null) return activity.visible;
        }
        return false;
    }

    public boolean isActivityTranslucent(ComponentName activityName) {
        for (Task rootTask : mRootTasks) {
            final Activity activity = rootTask.getActivity(activityName);
            if (activity != null) return activity.translucent;
        }
        return false;
    }

    public boolean isBehindOpaqueActivities(ComponentName activityName) {
        final String fullName = getActivityName(activityName);
        for (Task rootTask : mRootTasks) {
            final Activity activity =
                    rootTask.getActivity((a) -> a.name.equals(fullName) || !a.translucent);
            if (activity != null) {
                if (activity.name.equals(fullName)) {
                    return false;
                }
                if (!activity.translucent) {
                    return true;
                }
            }
        }

        return false;
    }

    public boolean containsStartedActivities() {
        for (Task rootTask : mRootTasks) {
            final Activity activity = rootTask.getActivity(
                    (a) -> !a.state.equals(STATE_STOPPED) && !a.state.equals(STATE_DESTROYED));
            if (activity != null) return true;
        }
        return false;
    }

    boolean hasActivityState(ComponentName activityName, String activityState) {
        for (Task rootTask : mRootTasks) {
            final Activity activity = rootTask.getActivity(activityName);
            if (activity != null) return activity.state.equals(activityState);
        }
        return false;
    }

    int getActivityProcId(ComponentName activityName) {
        for (Task rootTask : mRootTasks) {
            final Activity activity = rootTask.getActivity(activityName);
            if (activity != null) return activity.procId;
        }
        return -1;
    }

    boolean isRecentsActivityVisible() {
        final Activity recentsActivity = getRecentsActivity();
        return recentsActivity != null && recentsActivity.visible;
    }

    ComponentName getHomeActivityName() {
        Activity activity = getHomeActivity();
        if (activity == null) {
            return null;
        }
        return ComponentName.unflattenFromString(activity.name);
    }

    Task getDreamTask() {
        final Task dreamRootTask = getRootTaskByActivityType(ACTIVITY_TYPE_DREAM);
        if (dreamRootTask != null) {
            return dreamRootTask.getTopTask();
        }
        return null;
    }

    Task getHomeTask() {
        final Task homeRootTask = getRootTaskByActivityType(ACTIVITY_TYPE_HOME);
        if (homeRootTask != null) {
            return homeRootTask.getTopTask();
        }
        return null;
    }

    private Task getRecentsTask() {
        final Task recentsRootTask = getRootTaskByActivityType(ACTIVITY_TYPE_RECENTS);
        if (recentsRootTask != null) {
            return recentsRootTask.getTopTask();
        }
        return null;
    }

    private Activity getHomeActivity() {
        final Task homeTask = getHomeTask();
        return homeTask != null ? homeTask.mActivities.get(homeTask.mActivities.size() - 1) : null;
    }

    private Activity getRecentsActivity() {
        final Task recentsTask = getRecentsTask();
        return recentsTask != null ? recentsTask.mActivities.get(recentsTask.mActivities.size() - 1)
                : null;
    }

    public int getRootTaskIdByActivity(ComponentName activityName) {
        final Task task = getTaskByActivity(activityName);
        return  (task == null) ? INVALID_TASK_ID : task.mRootTaskId;
    }

    public Task getTaskByActivity(ComponentName activityName) {
        return getTaskByActivity(
                activityName, WINDOWING_MODE_UNDEFINED, new int[]{ INVALID_TASK_ID });
    }

    public Task getTaskByActivity(ComponentName activityName, int[] excludeTaskIds) {
        return getTaskByActivity(activityName, WINDOWING_MODE_UNDEFINED, excludeTaskIds);
    }

    private Task getTaskByActivity(ComponentName activityName, int windowingMode,
            int[] excludeTaskIds) {
        Activity activity = getActivity(activityName, windowingMode, excludeTaskIds);
        return activity == null ? null : activity.getTask();
    }

    @Nullable
    public TaskFragment getTaskFragmentByActivity(ComponentName activityName) {
        return getActivity(activityName).getTaskFragment();
    }

    public Activity getActivity(ComponentName activityName) {
        return getActivity(activityName, WINDOWING_MODE_UNDEFINED, new int[]{ INVALID_TASK_ID });
    }

    private Activity getActivity(ComponentName activityName, int windowingMode,
            int[] excludeTaskIds) {
        for (Task rootTask : mRootTasks) {
            if (windowingMode == WINDOWING_MODE_UNDEFINED
                    || windowingMode == rootTask.getWindowingMode()) {
                Activity activity = rootTask.getActivity(activityName, excludeTaskIds);
                if (activity != null) return activity;
            }
        }
        return null;
    }

    /**
     * Get the number of activities in the task, with the option to count only activities with
     * specific name.
     * @param taskId Id of the task where we're looking for the number of activities.
     * @param activityName Optional name of the activity we're interested in.
     * @return Number of all activities in the task if activityName is {@code null}, otherwise will
     *         report number of activities that have specified name.
     */
    public int getActivityCountInTask(int taskId, @Nullable ComponentName activityName) {
        // If activityName is null, count all activities in the task.
        // Otherwise count activities that have specified name.
        for (Task rootTask : mRootTasks) {
            final Task task = rootTask.getTask(taskId);
            if (task == null) continue;

            if (activityName == null) {
                return task.mActivities.size();
            }
            final String fullName = getActivityName(activityName);
            int count = 0;
            for (Activity activity : task.mActivities) {
                if (activity.name.equals(fullName)) {
                    count++;
                }
            }
            return count;
        }
        return 0;
    }

    public int getRootTasksCount() {
        return mRootTasks.size();
    }

    public int getRootTasksCount(int displayId) {
        return getRootTasksCount(t -> t.mDisplayId == displayId);
    }

    /**
     * Count root tasks filtered by the predicate passed as argument.
     */
    public int getRootTasksCount(Predicate<? super Task> predicate) {
        return (int) mRootTasks.stream().filter(predicate).count();
    }

    boolean pendingActivityContain(ComponentName activityName) {
        return mPendingActivities.contains(getActivityName(activityName));
    }

    // Get the logical display size of the default display.
    public static Point getLogicalDisplaySize() {
        WindowManagerState mWmState = new WindowManagerState();
        mWmState.computeState();
        Rect size = mWmState.getDisplay(DEFAULT_DISPLAY).getDisplayRect();
        return new Point(size.width(), size.height());
    }

    String getDefaultDisplayLastTransition() {
        return getDisplay(DEFAULT_DISPLAY).getLastTransition();
    }

    String getDefaultDisplayAppTransitionState() {
        return getDisplay(DEFAULT_DISPLAY).getAppTransitionState();
    }

    public List<WindowState> getMatchingVisibleWindowState(final String windowName) {
        return getMatchingWindows(ws -> ws.isSurfaceShown() && windowName.equals(ws.getName()))
                .collect(Collectors.toList());
    }

    private Stream<WindowState> getMatchingWindows(Predicate<WindowState> condition) {
        return mWindowStates.stream().filter(condition);
    }

    @Nullable
    public WindowState getWindowByPackageName(String packageName, int windowType) {
        final List<WindowState> windowList = getWindowsByPackageName(packageName, windowType);
        return windowList.isEmpty() ? null : windowList.get(0);
    }

    public List<WindowState> getWindowsByPackageName(String packageName, int... restrictToTypes) {
        return getMatchingWindows(ws ->
                (ws.getName().equals(packageName) || ws.getName().startsWith(packageName + "/"))
                        && Arrays.stream(restrictToTypes).anyMatch(type -> type == ws.getType()))
                .collect(Collectors.toList());
    }

    public boolean hasNotificationShade() {
        computeState();
        return !getMatchingWindowType(TYPE_NOTIFICATION_SHADE).isEmpty();
    }

    List<WindowState> getWindows() {
        return new ArrayList<>(mWindowStates);
    }

    List<WindowState> getMatchingWindowType(int type) {
        return getMatchingWindows(ws -> type == ws.mType).collect(Collectors.toList());
    }

    List<String> getMatchingWindowTokens(final String windowName) {
        return getMatchingWindows(ws -> windowName.equals(ws.getName()))
                .map(WindowState::getToken)
                .collect(Collectors.toList());
    }

    List<WindowState> getAllNavigationBarStates() {
        return getMatchingWindows(WindowManagerState::isValidNavBarType)
                .collect(Collectors.toList());
    }

    @Nullable
    List<WindowState> getAndAssertNavBarWindowsOnDisplay(int displayId, int expectedNavBarCount) {
        List<WindowState> navWindows = getMatchingWindows(ws -> isValidNavBarType(ws)
                && ws.getDisplayId() == displayId)
                .filter(Objects::nonNull)
                .collect(Collectors.toList());
        // We may need some time to wait for nav bar showing.
        // It's Ok to get less that expected nav bars here.
        assertTrue("There should be at most expectedNavBarCount navigation bar on a display",
                navWindows.size() <= expectedNavBarCount);

        return navWindows.size() == expectedNavBarCount ? navWindows : null;
    }

    WindowState getWindowStateForAppToken(String appToken) {
        return getMatchingWindows(ws -> ws.getToken().equals(appToken))
                .findFirst()
                .orElse(null);
    }

    String getFrontWindow() {
        if (mWindowStates == null || mWindowStates.isEmpty()) {
            return null;
        }
        return mWindowStates.get(0).getName();
    }

    /** Check if there exists a window record with matching windowName. */
    public boolean containsWindow(String windowName) {
        for (WindowState window : mWindowStates) {
            if (window.getName().equals(windowName)) {
                return true;
            }
        }
        return false;
    }

    /** Check if at least one window which matches the specified name has shown it's surface. */
    public boolean isWindowSurfaceShown(String windowName) {
        for (WindowState window : mWindowStates) {
            if (window.getName().equals(windowName)) {
                if (window.isSurfaceShown()) {
                    return true;
                }
            }
        }
        return false;
    }

    /** Check if at least one window which matches provided window name is visible. */
    public boolean isWindowVisible(String windowName) {
        for (WindowState window : mWindowStates) {
            if (window.getName().equals(windowName)) {
                if (window.isVisible()) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean allWindowSurfacesShown(String windowName) {
        boolean allShown = false;
        for (WindowState window : mWindowStates) {
            if (window.getName().equals(windowName)) {
                if (!window.isSurfaceShown()) {
                    log("[VISIBLE] not visible" + windowName);
                    return false;
                }
                log("[VISIBLE] visible" + windowName);
                allShown = true;
            }
        }
        return allShown;
    }

    /** Checks whether the display contains the given activity. */
    boolean hasActivityInDisplay(int displayId, ComponentName activityName) {
        for (Task rootTask : getDisplay(displayId).getRootTasks()) {
            if (rootTask.containsActivity(activityName)) {
                return true;
            }
        }
        return false;
    }

    WindowState findFirstWindowWithType(int type) {
        for (WindowState window : mWindowStates) {
            if (window.getType() == type) {
                return window;
            }
        }
        return null;
    }

    public int getZOrder(WindowState w) {
        return mWindowStates.size() - mWindowStates.indexOf(w);
    }

    Task getStandardRootTaskByWindowingMode(int windowingMode) {
        for (Task task : mRootTasks) {
            if (task.getActivityType() != ACTIVITY_TYPE_STANDARD) {
                continue;
            }
            if (task.getWindowingMode() == windowingMode) {
                return task;
            }
        }
        return null;
    }

    WindowManagerState.WindowState getInputMethodWindowState() {
        return getWindowStateForAppToken(mInputMethodWindowAppToken);
    }

    public boolean isDisplayFrozen() {
        return mDisplayFrozen;
    }

    public int getRotation() {
        return getDisplay(DEFAULT_DISPLAY).mRotation;
    }

    public int getLastOrientation() {
        return getDisplay(DEFAULT_DISPLAY).mLastOrientation;
    }

    public int getFocusedDisplayId() {
        return mFocusedDisplayId;
    }

    public static class DisplayContent extends DisplayArea {
        public int mId;
        ArrayList<Task> mRootTasks = new ArrayList<>();
        int mFocusedRootTaskId;
        String mResumedActivity;
        boolean mSingleTaskInstance;
        Rect mDefaultPinnedStackBounds = null;
        Rect mPinnedStackMovementBounds = null;

        private Rect mDisplayRect = new Rect();
        private Rect mAppRect = new Rect();
        private int mDpi;
        private int mFlags;
        private String mName;
        private int mSurfaceSize;
        private String mFocusedApp;
        private String mLastTransition;
        private String mAppTransitionState;
        private int mRotation;
        private boolean mFrozenToUserRotation;
        private int mUserRotation;
        private int mFixedToUserRotationMode;
        private int mLastOrientation;

        DisplayContent(DisplayContentProto proto) {
            super(proto.rootDisplayArea);
            mId = proto.id;
            mFocusedRootTaskId = proto.focusedRootTaskId;
            mSingleTaskInstance = proto.singleTaskInstance;
            if (proto.resumedActivity != null) {
                mResumedActivity = proto.resumedActivity.title;
            }
            addRootTasks();

            mDpi = proto.dpi;
            DisplayInfoProto infoProto = proto.displayInfo;
            if (infoProto != null) {
                mDisplayRect.set(0, 0, infoProto.logicalWidth, infoProto.logicalHeight);
                mAppRect.set(0, 0, infoProto.appWidth, infoProto.appHeight);
                mName = infoProto.name;
                mFlags = infoProto.flags;
            }
            final DisplayFramesProto displayFramesProto = proto.displayFrames;
            mSurfaceSize = proto.surfaceSize;
            mFocusedApp = proto.focusedApp;

            final AppTransitionProto appTransitionProto = proto.appTransition;
            int appState = 0;
            int lastTransition = 0;
            if (appTransitionProto != null) {
                appState = appTransitionProto.appTransitionState;
                lastTransition = appTransitionProto.lastUsedAppTransition;
            }
            mAppTransitionState = appStateToString(appState);
            mLastTransition = appTransitionToString(lastTransition);

            PinnedTaskControllerProto pinnedTaskProto = proto.pinnedTaskController;
            if (pinnedTaskProto != null) {
                mDefaultPinnedStackBounds = extract(pinnedTaskProto.defaultBounds);
                mPinnedStackMovementBounds = extract(pinnedTaskProto.movementBounds);
            }

            final DisplayRotationProto rotationProto = proto.displayRotation;
            if (rotationProto != null) {
                mRotation = rotationProto.rotation;
                mFrozenToUserRotation = rotationProto.frozenToUserRotation;
                mUserRotation = rotationProto.userRotation;
                mFixedToUserRotationMode = rotationProto.fixedToUserRotationMode;
                mLastOrientation = rotationProto.lastOrientation;
            }
        }

        public String getName() {
            return mName;
        }

        private void addRootTasks() {
            // TODO(b/149338177): figure out how CTS tests deal with organizer. For now,
            //                    don't treat them as regular root tasks
            collectDescendantsOfTypeIf(Task.class, t -> t.isRootTask(), this,
                    mRootTasks);
            ArrayList<Task> rootOrganizedTasks = new ArrayList<>();
            for (int i = mRootTasks.size() -1; i >= 0; --i) {
                final Task task = mRootTasks.get(i);
                // Skip tasks created by an organizer
                if (task.mCreatedByOrganizer) {
                    mRootTasks.remove(task);
                    rootOrganizedTasks.add(task);
                }
            }
            // Add root tasks controlled by an organizer
            while (rootOrganizedTasks.size() > 0) {
                final Task task = rootOrganizedTasks.remove(0);
                for (int i = task.mChildren.size() - 1; i >= 0; i--) {
                    final Task child = (Task) task.mChildren.get(i);
                    if (!child.mCreatedByOrganizer) {
                        mRootTasks.add(child);
                    } else {
                        rootOrganizedTasks.add(child);
                    }
                }
            }
        }

        boolean containsActivity(ComponentName activityName) {
            for (Task task : mRootTasks) {
                if (task.containsActivity(activityName)) return true;
            }
            return false;
        }

        List<DisplayArea> getAllTaskDisplayAreas() {
            final List<DisplayArea> taskDisplayAreas = new ArrayList<>();
            collectDescendantsOfTypeIf(DisplayArea.class, DisplayArea::isTaskDisplayArea, this,
                    taskDisplayAreas);
            return taskDisplayAreas;
        }

        @Nullable
        DisplayArea getTaskDisplayArea(ComponentName activityName) {
            final List<DisplayArea> taskDisplayAreas = getAllTaskDisplayAreas();
            List<DisplayArea> result = taskDisplayAreas.stream().filter(
                    tda -> tda.containsActivity(activityName))
                    .collect(Collectors.toList());

            assertWithMessage("There must be exactly one activity among all TaskDisplayAreas.")
                    .that(result.size()).isAtMost(1);

            return result.stream().findFirst().orElse(null);
        }

        List<DisplayArea> getAllChildDisplayAreas() {
            final List<DisplayArea> displayAreas = new ArrayList<>();
            collectDescendantsOfType(DisplayArea.class,this, displayAreas);
            return displayAreas;
        }

        @Nullable
        DisplayArea getDisplayArea(String windowName) {
            List<DisplayArea> displayAreas = new ArrayList<>();
            final Predicate<DisplayArea> p = da -> {
                final boolean containsChildWindowToken = !da.mChildren.isEmpty()
                        && da.mChildren.get(0) instanceof WindowToken;
                return !da.isTaskDisplayArea() && containsChildWindowToken;
            };
            collectDescendantsOfTypeIf(DisplayArea.class, p, this, displayAreas);
            List<DisplayArea> result = displayAreas.stream().filter(
                    da -> da.containsWindow(windowName))
                    .collect(Collectors.toList());

            assertWithMessage("There must be exactly one window among all DisplayAreas.")
                    .that(result.size()).isAtMost(1);

            return result.stream().findFirst().orElse(null);
        }

        ArrayList<Task> getRootTasks() {
            return mRootTasks;
        }

        int getDpi() {
            return mDpi;
        }

        Rect getDisplayRect() {
            return mDisplayRect;
        }

        public Rect getAppRect() {
            return mAppRect;
        }

        int getFlags() {
            return mFlags;
        }

        int getSurfaceSize() {
            return mSurfaceSize;
        }

        String getFocusedApp() {
            return mFocusedApp;
        }

        String getLastTransition() { return mLastTransition; }

        String getAppTransitionState() { return mAppTransitionState; }

        @Override
        public String toString() {
            return "Display #" + mId + ": name=" + mName + " mDisplayRect=" + mDisplayRect
                    + " mAppRect=" + mAppRect + " mFlags=" + mFlags;
        }

        @Override
        public boolean equals(Object o) {
            if (o == this) {
                return true;
            }
            if (o == null) {
                return false;
            }
            if (!(o instanceof DisplayContent)) {
                return false;
            }

            DisplayContent dc = (DisplayContent) o;

            return (dc.mDisplayRect == null ? mDisplayRect == null
                    : dc.mDisplayRect.equals(mDisplayRect))
                && (dc.mAppRect == null ? mAppRect == null : dc.mAppRect.equals(mAppRect))
                && dc.mDpi == mDpi
                && dc.mFlags == mFlags
                && (dc.mName == null ? mName == null : dc.mName.equals(mName))
                && dc.mSurfaceSize == mSurfaceSize
                && (dc.mAppTransitionState == null ? mAppTransitionState == null
                    : dc.mAppTransitionState.equals(mAppTransitionState))
                && dc.mRotation == mRotation
                && dc.mFrozenToUserRotation == mFrozenToUserRotation
                && dc.mUserRotation == mUserRotation
                && dc.mFixedToUserRotationMode == mFixedToUserRotationMode
                && dc.mLastOrientation == mLastOrientation;
        }

        @Override
        public int hashCode() {
            int result = 0;
            if (mDisplayRect != null) {
                result = 31 * result + mDisplayRect.hashCode();
            }
            if (mAppRect != null) {
                result = 31 * result + mAppRect.hashCode();
            }
            result = 31 * result + mDpi;
            result = 31 * result + mFlags;
            if (mName != null) {
                result = 31 * result + mName.hashCode();
            }
            result = 31 * result + mSurfaceSize;
            if (mAppTransitionState != null) {
                result = 31 * result + mAppTransitionState.hashCode();
            }
            result = 31 * result + mRotation;
            result = 31 * result + Boolean.hashCode(mFrozenToUserRotation);
            result = 31 * result + mUserRotation;
            result = 31 * result + mFixedToUserRotationMode;
            result = 31 * result + mLastOrientation;
            return result;
        }
    }

    public static class Task extends ActivityContainer {
        int mTaskId;
        int mRootTaskId;
        public int mDisplayId;
        Rect mLastNonFullscreenBounds;
        String mRealActivity;
        String mOrigActivity;
        ArrayList<Task> mTasks = new ArrayList<>();
        /** Contains TaskFragment but not Task children */
        ArrayList<TaskFragment> mTaskFragments = new ArrayList<>();
        ArrayList<Activity> mActivities = new ArrayList<>();
        int mTaskType;
        private int mResizeMode;
        String mResumedActivity;
        boolean mAnimatingBounds;
        private int mSurfaceWidth;
        private int mSurfaceHeight;
        boolean mCreatedByOrganizer;
        String mAffinity;
        boolean mHasChildPipActivity;
        WindowContainer mParent;

        Task(TaskProto proto, WindowContainer parent) {
            super(proto.taskFragment.windowContainer);
            mTaskId = proto.id;
            mRootTaskId = proto.rootTaskId;
            mParent = parent;
            mDisplayId = proto.taskFragment.displayId;
            mLastNonFullscreenBounds = extract(proto.lastNonFullscreenBounds);
            mRealActivity = proto.realActivity;
            mOrigActivity = proto.origActivity;
            mTaskType = proto.taskFragment.activityType;
            mResizeMode = proto.resizeMode;
            mFullscreen = proto.fillsParent;
            mBounds = extract(proto.bounds);
            mMinWidth = proto.taskFragment.minWidth;
            mMinHeight = proto.taskFragment.minHeight;
            mAnimatingBounds = proto.animatingBounds;
            mSurfaceWidth = proto.surfaceWidth;
            mSurfaceHeight = proto.surfaceHeight;
            mCreatedByOrganizer = proto.createdByOrganizer;
            mAffinity = proto.affinity;
            mHasChildPipActivity = proto.hasChildPipActivity;

            if (proto.resumedActivity != null) {
                mResumedActivity = proto.resumedActivity.title;
            }

            collectChildrenOfType(Task.class, this, mTasks);
            collectChildrenOfType(TaskFragment.class, this, mTaskFragments);
            collectChildrenOfType(Activity.class, this, mActivities);
        }

        boolean isEmpty() {
            return mTasks.isEmpty() && mTaskFragments.isEmpty() && mActivities.isEmpty();
        }

        /** Gets the pure parent TaskFragment if exist. */
        public TaskFragment getParentTaskFragment() {
            if (mParent instanceof TaskFragment) {
                return (TaskFragment) mParent;
            }
            if (mParent instanceof Task) {
                return ((Task) mParent).getParentTaskFragment();
            }
            // If the parent is a TaskDisplayArea, it means this Task doesn't have TaskFragment
            // parent.
            return null;
        }

        public int getResizeMode() {
            return mResizeMode;
        }

        public int getTaskId() {
            return mTaskId;
        }
        boolean isRootTask() {
            return mTaskId == mRootTaskId;
        }

        boolean isLeafTask() {
            return mTasks.size() == 0;
        }

        public int getRootTaskId() {
            return mRootTaskId;
        }

        int getSurfaceWidth() {
            return mSurfaceWidth;
        }

        int getSurfaceHeight() {
            return mSurfaceHeight;
        }

        public String getAffinity() { return mAffinity; }

        public ArrayList<Activity> getActivities() {
            return mActivities;
        }

        /** @return the top task in the root task. */
        Task getTopTask() {
            // NOTE: Unlike the WindowManager internals, we dump the state from top to bottom,
            //       so the indices are inverted
            return getTask((t) -> true);
        }

        public String getResumedActivity() {
            return mResumedActivity;
        }

        public List<Task> getTasks() {
            return new ArrayList<>(mTasks);
        }

        /** Returns non-Task leaf {@link TaskFragment} list. */
        public List<TaskFragment> getTaskFragments() {
            return new ArrayList<>(mTaskFragments);
        }

        Task getTask(Predicate<Task> predicate) {
            for (Task task : mTasks) {
                if (predicate.test(task)) return task;
            }
            return predicate.test(this) ? this : null;
        }

        Task getTask(int taskId) {
            return getTask((t) -> t.mTaskId == taskId);
        }

        void forAllTasks(Consumer<Task> consumer) {
            for (Task task : mTasks) {
                consumer.accept(task);
            }
            consumer.accept(this);
        }

        Activity getActivity(Predicate<Activity> predicate) {
            for (Activity activity : mActivities) {
                if (predicate.test(activity)) return activity;
            }
            for (TaskFragment taskFragment : mTaskFragments) {
                final Activity activity = taskFragment.getActivity(predicate);
                if (activity != null) return activity;
            }
            for (Task task : mTasks) {
                final Activity activity = task.getActivity(predicate);
                if (activity != null) return activity;
            }
            return null;
        }

        public Activity getActivity(ComponentName activityName) {
            final String fullName = getActivityName(activityName);
            return getActivity((activity) -> activity.name.equals(fullName));
        }

        public Activity getActivity(ComponentName activityName, int[] excludeTaskIds) {
            final String fullName = getActivityName(activityName);
            return getActivity((activity) -> {
                if (!activity.name.equals(fullName)) {
                    return false;
                }
                for (int excludeTaskId : excludeTaskIds) {
                    if (activity.getTask().mTaskId == excludeTaskId) {
                        return false;
                    }
                }
                return true;
            });
        }

        boolean containsActivity(ComponentName activityName) {
            return getActivity(activityName) != null;
        }

        @Override
        int getActivityType() {
            return mTaskType;
        }
    }

    public static class TaskFragment extends ActivityContainer {
        public int mDisplayId;
        Task mParentTask;
        ArrayList<Task> mTasks = new ArrayList<>();
        ArrayList<TaskFragment> mTaskFragments = new ArrayList<>();
        ArrayList<Activity> mActivities = new ArrayList<>();
        int mTaskFragmentType;

        TaskFragment(TaskFragmentProto proto, WindowContainer parent) {
            super(proto.windowContainer);
            mParentTask = (Task) parent;
            mDisplayId = proto.displayId;
            mTaskFragmentType = proto.activityType;
            mMinWidth = proto.minWidth;
            mMinHeight = proto.minHeight;

            collectChildrenOfType(Task.class, this, mTasks);
            collectChildrenOfType(TaskFragment.class, this, mTaskFragments);
            collectChildrenOfType(Activity.class, this, mActivities);
        }

        public List<Task> getTasks() {
            return mTasks;
        }

        /** Returns non-Task TaskFragment children. */
        public List<TaskFragment> getTaskFragments() {
            return mTaskFragments;
        }

        public List<Activity> getActivities() {
            return mActivities;
        }

        Activity getActivity(Predicate<Activity> predicate) {
            for (Activity activity : mActivities) {
                if (predicate.test(activity)) {
                    return activity;
                }
            }
            for (TaskFragment taskFragment : mTaskFragments) {
                final Activity activity = taskFragment.getActivity(predicate);
                if (activity != null) {
                    return activity;
                }
            }
            for (Task task : mTasks) {
                final Activity activity = task.getActivity(predicate);
                if (activity != null) {
                    return activity;
                }
            }
            return null;
        }

        @Override
        int getActivityType() {
            return mTaskFragmentType;
        }
    }

    public static class Activity extends ActivityContainer {

        String name;
        String state;
        boolean visible;
        boolean frontOfTask;
        boolean inSizeCompatMode;
        float minAspectRatio;
        boolean providesMaxBounds;
        int procId = -1;
        public boolean translucent;
        private WindowContainer mParent;

        Activity(ActivityRecordProto proto, WindowContainer parent) {
            super(proto.windowToken.windowContainer);
            name = proto.name;
            state = proto.state;
            visible = proto.visible;
            frontOfTask = proto.frontOfTask;
            inSizeCompatMode = proto.inSizeCompatMode;
            minAspectRatio = proto.minAspectRatio;
            providesMaxBounds = proto.providesMaxBounds;
            if (proto.procId != 0) {
                procId = proto.procId;
            }
            translucent = proto.translucent;
            mParent = parent;
        }

        @NonNull
        public Task getTask() {
            if (mParent instanceof Task) {
                return (Task) mParent;
            }
            return ((TaskFragment) mParent).mParentTask;
        }

        @Nullable
        public TaskFragment getTaskFragment() {
            if (mParent instanceof TaskFragment) {
                return (TaskFragment) mParent;
            }
            return ((Task) mParent).getParentTaskFragment();
        }

        public String getName() {
            return name;
        }

        public String getState() {
            return state;
        }

        public boolean inSizeCompatMode() {
            return inSizeCompatMode;
        }

        public float getMinAspectRatio() {
            return minAspectRatio;
        }

        public boolean providesMaxBounds() {
            return providesMaxBounds;
        }

        @Override
        public Rect getBounds() {
            if (mBounds == null) {
                return mFullConfiguration.windowConfiguration.getBounds();
            }
            return mBounds;
        }

        public Rect getMaxBounds() {
            return mFullConfiguration.windowConfiguration.getMaxBounds();
        }

        public Rect getAppBounds() {
            return mFullConfiguration.windowConfiguration.getAppBounds();
        }
    }

    static abstract class ActivityContainer extends WindowContainer {
        protected boolean mFullscreen;
        protected Rect mBounds;
        protected int mMinWidth = -1;
        protected int mMinHeight = -1;

        ActivityContainer(WindowContainerProto proto) {
            super(proto);
        }

        public Rect getBounds() {
            return mBounds;
        }

        boolean isFullscreen() {
            return mFullscreen;
        }

        int getMinWidth() {
            return mMinWidth;
        }

        int getMinHeight() {
            return mMinHeight;
        }
    }

    static class KeyguardControllerState {

        boolean aodShowing = false;
        boolean keyguardShowing = false;
        SparseArray<Boolean> mKeyguardOccludedStates = new SparseArray<>();

        KeyguardControllerState(KeyguardControllerProto proto) {
            if (proto != null) {
                aodShowing = proto.aodShowing;
                keyguardShowing = proto.keyguardShowing;
                for (int i = 0;  i < proto.keyguardOccludedStates.length; i++) {
                    mKeyguardOccludedStates.append(proto.keyguardOccludedStates[i].displayId,
                            proto.keyguardOccludedStates[i].keyguardOccluded);
                }
            }
        }

        boolean isKeyguardOccluded(int displayId) {
            if (mKeyguardOccludedStates.get(displayId) != null) {
                return mKeyguardOccludedStates.get(displayId);
            }
            return false;
        }
    }

    static class ConfigurationContainer {
        final Configuration mOverrideConfiguration = new Configuration();
        final Configuration mFullConfiguration = new Configuration();
        final Configuration mMergedOverrideConfiguration = new Configuration();

        ConfigurationContainer(ConfigurationContainerProto proto) {
            if (proto == null) {
                return;
            }
            mOverrideConfiguration.setTo(extract(proto.overrideConfiguration));
            mFullConfiguration.setTo(extract(proto.fullConfiguration));
            mMergedOverrideConfiguration.setTo(extract(proto.mergedOverrideConfiguration));
        }

        boolean isWindowingModeCompatible(int requestedWindowingMode) {
            if (requestedWindowingMode == WINDOWING_MODE_UNDEFINED) {
                return true;
            }
            return getWindowingMode() == requestedWindowingMode;
        }

        public int getWindowingMode() {
            if (mFullConfiguration == null) {
                return WINDOWING_MODE_UNDEFINED;
            }
            return mFullConfiguration.windowConfiguration.getWindowingMode();
        }

        int getActivityType() {
            if (mFullConfiguration == null) {
                return ACTIVITY_TYPE_UNDEFINED;
            }
            return mFullConfiguration.windowConfiguration.getActivityType();
        }
    }

    public static class RootWindowContainer extends WindowContainer {
        RootWindowContainer(RootWindowContainerProto proto) {
            super(proto.windowContainer);
        }
    }
    public static class DisplayArea extends WindowContainer {
        private final boolean mIsTaskDisplayArea;
        private final boolean mIsRootDisplayArea;
        private final int mFeatureId;
        private final boolean mIsOrganized;
        private ArrayList<Activity> mActivities;
        private final ArrayList<WindowState> mWindows = new ArrayList<>();

        DisplayArea(DisplayAreaProto proto) {
            super(proto.windowContainer);
            mIsTaskDisplayArea = proto.isTaskDisplayArea;
            mIsRootDisplayArea = proto.isRootDisplayArea;
            mFeatureId = proto.featureId;
            mIsOrganized = proto.isOrganized;
            if (mIsTaskDisplayArea) {
                mActivities = new ArrayList<>();
                collectDescendantsOfType(Activity.class, this, mActivities);
            }
            collectDescendantsOfType(WindowState.class, this, mWindows);
        }

        boolean isTaskDisplayArea() {
            return mIsTaskDisplayArea;
        }

        boolean isRootDisplayArea() {
            return mIsRootDisplayArea;
        }

        int getFeatureId() {
            return mFeatureId;
        }

        boolean isOrganized() {
            return mIsOrganized;
        }

        @Override
        public Rect getBounds() {
            if (mBounds == null) {
                return mFullConfiguration.windowConfiguration.getBounds();
            }
            return mBounds;
        }

        boolean containsActivity(ComponentName activityName) {
            if (!mIsTaskDisplayArea) {
                return false;
            }

            final String fullName = getActivityName(activityName);
            for (Activity a : mActivities) {
                if (a.name.equals(fullName)) {
                    return true;
                }
            }
            return false;
        }

        boolean containsWindow(String windowName) {
            for (WindowState w : mWindows) {
                if (w.mName.equals(windowName)) {
                    return true;
                }
            }
            return false;
        }
    }
    public static class WindowToken extends WindowContainer {
        WindowToken(WindowTokenProto proto) {
            super(proto.windowContainer);
        }
    }

    /**
     * Represents WindowContainer classes such as DisplayContent.WindowContainers and
     * DisplayContent.NonAppWindowContainers. This can be expanded into a specific class
     * if we need track and assert some state in the future.
     */
    public static class GenericWindowContainer extends WindowContainer {
        GenericWindowContainer(WindowContainerProto proto) {
            super(proto);
        }
    }

    static WindowContainer getWindowContainer(WindowContainerChildProto proto,
            WindowContainer parent) {
        if (proto.displayContent != null) {
            return new DisplayContent(proto.displayContent);
        }

        if (proto.displayArea != null) {
            return new DisplayArea(proto.displayArea);
        }

        if (proto.task != null) {
            return new Task(proto.task, parent);
        }

        if (proto.taskFragment != null) {
            return new TaskFragment(proto.taskFragment, parent);
        }

        if (proto.activity != null) {
            return new Activity(proto.activity, parent);
        }

        if (proto.windowToken != null) {
            return new WindowToken(proto.windowToken);
        }

        if (proto.window != null) {
            return new WindowState(proto.window);
        }

        if (proto.windowContainer != null) {
            return new GenericWindowContainer(proto.windowContainer);
        }
        return null;
    }

    static abstract class WindowContainer extends ConfigurationContainer {

        protected String mName;
        protected final String mAppToken;
        protected boolean mFullscreen;
        protected Rect mBounds;
        protected int mOrientation;
        protected boolean mVisible;
        protected List<WindowState> mSubWindows = new ArrayList<>();
        protected List<WindowContainer> mChildren = new ArrayList<>();

        WindowContainer(WindowContainerProto proto) {
            super(proto.configurationContainer);
            IdentifierProto identifierProto = proto.identifier;
            mName = identifierProto.title;
            mAppToken = Integer.toHexString(identifierProto.hashCode);
            mOrientation = proto.orientation;
            for (int i = 0; i < proto.children.length; i++) {
                final WindowContainer child = getWindowContainer(proto.children[i], this);
                if (child != null) {
                    mChildren.add(child);
                }
            }
            mVisible = proto.visible;
        }

        @NonNull
        public String getName() {
            return mName;
        }

        @NonNull
        public String getPackageName() {
            int sep = mName.indexOf('/');
            return sep == -1 ? mName : mName.substring(0, sep);
        }

        String getToken() {
            return mAppToken;
        }

        Rect getBounds() {
            return mBounds;
        }

        boolean isFullscreen() {
            return mFullscreen;
        }

        boolean isVisible() {
            return mVisible;
        }

        List<WindowState> getWindows() {
            return mSubWindows;
        }
    }

    public static class WindowState extends WindowContainer {

        private static final int WINDOW_TYPE_NORMAL = 0;
        public static final int WINDOW_TYPE_STARTING = 1;
        private static final int WINDOW_TYPE_EXITING = 2;
        private static final int WINDOW_TYPE_DEBUGGER = 3;

        private final int mWindowType;
        private int mType = 0;
        private int mDisplayId;
        private int mStackId;
        private int mLayer;
        private boolean mShown;
        private Rect mContainingFrame;
        private Rect mParentFrame;
        private Rect mFrame;
        private Rect mCompatFrame;
        private Rect mSurfaceInsets = new Rect();
        private Rect mGivenContentInsets = new Rect();
        private Rect mCrop = new Rect();
        private boolean mHasCompatScale;
        private float mGlobalScale;
        private int mRequestedWidth;
        private int mRequestedHeight;

        WindowState(WindowStateProto proto) {
            super(proto.windowContainer);
            mDisplayId = proto.displayId;
            mStackId = proto.stackId;
            if (proto.attributes != null) {
                mType = proto.attributes.type;
            }
            WindowStateAnimatorProto animatorProto = proto.animator;
            if (animatorProto != null) {
                if (animatorProto.surface != null) {
                    WindowSurfaceControllerProto surfaceProto = animatorProto.surface;
                    mShown = surfaceProto.shown;
                    mLayer = surfaceProto.layer;
                }
                mCrop = extract(animatorProto.lastClipRect);
            }
            mGivenContentInsets = extract(proto.givenContentInsets);
            WindowFramesProto windowFramesProto = proto.windowFrames;
            if (windowFramesProto != null) {
                mFrame = extract(windowFramesProto.frame);
                mContainingFrame = extract(windowFramesProto.containingFrame);
                mParentFrame = extract(windowFramesProto.parentFrame);
                mCompatFrame = extract(windowFramesProto.compatFrame);
            }
            mSurfaceInsets = extract(proto.surfaceInsets);
            if (mName.startsWith(STARTING_WINDOW_PREFIX)) {
                mWindowType = WINDOW_TYPE_STARTING;
                // Existing code depends on the prefix being removed
                mName = mName.substring(STARTING_WINDOW_PREFIX.length());
            } else if (proto.animatingExit) {
                mWindowType = WINDOW_TYPE_EXITING;
            } else if (mName.startsWith(DEBUGGER_WINDOW_PREFIX)) {
                mWindowType = WINDOW_TYPE_STARTING;
                mName = mName.substring(DEBUGGER_WINDOW_PREFIX.length());
            } else {
                mWindowType = 0;
            }
            collectDescendantsOfType(WindowState.class, this, mSubWindows);
            mHasCompatScale = proto.hasCompatScale;
            mGlobalScale = proto.globalScale;
            mRequestedWidth = proto.requestedWidth;
            mRequestedHeight = proto.requestedHeight;
        }

        boolean isStartingWindow() {
            return mWindowType == WINDOW_TYPE_STARTING;
        }

        boolean isExitingWindow() {
            return mWindowType == WINDOW_TYPE_EXITING;
        }

        boolean isDebuggerWindow() {
            return mWindowType == WINDOW_TYPE_DEBUGGER;
        }

        int getDisplayId() {
            return mDisplayId;
        }

        int getStackId() {
            return mStackId;
        }

        Rect getContainingFrame() {
            return mContainingFrame;
        }

        public Rect getFrame() {
            return mFrame;
        }

        Rect getSurfaceInsets() {
            return mSurfaceInsets;
        }

        Rect getGivenContentInsets() {
            return mGivenContentInsets;
        }

        Rect getParentFrame() {
            return mParentFrame;
        }

        public Rect getCompatFrame() {
            return mCompatFrame;
        }

        Rect getCrop() {
            return mCrop;
        }

        public boolean isSurfaceShown() {
            return mShown;
        }

        public int getType() {
            return mType;
        }

        public boolean hasCompatScale() {
            return mHasCompatScale;
        }

        public float getGlobalScale() {
            return mGlobalScale;
        }

        public int getRequestedWidth() {
            return mRequestedWidth;
        }

        public int getRequestedHeight() {
            return mRequestedHeight;
        }

        private String getWindowTypeSuffix(int windowType) {
            switch (windowType) {
                case WINDOW_TYPE_STARTING:
                    return " STARTING";
                case WINDOW_TYPE_EXITING:
                    return " EXITING";
                case WINDOW_TYPE_DEBUGGER:
                    return " DEBUGGER";
                default:
                    break;
            }
            return "";
        }

        @Override
        public String toString() {
            return "WindowState: {" + mAppToken + " " + mName
                    + getWindowTypeSuffix(mWindowType) + "}" + " type=" + mType
                    + " cf=" + mContainingFrame + " pf=" + mParentFrame;
        }

        public String toLongString() {
            return toString() + " f=" + mFrame + " crop=" + mCrop + " isSurfaceShown="
                    + isSurfaceShown();
        }
    }

    static int dpToPx(float dp, int densityDpi) {
        return (int) (dp * densityDpi / DENSITY_DEFAULT + 0.5f);
    }

    int defaultMinimalTaskSize(int displayId) {
        return dpToPx(mDefaultMinSizeOfResizableTaskDp, getDisplay(displayId).getDpi());
    }

    int defaultMinimalDisplaySizeForSplitScreen(int displayId) {
        return dpToPx(ActivityTaskManager.DEFAULT_MINIMAL_SPLIT_SCREEN_DISPLAY_SIZE_DP,
                getDisplay(displayId).getDpi());
    }
}

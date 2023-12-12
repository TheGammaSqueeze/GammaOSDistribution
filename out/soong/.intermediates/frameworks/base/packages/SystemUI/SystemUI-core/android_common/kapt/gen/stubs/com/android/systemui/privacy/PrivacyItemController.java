package com.android.systemui.privacy;

import android.app.AppOpsManager;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.UserInfo;
import android.os.UserHandle;
import android.provider.DeviceConfig;
import com.android.internal.annotations.VisibleForTesting;
import com.android.internal.config.sysui.SystemUiDeviceConfigFlags;
import com.android.systemui.Dumpable;
import com.android.systemui.appops.AppOpItem;
import com.android.systemui.appops.AppOpsController;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.privacy.logging.PrivacyLogger;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.DeviceConfigProxy;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.time.SystemClock;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.lang.ref.WeakReference;
import java.util.concurrent.Executor;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00aa\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\n\n\u0002\u0018\u0002\n\u0002\b\t\b\u0007\u0018\u0000 [2\u00020\u0001:\u0004Z[\\]BK\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0001\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\u0002\u0010\u0011J\u000e\u0010?\u001a\u00020@2\u0006\u0010A\u001a\u00020\u001bJ\u0016\u0010?\u001a\u00020@2\f\u0010A\u001a\b\u0012\u0004\u0012\u00020\u001b0\u001aH\u0002J-\u0010B\u001a\u00020@2\u0006\u0010C\u001a\u00020D2\u0006\u0010E\u001a\u00020F2\u000e\u0010G\u001a\n\u0012\u0006\b\u0001\u0012\u00020I0HH\u0016\u00a2\u0006\u0002\u0010JJ\b\u0010K\u001a\u00020\u0013H\u0002J\b\u0010L\u001a\u00020\u0013H\u0002J\u001c\u0010M\u001a\b\u0012\u0004\u0012\u00020/0\u001f2\f\u0010N\u001a\b\u0012\u0004\u0012\u00020/0\u001fH\u0002J\b\u0010O\u001a\u00020@H\u0002J\u000e\u0010P\u001a\u00020@2\u0006\u0010A\u001a\u00020\u001bJ\u0016\u0010P\u001a\u00020@2\f\u0010A\u001a\b\u0012\u0004\u0012\u00020\u001b0\u001aH\u0002J\b\u0010Q\u001a\u00020@H\u0002J\u0012\u0010R\u001a\u0004\u0018\u00010/2\u0006\u0010S\u001a\u00020TH\u0002J\b\u0010U\u001a\u00020@H\u0002J\u0010\u0010V\u001a\u00020@2\u0006\u0010W\u001a\u00020\u0013H\u0002J\b\u0010X\u001a\u00020@H\u0002J\u001b\u0010Y\u001a\u00020\u0013*\u00020/2\f\u0010N\u001a\b\u0012\u0004\u0012\u00020/0\u001fH\u0082\u0004R\u001a\u0010\u0012\u001a\u00020\u0013X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0014\u0010\u0015\"\u0004\b\u0016\u0010\u0017R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0018\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u001b0\u001a0\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u001dX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001e\u001a\b\u0012\u0004\u0012\u00020 0\u001fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010!\u001a\u00020\"X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010#\u001a\u0004\u0018\u00010$X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010%\u001a\u00060&R\u00020\u0000X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010(\u001a\u00020\u0013X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b)\u0010\u0015\"\u0004\b*\u0010\u0017R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010,\u001a\u00020\u00132\u0006\u0010+\u001a\u00020\u0013@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b-\u0010\u0015R\u000e\u0010.\u001a\u00020$X\u0082\u0004\u00a2\u0006\u0002\n\u0000R8\u00100\u001a\b\u0012\u0004\u0012\u00020/0\u001f2\f\u0010+\u001a\b\u0012\u0004\u0012\u00020/0\u001f8@@@X\u0081\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b1\u00102\u001a\u0004\b3\u00104\"\u0004\b5\u00106R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00107\u001a\u00020$X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u00108\u001a\u0002098\u0000@\u0000X\u0081\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b:\u00102\u001a\u0004\b;\u0010<\"\u0004\b=\u0010>"}, d2 = {"Lcom/android/systemui/privacy/PrivacyItemController;", "Lcom/android/systemui/Dumpable;", "appOpsController", "Lcom/android/systemui/appops/AppOpsController;", "uiExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "bgExecutor", "deviceConfigProxy", "Lcom/android/systemui/util/DeviceConfigProxy;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "logger", "Lcom/android/systemui/privacy/logging/PrivacyLogger;", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Lcom/android/systemui/appops/AppOpsController;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/util/DeviceConfigProxy;Lcom/android/systemui/settings/UserTracker;Lcom/android/systemui/privacy/logging/PrivacyLogger;Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/dump/DumpManager;)V", "allIndicatorsAvailable", "", "getAllIndicatorsAvailable", "()Z", "setAllIndicatorsAvailable", "(Z)V", "callbacks", "", "Ljava/lang/ref/WeakReference;", "Lcom/android/systemui/privacy/PrivacyItemController$Callback;", "cb", "Lcom/android/systemui/appops/AppOpsController$Callback;", "currentUserIds", "", "", "devicePropertiesChangedListener", "Landroid/provider/DeviceConfig$OnPropertiesChangedListener;", "holdingRunnableCanceler", "Ljava/lang/Runnable;", "internalUiExecutor", "Lcom/android/systemui/privacy/PrivacyItemController$MyExecutor;", "listening", "locationAvailable", "getLocationAvailable", "setLocationAvailable", "<set-?>", "micCameraAvailable", "getMicCameraAvailable", "notifyChanges", "Lcom/android/systemui/privacy/PrivacyItem;", "privacyList", "getPrivacyList$main$annotations", "()V", "getPrivacyList$main", "()Ljava/util/List;", "setPrivacyList$main", "(Ljava/util/List;)V", "updateListAndNotifyChanges", "userTrackerCallback", "Lcom/android/systemui/settings/UserTracker$Callback;", "getUserTrackerCallback$main$annotations", "getUserTrackerCallback$main", "()Lcom/android/systemui/settings/UserTracker$Callback;", "setUserTrackerCallback$main", "(Lcom/android/systemui/settings/UserTracker$Callback;)V", "addCallback", "", "callback", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "isLocationEnabled", "isMicCameraEnabled", "processNewList", "list", "registerReceiver", "removeCallback", "setListeningState", "toPrivacyItem", "appOpItem", "Lcom/android/systemui/appops/AppOpItem;", "unregisterListener", "update", "updateUsers", "updatePrivacyList", "isIn", "Callback", "Companion", "MyExecutor", "NotifyChangesToCallback"})
@com.android.systemui.dagger.SysUISingleton()
public final class PrivacyItemController implements com.android.systemui.Dumpable {
    @org.jetbrains.annotations.NotNull()
    private java.util.List<com.android.systemui.privacy.PrivacyItem> privacyList;
    private java.util.List<java.lang.Integer> currentUserIds;
    private boolean listening = false;
    private final java.util.List<java.lang.ref.WeakReference<com.android.systemui.privacy.PrivacyItemController.Callback>> callbacks = null;
    private final com.android.systemui.privacy.PrivacyItemController.MyExecutor internalUiExecutor = null;
    private java.lang.Runnable holdingRunnableCanceler;
    private final java.lang.Runnable notifyChanges = null;
    private final java.lang.Runnable updateListAndNotifyChanges = null;
    private boolean micCameraAvailable;
    private boolean locationAvailable;
    private boolean allIndicatorsAvailable;
    private final android.provider.DeviceConfig.OnPropertiesChangedListener devicePropertiesChangedListener = null;
    private final com.android.systemui.appops.AppOpsController.Callback cb = null;
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.settings.UserTracker.Callback userTrackerCallback;
    private final com.android.systemui.appops.AppOpsController appOpsController = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor bgExecutor = null;
    private final com.android.systemui.util.DeviceConfigProxy deviceConfigProxy = null;
    private final com.android.systemui.settings.UserTracker userTracker = null;
    private final com.android.systemui.privacy.logging.PrivacyLogger logger = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    @org.jetbrains.annotations.NotNull()
    private static final int[] OPS_MIC_CAMERA = {26, 101, 27, 100};
    @org.jetbrains.annotations.NotNull()
    private static final int[] OPS_LOCATION = {0, 1};
    @org.jetbrains.annotations.NotNull()
    private static final int[] OPS = null;
    @org.jetbrains.annotations.NotNull()
    private static final android.content.IntentFilter intentFilter = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String TAG = "PrivacyItemController";
    private static final java.lang.String MIC_CAMERA = "camera_mic_icons_enabled";
    private static final java.lang.String LOCATION = "location_indicators_enabled";
    private static final boolean DEFAULT_MIC_CAMERA = true;
    private static final boolean DEFAULT_LOCATION = false;
    public static final long TIME_TO_HOLD_INDICATORS = 5000L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.privacy.PrivacyItemController.Companion Companion = null;
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getPrivacyList$main$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final synchronized java.util.List<com.android.systemui.privacy.PrivacyItem> getPrivacyList$main() {
        return null;
    }
    
    public final synchronized void setPrivacyList$main(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.privacy.PrivacyItem> p0) {
    }
    
    private final boolean isMicCameraEnabled() {
        return false;
    }
    
    private final boolean isLocationEnabled() {
        return false;
    }
    
    public final boolean getMicCameraAvailable() {
        return false;
    }
    
    public final boolean getLocationAvailable() {
        return false;
    }
    
    public final void setLocationAvailable(boolean p0) {
    }
    
    public final boolean getAllIndicatorsAvailable() {
        return false;
    }
    
    public final void setAllIndicatorsAvailable(boolean p0) {
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getUserTrackerCallback$main$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.settings.UserTracker.Callback getUserTrackerCallback$main() {
        return null;
    }
    
    public final void setUserTrackerCallback$main(@org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker.Callback p0) {
    }
    
    private final void unregisterListener() {
    }
    
    private final void registerReceiver() {
    }
    
    private final void update(boolean updateUsers) {
    }
    
    /**
     * Updates listening status based on whether there are callbacks and the indicators are enabled.
     *
     * Always listen to all OPS so we don't have to figure out what we should be listening to. We
     * still have to filter anyway. Updates are filtered in the callback.
     *
     * This is only called from private (add/remove)Callback and from the config listener, all in
     * main thread.
     */
    private final void setListeningState() {
    }
    
    private final void addCallback(java.lang.ref.WeakReference<com.android.systemui.privacy.PrivacyItemController.Callback> callback) {
    }
    
    private final void removeCallback(java.lang.ref.WeakReference<com.android.systemui.privacy.PrivacyItemController.Callback> callback) {
    }
    
    public final void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyItemController.Callback callback) {
    }
    
    public final void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyItemController.Callback callback) {
    }
    
    private final void updatePrivacyList() {
    }
    
    /**
     * Figure out which items have not been around for long enough and put them back in the list.
     *
     * Also schedule when we should check again to remove expired items. Because we always retrieve
     * the current list, we have the latest info.
     *
     * @param list map of list retrieved from [AppOpsController].
     * @return a list that may have added items that should be kept for some time.
     */
    private final java.util.List<com.android.systemui.privacy.PrivacyItem> processNewList(java.util.List<com.android.systemui.privacy.PrivacyItem> list) {
        return null;
    }
    
    /**
     * Ignores the paused status to determine if the element is in the list
     */
    private final boolean isIn(com.android.systemui.privacy.PrivacyItem $this$isIn, java.util.List<com.android.systemui.privacy.PrivacyItem> list) {
        return false;
    }
    
    private final com.android.systemui.privacy.PrivacyItem toPrivacyItem(com.android.systemui.appops.AppOpItem appOpItem) {
        return null;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public PrivacyItemController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.appops.AppOpsController appOpsController, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor uiExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    com.android.systemui.util.concurrency.DelayableExecutor bgExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.DeviceConfigProxy deviceConfigProxy, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.logging.PrivacyLogger logger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010 \n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\u0017J\u0010\u0010\u0006\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\u0017J\u0010\u0010\u0007\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\u0017J\u0016\u0010\b\u001a\u00020\u00032\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u000b0\nH&\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/privacy/PrivacyItemController$Callback;", "", "onFlagAllChanged", "", "flag", "", "onFlagLocationChanged", "onFlagMicCameraChanged", "onPrivacyItemsChanged", "privacyItems", "", "Lcom/android/systemui/privacy/PrivacyItem;"})
    public static abstract interface Callback {
        
        public abstract void onPrivacyItemsChanged(@org.jetbrains.annotations.NotNull()
        java.util.List<com.android.systemui.privacy.PrivacyItem> privacyItems);
        
        public default void onFlagAllChanged(boolean flag) {
        }
        
        public default void onFlagMicCameraChanged(boolean flag) {
        }
        
        public default void onFlagLocationChanged(boolean flag) {
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\b\u0002\u0018\u00002\u00020\u0001B\u001d\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u00a2\u0006\u0002\u0010\u0007J\b\u0010\b\u001a\u00020\tH\u0016R\u0010\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/privacy/PrivacyItemController$NotifyChangesToCallback;", "Ljava/lang/Runnable;", "callback", "Lcom/android/systemui/privacy/PrivacyItemController$Callback;", "list", "", "Lcom/android/systemui/privacy/PrivacyItem;", "(Lcom/android/systemui/privacy/PrivacyItemController$Callback;Ljava/util/List;)V", "run", ""})
    static final class NotifyChangesToCallback implements java.lang.Runnable {
        private final com.android.systemui.privacy.PrivacyItemController.Callback callback = null;
        private final java.util.List<com.android.systemui.privacy.PrivacyItem> list = null;
        
        @java.lang.Override()
        public void run() {
        }
        
        public NotifyChangesToCallback(@org.jetbrains.annotations.Nullable()
        com.android.systemui.privacy.PrivacyItemController.Callback callback, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.systemui.privacy.PrivacyItem> list) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\b\u0082\u0004\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\u0006H\u0016J\u0006\u0010\n\u001a\u00020\bR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0005\u001a\u0004\u0018\u00010\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/privacy/PrivacyItemController$MyExecutor;", "Ljava/util/concurrent/Executor;", "delegate", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "(Lcom/android/systemui/privacy/PrivacyItemController;Lcom/android/systemui/util/concurrency/DelayableExecutor;)V", "listeningCanceller", "Ljava/lang/Runnable;", "execute", "", "command", "updateListeningState"})
    final class MyExecutor implements java.util.concurrent.Executor {
        private java.lang.Runnable listeningCanceller;
        private final com.android.systemui.util.concurrency.DelayableExecutor delegate = null;
        
        @java.lang.Override()
        public void execute(@org.jetbrains.annotations.NotNull()
        java.lang.Runnable command) {
        }
        
        public final void updateListeningState() {
        }
        
        public MyExecutor(@org.jetbrains.annotations.NotNull()
        com.android.systemui.util.concurrency.DelayableExecutor delegate) {
            super();
        }
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u0015\n\u0002\b\b\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0081\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0082T\u00a2\u0006\u0002\n\u0000R\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\r\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\fR\u0011\u0010\u000f\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\fR\u000e\u0010\u0011\u001a\u00020\u0007X\u0086T\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0012\u001a\u00020\u00138\u0006X\u0087T\u00a2\u0006\b\n\u0000\u0012\u0004\b\u0014\u0010\u0002R\u0011\u0010\u0015\u001a\u00020\u0016\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0018"}, d2 = {"Lcom/android/systemui/privacy/PrivacyItemController$Companion;", "", "()V", "DEFAULT_LOCATION", "", "DEFAULT_MIC_CAMERA", "LOCATION", "", "MIC_CAMERA", "OPS", "", "getOPS", "()[I", "OPS_LOCATION", "getOPS_LOCATION", "OPS_MIC_CAMERA", "getOPS_MIC_CAMERA", "TAG", "TIME_TO_HOLD_INDICATORS", "", "getTIME_TO_HOLD_INDICATORS$annotations", "intentFilter", "Landroid/content/IntentFilter;", "getIntentFilter", "()Landroid/content/IntentFilter;"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final int[] getOPS_MIC_CAMERA() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final int[] getOPS_LOCATION() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final int[] getOPS() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.content.IntentFilter getIntentFilter() {
            return null;
        }
        
        @com.android.internal.annotations.VisibleForTesting()
        @java.lang.Deprecated()
        public static void getTIME_TO_HOLD_INDICATORS$annotations() {
        }
        
        private Companion() {
            super();
        }
    }
}
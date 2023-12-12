package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.content.pm.UserInfo;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
import android.os.HandlerExecutor;
import android.os.UserHandle;
import android.provider.Settings;
import android.util.ArraySet;
import android.util.SparseBooleanArray;
import androidx.annotation.GuardedBy;
import androidx.annotation.WorkerThread;
import com.android.systemui.Dumpable;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.settings.GlobalSettings;
import com.android.systemui.util.settings.SecureSettings;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.concurrent.Executor;
import java.util.concurrent.atomic.AtomicBoolean;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00a8\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0002\b\u000b\b\u0017\u0018\u0000 F2\u00020\u00012\u00020\u00022\u00020\u0003:\u0001FB;\b\u0007\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\b\b\u0001\u0010\f\u001a\u00020\r\u0012\b\b\u0001\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\u0002\u0010\u0010J\u0010\u0010(\u001a\u00020)2\u0006\u0010*\u001a\u00020\u0002H\u0016J!\u0010+\u001a\u00020)2\u0017\u0010,\u001a\u0013\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020)0-\u00a2\u0006\u0002\b.H\u0004J-\u0010/\u001a\u00020)2\u0006\u00100\u001a\u0002012\u0006\u00102\u001a\u0002032\u000e\u00104\u001a\n\u0012\u0006\b\u0001\u0012\u00020605H\u0016\u00a2\u0006\u0002\u00107J\b\u00108\u001a\u00020\u0012H\u0016J\b\u00109\u001a\u00020)H\u0016J\b\u0010:\u001a\u00020;H\u0016J\b\u0010<\u001a\u00020;H\u0016J\u0010\u0010=\u001a\u00020;2\u0006\u0010>\u001a\u00020\u0012H\u0016J\b\u0010?\u001a\u00020)H\u0016J\b\u0010@\u001a\u00020)H\u0016J\b\u0010A\u001a\u00020)H\u0016J\u0010\u0010B\u001a\u00020)2\u0006\u0010*\u001a\u00020\u0002H\u0016J\u001c\u0010C\u001a\u00020)2\b\b\u0002\u0010D\u001a\u00020;2\b\b\u0002\u0010E\u001a\u00020\u0012H\u0003R\u0014\u0010\u0011\u001a\u00020\u00128BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0013\u0010\u0014R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0019\u001a\n \u001b*\u0004\u0018\u00010\u001a0\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u001d\u001a\b\u0012\u0004\u0012\u00020\u00020\u001e8\u0002X\u0083\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020 X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010!\u001a\u00020\"X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010#\u001a\u00020$X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010%\u001a\u00020&8\u0002X\u0083\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\'\u001a\n \u001b*\u0004\u0018\u00010\u001a0\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/DeviceProvisionedControllerImpl;", "Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;", "Lcom/android/systemui/statusbar/policy/DeviceProvisionedController$DeviceProvisionedListener;", "Lcom/android/systemui/Dumpable;", "secureSettings", "Lcom/android/systemui/util/settings/SecureSettings;", "globalSettings", "Lcom/android/systemui/util/settings/GlobalSettings;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "backgroundHandler", "Landroid/os/Handler;", "mainExecutor", "Ljava/util/concurrent/Executor;", "(Lcom/android/systemui/util/settings/SecureSettings;Lcom/android/systemui/util/settings/GlobalSettings;Lcom/android/systemui/settings/UserTracker;Lcom/android/systemui/dump/DumpManager;Landroid/os/Handler;Ljava/util/concurrent/Executor;)V", "_currentUser", "", "get_currentUser", "()I", "backgroundExecutor", "Landroid/os/HandlerExecutor;", "deviceProvisioned", "Ljava/util/concurrent/atomic/AtomicBoolean;", "deviceProvisionedUri", "Landroid/net/Uri;", "kotlin.jvm.PlatformType", "initted", "listeners", "Landroid/util/ArraySet;", "lock", "", "observer", "Landroid/database/ContentObserver;", "userChangedCallback", "Lcom/android/systemui/settings/UserTracker$Callback;", "userSetupComplete", "Landroid/util/SparseBooleanArray;", "userSetupUri", "addCallback", "", "listener", "dispatchChange", "callback", "Lkotlin/Function1;", "Lkotlin/ExtensionFunctionType;", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "getCurrentUser", "init", "isCurrentUserSetup", "", "isDeviceProvisioned", "isUserSetup", "user", "onDeviceProvisionedChanged", "onUserSetupChanged", "onUserSwitched", "removeCallback", "updateValues", "updateDeviceProvisioned", "updateUser", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public class DeviceProvisionedControllerImpl implements com.android.systemui.statusbar.policy.DeviceProvisionedController, com.android.systemui.statusbar.policy.DeviceProvisionedController.DeviceProvisionedListener, com.android.systemui.Dumpable {
    private final android.net.Uri deviceProvisionedUri = null;
    private final android.net.Uri userSetupUri = null;
    private final java.util.concurrent.atomic.AtomicBoolean deviceProvisioned = null;
    @androidx.annotation.GuardedBy(value = "lock")
    private final android.util.SparseBooleanArray userSetupComplete = null;
    @androidx.annotation.GuardedBy(value = "lock")
    private final android.util.ArraySet<com.android.systemui.statusbar.policy.DeviceProvisionedController.DeviceProvisionedListener> listeners = null;
    private final java.lang.Object lock = null;
    private final android.os.HandlerExecutor backgroundExecutor = null;
    private final java.util.concurrent.atomic.AtomicBoolean initted = null;
    private final android.database.ContentObserver observer = null;
    private final com.android.systemui.settings.UserTracker.Callback userChangedCallback = null;
    private final com.android.systemui.util.settings.SecureSettings secureSettings = null;
    private final com.android.systemui.util.settings.GlobalSettings globalSettings = null;
    private final com.android.systemui.settings.UserTracker userTracker = null;
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final android.os.Handler backgroundHandler = null;
    private final java.util.concurrent.Executor mainExecutor = null;
    private static final int ALL_USERS = -1;
    private static final int NO_USERS = -2;
    @org.jetbrains.annotations.NotNull()
    protected static final java.lang.String TAG = "DeviceProvisionedControllerImpl";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.policy.DeviceProvisionedControllerImpl.Companion Companion = null;
    
    private final int get_currentUser() {
        return 0;
    }
    
    @java.lang.Override()
    public int getCurrentUser() {
        return 0;
    }
    
    /**
     * Call to initialize values and register observers
     */
    public void init() {
    }
    
    @androidx.annotation.WorkerThread()
    private final void updateValues(boolean updateDeviceProvisioned, int updateUser) {
    }
    
    /**
     * Adds a listener.
     *
     * The listener will not be called when this happens.
     */
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.DeviceProvisionedController.DeviceProvisionedListener listener) {
    }
    
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.DeviceProvisionedController.DeviceProvisionedListener listener) {
    }
    
    @java.lang.Override()
    public boolean isDeviceProvisioned() {
        return false;
    }
    
    @java.lang.Override()
    public boolean isUserSetup(int user) {
        return false;
    }
    
    @java.lang.Override()
    public boolean isCurrentUserSetup() {
        return false;
    }
    
    @java.lang.Override()
    public void onDeviceProvisionedChanged() {
    }
    
    @java.lang.Override()
    public void onUserSetupChanged() {
    }
    
    @java.lang.Override()
    public void onUserSwitched() {
    }
    
    protected final void dispatchChange(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.statusbar.policy.DeviceProvisionedController.DeviceProvisionedListener, kotlin.Unit> callback) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public DeviceProvisionedControllerImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.settings.SecureSettings secureSettings, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.settings.GlobalSettings globalSettings, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    android.os.Handler backgroundHandler, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor mainExecutor) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0084T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/DeviceProvisionedControllerImpl$Companion;", "", "()V", "ALL_USERS", "", "NO_USERS", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
package com.android.systemui.settings;

import android.content.BroadcastReceiver;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.UserInfo;
import android.os.Handler;
import android.os.UserHandle;
import android.os.UserManager;
import android.util.Log;
import androidx.annotation.GuardedBy;
import androidx.annotation.WorkerThread;
import com.android.systemui.Dumpable;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.util.Assert;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.lang.IllegalStateException;
import java.lang.ref.WeakReference;
import java.util.concurrent.Executor;
import kotlin.properties.ReadWriteProperty;
import kotlin.reflect.KProperty;

/**
 * SystemUI cache for keeping track of the current user and associated values.
 *
 * The values provided asynchronously are NOT copies, but shared among all requesters. Do not
 * modify them.
 *
 * This class purposefully doesn't use [BroadcastDispatcher] in order to receive the broadcast as
 * soon as possible (and reduce its dependency graph).
 * Other classes that want to listen to the broadcasts listened here SHOULD
 * subscribe to this class instead.
 *
 * @see UserTracker
 *
 * Class constructed and initialized in [SettingsModule].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00b4\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\b\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u0000 Z2\u00020\u00012\u00020\u00022\u00020\u0003:\u0002Z[B\'\b\u0000\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u0018\u0010;\u001a\u00020<2\u0006\u0010=\u001a\u00020>2\u0006\u0010?\u001a\u00020@H\u0016J-\u0010A\u001a\u00020<2\u0006\u0010B\u001a\u00020C2\u0006\u0010D\u001a\u00020E2\u000e\u0010F\u001a\n\u0012\u0006\b\u0001\u0012\u00020H0GH\u0016\u00a2\u0006\u0002\u0010IJ\b\u0010J\u001a\u00020<H\u0003J\u0010\u0010K\u001a\u00020<2\u0006\u0010L\u001a\u00020)H\u0003J\u000e\u0010M\u001a\u00020<2\u0006\u0010N\u001a\u00020)J$\u0010O\u001a\u00020<2\u0019\b\u0004\u0010P\u001a\u0013\u0012\u0004\u0012\u00020>\u0012\u0004\u0012\u00020<0Q\u00a2\u0006\u0002\bRH\u0082\bJ\u0018\u0010S\u001a\u00020<2\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010T\u001a\u00020UH\u0016J\u0010\u0010V\u001a\u00020<2\u0006\u0010=\u001a\u00020>H\u0016J\"\u0010W\u001a\u0014\u0012\u0004\u0012\u00020\u0005\u0012\n\u0012\b\u0012\u0004\u0012\u000201040X2\u0006\u0010Y\u001a\u00020)H\u0002R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u000f0\u000e8\u0002X\u0083\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u0012\u001a\u00020\u00112\u0006\u0010\u0010\u001a\u00020\u0011@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0017\u001a\u00020\u00188VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0019\u0010\u001aR+\u0010\u001b\u001a\u00020\u00052\u0006\u0010\u0010\u001a\u00020\u00058V@RX\u0096\u008e\u0002\u00a2\u0006\u0012\n\u0004\b \u0010!\u001a\u0004\b\u001c\u0010\u001d\"\u0004\b\u001e\u0010\u001fR+\u0010#\u001a\u00020\"2\u0006\u0010\u0010\u001a\u00020\"8V@RX\u0096\u008e\u0002\u00a2\u0006\u0012\n\u0004\b(\u0010!\u001a\u0004\b$\u0010%\"\u0004\b&\u0010\'R+\u0010*\u001a\u00020)2\u0006\u0010\u0010\u001a\u00020)8V@RX\u0096\u008e\u0002\u00a2\u0006\u0012\n\u0004\b/\u0010!\u001a\u0004\b+\u0010,\"\u0004\b-\u0010.R\u0014\u00100\u001a\u0002018VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b2\u00103R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R7\u00105\u001a\b\u0012\u0004\u0012\u000201042\f\u0010\u0010\u001a\b\u0012\u0004\u0012\u000201048V@RX\u0096\u008e\u0002\u00a2\u0006\u0012\n\u0004\b:\u0010!\u001a\u0004\b6\u00107\"\u0004\b8\u00109"}, d2 = {"Lcom/android/systemui/settings/UserTrackerImpl;", "Lcom/android/systemui/settings/UserTracker;", "Lcom/android/systemui/Dumpable;", "Landroid/content/BroadcastReceiver;", "context", "Landroid/content/Context;", "userManager", "Landroid/os/UserManager;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "backgroundHandler", "Landroid/os/Handler;", "(Landroid/content/Context;Landroid/os/UserManager;Lcom/android/systemui/dump/DumpManager;Landroid/os/Handler;)V", "callbacks", "", "Lcom/android/systemui/settings/DataItem;", "<set-?>", "", "initialized", "getInitialized", "()Z", "mutex", "", "userContentResolver", "Landroid/content/ContentResolver;", "getUserContentResolver", "()Landroid/content/ContentResolver;", "userContext", "getUserContext", "()Landroid/content/Context;", "setUserContext", "(Landroid/content/Context;)V", "userContext$delegate", "Lcom/android/systemui/settings/UserTrackerImpl$SynchronizedDelegate;", "Landroid/os/UserHandle;", "userHandle", "getUserHandle", "()Landroid/os/UserHandle;", "setUserHandle", "(Landroid/os/UserHandle;)V", "userHandle$delegate", "", "userId", "getUserId", "()I", "setUserId", "(I)V", "userId$delegate", "userInfo", "Landroid/content/pm/UserInfo;", "getUserInfo", "()Landroid/content/pm/UserInfo;", "", "userProfiles", "getUserProfiles", "()Ljava/util/List;", "setUserProfiles", "(Ljava/util/List;)V", "userProfiles$delegate", "addCallback", "", "callback", "Lcom/android/systemui/settings/UserTracker$Callback;", "executor", "Ljava/util/concurrent/Executor;", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "handleProfilesChanged", "handleSwitchUser", "newUser", "initialize", "startingUser", "notifySubscribers", "action", "Lkotlin/Function1;", "Lkotlin/ExtensionFunctionType;", "onReceive", "intent", "Landroid/content/Intent;", "removeCallback", "setUserIdInternal", "Lkotlin/Pair;", "user", "Companion", "SynchronizedDelegate"})
public final class UserTrackerImpl extends android.content.BroadcastReceiver implements com.android.systemui.settings.UserTracker, com.android.systemui.Dumpable {
    private boolean initialized = false;
    private final java.lang.Object mutex = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.settings.UserTrackerImpl.SynchronizedDelegate userId$delegate = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.settings.UserTrackerImpl.SynchronizedDelegate userHandle$delegate = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.settings.UserTrackerImpl.SynchronizedDelegate userContext$delegate = null;
    
    /**
     * Returns a [List<UserInfo>] of all profiles associated with the current user.
     *
     * The list returned is not a copy, so a copy should be made if its elements need to be
     * modified.
     */
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.settings.UserTrackerImpl.SynchronizedDelegate userProfiles$delegate = null;
    @androidx.annotation.GuardedBy(value = "callbacks")
    private final java.util.List<com.android.systemui.settings.DataItem> callbacks = null;
    private final android.content.Context context = null;
    private final android.os.UserManager userManager = null;
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final android.os.Handler backgroundHandler = null;
    private static final java.lang.String TAG = "UserTrackerImpl";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.settings.UserTrackerImpl.Companion Companion = null;
    
    public final boolean getInitialized() {
        return false;
    }
    
    @java.lang.Override()
    public int getUserId() {
        return 0;
    }
    
    private void setUserId(int p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.os.UserHandle getUserHandle() {
        return null;
    }
    
    private void setUserHandle(android.os.UserHandle p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.content.Context getUserContext() {
        return null;
    }
    
    private void setUserContext(android.content.Context p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.content.ContentResolver getUserContentResolver() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.content.pm.UserInfo getUserInfo() {
        return null;
    }
    
    /**
     * Returns a [List<UserInfo>] of all profiles associated with the current user.
     *
     * The list returned is not a copy, so a copy should be made if its elements need to be
     * modified.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<android.content.pm.UserInfo> getUserProfiles() {
        return null;
    }
    
    private void setUserProfiles(java.util.List<? extends android.content.pm.UserInfo> p0) {
    }
    
    public final void initialize(int startingUser) {
    }
    
    @java.lang.Override()
    public void onReceive(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.content.Intent intent) {
    }
    
    private final kotlin.Pair<android.content.Context, java.util.List<android.content.pm.UserInfo>> setUserIdInternal(int user) {
        return null;
    }
    
    @androidx.annotation.WorkerThread()
    private final void handleSwitchUser(int newUser) {
    }
    
    @androidx.annotation.WorkerThread()
    private final void handleProfilesChanged() {
    }
    
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker.Callback callback, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor) {
    }
    
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker.Callback callback) {
    }
    
    private final void notifySubscribers(kotlin.jvm.functions.Function1<? super com.android.systemui.settings.UserTracker.Callback, kotlin.Unit> action) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    public UserTrackerImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.os.UserManager userManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    android.os.Handler backgroundHandler) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\b\u0002\u0018\u0000*\b\b\u0000\u0010\u0001*\u00020\u00022\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u0002H\u00010\u0003B\r\u0012\u0006\u0010\u0005\u001a\u00028\u0000\u00a2\u0006\u0002\u0010\u0006J\"\u0010\b\u001a\u00028\u00002\u0006\u0010\t\u001a\u00020\u00042\n\u0010\n\u001a\u0006\u0012\u0002\b\u00030\u000bH\u0097\u0002\u00a2\u0006\u0002\u0010\fJ*\u0010\r\u001a\u00020\u000e2\u0006\u0010\t\u001a\u00020\u00042\n\u0010\n\u001a\u0006\u0012\u0002\b\u00030\u000b2\u0006\u0010\u0005\u001a\u00028\u0000H\u0097\u0002\u00a2\u0006\u0002\u0010\u000fR\u0010\u0010\u0005\u001a\u00028\u0000X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u0007"}, d2 = {"Lcom/android/systemui/settings/UserTrackerImpl$SynchronizedDelegate;", "T", "", "Lkotlin/properties/ReadWriteProperty;", "Lcom/android/systemui/settings/UserTrackerImpl;", "value", "(Ljava/lang/Object;)V", "Ljava/lang/Object;", "getValue", "thisRef", "property", "Lkotlin/reflect/KProperty;", "(Lcom/android/systemui/settings/UserTrackerImpl;Lkotlin/reflect/KProperty;)Ljava/lang/Object;", "setValue", "", "(Lcom/android/systemui/settings/UserTrackerImpl;Lkotlin/reflect/KProperty;Ljava/lang/Object;)V"})
    static final class SynchronizedDelegate<T extends java.lang.Object> implements kotlin.properties.ReadWriteProperty<com.android.systemui.settings.UserTrackerImpl, T> {
        private T value;
        
        @org.jetbrains.annotations.NotNull()
        @androidx.annotation.GuardedBy(value = "mutex")
        @java.lang.Override()
        public T getValue(@org.jetbrains.annotations.NotNull()
        com.android.systemui.settings.UserTrackerImpl thisRef, @org.jetbrains.annotations.NotNull()
        kotlin.reflect.KProperty<?> property) {
            return null;
        }
        
        @androidx.annotation.GuardedBy(value = "mutex")
        @java.lang.Override()
        public void setValue(@org.jetbrains.annotations.NotNull()
        com.android.systemui.settings.UserTrackerImpl thisRef, @org.jetbrains.annotations.NotNull()
        kotlin.reflect.KProperty<?> property, @org.jetbrains.annotations.NotNull()
        T value) {
        }
        
        public SynchronizedDelegate(@org.jetbrains.annotations.NotNull()
        T value) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/settings/UserTrackerImpl$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
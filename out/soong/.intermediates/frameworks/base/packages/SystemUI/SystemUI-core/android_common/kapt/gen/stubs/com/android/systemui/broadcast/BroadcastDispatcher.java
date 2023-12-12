package com.android.systemui.broadcast;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Handler;
import android.os.HandlerExecutor;
import android.os.Looper;
import android.os.Message;
import android.os.UserHandle;
import android.text.TextUtils;
import android.util.IndentingPrintWriter;
import android.util.SparseArray;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.broadcast.logging.BroadcastDispatcherLogger;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.settings.UserTracker;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.concurrent.Executor;

/**
 * SystemUI master Broadcast Dispatcher.
 *
 * This class allows [BroadcastReceiver] to register and centralizes registrations to [Context]
 * from SystemUI. That way the number of calls to [BroadcastReceiver.onReceive] can be reduced for
 * a given broadcast.
 *
 * Use only for IntentFilters with actions and optionally categories. It does not support,
 * permissions, schemes, data types, data authorities or priority different than 0.
 * Cannot be used for getting sticky broadcasts (either as return of registering or as re-delivery).
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000~\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0016\u0018\u00002\u00020\u0001B5\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ\u0010\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u0017H\u0002J\u0010\u0010\u0018\u001a\u00020\u00132\u0006\u0010\u0019\u001a\u00020\u001aH\u0015J-\u0010\u001b\u001a\u00020\u00152\u0006\u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u001f2\u000e\u0010 \u001a\n\u0012\u0006\b\u0001\u0012\u00020\"0!H\u0016\u00a2\u0006\u0002\u0010#J\u0006\u0010$\u001a\u00020\u0015J0\u0010%\u001a\u00020\u00152\u0006\u0010&\u001a\u00020\'2\u0006\u0010\u0016\u001a\u00020\u00172\n\b\u0002\u0010(\u001a\u0004\u0018\u00010\u00072\n\b\u0002\u0010)\u001a\u0004\u0018\u00010*H\u0017J*\u0010+\u001a\u00020\u00152\u0006\u0010&\u001a\u00020\'2\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u000f\u001a\u00020\u00102\b\b\u0002\u0010)\u001a\u00020*H\u0017J\u0010\u0010,\u001a\u00020\u00152\u0006\u0010&\u001a\u00020\'H\u0016J\u0018\u0010-\u001a\u00020\u00152\u0006\u0010&\u001a\u00020\'2\u0006\u0010)\u001a\u00020*H\u0016R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0011\u001a\b\u0012\u0004\u0012\u00020\u00130\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/broadcast/BroadcastDispatcher;", "Lcom/android/systemui/Dumpable;", "context", "Landroid/content/Context;", "bgLooper", "Landroid/os/Looper;", "bgExecutor", "Ljava/util/concurrent/Executor;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "logger", "Lcom/android/systemui/broadcast/logging/BroadcastDispatcherLogger;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "(Landroid/content/Context;Landroid/os/Looper;Ljava/util/concurrent/Executor;Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/broadcast/logging/BroadcastDispatcherLogger;Lcom/android/systemui/settings/UserTracker;)V", "handler", "Landroid/os/Handler;", "receiversByUser", "Landroid/util/SparseArray;", "Lcom/android/systemui/broadcast/UserBroadcastDispatcher;", "checkFilter", "", "filter", "Landroid/content/IntentFilter;", "createUBRForUser", "userId", "", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "initialize", "registerReceiver", "receiver", "Landroid/content/BroadcastReceiver;", "executor", "user", "Landroid/os/UserHandle;", "registerReceiverWithHandler", "unregisterReceiver", "unregisterReceiverForUser"})
public class BroadcastDispatcher implements com.android.systemui.Dumpable {
    private final android.util.SparseArray<com.android.systemui.broadcast.UserBroadcastDispatcher> receiversByUser = null;
    private final android.os.Handler handler = null;
    private final android.content.Context context = null;
    private final android.os.Looper bgLooper = null;
    private final java.util.concurrent.Executor bgExecutor = null;
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final com.android.systemui.broadcast.logging.BroadcastDispatcherLogger logger = null;
    private final com.android.systemui.settings.UserTracker userTracker = null;
    
    public final void initialize() {
    }
    
    /**
     * Register a receiver for broadcast with the dispatcher
     *
     * @param receiver A receiver to dispatch the [Intent]
     * @param filter A filter to determine what broadcasts should be dispatched to this receiver.
     *              It will only take into account actions and categories for filtering. It must
     *              have at least one action.
     * @param handler A handler to dispatch [BroadcastReceiver.onReceive].
     * @param user A user handle to determine which broadcast should be dispatched to this receiver.
     *            By default, it is the user of the context (system user in SystemUI).
     * @throws IllegalArgumentException if the filter has other constraints that are not actions or
     *                                 categories or the filter has no actions.
     */
    @java.lang.Deprecated()
    public void registerReceiverWithHandler(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver, @org.jetbrains.annotations.NotNull()
    android.content.IntentFilter filter, @org.jetbrains.annotations.NotNull()
    android.os.Handler handler, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
    }
    
    /**
     * Register a receiver for broadcast with the dispatcher
     *
     * @param receiver A receiver to dispatch the [Intent]
     * @param filter A filter to determine what broadcasts should be dispatched to this receiver.
     *              It will only take into account actions and categories for filtering. It must
     *              have at least one action.
     * @param handler A handler to dispatch [BroadcastReceiver.onReceive].
     * @param user A user handle to determine which broadcast should be dispatched to this receiver.
     *            By default, it is the user of the context (system user in SystemUI).
     * @throws IllegalArgumentException if the filter has other constraints that are not actions or
     *                                 categories or the filter has no actions.
     */
    @java.lang.Deprecated()
    public final void registerReceiverWithHandler(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver, @org.jetbrains.annotations.NotNull()
    android.content.IntentFilter filter, @org.jetbrains.annotations.NotNull()
    android.os.Handler handler) {
    }
    
    /**
     * Register a receiver for broadcast with the dispatcher
     *
     * @param receiver A receiver to dispatch the [Intent]
     * @param filter A filter to determine what broadcasts should be dispatched to this receiver.
     *              It will only take into account actions and categories for filtering. It must
     *              have at least one action.
     * @param executor An executor to dispatch [BroadcastReceiver.onReceive]. Pass null to use an
     *                executor in the main thread (default).
     * @param user A user handle to determine which broadcast should be dispatched to this receiver.
     *            Pass `null` to use the user of the context (system user in SystemUI).
     * @throws IllegalArgumentException if the filter has other constraints that are not actions or
     *                                 categories or the filter has no actions.
     */
    public void registerReceiver(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver, @org.jetbrains.annotations.NotNull()
    android.content.IntentFilter filter, @org.jetbrains.annotations.Nullable()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.Nullable()
    android.os.UserHandle user) {
    }
    
    /**
     * Register a receiver for broadcast with the dispatcher
     *
     * @param receiver A receiver to dispatch the [Intent]
     * @param filter A filter to determine what broadcasts should be dispatched to this receiver.
     *              It will only take into account actions and categories for filtering. It must
     *              have at least one action.
     * @param executor An executor to dispatch [BroadcastReceiver.onReceive]. Pass null to use an
     *                executor in the main thread (default).
     * @param user A user handle to determine which broadcast should be dispatched to this receiver.
     *            Pass `null` to use the user of the context (system user in SystemUI).
     * @throws IllegalArgumentException if the filter has other constraints that are not actions or
     *                                 categories or the filter has no actions.
     */
    public final void registerReceiver(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver, @org.jetbrains.annotations.NotNull()
    android.content.IntentFilter filter, @org.jetbrains.annotations.Nullable()
    java.util.concurrent.Executor executor) {
    }
    
    /**
     * Register a receiver for broadcast with the dispatcher
     *
     * @param receiver A receiver to dispatch the [Intent]
     * @param filter A filter to determine what broadcasts should be dispatched to this receiver.
     *              It will only take into account actions and categories for filtering. It must
     *              have at least one action.
     * @param executor An executor to dispatch [BroadcastReceiver.onReceive]. Pass null to use an
     *                executor in the main thread (default).
     * @param user A user handle to determine which broadcast should be dispatched to this receiver.
     *            Pass `null` to use the user of the context (system user in SystemUI).
     * @throws IllegalArgumentException if the filter has other constraints that are not actions or
     *                                 categories or the filter has no actions.
     */
    public final void registerReceiver(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver, @org.jetbrains.annotations.NotNull()
    android.content.IntentFilter filter) {
    }
    
    private final void checkFilter(android.content.IntentFilter filter) {
    }
    
    /**
     * Unregister receiver for all users.
     * <br>
     * This will remove every registration of [receiver], not those done just with [UserHandle.ALL].
     *
     * @param receiver The receiver to unregister. It will be unregistered for all users.
     */
    public void unregisterReceiver(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver) {
    }
    
    /**
     * Unregister receiver for a particular user.
     *
     * @param receiver The receiver to unregister.
     * @param user The user associated to the registered [receiver]. It can be [UserHandle.ALL].
     */
    public void unregisterReceiverForUser(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @com.android.internal.annotations.VisibleForTesting()
    protected com.android.systemui.broadcast.UserBroadcastDispatcher createUBRForUser(int userId) {
        return null;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    public BroadcastDispatcher(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.os.Looper bgLooper, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor bgExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.logging.BroadcastDispatcherLogger logger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker) {
        super();
    }
}
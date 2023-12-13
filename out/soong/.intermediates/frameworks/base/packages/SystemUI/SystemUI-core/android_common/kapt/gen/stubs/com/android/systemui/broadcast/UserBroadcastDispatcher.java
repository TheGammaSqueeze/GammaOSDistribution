package com.android.systemui.broadcast;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.os.UserHandle;
import android.util.ArrayMap;
import android.util.ArraySet;
import android.util.Log;
import androidx.annotation.VisibleForTesting;
import com.android.internal.util.Preconditions;
import com.android.systemui.Dumpable;
import com.android.systemui.broadcast.logging.BroadcastDispatcherLogger;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.concurrent.Executor;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Broadcast dispatcher for a given user registration [userId].
 *
 * Created by [BroadcastDispatcher] as needed by users. The value of [userId] can be
 * [UserHandle.USER_ALL].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000v\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010#\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0004\b\u0016\u0018\u0000 02\u00020\u0001:\u00010B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u0015\u0010\u001a\u001a\u00020\u00102\u0006\u0010\u001b\u001a\u00020\u000fH\u0011\u00a2\u0006\u0002\b\u001cJ-\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020 2\u0006\u0010!\u001a\u00020\"2\u000e\u0010#\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u000f0$H\u0016\u00a2\u0006\u0002\u0010%J\u0010\u0010&\u001a\u00020\u001e2\u0006\u0010\'\u001a\u00020(H\u0002J\u0010\u0010)\u001a\u00020\u001e2\u0006\u0010*\u001a\u00020\u0018H\u0002J\u0015\u0010+\u001a\u00020,2\u0006\u0010*\u001a\u00020\u0018H\u0001\u00a2\u0006\u0002\b-J\u000e\u0010.\u001a\u00020\u001e2\u0006\u0010\'\u001a\u00020(J\u000e\u0010/\u001a\u00020\u001e2\u0006\u0010*\u001a\u00020\u0018R(\u0010\r\u001a\u000e\u0012\u0004\u0012\u00020\u000f\u0012\u0004\u0012\u00020\u00100\u000e8\u0000X\u0081\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\u0011\u0010\u0012\u001a\u0004\b\u0013\u0010\u0014R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\u0017\u001a\u0014\u0012\u0004\u0012\u00020\u0018\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000f0\u00190\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/broadcast/UserBroadcastDispatcher;", "Lcom/android/systemui/Dumpable;", "context", "Landroid/content/Context;", "userId", "", "bgLooper", "Landroid/os/Looper;", "bgExecutor", "Ljava/util/concurrent/Executor;", "logger", "Lcom/android/systemui/broadcast/logging/BroadcastDispatcherLogger;", "(Landroid/content/Context;ILandroid/os/Looper;Ljava/util/concurrent/Executor;Lcom/android/systemui/broadcast/logging/BroadcastDispatcherLogger;)V", "actionsToActionsReceivers", "Landroid/util/ArrayMap;", "", "Lcom/android/systemui/broadcast/ActionReceiver;", "getActionsToActionsReceivers$main$annotations", "()V", "getActionsToActionsReceivers$main", "()Landroid/util/ArrayMap;", "bgHandler", "Landroid/os/Handler;", "receiverToActions", "Landroid/content/BroadcastReceiver;", "", "createActionReceiver", "action", "createActionReceiver$main", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "handleRegisterReceiver", "receiverData", "Lcom/android/systemui/broadcast/ReceiverData;", "handleUnregisterReceiver", "receiver", "isReceiverReferenceHeld", "", "isReceiverReferenceHeld$main", "registerReceiver", "unregisterReceiver", "Companion"})
public class UserBroadcastDispatcher implements com.android.systemui.Dumpable {
    private final android.os.Handler bgHandler = null;
    @org.jetbrains.annotations.NotNull()
    private final android.util.ArrayMap<java.lang.String, com.android.systemui.broadcast.ActionReceiver> actionsToActionsReceivers = null;
    private final android.util.ArrayMap<android.content.BroadcastReceiver, java.util.Set<java.lang.String>> receiverToActions = null;
    private final android.content.Context context = null;
    private final int userId = 0;
    private final android.os.Looper bgLooper = null;
    private final java.util.concurrent.Executor bgExecutor = null;
    private final com.android.systemui.broadcast.logging.BroadcastDispatcherLogger logger = null;
    @org.jetbrains.annotations.NotNull()
    private static final java.util.concurrent.atomic.AtomicInteger index = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.broadcast.UserBroadcastDispatcher.Companion Companion = null;
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getActionsToActionsReceivers$main$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.util.ArrayMap<java.lang.String, com.android.systemui.broadcast.ActionReceiver> getActionsToActionsReceivers$main() {
        return null;
    }
    
    @androidx.annotation.VisibleForTesting()
    public final boolean isReceiverReferenceHeld$main(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver) {
        return false;
    }
    
    /**
     * Register a [ReceiverData] for this user.
     */
    public final void registerReceiver(@org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.ReceiverData receiverData) {
    }
    
    /**
     * Unregister a given [BroadcastReceiver] for this user.
     */
    public final void unregisterReceiver(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver) {
    }
    
    private final void handleRegisterReceiver(com.android.systemui.broadcast.ReceiverData receiverData) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.VisibleForTesting()
    public com.android.systemui.broadcast.ActionReceiver createActionReceiver$main(@org.jetbrains.annotations.NotNull()
    java.lang.String action) {
        return null;
    }
    
    private final void handleUnregisterReceiver(android.content.BroadcastReceiver receiver) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    public UserBroadcastDispatcher(@org.jetbrains.annotations.NotNull()
    android.content.Context context, int userId, @org.jetbrains.annotations.NotNull()
    android.os.Looper bgLooper, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor bgExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.logging.BroadcastDispatcherLogger logger) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006"}, d2 = {"Lcom/android/systemui/broadcast/UserBroadcastDispatcher$Companion;", "", "()V", "index", "Ljava/util/concurrent/atomic/AtomicInteger;", "getIndex", "()Ljava/util/concurrent/atomic/AtomicInteger;"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.concurrent.atomic.AtomicInteger getIndex() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}
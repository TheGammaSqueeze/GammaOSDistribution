package com.android.systemui.broadcast;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.util.ArraySet;
import com.android.systemui.Dumpable;
import com.android.systemui.broadcast.logging.BroadcastDispatcherLogger;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.concurrent.Executor;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Receiver for a given action-userId pair to be used by [UserBroadcastDispatcher].
 *
 * Each object of this class will take care of a single Action. It will register if it has at least
 * one [BroadcastReceiver] added to it, and unregister when none are left.
 *
 * It will also re-register if filters with new categories are added. But this should not happen
 * often.
 *
 * This class has no sync controls, so make sure to only make modifications from the background
 * thread.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000v\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000 /2\u00020\u00012\u00020\u0002:\u0001/B]\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u001d\u0010\u0007\u001a\u0019\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\t\u0012\u0004\u0012\u00020\n0\b\u00a2\u0006\u0002\b\u000b\u0012\u0017\u0010\f\u001a\u0013\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\n0\r\u00a2\u0006\u0002\b\u000b\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u00a2\u0006\u0002\u0010\u0012J\u000e\u0010\u001c\u001a\u00020\n2\u0006\u0010\u001d\u001a\u00020\u0016J\b\u0010\u001e\u001a\u00020\tH\u0002J-\u0010\u001f\u001a\u00020\n2\u0006\u0010 \u001a\u00020!2\u0006\u0010\"\u001a\u00020#2\u000e\u0010$\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00040%H\u0016\u00a2\u0006\u0002\u0010&J\u000e\u0010\'\u001a\u00020\u00182\u0006\u0010(\u001a\u00020\u0001J\u0018\u0010)\u001a\u00020\n2\u0006\u0010*\u001a\u00020+2\u0006\u0010,\u001a\u00020-H\u0016J\u000e\u0010.\u001a\u00020\n2\u0006\u0010(\u001a\u00020\u0001R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00040\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0015\u001a\b\u0012\u0004\u0012\u00020\u00160\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R%\u0010\u0007\u001a\u0019\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\t\u0012\u0004\u0012\u00020\n0\b\u00a2\u0006\u0002\b\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u0019\u001a\u00020\u00182\u0006\u0010\u0017\u001a\u00020\u0018@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u001bR\u001f\u0010\f\u001a\u0013\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\n0\r\u00a2\u0006\u0002\b\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/broadcast/ActionReceiver;", "Landroid/content/BroadcastReceiver;", "Lcom/android/systemui/Dumpable;", "action", "", "userId", "", "registerAction", "Lkotlin/Function2;", "Landroid/content/IntentFilter;", "", "Lkotlin/ExtensionFunctionType;", "unregisterAction", "Lkotlin/Function1;", "bgExecutor", "Ljava/util/concurrent/Executor;", "logger", "Lcom/android/systemui/broadcast/logging/BroadcastDispatcherLogger;", "(Ljava/lang/String;ILkotlin/jvm/functions/Function2;Lkotlin/jvm/functions/Function1;Ljava/util/concurrent/Executor;Lcom/android/systemui/broadcast/logging/BroadcastDispatcherLogger;)V", "activeCategories", "Landroid/util/ArraySet;", "receiverDatas", "Lcom/android/systemui/broadcast/ReceiverData;", "<set-?>", "", "registered", "getRegistered", "()Z", "addReceiverData", "receiverData", "createFilter", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "hasReceiver", "receiver", "onReceive", "context", "Landroid/content/Context;", "intent", "Landroid/content/Intent;", "removeReceiver", "Companion"})
public final class ActionReceiver extends android.content.BroadcastReceiver implements com.android.systemui.Dumpable {
    private boolean registered = false;
    private final android.util.ArraySet<com.android.systemui.broadcast.ReceiverData> receiverDatas = null;
    private final android.util.ArraySet<java.lang.String> activeCategories = null;
    private final java.lang.String action = null;
    private final int userId = 0;
    private final kotlin.jvm.functions.Function2<android.content.BroadcastReceiver, android.content.IntentFilter, kotlin.Unit> registerAction = null;
    private final kotlin.jvm.functions.Function1<android.content.BroadcastReceiver, kotlin.Unit> unregisterAction = null;
    private final java.util.concurrent.Executor bgExecutor = null;
    private final com.android.systemui.broadcast.logging.BroadcastDispatcherLogger logger = null;
    @org.jetbrains.annotations.NotNull()
    private static final java.util.concurrent.atomic.AtomicInteger index = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.broadcast.ActionReceiver.Companion Companion = null;
    
    public final boolean getRegistered() {
        return false;
    }
    
    public final void addReceiverData(@org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.ReceiverData receiverData) throws java.lang.IllegalArgumentException {
    }
    
    public final boolean hasReceiver(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver) {
        return false;
    }
    
    private final android.content.IntentFilter createFilter() {
        return null;
    }
    
    public final void removeReceiver(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver) {
    }
    
    @java.lang.Override()
    public void onReceive(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.content.Intent intent) throws java.lang.IllegalStateException {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    public ActionReceiver(@org.jetbrains.annotations.NotNull()
    java.lang.String action, int userId, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super android.content.BroadcastReceiver, ? super android.content.IntentFilter, kotlin.Unit> registerAction, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super android.content.BroadcastReceiver, kotlin.Unit> unregisterAction, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor bgExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.logging.BroadcastDispatcherLogger logger) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006"}, d2 = {"Lcom/android/systemui/broadcast/ActionReceiver$Companion;", "", "()V", "index", "Ljava/util/concurrent/atomic/AtomicInteger;", "getIndex", "()Ljava/util/concurrent/atomic/AtomicInteger;"})
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
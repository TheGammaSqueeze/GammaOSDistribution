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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u000f\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\t\u0010\u0013\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0014\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0015\u001a\u00020\u0007H\u00c6\u0003J\t\u0010\u0016\u001a\u00020\tH\u00c6\u0003J1\u0010\u0017\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\b\b\u0002\u0010\b\u001a\u00020\tH\u00c6\u0001J\u0013\u0010\u0018\u001a\u00020\u00192\b\u0010\u001a\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001b\u001a\u00020\u001cH\u00d6\u0001J\t\u0010\u001d\u001a\u00020\u001eH\u00d6\u0001R\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012"}, d2 = {"Lcom/android/systemui/broadcast/ReceiverData;", "", "receiver", "Landroid/content/BroadcastReceiver;", "filter", "Landroid/content/IntentFilter;", "executor", "Ljava/util/concurrent/Executor;", "user", "Landroid/os/UserHandle;", "(Landroid/content/BroadcastReceiver;Landroid/content/IntentFilter;Ljava/util/concurrent/Executor;Landroid/os/UserHandle;)V", "getExecutor", "()Ljava/util/concurrent/Executor;", "getFilter", "()Landroid/content/IntentFilter;", "getReceiver", "()Landroid/content/BroadcastReceiver;", "getUser", "()Landroid/os/UserHandle;", "component1", "component2", "component3", "component4", "copy", "equals", "", "other", "hashCode", "", "toString", ""})
public final class ReceiverData {
    @org.jetbrains.annotations.NotNull()
    private final android.content.BroadcastReceiver receiver = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.IntentFilter filter = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.concurrent.Executor executor = null;
    @org.jetbrains.annotations.NotNull()
    private final android.os.UserHandle user = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.BroadcastReceiver getReceiver() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.IntentFilter getFilter() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.concurrent.Executor getExecutor() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.os.UserHandle getUser() {
        return null;
    }
    
    public ReceiverData(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver, @org.jetbrains.annotations.NotNull()
    android.content.IntentFilter filter, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.BroadcastReceiver component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.IntentFilter component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.concurrent.Executor component3() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.os.UserHandle component4() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.broadcast.ReceiverData copy(@org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver, @org.jetbrains.annotations.NotNull()
    android.content.IntentFilter filter, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}
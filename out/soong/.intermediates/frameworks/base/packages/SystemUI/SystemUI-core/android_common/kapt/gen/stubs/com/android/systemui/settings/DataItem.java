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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B\u001b\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u000f\u0010\f\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u00c6\u0003J\t\u0010\r\u001a\u00020\u0006H\u00c6\u0003J#\u0010\u000e\u001a\u00020\u00002\u000e\b\u0002\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u0006H\u00c6\u0001J\u0013\u0010\u000f\u001a\u00020\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0012\u001a\u00020\u0013H\u00d6\u0001J\u000e\u0010\u0014\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0004J\t\u0010\u0015\u001a\u00020\u0016H\u00d6\u0001R\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/systemui/settings/DataItem;", "", "callback", "Ljava/lang/ref/WeakReference;", "Lcom/android/systemui/settings/UserTracker$Callback;", "executor", "Ljava/util/concurrent/Executor;", "(Ljava/lang/ref/WeakReference;Ljava/util/concurrent/Executor;)V", "getCallback", "()Ljava/lang/ref/WeakReference;", "getExecutor", "()Ljava/util/concurrent/Executor;", "component1", "component2", "copy", "equals", "", "other", "hashCode", "", "sameOrEmpty", "toString", ""})
final class DataItem {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.ref.WeakReference<com.android.systemui.settings.UserTracker.Callback> callback = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.concurrent.Executor executor = null;
    
    public final boolean sameOrEmpty(@org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker.Callback other) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.ref.WeakReference<com.android.systemui.settings.UserTracker.Callback> getCallback() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.concurrent.Executor getExecutor() {
        return null;
    }
    
    public DataItem(@org.jetbrains.annotations.NotNull()
    java.lang.ref.WeakReference<com.android.systemui.settings.UserTracker.Callback> callback, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.ref.WeakReference<com.android.systemui.settings.UserTracker.Callback> component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.concurrent.Executor component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.settings.DataItem copy(@org.jetbrains.annotations.NotNull()
    java.lang.ref.WeakReference<com.android.systemui.settings.UserTracker.Callback> callback, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor) {
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
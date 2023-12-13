package com.android.systemui;

import android.util.Log;
import com.android.internal.annotations.GuardedBy;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dump.DumpManager;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.lang.ref.WeakReference;
import java.util.concurrent.atomic.AtomicBoolean;
import javax.inject.Inject;

/**
 * Caches whether the device has reached [SystemService.PHASE_BOOT_COMPLETED].
 *
 * This class is constructed and set by [SystemUIApplication] and will notify all listeners when
 * boot is completed.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000P\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0005\b\u0007\u0018\u0000 \u001c2\u00020\u00012\u00020\u0002:\u0001\u001cB\u000f\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000bH\u0016J-\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u000e\u0010\u0015\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00170\u0016H\u0016\u00a2\u0006\u0002\u0010\u0018J\b\u0010\u0019\u001a\u00020\rH\u0016J\u0010\u0010\u001a\u001a\u00020\u00102\u0006\u0010\u000e\u001a\u00020\u000bH\u0016J\u0006\u0010\u001b\u001a\u00020\u0010R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\b\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\n0\t8\u0002X\u0083\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/BootCompleteCacheImpl;", "Lcom/android/systemui/BootCompleteCache;", "Lcom/android/systemui/Dumpable;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Lcom/android/systemui/dump/DumpManager;)V", "bootComplete", "Ljava/util/concurrent/atomic/AtomicBoolean;", "listeners", "", "Ljava/lang/ref/WeakReference;", "Lcom/android/systemui/BootCompleteCache$BootCompleteListener;", "addListener", "", "listener", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "isBootComplete", "removeListener", "setBootComplete", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class BootCompleteCacheImpl implements com.android.systemui.BootCompleteCache, com.android.systemui.Dumpable {
    @com.android.internal.annotations.GuardedBy(value = {"listeners"})
    private final java.util.List<java.lang.ref.WeakReference<com.android.systemui.BootCompleteCache.BootCompleteListener>> listeners = null;
    private final java.util.concurrent.atomic.AtomicBoolean bootComplete = null;
    private static final java.lang.String TAG = "BootCompleteCacheImpl";
    private static final boolean DEBUG = false;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.BootCompleteCacheImpl.Companion Companion = null;
    
    /**
     * Provides the current boot state of the system as determined by [SystemUIApplication].
     * @return `true` if the system has reached [SystemService.PHASE_BOOT_COMPLETED]
     */
    @java.lang.Override()
    public boolean isBootComplete() {
        return false;
    }
    
    /**
     * Indicates to this object that boot is complete. Subsequent calls to this function will have
     * no effect.
     */
    public final void setBootComplete() {
    }
    
    /**
     * Add a listener for boot complete event. It will immediately return the current boot complete
     * state. If this value is true, [BootCompleteCache.BootCompleteListener.onBootComplete] will
     * never be called.
     *
     * @param listener a listener for boot complete state.
     * @return `true` if boot has been completed.
     */
    @java.lang.Override()
    public boolean addListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.BootCompleteCache.BootCompleteListener listener) {
        return false;
    }
    
    /**
     * Removes a listener for boot complete event.
     *
     * @param listener a listener to removed.
     */
    @java.lang.Override()
    public void removeListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.BootCompleteCache.BootCompleteListener listener) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public BootCompleteCacheImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/BootCompleteCacheImpl$Companion;", "", "()V", "DEBUG", "", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
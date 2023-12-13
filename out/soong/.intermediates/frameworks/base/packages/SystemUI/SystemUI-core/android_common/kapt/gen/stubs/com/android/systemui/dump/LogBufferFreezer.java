package com.android.systemui.dump;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.UserHandle;
import android.util.Log;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.util.concurrency.DelayableExecutor;
import java.util.concurrent.TimeUnit;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0019\b\u0017\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006B\u001f\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\u000e\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fJ\b\u0010\u0010\u001a\u00020\rH\u0002R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\n\u001a\u0004\u0018\u00010\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/dump/LogBufferFreezer;", "", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "executor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "(Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/util/concurrency/DelayableExecutor;)V", "freezeDuration", "", "(Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/util/concurrency/DelayableExecutor;J)V", "pendingToken", "Ljava/lang/Runnable;", "attach", "", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "onBugreportStarted"})
public final class LogBufferFreezer {
    private java.lang.Runnable pendingToken;
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor executor = null;
    private final long freezeDuration = 0L;
    
    public final void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher) {
    }
    
    private final void onBugreportStarted() {
    }
    
    public LogBufferFreezer(@org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor executor, long freezeDuration) {
        super();
    }
    
    @javax.inject.Inject()
    public LogBufferFreezer(@org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor executor) {
        super();
    }
}
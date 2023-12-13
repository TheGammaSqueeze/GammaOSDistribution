package com.android.systemui.broadcast.logging;

import android.content.BroadcastReceiver;
import android.content.Intent;
import android.content.IntentFilter;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogLevel;
import com.android.systemui.log.LogMessage;
import com.android.systemui.log.dagger.BroadcastDispatcherLog;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004JE\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0017\u0010\t\u001a\u0013\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\u00060\n\u00a2\u0006\u0002\b\f2\u0019\b\b\u0010\r\u001a\u0013\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\u000e0\n\u00a2\u0006\u0002\b\fH\u0082\bJ \u0010\u000f\u001a\u00020\u00062\u0006\u0010\u0010\u001a\u00020\u00112\b\u0010\u0012\u001a\u0004\u0018\u00010\u000e2\u0006\u0010\u0013\u001a\u00020\u0014J\u001e\u0010\u0015\u001a\u00020\u00062\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0016\u001a\u00020\u00112\u0006\u0010\u0017\u001a\u00020\u0018J\u0016\u0010\u0019\u001a\u00020\u00062\u0006\u0010\u0016\u001a\u00020\u00112\u0006\u0010\u001a\u001a\u00020\u001bJ\u0016\u0010\u001c\u001a\u00020\u00062\u0006\u0010\u0016\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u000eJ\u0016\u0010\u001d\u001a\u00020\u00062\u0006\u0010\u0016\u001a\u00020\u00112\u0006\u0010\u0013\u001a\u00020\u0014J\u0016\u0010\u001e\u001a\u00020\u00062\u0006\u0010\u0016\u001a\u00020\u00112\u0006\u0010\u0013\u001a\u00020\u0014R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/broadcast/logging/BroadcastDispatcherLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "log", "", "logLevel", "Lcom/android/systemui/log/LogLevel;", "initializer", "Lkotlin/Function1;", "Lcom/android/systemui/log/LogMessage;", "Lkotlin/ExtensionFunctionType;", "printer", "", "logBroadcastDispatched", "broadcastId", "", "action", "receiver", "Landroid/content/BroadcastReceiver;", "logBroadcastReceived", "user", "intent", "Landroid/content/Intent;", "logContextReceiverRegistered", "filter", "Landroid/content/IntentFilter;", "logContextReceiverUnregistered", "logReceiverRegistered", "logReceiverUnregistered"})
public final class BroadcastDispatcherLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logBroadcastReceived(int broadcastId, int user, @org.jetbrains.annotations.NotNull()
    android.content.Intent intent) {
    }
    
    public final void logBroadcastDispatched(int broadcastId, @org.jetbrains.annotations.Nullable()
    java.lang.String action, @org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver) {
    }
    
    public final void logReceiverRegistered(int user, @org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver) {
    }
    
    public final void logReceiverUnregistered(int user, @org.jetbrains.annotations.NotNull()
    android.content.BroadcastReceiver receiver) {
    }
    
    public final void logContextReceiverRegistered(int user, @org.jetbrains.annotations.NotNull()
    android.content.IntentFilter filter) {
    }
    
    public final void logContextReceiverUnregistered(int user, @org.jetbrains.annotations.NotNull()
    java.lang.String action) {
    }
    
    private final void log(com.android.systemui.log.LogLevel logLevel, kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, kotlin.Unit> initializer, kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> printer) {
    }
    
    @javax.inject.Inject()
    public BroadcastDispatcherLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.BroadcastDispatcherLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}
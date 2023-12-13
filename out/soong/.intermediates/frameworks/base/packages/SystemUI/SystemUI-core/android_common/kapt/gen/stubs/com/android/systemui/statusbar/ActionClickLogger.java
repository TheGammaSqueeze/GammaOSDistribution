package com.android.systemui.statusbar;

import android.app.PendingIntent;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogLevel;
import com.android.systemui.log.dagger.NotifInteractionLog;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import javax.inject.Inject;

/**
 * Logger class for events related to the user clicking on notification actions
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0018\u0010\u0005\u001a\u00020\u00062\b\u0010\u0007\u001a\u0004\u0018\u00010\b2\u0006\u0010\t\u001a\u00020\nJ\u000e\u0010\u000b\u001a\u00020\u00062\u0006\u0010\t\u001a\u00020\nJ\u0010\u0010\f\u001a\u00020\u00062\b\u0010\u0007\u001a\u0004\u0018\u00010\bJ\u0018\u0010\r\u001a\u00020\u00062\b\u0010\u0007\u001a\u0004\u0018\u00010\b2\u0006\u0010\t\u001a\u00020\nJ\u000e\u0010\u000e\u001a\u00020\u00062\u0006\u0010\t\u001a\u00020\nR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/ActionClickLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "logInitialClick", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "pendingIntent", "Landroid/app/PendingIntent;", "logKeyguardGone", "logRemoteInputWasHandled", "logStartingIntentWithDefaultHandler", "logWaitingToCloseKeyguard"})
public final class ActionClickLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logInitialClick(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    android.app.PendingIntent pendingIntent) {
    }
    
    public final void logRemoteInputWasHandled(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    public final void logStartingIntentWithDefaultHandler(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    android.app.PendingIntent pendingIntent) {
    }
    
    public final void logWaitingToCloseKeyguard(@org.jetbrains.annotations.NotNull()
    android.app.PendingIntent pendingIntent) {
    }
    
    public final void logKeyguardGone(@org.jetbrains.annotations.NotNull()
    android.app.PendingIntent pendingIntent) {
    }
    
    @javax.inject.Inject()
    public ActionClickLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.NotifInteractionLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}
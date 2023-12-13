package com.android.systemui.statusbar.notification;

import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.dagger.NotificationLog;
import javax.inject.Inject;

/**
 * Logger for [NotificationEntryManager].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\b\n\u0002\u0010\u000b\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u001e\u0010\t\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\b2\u0006\u0010\u000b\u001a\u00020\b2\u0006\u0010\u0007\u001a\u00020\bJ\u001e\u0010\f\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\b2\u0006\u0010\r\u001a\u00020\b2\u0006\u0010\u000b\u001a\u00020\bJ\u000e\u0010\u000e\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\bJ\u0016\u0010\u000f\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\b2\u0006\u0010\u0010\u001a\u00020\u0011J\u0016\u0010\u0012\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\b2\u0006\u0010\u0013\u001a\u00020\u0011J\u000e\u0010\u0014\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\bJ\u000e\u0010\u0015\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\bR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/NotificationEntryManagerLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "logFilterAndSort", "", "reason", "", "logInflationAborted", "key", "status", "logLifetimeExtended", "extenderName", "logNotifAdded", "logNotifInflated", "isNew", "", "logNotifRemoved", "removedByUser", "logNotifUpdated", "logRemovalIntercepted"})
public final class NotificationEntryManagerLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logNotifAdded(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logNotifUpdated(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logInflationAborted(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    java.lang.String status, @org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    public final void logNotifInflated(@org.jetbrains.annotations.NotNull()
    java.lang.String key, boolean isNew) {
    }
    
    public final void logRemovalIntercepted(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logLifetimeExtended(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    java.lang.String extenderName, @org.jetbrains.annotations.NotNull()
    java.lang.String status) {
    }
    
    public final void logNotifRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String key, boolean removedByUser) {
    }
    
    public final void logFilterAndSort(@org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    @javax.inject.Inject()
    public NotificationEntryManagerLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.NotificationLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}
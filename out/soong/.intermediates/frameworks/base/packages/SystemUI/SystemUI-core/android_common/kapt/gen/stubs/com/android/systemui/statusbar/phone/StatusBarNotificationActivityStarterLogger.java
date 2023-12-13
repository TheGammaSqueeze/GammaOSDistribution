package com.android.systemui.statusbar.phone;

import android.app.PendingIntent;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.dagger.NotifInteractionLog;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\t\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\n\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\u000b\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\f\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\r\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u0016\u0010\u000e\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\u000f\u001a\u00020\u0010J\u0012\u0010\u0011\u001a\u00020\u00062\n\u0010\u0012\u001a\u00060\u0013j\u0002`\u0014J\u0016\u0010\u0015\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\u000f\u001a\u00020\u0010J\u000e\u0010\u0016\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/StatusBarNotificationActivityStarterLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "logExpandingBubble", "", "key", "", "logFullScreenIntentNotImportantEnough", "logFullScreenIntentSuppressedByDnD", "logHandleClickAfterKeyguardDismissed", "logHandleClickAfterPanelCollapsed", "logNonClickableNotification", "logSendingFullScreenIntent", "pendingIntent", "Landroid/app/PendingIntent;", "logSendingIntentFailed", "e", "Ljava/lang/Exception;", "Lkotlin/Exception;", "logStartNotificationIntent", "logStartingActivityFromClick"})
public final class StatusBarNotificationActivityStarterLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logStartingActivityFromClick(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logHandleClickAfterKeyguardDismissed(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logHandleClickAfterPanelCollapsed(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logStartNotificationIntent(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    android.app.PendingIntent pendingIntent) {
    }
    
    public final void logExpandingBubble(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logSendingIntentFailed(@org.jetbrains.annotations.NotNull()
    java.lang.Exception e) {
    }
    
    public final void logNonClickableNotification(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logFullScreenIntentSuppressedByDnD(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logFullScreenIntentNotImportantEnough(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logSendingFullScreenIntent(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    android.app.PendingIntent pendingIntent) {
    }
    
    @javax.inject.Inject()
    public StatusBarNotificationActivityStarterLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.NotifInteractionLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}
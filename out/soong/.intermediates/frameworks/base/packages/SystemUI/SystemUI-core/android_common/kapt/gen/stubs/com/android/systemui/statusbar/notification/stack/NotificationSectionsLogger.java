package com.android.systemui.statusbar.notification.stack;

import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogLevel;
import com.android.systemui.log.dagger.NotificationSectionLog;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0006\b\u0007\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0016\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nJ\u000e\u0010\u000b\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u0016\u0010\f\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nJ\u000e\u0010\r\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u0016\u0010\u000e\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nJ\u0016\u0010\u000f\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nJ\u000e\u0010\u0010\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\u0011\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u001a\u0010\u0012\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\n\u0010\u0013\u001a\u0006\u0012\u0002\b\u00030\u0014J\u0018\u0010\u0015\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\u0016\u001a\u00020\u0017H\u0002J \u0010\u0015\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\t\u001a\u00020\nH\u0002J\u0016\u0010\u0018\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nJ\u000e\u0010\u0019\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\u001a\u001a\u00020\u00062\u0006\u0010\u001b\u001a\u00020\u0017J\u000e\u0010\u001c\u001a\u00020\u00062\u0006\u0010\u001d\u001a\u00020\u0017R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsLogger;", "", "logBuffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "logAlerting", "", "position", "", "isHeadsUp", "", "logAlertingHeader", "logConversation", "logConversationsHeader", "logForegroundService", "logHeadsUp", "logIncomingHeader", "logMediaControls", "logOther", "clazz", "Ljava/lang/Class;", "logPosition", "label", "", "logSilent", "logSilentHeader", "logStartSectionUpdate", "reason", "logStr", "str"})
@com.android.systemui.dagger.SysUISingleton()
public final class NotificationSectionsLogger {
    private final com.android.systemui.log.LogBuffer logBuffer = null;
    
    public final void logStartSectionUpdate(@org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    public final void logIncomingHeader(int position) {
    }
    
    public final void logMediaControls(int position) {
    }
    
    public final void logConversationsHeader(int position) {
    }
    
    public final void logAlertingHeader(int position) {
    }
    
    public final void logSilentHeader(int position) {
    }
    
    public final void logOther(int position, @org.jetbrains.annotations.NotNull()
    java.lang.Class<?> clazz) {
    }
    
    public final void logHeadsUp(int position, boolean isHeadsUp) {
    }
    
    public final void logConversation(int position, boolean isHeadsUp) {
    }
    
    public final void logAlerting(int position, boolean isHeadsUp) {
    }
    
    public final void logSilent(int position, boolean isHeadsUp) {
    }
    
    public final void logForegroundService(int position, boolean isHeadsUp) {
    }
    
    public final void logStr(@org.jetbrains.annotations.NotNull()
    java.lang.String str) {
    }
    
    private final void logPosition(int position, java.lang.String label, boolean isHeadsUp) {
    }
    
    private final void logPosition(int position, java.lang.String label) {
    }
    
    @javax.inject.Inject()
    public NotificationSectionsLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.NotificationSectionLog()
    com.android.systemui.log.LogBuffer logBuffer) {
        super();
    }
}
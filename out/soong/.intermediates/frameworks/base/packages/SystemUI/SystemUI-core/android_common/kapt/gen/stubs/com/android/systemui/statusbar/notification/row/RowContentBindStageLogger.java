package com.android.systemui.statusbar.notification.row;

import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.dagger.NotificationLog;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0016\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\bR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/row/RowContentBindStageLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "logStageParams", "", "notifKey", "", "stageParams"})
public final class RowContentBindStageLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logStageParams(@org.jetbrains.annotations.NotNull()
    java.lang.String notifKey, @org.jetbrains.annotations.NotNull()
    java.lang.String stageParams) {
    }
    
    @javax.inject.Inject()
    public RowContentBindStageLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.NotificationLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}
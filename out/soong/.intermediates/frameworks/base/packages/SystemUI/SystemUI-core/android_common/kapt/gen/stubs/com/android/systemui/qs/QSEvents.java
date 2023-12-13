package com.android.systemui.qs;

import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.logging.UiEventLoggerImpl;
import com.android.internal.logging.testing.UiEventLoggerFake;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0006\u0010\b\u001a\u00020\tJ\u0006\u0010\n\u001a\u00020\u000bR\u001e\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u0003\u001a\u00020\u0004@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"Lcom/android/systemui/qs/QSEvents;", "", "()V", "<set-?>", "Lcom/android/internal/logging/UiEventLogger;", "qsUiEventsLogger", "getQsUiEventsLogger", "()Lcom/android/internal/logging/UiEventLogger;", "resetLogger", "", "setLoggerForTesting", "Lcom/android/internal/logging/testing/UiEventLoggerFake;"})
public final class QSEvents {
    @org.jetbrains.annotations.NotNull()
    private static com.android.internal.logging.UiEventLogger qsUiEventsLogger;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.qs.QSEvents INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.internal.logging.UiEventLogger getQsUiEventsLogger() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.internal.logging.testing.UiEventLoggerFake setLoggerForTesting() {
        return null;
    }
    
    public final void resetLogger() {
    }
    
    private QSEvents() {
        super();
    }
}
package com.android.systemui.qs;

import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogLevel;
import com.android.systemui.log.dagger.QSFragmentDisableLog;
import com.android.systemui.statusbar.DisableFlagsLogger;
import javax.inject.Inject;

/**
 * A helper class for logging disable flag changes made in [QSFragment].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0019\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0016\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\nR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/QSFragmentDisableFlagsLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "disableFlagsLogger", "Lcom/android/systemui/statusbar/DisableFlagsLogger;", "(Lcom/android/systemui/log/LogBuffer;Lcom/android/systemui/statusbar/DisableFlagsLogger;)V", "logDisableFlagChange", "", "new", "Lcom/android/systemui/statusbar/DisableFlagsLogger$DisableState;", "newAfterLocalModification"})
public final class QSFragmentDisableFlagsLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    private final com.android.systemui.statusbar.DisableFlagsLogger disableFlagsLogger = null;
    
    /**
     * Logs a string representing the new state received by [QSFragment] and any modifications that
     * were made to the flags locally.
     *
     * @param new see [DisableFlagsLogger.getDisableFlagsString]
     * @param newAfterLocalModification see [DisableFlagsLogger.getDisableFlagsString]
     */
    public final void logDisableFlagChange(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.DisableFlagsLogger.DisableState p0_54480, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.DisableFlagsLogger.DisableState newAfterLocalModification) {
    }
    
    @javax.inject.Inject()
    public QSFragmentDisableFlagsLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.QSFragmentDisableLog()
    com.android.systemui.log.LogBuffer buffer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.DisableFlagsLogger disableFlagsLogger) {
        super();
    }
}
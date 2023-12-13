package com.android.systemui.statusbar.phone.ongoingcall;

import androidx.annotation.VisibleForTesting;
import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

/**
 * A class to log events for the ongoing call chip.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001:\u0001\nB\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\t\u001a\u00020\b2\u0006\u0010\u0005\u001a\u00020\u0006R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallLogger;", "", "logger", "Lcom/android/internal/logging/UiEventLogger;", "(Lcom/android/internal/logging/UiEventLogger;)V", "chipIsVisible", "", "logChipClicked", "", "logChipVisibilityChanged", "OngoingCallEvents"})
@com.android.systemui.dagger.SysUISingleton()
public final class OngoingCallLogger {
    private boolean chipIsVisible = false;
    private final com.android.internal.logging.UiEventLogger logger = null;
    
    /**
     * Logs that the ongoing call chip was clicked.
     */
    public final void logChipClicked() {
    }
    
    /**
     * If needed, logs that the ongoing call chip's visibility has changed.
     *
     * For now, only logs when the chip changes from not visible to visible.
     */
    public final void logChipVisibilityChanged(boolean chipIsVisible) {
    }
    
    @javax.inject.Inject()
    public OngoingCallLogger(@org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger logger) {
        super();
    }
    
    @androidx.annotation.VisibleForTesting()
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0006\b\u0087\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u00012\u00020\u0002B\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\b\u001a\u00020\u0004H\u0016R\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007j\u0002\b\tj\u0002\b\n"}, d2 = {"Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallLogger$OngoingCallEvents;", "", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "metricId", "", "(Ljava/lang/String;II)V", "getMetricId", "()I", "getId", "ONGOING_CALL_VISIBLE", "ONGOING_CALL_CLICKED"})
    public static enum OngoingCallEvents implements com.android.internal.logging.UiEventLogger.UiEventEnum {
        @com.android.internal.logging.UiEvent(doc = "The ongoing call chip became visible")
        /*public static final*/ ONGOING_CALL_VISIBLE /* = new ONGOING_CALL_VISIBLE(0) */,
        @com.android.internal.logging.UiEvent(doc = "The ongoing call chip was clicked")
        /*public static final*/ ONGOING_CALL_CLICKED /* = new ONGOING_CALL_CLICKED(0) */;
        private final int metricId = 0;
        
        @java.lang.Override()
        public int getId() {
            return 0;
        }
        
        public final int getMetricId() {
            return 0;
        }
        
        OngoingCallEvents(int metricId) {
        }
    }
}
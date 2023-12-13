package com.android.systemui.qs;

import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.logging.UiEventLoggerImpl;
import com.android.internal.logging.testing.UiEventLoggerFake;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0005\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u00012\u00020\u0002B\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\u0006\u001a\u00020\u0004H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000j\u0002\b\u0007j\u0002\b\bj\u0002\b\t"}, d2 = {"Lcom/android/systemui/qs/QSDndEvent;", "", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "_id", "", "(Ljava/lang/String;II)V", "getId", "QS_DND_CONDITION_SELECT", "QS_DND_TIME_UP", "QS_DND_TIME_DOWN"})
public enum QSDndEvent implements com.android.internal.logging.UiEventLogger.UiEventEnum {
    @com.android.internal.logging.UiEvent(doc = "TODO(beverlyt)")
    /*public static final*/ QS_DND_CONDITION_SELECT /* = new QS_DND_CONDITION_SELECT(0) */,
    @com.android.internal.logging.UiEvent(doc = "TODO(beverlyt)")
    /*public static final*/ QS_DND_TIME_UP /* = new QS_DND_TIME_UP(0) */,
    @com.android.internal.logging.UiEvent(doc = "TODO(beverlyt)")
    /*public static final*/ QS_DND_TIME_DOWN /* = new QS_DND_TIME_DOWN(0) */;
    private final int _id = 0;
    
    @java.lang.Override()
    public int getId() {
        return 0;
    }
    
    QSDndEvent(int _id) {
    }
}
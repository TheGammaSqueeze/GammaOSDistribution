package com.android.systemui.qs;

import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.logging.UiEventLoggerImpl;
import com.android.internal.logging.testing.UiEventLoggerFake;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\b\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u00012\u00020\u0002B\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\u0006\u001a\u00020\u0004H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000j\u0002\b\u0007j\u0002\b\bj\u0002\b\tj\u0002\b\nj\u0002\b\u000bj\u0002\b\f"}, d2 = {"Lcom/android/systemui/qs/QSEditEvent;", "", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "_id", "", "(Ljava/lang/String;II)V", "getId", "QS_EDIT_REMOVE", "QS_EDIT_ADD", "QS_EDIT_MOVE", "QS_EDIT_OPEN", "QS_EDIT_CLOSED", "QS_EDIT_RESET"})
public enum QSEditEvent implements com.android.internal.logging.UiEventLogger.UiEventEnum {
    @com.android.internal.logging.UiEvent(doc = "Tile removed from current tiles")
    /*public static final*/ QS_EDIT_REMOVE /* = new QS_EDIT_REMOVE(0) */,
    @com.android.internal.logging.UiEvent(doc = "Tile added to current tiles")
    /*public static final*/ QS_EDIT_ADD /* = new QS_EDIT_ADD(0) */,
    @com.android.internal.logging.UiEvent(doc = "Tile moved")
    /*public static final*/ QS_EDIT_MOVE /* = new QS_EDIT_MOVE(0) */,
    @com.android.internal.logging.UiEvent(doc = "QS customizer open")
    /*public static final*/ QS_EDIT_OPEN /* = new QS_EDIT_OPEN(0) */,
    @com.android.internal.logging.UiEvent(doc = "QS customizer closed")
    /*public static final*/ QS_EDIT_CLOSED /* = new QS_EDIT_CLOSED(0) */,
    @com.android.internal.logging.UiEvent(doc = "QS tiles reset")
    /*public static final*/ QS_EDIT_RESET /* = new QS_EDIT_RESET(0) */;
    private final int _id = 0;
    
    @java.lang.Override()
    public int getId() {
        return 0;
    }
    
    QSEditEvent(int _id) {
    }
}
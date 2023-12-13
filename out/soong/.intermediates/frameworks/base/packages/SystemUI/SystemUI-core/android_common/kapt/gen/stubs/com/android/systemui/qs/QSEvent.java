package com.android.systemui.qs;

import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.logging.UiEventLoggerImpl;
import com.android.internal.logging.testing.UiEventLoggerFake;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u000b\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u00012\u00020\u0002B\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\u0006\u001a\u00020\u0004H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000j\u0002\b\u0007j\u0002\b\bj\u0002\b\tj\u0002\b\nj\u0002\b\u000bj\u0002\b\fj\u0002\b\rj\u0002\b\u000ej\u0002\b\u000f"}, d2 = {"Lcom/android/systemui/qs/QSEvent;", "", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "_id", "", "(Ljava/lang/String;II)V", "getId", "QS_ACTION_CLICK", "QS_ACTION_SECONDARY_CLICK", "QS_ACTION_LONG_PRESS", "QS_PANEL_EXPANDED", "QS_PANEL_COLLAPSED", "QS_TILE_VISIBLE", "QQS_PANEL_EXPANDED", "QQS_PANEL_COLLAPSED", "QQS_TILE_VISIBLE"})
public enum QSEvent implements com.android.internal.logging.UiEventLogger.UiEventEnum {
    @com.android.internal.logging.UiEvent(doc = "Tile clicked. It has an instance id and a spec (or packageName)")
    /*public static final*/ QS_ACTION_CLICK /* = new QS_ACTION_CLICK(0) */,
    @com.android.internal.logging.UiEvent(doc = "Tile secondary button clicked. It has an instance id and a spec (or packageName)")
    /*public static final*/ QS_ACTION_SECONDARY_CLICK /* = new QS_ACTION_SECONDARY_CLICK(0) */,
    @com.android.internal.logging.UiEvent(doc = "Tile long clicked. It has an instance id and a spec (or packageName)")
    /*public static final*/ QS_ACTION_LONG_PRESS /* = new QS_ACTION_LONG_PRESS(0) */,
    @com.android.internal.logging.UiEvent(doc = "Quick Settings panel expanded")
    /*public static final*/ QS_PANEL_EXPANDED /* = new QS_PANEL_EXPANDED(0) */,
    @com.android.internal.logging.UiEvent(doc = "Quick Settings panel collapsed")
    /*public static final*/ QS_PANEL_COLLAPSED /* = new QS_PANEL_COLLAPSED(0) */,
    @com.android.internal.logging.UiEvent(doc = "Tile visible in Quick Settings panel. The tile may be in a different page. It has an instance id and a spec (or packageName)")
    /*public static final*/ QS_TILE_VISIBLE /* = new QS_TILE_VISIBLE(0) */,
    @com.android.internal.logging.UiEvent(doc = "Quick Quick Settings panel expanded")
    /*public static final*/ QQS_PANEL_EXPANDED /* = new QQS_PANEL_EXPANDED(0) */,
    @com.android.internal.logging.UiEvent(doc = "Quick Quick Settings panel collapsed")
    /*public static final*/ QQS_PANEL_COLLAPSED /* = new QQS_PANEL_COLLAPSED(0) */,
    @com.android.internal.logging.UiEvent(doc = "Tile visible in Quick Quick Settings panel. It has an instance id and a spec (or packageName)")
    /*public static final*/ QQS_TILE_VISIBLE /* = new QQS_TILE_VISIBLE(0) */;
    private final int _id = 0;
    
    @java.lang.Override()
    public int getId() {
        return 0;
    }
    
    QSEvent(int _id) {
    }
}
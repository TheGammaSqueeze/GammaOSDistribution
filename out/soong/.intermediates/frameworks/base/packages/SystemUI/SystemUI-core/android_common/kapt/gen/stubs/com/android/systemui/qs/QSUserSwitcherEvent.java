package com.android.systemui.qs;

import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.logging.UiEventLoggerImpl;
import com.android.internal.logging.testing.UiEventLoggerFake;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\n\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u00012\u00020\u0002B\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\u0006\u001a\u00020\u0004H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000j\u0002\b\u0007j\u0002\b\bj\u0002\b\tj\u0002\b\nj\u0002\b\u000bj\u0002\b\fj\u0002\b\rj\u0002\b\u000e"}, d2 = {"Lcom/android/systemui/qs/QSUserSwitcherEvent;", "", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "_id", "", "(Ljava/lang/String;II)V", "getId", "QS_USER_SWITCH", "QS_USER_DETAIL_OPEN", "QS_USER_DETAIL_CLOSE", "QS_USER_MORE_SETTINGS", "QS_USER_GUEST_ADD", "QS_USER_GUEST_WIPE", "QS_USER_GUEST_CONTINUE", "QS_USER_GUEST_REMOVE"})
public enum QSUserSwitcherEvent implements com.android.internal.logging.UiEventLogger.UiEventEnum {
    @com.android.internal.logging.UiEvent(doc = "The current user has been switched in the detail panel")
    /*public static final*/ QS_USER_SWITCH /* = new QS_USER_SWITCH(0) */,
    @com.android.internal.logging.UiEvent(doc = "User switcher QS detail panel open")
    /*public static final*/ QS_USER_DETAIL_OPEN /* = new QS_USER_DETAIL_OPEN(0) */,
    @com.android.internal.logging.UiEvent(doc = "User switcher QS detail panel closed")
    /*public static final*/ QS_USER_DETAIL_CLOSE /* = new QS_USER_DETAIL_CLOSE(0) */,
    @com.android.internal.logging.UiEvent(doc = "User switcher QS detail panel more settings pressed")
    /*public static final*/ QS_USER_MORE_SETTINGS /* = new QS_USER_MORE_SETTINGS(0) */,
    @com.android.internal.logging.UiEvent(doc = "The user has added a guest in the detail panel")
    /*public static final*/ QS_USER_GUEST_ADD /* = new QS_USER_GUEST_ADD(0) */,
    @com.android.internal.logging.UiEvent(doc = "The user selected \'Start over\' after switching to the existing Guest user")
    /*public static final*/ QS_USER_GUEST_WIPE /* = new QS_USER_GUEST_WIPE(0) */,
    @com.android.internal.logging.UiEvent(doc = "The user selected \'Yes, continue\' after switching to the existing Guest user")
    /*public static final*/ QS_USER_GUEST_CONTINUE /* = new QS_USER_GUEST_CONTINUE(0) */,
    @com.android.internal.logging.UiEvent(doc = "The user has pressed \'Remove guest\' in the detail panel")
    /*public static final*/ QS_USER_GUEST_REMOVE /* = new QS_USER_GUEST_REMOVE(0) */;
    private final int _id = 0;
    
    @java.lang.Override()
    public int getId() {
        return 0;
    }
    
    QSUserSwitcherEvent(int _id) {
    }
}
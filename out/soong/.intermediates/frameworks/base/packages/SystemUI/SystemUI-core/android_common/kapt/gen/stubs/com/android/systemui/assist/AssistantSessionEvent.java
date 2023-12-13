package com.android.systemui.assist;

import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\t\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u00012\u00020\u0002B\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\u0006\u001a\u00020\u0004H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000j\u0002\b\u0007j\u0002\b\bj\u0002\b\tj\u0002\b\nj\u0002\b\u000bj\u0002\b\fj\u0002\b\r"}, d2 = {"Lcom/android/systemui/assist/AssistantSessionEvent;", "", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "id", "", "(Ljava/lang/String;II)V", "getId", "ASSISTANT_SESSION_UNKNOWN", "ASSISTANT_SESSION_TIMEOUT_DISMISS", "ASSISTANT_SESSION_INVOCATION_START", "ASSISTANT_SESSION_INVOCATION_CANCELLED", "ASSISTANT_SESSION_USER_DISMISS", "ASSISTANT_SESSION_UPDATE", "ASSISTANT_SESSION_CLOSE"})
public enum AssistantSessionEvent implements com.android.internal.logging.UiEventLogger.UiEventEnum {
    @com.android.internal.logging.UiEvent(doc = "Unknown assistant session event")
    /*public static final*/ ASSISTANT_SESSION_UNKNOWN /* = new ASSISTANT_SESSION_UNKNOWN(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant session dismissed due to timeout")
    /*public static final*/ ASSISTANT_SESSION_TIMEOUT_DISMISS /* = new ASSISTANT_SESSION_TIMEOUT_DISMISS(0) */,
    @com.android.internal.logging.UiEvent(doc = "User began a gesture for invoking the Assistant")
    /*public static final*/ ASSISTANT_SESSION_INVOCATION_START /* = new ASSISTANT_SESSION_INVOCATION_START(0) */,
    @com.android.internal.logging.UiEvent(doc = "User stopped a gesture for invoking the Assistant before the gesture was completed")
    /*public static final*/ ASSISTANT_SESSION_INVOCATION_CANCELLED /* = new ASSISTANT_SESSION_INVOCATION_CANCELLED(0) */,
    @com.android.internal.logging.UiEvent(doc = "User manually dismissed the Assistant session")
    /*public static final*/ ASSISTANT_SESSION_USER_DISMISS /* = new ASSISTANT_SESSION_USER_DISMISS(0) */,
    @com.android.internal.logging.UiEvent(doc = "The Assistant session has changed modes")
    /*public static final*/ ASSISTANT_SESSION_UPDATE /* = new ASSISTANT_SESSION_UPDATE(0) */,
    @com.android.internal.logging.UiEvent(doc = "The Assistant session completed")
    /*public static final*/ ASSISTANT_SESSION_CLOSE /* = new ASSISTANT_SESSION_CLOSE(0) */;
    private final int id = 0;
    
    @java.lang.Override()
    public int getId() {
        return 0;
    }
    
    AssistantSessionEvent(int id) {
    }
}
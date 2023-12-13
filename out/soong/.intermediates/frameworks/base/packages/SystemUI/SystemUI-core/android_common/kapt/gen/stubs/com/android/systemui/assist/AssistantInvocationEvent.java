package com.android.systemui.assist;

import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u000e\b\u0086\u0001\u0018\u0000 \u00122\b\u0012\u0004\u0012\u00020\u00000\u00012\u00020\u0002:\u0001\u0012B\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\u0006\u001a\u00020\u0004H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000j\u0002\b\u0007j\u0002\b\bj\u0002\b\tj\u0002\b\nj\u0002\b\u000bj\u0002\b\fj\u0002\b\rj\u0002\b\u000ej\u0002\b\u000fj\u0002\b\u0010j\u0002\b\u0011"}, d2 = {"Lcom/android/systemui/assist/AssistantInvocationEvent;", "", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "id", "", "(Ljava/lang/String;II)V", "getId", "ASSISTANT_INVOCATION_UNKNOWN", "ASSISTANT_INVOCATION_TOUCH_GESTURE", "ASSISTANT_INVOCATION_TOUCH_GESTURE_ALT", "ASSISTANT_INVOCATION_HOTWORD", "ASSISTANT_INVOCATION_QUICK_SEARCH_BAR", "ASSISTANT_INVOCATION_HOME_LONG_PRESS", "ASSISTANT_INVOCATION_PHYSICAL_GESTURE", "ASSISTANT_INVOCATION_START_UNKNOWN", "ASSISTANT_INVOCATION_START_TOUCH_GESTURE", "ASSISTANT_INVOCATION_START_PHYSICAL_GESTURE", "ASSISTANT_INVOCATION_POWER_LONG_PRESS", "Companion"})
public enum AssistantInvocationEvent implements com.android.internal.logging.UiEventLogger.UiEventEnum {
    @com.android.internal.logging.UiEvent(doc = "Assistant invoked by unknown method")
    /*public static final*/ ASSISTANT_INVOCATION_UNKNOWN /* = new ASSISTANT_INVOCATION_UNKNOWN(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invoked by touch gesture")
    /*public static final*/ ASSISTANT_INVOCATION_TOUCH_GESTURE /* = new ASSISTANT_INVOCATION_TOUCH_GESTURE(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invoked by alternate touch gesture")
    /*public static final*/ ASSISTANT_INVOCATION_TOUCH_GESTURE_ALT /* = new ASSISTANT_INVOCATION_TOUCH_GESTURE_ALT(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invoked by hotword")
    /*public static final*/ ASSISTANT_INVOCATION_HOTWORD /* = new ASSISTANT_INVOCATION_HOTWORD(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invoked by tapping quick search bar icon")
    /*public static final*/ ASSISTANT_INVOCATION_QUICK_SEARCH_BAR /* = new ASSISTANT_INVOCATION_QUICK_SEARCH_BAR(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invoked by home button long press")
    /*public static final*/ ASSISTANT_INVOCATION_HOME_LONG_PRESS /* = new ASSISTANT_INVOCATION_HOME_LONG_PRESS(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invoked by physical gesture")
    /*public static final*/ ASSISTANT_INVOCATION_PHYSICAL_GESTURE /* = new ASSISTANT_INVOCATION_PHYSICAL_GESTURE(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invocation started by unknown method")
    /*public static final*/ ASSISTANT_INVOCATION_START_UNKNOWN /* = new ASSISTANT_INVOCATION_START_UNKNOWN(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invocation started by touch gesture")
    /*public static final*/ ASSISTANT_INVOCATION_START_TOUCH_GESTURE /* = new ASSISTANT_INVOCATION_START_TOUCH_GESTURE(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invocation started by physical gesture")
    /*public static final*/ ASSISTANT_INVOCATION_START_PHYSICAL_GESTURE /* = new ASSISTANT_INVOCATION_START_PHYSICAL_GESTURE(0) */,
    @com.android.internal.logging.UiEvent(doc = "Assistant invoked by long press on the physical power button")
    /*public static final*/ ASSISTANT_INVOCATION_POWER_LONG_PRESS /* = new ASSISTANT_INVOCATION_POWER_LONG_PRESS(0) */;
    private final int id = 0;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.assist.AssistantInvocationEvent.Companion Companion = null;
    
    @java.lang.Override()
    public int getId() {
        return 0;
    }
    
    AssistantInvocationEvent(int id) {
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0004J\u0016\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\u00042\u0006\u0010\t\u001a\u00020\n"}, d2 = {"Lcom/android/systemui/assist/AssistantInvocationEvent$Companion;", "", "()V", "deviceStateFromLegacyDeviceState", "", "legacyDeviceState", "eventFromLegacyInvocationType", "Lcom/android/systemui/assist/AssistantInvocationEvent;", "legacyInvocationType", "isInvocationComplete", ""})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.assist.AssistantInvocationEvent eventFromLegacyInvocationType(int legacyInvocationType, boolean isInvocationComplete) {
            return null;
        }
        
        public final int deviceStateFromLegacyDeviceState(int legacyDeviceState) {
            return 0;
        }
        
        private Companion() {
            super();
        }
    }
}
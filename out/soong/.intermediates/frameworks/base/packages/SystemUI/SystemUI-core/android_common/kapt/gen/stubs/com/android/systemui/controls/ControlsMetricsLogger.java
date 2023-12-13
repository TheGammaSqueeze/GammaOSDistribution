package com.android.systemui.controls;

import android.service.controls.DeviceTypes.DeviceType;
import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.controls.ui.ControlViewHolder;

/**
 * Interface for logging UI events related to controls
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0007\bf\u0018\u00002\u00020\u0001:\u0001\u0012J\b\u0010\u0002\u001a\u00020\u0003H&J\u0018\u0010\u0004\u001a\u00020\u00032\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016J(\u0010\t\u001a\u00020\u00032\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u000b2\u0006\u0010\r\u001a\u00020\u000b2\u0006\u0010\u0007\u001a\u00020\bH&J\u0018\u0010\u000e\u001a\u00020\u00032\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016J\u0018\u0010\u000f\u001a\u00020\u00032\u0006\u0010\r\u001a\u00020\u000b2\u0006\u0010\u0007\u001a\u00020\bH\u0016J\u0018\u0010\u0010\u001a\u00020\u00032\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016J\u0018\u0010\u0011\u001a\u00020\u00032\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016"}, d2 = {"Lcom/android/systemui/controls/ControlsMetricsLogger;", "", "assignInstanceId", "", "drag", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "isLocked", "", "log", "eventId", "", "deviceType", "uid", "longPress", "refreshBegin", "refreshEnd", "touch", "ControlsEvents"})
public abstract interface ControlsMetricsLogger {
    
    /**
     * Assign a new instance id for this controls session, defined as when the controls area is
     * made visible to when it is closed.
     */
    public abstract void assignInstanceId();
    
    public abstract void touch(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked);
    
    public abstract void drag(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked);
    
    public abstract void longPress(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked);
    
    public abstract void refreshBegin(int uid, boolean isLocked);
    
    public abstract void refreshEnd(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked);
    
    /**
     * Logs a controls-related event
     *
     * @param eventId Main UIEvent to capture
     * @param deviceType One of {@link android.service.controls.DeviceTypes}
     * @param packageName Package name of the service that receives the request
     * @param isLocked Is the device locked at the start of the action?
     */
    public abstract void log(int eventId, @android.service.controls.DeviceTypes.DeviceType()
    int deviceType, int uid, boolean isLocked);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\t\b\u0082\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u00012\u00020\u0002B\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\b\u001a\u00020\u0004H\u0016R\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007j\u0002\b\tj\u0002\b\nj\u0002\b\u000bj\u0002\b\fj\u0002\b\r"}, d2 = {"Lcom/android/systemui/controls/ControlsMetricsLogger$ControlsEvents;", "", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "metricId", "", "(Ljava/lang/String;II)V", "getMetricId", "()I", "getId", "CONTROL_TOUCH", "CONTROL_DRAG", "CONTROL_LONG_PRESS", "CONTROL_REFRESH_BEGIN", "CONTROL_REFRESH_END"})
    public static enum ControlsEvents implements com.android.internal.logging.UiEventLogger.UiEventEnum {
        @com.android.internal.logging.UiEvent(doc = "User touched a control")
        /*public static final*/ CONTROL_TOUCH /* = new CONTROL_TOUCH(0) */,
        @com.android.internal.logging.UiEvent(doc = "User dragged a control")
        /*public static final*/ CONTROL_DRAG /* = new CONTROL_DRAG(0) */,
        @com.android.internal.logging.UiEvent(doc = "User long-pressed a control")
        /*public static final*/ CONTROL_LONG_PRESS /* = new CONTROL_LONG_PRESS(0) */,
        @com.android.internal.logging.UiEvent(doc = "User has opened controls, and a state refresh has begun")
        /*public static final*/ CONTROL_REFRESH_BEGIN /* = new CONTROL_REFRESH_BEGIN(0) */,
        @com.android.internal.logging.UiEvent(doc = "User has opened controls, and a state refresh has ended")
        /*public static final*/ CONTROL_REFRESH_END /* = new CONTROL_REFRESH_END(0) */;
        private final int metricId = 0;
        
        @java.lang.Override()
        public int getId() {
            return 0;
        }
        
        public final int getMetricId() {
            return 0;
        }
        
        ControlsEvents(int metricId) {
        }
    }
    
    /**
     * Interface for logging UI events related to controls
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
        
        public static void touch(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ControlsMetricsLogger $this, @org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked) {
        }
        
        public static void drag(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ControlsMetricsLogger $this, @org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked) {
        }
        
        public static void longPress(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ControlsMetricsLogger $this, @org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked) {
        }
        
        public static void refreshBegin(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ControlsMetricsLogger $this, int uid, boolean isLocked) {
        }
        
        public static void refreshEnd(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ControlsMetricsLogger $this, @org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked) {
        }
    }
}
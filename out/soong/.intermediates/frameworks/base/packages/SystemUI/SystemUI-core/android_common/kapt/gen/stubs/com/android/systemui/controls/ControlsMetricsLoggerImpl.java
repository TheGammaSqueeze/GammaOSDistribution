package com.android.systemui.controls;

import android.service.controls.DeviceTypes.DeviceType;
import com.android.internal.logging.InstanceIdSequence;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.shared.system.SysUiStatsLog;
import javax.inject.Inject;

/**
 * Implementation for logging UI events related to controls
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0000\b\u0007\u0018\u0000 \u000f2\u00020\u0001:\u0001\u000fB\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0007\u001a\u00020\bH\u0016J(\u0010\t\u001a\u00020\b2\u0006\u0010\n\u001a\u00020\u00042\u0006\u0010\u000b\u001a\u00020\u00042\u0006\u0010\f\u001a\u00020\u00042\u0006\u0010\r\u001a\u00020\u000eH\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ControlsMetricsLoggerImpl;", "Lcom/android/systemui/controls/ControlsMetricsLogger;", "()V", "instanceId", "", "instanceIdSequence", "Lcom/android/internal/logging/InstanceIdSequence;", "assignInstanceId", "", "log", "eventId", "deviceType", "uid", "isLocked", "", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class ControlsMetricsLoggerImpl implements com.android.systemui.controls.ControlsMetricsLogger {
    private final com.android.internal.logging.InstanceIdSequence instanceIdSequence = null;
    private int instanceId = 0;
    private static final int INSTANCE_ID_MAX = 8192;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ControlsMetricsLoggerImpl.Companion Companion = null;
    
    @java.lang.Override()
    public void assignInstanceId() {
    }
    
    /**
     * {@see ControlsMetricsLogger#log}
     */
    @java.lang.Override()
    public void log(int eventId, @android.service.controls.DeviceTypes.DeviceType()
    int deviceType, int uid, boolean isLocked) {
    }
    
    @javax.inject.Inject()
    public ControlsMetricsLoggerImpl() {
        super();
    }
    
    public void touch(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked) {
    }
    
    public void drag(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked) {
    }
    
    public void longPress(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked) {
    }
    
    public void refreshBegin(int uid, boolean isLocked) {
    }
    
    public void refreshEnd(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, boolean isLocked) {
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ControlsMetricsLoggerImpl$Companion;", "", "()V", "INSTANCE_ID_MAX", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
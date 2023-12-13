package com.android.systemui.statusbar.policy;

import java.lang.System;

/**
 * Supports adding a DeviceControls QS tile
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\bf\u0018\u00002\u00020\u0001:\u0001\u0007J\b\u0010\u0002\u001a\u00020\u0003H&J\u0010\u0010\u0004\u001a\u00020\u00032\u0006\u0010\u0005\u001a\u00020\u0006H&"}, d2 = {"Lcom/android/systemui/statusbar/policy/DeviceControlsController;", "", "removeCallback", "", "setCallback", "callback", "Lcom/android/systemui/statusbar/policy/DeviceControlsController$Callback;", "Callback"})
public abstract interface DeviceControlsController {
    
    /**
     * Add callback, supporting only a single callback at once
     */
    public abstract void setCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.DeviceControlsController.Callback callback);
    
    /**
     * Remove any existing callback, if any
     */
    public abstract void removeCallback();
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\bf\u0018\u00002\u00020\u0001J\u0017\u0010\u0002\u001a\u00020\u00032\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005H&\u00a2\u0006\u0002\u0010\u0006"}, d2 = {"Lcom/android/systemui/statusbar/policy/DeviceControlsController$Callback;", "", "onControlsUpdate", "", "position", "", "(Ljava/lang/Integer;)V"})
    public static abstract interface Callback {
        
        /**
         * If controls become available, initiate this callback with the desired position
         */
        public abstract void onControlsUpdate(@org.jetbrains.annotations.Nullable()
        java.lang.Integer position);
    }
}
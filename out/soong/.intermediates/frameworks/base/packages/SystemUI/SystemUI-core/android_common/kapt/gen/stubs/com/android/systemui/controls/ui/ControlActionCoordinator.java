package com.android.systemui.controls.ui;

import android.content.Context;
import android.service.controls.Control;

/**
 * All control interactions should be routed through this coordinator. It handles dispatching of
 * actions, haptic support, and all detail panels
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0002\b\u0004\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\b\u0010\b\u001a\u00020\tH&J\u0010\u0010\n\u001a\u00020\t2\u0006\u0010\u000b\u001a\u00020\fH&J\u0010\u0010\r\u001a\u00020\t2\u0006\u0010\u000e\u001a\u00020\u000fH&J\u0010\u0010\u0010\u001a\u00020\t2\u0006\u0010\u0011\u001a\u00020\u0012H&J \u0010\u0013\u001a\u00020\t2\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0014\u001a\u00020\u000f2\u0006\u0010\u0015\u001a\u00020\u0016H&J \u0010\u0017\u001a\u00020\t2\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0014\u001a\u00020\u000f2\u0006\u0010\u0018\u001a\u00020\fH&J \u0010\u0019\u001a\u00020\t2\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0014\u001a\u00020\u000f2\u0006\u0010\u001a\u001a\u00020\u001bH&R\u0018\u0010\u0002\u001a\u00020\u0003X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0004\u0010\u0005\"\u0004\b\u0006\u0010\u0007"}, d2 = {"Lcom/android/systemui/controls/ui/ControlActionCoordinator;", "", "activityContext", "Landroid/content/Context;", "getActivityContext", "()Landroid/content/Context;", "setActivityContext", "(Landroid/content/Context;)V", "closeDialogs", "", "drag", "isEdge", "", "enableActionOnTouch", "controlId", "", "longPress", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "setValue", "templateId", "newValue", "", "toggle", "isChecked", "touch", "control", "Landroid/service/controls/Control;"})
public abstract interface ControlActionCoordinator {
    
    @org.jetbrains.annotations.NotNull()
    public abstract android.content.Context getActivityContext();
    
    public abstract void setActivityContext(@org.jetbrains.annotations.NotNull()
    android.content.Context p0);
    
    /**
     * Close any dialogs which may have been open
     */
    public abstract void closeDialogs();
    
    /**
     * Create a [BooleanAction], and inform the service of a request to change the device state
     *
     * @param cvh [ControlViewHolder] for the control
     * @param templateId id of the control's template, as given by the service
     * @param isChecked new requested state of the control
     */
    public abstract void toggle(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, @org.jetbrains.annotations.NotNull()
    java.lang.String templateId, boolean isChecked);
    
    /**
     * For non-toggle controls, touching may create a dialog or invoke a [CommandAction].
     *
     * @param cvh [ControlViewHolder] for the control
     * @param templateId id of the control's template, as given by the service
     * @param control the control as sent by the service
     */
    public abstract void touch(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, @org.jetbrains.annotations.NotNull()
    java.lang.String templateId, @org.jetbrains.annotations.NotNull()
    android.service.controls.Control control);
    
    /**
     * When a ToggleRange control is interacting with, a drag event is sent.
     *
     * @param isEdge did the drag event reach a control edge
     */
    public abstract void drag(boolean isEdge);
    
    /**
     * Send a request to update the value of a device using the [FloatAction].
     *
     * @param cvh [ControlViewHolder] for the control
     * @param templateId id of the control's template, as given by the service
     * @param newValue value to set for the device
     */
    public abstract void setValue(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, @org.jetbrains.annotations.NotNull()
    java.lang.String templateId, float newValue);
    
    /**
     * User interaction with a control may be blocked for a period of time while actions are being
     * executed by the application.  When the response returns, run this method to enable further
     * user interaction.
     */
    public abstract void enableActionOnTouch(@org.jetbrains.annotations.NotNull()
    java.lang.String controlId);
    
    /**
     * All long presses will be shown in a 3/4 height bottomsheet panel, in order for the user to
     * retain context with their favorited controls in the power menu.
     */
    public abstract void longPress(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh);
}
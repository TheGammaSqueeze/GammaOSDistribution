package com.android.systemui.controls.controller;

import android.content.ComponentName;
import android.service.controls.Control;
import android.service.controls.ControlsProviderService;
import android.service.controls.actions.ControlAction;
import com.android.systemui.util.UserAwareController;
import java.util.function.Consumer;

/**
 * Controller for keeping track of any [ControlsProviderService] that needs to be bound.
 *
 * This controller serves as an interface between [ControlsController] and the services.
 *
 * This controller being a [UserAwareController] means that all binding and requests will be
 * performed on services bound as the current user.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\bf\u0018\u00002\u00020\u0001:\u0001\u0015J \u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u00072\u0006\u0010\u0002\u001a\u00020\bH&J\u0018\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u00052\u0006\u0010\f\u001a\u00020\rH&J\u0018\u0010\u000e\u001a\u00020\u00032\u0006\u0010\u000b\u001a\u00020\u00052\u0006\u0010\f\u001a\u00020\rH&J\u0010\u0010\u000f\u001a\u00020\u00032\u0006\u0010\u000b\u001a\u00020\u0005H&J\u0010\u0010\u0010\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0010\u0010\u0011\u001a\u00020\u00032\u0006\u0010\u0012\u001a\u00020\u0013H&J\b\u0010\u0014\u001a\u00020\u0003H&\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingController;", "Lcom/android/systemui/util/UserAwareController;", "action", "", "componentName", "Landroid/content/ComponentName;", "controlInfo", "Lcom/android/systemui/controls/controller/ControlInfo;", "Landroid/service/controls/actions/ControlAction;", "bindAndLoad", "Ljava/lang/Runnable;", "component", "callback", "Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "bindAndLoadSuggested", "bindService", "onComponentRemoved", "subscribe", "structureInfo", "Lcom/android/systemui/controls/controller/StructureInfo;", "unsubscribe", "LoadCallback"})
public abstract interface ControlsBindingController extends com.android.systemui.util.UserAwareController {
    
    /**
     * Request bind to a service and load all controls.
     *
     * @param component The [ComponentName] of the service to bind
     * @param callback a callback to return the loaded controls to (or an error).
     * @return a runnable to cancel the load
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.Runnable bindAndLoad(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback);
    
    /**
     * Request bind to a service and load a limited number of suggested controls.
     *
     * @param component The [ComponentName] of the service to bind
     * @param callback a callback to return the loaded controls to (or an error).
     */
    public abstract void bindAndLoadSuggested(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback);
    
    /**
     * Request to bind to the given service.
     *
     * @param component The [ComponentName] of the service to bind
     */
    public abstract void bindService(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component);
    
    /**
     * Send a subscribe message to retrieve status of a set of controls.
     *
     * @param structureInfo structure containing the controls to update
     */
    public abstract void subscribe(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.StructureInfo structureInfo);
    
    /**
     * Send an action performed on a [Control].
     *
     * @param componentName name of the component
     * @param controlInfo information about the actioned control
     * @param action the action performed on the control
     */
    public abstract void action(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo, @org.jetbrains.annotations.NotNull()
    android.service.controls.actions.ControlAction action);
    
    /**
     * Unsubscribe from all services to stop status updates.
     */
    public abstract void unsubscribe();
    
    /**
     * Notify this controller that this component has been removed (uninstalled).
     */
    public abstract void onComponentRemoved(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName);
    
    /**
     * Consumer for load calls.
     *
     * Supports also sending error messages.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\bf\u0018\u00002\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\u00020\u0001J\u0010\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0007H&"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "Ljava/util/function/Consumer;", "", "Landroid/service/controls/Control;", "error", "", "message", ""})
    public static abstract interface LoadCallback extends java.util.function.Consumer<java.util.List<? extends android.service.controls.Control>> {
        
        /**
         * Indicates an error loading.
         *
         * @message an error message.
         */
        public abstract void error(@org.jetbrains.annotations.NotNull()
        java.lang.String message);
    }
}
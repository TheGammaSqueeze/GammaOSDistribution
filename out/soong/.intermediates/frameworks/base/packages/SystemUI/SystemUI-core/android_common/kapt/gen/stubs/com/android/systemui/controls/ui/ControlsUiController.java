package com.android.systemui.controls.ui;

import android.content.ComponentName;
import android.content.Context;
import android.service.controls.Control;
import android.service.controls.actions.ControlAction;
import android.view.ViewGroup;
import com.android.systemui.controls.controller.StructureInfo;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\bf\u0018\u0000 \u001c2\u00020\u0001:\u0001\u001cJ\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0016\u0010\u0006\u001a\u00020\u00072\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00070\tH&J\b\u0010\n\u001a\u00020\u0003H&J \u0010\u000b\u001a\u00020\u00032\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H&J\u001e\u0010\u0012\u001a\u00020\u00032\u0006\u0010\f\u001a\u00020\r2\f\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00140\tH&J \u0010\u0015\u001a\u00020\u00032\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bH&"}, d2 = {"Lcom/android/systemui/controls/ui/ControlsUiController;", "", "closeDialogs", "", "immediately", "", "getPreferredStructure", "Lcom/android/systemui/controls/controller/StructureInfo;", "structures", "", "hide", "onActionResponse", "componentName", "Landroid/content/ComponentName;", "controlId", "", "response", "", "onRefreshState", "controls", "Landroid/service/controls/Control;", "show", "parent", "Landroid/view/ViewGroup;", "onDismiss", "Ljava/lang/Runnable;", "activityContext", "Landroid/content/Context;", "Companion"})
public abstract interface ControlsUiController {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ui.ControlsUiController.Companion Companion = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String TAG = "ControlsUiController";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String EXTRA_ANIMATE = "extra_animate";
    
    public abstract void show(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent, @org.jetbrains.annotations.NotNull()
    java.lang.Runnable onDismiss, @org.jetbrains.annotations.NotNull()
    android.content.Context activityContext);
    
    public abstract void hide();
    
    /**
     * Request all open dialogs be closed. Set [immediately] to true to dismiss without
     * animations.
     */
    public abstract void closeDialogs(boolean immediately);
    
    public abstract void onRefreshState(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.util.List<android.service.controls.Control> controls);
    
    public abstract void onActionResponse(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.String controlId, @android.service.controls.actions.ControlAction.ResponseResult()
    int response);
    
    /**
     * Returns the structure that is currently preferred by the user.
     *
     * This structure will be the one that appears when the user first opens the controls activity.
     */
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.controls.controller.StructureInfo getPreferredStructure(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.controller.StructureInfo> structures);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/ControlsUiController$Companion;", "", "()V", "EXTRA_ANIMATE", "", "TAG"})
    public static final class Companion {
        @org.jetbrains.annotations.NotNull()
        public static final java.lang.String TAG = "ControlsUiController";
        @org.jetbrains.annotations.NotNull()
        public static final java.lang.String EXTRA_ANIMATE = "extra_animate";
        
        private Companion() {
            super();
        }
    }
}
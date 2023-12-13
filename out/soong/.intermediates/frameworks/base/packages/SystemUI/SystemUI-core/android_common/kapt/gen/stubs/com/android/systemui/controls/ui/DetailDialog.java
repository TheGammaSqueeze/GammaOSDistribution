package com.android.systemui.controls.ui;

import android.app.ActivityOptions;
import android.app.ActivityTaskManager;
import android.app.Dialog;
import android.app.PendingIntent;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.graphics.Rect;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowInsets;
import android.view.WindowInsets.Type;
import android.view.WindowManager;
import android.widget.ImageView;
import com.android.internal.policy.ScreenDecorationsUtils;
import com.android.systemui.R;
import com.android.wm.shell.TaskView;

/**
 * A dialog that provides an {@link TaskView}, allowing the application to provide
 * additional information and actions pertaining to a {@link android.service.controls.Control}.
 * The activity being launched is specified by {@link android.service.controls.Control#getAppIntent}.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000 $2\u00020\u0001:\u0001$B\'\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\b\u0010\u001f\u001a\u00020 H\u0016J\u0006\u0010!\u001a\u00020\"J\u0006\u0010#\u001a\u00020 R\u0013\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u001a\u0010\u000f\u001a\u00020\u0010X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0018R\u0011\u0010\u0019\u001a\u00020\u001a\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001b\u0010\u001cR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u001e"}, d2 = {"Lcom/android/systemui/controls/ui/DetailDialog;", "Landroid/app/Dialog;", "activityContext", "Landroid/content/Context;", "taskView", "Lcom/android/wm/shell/TaskView;", "pendingIntent", "Landroid/app/PendingIntent;", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "(Landroid/content/Context;Lcom/android/wm/shell/TaskView;Landroid/app/PendingIntent;Lcom/android/systemui/controls/ui/ControlViewHolder;)V", "getActivityContext", "()Landroid/content/Context;", "getCvh", "()Lcom/android/systemui/controls/ui/ControlViewHolder;", "detailTaskId", "", "getDetailTaskId", "()I", "setDetailTaskId", "(I)V", "fillInIntent", "Landroid/content/Intent;", "getPendingIntent", "()Landroid/app/PendingIntent;", "stateCallback", "Lcom/android/wm/shell/TaskView$Listener;", "getStateCallback", "()Lcom/android/wm/shell/TaskView$Listener;", "getTaskView", "()Lcom/android/wm/shell/TaskView;", "dismiss", "", "getTaskViewBounds", "Landroid/graphics/Rect;", "removeDetailTask", "Companion"})
public final class DetailDialog extends android.app.Dialog {
    private int detailTaskId = android.app.ActivityTaskManager.INVALID_TASK_ID;
    private final android.content.Intent fillInIntent = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.wm.shell.TaskView.Listener stateCallback = null;
    @org.jetbrains.annotations.Nullable()
    private final android.content.Context activityContext = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.wm.shell.TaskView taskView = null;
    @org.jetbrains.annotations.NotNull()
    private final android.app.PendingIntent pendingIntent = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.controls.ui.ControlViewHolder cvh = null;
    private static final java.lang.String EXTRA_USE_PANEL = "controls.DISPLAY_IN_PANEL";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ui.DetailDialog.Companion Companion = null;
    
    public final int getDetailTaskId() {
        return 0;
    }
    
    public final void setDetailTaskId(int p0) {
    }
    
    public final void removeDetailTask() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.TaskView.Listener getStateCallback() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.Rect getTaskViewBounds() {
        return null;
    }
    
    @java.lang.Override()
    public void dismiss() {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.content.Context getActivityContext() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.TaskView getTaskView() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.app.PendingIntent getPendingIntent() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.ControlViewHolder getCvh() {
        return null;
    }
    
    public DetailDialog(@org.jetbrains.annotations.Nullable()
    android.content.Context activityContext, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.TaskView taskView, @org.jetbrains.annotations.NotNull()
    android.app.PendingIntent pendingIntent, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/DetailDialog$Companion;", "", "()V", "EXTRA_USE_PANEL", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
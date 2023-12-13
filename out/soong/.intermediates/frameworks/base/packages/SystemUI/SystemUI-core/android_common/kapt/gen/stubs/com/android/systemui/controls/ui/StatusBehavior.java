package com.android.systemui.controls.ui;

import android.app.AlertDialog;
import android.app.PendingIntent;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.service.controls.Control;
import android.view.View;
import android.view.WindowManager;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eH\u0016J\u0010\u0010\u000f\u001a\u00020\n2\u0006\u0010\u0003\u001a\u00020\u0004H\u0016J\u0018\u0010\u0010\u001a\u00020\n2\u0006\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u000b\u001a\u00020\fH\u0002R\u001a\u0010\u0003\u001a\u00020\u0004X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\b"}, d2 = {"Lcom/android/systemui/controls/ui/StatusBehavior;", "Lcom/android/systemui/controls/ui/Behavior;", "()V", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "getCvh", "()Lcom/android/systemui/controls/ui/ControlViewHolder;", "setCvh", "(Lcom/android/systemui/controls/ui/ControlViewHolder;)V", "bind", "", "cws", "Lcom/android/systemui/controls/ui/ControlWithState;", "colorOffset", "", "initialize", "showNotFoundDialog"})
public final class StatusBehavior implements com.android.systemui.controls.ui.Behavior {
    public com.android.systemui.controls.ui.ControlViewHolder cvh;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.ControlViewHolder getCvh() {
        return null;
    }
    
    public final void setCvh(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder p0) {
    }
    
    @java.lang.Override()
    public void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh) {
    }
    
    @java.lang.Override()
    public void bind(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlWithState cws, int colorOffset) {
    }
    
    private final void showNotFoundDialog(com.android.systemui.controls.ui.ControlViewHolder cvh, com.android.systemui.controls.ui.ControlWithState cws) {
    }
    
    public StatusBehavior() {
        super();
    }
}
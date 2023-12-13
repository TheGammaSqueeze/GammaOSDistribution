package com.android.systemui.controls.ui;

import android.graphics.drawable.Drawable;
import android.graphics.drawable.LayerDrawable;
import android.service.controls.Control;
import android.service.controls.templates.ControlTemplate;
import android.service.controls.templates.TemperatureControlTemplate;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u001fH\u0016J\u0010\u0010 \u001a\u00020\u001b2\u0006\u0010\u000f\u001a\u00020\u0010H\u0016R\u001a\u0010\u0003\u001a\u00020\u0004X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\bR\u001a\u0010\t\u001a\u00020\nX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u001a\u0010\u000f\u001a\u00020\u0010X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u001c\u0010\u0015\u001a\u0004\u0018\u00010\u0001X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0016\u0010\u0017\"\u0004\b\u0018\u0010\u0019"}, d2 = {"Lcom/android/systemui/controls/ui/TemperatureControlBehavior;", "Lcom/android/systemui/controls/ui/Behavior;", "()V", "clipLayer", "Landroid/graphics/drawable/Drawable;", "getClipLayer", "()Landroid/graphics/drawable/Drawable;", "setClipLayer", "(Landroid/graphics/drawable/Drawable;)V", "control", "Landroid/service/controls/Control;", "getControl", "()Landroid/service/controls/Control;", "setControl", "(Landroid/service/controls/Control;)V", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "getCvh", "()Lcom/android/systemui/controls/ui/ControlViewHolder;", "setCvh", "(Lcom/android/systemui/controls/ui/ControlViewHolder;)V", "subBehavior", "getSubBehavior", "()Lcom/android/systemui/controls/ui/Behavior;", "setSubBehavior", "(Lcom/android/systemui/controls/ui/Behavior;)V", "bind", "", "cws", "Lcom/android/systemui/controls/ui/ControlWithState;", "colorOffset", "", "initialize"})
public final class TemperatureControlBehavior implements com.android.systemui.controls.ui.Behavior {
    public android.graphics.drawable.Drawable clipLayer;
    public android.service.controls.Control control;
    public com.android.systemui.controls.ui.ControlViewHolder cvh;
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.controls.ui.Behavior subBehavior;
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.Drawable getClipLayer() {
        return null;
    }
    
    public final void setClipLayer(@org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.controls.Control getControl() {
        return null;
    }
    
    public final void setControl(@org.jetbrains.annotations.NotNull()
    android.service.controls.Control p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.ControlViewHolder getCvh() {
        return null;
    }
    
    public final void setCvh(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.controls.ui.Behavior getSubBehavior() {
        return null;
    }
    
    public final void setSubBehavior(@org.jetbrains.annotations.Nullable()
    com.android.systemui.controls.ui.Behavior p0) {
    }
    
    @java.lang.Override()
    public void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh) {
    }
    
    @java.lang.Override()
    public void bind(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlWithState cws, int colorOffset) {
    }
    
    public TemperatureControlBehavior() {
        super();
    }
}
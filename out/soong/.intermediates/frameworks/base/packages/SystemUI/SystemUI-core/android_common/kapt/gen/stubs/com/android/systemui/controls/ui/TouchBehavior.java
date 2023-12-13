package com.android.systemui.controls.ui;

import android.graphics.drawable.Drawable;
import android.graphics.drawable.LayerDrawable;
import android.view.View;
import android.service.controls.Control;
import android.service.controls.templates.ControlTemplate;
import android.service.controls.templates.StatelessTemplate;
import com.android.systemui.R;

/**
 * Supports touch events, but has no notion of state as the {@link ToggleBehavior} does. Must be
 * used with {@link StatelessTemplate}.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u0000 (2\u00020\u0001:\u0001(B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\"\u001a\u00020#2\u0006\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020\u001aH\u0016J\u0010\u0010\'\u001a\u00020#2\u0006\u0010\u000f\u001a\u00020\u0010H\u0016R\u001a\u0010\u0003\u001a\u00020\u0004X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\bR\u001a\u0010\t\u001a\u00020\nX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u001a\u0010\u000f\u001a\u00020\u0010X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u0014\u0010\u0015\u001a\u00020\u00168BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0017\u0010\u0018R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u001c\u001a\u00020\u001dX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001e\u0010\u001f\"\u0004\b \u0010!"}, d2 = {"Lcom/android/systemui/controls/ui/TouchBehavior;", "Lcom/android/systemui/controls/ui/Behavior;", "()V", "clipLayer", "Landroid/graphics/drawable/Drawable;", "getClipLayer", "()Landroid/graphics/drawable/Drawable;", "setClipLayer", "(Landroid/graphics/drawable/Drawable;)V", "control", "Landroid/service/controls/Control;", "getControl", "()Landroid/service/controls/Control;", "setControl", "(Landroid/service/controls/Control;)V", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "getCvh", "()Lcom/android/systemui/controls/ui/ControlViewHolder;", "setCvh", "(Lcom/android/systemui/controls/ui/ControlViewHolder;)V", "enabled", "", "getEnabled", "()Z", "lastColorOffset", "", "statelessTouch", "template", "Landroid/service/controls/templates/ControlTemplate;", "getTemplate", "()Landroid/service/controls/templates/ControlTemplate;", "setTemplate", "(Landroid/service/controls/templates/ControlTemplate;)V", "bind", "", "cws", "Lcom/android/systemui/controls/ui/ControlWithState;", "colorOffset", "initialize", "Companion"})
public final class TouchBehavior implements com.android.systemui.controls.ui.Behavior {
    public android.graphics.drawable.Drawable clipLayer;
    public android.service.controls.templates.ControlTemplate template;
    public android.service.controls.Control control;
    public com.android.systemui.controls.ui.ControlViewHolder cvh;
    private boolean statelessTouch = false;
    private int lastColorOffset = 0;
    public static final long STATELESS_ENABLE_TIMEOUT_IN_MILLIS = 3000L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ui.TouchBehavior.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.Drawable getClipLayer() {
        return null;
    }
    
    public final void setClipLayer(@org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.controls.templates.ControlTemplate getTemplate() {
        return null;
    }
    
    public final void setTemplate(@org.jetbrains.annotations.NotNull()
    android.service.controls.templates.ControlTemplate p0) {
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
    
    private final boolean getEnabled() {
        return false;
    }
    
    @java.lang.Override()
    public void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh) {
    }
    
    @java.lang.Override()
    public void bind(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlWithState cws, int colorOffset) {
    }
    
    public TouchBehavior() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/TouchBehavior$Companion;", "", "()V", "STATELESS_ENABLE_TIMEOUT_IN_MILLIS", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
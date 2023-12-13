package com.android.systemui.controls.ui;

import android.graphics.BlendMode;
import android.graphics.BlendModeColorFilter;
import android.graphics.drawable.ClipDrawable;
import android.graphics.drawable.LayerDrawable;
import android.view.View;
import android.service.controls.Control;
import android.service.controls.templates.ThumbnailTemplate;
import android.util.TypedValue;
import com.android.systemui.R;

/**
 * Supports display of static images on the background of the tile. When marked active, the title
 * and subtitle will not be visible. To be used with {@link Thumbnailtemplate} only.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010\u0007\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0018\u0010\"\u001a\u00020#2\u0006\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020\u0003H\u0016J\u0010\u0010\'\u001a\u00020#2\u0006\u0010\r\u001a\u00020\u000eH\u0016R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0007\u001a\u00020\bX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\n\"\u0004\b\u000b\u0010\fR\u001a\u0010\r\u001a\u00020\u000eX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000f\u0010\u0010\"\u0004\b\u0011\u0010\u0012R\u0014\u0010\u0013\u001a\u00020\u00148BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0015\u0010\u0016R\u000e\u0010\u0017\u001a\u00020\u0003X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u001c\u001a\u00020\u001dX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001e\u0010\u001f\"\u0004\b \u0010!"}, d2 = {"Lcom/android/systemui/controls/ui/ThumbnailBehavior;", "Lcom/android/systemui/controls/ui/Behavior;", "currentUserId", "", "(I)V", "canUseIconPredicate", "Lcom/android/systemui/controls/ui/CanUseIconPredicate;", "control", "Landroid/service/controls/Control;", "getControl", "()Landroid/service/controls/Control;", "setControl", "(Landroid/service/controls/Control;)V", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "getCvh", "()Lcom/android/systemui/controls/ui/ControlViewHolder;", "setCvh", "(Lcom/android/systemui/controls/ui/ControlViewHolder;)V", "enabled", "", "getEnabled", "()Z", "shadowColor", "shadowOffsetX", "", "shadowOffsetY", "shadowRadius", "template", "Landroid/service/controls/templates/ThumbnailTemplate;", "getTemplate", "()Landroid/service/controls/templates/ThumbnailTemplate;", "setTemplate", "(Landroid/service/controls/templates/ThumbnailTemplate;)V", "bind", "", "cws", "Lcom/android/systemui/controls/ui/ControlWithState;", "colorOffset", "initialize"})
public final class ThumbnailBehavior implements com.android.systemui.controls.ui.Behavior {
    public android.service.controls.templates.ThumbnailTemplate template;
    public android.service.controls.Control control;
    public com.android.systemui.controls.ui.ControlViewHolder cvh;
    private float shadowOffsetX = 0.0F;
    private float shadowOffsetY = 0.0F;
    private float shadowRadius = 0.0F;
    private int shadowColor = 0;
    private final com.android.systemui.controls.ui.CanUseIconPredicate canUseIconPredicate = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.controls.templates.ThumbnailTemplate getTemplate() {
        return null;
    }
    
    public final void setTemplate(@org.jetbrains.annotations.NotNull()
    android.service.controls.templates.ThumbnailTemplate p0) {
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
    
    public ThumbnailBehavior(int currentUserId) {
        super();
    }
}
package com.android.systemui.controls.ui;

import android.graphics.Canvas;
import android.graphics.Path;
import android.graphics.Rect;
import android.graphics.RectF;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.DrawableWrapper;

/**
 * Use a path to add mask for corners around the drawable, to match the radius
 * of the underlying shape.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0012H\u0016J\u0010\u0010\u0013\u001a\u00020\u00102\u0006\u0010\u0014\u001a\u00020\u0015H\u0016J(\u0010\u0013\u001a\u00020\u00102\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00172\u0006\u0010\u0014\u001a\u00020\u00172\u0006\u0010\u0019\u001a\u00020\u0017H\u0016J\u0010\u0010\u001a\u001a\u00020\u00102\u0006\u0010\u0014\u001a\u00020\u001bH\u0002R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000e"}, d2 = {"Lcom/android/systemui/controls/ui/CornerDrawable;", "Landroid/graphics/drawable/DrawableWrapper;", "wrapped", "Landroid/graphics/drawable/Drawable;", "cornerRadius", "", "(Landroid/graphics/drawable/Drawable;F)V", "getCornerRadius", "()F", "path", "Landroid/graphics/Path;", "getPath", "()Landroid/graphics/Path;", "getWrapped", "()Landroid/graphics/drawable/Drawable;", "draw", "", "canvas", "Landroid/graphics/Canvas;", "setBounds", "r", "Landroid/graphics/Rect;", "l", "", "t", "b", "updatePath", "Landroid/graphics/RectF;"})
public final class CornerDrawable extends android.graphics.drawable.DrawableWrapper {
    @org.jetbrains.annotations.NotNull()
    private final android.graphics.Path path = null;
    @org.jetbrains.annotations.NotNull()
    private final android.graphics.drawable.Drawable wrapped = null;
    private final float cornerRadius = 0.0F;
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.Path getPath() {
        return null;
    }
    
    @java.lang.Override()
    public void draw(@org.jetbrains.annotations.NotNull()
    android.graphics.Canvas canvas) {
    }
    
    @java.lang.Override()
    public void setBounds(int l, int t, int r, int b) {
    }
    
    @java.lang.Override()
    public void setBounds(@org.jetbrains.annotations.NotNull()
    android.graphics.Rect r) {
    }
    
    private final void updatePath(android.graphics.RectF r) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.Drawable getWrapped() {
        return null;
    }
    
    public final float getCornerRadius() {
        return 0.0F;
    }
    
    public CornerDrawable(@org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable wrapped, float cornerRadius) {
        super(null);
    }
}
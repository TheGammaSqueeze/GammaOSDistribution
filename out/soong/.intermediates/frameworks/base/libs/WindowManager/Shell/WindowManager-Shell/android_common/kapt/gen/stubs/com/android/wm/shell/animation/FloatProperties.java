package com.android.wm.shell.animation;

import android.graphics.Rect;
import android.graphics.RectF;
import androidx.dynamicanimation.animation.FloatPropertyCompat;

/**
 * Helpful extra properties to use with the [PhysicsAnimator]. These allow you to animate objects
 * such as [Rect] and [RectF].
 *
 * There are additional, more basic properties available in [DynamicAnimation].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\u0018\u0000 \u00032\u00020\u0001:\u0001\u0003B\u0005\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lcom/android/wm/shell/animation/FloatProperties;", "", "()V", "Companion"})
public final class FloatProperties {
    
    /**
     * Represents the x-coordinate of a [Rect]. Typically used to animate moving a Rect
     * horizontally.
     *
     * This property's getter returns [Rect.left], and its setter uses [Rect.offsetTo], which
     * sets [Rect.left] to the new value and offsets [Rect.right] so that the width of the Rect
     * does not change.
     */
    @org.jetbrains.annotations.NotNull()
    public static final androidx.dynamicanimation.animation.FloatPropertyCompat<android.graphics.Rect> RECT_X = null;
    
    /**
     * Represents the y-coordinate of a [Rect]. Typically used to animate moving a Rect
     * vertically.
     *
     * This property's getter returns [Rect.top], and its setter uses [Rect.offsetTo], which
     * sets [Rect.top] to the new value and offsets [Rect.bottom] so that the height of the Rect
     * does not change.
     */
    @org.jetbrains.annotations.NotNull()
    public static final androidx.dynamicanimation.animation.FloatPropertyCompat<android.graphics.Rect> RECT_Y = null;
    
    /**
     * Represents the width of a [Rect]. Typically used to animate resizing a Rect horizontally.
     *
     * This property's getter returns [Rect.width], and its setter changes the value of
     * [Rect.right] by adding the animated width value to [Rect.left].
     */
    @org.jetbrains.annotations.NotNull()
    public static final androidx.dynamicanimation.animation.FloatPropertyCompat<android.graphics.Rect> RECT_WIDTH = null;
    
    /**
     * Represents the height of a [Rect]. Typically used to animate resizing a Rect vertically.
     *
     * This property's getter returns [Rect.height], and its setter changes the value of
     * [Rect.bottom] by adding the animated height value to [Rect.top].
     */
    @org.jetbrains.annotations.NotNull()
    public static final androidx.dynamicanimation.animation.FloatPropertyCompat<android.graphics.Rect> RECT_HEIGHT = null;
    
    /**
     * Represents the x-coordinate of a [RectF]. Typically used to animate moving a RectF
     * horizontally.
     *
     * This property's getter returns [RectF.left], and its setter uses [RectF.offsetTo], which
     * sets [RectF.left] to the new value and offsets [RectF.right] so that the width of the
     * RectF does not change.
     */
    @org.jetbrains.annotations.NotNull()
    public static final androidx.dynamicanimation.animation.FloatPropertyCompat<android.graphics.RectF> RECTF_X = null;
    
    /**
     * Represents the y-coordinate of a [RectF]. Typically used to animate moving a RectF
     * vertically.
     *
     * This property's getter returns [RectF.top], and its setter uses [RectF.offsetTo], which
     * sets [RectF.top] to the new value and offsets [RectF.bottom] so that the height of the
     * RectF does not change.
     */
    @org.jetbrains.annotations.NotNull()
    public static final androidx.dynamicanimation.animation.FloatPropertyCompat<android.graphics.RectF> RECTF_Y = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.wm.shell.animation.FloatProperties.Companion Companion = null;
    
    public FloatProperties() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0016\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u00048\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00050\u00048\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\b0\u00048\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\t\u001a\b\u0012\u0004\u0012\u00020\b0\u00048\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\n\u001a\b\u0012\u0004\u0012\u00020\b0\u00048\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\b0\u00048\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/animation/FloatProperties$Companion;", "", "()V", "RECTF_X", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "Landroid/graphics/RectF;", "RECTF_Y", "RECT_HEIGHT", "Landroid/graphics/Rect;", "RECT_WIDTH", "RECT_X", "RECT_Y"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
package com.android.systemui.media;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.AnimatorSet;
import android.animation.ValueAnimator;
import android.content.res.Resources;
import android.content.res.TypedArray;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorFilter;
import android.graphics.Outline;
import android.graphics.Paint;
import android.graphics.PixelFormat;
import android.graphics.RadialGradient;
import android.graphics.Rect;
import android.graphics.Shader;
import android.graphics.drawable.Drawable;
import android.util.AttributeSet;
import androidx.annotation.Keep;
import com.android.internal.graphics.ColorUtils;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;
import org.xmlpull.v1.XmlPullParser;

/**
 * Drawable that can draw an animated gradient when tapped.
 */
@androidx.annotation.Keep()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0080\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0015\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0003\n\u0002\u0018\u0002\b\u0007\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0014\u0010\u0017\u001a\u00020\u00182\n\u0010\u0019\u001a\u00060\u001aR\u00020\u001bH\u0016J\b\u0010\u001c\u001a\u00020\u0004H\u0016J\u0010\u0010\u001d\u001a\u00020\u00182\u0006\u0010\u001e\u001a\u00020\u001fH\u0016J\b\u0010 \u001a\u00020!H\u0016J\b\u0010\"\u001a\u00020\bH\u0016J\u0010\u0010#\u001a\u00020\u00182\u0006\u0010$\u001a\u00020%H\u0016J\b\u0010&\u001a\u00020\u0004H\u0016J\b\u0010\'\u001a\u00020\u0018H\u0002J.\u0010(\u001a\u00020\u00182\u0006\u0010)\u001a\u00020\u001b2\u0006\u0010*\u001a\u00020+2\u0006\u0010,\u001a\u00020-2\f\u0010.\u001a\b\u0018\u00010\u001aR\u00020\u001bH\u0016J\b\u0010/\u001a\u00020\u0004H\u0016J\b\u00100\u001a\u00020\u0004H\u0016J\u0012\u00101\u001a\u00020\u00042\b\u00102\u001a\u0004\u0018\u00010\u0016H\u0014J\u0010\u00103\u001a\u00020\u00182\u0006\u00104\u001a\u00020\bH\u0016J\u0012\u00105\u001a\u00020\u00182\b\u00106\u001a\u0004\u0018\u000107H\u0016J\u0018\u00108\u001a\u00020\u00182\u0006\u00109\u001a\u00020:2\u0006\u0010;\u001a\u00020:H\u0016J\u0010\u0010<\u001a\u00020\u00182\u0006\u0010=\u001a\u00020>H\u0002R\u001e\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u0003\u001a\u00020\u0004@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\u0006\u0010\u0007R$\u0010\t\u001a\u00020\b2\u0006\u0010\u0003\u001a\u00020\b@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0015\u001a\u0004\u0018\u00010\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/LightSourceDrawable;", "Landroid/graphics/drawable/Drawable;", "()V", "value", "", "active", "setActive", "(Z)V", "", "highlightColor", "getHighlightColor", "()I", "setHighlightColor", "(I)V", "paint", "Landroid/graphics/Paint;", "pressed", "rippleAnimation", "Landroid/animation/Animator;", "rippleData", "Lcom/android/systemui/media/RippleData;", "themeAttrs", "", "applyTheme", "", "t", "Landroid/content/res/Resources$Theme;", "Landroid/content/res/Resources;", "canApplyTheme", "draw", "canvas", "Landroid/graphics/Canvas;", "getDirtyBounds", "Landroid/graphics/Rect;", "getOpacity", "getOutline", "outline", "Landroid/graphics/Outline;", "hasFocusStateSpecified", "illuminate", "inflate", "r", "parser", "Lorg/xmlpull/v1/XmlPullParser;", "attrs", "Landroid/util/AttributeSet;", "theme", "isProjected", "isStateful", "onStateChange", "stateSet", "setAlpha", "alpha", "setColorFilter", "p0", "Landroid/graphics/ColorFilter;", "setHotspot", "x", "", "y", "updateStateFromTypedArray", "a", "Landroid/content/res/TypedArray;"})
public final class LightSourceDrawable extends android.graphics.drawable.Drawable {
    private boolean pressed = false;
    private int[] themeAttrs;
    private final com.android.systemui.media.RippleData rippleData = null;
    private android.graphics.Paint paint;
    private int highlightColor = android.graphics.Color.WHITE;
    
    /**
     * Draw a small highlight under the finger before expanding (or cancelling) it.
     */
    private boolean active = false;
    private android.animation.Animator rippleAnimation;
    
    public final int getHighlightColor() {
        return 0;
    }
    
    public final void setHighlightColor(int value) {
    }
    
    private final void setActive(boolean value) {
    }
    
    /**
     * Draw background and gradient.
     */
    @java.lang.Override()
    public void draw(@org.jetbrains.annotations.NotNull()
    android.graphics.Canvas canvas) {
    }
    
    @java.lang.Override()
    public void getOutline(@org.jetbrains.annotations.NotNull()
    android.graphics.Outline outline) {
    }
    
    @java.lang.Override()
    public int getOpacity() {
        return 0;
    }
    
    @java.lang.Override()
    public void inflate(@org.jetbrains.annotations.NotNull()
    android.content.res.Resources r, @org.jetbrains.annotations.NotNull()
    org.xmlpull.v1.XmlPullParser parser, @org.jetbrains.annotations.NotNull()
    android.util.AttributeSet attrs, @org.jetbrains.annotations.Nullable()
    android.content.res.Resources.Theme theme) {
    }
    
    private final void updateStateFromTypedArray(android.content.res.TypedArray a) {
    }
    
    @java.lang.Override()
    public boolean canApplyTheme() {
        return false;
    }
    
    @java.lang.Override()
    public void applyTheme(@org.jetbrains.annotations.NotNull()
    android.content.res.Resources.Theme t) {
    }
    
    @java.lang.Override()
    public void setColorFilter(@org.jetbrains.annotations.Nullable()
    android.graphics.ColorFilter p0) {
    }
    
    @java.lang.Override()
    public void setAlpha(int alpha) {
    }
    
    /**
     * Draws an animated ripple that expands fading away.
     */
    private final void illuminate() {
    }
    
    @java.lang.Override()
    public void setHotspot(float x, float y) {
    }
    
    @java.lang.Override()
    public boolean isStateful() {
        return false;
    }
    
    @java.lang.Override()
    public boolean hasFocusStateSpecified() {
        return false;
    }
    
    @java.lang.Override()
    public boolean isProjected() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.graphics.Rect getDirtyBounds() {
        return null;
    }
    
    @java.lang.Override()
    protected boolean onStateChange(@org.jetbrains.annotations.Nullable()
    int[] stateSet) {
        return false;
    }
    
    public LightSourceDrawable() {
        super();
    }
}
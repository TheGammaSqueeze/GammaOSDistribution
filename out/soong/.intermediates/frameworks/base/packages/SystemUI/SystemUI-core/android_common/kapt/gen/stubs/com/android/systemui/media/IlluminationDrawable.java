package com.android.systemui.media;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.content.res.ColorStateList;
import android.content.res.Resources;
import android.content.res.TypedArray;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorFilter;
import android.graphics.Outline;
import android.graphics.Paint;
import android.graphics.PixelFormat;
import android.graphics.Xfermode;
import android.graphics.drawable.Drawable;
import android.util.AttributeSet;
import android.util.MathUtils;
import android.view.View;
import androidx.annotation.Keep;
import com.android.internal.graphics.ColorUtils;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;
import org.xmlpull.v1.XmlPullParser;

/**
 * Drawable that can draw an animated gradient when tapped.
 */
@androidx.annotation.Keep()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u009a\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0010\u0007\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0015\n\u0000\n\u0002\u0010\u0014\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\b\u0007\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u001c\u001a\u00020\u001dH\u0002J\u0014\u0010\u001e\u001a\u00020\u001d2\n\u0010\u001f\u001a\u00060 R\u00020!H\u0016J\b\u0010\"\u001a\u00020#H\u0016J\u0010\u0010$\u001a\u00020\u001d2\u0006\u0010%\u001a\u00020&H\u0016J\b\u0010\'\u001a\u00020\u0006H\u0016J\b\u0010(\u001a\u00020\u0006H\u0016J\u0010\u0010)\u001a\u00020\u001d2\u0006\u0010*\u001a\u00020+H\u0016J.\u0010,\u001a\u00020\u001d2\u0006\u0010-\u001a\u00020!2\u0006\u0010.\u001a\u00020/2\u0006\u00100\u001a\u0002012\f\u00102\u001a\b\u0018\u00010 R\u00020!H\u0016J\u000e\u00103\u001a\u00020\u001d2\u0006\u00104\u001a\u000205J\u0010\u00103\u001a\u00020\u001d2\u0006\u00104\u001a\u00020\u0015H\u0002J\u0010\u00106\u001a\u00020\u001d2\u0006\u00107\u001a\u00020\u0006H\u0016J\u0012\u00108\u001a\u00020\u001d2\b\u00109\u001a\u0004\u0018\u00010:H\u0016J\u0015\u0010;\u001a\u00020\u001d2\b\u0010\n\u001a\u0004\u0018\u00010\u000b\u00a2\u0006\u0002\u0010<J\u0012\u0010=\u001a\u00020\u001d2\b\u0010>\u001a\u0004\u0018\u00010?H\u0016J\u0012\u0010@\u001a\u00020\u001d2\b\u0010A\u001a\u0004\u0018\u00010BH\u0016J\u0010\u0010C\u001a\u00020\u001d2\u0006\u0010D\u001a\u00020EH\u0002R\u0010\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u0007\u001a\u00020\u00062\u0006\u0010\u0005\u001a\u00020\u0006@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\b\u0010\tR\u001c\u0010\n\u001a\u00020\u000b8FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\f\u0010\r\"\u0004\b\u000e\u0010\u000fR\u000e\u0010\u0010\u001a\u00020\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00150\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0018\u001a\u0004\u0018\u00010\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/IlluminationDrawable;", "Landroid/graphics/drawable/Drawable;", "()V", "backgroundAnimation", "Landroid/animation/ValueAnimator;", "value", "", "backgroundColor", "setBackgroundColor", "(I)V", "cornerRadius", "", "getCornerRadius", "()F", "setCornerRadius", "(F)V", "cornerRadiusOverride", "highlight", "highlightColor", "lightSources", "Ljava/util/ArrayList;", "Lcom/android/systemui/media/LightSourceDrawable;", "paint", "Landroid/graphics/Paint;", "themeAttrs", "", "tmpHsl", "", "animateBackground", "", "applyTheme", "t", "Landroid/content/res/Resources$Theme;", "Landroid/content/res/Resources;", "canApplyTheme", "", "draw", "canvas", "Landroid/graphics/Canvas;", "getAlpha", "getOpacity", "getOutline", "outline", "Landroid/graphics/Outline;", "inflate", "r", "parser", "Lorg/xmlpull/v1/XmlPullParser;", "attrs", "Landroid/util/AttributeSet;", "theme", "registerLightSource", "lightSource", "Landroid/view/View;", "setAlpha", "alpha", "setColorFilter", "p0", "Landroid/graphics/ColorFilter;", "setCornerRadiusOverride", "(Ljava/lang/Float;)V", "setTintList", "tint", "Landroid/content/res/ColorStateList;", "setXfermode", "mode", "Landroid/graphics/Xfermode;", "updateStateFromTypedArray", "a", "Landroid/content/res/TypedArray;"})
public final class IlluminationDrawable extends android.graphics.drawable.Drawable {
    private int[] themeAttrs;
    private float cornerRadiusOverride = -1.0F;
    private float cornerRadius = 0.0F;
    private int highlightColor = android.graphics.Color.TRANSPARENT;
    private float[] tmpHsl = {0.0F, 0.0F, 0.0F};
    private android.graphics.Paint paint;
    private float highlight = 0.0F;
    private final java.util.ArrayList<com.android.systemui.media.LightSourceDrawable> lightSources = null;
    private int backgroundColor = android.graphics.Color.TRANSPARENT;
    private android.animation.ValueAnimator backgroundAnimation;
    
    public final float getCornerRadius() {
        return 0.0F;
    }
    
    public final void setCornerRadius(float p0) {
    }
    
    private final void setBackgroundColor(int value) {
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
    
    @java.lang.Override()
    public int getAlpha() {
        return 0;
    }
    
    @java.lang.Override()
    public void setXfermode(@org.jetbrains.annotations.Nullable()
    android.graphics.Xfermode mode) {
    }
    
    /**
     * Cross fade background.
     * @see setTintList
     * @see backgroundColor
     */
    private final void animateBackground() {
    }
    
    @java.lang.Override()
    public void setTintList(@org.jetbrains.annotations.Nullable()
    android.content.res.ColorStateList tint) {
    }
    
    public final void registerLightSource(@org.jetbrains.annotations.NotNull()
    android.view.View lightSource) {
    }
    
    private final void registerLightSource(com.android.systemui.media.LightSourceDrawable lightSource) {
    }
    
    /**
     * Set or remove the corner radius override. This is typically set during animations.
     */
    public final void setCornerRadiusOverride(@org.jetbrains.annotations.Nullable()
    java.lang.Float cornerRadius) {
    }
    
    public IlluminationDrawable() {
        super();
    }
}
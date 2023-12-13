package com.android.systemui.statusbar.charging;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.content.Context;
import android.content.res.Configuration;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.PointF;
import android.util.AttributeSet;
import android.view.View;

/**
 * Expanding ripple effect that shows when charging begins.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000f\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\t\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u0019\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\b\u0010&\u001a\u00020\'H\u0014J\u0012\u0010(\u001a\u00020\'2\b\u0010)\u001a\u0004\u0018\u00010*H\u0014J\u0012\u0010+\u001a\u00020\'2\b\u0010,\u001a\u0004\u0018\u00010-H\u0014J\u000e\u0010.\u001a\u00020\'2\u0006\u0010/\u001a\u00020\bJ\u0014\u00100\u001a\u00020\'2\n\b\u0002\u00101\u001a\u0004\u0018\u000102H\u0007R\u000e\u0010\u0007\u001a\u00020\bX\u0082D\u00a2\u0006\u0002\n\u0000R\u001a\u0010\t\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR$\u0010\u0011\u001a\u00020\u00102\u0006\u0010\u000f\u001a\u00020\u0010@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u0013\"\u0004\b\u0014\u0010\u0015R$\u0010\u0017\u001a\u00020\u00162\u0006\u0010\u000f\u001a\u00020\u0016@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0018\u0010\u0019\"\u0004\b\u001a\u0010\u001bR\u001a\u0010\u001c\u001a\u00020\u001dX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001e\u0010\u001f\"\u0004\b \u0010!R\u000e\u0010\"\u001a\u00020#X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010$\u001a\u00020%X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/charging/ChargingRippleView;", "Landroid/view/View;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "defaultColor", "", "duration", "", "getDuration", "()J", "setDuration", "(J)V", "value", "Landroid/graphics/PointF;", "origin", "getOrigin", "()Landroid/graphics/PointF;", "setOrigin", "(Landroid/graphics/PointF;)V", "", "radius", "getRadius", "()F", "setRadius", "(F)V", "rippleInProgress", "", "getRippleInProgress", "()Z", "setRippleInProgress", "(Z)V", "ripplePaint", "Landroid/graphics/Paint;", "rippleShader", "Lcom/android/systemui/statusbar/charging/RippleShader;", "onAttachedToWindow", "", "onConfigurationChanged", "newConfig", "Landroid/content/res/Configuration;", "onDraw", "canvas", "Landroid/graphics/Canvas;", "setColor", "color", "startRipple", "onAnimationEnd", "Ljava/lang/Runnable;"})
public final class ChargingRippleView extends android.view.View {
    private final com.android.systemui.statusbar.charging.RippleShader rippleShader = null;
    private final int defaultColor = -1;
    private final android.graphics.Paint ripplePaint = null;
    private boolean rippleInProgress = false;
    private float radius = 0.0F;
    @org.jetbrains.annotations.NotNull()
    private android.graphics.PointF origin;
    private long duration = 1750L;
    
    public final boolean getRippleInProgress() {
        return false;
    }
    
    public final void setRippleInProgress(boolean p0) {
    }
    
    public final float getRadius() {
        return 0.0F;
    }
    
    public final void setRadius(float value) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.PointF getOrigin() {
        return null;
    }
    
    public final void setOrigin(@org.jetbrains.annotations.NotNull()
    android.graphics.PointF value) {
    }
    
    public final long getDuration() {
        return 0L;
    }
    
    public final void setDuration(long p0) {
    }
    
    @java.lang.Override()
    protected void onConfigurationChanged(@org.jetbrains.annotations.Nullable()
    android.content.res.Configuration newConfig) {
    }
    
    @java.lang.Override()
    protected void onAttachedToWindow() {
    }
    
    public final void startRipple(@org.jetbrains.annotations.Nullable()
    java.lang.Runnable onAnimationEnd) {
    }
    
    public final void startRipple() {
    }
    
    public final void setColor(int color) {
    }
    
    @java.lang.Override()
    protected void onDraw(@org.jetbrains.annotations.Nullable()
    android.graphics.Canvas canvas) {
    }
    
    public ChargingRippleView(@org.jetbrains.annotations.Nullable()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
}
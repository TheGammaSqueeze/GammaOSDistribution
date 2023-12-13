package com.android.systemui.biometrics;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.AnimatorSet;
import android.animation.ValueAnimator;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PointF;
import android.util.AttributeSet;
import android.view.View;
import android.view.animation.PathInterpolator;
import com.android.internal.graphics.ColorUtils;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.statusbar.charging.DwellRippleShader;
import com.android.systemui.statusbar.charging.RippleShader;

/**
 * Expanding ripple effect
 * - startUnlockedRipple for the transition from biometric authentication success to showing
 * launcher.
 * - startDwellRipple for the ripple expansion out when the user has their finger down on the UDFPS
 * sensor area
 * - retractRipple for the ripple animation inwards to signal a failure
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000t\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0007\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u000f\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0019\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\u0012\u0010+\u001a\u00020,2\b\u0010-\u001a\u0004\u0018\u00010.H\u0014J\u0006\u0010/\u001a\u00020,J\u0006\u00100\u001a\u00020,J\u0006\u00101\u001a\u00020,J\u000e\u00102\u001a\u00020,2\u0006\u00103\u001a\u00020\bJ\u0016\u00104\u001a\u00020,2\u0006\u00105\u001a\u00020\u000e2\u0006\u00106\u001a\u00020\u0017J\u000e\u00107\u001a\u00020,2\u0006\u00108\u001a\u00020\u001eJ\u000e\u00109\u001a\u00020,2\u0006\u00105\u001a\u00020\u000eJ\u000e\u0010:\u001a\u00020,2\u0006\u0010;\u001a\u00020\nJ\u0010\u0010<\u001a\u00020,2\b\u0010=\u001a\u0004\u0018\u00010>J\u000e\u0010?\u001a\u00020,2\u0006\u0010;\u001a\u00020\nR\u000e\u0010\u0007\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\bX\u0082D\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u000f\u001a\u00020\u000e2\u0006\u0010\r\u001a\u00020\u000e@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\u0010\u0010\u0011R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\bX\u0082D\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0015\u001a\u0004\u0018\u00010\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u0018\u001a\u00020\u00172\u0006\u0010\r\u001a\u00020\u0017@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\u0019\u0010\u001aR\u000e\u0010\u001b\u001a\u00020\u001cX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u001f\u001a\u00020\u000e2\u0006\u0010\r\u001a\u00020\u000e@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b \u0010\u0011R\u001e\u0010!\u001a\u00020\u00172\u0006\u0010\r\u001a\u00020\u0017@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\"\u0010\u001aR\u0010\u0010#\u001a\u0004\u0018\u00010\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010$\u001a\u00020\bX\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010%\u001a\u00020&X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010(\u001a\u00020)X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/biometrics/AuthRippleView;", "Landroid/view/View;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "alphaInDuration", "", "drawDwell", "", "drawRipple", "dwellExpandDuration", "value", "Landroid/graphics/PointF;", "dwellOrigin", "setDwellOrigin", "(Landroid/graphics/PointF;)V", "dwellPaint", "Landroid/graphics/Paint;", "dwellPulseDuration", "dwellPulseOutAnimator", "Landroid/animation/Animator;", "", "dwellRadius", "setDwellRadius", "(F)V", "dwellShader", "Lcom/android/systemui/statusbar/charging/DwellRippleShader;", "lockScreenColorVal", "", "origin", "setOrigin", "radius", "setRadius", "retractAnimator", "retractDuration", "retractInterpolator", "Landroid/view/animation/PathInterpolator;", "ripplePaint", "rippleShader", "Lcom/android/systemui/statusbar/charging/RippleShader;", "unlockedRippleInProgress", "onDraw", "", "canvas", "Landroid/graphics/Canvas;", "resetDwellAlpha", "resetRippleAlpha", "retractRipple", "setAlphaInDuration", "duration", "setFingerprintSensorLocation", "location", "sensorRadius", "setLockScreenColor", "color", "setSensorLocation", "startDwellRipple", "isDozing", "startUnlockedRipple", "onAnimationEnd", "Ljava/lang/Runnable;", "updateDwellRippleColor"})
public final class AuthRippleView extends android.view.View {
    private final android.view.animation.PathInterpolator retractInterpolator = null;
    private final long dwellPulseDuration = 100L;
    private final long dwellExpandDuration = 0L;
    private boolean drawDwell = false;
    private boolean drawRipple = false;
    private int lockScreenColorVal = android.graphics.Color.WHITE;
    private final long retractDuration = 400L;
    private long alphaInDuration = 0L;
    private boolean unlockedRippleInProgress = false;
    private final com.android.systemui.statusbar.charging.DwellRippleShader dwellShader = null;
    private final android.graphics.Paint dwellPaint = null;
    private final com.android.systemui.statusbar.charging.RippleShader rippleShader = null;
    private final android.graphics.Paint ripplePaint = null;
    private android.animation.Animator retractAnimator;
    private android.animation.Animator dwellPulseOutAnimator;
    private float dwellRadius = 0.0F;
    private android.graphics.PointF dwellOrigin;
    private float radius = 0.0F;
    private android.graphics.PointF origin;
    
    private final void setDwellRadius(float value) {
    }
    
    private final void setDwellOrigin(android.graphics.PointF value) {
    }
    
    private final void setRadius(float value) {
    }
    
    private final void setOrigin(android.graphics.PointF value) {
    }
    
    public final void setSensorLocation(@org.jetbrains.annotations.NotNull()
    android.graphics.PointF location) {
    }
    
    public final void setFingerprintSensorLocation(@org.jetbrains.annotations.NotNull()
    android.graphics.PointF location, float sensorRadius) {
    }
    
    public final void setAlphaInDuration(long duration) {
    }
    
    /**
     * Animate ripple inwards back to radius 0
     */
    public final void retractRipple() {
    }
    
    /**
     * Plays a ripple animation that grows to the dwellRadius with distortion.
     */
    public final void startDwellRipple(boolean isDozing) {
    }
    
    /**
     * Ripple that bursts outwards from the position of the sensor to the edges of the screen
     */
    public final void startUnlockedRipple(@org.jetbrains.annotations.Nullable()
    java.lang.Runnable onAnimationEnd) {
    }
    
    public final void resetRippleAlpha() {
    }
    
    public final void setLockScreenColor(int color) {
    }
    
    public final void updateDwellRippleColor(boolean isDozing) {
    }
    
    public final void resetDwellAlpha() {
    }
    
    @java.lang.Override()
    protected void onDraw(@org.jetbrains.annotations.Nullable()
    android.graphics.Canvas canvas) {
    }
    
    public AuthRippleView(@org.jetbrains.annotations.Nullable()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
}
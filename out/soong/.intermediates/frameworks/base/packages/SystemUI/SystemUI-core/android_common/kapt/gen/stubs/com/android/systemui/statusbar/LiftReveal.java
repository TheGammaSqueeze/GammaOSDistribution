package com.android.systemui.statusbar;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.PointF;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffColorFilter;
import android.graphics.PorterDuffXfermode;
import android.graphics.RadialGradient;
import android.graphics.Shader;
import android.util.AttributeSet;
import android.view.View;
import com.android.systemui.animation.Interpolators;
import java.util.function.Consumer;

/**
 * Light reveal effect that shows light entering the phone from the bottom of the screen. The light
 * enters from the bottom-middle as a narrow oval, and moves upward, eventually widening to fill the
 * screen.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u00042\u0006\u0010\u000f\u001a\u00020\u0010H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/LiftReveal;", "Lcom/android/systemui/statusbar/LightRevealEffect;", "()V", "FADE_END_COLOR_OUT_THRESHOLD", "", "INTERPOLATOR", "Landroid/view/animation/Interpolator;", "kotlin.jvm.PlatformType", "OVAL_INITIAL_BOTTOM_PERCENT", "OVAL_INITIAL_TOP_PERCENT", "OVAL_INITIAL_WIDTH_PERCENT", "WIDEN_OVAL_THRESHOLD", "setRevealAmountOnScrim", "", "amount", "scrim", "Lcom/android/systemui/statusbar/LightRevealScrim;"})
public final class LiftReveal implements com.android.systemui.statusbar.LightRevealEffect {
    
    /**
     * Widen the oval of light after 35%, so it will eventually fill the screen.
     */
    private static final float WIDEN_OVAL_THRESHOLD = 0.35F;
    
    /**
     * After 85%, fade out the black color at the end of the gradient.
     */
    private static final float FADE_END_COLOR_OUT_THRESHOLD = 0.85F;
    
    /**
     * The initial width of the light oval, in percent of scrim width.
     */
    private static final float OVAL_INITIAL_WIDTH_PERCENT = 0.5F;
    
    /**
     * The initial top value of the light oval, in percent of scrim height.
     */
    private static final float OVAL_INITIAL_TOP_PERCENT = 1.1F;
    
    /**
     * The initial bottom value of the light oval, in percent of scrim height.
     */
    private static final float OVAL_INITIAL_BOTTOM_PERCENT = 1.2F;
    
    /**
     * Interpolator to use for the reveal amount.
     */
    private static final android.view.animation.Interpolator INTERPOLATOR = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.LiftReveal INSTANCE = null;
    
    @java.lang.Override()
    public void setRevealAmountOnScrim(float amount, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.LightRevealScrim scrim) {
    }
    
    private LiftReveal() {
        super();
    }
}
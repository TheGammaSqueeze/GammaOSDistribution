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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0002\b\n\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0003\u0012\u0006\u0010\u0006\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0007J\u0018\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00032\u0006\u0010\u0010\u001a\u00020\u0011H\u0016R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\tR\u0011\u0010\u0006\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\tR\u0011\u0010\u0005\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\t"}, d2 = {"Lcom/android/systemui/statusbar/CircleReveal;", "Lcom/android/systemui/statusbar/LightRevealEffect;", "centerX", "", "centerY", "startRadius", "endRadius", "(FFFF)V", "getCenterX", "()F", "getCenterY", "getEndRadius", "getStartRadius", "setRevealAmountOnScrim", "", "amount", "scrim", "Lcom/android/systemui/statusbar/LightRevealScrim;"})
public final class CircleReveal implements com.android.systemui.statusbar.LightRevealEffect {
    
    /**
     * X-value of the circle center of the reveal.
     */
    private final float centerX = 0.0F;
    
    /**
     * Y-value of the circle center of the reveal.
     */
    private final float centerY = 0.0F;
    
    /**
     * Radius of initial state of circle reveal
     */
    private final float startRadius = 0.0F;
    
    /**
     * Radius of end state of circle reveal
     */
    private final float endRadius = 0.0F;
    
    @java.lang.Override()
    public void setRevealAmountOnScrim(float amount, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.LightRevealScrim scrim) {
    }
    
    /**
     * X-value of the circle center of the reveal.
     */
    public final float getCenterX() {
        return 0.0F;
    }
    
    /**
     * Y-value of the circle center of the reveal.
     */
    public final float getCenterY() {
        return 0.0F;
    }
    
    /**
     * Radius of initial state of circle reveal
     */
    public final float getStartRadius() {
        return 0.0F;
    }
    
    /**
     * Radius of end state of circle reveal
     */
    public final float getEndRadius() {
        return 0.0F;
    }
    
    public CircleReveal(float centerX, float centerY, float startRadius, float endRadius) {
        super();
    }
}
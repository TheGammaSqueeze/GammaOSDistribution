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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0018\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u00032\u0006\u0010\f\u001a\u00020\rH\u0016R\u000e\u0010\u0005\u001a\u00020\u0003X\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0003X\u0082D\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\b"}, d2 = {"Lcom/android/systemui/statusbar/PowerButtonReveal;", "Lcom/android/systemui/statusbar/LightRevealEffect;", "powerButtonY", "", "(F)V", "OFF_SCREEN_START_AMOUNT", "WIDTH_INCREASE_MULTIPLIER", "getPowerButtonY", "()F", "setRevealAmountOnScrim", "", "amount", "scrim", "Lcom/android/systemui/statusbar/LightRevealScrim;"})
public final class PowerButtonReveal implements com.android.systemui.statusbar.LightRevealEffect {
    
    /**
     * How far off the side of the screen to start the power button reveal, in terms of percent of
     * the screen width. This ensures that the initial part of the animation (where the reveal is
     * just a sliver) starts just off screen.
     */
    private final float OFF_SCREEN_START_AMOUNT = 0.05F;
    private final float WIDTH_INCREASE_MULTIPLIER = 1.25F;
    
    /**
     * Approximate Y-value of the center of the power button on the physical device.
     */
    private final float powerButtonY = 0.0F;
    
    @java.lang.Override()
    public void setRevealAmountOnScrim(float amount, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.LightRevealScrim scrim) {
    }
    
    /**
     * Approximate Y-value of the center of the power button on the physical device.
     */
    public final float getPowerButtonY() {
        return 0.0F;
    }
    
    public PowerButtonReveal(float powerButtonY) {
        super();
    }
}
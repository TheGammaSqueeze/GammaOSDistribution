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
 * Provides methods to modify the various properties of a [LightRevealScrim] to reveal between 0% to
 * 100% of the view(s) underneath the scrim.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0018\u0002\n\u0000\bf\u0018\u0000 \b2\u00020\u0001:\u0001\bJ\u0018\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0007H&"}, d2 = {"Lcom/android/systemui/statusbar/LightRevealEffect;", "", "setRevealAmountOnScrim", "", "amount", "", "scrim", "Lcom/android/systemui/statusbar/LightRevealScrim;", "Companion"})
public abstract interface LightRevealEffect {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.LightRevealEffect.Companion Companion = null;
    
    public abstract void setRevealAmountOnScrim(float amount, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.LightRevealScrim scrim);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0016\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u0006\u001a\u00020\u0004"}, d2 = {"Lcom/android/systemui/statusbar/LightRevealEffect$Companion;", "", "()V", "getPercentPastThreshold", "", "value", "threshold"})
    public static final class Companion {
        
        /**
         * Returns the percent that the given value is past the threshold value. For example, 0.9 is
         * 50% of the way past 0.8.
         */
        public final float getPercentPastThreshold(float value, float threshold) {
            return 0.0F;
        }
        
        private Companion() {
            super();
        }
    }
}
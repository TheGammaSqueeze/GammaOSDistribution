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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u0000 \u000e2\u00020\u0001:\u0001\u000eB\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0018\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rH\u0016R\u0016\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/LinearLightRevealEffect;", "Lcom/android/systemui/statusbar/LightRevealEffect;", "isVertical", "", "(Z)V", "INTERPOLATOR", "Landroid/view/animation/Interpolator;", "kotlin.jvm.PlatformType", "setRevealAmountOnScrim", "", "amount", "", "scrim", "Lcom/android/systemui/statusbar/LightRevealScrim;", "Companion"})
public final class LinearLightRevealEffect implements com.android.systemui.statusbar.LightRevealEffect {
    private final android.view.animation.Interpolator INTERPOLATOR = null;
    private final boolean isVertical = false;
    @java.lang.Deprecated()
    private static final float GRADIENT_START_BOUNDS_PERCENTAGE = 0.3F;
    @java.lang.Deprecated()
    private static final float REVEAL_GRADIENT_END_COLOR_ALPHA_START_PERCENTAGE = 0.6F;
    @java.lang.Deprecated()
    private static final float START_COLOR_REVEAL_PERCENTAGE = 0.3F;
    @org.jetbrains.annotations.NotNull()
    private static final com.android.systemui.statusbar.LinearLightRevealEffect.Companion Companion = null;
    
    @java.lang.Override()
    public void setRevealAmountOnScrim(float amount, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.LightRevealScrim scrim) {
    }
    
    public LinearLightRevealEffect(boolean isVertical) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0002\b\u0082\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/LinearLightRevealEffect$Companion;", "", "()V", "GRADIENT_START_BOUNDS_PERCENTAGE", "", "REVEAL_GRADIENT_END_COLOR_ALPHA_START_PERCENTAGE", "START_COLOR_REVEAL_PERCENTAGE"})
    static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
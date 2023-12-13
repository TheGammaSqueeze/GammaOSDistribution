package com.android.systemui.util.animation;

import android.animation.ValueAnimator;
import android.graphics.PointF;
import android.util.MathUtils;
import com.android.systemui.animation.Interpolators;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\b\n\u0000\n\u0002\u0010\u0007\n\u0000\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"GONE_FADE_FRACTION", "", "GONE_SCALE_AMOUNT"})
public final class TransitionLayoutControllerKt {
    
    /**
     * The fraction after which we start fading in when going from a gone widget to a visible one
     */
    private static final float GONE_FADE_FRACTION = 0.8F;
    
    /**
     * The amont we're scaling appearing views
     */
    private static final float GONE_SCALE_AMOUNT = 0.8F;
}
package com.android.systemui.doze.util;

import android.util.MathUtils;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u001a\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0005\u001a\u0016\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\u00072\u0006\u0010\t\u001a\u00020\n\u001a\u0006\u0010\u000b\u001a\u00020\u0001\u001a\u0006\u0010\f\u001a\u00020\u0001\u001a \u0010\r\u001a\u00020\u00012\u0006\u0010\u000e\u001a\u00020\u00012\u0006\u0010\b\u001a\u00020\u00012\u0006\u0010\u000f\u001a\u00020\u0001H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"BURN_IN_PREVENTION_PERIOD_PROGRESS", "", "BURN_IN_PREVENTION_PERIOD_SCALE", "BURN_IN_PREVENTION_PERIOD_X", "BURN_IN_PREVENTION_PERIOD_Y", "MILLIS_PER_MINUTES", "getBurnInOffset", "", "amplitude", "xAxis", "", "getBurnInProgressOffset", "getBurnInScale", "zigzag", "x", "period"})
public final class BurnInHelperKt {
    private static final float MILLIS_PER_MINUTES = 60000.0F;
    private static final float BURN_IN_PREVENTION_PERIOD_Y = 521.0F;
    private static final float BURN_IN_PREVENTION_PERIOD_X = 83.0F;
    private static final float BURN_IN_PREVENTION_PERIOD_SCALE = 181.0F;
    private static final float BURN_IN_PREVENTION_PERIOD_PROGRESS = 89.0F;
    
    /**
     * Returns the translation offset that should be used to avoid burn in at
     * the current time (in pixels.)
     *
     * @param amplitude Maximum translation that will be interpolated.
     * @param xAxis If we're moving on X or Y.
     */
    public static final int getBurnInOffset(int amplitude, boolean xAxis) {
        return 0;
    }
    
    /**
     * Returns a progress offset (between 0f and 1.0f) that should be used to avoid burn in at
     * the current time.
     */
    public static final float getBurnInProgressOffset() {
        return 0.0F;
    }
    
    /**
     * Returns a value to scale a view in order to avoid burn in.
     */
    public static final float getBurnInScale() {
        return 0.0F;
    }
    
    /**
     * Implements a continuous, piecewise linear, periodic zig-zag function
     *
     * Can be thought of as a linear approximation of abs(sin(x)))
     *
     * @param period period of the function, ie. zigzag(x + period) == zigzag(x)
     * @param amplitude maximum value of the function
     * @return a value between 0 and amplitude
     */
    private static final float zigzag(float x, float amplitude, float period) {
        return 0.0F;
    }
}
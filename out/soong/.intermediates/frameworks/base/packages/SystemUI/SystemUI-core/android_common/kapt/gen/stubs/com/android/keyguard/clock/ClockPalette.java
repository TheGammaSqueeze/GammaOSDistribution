package com.android.keyguard.clock;

import android.graphics.Color;
import android.util.MathUtils;

/**
 * A helper class to extract colors from a clock face.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u0014\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0015\n\u0000\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0006\u0010\r\u001a\u00020\u0004J\u0006\u0010\u000e\u001a\u00020\u0004J\u0018\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014J\u000e\u0010\u0015\u001a\u00020\u00102\u0006\u0010\u0007\u001a\u00020\bR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/keyguard/clock/ClockPalette;", "", "()V", "accentPrimary", "", "accentSecondaryDark", "accentSecondaryLight", "darkAmount", "", "darkHSV", "", "hsv", "lightHSV", "getPrimaryColor", "getSecondaryColor", "setColorPalette", "", "supportsDarkText", "", "colorPalette", "", "setDarkAmount"})
public final class ClockPalette {
    private float darkAmount = 0.0F;
    private int accentPrimary = android.graphics.Color.WHITE;
    private int accentSecondaryLight = android.graphics.Color.WHITE;
    private int accentSecondaryDark = android.graphics.Color.BLACK;
    private final float[] lightHSV = null;
    private final float[] darkHSV = null;
    private final float[] hsv = null;
    
    /**
     * Returns a color from the palette as an RGB packed int.
     */
    public final int getPrimaryColor() {
        return 0;
    }
    
    /**
     * Returns either a light or dark color from the palette as an RGB packed int.
     */
    public final int getSecondaryColor() {
        return 0;
    }
    
    /**
     * See {@link ClockPlugin#setColorPalette}.
     */
    public final void setColorPalette(boolean supportsDarkText, @org.jetbrains.annotations.Nullable()
    int[] colorPalette) {
    }
    
    /**
     * See {@link ClockPlugin#setDarkAmount}.
     */
    public final void setDarkAmount(float darkAmount) {
    }
    
    public ClockPalette() {
        super();
    }
}
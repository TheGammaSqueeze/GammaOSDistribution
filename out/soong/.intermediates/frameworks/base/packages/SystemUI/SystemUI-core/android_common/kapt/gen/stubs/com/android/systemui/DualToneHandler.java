package com.android.systemui;

import android.animation.ArgbEvaluator;
import android.content.Context;
import android.view.ContextThemeWrapper;
import com.android.settingslib.Utils;

/**
 * A color blender for `Theme.SystemUI` and other themes.
 *
 * This class is used to handle colors from themes in [Context] in the following fashion:
 * * The theme associated has a `darkIconTheme` and a `lightIconTheme`
 * * Each of these themes define colors for the items `singleToneColor`, `backgroundColor`,
 * and `fillColor`.
 *
 * In particular, `Theme.SystemUI` is a valid [Context]. If the provided [Context] does not have
 * the correct themes, the colors that are not found will default to black.
 *
 * It provides a way to obtain these colors and blends for a given background intensity.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\u0018\u00002\u00020\u0001:\u0001\u0012B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000bJ \u0010\f\u001a\u00020\t2\u0006\u0010\r\u001a\u00020\u000b2\u0006\u0010\u0007\u001a\u00020\t2\u0006\u0010\u0005\u001a\u00020\tH\u0002J\u000e\u0010\u000e\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000bJ\u000e\u0010\u000f\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000bJ\u000e\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0002\u001a\u00020\u0003R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0006X\u0082.\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/DualToneHandler;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "darkColor", "Lcom/android/systemui/DualToneHandler$Color;", "lightColor", "getBackgroundColor", "", "intensity", "", "getColorForDarkIntensity", "darkIntensity", "getFillColor", "getSingleColor", "setColorsFromContext", "", "Color"})
public final class DualToneHandler {
    private com.android.systemui.DualToneHandler.Color darkColor;
    private com.android.systemui.DualToneHandler.Color lightColor;
    
    /**
     * Sets the colors in this object from the given [Context]
     *
     * @param[context] A context with the appropriate themes to extract the colors from.
     */
    public final void setColorsFromContext(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
    }
    
    private final int getColorForDarkIntensity(float darkIntensity, int lightColor, int darkColor) {
        return 0;
    }
    
    /**
     * Blends the single color associated with the light and dark theme
     *
     * @param[intensity] Intensity of the background. Correspond with the "percentage" of color
     * from `darkIconTheme` to use
     * @return The blended color
     */
    public final int getSingleColor(float intensity) {
        return 0;
    }
    
    /**
     * Blends the background color associated with the light and dark theme
     *
     * @param[intensity] Intensity of the background. Correspond with the "percentage" of color
     * from `darkIconTheme` to use
     * @return The blended color
     */
    public final int getBackgroundColor(float intensity) {
        return 0;
    }
    
    /**
     * Blends the fill color associated with the light and dark theme
     *
     * @param[intensity] Intensity of the background. Correspond with the "percentage" of color
     * from `darkIconTheme` to use
     * @return The blended color
     */
    public final int getFillColor(float intensity) {
        return 0;
    }
    
    public DualToneHandler(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\f\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0006J\t\u0010\u000b\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\f\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\r\u001a\u00020\u0003H\u00c6\u0003J\'\u0010\u000e\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\u000f\u001a\u00020\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0012\u001a\u00020\u0003H\u00d6\u0001J\t\u0010\u0013\u001a\u00020\u0014H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0005\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\b"}, d2 = {"Lcom/android/systemui/DualToneHandler$Color;", "", "single", "", "background", "fill", "(III)V", "getBackground", "()I", "getFill", "getSingle", "component1", "component2", "component3", "copy", "equals", "", "other", "hashCode", "toString", ""})
    static final class Color {
        private final int single = 0;
        private final int background = 0;
        private final int fill = 0;
        
        public final int getSingle() {
            return 0;
        }
        
        public final int getBackground() {
            return 0;
        }
        
        public final int getFill() {
            return 0;
        }
        
        public Color(int single, int background, int fill) {
            super();
        }
        
        public final int component1() {
            return 0;
        }
        
        public final int component2() {
            return 0;
        }
        
        public final int component3() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.DualToneHandler.Color copy(int single, int background, int fill) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}
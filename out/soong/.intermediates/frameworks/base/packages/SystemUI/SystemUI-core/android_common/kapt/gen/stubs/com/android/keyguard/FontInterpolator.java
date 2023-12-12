package com.android.keyguard;

import android.graphics.fonts.Font;
import android.graphics.fonts.FontVariationAxis;
import android.util.MathUtils;

/**
 * Provide interpolation of two fonts by adjusting font variation settings.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u000b\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\u0010\u0011\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\b\u0018\u0000 $2\u00020\u0001:\u0003$%&B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\fH\u0002J\u0010\u0010\u000e\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\fH\u0002J(\u0010\u000f\u001a\u00020\f2\u0006\u0010\u0010\u001a\u00020\f2\u0006\u0010\u0011\u001a\u00020\f2\u0006\u0010\u0012\u001a\u00020\f2\u0006\u0010\u0013\u001a\u00020\fH\u0002J\u001e\u0010\u0014\u001a\u00020\u00062\u0006\u0010\u0015\u001a\u00020\u00062\u0006\u0010\u0016\u001a\u00020\u00062\u0006\u0010\u0017\u001a\u00020\fJ\u0080\u0001\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00190\u00182\f\u0010\u0015\u001a\b\u0012\u0004\u0012\u00020\u00190\u001a2\f\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00190\u001a2O\u0010\u001b\u001aK\u0012\u0013\u0012\u00110\u001d\u00a2\u0006\f\b\u001e\u0012\b\b\u001f\u0012\u0004\b\b( \u0012\u0015\u0012\u0013\u0018\u00010\f\u00a2\u0006\f\b\u001e\u0012\b\b\u001f\u0012\u0004\b\b(!\u0012\u0015\u0012\u0013\u0018\u00010\f\u00a2\u0006\f\b\u001e\u0012\b\b\u001f\u0012\u0004\b\b(\"\u0012\u0004\u0012\u00020\f0\u001cH\u0002\u00a2\u0006\u0002\u0010#R\u001a\u0010\u0003\u001a\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u00060\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\n\u001a\u000e\u0012\u0004\u0012\u00020\t\u0012\u0004\u0012\u00020\u00060\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/keyguard/FontInterpolator;", "", "()V", "interpCache", "Ljava/util/HashMap;", "Lcom/android/keyguard/FontInterpolator$InterpKey;", "Landroid/graphics/fonts/Font;", "tmpInterpKey", "tmpVarFontKey", "Lcom/android/keyguard/FontInterpolator$VarFontKey;", "verFontCache", "adjustItalic", "", "value", "adjustWeight", "coerceInWithStep", "v", "min", "max", "step", "lerp", "start", "end", "progress", "", "Landroid/graphics/fonts/FontVariationAxis;", "", "filter", "Lkotlin/Function3;", "", "Lkotlin/ParameterName;", "name", "tag", "left", "right", "([Landroid/graphics/fonts/FontVariationAxis;[Landroid/graphics/fonts/FontVariationAxis;Lkotlin/jvm/functions/Function3;)Ljava/util/List;", "Companion", "InterpKey", "VarFontKey"})
public final class FontInterpolator {
    private final java.util.HashMap<com.android.keyguard.FontInterpolator.InterpKey, android.graphics.fonts.Font> interpCache = null;
    private final java.util.HashMap<com.android.keyguard.FontInterpolator.VarFontKey, android.graphics.fonts.Font> verFontCache = null;
    private final com.android.keyguard.FontInterpolator.InterpKey tmpInterpKey = null;
    private final com.android.keyguard.FontInterpolator.VarFontKey tmpVarFontKey = null;
    private static final android.graphics.fonts.FontVariationAxis[] EMPTY_AXES = {};
    @org.jetbrains.annotations.NotNull()
    public static final com.android.keyguard.FontInterpolator.Companion Companion = null;
    
    /**
     * Linear interpolate the font variation settings.
     */
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.fonts.Font lerp(@org.jetbrains.annotations.NotNull()
    android.graphics.fonts.Font start, @org.jetbrains.annotations.NotNull()
    android.graphics.fonts.Font end, float progress) {
        return null;
    }
    
    private final java.util.List<android.graphics.fonts.FontVariationAxis> lerp(android.graphics.fonts.FontVariationAxis[] start, android.graphics.fonts.FontVariationAxis[] end, kotlin.jvm.functions.Function3<? super java.lang.String, ? super java.lang.Float, ? super java.lang.Float, java.lang.Float> filter) {
        return null;
    }
    
    private final float adjustWeight(float value) {
        return 0.0F;
    }
    
    private final float adjustItalic(float value) {
        return 0.0F;
    }
    
    private final float coerceInWithStep(float v, float min, float max, float step) {
        return 0.0F;
    }
    
    public FontInterpolator() {
        super();
    }
    
    /**
     * Cache key for the interpolated font.
     *
     * This class is mutable for recycling.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0010\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B!\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u000b\u0010\u0012\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\u000b\u0010\u0013\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\t\u0010\u0014\u001a\u00020\u0006H\u00c6\u0003J+\u0010\u0015\u001a\u00020\u00002\n\b\u0002\u0010\u0002\u001a\u0004\u0018\u00010\u00032\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u0006H\u00c6\u0001J\u0013\u0010\u0016\u001a\u00020\u00172\b\u0010\u0018\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0019\u001a\u00020\u001aH\u00d6\u0001J\u001e\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00032\u0006\u0010\u0005\u001a\u00020\u0006J\t\u0010\u001d\u001a\u00020\u001eH\u00d6\u0001R\u001c\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\b\u0010\t\"\u0004\b\n\u0010\u000bR\u001a\u0010\u0005\u001a\u00020\u0006X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\f\u0010\r\"\u0004\b\u000e\u0010\u000fR\u001c\u0010\u0004\u001a\u0004\u0018\u00010\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0010\u0010\t\"\u0004\b\u0011\u0010\u000b"}, d2 = {"Lcom/android/keyguard/FontInterpolator$InterpKey;", "", "l", "Landroid/graphics/fonts/Font;", "r", "progress", "", "(Landroid/graphics/fonts/Font;Landroid/graphics/fonts/Font;F)V", "getL", "()Landroid/graphics/fonts/Font;", "setL", "(Landroid/graphics/fonts/Font;)V", "getProgress", "()F", "setProgress", "(F)V", "getR", "setR", "component1", "component2", "component3", "copy", "equals", "", "other", "hashCode", "", "set", "", "toString", ""})
    static final class InterpKey {
        @org.jetbrains.annotations.Nullable()
        private android.graphics.fonts.Font l;
        @org.jetbrains.annotations.Nullable()
        private android.graphics.fonts.Font r;
        private float progress;
        
        public final void set(@org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font l, @org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font r, float progress) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final android.graphics.fonts.Font getL() {
            return null;
        }
        
        public final void setL(@org.jetbrains.annotations.Nullable()
        android.graphics.fonts.Font p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final android.graphics.fonts.Font getR() {
            return null;
        }
        
        public final void setR(@org.jetbrains.annotations.Nullable()
        android.graphics.fonts.Font p0) {
        }
        
        public final float getProgress() {
            return 0.0F;
        }
        
        public final void setProgress(float p0) {
        }
        
        public InterpKey(@org.jetbrains.annotations.Nullable()
        android.graphics.fonts.Font l, @org.jetbrains.annotations.Nullable()
        android.graphics.fonts.Font r, float progress) {
            super();
        }
        
        @org.jetbrains.annotations.Nullable()
        public final android.graphics.fonts.Font component1() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final android.graphics.fonts.Font component2() {
            return null;
        }
        
        public final float component3() {
            return 0.0F;
        }
        
        /**
         * Cache key for the interpolated font.
         *
         * This class is mutable for recycling.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.keyguard.FontInterpolator.InterpKey copy(@org.jetbrains.annotations.Nullable()
        android.graphics.fonts.Font l, @org.jetbrains.annotations.Nullable()
        android.graphics.fonts.Font r, float progress) {
            return null;
        }
        
        /**
         * Cache key for the interpolated font.
         *
         * This class is mutable for recycling.
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * Cache key for the interpolated font.
         *
         * This class is mutable for recycling.
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * Cache key for the interpolated font.
         *
         * This class is mutable for recycling.
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     * Cache key for the font that has variable font.
     *
     * This class is mutable for recycling.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\b\u000e\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B\u001d\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u00a2\u0006\u0002\u0010\u0007B#\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\t\u0012\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\u00060\f\u00a2\u0006\u0002\u0010\rJ\t\u0010\u0016\u001a\u00020\tH\u00c6\u0003J\t\u0010\u0017\u001a\u00020\tH\u00c6\u0003J\u000f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u00060\fH\u00c6\u0003J-\u0010\u0019\u001a\u00020\u00002\b\b\u0002\u0010\b\u001a\u00020\t2\b\b\u0002\u0010\n\u001a\u00020\t2\u000e\b\u0002\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\u00060\fH\u00c6\u0001J\u0013\u0010\u001a\u001a\u00020\u001b2\b\u0010\u001c\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001d\u001a\u00020\tH\u00d6\u0001J\u001c\u0010\u001e\u001a\u00020\u001f2\u0006\u0010\u0002\u001a\u00020\u00032\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005J\t\u0010 \u001a\u00020!H\u00d6\u0001R\u001a\u0010\n\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000e\u0010\u000f\"\u0004\b\u0010\u0010\u0011R\u0017\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\u00060\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u001a\u0010\b\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0014\u0010\u000f\"\u0004\b\u0015\u0010\u0011"}, d2 = {"Lcom/android/keyguard/FontInterpolator$VarFontKey;", "", "font", "Landroid/graphics/fonts/Font;", "axes", "", "Landroid/graphics/fonts/FontVariationAxis;", "(Landroid/graphics/fonts/Font;Ljava/util/List;)V", "sourceId", "", "index", "sortedAxes", "", "(IILjava/util/List;)V", "getIndex", "()I", "setIndex", "(I)V", "getSortedAxes", "()Ljava/util/List;", "getSourceId", "setSourceId", "component1", "component2", "component3", "copy", "equals", "", "other", "hashCode", "set", "", "toString", ""})
    static final class VarFontKey {
        private int sourceId;
        private int index;
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<android.graphics.fonts.FontVariationAxis> sortedAxes = null;
        
        public final void set(@org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font font, @org.jetbrains.annotations.NotNull()
        java.util.List<android.graphics.fonts.FontVariationAxis> axes) {
        }
        
        public final int getSourceId() {
            return 0;
        }
        
        public final void setSourceId(int p0) {
        }
        
        public final int getIndex() {
            return 0;
        }
        
        public final void setIndex(int p0) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<android.graphics.fonts.FontVariationAxis> getSortedAxes() {
            return null;
        }
        
        public VarFontKey(int sourceId, int index, @org.jetbrains.annotations.NotNull()
        java.util.List<android.graphics.fonts.FontVariationAxis> sortedAxes) {
            super();
        }
        
        public VarFontKey(@org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font font, @org.jetbrains.annotations.NotNull()
        java.util.List<android.graphics.fonts.FontVariationAxis> axes) {
            super();
        }
        
        public final int component1() {
            return 0;
        }
        
        public final int component2() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<android.graphics.fonts.FontVariationAxis> component3() {
            return null;
        }
        
        /**
         * Cache key for the font that has variable font.
         *
         * This class is mutable for recycling.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.keyguard.FontInterpolator.VarFontKey copy(int sourceId, int index, @org.jetbrains.annotations.NotNull()
        java.util.List<android.graphics.fonts.FontVariationAxis> sortedAxes) {
            return null;
        }
        
        /**
         * Cache key for the font that has variable font.
         *
         * This class is mutable for recycling.
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * Cache key for the font that has variable font.
         *
         * This class is mutable for recycling.
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * Cache key for the font that has variable font.
         *
         * This class is mutable for recycling.
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0016\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\nR\u0016\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0006"}, d2 = {"Lcom/android/keyguard/FontInterpolator$Companion;", "", "()V", "EMPTY_AXES", "", "Landroid/graphics/fonts/FontVariationAxis;", "[Landroid/graphics/fonts/FontVariationAxis;", "canInterpolate", "", "start", "Landroid/graphics/fonts/Font;", "end"})
    public static final class Companion {
        
        public final boolean canInterpolate(@org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font start, @org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font end) {
            return false;
        }
        
        private Companion() {
            super();
        }
    }
}
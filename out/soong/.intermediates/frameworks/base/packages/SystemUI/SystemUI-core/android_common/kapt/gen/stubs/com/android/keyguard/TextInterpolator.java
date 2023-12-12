package com.android.keyguard;

import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.fonts.Font;
import android.graphics.text.PositionedGlyphs;
import android.text.Layout;
import android.text.TextPaint;
import android.text.TextShaper;
import android.util.MathUtils;
import com.android.internal.graphics.ColorUtils;

/**
 * Provide text style linear interpolation for plain text.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000l\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0002\b\b\n\u0002\u0010\u0014\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0003\u0018\u00002\u00020\u0001:\u0003678B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020 J(\u0010!\u001a\u00020\u001e2\u0006\u0010\"\u001a\u00020 2\u0006\u0010#\u001a\u00020$2\u0006\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020(H\u0002J(\u0010)\u001a\u00020\u001e2\u0006\u0010*\u001a\u00020(2\u0006\u0010+\u001a\u00020(2\u0006\u0010\u0012\u001a\u00020\u00132\u0006\u0010,\u001a\u00020(H\u0002J\u0006\u0010-\u001a\u00020\u001eJ\u0006\u0010.\u001a\u00020\u001eJ\u0006\u0010/\u001a\u00020\u001eJ\u0010\u00100\u001a\u00020\u001e2\u0006\u0010\u0002\u001a\u00020\u0003H\u0002J$\u00100\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u0002010\u00100\u00102\u0006\u0010\u0002\u001a\u00020\u00032\u0006\u0010\'\u001a\u00020\u0006H\u0002J$\u00102\u001a\u00020\u001e2\u0012\u00103\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u0002010\u00100\u00102\u0006\u00104\u001a\u000205H\u0002R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R&\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u000b\u001a\u00020\u00038F@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\f\u0010\r\"\u0004\b\u000e\u0010\u0004R\u0014\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0012\u001a\u00020\u0013X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0014\u0010\u0015\"\u0004\b\u0016\u0010\u0017R\u0011\u0010\u0018\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\bR\u000e\u0010\u001a\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u001cX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/keyguard/TextInterpolator;", "", "layout", "Landroid/text/Layout;", "(Landroid/text/Layout;)V", "basePaint", "Landroid/text/TextPaint;", "getBasePaint", "()Landroid/text/TextPaint;", "fontInterpolator", "Lcom/android/keyguard/FontInterpolator;", "value", "getLayout", "()Landroid/text/Layout;", "setLayout", "lines", "", "Lcom/android/keyguard/TextInterpolator$Line;", "progress", "", "getProgress", "()F", "setProgress", "(F)V", "targetPaint", "getTargetPaint", "tmpDrawPaint", "tmpPositionArray", "", "draw", "", "canvas", "Landroid/graphics/Canvas;", "drawFontRun", "c", "line", "Lcom/android/keyguard/TextInterpolator$Run;", "run", "Lcom/android/keyguard/TextInterpolator$FontRun;", "paint", "Landroid/graphics/Paint;", "lerp", "from", "to", "out", "onBasePaintModified", "onTargetPaintModified", "rebase", "shapeText", "Landroid/graphics/text/PositionedGlyphs;", "updatePositionsAndFonts", "layoutResult", "updateBase", "", "FontRun", "Line", "Run"})
public final class TextInterpolator {
    
    /**
     * Returns base paint used for interpolation.
     *
     * Once you modified the style parameters, you have to call reshapeText to recalculate base text
     * layout.
     *
     * @return a paint object
     */
    @org.jetbrains.annotations.NotNull()
    private final android.text.TextPaint basePaint = null;
    
    /**
     * Returns target paint used for interpolation.
     *
     * Once you modified the style parameters, you have to call reshapeText to recalculate target
     * text layout.
     *
     * @return a paint object
     */
    @org.jetbrains.annotations.NotNull()
    private final android.text.TextPaint targetPaint = null;
    private java.util.List<com.android.keyguard.TextInterpolator.Line> lines;
    private final com.android.keyguard.FontInterpolator fontInterpolator = null;
    private final android.text.TextPaint tmpDrawPaint = null;
    private float[] tmpPositionArray;
    
    /**
     * The progress position of the interpolation.
     *
     * The 0f means the start state, 1f means the end state.
     */
    private float progress = 0.0F;
    
    /**
     * The layout used for drawing text.
     *
     * Only non-styled text is supported. Even if the given layout is created from Spanned, the
     * span information is not used.
     *
     * The paint objects used for interpolation are not changed by this method call.
     *
     * Note: disabling ligature is strongly recommended if you give extra letter spacing since they
     * may be disjointed based on letter spacing value and cannot be interpolated. Animator will
     * throw runtime exception if they cannot be interpolated.
     */
    @org.jetbrains.annotations.NotNull()
    private android.text.Layout layout;
    
    @org.jetbrains.annotations.NotNull()
    public final android.text.TextPaint getBasePaint() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.text.TextPaint getTargetPaint() {
        return null;
    }
    
    public final float getProgress() {
        return 0.0F;
    }
    
    public final void setProgress(float p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.text.Layout getLayout() {
        return null;
    }
    
    public final void setLayout(@org.jetbrains.annotations.NotNull()
    android.text.Layout value) {
    }
    
    /**
     * Recalculate internal text layout for interpolation.
     *
     * Whenever the target paint is modified, call this method to recalculate internal
     * text layout used for interpolation.
     */
    public final void onTargetPaintModified() {
    }
    
    /**
     * Recalculate internal text layout for interpolation.
     *
     * Whenever the base paint is modified, call this method to recalculate internal
     * text layout used for interpolation.
     */
    public final void onBasePaintModified() {
    }
    
    /**
     * Rebase the base state to the middle of the interpolation.
     *
     * The text interpolator does not calculate all the text position by text shaper due to
     * performance reasons. Instead, the text interpolator shape the start and end state and
     * calculate text position of the middle state by linear interpolation. Due to this trick,
     * the text positions of the middle state is likely different from the text shaper result.
     * So, if you want to start animation from the middle state, you will see the glyph jumps due to
     * this trick, i.e. the progress 0.5 of interpolation between weight 400 and 700 is different
     * from text shape result of weight 550.
     *
     * After calling this method, do not call onBasePaintModified() since it reshape the text and
     * update the base state. As in above notice, the text shaping result at current progress is
     * different shaped result. By calling onBasePaintModified(), you may see the glyph jump.
     *
     * By calling this method, the progress will be reset to 0.
     *
     * This API is useful to continue animation from the middle of the state. For example, if you
     * animate weight from 200 to 400, then if you want to move back to 200 at the half of the
     * animation, it will look like
     *
     * <pre>
     * <code>
     *    val interp = TextInterpolator(layout)
     *
     *    // Interpolate between weight 200 to 400.
     *    interp.basePaint.fontVariationSettings = "'wght' 200"
     *    interp.onBasePaintModified()
     *    interp.targetPaint.fontVariationSettings = "'wght' 400"
     *    interp.onTargetPaintModified()
     *
     *    // animate
     *    val animator = ValueAnimator.ofFloat(1f).apply {
     *        addUpdaterListener {
     *            interp.progress = it.animateValue as Float
     *        }
     *    }.start()
     *
     *    // Here, assuming you receive some event and want to start new animation from current
     *    // state.
     *    OnSomeEvent {
     *        animator.cancel()
     *
     *        // start another animation from the current state.
     *        interp.rebase() // Use current state as base state.
     *        interp.targetPaint.fontVariationSettings = "'wght' 200" // set new target
     *        interp.onTargetPaintModified() // reshape target
     *
     *        // Here the textInterpolator interpolate from 'wght' from 300 to 200 if the current
     *        // progress is 0.5
     *        animator.start()
     *    }
     * </code>
     * </pre>
     */
    public final void rebase() {
    }
    
    /**
     * Draws interpolated text at the given progress.
     *
     * @param canvas a canvas.
     */
    public final void draw(@org.jetbrains.annotations.NotNull()
    android.graphics.Canvas canvas) {
    }
    
    private final void shapeText(android.text.Layout layout) {
    }
    
    private final void drawFontRun(android.graphics.Canvas c, com.android.keyguard.TextInterpolator.Run line, com.android.keyguard.TextInterpolator.FontRun run, android.graphics.Paint paint) {
    }
    
    private final void updatePositionsAndFonts(java.util.List<? extends java.util.List<android.graphics.text.PositionedGlyphs>> layoutResult, boolean updateBase) {
    }
    
    private final void lerp(android.graphics.Paint from, android.graphics.Paint to, float progress, android.graphics.Paint out) {
    }
    
    private final java.util.List<java.util.List<android.graphics.text.PositionedGlyphs>> shapeText(android.text.Layout layout, android.text.TextPaint paint) {
        return null;
    }
    
    public TextInterpolator(@org.jetbrains.annotations.NotNull()
    android.text.Layout layout) {
        super();
    }
    
    /**
     * A class represents a single font run.
     *
     * A font run is a range that will be drawn with the same font.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0013\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\bJ\t\u0010\u0014\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0015\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0016\u001a\u00020\u0006H\u00c6\u0003J\t\u0010\u0017\u001a\u00020\u0006H\u00c6\u0003J1\u0010\u0018\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u00062\b\b\u0002\u0010\u0007\u001a\u00020\u0006H\u00c6\u0001J\u0013\u0010\u0019\u001a\u00020\u001a2\b\u0010\u001b\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001c\u001a\u00020\u0003H\u00d6\u0001J\t\u0010\u001d\u001a\u00020\u001eH\u00d6\u0001R\u001a\u0010\u0005\u001a\u00020\u0006X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\n\"\u0004\b\u000b\u0010\fR\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u000f\u001a\u00020\u00038F\u00a2\u0006\u0006\u001a\u0004\b\u0010\u0010\u000eR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u000eR\u001a\u0010\u0007\u001a\u00020\u0006X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\n\"\u0004\b\u0013\u0010\f"}, d2 = {"Lcom/android/keyguard/TextInterpolator$FontRun;", "", "start", "", "end", "baseFont", "Landroid/graphics/fonts/Font;", "targetFont", "(IILandroid/graphics/fonts/Font;Landroid/graphics/fonts/Font;)V", "getBaseFont", "()Landroid/graphics/fonts/Font;", "setBaseFont", "(Landroid/graphics/fonts/Font;)V", "getEnd", "()I", "length", "getLength", "getStart", "getTargetFont", "setTargetFont", "component1", "component2", "component3", "component4", "copy", "equals", "", "other", "hashCode", "toString", ""})
    static final class FontRun {
        private final int start = 0;
        private final int end = 0;
        @org.jetbrains.annotations.NotNull()
        private android.graphics.fonts.Font baseFont;
        @org.jetbrains.annotations.NotNull()
        private android.graphics.fonts.Font targetFont;
        
        public final int getLength() {
            return 0;
        }
        
        public final int getStart() {
            return 0;
        }
        
        public final int getEnd() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.graphics.fonts.Font getBaseFont() {
            return null;
        }
        
        public final void setBaseFont(@org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font p0) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.graphics.fonts.Font getTargetFont() {
            return null;
        }
        
        public final void setTargetFont(@org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font p0) {
        }
        
        public FontRun(int start, int end, @org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font baseFont, @org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font targetFont) {
            super();
        }
        
        public final int component1() {
            return 0;
        }
        
        public final int component2() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.graphics.fonts.Font component3() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.graphics.fonts.Font component4() {
            return null;
        }
        
        /**
         * A class represents a single font run.
         *
         * A font run is a range that will be drawn with the same font.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.keyguard.TextInterpolator.FontRun copy(int start, int end, @org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font baseFont, @org.jetbrains.annotations.NotNull()
        android.graphics.fonts.Font targetFont) {
            return null;
        }
        
        /**
         * A class represents a single font run.
         *
         * A font run is a range that will be drawn with the same font.
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * A class represents a single font run.
         *
         * A font run is a range that will be drawn with the same font.
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * A class represents a single font run.
         *
         * A font run is a range that will be drawn with the same font.
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     * A class represents text layout of a single run.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0015\n\u0000\n\u0002\u0010\u0014\n\u0002\b\u0004\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\n\b\u0002\u0018\u00002\u00020\u0001B;\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\u0005\u0012\u0006\u0010\b\u001a\u00020\u0005\u0012\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u000b0\n\u00a2\u0006\u0002\u0010\fR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u000eR\u0017\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u000b0\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u0011\u0010\u0007\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u000eR\u0011\u0010\b\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u000e"}, d2 = {"Lcom/android/keyguard/TextInterpolator$Run;", "", "glyphIds", "", "baseX", "", "baseY", "targetX", "targetY", "fontRuns", "", "Lcom/android/keyguard/TextInterpolator$FontRun;", "([I[F[F[F[FLjava/util/List;)V", "getBaseX", "()[F", "getBaseY", "getFontRuns", "()Ljava/util/List;", "getGlyphIds", "()[I", "getTargetX", "getTargetY"})
    static final class Run {
        @org.jetbrains.annotations.NotNull()
        private final int[] glyphIds = null;
        @org.jetbrains.annotations.NotNull()
        private final float[] baseX = null;
        @org.jetbrains.annotations.NotNull()
        private final float[] baseY = null;
        @org.jetbrains.annotations.NotNull()
        private final float[] targetX = null;
        @org.jetbrains.annotations.NotNull()
        private final float[] targetY = null;
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<com.android.keyguard.TextInterpolator.FontRun> fontRuns = null;
        
        @org.jetbrains.annotations.NotNull()
        public final int[] getGlyphIds() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final float[] getBaseX() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final float[] getBaseY() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final float[] getTargetX() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final float[] getTargetY() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.keyguard.TextInterpolator.FontRun> getFontRuns() {
            return null;
        }
        
        public Run(@org.jetbrains.annotations.NotNull()
        int[] glyphIds, @org.jetbrains.annotations.NotNull()
        float[] baseX, @org.jetbrains.annotations.NotNull()
        float[] baseY, @org.jetbrains.annotations.NotNull()
        float[] targetX, @org.jetbrains.annotations.NotNull()
        float[] targetY, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.keyguard.TextInterpolator.FontRun> fontRuns) {
            super();
        }
    }
    
    /**
     * A class represents text layout of a single line.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0002\u0018\u00002\u00020\u0001B\u0013\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\u0002\u0010\u0005R\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"Lcom/android/keyguard/TextInterpolator$Line;", "", "runs", "", "Lcom/android/keyguard/TextInterpolator$Run;", "(Ljava/util/List;)V", "getRuns", "()Ljava/util/List;"})
    static final class Line {
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<com.android.keyguard.TextInterpolator.Run> runs = null;
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.keyguard.TextInterpolator.Run> getRuns() {
            return null;
        }
        
        public Line(@org.jetbrains.annotations.NotNull()
        java.util.List<com.android.keyguard.TextInterpolator.Run> runs) {
            super();
        }
    }
}
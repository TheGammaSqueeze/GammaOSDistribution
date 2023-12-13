package com.android.keyguard;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.TimeInterpolator;
import android.animation.ValueAnimator;
import android.graphics.Canvas;
import android.graphics.Typeface;
import android.text.Layout;
import android.util.SparseArray;

/**
 * This class provides text animation between two styles.
 *
 * Currently this class can provide text style animation for text weight and text size. For example
 * the simple view that draws text with animating text size is like as follows:
 *
 * <pre>
 * <code>
 *    class SimpleTextAnimation : View {
 *        @JvmOverloads constructor(...)
 *
 *        private val layout: Layout = ... // Text layout, e.g. StaticLayout.
 *
 *        // TextAnimator tells us when needs to be invalidate.
 *        private val animator = TextAnimator(layout) { invalidate() }
 *
 *        override fun onDraw(canvas: Canvas) = animator.draw(canvas)
 *
 *        // Change the text size with animation.
 *        fun setTextSize(sizePx: Float, animate: Boolean) {
 *            animator.setTextStyle(-1 / * unchanged weight * /, sizePx, animate)
 *        }
 *    }
 * </code>
 * </pre>
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000j\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0003\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u001b\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u00a2\u0006\u0002\u0010\u0007J\u000e\u0010\u0017\u001a\u00020\u00062\u0006\u0010\u0018\u001a\u00020\u0019J\u0006\u0010\u001a\u001a\u00020\u001bJa\u0010\u001c\u001a\u00020\u00062\b\b\u0002\u0010\u001d\u001a\u00020\u001e2\b\b\u0002\u0010\u001f\u001a\u00020 2\n\b\u0002\u0010!\u001a\u0004\u0018\u00010\u001e2\b\b\u0002\u0010\"\u001a\u00020\u001b2\b\b\u0002\u0010#\u001a\u00020$2\n\b\u0002\u0010%\u001a\u0004\u0018\u00010&2\b\b\u0002\u0010\'\u001a\u00020$2\n\b\u0002\u0010(\u001a\u0004\u0018\u00010)\u00a2\u0006\u0002\u0010*J\u000e\u0010+\u001a\u00020\u00062\u0006\u0010\u0002\u001a\u00020\u0003R\u001a\u0010\b\u001a\u00020\tX\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u0014\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000e\u001a\u00020\u000fX\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0010\u0010\u0011\"\u0004\b\u0012\u0010\u0013R\u0016\u0010\u0014\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010\u00160\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/keyguard/TextAnimator;", "", "layout", "Landroid/text/Layout;", "invalidateCallback", "Lkotlin/Function0;", "", "(Landroid/text/Layout;Lkotlin/jvm/functions/Function0;)V", "animator", "Landroid/animation/ValueAnimator;", "getAnimator$main", "()Landroid/animation/ValueAnimator;", "setAnimator$main", "(Landroid/animation/ValueAnimator;)V", "textInterpolator", "Lcom/android/keyguard/TextInterpolator;", "getTextInterpolator$main", "()Lcom/android/keyguard/TextInterpolator;", "setTextInterpolator$main", "(Lcom/android/keyguard/TextInterpolator;)V", "typefaceCache", "Landroid/util/SparseArray;", "Landroid/graphics/Typeface;", "draw", "c", "Landroid/graphics/Canvas;", "isRunning", "", "setTextStyle", "weight", "", "textSize", "", "color", "animate", "duration", "", "interpolator", "Landroid/animation/TimeInterpolator;", "delay", "onAnimationEnd", "Ljava/lang/Runnable;", "(IFLjava/lang/Integer;ZJLandroid/animation/TimeInterpolator;JLjava/lang/Runnable;)V", "updateLayout"})
public final class TextAnimator {
    @org.jetbrains.annotations.NotNull()
    private com.android.keyguard.TextInterpolator textInterpolator;
    @org.jetbrains.annotations.NotNull()
    private android.animation.ValueAnimator animator;
    private final android.util.SparseArray<android.graphics.Typeface> typefaceCache = null;
    private final kotlin.jvm.functions.Function0<kotlin.Unit> invalidateCallback = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.keyguard.TextInterpolator getTextInterpolator$main() {
        return null;
    }
    
    public final void setTextInterpolator$main(@org.jetbrains.annotations.NotNull()
    com.android.keyguard.TextInterpolator p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.animation.ValueAnimator getAnimator$main() {
        return null;
    }
    
    public final void setAnimator$main(@org.jetbrains.annotations.NotNull()
    android.animation.ValueAnimator p0) {
    }
    
    public final void updateLayout(@org.jetbrains.annotations.NotNull()
    android.text.Layout layout) {
    }
    
    public final boolean isRunning() {
        return false;
    }
    
    public final void draw(@org.jetbrains.annotations.NotNull()
    android.graphics.Canvas c) {
    }
    
    /**
     * Set text style with animation.
     *
     * By passing -1 to weight, the view preserve the current weight.
     * By passing -1 to textSize, the view preserve the current text size.
     * Bu passing -1 to duration, the default text animation, 1000ms, is used.
     * By passing false to animate, the text will be updated without animation.
     *
     * @param weight an optional text weight.
     * @param textSize an optional font size.
     * @param colors an optional colors array that must be the same size as numLines passed to
     * the TextInterpolator
     * @param animate an optional boolean indicating true for showing style transition as animation,
     *               false for immediate style transition. True by default.
     * @param duration an optional animation duration in milliseconds. This is ignored if animate is
     *                false.
     * @param interpolator an optional time interpolator. If null is passed, last set interpolator
     *                    will be used. This is ignored if animate is false.
     */
    public final void setTextStyle(int weight, float textSize, @org.jetbrains.annotations.Nullable()
    java.lang.Integer color, boolean animate, long duration, @org.jetbrains.annotations.Nullable()
    android.animation.TimeInterpolator interpolator, long delay, @org.jetbrains.annotations.Nullable()
    java.lang.Runnable onAnimationEnd) {
    }
    
    public TextAnimator(@org.jetbrains.annotations.NotNull()
    android.text.Layout layout, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> invalidateCallback) {
        super();
    }
}
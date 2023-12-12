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
 * Scrim view that partially reveals the content underneath it using a [RadialGradient] with a
 * transparent center. The center position, size, and stops of the gradient can be manipulated to
 * reveal views below the scrim as if they are being 'lit up'.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000d\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\b\n\u0002\b\u000f\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\r\u0018\u00002\u00020\u0001B\u0019\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\u0012\u0010:\u001a\u00020;2\b\u0010<\u001a\u0004\u0018\u00010=H\u0014J\u0010\u0010>\u001a\u00020;2\u0006\u0010?\u001a\u00020\u0014H\u0016J\b\u0010@\u001a\u00020;H\u0002J&\u0010A\u001a\u00020;2\u0006\u0010B\u001a\u00020\u00142\u0006\u0010C\u001a\u00020\u00142\u0006\u0010D\u001a\u00020\u00142\u0006\u0010E\u001a\u00020\u0014J\u0010\u0010F\u001a\u00020;2\u0006\u0010G\u001a\u00020&H\u0016J\u0018\u0010H\u001a\u00020&2\u0006\u0010I\u001a\u00020&2\u0006\u0010?\u001a\u00020\u0014H\u0002J\b\u0010J\u001a\u00020;H\u0002R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\u000b\u001a\u00020\n2\u0006\u0010\t\u001a\u00020\n@BX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR \u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\n0\u0010X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000f\u0010\u0011\"\u0004\b\u0012\u0010\u0013R$\u0010\u0015\u001a\u00020\u00142\u0006\u0010\t\u001a\u00020\u0014@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0016\u0010\u0017\"\u0004\b\u0018\u0010\u0019R$\u0010\u001b\u001a\u00020\u001a2\u0006\u0010\t\u001a\u00020\u001a@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001c\u0010\u001d\"\u0004\b\u001e\u0010\u001fR\u001a\u0010 \u001a\u00020!X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\"\u0010#\"\u0004\b$\u0010%R$\u0010\'\u001a\u00020&2\u0006\u0010\t\u001a\u00020&@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b(\u0010)\"\u0004\b*\u0010+R$\u0010,\u001a\u00020\u00142\u0006\u0010\t\u001a\u00020\u0014@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b-\u0010\u0017\"\u0004\b.\u0010\u0019R\u001a\u0010/\u001a\u00020\u0014X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b0\u0010\u0017\"\u0004\b1\u0010\u0019R\u001a\u00102\u001a\u00020\u0014X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b3\u0010\u0017\"\u0004\b4\u0010\u0019R\u000e\u00105\u001a\u000206X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u00107\u001a\u00020\u00142\u0006\u0010\t\u001a\u00020\u0014@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b8\u0010\u0017\"\u0004\b9\u0010\u0019"}, d2 = {"Lcom/android/systemui/statusbar/LightRevealScrim;", "Landroid/view/View;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "gradientPaint", "Landroid/graphics/Paint;", "value", "", "isScrimOpaque", "()Z", "setScrimOpaque", "(Z)V", "isScrimOpaqueChangedListener", "Ljava/util/function/Consumer;", "()Ljava/util/function/Consumer;", "setScrimOpaqueChangedListener", "(Ljava/util/function/Consumer;)V", "", "revealAmount", "getRevealAmount", "()F", "setRevealAmount", "(F)V", "Lcom/android/systemui/statusbar/LightRevealEffect;", "revealEffect", "getRevealEffect", "()Lcom/android/systemui/statusbar/LightRevealEffect;", "setRevealEffect", "(Lcom/android/systemui/statusbar/LightRevealEffect;)V", "revealGradientCenter", "Landroid/graphics/PointF;", "getRevealGradientCenter", "()Landroid/graphics/PointF;", "setRevealGradientCenter", "(Landroid/graphics/PointF;)V", "", "revealGradientEndColor", "getRevealGradientEndColor", "()I", "setRevealGradientEndColor", "(I)V", "revealGradientEndColorAlpha", "getRevealGradientEndColorAlpha", "setRevealGradientEndColorAlpha", "revealGradientHeight", "getRevealGradientHeight", "setRevealGradientHeight", "revealGradientWidth", "getRevealGradientWidth", "setRevealGradientWidth", "shaderGradientMatrix", "Landroid/graphics/Matrix;", "startColorAlpha", "getStartColorAlpha", "setStartColorAlpha", "onDraw", "", "canvas", "Landroid/graphics/Canvas;", "setAlpha", "alpha", "setPaintColorFilter", "setRevealGradientBounds", "left", "top", "right", "bottom", "setVisibility", "visibility", "updateColorAlpha", "color", "updateScrimOpaque"})
public final class LightRevealScrim extends android.view.View {
    
    /**
     * Listener that is called if the scrim's opaqueness changes
     */
    public java.util.function.Consumer<java.lang.Boolean> isScrimOpaqueChangedListener;
    
    /**
     * How much of the underlying views are revealed, in percent. 0 means they will be completely
     * obscured and 1 means they'll be fully visible.
     */
    private float revealAmount = 1.0F;
    
    /**
     * The [LightRevealEffect] used to manipulate the radial gradient whenever [revealAmount]
     * changes.
     */
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.statusbar.LightRevealEffect revealEffect;
    @org.jetbrains.annotations.NotNull()
    private android.graphics.PointF revealGradientCenter;
    private float revealGradientWidth = 0.0F;
    private float revealGradientHeight = 0.0F;
    
    /**
     * Alpha of the fill that can be used in the beginning of the animation to hide the content.
     * Normally the gradient bounds are animated from small size so the content is not visible,
     * but if the start gradient bounds allow to see some content this could be used to make the
     * reveal smoother. It can help to add fade in effect in the beginning of the animation.
     * The color of the fill is determined by [revealGradientEndColor].
     *
     * 0 - no fill and content is visible, 1 - the content is covered with the start color
     */
    private float startColorAlpha = 0.0F;
    private int revealGradientEndColor = android.graphics.Color.BLACK;
    private float revealGradientEndColorAlpha = 0.0F;
    
    /**
     * Is the scrim currently fully opaque
     */
    private boolean isScrimOpaque = false;
    
    /**
     * Paint used to draw a transparent-to-white radial gradient. This will be scaled and translated
     * via local matrix in [onDraw] so we never need to construct a new shader.
     */
    private final android.graphics.Paint gradientPaint = null;
    
    /**
     * Matrix applied to [gradientPaint]'s RadialGradient shader to move the gradient to
     * [revealGradientCenter] and set its size to [revealGradientWidth]/[revealGradientHeight],
     * without needing to construct a new shader each time those properties change.
     */
    private final android.graphics.Matrix shaderGradientMatrix = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.function.Consumer<java.lang.Boolean> isScrimOpaqueChangedListener() {
        return null;
    }
    
    public final void setScrimOpaqueChangedListener(@org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<java.lang.Boolean> p0) {
    }
    
    public final float getRevealAmount() {
        return 0.0F;
    }
    
    public final void setRevealAmount(float value) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.LightRevealEffect getRevealEffect() {
        return null;
    }
    
    public final void setRevealEffect(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.LightRevealEffect value) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.PointF getRevealGradientCenter() {
        return null;
    }
    
    public final void setRevealGradientCenter(@org.jetbrains.annotations.NotNull()
    android.graphics.PointF p0) {
    }
    
    public final float getRevealGradientWidth() {
        return 0.0F;
    }
    
    public final void setRevealGradientWidth(float p0) {
    }
    
    public final float getRevealGradientHeight() {
        return 0.0F;
    }
    
    public final void setRevealGradientHeight(float p0) {
    }
    
    public final float getStartColorAlpha() {
        return 0.0F;
    }
    
    public final void setStartColorAlpha(float value) {
    }
    
    public final int getRevealGradientEndColor() {
        return 0;
    }
    
    public final void setRevealGradientEndColor(int value) {
    }
    
    public final float getRevealGradientEndColorAlpha() {
        return 0.0F;
    }
    
    public final void setRevealGradientEndColorAlpha(float value) {
    }
    
    public final boolean isScrimOpaque() {
        return false;
    }
    
    private final void setScrimOpaque(boolean value) {
    }
    
    private final void updateScrimOpaque() {
    }
    
    @java.lang.Override()
    public void setAlpha(float alpha) {
    }
    
    @java.lang.Override()
    public void setVisibility(int visibility) {
    }
    
    /**
     * Sets bounds for the transparent oval gradient that reveals the views below the scrim. This is
     * simply a helper method that sets [revealGradientCenter], [revealGradientWidth], and
     * [revealGradientHeight] for you.
     *
     * This method does not call [invalidate] - you should do so once you're done changing
     * properties.
     */
    public final void setRevealGradientBounds(float left, float top, float right, float bottom) {
    }
    
    @java.lang.Override()
    protected void onDraw(@org.jetbrains.annotations.Nullable()
    android.graphics.Canvas canvas) {
    }
    
    private final void setPaintColorFilter() {
    }
    
    private final int updateColorAlpha(int color, float alpha) {
        return 0;
    }
    
    public LightRevealScrim(@org.jetbrains.annotations.Nullable()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
}
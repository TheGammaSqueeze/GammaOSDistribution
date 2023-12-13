package com.android.systemui.util.animation;

import android.animation.ValueAnimator;
import android.graphics.PointF;
import android.util.MathUtils;
import com.android.systemui.animation.Interpolators;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\u0012\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0006\u0010\u001b\u001a\u00020\u0000J\u0013\u0010\u001c\u001a\u00020\u001d2\b\u0010\u001e\u001a\u0004\u0018\u00010\u0001H\u0096\u0002J\b\u0010\u001f\u001a\u00020 H\u0016R\u001a\u0010\u0003\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\bR\u001a\u0010\t\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u001a\u0010\u000f\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0010\u0010\u0006\"\u0004\b\u0011\u0010\bR\u001a\u0010\u0012\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0013\u0010\f\"\u0004\b\u0014\u0010\u000eR\u001a\u0010\u0015\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0016\u0010\f\"\u0004\b\u0017\u0010\u000eR\u001a\u0010\u0018\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0019\u0010\u0006\"\u0004\b\u001a\u0010\b"}, d2 = {"Lcom/android/systemui/util/animation/DisappearParameters;", "", "()V", "contentTranslationFraction", "Landroid/graphics/PointF;", "getContentTranslationFraction", "()Landroid/graphics/PointF;", "setContentTranslationFraction", "(Landroid/graphics/PointF;)V", "disappearEnd", "", "getDisappearEnd", "()F", "setDisappearEnd", "(F)V", "disappearSize", "getDisappearSize", "setDisappearSize", "disappearStart", "getDisappearStart", "setDisappearStart", "fadeStartPosition", "getFadeStartPosition", "setFadeStartPosition", "gonePivot", "getGonePivot", "setGonePivot", "deepCopy", "equals", "", "other", "hashCode", ""})
public final class DisappearParameters {
    
    /**
     * The pivot point when clipping view when disappearing, which describes how the content will
     * be translated.
     * The default value of (0.0f, 1.0f) means that the view will not be translated in horizontally
     * and the vertical disappearing will be aligned on the bottom of the view,
     */
    @org.jetbrains.annotations.NotNull()
    private android.graphics.PointF gonePivot;
    
    /**
     * The fraction of the width and height that will remain when disappearing. The default of
     * (1.0f, 0.0f) means that 100% of the width, but 0% of the height will remain at the end of
     * the transition.
     */
    @org.jetbrains.annotations.NotNull()
    private android.graphics.PointF disappearSize;
    
    /**
     * The fraction of the normal translation, by which the content will be moved during the
     * disappearing. The values here can be both negative as well as positive. The default value
     * of (0.0f, 0.2f) means that the content doesn't move horizontally but moves 20% of the
     * translation imposed by the pivot downwards. 1.0f means that the content will be translated
     * in sync with the translation of the bounds
     */
    @org.jetbrains.annotations.NotNull()
    private android.graphics.PointF contentTranslationFraction;
    
    /**
     * The point during the progress from [0.0, 1.0f] where the view is fully appeared. 0.0f
     * means that the content will start disappearing immediately, while 0.5f means that it
     * starts disappearing half way through the progress.
     */
    private float disappearStart = 0.0F;
    
    /**
     * The point during the progress from [0.0, 1.0f] where the view has fully disappeared. 1.0f
     * means that the view will disappear in sync with the progress, while 0.5f means that it
     * is fully gone half way through the progress.
     */
    private float disappearEnd = 1.0F;
    
    /**
     * The point during the mapped progress from [0.0, 1.0f] where the view starts fading out. 1.0f
     * means that the view doesn't fade at all, while 0.5 means that the content fades starts
     * fading at the midpoint between [disappearStart] and [disappearEnd]
     */
    private float fadeStartPosition = 0.9F;
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.PointF getGonePivot() {
        return null;
    }
    
    public final void setGonePivot(@org.jetbrains.annotations.NotNull()
    android.graphics.PointF p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.PointF getDisappearSize() {
        return null;
    }
    
    public final void setDisappearSize(@org.jetbrains.annotations.NotNull()
    android.graphics.PointF p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.PointF getContentTranslationFraction() {
        return null;
    }
    
    public final void setContentTranslationFraction(@org.jetbrains.annotations.NotNull()
    android.graphics.PointF p0) {
    }
    
    public final float getDisappearStart() {
        return 0.0F;
    }
    
    public final void setDisappearStart(float p0) {
    }
    
    public final float getDisappearEnd() {
        return 0.0F;
    }
    
    public final void setDisappearEnd(float p0) {
    }
    
    public final float getFadeStartPosition() {
        return 0.0F;
    }
    
    public final void setFadeStartPosition(float p0) {
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object other) {
        return false;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.DisappearParameters deepCopy() {
        return null;
    }
    
    public DisappearParameters() {
        super();
    }
}
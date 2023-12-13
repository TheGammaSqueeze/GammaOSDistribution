package com.android.systemui.statusbar.notification;

import android.util.MathUtils;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.animation.LaunchAnimator;

/**
 * Parameters for the notifications expand animations.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0010\u0007\n\u0002\b!\n\u0002\u0010\t\n\u0000\u0018\u00002\u00020\u0001B\u0007\b\u0017\u00a2\u0006\u0002\u0010\u0002B9\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0004\u0012\u0006\u0010\u0006\u001a\u00020\u0004\u0012\u0006\u0010\u0007\u001a\u00020\u0004\u0012\b\b\u0002\u0010\b\u001a\u00020\t\u0012\b\b\u0002\u0010\n\u001a\u00020\t\u00a2\u0006\u0002\u0010\u000bJ\u0016\u0010\u001a\u001a\u00020\t2\u0006\u0010*\u001a\u00020+2\u0006\u0010,\u001a\u00020+R\u001a\u0010\f\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\r\u0010\u000e\"\u0004\b\u000f\u0010\u0010R\u001a\u0010\u0011\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u0013\"\u0004\b\u0014\u0010\u0015R\u001a\u0010\u0016\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0017\u0010\u0013\"\u0004\b\u0018\u0010\u0015R\u001a\u0010\u0019\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001a\u0010\u000e\"\u0004\b\u001b\u0010\u0010R\u001a\u0010\u001c\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001d\u0010\u0013\"\u0004\b\u001e\u0010\u0015R\u001a\u0010\u001f\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b \u0010\u000e\"\u0004\b!\u0010\u0010R\u001a\u0010\"\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b#\u0010\u0013\"\u0004\b$\u0010\u0015R\u001a\u0010%\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b&\u0010\u000e\"\u0004\b\'\u0010\u0010R\u0014\u0010(\u001a\u00020\u00048VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b)\u0010\u0013"}, d2 = {"Lcom/android/systemui/statusbar/notification/ExpandAnimationParameters;", "Lcom/android/systemui/animation/LaunchAnimator$State;", "()V", "top", "", "bottom", "left", "right", "topCornerRadius", "", "bottomCornerRadius", "(IIIIFF)V", "linearProgress", "getLinearProgress", "()F", "setLinearProgress", "(F)V", "parentStartClipTopAmount", "getParentStartClipTopAmount", "()I", "setParentStartClipTopAmount", "(I)V", "parentStartRoundedTopClipping", "getParentStartRoundedTopClipping", "setParentStartRoundedTopClipping", "progress", "getProgress", "setProgress", "startClipTopAmount", "getStartClipTopAmount", "setStartClipTopAmount", "startNotificationTop", "getStartNotificationTop", "setStartNotificationTop", "startRoundedTopClipping", "getStartRoundedTopClipping", "setStartRoundedTopClipping", "startTranslationZ", "getStartTranslationZ", "setStartTranslationZ", "topChange", "getTopChange", "delay", "", "duration"})
public final class ExpandAnimationParameters extends com.android.systemui.animation.LaunchAnimator.State {
    private float startTranslationZ = 0.0F;
    
    /**
     * The top position of the notification at the start of the animation. This is needed in order
     * to keep the notification at its place when launching a notification that is clipped rounded.
     */
    private float startNotificationTop = 0.0F;
    private int startClipTopAmount = 0;
    private int parentStartClipTopAmount = 0;
    private float progress = 0.0F;
    private float linearProgress = 0.0F;
    
    /**
     * The rounded top clipping at the beginning.
     */
    private int startRoundedTopClipping = 0;
    
    /**
     * The rounded top clipping of the parent notification at the start.
     */
    private int parentStartRoundedTopClipping = 0;
    
    public final float getStartTranslationZ() {
        return 0.0F;
    }
    
    public final void setStartTranslationZ(float p0) {
    }
    
    public final float getStartNotificationTop() {
        return 0.0F;
    }
    
    public final void setStartNotificationTop(float p0) {
    }
    
    public final int getStartClipTopAmount() {
        return 0;
    }
    
    public final void setStartClipTopAmount(int p0) {
    }
    
    public final int getParentStartClipTopAmount() {
        return 0;
    }
    
    public final void setParentStartClipTopAmount(int p0) {
    }
    
    public final float getProgress() {
        return 0.0F;
    }
    
    public final void setProgress(float p0) {
    }
    
    public final float getLinearProgress() {
        return 0.0F;
    }
    
    public final void setLinearProgress(float p0) {
    }
    
    public final int getStartRoundedTopClipping() {
        return 0;
    }
    
    public final void setStartRoundedTopClipping(int p0) {
    }
    
    public final int getParentStartRoundedTopClipping() {
        return 0;
    }
    
    public final void setParentStartRoundedTopClipping(int p0) {
    }
    
    @java.lang.Override()
    public int getTopChange() {
        return 0;
    }
    
    public final float getProgress(long delay, long duration) {
        return 0.0F;
    }
    
    public ExpandAnimationParameters(int top, int bottom, int left, int right, float topCornerRadius, float bottomCornerRadius) {
        super(0, 0, 0, 0, 0.0F, 0.0F);
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    public ExpandAnimationParameters() {
        super(0, 0, 0, 0, 0.0F, 0.0F);
    }
}
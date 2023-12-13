package com.android.wm.shell.bubbles;

import android.content.Context;
import android.graphics.drawable.TransitionDrawable;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import androidx.dynamicanimation.animation.DynamicAnimation;
import com.android.wm.shell.R;
import com.android.wm.shell.animation.PhysicsAnimator;
import com.android.wm.shell.common.DismissCircleView;
import android.view.WindowInsets;
import android.view.WindowManager;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0006\u0010\u0018\u001a\u00020\u0019J\u0006\u0010\u001a\u001a\u00020\u0019J\b\u0010\u001b\u001a\u00020\u0019H\u0002J\u0006\u0010\u001c\u001a\u00020\u0019R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082D\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\n\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u001a\u0010\u000f\u001a\u00020\u0010X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000f\u0010\u0011\"\u0004\b\u0012\u0010\u0013R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/bubbles/DismissView;", "Landroid/widget/FrameLayout;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "DISMISS_SCRIM_FADE_MS", "", "animator", "Lcom/android/wm/shell/animation/PhysicsAnimator;", "Lcom/android/wm/shell/common/DismissCircleView;", "circle", "getCircle", "()Lcom/android/wm/shell/common/DismissCircleView;", "setCircle", "(Lcom/android/wm/shell/common/DismissCircleView;)V", "isShowing", "", "()Z", "setShowing", "(Z)V", "spring", "Lcom/android/wm/shell/animation/PhysicsAnimator$SpringConfig;", "wm", "Landroid/view/WindowManager;", "hide", "", "show", "updatePadding", "updateResources"})
public final class DismissView extends android.widget.FrameLayout {
    @org.jetbrains.annotations.NotNull()
    private com.android.wm.shell.common.DismissCircleView circle;
    private boolean isShowing = false;
    private final com.android.wm.shell.animation.PhysicsAnimator<com.android.wm.shell.common.DismissCircleView> animator = null;
    private final com.android.wm.shell.animation.PhysicsAnimator.SpringConfig spring = null;
    private final int DISMISS_SCRIM_FADE_MS = 200;
    private android.view.WindowManager wm;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.common.DismissCircleView getCircle() {
        return null;
    }
    
    public final void setCircle(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.common.DismissCircleView p0) {
    }
    
    public final boolean isShowing() {
        return false;
    }
    
    public final void setShowing(boolean p0) {
    }
    
    /**
     * Animates this view in.
     */
    public final void show() {
    }
    
    /**
     * Animates this view out, as well as the circle that encircles the bubbles, if they
     * were dragged into the target and encircled.
     */
    public final void hide() {
    }
    
    public final void updateResources() {
    }
    
    private final void updatePadding() {
    }
    
    public DismissView(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
}
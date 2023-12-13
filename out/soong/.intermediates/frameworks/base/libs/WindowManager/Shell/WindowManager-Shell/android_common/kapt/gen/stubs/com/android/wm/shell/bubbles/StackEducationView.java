package com.android.wm.shell.bubbles;

import android.content.Context;
import android.graphics.Color;
import android.graphics.PointF;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnKeyListener;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.android.internal.util.ContrastColorUtil;
import com.android.wm.shell.R;
import com.android.wm.shell.animation.Interpolators;

/**
 * User education view to highlight the collapsed stack of bubbles.
 * Shown only the first time a user taps the stack.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000X\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0002\b\u0007\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u000e\u0010\u001f\u001a\u00020 2\u0006\u0010!\u001a\u00020\u0016J\b\u0010\"\u001a\u00020 H\u0014J\b\u0010#\u001a\u00020 H\u0014J\b\u0010$\u001a\u00020 H\u0014J\b\u0010%\u001a\u00020 H\u0002J\u0010\u0010&\u001a\u00020 2\u0006\u0010\'\u001a\u00020(H\u0016J\u0010\u0010)\u001a\u00020 2\u0006\u0010*\u001a\u00020\u0016H\u0002J\b\u0010+\u001a\u00020 H\u0002J\u000e\u0010,\u001a\u00020\u00162\u0006\u0010-\u001a\u00020.R\u000e\u0010\t\u001a\u00020\nX\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\nX\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R#\u0010\u000e\u001a\n \u0010*\u0004\u0018\u00010\u000f0\u000f8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0013\u0010\u0014\u001a\u0004\b\u0011\u0010\u0012R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R#\u0010\u0017\u001a\n \u0010*\u0004\u0018\u00010\u000f0\u000f8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0019\u0010\u0014\u001a\u0004\b\u0018\u0010\u0012R#\u0010\u001a\u001a\n \u0010*\u0004\u0018\u00010\u001b0\u001b8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u001e\u0010\u0014\u001a\u0004\b\u001c\u0010\u001d"}, d2 = {"Lcom/android/wm/shell/bubbles/StackEducationView;", "Landroid/widget/LinearLayout;", "context", "Landroid/content/Context;", "positioner", "Lcom/android/wm/shell/bubbles/BubblePositioner;", "controller", "Lcom/android/wm/shell/bubbles/BubbleController;", "(Landroid/content/Context;Lcom/android/wm/shell/bubbles/BubblePositioner;Lcom/android/wm/shell/bubbles/BubbleController;)V", "ANIMATE_DURATION", "", "ANIMATE_DURATION_SHORT", "TAG", "", "descTextView", "Landroid/widget/TextView;", "kotlin.jvm.PlatformType", "getDescTextView", "()Landroid/widget/TextView;", "descTextView$delegate", "Lkotlin/Lazy;", "isHiding", "", "titleTextView", "getTitleTextView", "titleTextView$delegate", "view", "Landroid/view/View;", "getView", "()Landroid/view/View;", "view$delegate", "hide", "", "isExpanding", "onAttachedToWindow", "onDetachedFromWindow", "onFinishInflate", "setDrawableDirection", "setLayoutDirection", "layoutDirection", "", "setShouldShow", "shouldShow", "setTextColor", "show", "stackPosition", "Landroid/graphics/PointF;"})
public final class StackEducationView extends android.widget.LinearLayout {
    private final java.lang.String TAG = null;
    private final long ANIMATE_DURATION = 200L;
    private final long ANIMATE_DURATION_SHORT = 40L;
    private final com.android.wm.shell.bubbles.BubblePositioner positioner = null;
    private final com.android.wm.shell.bubbles.BubbleController controller = null;
    private final kotlin.Lazy view$delegate = null;
    private final kotlin.Lazy titleTextView$delegate = null;
    private final kotlin.Lazy descTextView$delegate = null;
    private boolean isHiding = false;
    
    private final android.view.View getView() {
        return null;
    }
    
    private final android.widget.TextView getTitleTextView() {
        return null;
    }
    
    private final android.widget.TextView getDescTextView() {
        return null;
    }
    
    @java.lang.Override()
    public void setLayoutDirection(int layoutDirection) {
    }
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    @java.lang.Override()
    protected void onAttachedToWindow() {
    }
    
    @java.lang.Override()
    protected void onDetachedFromWindow() {
    }
    
    private final void setTextColor() {
    }
    
    private final void setDrawableDirection() {
    }
    
    /**
     * If necessary, shows the user education view for the bubble stack. This appears the first
     * time a user taps on a bubble.
     *
     * @return true if user education was shown, false otherwise.
     */
    public final boolean show(@org.jetbrains.annotations.NotNull()
    android.graphics.PointF stackPosition) {
        return false;
    }
    
    /**
     * If necessary, hides the stack education view.
     *
     * @param isExpanding if true this indicates the hide is happening due to the bubble being
     *                     expanded, false if due to a touch outside of the bubble stack.
     */
    public final void hide(boolean isExpanding) {
    }
    
    private final void setShouldShow(boolean shouldShow) {
    }
    
    public StackEducationView(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.bubbles.BubblePositioner positioner, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.bubbles.BubbleController controller) {
        super(null);
    }
}
package com.android.wm.shell.bubbles;

import android.content.Context;
import android.graphics.Color;
import android.graphics.Rect;
import android.graphics.drawable.ColorDrawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout;
import com.android.wm.shell.R;
import com.android.wm.shell.animation.Interpolators;

/**
 * User education view to highlight the manage button that allows a user to configure the settings
 * for the bubble. Shown only the first time a user expands a bubble.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000X\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0010\b\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0006\u0010 \u001a\u00020!J\b\u0010\"\u001a\u00020!H\u0014J\b\u0010#\u001a\u00020!H\u0002J\b\u0010$\u001a\u00020!H\u0002J\u0010\u0010%\u001a\u00020!2\u0006\u0010&\u001a\u00020\'H\u0016J\u0010\u0010(\u001a\u00020!2\u0006\u0010)\u001a\u00020\u0015H\u0002J\u000e\u0010*\u001a\u00020!2\u0006\u0010+\u001a\u00020\fR\u000e\u0010\u0007\u001a\u00020\bX\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R#\u0010\r\u001a\n \u000f*\u0004\u0018\u00010\u000e0\u000e8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0012\u0010\u0013\u001a\u0004\b\u0010\u0010\u0011R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R#\u0010\u0016\u001a\n \u000f*\u0004\u0018\u00010\u000e0\u000e8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0018\u0010\u0013\u001a\u0004\b\u0017\u0010\u0011R#\u0010\u0019\u001a\n \u000f*\u0004\u0018\u00010\u001a0\u001a8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u001d\u0010\u0013\u001a\u0004\b\u001b\u0010\u001cR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001e\u001a\u00020\u001fX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/bubbles/ManageEducationView;", "Landroid/widget/LinearLayout;", "context", "Landroid/content/Context;", "positioner", "Lcom/android/wm/shell/bubbles/BubblePositioner;", "(Landroid/content/Context;Lcom/android/wm/shell/bubbles/BubblePositioner;)V", "ANIMATE_DURATION", "", "TAG", "", "bubbleExpandedView", "Lcom/android/wm/shell/bubbles/BubbleExpandedView;", "gotItButton", "Landroid/widget/Button;", "kotlin.jvm.PlatformType", "getGotItButton", "()Landroid/widget/Button;", "gotItButton$delegate", "Lkotlin/Lazy;", "isHiding", "", "manageButton", "getManageButton", "manageButton$delegate", "manageView", "Landroid/view/ViewGroup;", "getManageView", "()Landroid/view/ViewGroup;", "manageView$delegate", "realManageButtonRect", "Landroid/graphics/Rect;", "hide", "", "onFinishInflate", "setButtonColor", "setDrawableDirection", "setLayoutDirection", "layoutDirection", "", "setShouldShow", "shouldShow", "show", "expandedView"})
public final class ManageEducationView extends android.widget.LinearLayout {
    private final java.lang.String TAG = null;
    private final long ANIMATE_DURATION = 200L;
    private final com.android.wm.shell.bubbles.BubblePositioner positioner = null;
    private final kotlin.Lazy manageView$delegate = null;
    private final kotlin.Lazy manageButton$delegate = null;
    private final kotlin.Lazy gotItButton$delegate = null;
    private boolean isHiding = false;
    private android.graphics.Rect realManageButtonRect;
    private com.android.wm.shell.bubbles.BubbleExpandedView bubbleExpandedView;
    
    private final android.view.ViewGroup getManageView() {
        return null;
    }
    
    private final android.widget.Button getManageButton() {
        return null;
    }
    
    private final android.widget.Button getGotItButton() {
        return null;
    }
    
    @java.lang.Override()
    public void setLayoutDirection(int layoutDirection) {
    }
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    private final void setButtonColor() {
    }
    
    private final void setDrawableDirection() {
    }
    
    /**
     * If necessary, toggles the user education view for the manage button. This is shown when the
     * bubble stack is expanded for the first time.
     *
     * @param expandedView the expandedView the user education is shown on top of.
     */
    public final void show(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.bubbles.BubbleExpandedView expandedView) {
    }
    
    public final void hide() {
    }
    
    private final void setShouldShow(boolean shouldShow) {
    }
    
    public ManageEducationView(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.bubbles.BubblePositioner positioner) {
        super(null);
    }
}
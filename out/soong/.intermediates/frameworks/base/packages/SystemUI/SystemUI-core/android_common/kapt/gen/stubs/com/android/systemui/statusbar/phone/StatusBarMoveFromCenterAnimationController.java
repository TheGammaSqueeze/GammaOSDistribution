package com.android.systemui.statusbar.phone;

import android.view.View;
import android.view.WindowManager;
import com.android.systemui.shared.animation.UnfoldMoveFromCenterAnimator;
import com.android.systemui.statusbar.phone.PhoneStatusBarViewController.StatusBarViewsCenterProvider;
import com.android.systemui.unfold.SysUIUnfoldScope;
import com.android.systemui.unfold.UnfoldTransitionProgressProvider.TransitionProgressListener;
import com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001:\u0001\u0013B\u0017\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0006\u0010\u000b\u001a\u00020\fJ\u0006\u0010\r\u001a\u00020\fJ\u0019\u0010\u000e\u001a\u00020\f2\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010\u00a2\u0006\u0002\u0010\u0012R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\t\u001a\u00060\nR\u00020\u0000X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/StatusBarMoveFromCenterAnimationController;", "", "progressProvider", "Lcom/android/systemui/unfold/util/ScopedUnfoldTransitionProgressProvider;", "windowManager", "Landroid/view/WindowManager;", "(Lcom/android/systemui/unfold/util/ScopedUnfoldTransitionProgressProvider;Landroid/view/WindowManager;)V", "moveFromCenterAnimator", "Lcom/android/systemui/shared/animation/UnfoldMoveFromCenterAnimator;", "transitionListener", "Lcom/android/systemui/statusbar/phone/StatusBarMoveFromCenterAnimationController$TransitionListener;", "onStatusBarWidthChanged", "", "onViewDetached", "onViewsReady", "viewsToAnimate", "", "Landroid/view/View;", "([Landroid/view/View;)V", "TransitionListener"})
@com.android.systemui.unfold.SysUIUnfoldScope()
public final class StatusBarMoveFromCenterAnimationController {
    private final com.android.systemui.statusbar.phone.StatusBarMoveFromCenterAnimationController.TransitionListener transitionListener = null;
    private final com.android.systemui.shared.animation.UnfoldMoveFromCenterAnimator moveFromCenterAnimator = null;
    private final com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider progressProvider = null;
    
    public final void onViewsReady(@org.jetbrains.annotations.NotNull()
    android.view.View[] viewsToAnimate) {
    }
    
    public final void onViewDetached() {
    }
    
    public final void onStatusBarWidthChanged() {
    }
    
    @javax.inject.Inject()
    public StatusBarMoveFromCenterAnimationController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider progressProvider, @org.jetbrains.annotations.NotNull()
    android.view.WindowManager windowManager) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\b\u0082\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0016J\u0010\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u0006\u001a\u00020\u0007H\u0016"}, d2 = {"Lcom/android/systemui/statusbar/phone/StatusBarMoveFromCenterAnimationController$TransitionListener;", "Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider$TransitionProgressListener;", "(Lcom/android/systemui/statusbar/phone/StatusBarMoveFromCenterAnimationController;)V", "onTransitionFinished", "", "onTransitionProgress", "progress", ""})
    final class TransitionListener implements com.android.systemui.unfold.UnfoldTransitionProgressProvider.TransitionProgressListener {
        
        @java.lang.Override()
        public void onTransitionProgress(float progress) {
        }
        
        @java.lang.Override()
        public void onTransitionFinished() {
        }
        
        public TransitionListener() {
            super();
        }
        
        public void onTransitionStarted() {
        }
    }
}
package com.android.systemui.statusbar.phone;

import android.graphics.Point;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewTreeObserver;
import com.android.systemui.R;
import com.android.systemui.shared.animation.UnfoldMoveFromCenterAnimator;
import com.android.systemui.unfold.SysUIUnfoldComponent;
import com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider;
import com.android.systemui.util.ViewController;
import java.util.Optional;
import javax.inject.Inject;
import javax.inject.Named;

/**
 * Controller for [PhoneStatusBarView].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0002\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001:\u0002\u0011\u0012B-\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0002\u0012\n\b\u0001\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\b\u0010\u000b\u001a\u00020\fH\u0014J\b\u0010\r\u001a\u00020\fH\u0014J\u000e\u0010\u000e\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u0010R\u0010\u0010\u0006\u001a\u0004\u0018\u00010\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0004\u001a\u0004\u0018\u00010\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/PhoneStatusBarViewController;", "Lcom/android/systemui/util/ViewController;", "Lcom/android/systemui/statusbar/phone/PhoneStatusBarView;", "view", "progressProvider", "Lcom/android/systemui/unfold/util/ScopedUnfoldTransitionProgressProvider;", "moveFromCenterAnimationController", "Lcom/android/systemui/statusbar/phone/StatusBarMoveFromCenterAnimationController;", "touchEventHandler", "Lcom/android/systemui/statusbar/phone/PhoneStatusBarView$TouchEventHandler;", "(Lcom/android/systemui/statusbar/phone/PhoneStatusBarView;Lcom/android/systemui/unfold/util/ScopedUnfoldTransitionProgressProvider;Lcom/android/systemui/statusbar/phone/StatusBarMoveFromCenterAnimationController;Lcom/android/systemui/statusbar/phone/PhoneStatusBarView$TouchEventHandler;)V", "onViewAttached", "", "onViewDetached", "setImportantForAccessibility", "mode", "", "Factory", "StatusBarViewsCenterProvider"})
public final class PhoneStatusBarViewController extends com.android.systemui.util.ViewController<com.android.systemui.statusbar.phone.PhoneStatusBarView> {
    private final com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider progressProvider = null;
    private final com.android.systemui.statusbar.phone.StatusBarMoveFromCenterAnimationController moveFromCenterAnimationController = null;
    
    @java.lang.Override()
    protected void onViewAttached() {
    }
    
    @java.lang.Override()
    protected void onViewDetached() {
    }
    
    public final void setImportantForAccessibility(int mode) {
    }
    
    private PhoneStatusBarViewController(com.android.systemui.statusbar.phone.PhoneStatusBarView view, @javax.inject.Named(value = "unfold_status_bar")
    com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider progressProvider, com.android.systemui.statusbar.phone.StatusBarMoveFromCenterAnimationController moveFromCenterAnimationController, com.android.systemui.statusbar.phone.PhoneStatusBarView.TouchEventHandler touchEventHandler) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016J \u0010\t\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\n\u001a\u00020\u000bH\u0002"}, d2 = {"Lcom/android/systemui/statusbar/phone/PhoneStatusBarViewController$StatusBarViewsCenterProvider;", "Lcom/android/systemui/shared/animation/UnfoldMoveFromCenterAnimator$ViewCenterProvider;", "()V", "getViewCenter", "", "view", "Landroid/view/View;", "outPoint", "Landroid/graphics/Point;", "getViewEdgeCenter", "isStart", ""})
    public static final class StatusBarViewsCenterProvider implements com.android.systemui.shared.animation.UnfoldMoveFromCenterAnimator.ViewCenterProvider {
        
        @java.lang.Override()
        public void getViewCenter(@org.jetbrains.annotations.NotNull()
        android.view.View view, @org.jetbrains.annotations.NotNull()
        android.graphics.Point outPoint) {
        }
        
        /**
         * Returns start or end (based on [isStart]) center point of the view
         */
        private final void getViewEdgeCenter(android.view.View view, android.graphics.Point outPoint, boolean isStart) {
        }
        
        public StatusBarViewsCenterProvider() {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B%\b\u0007\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u000e\b\u0001\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00060\u0003\u00a2\u0006\u0002\u0010\u0007J\u0016\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rR\u0014\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00060\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/PhoneStatusBarViewController$Factory;", "", "unfoldComponent", "Ljava/util/Optional;", "Lcom/android/systemui/unfold/SysUIUnfoldComponent;", "progressProvider", "Lcom/android/systemui/unfold/util/ScopedUnfoldTransitionProgressProvider;", "(Ljava/util/Optional;Ljava/util/Optional;)V", "create", "Lcom/android/systemui/statusbar/phone/PhoneStatusBarViewController;", "view", "Lcom/android/systemui/statusbar/phone/PhoneStatusBarView;", "touchEventHandler", "Lcom/android/systemui/statusbar/phone/PhoneStatusBarView$TouchEventHandler;"})
    public static final class Factory {
        private final java.util.Optional<com.android.systemui.unfold.SysUIUnfoldComponent> unfoldComponent = null;
        private final java.util.Optional<com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider> progressProvider = null;
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.phone.PhoneStatusBarViewController create(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.phone.PhoneStatusBarView view, @org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.phone.PhoneStatusBarView.TouchEventHandler touchEventHandler) {
            return null;
        }
        
        @javax.inject.Inject()
        public Factory(@org.jetbrains.annotations.NotNull()
        java.util.Optional<com.android.systemui.unfold.SysUIUnfoldComponent> unfoldComponent, @org.jetbrains.annotations.NotNull()
        @javax.inject.Named(value = "unfold_status_bar")
        java.util.Optional<com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider> progressProvider) {
            super();
        }
    }
}
package com.android.systemui.statusbar.phone;

import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.animation.LaunchAnimator;

/**
 * A [ActivityLaunchAnimator.Controller] that takes care of collapsing the status bar at the right
 * time.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0007\n\u0002\u0010\u0007\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u001f\u0012\u0006\u0010\u0002\u001a\u00020\u0001\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\b\b\u0002\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\t\u0010\u000e\u001a\u00020\u000fH\u0096\u0001J\u0010\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0006H\u0016J\b\u0010\u0013\u001a\u00020\u0011H\u0016J\u0010\u0010\u0014\u001a\u00020\u00112\u0006\u0010\u0015\u001a\u00020\u0006H\u0016J \u0010\u0016\u001a\u00020\u00112\u0006\u0010\u0017\u001a\u00020\u000f2\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u0019H\u0016J\u0010\u0010\u001b\u001a\u00020\u00112\u0006\u0010\u0015\u001a\u00020\u0006H\u0016R\u000e\u0010\u0002\u001a\u00020\u0001X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0018\u0010\b\u001a\u00020\tX\u0096\u000f\u00a2\u0006\f\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/StatusBarLaunchAnimatorController;", "Lcom/android/systemui/animation/ActivityLaunchAnimator$Controller;", "delegate", "statusBar", "Lcom/android/systemui/statusbar/phone/StatusBar;", "isLaunchForActivity", "", "(Lcom/android/systemui/animation/ActivityLaunchAnimator$Controller;Lcom/android/systemui/statusbar/phone/StatusBar;Z)V", "launchContainer", "Landroid/view/ViewGroup;", "getLaunchContainer", "()Landroid/view/ViewGroup;", "setLaunchContainer", "(Landroid/view/ViewGroup;)V", "createAnimatorState", "Lcom/android/systemui/animation/LaunchAnimator$State;", "onIntentStarted", "", "willAnimate", "onLaunchAnimationCancelled", "onLaunchAnimationEnd", "isExpandingFullyAbove", "onLaunchAnimationProgress", "state", "progress", "", "linearProgress", "onLaunchAnimationStart"})
public final class StatusBarLaunchAnimatorController implements com.android.systemui.animation.ActivityLaunchAnimator.Controller {
    private final com.android.systemui.animation.ActivityLaunchAnimator.Controller delegate = null;
    private final com.android.systemui.statusbar.phone.StatusBar statusBar = null;
    private final boolean isLaunchForActivity = false;
    
    @java.lang.Override()
    public void onIntentStarted(boolean willAnimate) {
    }
    
    @java.lang.Override()
    public void onLaunchAnimationStart(boolean isExpandingFullyAbove) {
    }
    
    @java.lang.Override()
    public void onLaunchAnimationEnd(boolean isExpandingFullyAbove) {
    }
    
    @java.lang.Override()
    public void onLaunchAnimationProgress(@org.jetbrains.annotations.NotNull()
    com.android.systemui.animation.LaunchAnimator.State state, float progress, float linearProgress) {
    }
    
    @java.lang.Override()
    public void onLaunchAnimationCancelled() {
    }
    
    public StatusBarLaunchAnimatorController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.animation.ActivityLaunchAnimator.Controller delegate, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBar statusBar, boolean isLaunchForActivity) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.ViewGroup getLaunchContainer() {
        return null;
    }
    
    @java.lang.Override()
    public void setLaunchContainer(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.animation.LaunchAnimator.State createAnimatorState() {
        return null;
    }
}
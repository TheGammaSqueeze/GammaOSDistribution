package com.android.systemui.statusbar.notification;

import android.view.ViewGroup;
import com.android.internal.jank.InteractionJankMonitor;
import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.animation.LaunchAnimator;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.stack.NotificationListContainer;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.NotificationShadeWindowViewController;
import com.android.systemui.statusbar.policy.HeadsUpUtil;

/**
 * An [ActivityLaunchAnimator.Controller] that animates an [ExpandableNotificationRow]. An instance
 * of this class can be passed to [ActivityLaunchAnimator.startIntentWithAnimation] to animate a
 * notification expanding into an opening window.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0010\u0007\n\u0002\b\u0005\u0018\u0000 +2\u00020\u0001:\u0001+B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0012\u0010\u0017\u001a\u00020\u00182\b\u0010\u0019\u001a\u0004\u0018\u00010\u001aH\u0002J\b\u0010\u001b\u001a\u00020\u001cH\u0016J\u0010\u0010\u001d\u001a\u00020\u00182\u0006\u0010\u001e\u001a\u00020\u001fH\u0016J\b\u0010 \u001a\u00020\u0018H\u0016J\u0010\u0010!\u001a\u00020\u00182\u0006\u0010\"\u001a\u00020\u001fH\u0016J \u0010#\u001a\u00020\u00182\u0006\u0010$\u001a\u00020\u001c2\u0006\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020&H\u0016J\u0010\u0010(\u001a\u00020\u00182\u0006\u0010\"\u001a\u00020\u001fH\u0016J\u0010\u0010)\u001a\u00020\u00182\u0006\u0010*\u001a\u00020\u001fH\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\r\u001a\u00020\f2\u0006\u0010\u000b\u001a\u00020\f8V@VX\u0096\u000e\u00a2\u0006\f\u001a\u0004\b\u000e\u0010\u000f\"\u0004\b\u0010\u0010\u0011R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0014\u001a\n \u0016*\u0004\u0018\u00010\u00150\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/NotificationLaunchAnimatorController;", "Lcom/android/systemui/animation/ActivityLaunchAnimator$Controller;", "notificationShadeWindowViewController", "Lcom/android/systemui/statusbar/phone/NotificationShadeWindowViewController;", "notificationListContainer", "Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;", "headsUpManager", "Lcom/android/systemui/statusbar/phone/HeadsUpManagerPhone;", "notification", "Lcom/android/systemui/statusbar/notification/row/ExpandableNotificationRow;", "(Lcom/android/systemui/statusbar/phone/NotificationShadeWindowViewController;Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;Lcom/android/systemui/statusbar/phone/HeadsUpManagerPhone;Lcom/android/systemui/statusbar/notification/row/ExpandableNotificationRow;)V", "ignored", "Landroid/view/ViewGroup;", "launchContainer", "getLaunchContainer", "()Landroid/view/ViewGroup;", "setLaunchContainer", "(Landroid/view/ViewGroup;)V", "notificationEntry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "notificationKey", "", "kotlin.jvm.PlatformType", "applyParams", "", "params", "Lcom/android/systemui/statusbar/notification/ExpandAnimationParameters;", "createAnimatorState", "Lcom/android/systemui/animation/LaunchAnimator$State;", "onIntentStarted", "willAnimate", "", "onLaunchAnimationCancelled", "onLaunchAnimationEnd", "isExpandingFullyAbove", "onLaunchAnimationProgress", "state", "progress", "", "linearProgress", "onLaunchAnimationStart", "removeHun", "animate", "Companion"})
public final class NotificationLaunchAnimatorController implements com.android.systemui.animation.ActivityLaunchAnimator.Controller {
    private final com.android.systemui.statusbar.notification.collection.NotificationEntry notificationEntry = null;
    private final java.lang.String notificationKey = null;
    private final com.android.systemui.statusbar.phone.NotificationShadeWindowViewController notificationShadeWindowViewController = null;
    private final com.android.systemui.statusbar.notification.stack.NotificationListContainer notificationListContainer = null;
    private final com.android.systemui.statusbar.phone.HeadsUpManagerPhone headsUpManager = null;
    private final com.android.systemui.statusbar.notification.row.ExpandableNotificationRow notification = null;
    public static final long ANIMATION_DURATION_TOP_ROUNDING = 100L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.NotificationLaunchAnimatorController.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.ViewGroup getLaunchContainer() {
        return null;
    }
    
    @java.lang.Override()
    public void setLaunchContainer(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup ignored) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.animation.LaunchAnimator.State createAnimatorState() {
        return null;
    }
    
    @java.lang.Override()
    public void onIntentStarted(boolean willAnimate) {
    }
    
    private final void removeHun(boolean animate) {
    }
    
    @java.lang.Override()
    public void onLaunchAnimationCancelled() {
    }
    
    @java.lang.Override()
    public void onLaunchAnimationStart(boolean isExpandingFullyAbove) {
    }
    
    @java.lang.Override()
    public void onLaunchAnimationEnd(boolean isExpandingFullyAbove) {
    }
    
    private final void applyParams(com.android.systemui.statusbar.notification.ExpandAnimationParameters params) {
    }
    
    @java.lang.Override()
    public void onLaunchAnimationProgress(@org.jetbrains.annotations.NotNull()
    com.android.systemui.animation.LaunchAnimator.State state, float progress, float linearProgress) {
    }
    
    public NotificationLaunchAnimatorController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.NotificationShadeWindowViewController notificationShadeWindowViewController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationListContainer notificationListContainer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.HeadsUpManagerPhone headsUpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.ExpandableNotificationRow notification) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/NotificationLaunchAnimatorController$Companion;", "", "()V", "ANIMATION_DURATION_TOP_ROUNDING", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
package com.android.systemui.statusbar.notification;

import android.animation.ObjectAnimator;
import android.util.FloatProperty;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController;
import com.android.systemui.statusbar.notification.stack.StackStateAnimator;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionListener;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import com.android.systemui.statusbar.policy.OnHeadsUpChangedListener;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0084\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\t\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0002\b&\b\u0007\u0018\u00002\u00020\u00012\u00020\u00022\u00020\u0003:\u0001gB/\b\u0007\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ\u000e\u0010@\u001a\u00020A2\u0006\u0010B\u001a\u000209J\b\u0010C\u001a\u00020AH\u0002J\u0006\u0010D\u001a\u00020\u0010J\u0010\u0010E\u001a\u00020A2\u0006\u0010F\u001a\u00020\u0010H\u0002J\u0018\u0010G\u001a\u00020A2\u0006\u0010H\u001a\u00020\u001a2\u0006\u0010I\u001a\u00020\u001aH\u0016J\u0010\u0010J\u001a\u00020A2\u0006\u0010K\u001a\u00020\u0010H\u0016J\u0018\u0010L\u001a\u00020A2\u0006\u0010M\u001a\u00020\u001d2\u0006\u0010N\u001a\u00020\u0010H\u0016J \u0010O\u001a\u00020A2\u0006\u0010P\u001a\u00020\u001a2\u0006\u0010Q\u001a\u00020\u00102\u0006\u0010R\u001a\u00020\u0010H\u0016J\u0010\u0010S\u001a\u00020A2\u0006\u0010T\u001a\u000206H\u0016J\u0010\u0010U\u001a\u00020\u00102\u0006\u0010V\u001a\u00020\u001aH\u0002J\b\u0010W\u001a\u00020\u0010H\u0002J\u000e\u0010X\u001a\u00020A2\u0006\u0010B\u001a\u000209J\u0016\u0010Y\u001a\u00020A2\u0006\u0010H\u001a\u00020\u001a2\u0006\u0010I\u001a\u00020\u001aJ \u0010Z\u001a\u00020A2\u0006\u0010[\u001a\u00020\u00102\u0006\u0010\\\u001a\u00020\u00102\u0006\u0010]\u001a\u00020\u0010H\u0002J\u001e\u0010^\u001a\u00020A2\u0006\u0010[\u001a\u00020\u00102\u0006\u0010\\\u001a\u00020\u00102\u0006\u0010]\u001a\u00020\u0010J\u000e\u0010_\u001a\u00020A2\u0006\u0010`\u001a\u00020&J\u0010\u0010a\u001a\u00020A2\u0006\u0010b\u001a\u00020\u001aH\u0002J\b\u0010c\u001a\u00020\u0010H\u0002J\u0010\u0010d\u001a\u00020A2\u0006\u0010]\u001a\u00020\u0010H\u0002J\b\u0010e\u001a\u00020AH\u0002J\u0018\u0010f\u001a\u00020A2\u0006\u0010\\\u001a\u00020\u00102\u0006\u0010]\u001a\u00020\u0010H\u0002R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\u0011\u001a\u00020\u00102\u0006\u0010\u000f\u001a\u00020\u00108F@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u000e\u0010\u0014\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0015\u001a\u00020\u0010X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0016\u0010\u0013\"\u0004\b\u0017\u0010\u0018R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\u001d0\u001cX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001e\u001a\u00020\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010 \u001a\b\u0012\u0004\u0012\u00020\u00000!X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010#\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010$\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010%\u001a\u00020&X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010(\u001a\u0004\u0018\u00010)X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010*\u001a\n ,*\u0004\u0018\u00010+0+X\u0082\u000e\u00a2\u0006\u0002\n\u0000R$\u0010.\u001a\u00020\u00102\u0006\u0010-\u001a\u00020\u0010@BX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b/\u0010\u0013\"\u0004\b0\u0010\u0018R\u000e\u00101\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R$\u00102\u001a\u00020\u00102\u0006\u0010-\u001a\u00020\u0010@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b3\u0010\u0013\"\u0004\b4\u0010\u0018R\u000e\u00105\u001a\u000206X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u00107\u001a\b\u0012\u0004\u0012\u00020908X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010:\u001a\u00020\u00102\u0006\u0010-\u001a\u00020\u0010@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b;\u0010\u0013\"\u0004\b<\u0010\u0018R$\u0010=\u001a\u00020\u00102\u0006\u0010-\u001a\u00020\u0010@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b>\u0010\u0013\"\u0004\b?\u0010\u0018"}, d2 = {"Lcom/android/systemui/statusbar/notification/NotificationWakeUpCoordinator;", "Lcom/android/systemui/statusbar/policy/OnHeadsUpChangedListener;", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController$StateListener;", "Lcom/android/systemui/statusbar/phone/panelstate/PanelExpansionListener;", "mHeadsUpManager", "Lcom/android/systemui/statusbar/policy/HeadsUpManager;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "bypassController", "Lcom/android/systemui/statusbar/phone/KeyguardBypassController;", "dozeParameters", "Lcom/android/systemui/statusbar/phone/DozeParameters;", "unlockedScreenOffAnimationController", "Lcom/android/systemui/statusbar/phone/UnlockedScreenOffAnimationController;", "(Lcom/android/systemui/statusbar/policy/HeadsUpManager;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/statusbar/phone/KeyguardBypassController;Lcom/android/systemui/statusbar/phone/DozeParameters;Lcom/android/systemui/statusbar/phone/UnlockedScreenOffAnimationController;)V", "<set-?>", "", "canShowPulsingHuns", "getCanShowPulsingHuns", "()Z", "collapsedEnoughToHide", "fullyAwake", "getFullyAwake", "setFullyAwake", "(Z)V", "mDozeAmount", "", "mEntrySetToClearWhenFinished", "", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "mLinearDozeAmount", "mLinearVisibilityAmount", "mNotificationVisibility", "Landroid/util/FloatProperty;", "mNotificationVisibleAmount", "mNotificationsVisible", "mNotificationsVisibleForExpansion", "mStackScrollerController", "Lcom/android/systemui/statusbar/notification/stack/NotificationStackScrollLayoutController;", "mVisibilityAmount", "mVisibilityAnimator", "Landroid/animation/ObjectAnimator;", "mVisibilityInterpolator", "Landroid/view/animation/Interpolator;", "kotlin.jvm.PlatformType", "value", "notificationsFullyHidden", "getNotificationsFullyHidden", "setNotificationsFullyHidden", "pulseExpanding", "pulsing", "getPulsing", "setPulsing", "state", "", "wakeUpListeners", "Ljava/util/ArrayList;", "Lcom/android/systemui/statusbar/notification/NotificationWakeUpCoordinator$WakeUpListener;", "wakingUp", "getWakingUp", "setWakingUp", "willWakeUp", "getWillWakeUp", "setWillWakeUp", "addListener", "", "listener", "handleAnimationFinished", "isPulseExpanding", "notifyAnimationStart", "awake", "onDozeAmountChanged", "linear", "eased", "onDozingChanged", "isDozing", "onHeadsUpStateChanged", "entry", "isHeadsUp", "onPanelExpansionChanged", "fraction", "expanded", "tracking", "onStateChanged", "newState", "overrideDozeAmountIfAnimatingScreenOff", "linearDozeAmount", "overrideDozeAmountIfBypass", "removeListener", "setDozeAmount", "setNotificationsVisible", "visible", "animate", "increaseSpeed", "setNotificationsVisibleForExpansion", "setStackScroller", "stackScrollerController", "setVisibilityAmount", "visibilityAmount", "shouldAnimateVisibility", "startVisibilityAnimation", "updateHideAmount", "updateNotificationVisibility", "WakeUpListener"})
@com.android.systemui.dagger.SysUISingleton()
public final class NotificationWakeUpCoordinator implements com.android.systemui.statusbar.policy.OnHeadsUpChangedListener, com.android.systemui.plugins.statusbar.StatusBarStateController.StateListener, com.android.systemui.statusbar.phone.panelstate.PanelExpansionListener {
    private final android.util.FloatProperty<com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator> mNotificationVisibility = null;
    private com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController mStackScrollerController;
    private android.view.animation.Interpolator mVisibilityInterpolator;
    private float mLinearDozeAmount = 0.0F;
    private float mDozeAmount = 0.0F;
    private float mNotificationVisibleAmount = 0.0F;
    private boolean mNotificationsVisible = false;
    private boolean mNotificationsVisibleForExpansion = false;
    private android.animation.ObjectAnimator mVisibilityAnimator;
    private float mVisibilityAmount = 0.0F;
    private float mLinearVisibilityAmount = 0.0F;
    private final java.util.Set<com.android.systemui.statusbar.notification.collection.NotificationEntry> mEntrySetToClearWhenFinished = null;
    private boolean pulseExpanding = false;
    private final java.util.ArrayList<com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator.WakeUpListener> wakeUpListeners = null;
    private int state = com.android.systemui.statusbar.StatusBarState.KEYGUARD;
    private boolean fullyAwake = false;
    private boolean wakingUp = false;
    private boolean willWakeUp = false;
    private boolean collapsedEnoughToHide = false;
    private boolean pulsing = false;
    private boolean notificationsFullyHidden = false;
    
    /**
     * True if we can show pulsing heads up notifications
     */
    private boolean canShowPulsingHuns = false;
    private final com.android.systemui.statusbar.policy.HeadsUpManager mHeadsUpManager = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.phone.KeyguardBypassController bypassController = null;
    private final com.android.systemui.statusbar.phone.DozeParameters dozeParameters = null;
    private final com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController unlockedScreenOffAnimationController = null;
    
    public final boolean getFullyAwake() {
        return false;
    }
    
    public final void setFullyAwake(boolean p0) {
    }
    
    public final boolean getWakingUp() {
        return false;
    }
    
    public final void setWakingUp(boolean value) {
    }
    
    public final boolean getWillWakeUp() {
        return false;
    }
    
    public final void setWillWakeUp(boolean value) {
    }
    
    public final boolean getPulsing() {
        return false;
    }
    
    public final void setPulsing(boolean value) {
    }
    
    public final boolean getNotificationsFullyHidden() {
        return false;
    }
    
    private final void setNotificationsFullyHidden(boolean value) {
    }
    
    public final boolean getCanShowPulsingHuns() {
        return false;
    }
    
    public final void setStackScroller(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController stackScrollerController) {
    }
    
    public final boolean isPulseExpanding() {
        return false;
    }
    
    /**
     * @param visible should notifications be visible
     * @param animate should this change be animated
     * @param increaseSpeed should the speed be increased of the animation
     */
    public final void setNotificationsVisibleForExpansion(boolean visible, boolean animate, boolean increaseSpeed) {
    }
    
    public final void addListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator.WakeUpListener listener) {
    }
    
    public final void removeListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator.WakeUpListener listener) {
    }
    
    private final void updateNotificationVisibility(boolean animate, boolean increaseSpeed) {
    }
    
    private final void setNotificationsVisible(boolean visible, boolean animate, boolean increaseSpeed) {
    }
    
    @java.lang.Override()
    public void onDozeAmountChanged(float linear, float eased) {
    }
    
    public final void setDozeAmount(float linear, float eased) {
    }
    
    @java.lang.Override()
    public void onStateChanged(int newState) {
    }
    
    @java.lang.Override()
    public void onPanelExpansionChanged(float fraction, boolean expanded, boolean tracking) {
    }
    
    /**
     * @return Whether the doze amount was overridden because bypass is enabled. If true, the
     * original doze amount should be ignored.
     */
    private final boolean overrideDozeAmountIfBypass() {
        return false;
    }
    
    /**
     * If we're playing the screen off animation, force the notification doze amount to be 1f (fully
     * dozing). This is needed so that the notifications aren't briefly visible as the screen turns
     * off and dozeAmount goes from 1f to 0f.
     *
     * @return Whether the doze amount was overridden because we are playing the screen off
     * animation. If true, the original doze amount should be ignored.
     */
    private final boolean overrideDozeAmountIfAnimatingScreenOff(float linearDozeAmount) {
        return false;
    }
    
    private final void startVisibilityAnimation(boolean increaseSpeed) {
    }
    
    private final void setVisibilityAmount(float visibilityAmount) {
    }
    
    private final void handleAnimationFinished() {
    }
    
    private final void updateHideAmount() {
    }
    
    private final void notifyAnimationStart(boolean awake) {
    }
    
    @java.lang.Override()
    public void onDozingChanged(boolean isDozing) {
    }
    
    @java.lang.Override()
    public void onHeadsUpStateChanged(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, boolean isHeadsUp) {
    }
    
    private final boolean shouldAnimateVisibility() {
        return false;
    }
    
    @javax.inject.Inject()
    public NotificationWakeUpCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.HeadsUpManager mHeadsUpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardBypassController bypassController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.DozeParameters dozeParameters, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController unlockedScreenOffAnimationController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\u0017J\u0010\u0010\u0006\u001a\u00020\u00032\u0006\u0010\u0007\u001a\u00020\u0005H\u0017\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/statusbar/notification/NotificationWakeUpCoordinator$WakeUpListener;", "", "onFullyHiddenChanged", "", "isFullyHidden", "", "onPulseExpansionChanged", "expandingChanged"})
    public static abstract interface WakeUpListener {
        
        /**
         * Called whenever the notifications are fully hidden or shown
         */
        public default void onFullyHiddenChanged(boolean isFullyHidden) {
        }
        
        /**
         * Called whenever the pulseExpansion changes
         * @param expandingChanged if the user has started or stopped expanding
         */
        public default void onPulseExpansionChanged(boolean expandingChanged) {
        }
    }
}
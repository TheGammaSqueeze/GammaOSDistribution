package com.android.systemui.statusbar.phone;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.content.Context;
import android.database.ContentObserver;
import android.os.Handler;
import android.os.PowerManager;
import android.provider.Settings;
import android.view.Surface;
import android.view.View;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.keyguard.KeyguardViewMediator;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.statusbar.LightRevealScrim;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.StatusBarStateControllerImpl;
import com.android.systemui.statusbar.notification.AnimatableProperty;
import com.android.systemui.statusbar.notification.PropertyAnimator;
import com.android.systemui.statusbar.notification.stack.AnimationProperties;
import com.android.systemui.statusbar.notification.stack.StackStateAnimator;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.settings.GlobalSettings;
import javax.inject.Inject;

/**
 * Controller for the unlocked screen off animation, which runs when the device is going to sleep
 * and we're unlocked.
 *
 * This animation uses a [LightRevealScrim] that lives in the status bar to hide the screen contents
 * and then animates in the AOD UI.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0092\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\r\b\u0007\u0018\u00002\u00020\u0001:\u0001@B]\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\t\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\f\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u000e0\t\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\b\b\u0002\u0010\u0013\u001a\u00020\u0014\u00a2\u0006\u0002\u0010\u0015J\u000e\u0010,\u001a\u00020-2\u0006\u0010.\u001a\u00020 J\u0016\u0010/\u001a\u00020-2\u0006\u00100\u001a\u0002012\u0006\u00102\u001a\u000203J\u0016\u00104\u001a\u00020-2\u0006\u0010*\u001a\u00020+2\u0006\u0010\'\u001a\u00020(J\u0006\u00105\u001a\u00020\u001dJ\u0006\u00106\u001a\u00020\u001dJ\b\u00107\u001a\u00020-H\u0016J\b\u00108\u001a\u00020-H\u0016J\b\u00109\u001a\u00020-H\u0016J\u000e\u0010:\u001a\u00020-2\u0006\u0010.\u001a\u00020 J\u0016\u0010;\u001a\u00020-2\u0006\u0010<\u001a\u00020\u00172\u0006\u0010=\u001a\u00020\u0017J\u0006\u0010)\u001a\u00020\u001dJ\u0006\u0010>\u001a\u00020\u001dJ\u0006\u0010?\u001a\u00020-R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0018\u001a\u00020\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u001bR\u000e\u0010\u001c\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001e\u001a\b\u0012\u0004\u0012\u00020 0\u001fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010!\u001a\u0004\u0018\u00010\u001dX\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\"R\u0014\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u000e0\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010#\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010$\u001a\n &*\u0004\u0018\u00010%0%X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020(X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010)\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020+X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/UnlockedScreenOffAnimationController;", "Lcom/android/systemui/keyguard/WakefulnessLifecycle$Observer;", "context", "Landroid/content/Context;", "wakefulnessLifecycle", "Lcom/android/systemui/keyguard/WakefulnessLifecycle;", "statusBarStateControllerImpl", "Lcom/android/systemui/statusbar/StatusBarStateControllerImpl;", "keyguardViewMediatorLazy", "Ldagger/Lazy;", "Lcom/android/systemui/keyguard/KeyguardViewMediator;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "dozeParameters", "Lcom/android/systemui/statusbar/phone/DozeParameters;", "globalSettings", "Lcom/android/systemui/util/settings/GlobalSettings;", "powerManager", "Landroid/os/PowerManager;", "handler", "Landroid/os/Handler;", "(Landroid/content/Context;Lcom/android/systemui/keyguard/WakefulnessLifecycle;Lcom/android/systemui/statusbar/StatusBarStateControllerImpl;Ldagger/Lazy;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Ldagger/Lazy;Lcom/android/systemui/util/settings/GlobalSettings;Landroid/os/PowerManager;Landroid/os/Handler;)V", "animatorDurationScale", "", "animatorDurationScaleObserver", "Landroid/database/ContentObserver;", "getAnimatorDurationScaleObserver", "()Landroid/database/ContentObserver;", "aodUiAnimationPlaying", "", "callbacks", "Ljava/util/HashSet;", "Lcom/android/systemui/statusbar/phone/UnlockedScreenOffAnimationController$Callback;", "decidedToAnimateGoingToSleep", "Ljava/lang/Boolean;", "lightRevealAnimationPlaying", "lightRevealAnimator", "Landroid/animation/ValueAnimator;", "kotlin.jvm.PlatformType", "lightRevealScrim", "Lcom/android/systemui/statusbar/LightRevealScrim;", "shouldAnimateInKeyguard", "statusBar", "Lcom/android/systemui/statusbar/phone/StatusBar;", "addCallback", "", "callback", "animateInKeyguard", "keyguardView", "Landroid/view/View;", "after", "Ljava/lang/Runnable;", "initialize", "isScreenOffAnimationPlaying", "isScreenOffLightRevealAnimationPlaying", "onFinishedWakingUp", "onStartedGoingToSleep", "onStartedWakingUp", "removeCallback", "sendUnlockedScreenOffProgressUpdate", "linear", "eased", "shouldPlayUnlockedScreenOffAnimation", "updateAnimatorDurationScale", "Callback"})
@com.android.systemui.dagger.SysUISingleton()
public final class UnlockedScreenOffAnimationController implements com.android.systemui.keyguard.WakefulnessLifecycle.Observer {
    private com.android.systemui.statusbar.phone.StatusBar statusBar;
    private com.android.systemui.statusbar.LightRevealScrim lightRevealScrim;
    private float animatorDurationScale = 1.0F;
    private boolean shouldAnimateInKeyguard = false;
    private boolean lightRevealAnimationPlaying = false;
    private boolean aodUiAnimationPlaying = false;
    private java.util.HashSet<com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController.Callback> callbacks;
    
    /**
     * The result of our decision whether to play the screen off animation in
     * [onStartedGoingToSleep], or null if we haven't made that decision yet or aren't going to
     * sleep.
     */
    private java.lang.Boolean decidedToAnimateGoingToSleep;
    private final android.animation.ValueAnimator lightRevealAnimator = null;
    @org.jetbrains.annotations.NotNull()
    private final android.database.ContentObserver animatorDurationScaleObserver = null;
    private final android.content.Context context = null;
    private final com.android.systemui.keyguard.WakefulnessLifecycle wakefulnessLifecycle = null;
    private final com.android.systemui.statusbar.StatusBarStateControllerImpl statusBarStateControllerImpl = null;
    private final dagger.Lazy<com.android.systemui.keyguard.KeyguardViewMediator> keyguardViewMediatorLazy = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private final dagger.Lazy<com.android.systemui.statusbar.phone.DozeParameters> dozeParameters = null;
    private final com.android.systemui.util.settings.GlobalSettings globalSettings = null;
    private final android.os.PowerManager powerManager = null;
    private final android.os.Handler handler = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.database.ContentObserver getAnimatorDurationScaleObserver() {
        return null;
    }
    
    public final void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBar statusBar, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.LightRevealScrim lightRevealScrim) {
    }
    
    public final void updateAnimatorDurationScale() {
    }
    
    /**
     * Animates in the provided keyguard view, ending in the same position that it will be in on
     * AOD.
     */
    public final void animateInKeyguard(@org.jetbrains.annotations.NotNull()
    android.view.View keyguardView, @org.jetbrains.annotations.NotNull()
    java.lang.Runnable after) {
    }
    
    @java.lang.Override()
    public void onStartedWakingUp() {
    }
    
    @java.lang.Override()
    public void onFinishedWakingUp() {
    }
    
    @java.lang.Override()
    public void onStartedGoingToSleep() {
    }
    
    /**
     * Whether we want to play the screen off animation when the phone starts going to sleep, based
     * on the current state of the device.
     */
    public final boolean shouldPlayUnlockedScreenOffAnimation() {
        return false;
    }
    
    public final void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController.Callback callback) {
    }
    
    public final void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController.Callback callback) {
    }
    
    public final void sendUnlockedScreenOffProgressUpdate(float linear, float eased) {
    }
    
    /**
     * Whether we're doing the light reveal animation or we're done with that and animating in the
     * AOD UI.
     */
    public final boolean isScreenOffAnimationPlaying() {
        return false;
    }
    
    public final boolean shouldAnimateInKeyguard() {
        return false;
    }
    
    /**
     * Whether the light reveal animation is playing. The second part of the screen off animation,
     * where AOD animates in, might still be playing if this returns false.
     */
    public final boolean isScreenOffLightRevealAnimationPlaying() {
        return false;
    }
    
    @javax.inject.Inject()
    public UnlockedScreenOffAnimationController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.keyguard.WakefulnessLifecycle wakefulnessLifecycle, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.StatusBarStateControllerImpl statusBarStateControllerImpl, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.keyguard.KeyguardViewMediator> keyguardViewMediatorLazy, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.statusbar.phone.DozeParameters> dozeParameters, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.settings.GlobalSettings globalSettings, @org.jetbrains.annotations.NotNull()
    android.os.PowerManager powerManager, @org.jetbrains.annotations.NotNull()
    android.os.Handler handler) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u0007\n\u0000\bf\u0018\u00002\u00020\u0001J\u0018\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/phone/UnlockedScreenOffAnimationController$Callback;", "", "onUnlockedScreenOffProgressUpdate", "", "linear", "", "eased"})
    public static abstract interface Callback {
        
        public abstract void onUnlockedScreenOffProgressUpdate(float linear, float eased);
    }
}
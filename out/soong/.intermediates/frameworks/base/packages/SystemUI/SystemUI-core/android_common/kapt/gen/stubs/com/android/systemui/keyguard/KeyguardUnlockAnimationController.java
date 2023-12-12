package com.android.systemui.keyguard;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.content.Context;
import android.graphics.Matrix;
import android.util.Log;
import android.view.RemoteAnimationTarget;
import android.view.SyncRtSurfaceTransactionApplier;
import android.view.View;
import androidx.annotation.VisibleForTesting;
import androidx.core.math.MathUtils;
import com.android.internal.R;
import com.android.keyguard.KeyguardClockSwitchController;
import com.android.keyguard.KeyguardViewController;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.shared.system.smartspace.SmartspaceTransitionController;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import dagger.Lazy;
import javax.inject.Inject;

/**
 * Initiates, controls, and ends the keyguard unlock animation.
 *
 * The unlock animation transitions between the keyguard (lock screen) and the app/launcher surface
 * behind the keyguard. If the user is swiping away the keyguard, this controller will decide when
 * to animate in the surface, and synchronize its appearance with the swipe gesture. If the keyguard
 * is animating away via a canned animation (due to biometric unlock, tapping a notification, etc.)
 * this controller will play a canned animation on the surface as well.
 *
 * The surface behind the keyguard is manipulated via a RemoteAnimation passed to
 * [notifyStartKeyguardExitAnimation] by [KeyguardViewMediator].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000z\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0002\b\u0011\b\u0007\u0018\u00002\u00020\u0001BE\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\u0002\u0010\u0011J\b\u00103\u001a\u000204H\u0002J\b\u00105\u001a\u000204H\u0002J\b\u00106\u001a\u000204H\u0002J\u0006\u00107\u001a\u000204J\u0006\u00108\u001a\u00020\u0013J\u0006\u00109\u001a\u000204J\u0006\u0010:\u001a\u000204J\u001e\u0010;\u001a\u0002042\u0006\u0010<\u001a\u00020*2\u0006\u0010=\u001a\u00020(2\u0006\u0010>\u001a\u00020\u0013J\b\u0010?\u001a\u000204H\u0016J\u000e\u0010@\u001a\u0002042\u0006\u0010A\u001a\u00020\u001bJ\b\u0010B\u001a\u000204H\u0002J\u0006\u0010C\u001a\u000204J\b\u0010D\u001a\u000204H\u0002J\b\u0010E\u001a\u000204H\u0002R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0016\u0010\u0017\"\u0004\b\u0018\u0010\u0019R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u001d\u001a\n \u001f*\u0004\u0018\u00010\u001e0\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R$\u0010 \u001a\n \u001f*\u0004\u0018\u00010\u001e0\u001e8\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b!\u0010\"\u001a\u0004\b#\u0010$R\u000e\u0010%\u001a\u00020&X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020(X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010)\u001a\u0004\u0018\u00010*X\u0082\u000e\u00a2\u0006\u0002\n\u0000R&\u0010+\u001a\u0004\u0018\u00010,8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b-\u0010\"\u001a\u0004\b.\u0010/\"\u0004\b0\u00101R\u000e\u00102\u001a\u00020\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/keyguard/KeyguardUnlockAnimationController;", "Lcom/android/systemui/statusbar/policy/KeyguardStateController$Callback;", "context", "Landroid/content/Context;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "keyguardViewMediator", "Ldagger/Lazy;", "Lcom/android/systemui/keyguard/KeyguardViewMediator;", "keyguardViewController", "Lcom/android/keyguard/KeyguardViewController;", "smartspaceTransitionController", "Lcom/android/systemui/shared/system/smartspace/SmartspaceTransitionController;", "featureFlags", "Lcom/android/systemui/flags/FeatureFlags;", "biometricUnlockController", "Lcom/android/systemui/statusbar/phone/BiometricUnlockController;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Ldagger/Lazy;Lcom/android/keyguard/KeyguardViewController;Lcom/android/systemui/shared/system/smartspace/SmartspaceTransitionController;Lcom/android/systemui/flags/FeatureFlags;Lcom/android/systemui/statusbar/phone/BiometricUnlockController;)V", "attemptedSmartSpaceTransitionForThisSwipe", "", "lockscreenSmartSpace", "Landroid/view/View;", "getLockscreenSmartSpace", "()Landroid/view/View;", "setLockscreenSmartSpace", "(Landroid/view/View;)V", "roundedCornerRadius", "", "surfaceBehindAlpha", "surfaceBehindAlphaAnimator", "Landroid/animation/ValueAnimator;", "kotlin.jvm.PlatformType", "surfaceBehindEntryAnimator", "getSurfaceBehindEntryAnimator$annotations", "()V", "getSurfaceBehindEntryAnimator", "()Landroid/animation/ValueAnimator;", "surfaceBehindMatrix", "Landroid/graphics/Matrix;", "surfaceBehindRemoteAnimationStartTime", "", "surfaceBehindRemoteAnimationTarget", "Landroid/view/RemoteAnimationTarget;", "surfaceTransactionApplier", "Landroid/view/SyncRtSurfaceTransactionApplier;", "getSurfaceTransactionApplier$annotations", "getSurfaceTransactionApplier", "()Landroid/view/SyncRtSurfaceTransactionApplier;", "setSurfaceTransactionApplier", "(Landroid/view/SyncRtSurfaceTransactionApplier;)V", "unlockingWithSmartSpaceTransition", "fadeInSurfaceBehind", "", "fadeOutSurfaceBehind", "finishKeyguardExitRemoteAnimationIfReachThreshold", "hideKeyguardViewAfterRemoteAnimation", "isUnlockingWithSmartSpaceTransition", "notifyCancelKeyguardExitAnimation", "notifyFinishedKeyguardExitAnimation", "notifyStartKeyguardExitAnimation", "target", "startTime", "requestedShowSurfaceBehindKeyguard", "onKeyguardDismissAmountChanged", "setSurfaceBehindAppearAmount", "amount", "updateKeyguardViewMediatorIfThresholdsReached", "updateLockscreenSmartSpacePosition", "updateSmartSpaceTransition", "updateSurfaceBehindAppearAmount"})
@com.android.systemui.dagger.SysUISingleton()
public final class KeyguardUnlockAnimationController implements com.android.systemui.statusbar.policy.KeyguardStateController.Callback {
    
    /**
     * Information used to start, run, and finish a RemoteAnimation on the app or launcher surface
     * behind the keyguard.
     *
     * If we're swiping to unlock, the "animation" is controlled via the gesture, tied to the
     * dismiss amounts received in [onKeyguardDismissAmountChanged]. It does not have a fixed
     * duration, and it ends when the gesture reaches a certain threshold or is cancelled.
     *
     * If we're unlocking via biometrics, PIN entry, or from clicking a notification, a canned
     * animation is started in [notifyStartKeyguardExitAnimation].
     */
    @org.jetbrains.annotations.Nullable()
    private android.view.SyncRtSurfaceTransactionApplier surfaceTransactionApplier;
    private android.view.RemoteAnimationTarget surfaceBehindRemoteAnimationTarget;
    private long surfaceBehindRemoteAnimationStartTime = 0L;
    
    /**
     * Alpha value applied to [surfaceBehindRemoteAnimationTarget], which is the surface of the
     * app/launcher behind the keyguard.
     *
     * If we're doing a swipe gesture, we fade in the surface when the swipe passes a certain
     * threshold. If we're doing a canned animation, it'll be faded in while a translate/scale
     * animation plays.
     */
    private float surfaceBehindAlpha = 1.0F;
    private android.animation.ValueAnimator surfaceBehindAlphaAnimator;
    
    /**
     * Matrix applied to [surfaceBehindRemoteAnimationTarget], which is the surface of the
     * app/launcher behind the keyguard.
     *
     * This is used during the unlock animation/swipe gesture to scale and translate the surface.
     */
    private final android.graphics.Matrix surfaceBehindMatrix = null;
    
    /**
     * Animator that animates in the surface behind the keyguard. This is used to play a canned
     * animation on the surface, if we're not doing a swipe gesture.
     */
    private final android.animation.ValueAnimator surfaceBehindEntryAnimator = null;
    
    /**
     * Rounded corner radius to apply to the surface behind the keyguard.
     */
    private float roundedCornerRadius = 0.0F;
    
    /**
     * The SmartSpace view on the lockscreen, provided by [KeyguardClockSwitchController].
     */
    @org.jetbrains.annotations.Nullable()
    private android.view.View lockscreenSmartSpace;
    
    /**
     * Whether we are currently in the process of unlocking the keyguard, and we are performing the
     * shared element SmartSpace transition.
     */
    private boolean unlockingWithSmartSpaceTransition = false;
    
    /**
     * Whether we tried to start the SmartSpace shared element transition for this unlock swipe.
     * It's possible we're unable to do so (if the Launcher SmartSpace is not available).
     */
    private boolean attemptedSmartSpaceTransitionForThisSwipe = false;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private final dagger.Lazy<com.android.systemui.keyguard.KeyguardViewMediator> keyguardViewMediator = null;
    private final com.android.keyguard.KeyguardViewController keyguardViewController = null;
    private final com.android.systemui.shared.system.smartspace.SmartspaceTransitionController smartspaceTransitionController = null;
    private final com.android.systemui.flags.FeatureFlags featureFlags = null;
    private final com.android.systemui.statusbar.phone.BiometricUnlockController biometricUnlockController = null;
    
    /**
     * Information used to start, run, and finish a RemoteAnimation on the app or launcher surface
     * behind the keyguard.
     *
     * If we're swiping to unlock, the "animation" is controlled via the gesture, tied to the
     * dismiss amounts received in [onKeyguardDismissAmountChanged]. It does not have a fixed
     * duration, and it ends when the gesture reaches a certain threshold or is cancelled.
     *
     * If we're unlocking via biometrics, PIN entry, or from clicking a notification, a canned
     * animation is started in [notifyStartKeyguardExitAnimation].
     */
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getSurfaceTransactionApplier$annotations() {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.view.SyncRtSurfaceTransactionApplier getSurfaceTransactionApplier() {
        return null;
    }
    
    public final void setSurfaceTransactionApplier(@org.jetbrains.annotations.Nullable()
    android.view.SyncRtSurfaceTransactionApplier p0) {
    }
    
    /**
     * Animator that animates in the surface behind the keyguard. This is used to play a canned
     * animation on the surface, if we're not doing a swipe gesture.
     */
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getSurfaceBehindEntryAnimator$annotations() {
    }
    
    public final android.animation.ValueAnimator getSurfaceBehindEntryAnimator() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.view.View getLockscreenSmartSpace() {
        return null;
    }
    
    public final void setLockscreenSmartSpace(@org.jetbrains.annotations.Nullable()
    android.view.View p0) {
    }
    
    /**
     * Called from [KeyguardViewMediator] to tell us that the RemoteAnimation on the surface behind
     * the keyguard has started successfully. We can use these parameters to directly manipulate the
     * surface for the unlock gesture/animation.
     *
     * When we're done with it, we'll call [KeyguardViewMediator.finishSurfaceBehindRemoteAnimation]
     * to end the RemoteAnimation.
     *
     * [requestedShowSurfaceBehindKeyguard] denotes whether the exit animation started because of a
     * call to [KeyguardViewMediator.showSurfaceBehindKeyguard], as happens during a swipe gesture,
     * as opposed to the keyguard hiding.
     */
    public final void notifyStartKeyguardExitAnimation(@org.jetbrains.annotations.NotNull()
    android.view.RemoteAnimationTarget target, long startTime, boolean requestedShowSurfaceBehindKeyguard) {
    }
    
    public final void notifyCancelKeyguardExitAnimation() {
    }
    
    public final void notifyFinishedKeyguardExitAnimation() {
    }
    
    public final void hideKeyguardViewAfterRemoteAnimation() {
    }
    
    /**
     * Whether we are currently in the process of unlocking the keyguard, and we are performing the
     * shared element SmartSpace transition.
     */
    public final boolean isUnlockingWithSmartSpaceTransition() {
        return false;
    }
    
    /**
     * Update the lockscreen SmartSpace to be positioned according to the current dismiss amount. As
     * the dismiss amount increases, we will increase our SmartSpace's progress to the destination
     * bounds (the location of the Launcher SmartSpace).
     */
    public final void updateLockscreenSmartSpacePosition() {
    }
    
    /**
     * Scales in and translates up the surface behind the keyguard. This is used during unlock
     * animations and swipe gestures to animate the surface's entry (and exit, if the swipe is
     * cancelled).
     */
    public final void setSurfaceBehindAppearAmount(float amount) {
    }
    
    /**
     * Sets the appearance amount of the surface behind the keyguard, according to the current
     * keyguard dismiss amount and the method of dismissal.
     */
    private final void updateSurfaceBehindAppearAmount() {
    }
    
    @java.lang.Override()
    public void onKeyguardDismissAmountChanged() {
    }
    
    /**
     * Lets the KeyguardViewMediator know if the dismiss amount has crossed a threshold of interest,
     * such as reaching the point in the dismiss swipe where we need to make the surface behind the
     * keyguard visible.
     */
    private final void updateKeyguardViewMediatorIfThresholdsReached() {
    }
    
    /**
     * Hides the keyguard if we're fully dismissed, or if we're swiping to dismiss and have crossed
     * the threshold to finish the dismissal.
     */
    private final void finishKeyguardExitRemoteAnimationIfReachThreshold() {
    }
    
    /**
     * Updates flags related to the SmartSpace transition in response to a change in keyguard
     * dismiss amount, and also updates the SmartSpaceTransitionController, which will let Launcher
     * know if it needs to do something as a result.
     */
    private final void updateSmartSpaceTransition() {
    }
    
    private final void fadeInSurfaceBehind() {
    }
    
    private final void fadeOutSurfaceBehind() {
    }
    
    @javax.inject.Inject()
    public KeyguardUnlockAnimationController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.keyguard.KeyguardViewMediator> keyguardViewMediator, @org.jetbrains.annotations.NotNull()
    com.android.keyguard.KeyguardViewController keyguardViewController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.shared.system.smartspace.SmartspaceTransitionController smartspaceTransitionController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.flags.FeatureFlags featureFlags, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.BiometricUnlockController biometricUnlockController) {
        super();
    }
}
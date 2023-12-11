package com.android.systemui.media;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.annotation.IntDef;
import android.content.Context;
import android.content.res.Configuration;
import android.graphics.Rect;
import android.util.MathUtils;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewGroupOverlay;
import androidx.annotation.VisibleForTesting;
import com.android.keyguard.KeyguardViewController;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.CrossFadeHelper;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.notification.stack.StackStateAnimator;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.Utils;
import com.android.systemui.util.animation.UniqueObjectHostView;
import javax.inject.Inject;

/**
 * This manager is responsible for placement of the unique media view between the different hosts
 * and animate the positions of the views to achieve seamless transitions.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00aa\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\r\n\u0002\u0010\b\n\u0002\b\u0018\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\b\u000b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\r\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\t\n\u0002\b!\b\u0007\u0018\u0000 \u0090\u00012\u00020\u0001:\u0002\u0090\u0001BO\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u00a2\u0006\u0002\u0010\u0014J\u0018\u0010]\u001a\u00020^2\u0006\u00104\u001a\u00020,2\u0006\u0010L\u001a\u00020,H\u0002J\"\u0010_\u001a\u00020^2\u0006\u0010`\u001a\u00020\u001b2\u0006\u0010a\u001a\u00020\u00162\b\b\u0002\u0010b\u001a\u00020\u0018H\u0002J\b\u0010c\u001a\u00020^H\u0002J\u0018\u0010d\u001a\u00020\u00162\u0006\u0010e\u001a\u00020\u00162\u0006\u0010f\u001a\u00020\u0018H\u0002J\b\u0010g\u001a\u00020,H\u0002J\b\u0010h\u001a\u00020,H\u0007J\b\u0010i\u001a\u00020^H\u0002J\u0006\u0010j\u001a\u00020^J\b\u0010k\u001a\u00020lH\u0002J$\u0010m\u001a\u000e\u0012\u0004\u0012\u00020o\u0012\u0004\u0012\u00020o0n2\u0006\u0010L\u001a\u00020,2\u0006\u00104\u001a\u00020,H\u0002J\u0012\u0010p\u001a\u0004\u0018\u00010J2\u0006\u0010q\u001a\u00020,H\u0002J\b\u0010r\u001a\u00020\u0016H\u0002J\b\u0010s\u001a\u00020\u0016H\u0002J,\u0010t\u001a\u00020\u001b2\u0006\u0010u\u001a\u00020\u001b2\u0006\u0010v\u001a\u00020\u001b2\u0006\u0010w\u001a\u00020\u00162\n\b\u0002\u0010x\u001a\u0004\u0018\u00010\u001bH\u0002J\b\u0010y\u001a\u00020\u0018H\u0002J\b\u0010z\u001a\u00020\u0018H\u0002J\b\u0010{\u001a\u00020\u0018H\u0002J\b\u0010|\u001a\u00020\u0018H\u0002J\b\u0010}\u001a\u00020\u0018H\u0002J\b\u0010~\u001a\u00020\u0018H\u0002J\b\u0010\u007f\u001a\u00020\u0018H\u0002J\t\u0010\u0080\u0001\u001a\u00020\u0018H\u0002J\u001b\u0010\u0081\u0001\u001a\u00020^2\u0007\u0010\u0082\u0001\u001a\u00020\u00182\u0007\u0010\u0083\u0001\u001a\u00020\u0018H\u0002J\u0010\u0010\u0084\u0001\u001a\u00020l2\u0007\u0010\u0085\u0001\u001a\u00020JJ\t\u0010\u0086\u0001\u001a\u00020,H\u0002J\u000f\u0010\u0087\u0001\u001a\u00020^2\u0006\u0010#\u001a\u00020\u0016J\u001a\u0010\u0088\u0001\u001a\u00020\u00182\u0007\u0010\u0089\u0001\u001a\u00020,2\u0006\u0010L\u001a\u00020,H\u0002J\t\u0010\u008a\u0001\u001a\u00020^H\u0002J\u001f\u0010\u008b\u0001\u001a\u00020^2\t\b\u0002\u0010\u008c\u0001\u001a\u00020\u00182\t\b\u0002\u0010\u008d\u0001\u001a\u00020\u0018H\u0002J\t\u0010\u008e\u0001\u001a\u00020^H\u0002J\t\u0010\u008f\u0001\u001a\u00020^H\u0002R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u001d\u001a\n \u001f*\u0004\u0018\u00010\u001e0\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010 \u001a\u00020\u00188BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b!\u0010\"R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010$\u001a\u00020\u00162\u0006\u0010#\u001a\u00020\u0016@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b%\u0010&R$\u0010\'\u001a\u00020\u00182\u0006\u0010#\u001a\u00020\u0018@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b(\u0010\"\"\u0004\b)\u0010*R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010+\u001a\u00020,X\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\b-\u0010.R\u0014\u0010/\u001a\u00020,X\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\b0\u0010.R\u0014\u00101\u001a\u00020,X\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\b2\u0010.R\u000e\u00103\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u00104\u001a\u00020,X\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\b5\u0010.R\u000e\u00106\u001a\u00020,X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u00107\u001a\u00020\u00182\u0006\u0010#\u001a\u00020\u0018@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b8\u0010*R\u001e\u00109\u001a\u00020\u00162\u0006\u0010#\u001a\u00020\u0016@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b:\u0010&R\u001e\u0010;\u001a\u00020\u00182\u0006\u0010#\u001a\u00020\u0018@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b<\u0010*R\u001e\u0010=\u001a\u00020\u00182\u0006\u0010#\u001a\u00020\u0018@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b>\u0010*R\u0016\u0010?\u001a\u00020\u00188BX\u0082\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b@\u0010\"R\u000e\u0010A\u001a\u00020\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010B\u001a\u00020\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010C\u001a\u00020\u00188BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\bC\u0010\"R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010D\u001a\u00020E8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\bF\u0010GR\u0018\u0010H\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010J0IX\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010KR\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010L\u001a\u00020,X\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\bM\u0010.R$\u0010N\u001a\u00020\u00182\u0006\u0010#\u001a\u00020\u0018@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bO\u0010\"\"\u0004\bP\u0010*R$\u0010Q\u001a\u00020\u00162\u0006\u0010#\u001a\u00020\u0016@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bR\u0010S\"\u0004\bT\u0010&R\u0010\u0010U\u001a\u0004\u0018\u00010VX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010W\u001a\u0004\u0018\u00010XX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010Y\u001a\u00020ZX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010[\u001a\u00020,X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\\\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaHierarchyManager;", "", "context", "Landroid/content/Context;", "statusBarStateController", "Lcom/android/systemui/statusbar/SysuiStatusBarStateController;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "bypassController", "Lcom/android/systemui/statusbar/phone/KeyguardBypassController;", "mediaCarouselController", "Lcom/android/systemui/media/MediaCarouselController;", "notifLockscreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "wakefulnessLifecycle", "Lcom/android/systemui/keyguard/WakefulnessLifecycle;", "keyguardViewController", "Lcom/android/keyguard/KeyguardViewController;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/SysuiStatusBarStateController;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Lcom/android/systemui/statusbar/phone/KeyguardBypassController;Lcom/android/systemui/media/MediaCarouselController;Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/keyguard/WakefulnessLifecycle;Lcom/android/keyguard/KeyguardViewController;)V", "animationCrossFadeProgress", "", "animationPending", "", "animationStartAlpha", "animationStartBounds", "Landroid/graphics/Rect;", "animationStartCrossFadeProgress", "animator", "Landroid/animation/ValueAnimator;", "kotlin.jvm.PlatformType", "blockLocationChanges", "getBlockLocationChanges", "()Z", "value", "carouselAlpha", "setCarouselAlpha", "(F)V", "collapsingShadeFromQS", "getCollapsingShadeFromQS", "setCollapsingShadeFromQS", "(Z)V", "crossFadeAnimationEndLocation", "", "getCrossFadeAnimationEndLocation$annotations", "()V", "crossFadeAnimationStartLocation", "getCrossFadeAnimationStartLocation$annotations", "currentAttachmentLocation", "getCurrentAttachmentLocation$annotations", "currentBounds", "desiredLocation", "getDesiredLocation$annotations", "distanceForFullShadeTransition", "dozeAnimationRunning", "setDozeAnimationRunning", "fullShadeTransitionProgress", "setFullShadeTransitionProgress", "fullyAwake", "setFullyAwake", "goingToSleep", "setGoingToSleep", "hasActiveMedia", "getHasActiveMedia", "inSplitShade", "isCrossFadeAnimatorRunning", "isTransitioningToFullShade", "mediaFrame", "Landroid/view/ViewGroup;", "getMediaFrame", "()Landroid/view/ViewGroup;", "mediaHosts", "", "Lcom/android/systemui/media/MediaHost;", "[Lcom/android/systemui/media/MediaHost;", "previousLocation", "getPreviousLocation$annotations", "qsExpanded", "getQsExpanded", "setQsExpanded", "qsExpansion", "getQsExpansion", "()F", "setQsExpansion", "rootOverlay", "Landroid/view/ViewGroupOverlay;", "rootView", "Landroid/view/View;", "startAnimation", "Ljava/lang/Runnable;", "statusbarState", "targetBounds", "adjustAnimatorForTransition", "", "applyState", "bounds", "alpha", "immediately", "applyTargetStateIfNotAnimating", "calculateAlphaFromCrossFade", "crossFadeProgress", "instantlyShowAtEnd", "calculateLocation", "calculateTransformationType", "cancelAnimationAndApplyDesiredState", "closeGuts", "createUniqueObjectHost", "Lcom/android/systemui/util/animation/UniqueObjectHostView;", "getAnimationParams", "Lkotlin/Pair;", "", "getHost", "location", "getQSTransformationProgress", "getTransformationProgress", "interpolateBounds", "startBounds", "endBounds", "progress", "result", "isCurrentlyFading", "isCurrentlyInGuidedTransformation", "isHomeScreenShadeVisibleToUser", "isLockScreenShadeVisibleToUser", "isLockScreenVisibleToUser", "isTransformingToFullShadeAndInQQS", "isTransitionRunning", "isVisibleToUser", "performTransitionToNewLocation", "isNewView", "animate", "register", "mediaObject", "resolveLocationForFading", "setTransitionToFullShadeAmount", "shouldAnimateTransition", "currentLocation", "updateConfiguration", "updateDesiredLocation", "forceNoAnimation", "forceStateUpdate", "updateHostAttachment", "updateTargetState", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class MediaHierarchyManager {
    
    /**
     * The root overlay of the hierarchy. This is where the media notification is attached to
     * whenever the view is transitioning from one host to another. It also make sure that the
     * view is always in its final state when it is attached to a view host.
     */
    private android.view.ViewGroupOverlay rootOverlay;
    private android.view.View rootView;
    private android.graphics.Rect currentBounds;
    private android.graphics.Rect animationStartBounds;
    
    /**
     * The cross fade progress at the start of the animation. 0.5f means it's just switching between
     * the start and the end location and the content is fully faded, while 0.75f means that we're
     * halfway faded in again in the target state.
     */
    private float animationStartCrossFadeProgress = 0.0F;
    
    /**
     * The starting alpha of the animation
     */
    private float animationStartAlpha = 0.0F;
    
    /**
     * The starting location of the cross fade if an animation is running right now.
     */
    private int crossFadeAnimationStartLocation = -1;
    
    /**
     * The end location of the cross fade if an animation is running right now.
     */
    private int crossFadeAnimationEndLocation = -1;
    private android.graphics.Rect targetBounds;
    private int statusbarState;
    private android.animation.ValueAnimator animator;
    private final com.android.systemui.media.MediaHost[] mediaHosts = null;
    
    /**
     * The last location where this view was at before going to the desired location. This is
     * useful for guided transitions.
     */
    private int previousLocation = -1;
    
    /**
     * The desired location where the view will be at the end of the transition.
     */
    private int desiredLocation = -1;
    
    /**
     * The current attachment location where the view is currently attached.
     * Usually this matches the desired location except for animations whenever a view moves
     * to the new desired location, during which it is in [IN_OVERLAY].
     */
    private int currentAttachmentLocation = -1;
    private boolean inSplitShade = false;
    
    /**
     * Is there any active media in the carousel?
     */
    private boolean hasActiveMedia = false;
    
    /**
     * Are we currently waiting on an animation to start?
     */
    private boolean animationPending = false;
    private final java.lang.Runnable startAnimation = null;
    
    /**
     * The expansion of quick settings
     */
    private float qsExpansion = 0.0F;
    
    /**
     * Is quick setting expanded?
     */
    private boolean qsExpanded = false;
    
    /**
     * distance that the full shade transition takes in order for media to fully transition to the
     * shade
     */
    private int distanceForFullShadeTransition = 0;
    
    /**
     * The amount of progress we are currently in if we're transitioning to the full shade.
     * 0.0f means we're not transitioning yet, while 1 means we're all the way in the full
     * shade.
     */
    private float fullShadeTransitionProgress = 0.0F;
    
    /**
     * Is there currently a cross-fade animation running driven by an animator?
     */
    private boolean isCrossFadeAnimatorRunning = false;
    
    /**
     * Is the shade currently collapsing from the expanded qs? If we're on the lockscreen and in qs,
     * we wouldn't want to transition in that case.
     */
    private boolean collapsingShadeFromQS = false;
    
    /**
     * Are we currently going to sleep
     */
    private boolean goingToSleep = false;
    
    /**
     * Are we currently fullyAwake
     */
    private boolean fullyAwake = false;
    
    /**
     * Is the doze animation currently Running
     */
    private boolean dozeAnimationRunning = false;
    
    /**
     * The current cross fade progress. 0.5f means it's just switching
     * between the start and the end location and the content is fully faded, while 0.75f means
     * that we're halfway faded in again in the target state.
     * This is only valid while [isCrossFadeAnimatorRunning] is true.
     */
    private float animationCrossFadeProgress = 1.0F;
    
    /**
     * The current carousel Alpha.
     */
    private float carouselAlpha = 1.0F;
    private final android.content.Context context = null;
    private final com.android.systemui.statusbar.SysuiStatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private final com.android.systemui.statusbar.phone.KeyguardBypassController bypassController = null;
    private final com.android.systemui.media.MediaCarouselController mediaCarouselController = null;
    private final com.android.systemui.statusbar.NotificationLockscreenUserManager notifLockscreenUserManager = null;
    private final com.android.keyguard.KeyguardViewController keyguardViewController = null;
    
    /**
     * Attached in expanded quick settings
     */
    public static final int LOCATION_QS = 0;
    
    /**
     * Attached in the collapsed QS
     */
    public static final int LOCATION_QQS = 1;
    
    /**
     * Attached on the lock screen
     */
    public static final int LOCATION_LOCKSCREEN = 2;
    
    /**
     * Attached at the root of the hierarchy in an overlay
     */
    public static final int IN_OVERLAY = -1000;
    
    /**
     * The default transformation type where the hosts transform into each other using a direct
     * transition
     */
    public static final int TRANSFORMATION_TYPE_TRANSITION = 0;
    
    /**
     * A transformation type where content fades from one place to another instead of
     * transitioning
     */
    public static final int TRANSFORMATION_TYPE_FADE = 1;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.MediaHierarchyManager.Companion Companion = null;
    
    /**
     * The starting location of the cross fade if an animation is running right now.
     */
    @MediaLocation()
    @java.lang.Deprecated()
    private static void getCrossFadeAnimationStartLocation$annotations() {
    }
    
    /**
     * The end location of the cross fade if an animation is running right now.
     */
    @MediaLocation()
    @java.lang.Deprecated()
    private static void getCrossFadeAnimationEndLocation$annotations() {
    }
    
    private final android.view.ViewGroup getMediaFrame() {
        return null;
    }
    
    /**
     * The last location where this view was at before going to the desired location. This is
     * useful for guided transitions.
     */
    @MediaLocation()
    @java.lang.Deprecated()
    private static void getPreviousLocation$annotations() {
    }
    
    /**
     * The desired location where the view will be at the end of the transition.
     */
    @MediaLocation()
    @java.lang.Deprecated()
    private static void getDesiredLocation$annotations() {
    }
    
    /**
     * The current attachment location where the view is currently attached.
     * Usually this matches the desired location except for animations whenever a view moves
     * to the new desired location, during which it is in [IN_OVERLAY].
     */
    @MediaLocation()
    @java.lang.Deprecated()
    private static void getCurrentAttachmentLocation$annotations() {
    }
    
    private final boolean getHasActiveMedia() {
        return false;
    }
    
    public final float getQsExpansion() {
        return 0.0F;
    }
    
    public final void setQsExpansion(float value) {
    }
    
    public final boolean getQsExpanded() {
        return false;
    }
    
    public final void setQsExpanded(boolean value) {
    }
    
    private final void setFullShadeTransitionProgress(float value) {
    }
    
    private final boolean isTransitioningToFullShade() {
        return false;
    }
    
    /**
     * Set the amount of pixels we have currently dragged down if we're transitioning to the full
     * shade. 0.0f means we're not transitioning yet.
     */
    public final void setTransitionToFullShadeAmount(float value) {
    }
    
    public final boolean getCollapsingShadeFromQS() {
        return false;
    }
    
    public final void setCollapsingShadeFromQS(boolean value) {
    }
    
    private final boolean getBlockLocationChanges() {
        return false;
    }
    
    private final void setGoingToSleep(boolean value) {
    }
    
    private final void setFullyAwake(boolean value) {
    }
    
    private final void setDozeAnimationRunning(boolean value) {
    }
    
    private final void setCarouselAlpha(float value) {
    }
    
    /**
     * Calculate the alpha of the view when given a cross-fade progress.
     *
     * @param crossFadeProgress The current cross fade progress. 0.5f means it's just switching
     * between the start and the end location and the content is fully faded, while 0.75f means
     * that we're halfway faded in again in the target state.
     *
     * @param instantlyShowAtEnd should the view be instantly shown at the end. This is needed
     * to avoid fadinging in when the target was hidden anyway.
     */
    private final float calculateAlphaFromCrossFade(float crossFadeProgress, boolean instantlyShowAtEnd) {
        return 0.0F;
    }
    
    private final void updateConfiguration() {
    }
    
    /**
     * Register a media host and create a view can be attached to a view hierarchy
     * and where the players will be placed in when the host is the currently desired state.
     *
     * @return the hostView associated with this location
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.UniqueObjectHostView register(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHost mediaObject) {
        return null;
    }
    
    /**
     * Close the guts in all players in [MediaCarouselController].
     */
    public final void closeGuts() {
    }
    
    private final com.android.systemui.util.animation.UniqueObjectHostView createUniqueObjectHost() {
        return null;
    }
    
    /**
     * Updates the location that the view should be in. If it changes, an animation may be triggered
     * going from the old desired location to the new one.
     *
     * @param forceNoAnimation optional parameter telling the system not to animate
     * @param forceStateUpdate optional parameter telling the system to update transition state
     *                        even if location did not change
     */
    private final void updateDesiredLocation(boolean forceNoAnimation, boolean forceStateUpdate) {
    }
    
    private final void performTransitionToNewLocation(boolean isNewView, boolean animate) {
    }
    
    private final boolean shouldAnimateTransition(@MediaLocation()
    int currentLocation, @MediaLocation()
    int previousLocation) {
        return false;
    }
    
    private final void adjustAnimatorForTransition(int desiredLocation, int previousLocation) {
    }
    
    private final kotlin.Pair<java.lang.Long, java.lang.Long> getAnimationParams(int previousLocation, int desiredLocation) {
        return null;
    }
    
    private final void applyTargetStateIfNotAnimating() {
    }
    
    /**
     * Updates the bounds that the view wants to be in at the end of the animation.
     */
    private final void updateTargetState() {
    }
    
    private final android.graphics.Rect interpolateBounds(android.graphics.Rect startBounds, android.graphics.Rect endBounds, float progress, android.graphics.Rect result) {
        return null;
    }
    
    /**
     * @return true if this transformation is guided by an external progress like a finger
     */
    private final boolean isCurrentlyInGuidedTransformation() {
        return false;
    }
    
    /**
     * Calculate the transformation type for the current animation
     */
    @TransformationType()
    @androidx.annotation.VisibleForTesting()
    public final int calculateTransformationType() {
        return 0;
    }
    
    /**
     * @return the current transformation progress if we're in a guided transformation and -1
     * otherwise
     */
    private final float getTransformationProgress() {
        return 0.0F;
    }
    
    private final float getQSTransformationProgress() {
        return 0.0F;
    }
    
    private final com.android.systemui.media.MediaHost getHost(@MediaLocation()
    int location) {
        return null;
    }
    
    private final void cancelAnimationAndApplyDesiredState() {
    }
    
    /**
     * Apply the current state to the view, updating it's bounds and desired state
     */
    private final void applyState(android.graphics.Rect bounds, float alpha, boolean immediately) {
    }
    
    private final void updateHostAttachment() {
    }
    
    /**
     * Calculate the location when cross fading between locations. While fading out,
     * the content should remain in the previous location, while after the switch it should
     * be at the desired location.
     */
    private final int resolveLocationForFading() {
        return 0;
    }
    
    private final boolean isTransitionRunning() {
        return false;
    }
    
    @MediaLocation()
    private final int calculateLocation() {
        return 0;
    }
    
    /**
     * Are we currently transforming to the full shade and already in QQS
     */
    private final boolean isTransformingToFullShadeAndInQQS() {
        return false;
    }
    
    /**
     * Is the current transformationType fading
     */
    private final boolean isCurrentlyFading() {
        return false;
    }
    
    /**
     * Returns true when the media card could be visible to the user if existed.
     */
    private final boolean isVisibleToUser() {
        return false;
    }
    
    private final boolean isLockScreenVisibleToUser() {
        return false;
    }
    
    private final boolean isLockScreenShadeVisibleToUser() {
        return false;
    }
    
    private final boolean isHomeScreenShadeVisibleToUser() {
        return false;
    }
    
    @javax.inject.Inject()
    public MediaHierarchyManager(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.SysuiStatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardBypassController bypassController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaCarouselController mediaCarouselController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager notifLockscreenUserManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.keyguard.WakefulnessLifecycle wakefulnessLifecycle, @org.jetbrains.annotations.NotNull()
    com.android.keyguard.KeyguardViewController keyguardViewController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaHierarchyManager$Companion;", "", "()V", "IN_OVERLAY", "", "LOCATION_LOCKSCREEN", "LOCATION_QQS", "LOCATION_QS", "TRANSFORMATION_TYPE_FADE", "TRANSFORMATION_TYPE_TRANSITION"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
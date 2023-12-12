package com.android.systemui.statusbar;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.os.SystemClock;
import android.os.Trace;
import android.util.IndentingPrintWriter;
import android.util.Log;
import android.util.MathUtils;
import android.view.Choreographer;
import android.view.View;
import androidx.annotation.VisibleForTesting;
import androidx.dynamicanimation.animation.FloatPropertyCompat;
import androidx.dynamicanimation.animation.SpringAnimation;
import androidx.dynamicanimation.animation.SpringForce;
import com.android.systemui.Dumpable;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.animation.ShadeInterpolation;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.ScrimController;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionListener;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.WallpaperController;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

/**
 * Controller responsible for statusbar window blur.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00ba\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\r\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0007\n\u0002\u0010\t\n\u0002\b\u0013\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u000f\b\u0007\u0018\u0000 z2\u00020\u00012\u00020\u0002:\u0003z{|BO\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u00a2\u0006\u0002\u0010\u0015J\u000e\u0010`\u001a\u00020a2\u0006\u0010b\u001a\u000205J\u0018\u0010c\u001a\u00020a2\u0006\u0010d\u001a\u00020\u00192\u0006\u0010e\u001a\u000208H\u0002J-\u0010f\u001a\u00020a2\u0006\u0010g\u001a\u00020h2\u0006\u0010i\u001a\u00020j2\u000e\u0010k\u001a\n\u0012\u0006\b\u0001\u0012\u00020m0lH\u0016\u00a2\u0006\u0002\u0010nJ \u0010o\u001a\u00020a2\u0006\u0010p\u001a\u0002082\u0006\u0010q\u001a\u00020\u00192\u0006\u0010r\u001a\u00020\u0019H\u0016J\u000e\u0010s\u001a\u00020a2\u0006\u0010b\u001a\u000205J\u0014\u0010t\u001a\u00020a2\n\b\u0002\u0010u\u001a\u0004\u0018\u00010\u0017H\u0002J\b\u0010v\u001a\u00020\u0019H\u0002J(\u0010w\u001a\u00020a2\u0006\u0010x\u001a\u0002082\u0006\u0010r\u001a\u00020\u00192\u0006\u0010e\u001a\u0002082\u0006\u0010y\u001a\u000202H\u0002R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0016\u001a\u0004\u0018\u00010\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\u001a\u001a\u00020\u00192\u0006\u0010\u0018\u001a\u00020\u0019@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001b\u0010\u001c\"\u0004\b\u001d\u0010\u001eR(\u0010\u001f\u001a\u00060 R\u00020\u00008\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b!\u0010\"\u001a\u0004\b#\u0010$\"\u0004\b%\u0010&R$\u0010\'\u001a\u00020\u00192\u0006\u0010\u0018\u001a\u00020\u0019@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b(\u0010\u001c\"\u0004\b)\u0010\u001eR\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010+\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010,\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010-\u001a\u0004\u0018\u00010.X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010/\u001a\u000200X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00101\u001a\u000202X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u00103\u001a\b\u0012\u0004\u0012\u00020504X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u00106\u001a\u0004\u0018\u00010.X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u00107\u001a\u000208X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b9\u0010:\"\u0004\b;\u0010<R\u000e\u0010=\u001a\u000202X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010>\u001a\u000208X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010?\u001a\u00020@X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010A\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R$\u0010B\u001a\u0002082\u0006\u0010\u0018\u001a\u000208@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bC\u0010:\"\u0004\bD\u0010<R\u001a\u0010E\u001a\u00020\u0017X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\bF\u0010G\"\u0004\bH\u0010IR\u001e\u0010J\u001a\u00020\u00192\u0006\u0010\u0018\u001a\u00020\u0019@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\bK\u0010\u001eR\u001e\u0010L\u001a\u00060 R\u00020\u0000X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bM\u0010$\"\u0004\bN\u0010&R$\u0010O\u001a\u0002088\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\bP\u0010\"\u001a\u0004\bQ\u0010:\"\u0004\bR\u0010<R\u000e\u0010S\u001a\u00020TX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010U\u001a\u0002082\u0006\u0010\u0018\u001a\u000208@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bV\u0010:\"\u0004\bW\u0010<R\u001c\u0010X\u001a\u00020Y8\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\bZ\u0010\"\u001a\u0004\b[\u0010\\R\u000e\u0010]\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010^\u001a\u0002082\u0006\u0010\u0018\u001a\u000208@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b_\u0010<R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/NotificationShadeDepthController;", "Lcom/android/systemui/statusbar/phone/panelstate/PanelExpansionListener;", "Lcom/android/systemui/Dumpable;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "blurUtils", "Lcom/android/systemui/statusbar/BlurUtils;", "biometricUnlockController", "Lcom/android/systemui/statusbar/phone/BiometricUnlockController;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "choreographer", "Landroid/view/Choreographer;", "wallpaperController", "Lcom/android/systemui/util/WallpaperController;", "notificationShadeWindowController", "Lcom/android/systemui/statusbar/NotificationShadeWindowController;", "dozeParameters", "Lcom/android/systemui/statusbar/phone/DozeParameters;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/statusbar/BlurUtils;Lcom/android/systemui/statusbar/phone/BiometricUnlockController;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Landroid/view/Choreographer;Lcom/android/systemui/util/WallpaperController;Lcom/android/systemui/statusbar/NotificationShadeWindowController;Lcom/android/systemui/statusbar/phone/DozeParameters;Lcom/android/systemui/dump/DumpManager;)V", "blurRoot", "Landroid/view/View;", "value", "", "blursDisabledForAppLaunch", "getBlursDisabledForAppLaunch", "()Z", "setBlursDisabledForAppLaunch", "(Z)V", "brightnessMirrorSpring", "Lcom/android/systemui/statusbar/NotificationShadeDepthController$DepthAnimation;", "getBrightnessMirrorSpring$annotations", "()V", "getBrightnessMirrorSpring", "()Lcom/android/systemui/statusbar/NotificationShadeDepthController$DepthAnimation;", "setBrightnessMirrorSpring", "(Lcom/android/systemui/statusbar/NotificationShadeDepthController$DepthAnimation;)V", "brightnessMirrorVisible", "getBrightnessMirrorVisible", "setBrightnessMirrorVisible", "isBlurred", "isClosed", "isOpen", "keyguardAnimator", "Landroid/animation/Animator;", "keyguardStateCallback", "Lcom/android/systemui/statusbar/policy/KeyguardStateController$Callback;", "lastAppliedBlur", "", "listeners", "", "Lcom/android/systemui/statusbar/NotificationShadeDepthController$DepthListener;", "notificationAnimator", "panelPullDownMinFraction", "", "getPanelPullDownMinFraction", "()F", "setPanelPullDownMinFraction", "(F)V", "prevShadeDirection", "prevShadeVelocity", "prevTimestamp", "", "prevTracking", "qsPanelExpansion", "getQsPanelExpansion", "setQsPanelExpansion", "root", "getRoot", "()Landroid/view/View;", "setRoot", "(Landroid/view/View;)V", "scrimsVisible", "setScrimsVisible", "shadeAnimation", "getShadeAnimation", "setShadeAnimation", "shadeExpansion", "getShadeExpansion$annotations", "getShadeExpansion", "setShadeExpansion", "statusBarStateCallback", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController$StateListener;", "transitionToFullShadeProgress", "getTransitionToFullShadeProgress", "setTransitionToFullShadeProgress", "updateBlurCallback", "Landroid/view/Choreographer$FrameCallback;", "getUpdateBlurCallback$annotations", "getUpdateBlurCallback", "()Landroid/view/Choreographer$FrameCallback;", "updateScheduled", "wakeAndUnlockBlurRadius", "setWakeAndUnlockBlurRadius", "addListener", "", "listener", "animateBlur", "blur", "velocity", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "onPanelExpansionChanged", "rawFraction", "expanded", "tracking", "removeListener", "scheduleUpdate", "viewToBlur", "shouldApplyShadeBlur", "updateShadeAnimationBlur", "expansion", "direction", "Companion", "DepthAnimation", "DepthListener"})
@com.android.systemui.dagger.SysUISingleton()
public final class NotificationShadeDepthController implements com.android.systemui.statusbar.phone.panelstate.PanelExpansionListener, com.android.systemui.Dumpable {
    public android.view.View root;
    private android.view.View blurRoot;
    private android.animation.Animator keyguardAnimator;
    private android.animation.Animator notificationAnimator;
    private boolean updateScheduled = false;
    private float shadeExpansion = 0.0F;
    private boolean isClosed = true;
    private boolean isOpen = false;
    private boolean isBlurred = false;
    private java.util.List<com.android.systemui.statusbar.NotificationShadeDepthController.DepthListener> listeners;
    private boolean prevTracking = false;
    private long prevTimestamp = -1L;
    private int prevShadeDirection = 0;
    private float prevShadeVelocity = 0.0F;
    private int lastAppliedBlur = 0;
    private float panelPullDownMinFraction = 0.0F;
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.statusbar.NotificationShadeDepthController.DepthAnimation shadeAnimation;
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.statusbar.NotificationShadeDepthController.DepthAnimation brightnessMirrorSpring;
    private boolean brightnessMirrorVisible = false;
    private float qsPanelExpansion = 0.0F;
    
    /**
     * How much we're transitioning to the full shade
     */
    private float transitionToFullShadeProgress = 0.0F;
    
    /**
     * When launching an app from the shade, the animations progress should affect how blurry the
     * shade is, overriding the expansion amount.
     */
    private boolean blursDisabledForAppLaunch = false;
    
    /**
     * Force stop blur effect when necessary.
     */
    private boolean scrimsVisible = false;
    
    /**
     * Blur radius of the wake-up animation on this frame.
     */
    private float wakeAndUnlockBlurRadius = 0.0F;
    
    /**
     * Callback that updates the window blur value and is called only once per frame.
     */
    @org.jetbrains.annotations.NotNull()
    private final android.view.Choreographer.FrameCallback updateBlurCallback = null;
    
    /**
     * Animate blurs when unlocking.
     */
    private final com.android.systemui.statusbar.policy.KeyguardStateController.Callback keyguardStateCallback = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController.StateListener statusBarStateCallback = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.BlurUtils blurUtils = null;
    private final com.android.systemui.statusbar.phone.BiometricUnlockController biometricUnlockController = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private final android.view.Choreographer choreographer = null;
    private final com.android.systemui.util.WallpaperController wallpaperController = null;
    private final com.android.systemui.statusbar.NotificationShadeWindowController notificationShadeWindowController = null;
    private final com.android.systemui.statusbar.phone.DozeParameters dozeParameters = null;
    private static final boolean WAKE_UP_ANIMATION_ENABLED = true;
    private static final float VELOCITY_SCALE = 100.0F;
    private static final float MAX_VELOCITY = 3000.0F;
    private static final float MIN_VELOCITY = -3000.0F;
    private static final float INTERACTION_BLUR_FRACTION = 0.8F;
    private static final float ANIMATION_BLUR_FRACTION = 0.19999999F;
    private static final java.lang.String TAG = "DepthController";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.NotificationShadeDepthController.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.View getRoot() {
        return null;
    }
    
    public final void setRoot(@org.jetbrains.annotations.NotNull()
    android.view.View p0) {
    }
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getShadeExpansion$annotations() {
    }
    
    public final float getShadeExpansion() {
        return 0.0F;
    }
    
    public final void setShadeExpansion(float p0) {
    }
    
    public final float getPanelPullDownMinFraction() {
        return 0.0F;
    }
    
    public final void setPanelPullDownMinFraction(float p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.NotificationShadeDepthController.DepthAnimation getShadeAnimation() {
        return null;
    }
    
    public final void setShadeAnimation(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationShadeDepthController.DepthAnimation p0) {
    }
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getBrightnessMirrorSpring$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.NotificationShadeDepthController.DepthAnimation getBrightnessMirrorSpring() {
        return null;
    }
    
    public final void setBrightnessMirrorSpring(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationShadeDepthController.DepthAnimation p0) {
    }
    
    public final boolean getBrightnessMirrorVisible() {
        return false;
    }
    
    public final void setBrightnessMirrorVisible(boolean value) {
    }
    
    public final float getQsPanelExpansion() {
        return 0.0F;
    }
    
    public final void setQsPanelExpansion(float value) {
    }
    
    public final float getTransitionToFullShadeProgress() {
        return 0.0F;
    }
    
    public final void setTransitionToFullShadeProgress(float value) {
    }
    
    public final boolean getBlursDisabledForAppLaunch() {
        return false;
    }
    
    public final void setBlursDisabledForAppLaunch(boolean value) {
    }
    
    private final void setScrimsVisible(boolean value) {
    }
    
    private final void setWakeAndUnlockBlurRadius(float value) {
    }
    
    /**
     * Callback that updates the window blur value and is called only once per frame.
     */
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getUpdateBlurCallback$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.Choreographer.FrameCallback getUpdateBlurCallback() {
        return null;
    }
    
    public final void addListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationShadeDepthController.DepthListener listener) {
    }
    
    public final void removeListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationShadeDepthController.DepthListener listener) {
    }
    
    /**
     * Update blurs when pulling down the shade
     */
    @java.lang.Override()
    public void onPanelExpansionChanged(float rawFraction, boolean expanded, boolean tracking) {
    }
    
    private final void updateShadeAnimationBlur(float expansion, boolean tracking, float velocity, int direction) {
    }
    
    private final void animateBlur(boolean blur, float velocity) {
    }
    
    private final void scheduleUpdate(android.view.View viewToBlur) {
    }
    
    /**
     * Should blur be applied to the shade currently. This is mainly used to make sure that
     * on the lockscreen, the wallpaper isn't blurred.
     */
    private final boolean shouldApplyShadeBlur() {
        return false;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public NotificationShadeDepthController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.BlurUtils blurUtils, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.BiometricUnlockController biometricUnlockController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    android.view.Choreographer choreographer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.WallpaperController wallpaperController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationShadeWindowController notificationShadeWindowController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.DozeParameters dozeParameters, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
    
    /**
     * Animation helper that smoothly animates the depth using a spring and deals with frame
     * invalidation.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\t\b\u0086\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u001a\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00042\n\b\u0002\u0010\u0014\u001a\u0004\u0018\u00010\u0010J\u0006\u0010\u0015\u001a\u00020\u0012J\u000e\u0010\u0016\u001a\u00020\u00122\u0006\u0010\u0017\u001a\u00020\u0006J\u000e\u0010\u0018\u001a\u00020\u00122\u0006\u0010\u0019\u001a\u00020\u0006J\u000e\u0010\u001a\u001a\u00020\u00122\u0006\u0010\u001b\u001a\u00020\u0006R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0005\u001a\u00020\u0006X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0007\u0010\b\"\u0004\b\t\u0010\nR\u0011\u0010\u000b\u001a\u00020\u00068F\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\bR\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000f\u001a\u0004\u0018\u00010\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/NotificationShadeDepthController$DepthAnimation;", "", "(Lcom/android/systemui/statusbar/NotificationShadeDepthController;)V", "pendingRadius", "", "radius", "", "getRadius", "()F", "setRadius", "(F)V", "ratio", "getRatio", "springAnimation", "Landroidx/dynamicanimation/animation/SpringAnimation;", "view", "Landroid/view/View;", "animateTo", "", "newRadius", "viewToBlur", "finishIfRunning", "setDampingRatio", "dampingRation", "setStartVelocity", "velocity", "setStiffness", "stiffness"})
    public final class DepthAnimation {
        
        /**
         * Blur radius visible on the UI, in pixels.
         */
        private float radius = 0.0F;
        
        /**
         * Radius that we're animating to.
         */
        private int pendingRadius = -1;
        
        /**
         * View on {@link Surface} that wants depth.
         */
        private android.view.View view;
        private androidx.dynamicanimation.animation.SpringAnimation springAnimation;
        
        public final float getRadius() {
            return 0.0F;
        }
        
        public final void setRadius(float p0) {
        }
        
        public final float getRatio() {
            return 0.0F;
        }
        
        public final void animateTo(int newRadius, @org.jetbrains.annotations.Nullable()
        android.view.View viewToBlur) {
        }
        
        public final void finishIfRunning() {
        }
        
        public final void setStiffness(float stiffness) {
        }
        
        public final void setDampingRatio(float dampingRation) {
        }
        
        public final void setStartVelocity(float velocity) {
        }
        
        public DepthAnimation() {
            super();
        }
    }
    
    /**
     * Invoked when changes are needed in z-space
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0007\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\u0017J\u0010\u0010\u0006\u001a\u00020\u00032\u0006\u0010\u0007\u001a\u00020\bH&\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/statusbar/NotificationShadeDepthController$DepthListener;", "", "onBlurRadiusChanged", "", "blurRadius", "", "onWallpaperZoomOutChanged", "zoomOut", ""})
    public static abstract interface DepthListener {
        
        /**
         * Current wallpaper zoom out, where 0 is the closest, and 1 the farthest
         */
        public abstract void onWallpaperZoomOutChanged(float zoomOut);
        
        public default void onBlurRadiusChanged(int blurRadius) {
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0004\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/NotificationShadeDepthController$Companion;", "", "()V", "ANIMATION_BLUR_FRACTION", "", "INTERACTION_BLUR_FRACTION", "MAX_VELOCITY", "MIN_VELOCITY", "TAG", "", "VELOCITY_SCALE", "WAKE_UP_ANIMATION_ENABLED", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
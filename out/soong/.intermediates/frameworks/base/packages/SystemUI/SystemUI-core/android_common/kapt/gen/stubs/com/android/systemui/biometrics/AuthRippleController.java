package com.android.systemui.biometrics;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.content.Context;
import android.graphics.PointF;
import android.hardware.biometrics.BiometricSourceType;
import android.util.DisplayMetrics;
import android.util.Log;
import androidx.annotation.VisibleForTesting;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.keyguard.KeyguardUpdateMonitorCallback;
import com.android.settingslib.Utils;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.CircleReveal;
import com.android.systemui.statusbar.LiftReveal;
import com.android.systemui.statusbar.LightRevealEffect;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.commandline.Command;
import com.android.systemui.statusbar.commandline.CommandRegistry;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.phone.dagger.StatusBarComponent.StatusBarScope;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.ViewController;
import com.android.systemui.util.leak.RotationUtils;
import java.io.PrintWriter;
import javax.inject.Inject;
import javax.inject.Provider;

/**
 * *
 * Controls the ripple effect that shows when authentication is successful.
 * The ripple uses the accent color of the current theme.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00ae\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0007\b\u0007\u0018\u0000 N2\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u00032\u00020\u0004:\u0002MNB\u007f\b\u0007\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u0012\u0006\u0010\u0017\u001a\u00020\u0018\u0012\u0006\u0010\u0019\u001a\u00020\u001a\u0012\f\u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\u001d0\u001c\u0012\u0006\u0010\u001e\u001a\u00020\u001f\u0012\b\u0010 \u001a\u0004\u0018\u00010\u0002\u00a2\u0006\u0002\u0010!J\b\u0010>\u001a\u00020?H\u0014J\b\u0010@\u001a\u00020?H\u0016J\b\u0010A\u001a\u00020?H\u0016J\b\u0010B\u001a\u00020?H\u0017J\b\u0010C\u001a\u00020?H\u0017J\b\u0010D\u001a\u00020?H\u0002J\u0010\u0010E\u001a\u00020?2\b\u0010F\u001a\u0004\u0018\u00010GJ\b\u0010H\u001a\u00020?H\u0002J\b\u0010I\u001a\u00020?H\u0002J\b\u0010J\u001a\u00020?H\u0002J\u0006\u0010K\u001a\u00020?J\b\u0010L\u001a\u00020?H\u0002R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020#X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010$\u001a\u0004\u0018\u00010%X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010&\u001a\u00020\'X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010(\u001a\u0004\u0018\u00010)X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u0010*\u001a\u0004\u0018\u00010)X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b+\u0010,\"\u0004\b-\u0010.R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010/\u001a\u000200X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u00101\u001a\u0002028\u0000@\u0000X\u0081\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b3\u00104\u001a\u0004\b5\u00106\"\u0004\b7\u00108R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001e\u001a\u00020\u001fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u00109\u001a\u0004\u0018\u00010\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010:\u001a\u00020;X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\u001d0\u001cX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010<\u001a\u00020=X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/biometrics/AuthRippleController;", "Lcom/android/systemui/util/ViewController;", "Lcom/android/systemui/biometrics/AuthRippleView;", "Lcom/android/systemui/statusbar/policy/KeyguardStateController$Callback;", "Lcom/android/systemui/keyguard/WakefulnessLifecycle$Observer;", "statusBar", "Lcom/android/systemui/statusbar/phone/StatusBar;", "sysuiContext", "Landroid/content/Context;", "authController", "Lcom/android/systemui/biometrics/AuthController;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "keyguardUpdateMonitor", "Lcom/android/keyguard/KeyguardUpdateMonitor;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "wakefulnessLifecycle", "Lcom/android/systemui/keyguard/WakefulnessLifecycle;", "commandRegistry", "Lcom/android/systemui/statusbar/commandline/CommandRegistry;", "notificationShadeWindowController", "Lcom/android/systemui/statusbar/NotificationShadeWindowController;", "bypassController", "Lcom/android/systemui/statusbar/phone/KeyguardBypassController;", "biometricUnlockController", "Lcom/android/systemui/statusbar/phone/BiometricUnlockController;", "udfpsControllerProvider", "Ljavax/inject/Provider;", "Lcom/android/systemui/biometrics/UdfpsController;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "rippleView", "(Lcom/android/systemui/statusbar/phone/StatusBar;Landroid/content/Context;Lcom/android/systemui/biometrics/AuthController;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/keyguard/KeyguardUpdateMonitor;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Lcom/android/systemui/keyguard/WakefulnessLifecycle;Lcom/android/systemui/statusbar/commandline/CommandRegistry;Lcom/android/systemui/statusbar/NotificationShadeWindowController;Lcom/android/systemui/statusbar/phone/KeyguardBypassController;Lcom/android/systemui/statusbar/phone/BiometricUnlockController;Ljavax/inject/Provider;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/biometrics/AuthRippleView;)V", "authControllerCallback", "Lcom/android/systemui/biometrics/AuthController$Callback;", "circleReveal", "Lcom/android/systemui/statusbar/LightRevealEffect;", "configurationChangedListener", "Lcom/android/systemui/statusbar/policy/ConfigurationController$ConfigurationListener;", "faceSensorLocation", "Landroid/graphics/PointF;", "fingerprintSensorLocation", "getFingerprintSensorLocation", "()Landroid/graphics/PointF;", "setFingerprintSensorLocation", "(Landroid/graphics/PointF;)V", "keyguardUpdateMonitorCallback", "Lcom/android/keyguard/KeyguardUpdateMonitorCallback;", "startLightRevealScrimOnKeyguardFadingAway", "", "getStartLightRevealScrimOnKeyguardFadingAway$main$annotations", "()V", "getStartLightRevealScrimOnKeyguardFadingAway$main", "()Z", "setStartLightRevealScrimOnKeyguardFadingAway$main", "(Z)V", "udfpsController", "udfpsControllerCallback", "Lcom/android/systemui/biometrics/UdfpsController$Callback;", "udfpsRadius", "", "onInit", "", "onKeyguardFadingAwayChanged", "onStartedGoingToSleep", "onViewAttached", "onViewDetached", "showDwellRipple", "showRipple", "biometricSourceType", "Landroid/hardware/biometrics/BiometricSourceType;", "showUnlockedRipple", "updateFingerprintLocation", "updateRippleColor", "updateSensorLocation", "updateUdfpsDependentParams", "AuthRippleCommand", "Companion"})
@com.android.systemui.statusbar.phone.dagger.StatusBarComponent.StatusBarScope()
public final class AuthRippleController extends com.android.systemui.util.ViewController<com.android.systemui.biometrics.AuthRippleView> implements com.android.systemui.statusbar.policy.KeyguardStateController.Callback, com.android.systemui.keyguard.WakefulnessLifecycle.Observer {
    private boolean startLightRevealScrimOnKeyguardFadingAway = false;
    @org.jetbrains.annotations.Nullable()
    private android.graphics.PointF fingerprintSensorLocation;
    private android.graphics.PointF faceSensorLocation;
    private com.android.systemui.statusbar.LightRevealEffect circleReveal;
    private com.android.systemui.biometrics.UdfpsController udfpsController;
    private float udfpsRadius = -1.0F;
    private final com.android.keyguard.KeyguardUpdateMonitorCallback keyguardUpdateMonitorCallback = null;
    private final com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener configurationChangedListener = null;
    private final com.android.systemui.biometrics.UdfpsController.Callback udfpsControllerCallback = null;
    private final com.android.systemui.biometrics.AuthController.Callback authControllerCallback = null;
    private final com.android.systemui.statusbar.phone.StatusBar statusBar = null;
    private final android.content.Context sysuiContext = null;
    private final com.android.systemui.biometrics.AuthController authController = null;
    private final com.android.systemui.statusbar.policy.ConfigurationController configurationController = null;
    private final com.android.keyguard.KeyguardUpdateMonitor keyguardUpdateMonitor = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private final com.android.systemui.keyguard.WakefulnessLifecycle wakefulnessLifecycle = null;
    private final com.android.systemui.statusbar.commandline.CommandRegistry commandRegistry = null;
    private final com.android.systemui.statusbar.NotificationShadeWindowController notificationShadeWindowController = null;
    private final com.android.systemui.statusbar.phone.KeyguardBypassController bypassController = null;
    private final com.android.systemui.statusbar.phone.BiometricUnlockController biometricUnlockController = null;
    private final javax.inject.Provider<com.android.systemui.biometrics.UdfpsController> udfpsControllerProvider = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    public static final long RIPPLE_ANIMATION_DURATION = 1533L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.biometrics.AuthRippleController.Companion Companion = null;
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getStartLightRevealScrimOnKeyguardFadingAway$main$annotations() {
    }
    
    public final boolean getStartLightRevealScrimOnKeyguardFadingAway$main() {
        return false;
    }
    
    public final void setStartLightRevealScrimOnKeyguardFadingAway$main(boolean p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.PointF getFingerprintSensorLocation() {
        return null;
    }
    
    public final void setFingerprintSensorLocation(@org.jetbrains.annotations.Nullable()
    android.graphics.PointF p0) {
    }
    
    @java.lang.Override()
    protected void onInit() {
    }
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Override()
    public void onViewAttached() {
    }
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Override()
    public void onViewDetached() {
    }
    
    public final void showRipple(@org.jetbrains.annotations.Nullable()
    android.hardware.biometrics.BiometricSourceType biometricSourceType) {
    }
    
    private final void showUnlockedRipple() {
    }
    
    @java.lang.Override()
    public void onKeyguardFadingAwayChanged() {
    }
    
    @java.lang.Override()
    public void onStartedGoingToSleep() {
    }
    
    public final void updateSensorLocation() {
    }
    
    private final void updateFingerprintLocation() {
    }
    
    private final void updateRippleColor() {
    }
    
    private final void showDwellRipple() {
    }
    
    private final void updateUdfpsDependentParams() {
    }
    
    @javax.inject.Inject()
    public AuthRippleController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBar statusBar, @org.jetbrains.annotations.NotNull()
    android.content.Context sysuiContext, @org.jetbrains.annotations.NotNull()
    com.android.systemui.biometrics.AuthController authController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.keyguard.KeyguardUpdateMonitor keyguardUpdateMonitor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.keyguard.WakefulnessLifecycle wakefulnessLifecycle, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.commandline.CommandRegistry commandRegistry, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationShadeWindowController notificationShadeWindowController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardBypassController bypassController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.BiometricUnlockController biometricUnlockController, @org.jetbrains.annotations.NotNull()
    javax.inject.Provider<com.android.systemui.biometrics.UdfpsController> udfpsControllerProvider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.Nullable()
    com.android.systemui.biometrics.AuthRippleView rippleView) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0002\b\u0086\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u001e\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\bH\u0016J\u0010\u0010\n\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016J\u000e\u0010\u000b\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006"}, d2 = {"Lcom/android/systemui/biometrics/AuthRippleController$AuthRippleCommand;", "Lcom/android/systemui/statusbar/commandline/Command;", "(Lcom/android/systemui/biometrics/AuthRippleController;)V", "execute", "", "pw", "Ljava/io/PrintWriter;", "args", "", "", "help", "invalidCommand"})
    public final class AuthRippleCommand implements com.android.systemui.statusbar.commandline.Command {
        
        @java.lang.Override()
        public void execute(@org.jetbrains.annotations.NotNull()
        java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.String> args) {
        }
        
        @java.lang.Override()
        public void help(@org.jetbrains.annotations.NotNull()
        java.io.PrintWriter pw) {
        }
        
        public final void invalidCommand(@org.jetbrains.annotations.NotNull()
        java.io.PrintWriter pw) {
        }
        
        public AuthRippleCommand() {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/biometrics/AuthRippleController$Companion;", "", "()V", "RIPPLE_ANIMATION_DURATION", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
package com.android.systemui.biometrics;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.app.ActivityTaskManager;
import android.content.Context;
import android.graphics.PixelFormat;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffColorFilter;
import android.graphics.Rect;
import android.hardware.biometrics.BiometricOverlayConstants;
import android.hardware.display.DisplayManager;
import android.hardware.fingerprint.FingerprintManager;
import android.hardware.fingerprint.FingerprintSensorPropertiesInternal;
import android.hardware.fingerprint.ISidefpsController;
import android.os.Handler;
import android.util.Log;
import android.view.Display;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.Surface;
import android.view.View;
import android.view.ViewPropertyAnimator;
import android.view.WindowInsets;
import android.view.WindowManager;
import androidx.annotation.RawRes;
import com.airbnb.lottie.LottieAnimationView;
import com.airbnb.lottie.LottieProperty;
import com.airbnb.lottie.model.KeyPath;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.util.concurrency.DelayableExecutor;
import javax.inject.Inject;

/**
 * Shows and hides the side fingerprint sensor (side-fps) overlay and handles side fps touch events.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u008a\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001BU\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\b\b\u0001\u0010\u0010\u001a\u00020\u0011\u0012\b\b\u0001\u0010\u0012\u001a\u00020\u0013\u00a2\u0006\u0002\u0010\u0014J\b\u00100\u001a\u00020 H\u0002J\b\u00101\u001a\u000202H\u0002J\u0018\u00103\u001a\u0002022\u0006\u00104\u001a\u0002052\u0006\u00106\u001a\u000207H\u0002J\u0010\u00108\u001a\u0002022\u0006\u00109\u001a\u00020 H\u0002R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u0017\u001a\u00020\u00188\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\u0019\u0010\u001a\u001a\u0004\b\u001b\u0010\u001cR\u0010\u0010\u001d\u001a\u0004\u0018\u00010\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\"\u0010!\u001a\u0004\u0018\u00010 2\b\u0010\u001f\u001a\u0004\u0018\u00010 @BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\"\u0010#R\u000e\u0010$\u001a\u00020%X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010&\u001a\u00020\'8\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b(\u0010\u001a\u001a\u0004\b)\u0010*R\u001c\u0010+\u001a\u00020,8\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b-\u0010\u001a\u001a\u0004\b.\u0010/R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/biometrics/SidefpsController;", "", "context", "Landroid/content/Context;", "layoutInflater", "Landroid/view/LayoutInflater;", "fingerprintManager", "Landroid/hardware/fingerprint/FingerprintManager;", "windowManager", "Landroid/view/WindowManager;", "activityTaskManager", "Landroid/app/ActivityTaskManager;", "overviewProxyService", "Lcom/android/systemui/recents/OverviewProxyService;", "displayManager", "Landroid/hardware/display/DisplayManager;", "mainExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "handler", "Landroid/os/Handler;", "(Landroid/content/Context;Landroid/view/LayoutInflater;Landroid/hardware/fingerprint/FingerprintManager;Landroid/view/WindowManager;Landroid/app/ActivityTaskManager;Lcom/android/systemui/recents/OverviewProxyService;Landroid/hardware/display/DisplayManager;Lcom/android/systemui/util/concurrency/DelayableExecutor;Landroid/os/Handler;)V", "animationDuration", "", "orientationListener", "Lcom/android/systemui/biometrics/BiometricDisplayListener;", "getOrientationListener$annotations", "()V", "getOrientationListener", "()Lcom/android/systemui/biometrics/BiometricDisplayListener;", "overlayHideAnimator", "Landroid/view/ViewPropertyAnimator;", "value", "Landroid/view/View;", "overlayView", "setOverlayView", "(Landroid/view/View;)V", "overlayViewParams", "Landroid/view/WindowManager$LayoutParams;", "overviewProxyListener", "Lcom/android/systemui/recents/OverviewProxyService$OverviewProxyListener;", "getOverviewProxyListener$annotations", "getOverviewProxyListener", "()Lcom/android/systemui/recents/OverviewProxyService$OverviewProxyListener;", "sensorProps", "Landroid/hardware/fingerprint/FingerprintSensorPropertiesInternal;", "getSensorProps$annotations", "getSensorProps", "()Landroid/hardware/fingerprint/FingerprintSensorPropertiesInternal;", "createOverlayForDisplay", "onOrientationChanged", "", "updateOverlayParams", "display", "Landroid/view/Display;", "bounds", "Landroid/graphics/Rect;", "updateOverlayVisibility", "view"})
@com.android.systemui.dagger.SysUISingleton()
public final class SidefpsController {
    @org.jetbrains.annotations.NotNull()
    private final android.hardware.fingerprint.FingerprintSensorPropertiesInternal sensorProps = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.biometrics.BiometricDisplayListener orientationListener = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.recents.OverviewProxyService.OverviewProxyListener overviewProxyListener = null;
    private final long animationDuration = 0L;
    private android.view.ViewPropertyAnimator overlayHideAnimator;
    private android.view.View overlayView;
    private final android.view.WindowManager.LayoutParams overlayViewParams = null;
    private final android.content.Context context = null;
    private final android.view.LayoutInflater layoutInflater = null;
    private final android.view.WindowManager windowManager = null;
    private final android.app.ActivityTaskManager activityTaskManager = null;
    private final android.os.Handler handler = null;
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getSensorProps$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.hardware.fingerprint.FingerprintSensorPropertiesInternal getSensorProps() {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getOrientationListener$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.biometrics.BiometricDisplayListener getOrientationListener() {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getOverviewProxyListener$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.recents.OverviewProxyService.OverviewProxyListener getOverviewProxyListener() {
        return null;
    }
    
    private final void setOverlayView(android.view.View value) {
    }
    
    private final void onOrientationChanged() {
    }
    
    private final android.view.View createOverlayForDisplay() {
        return null;
    }
    
    private final void updateOverlayParams(android.view.Display display, android.graphics.Rect bounds) {
    }
    
    private final void updateOverlayVisibility(android.view.View view) {
    }
    
    @javax.inject.Inject()
    public SidefpsController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater layoutInflater, @org.jetbrains.annotations.Nullable()
    android.hardware.fingerprint.FingerprintManager fingerprintManager, @org.jetbrains.annotations.NotNull()
    android.view.WindowManager windowManager, @org.jetbrains.annotations.NotNull()
    android.app.ActivityTaskManager activityTaskManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.recents.OverviewProxyService overviewProxyService, @org.jetbrains.annotations.NotNull()
    android.hardware.display.DisplayManager displayManager, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor mainExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler handler) {
        super();
    }
}
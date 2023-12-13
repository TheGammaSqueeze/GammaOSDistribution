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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000:\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u000b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\u001a\u0014\u0010\u0002\u001a\u00020\u0003*\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0002\u001a\f\u0010\u0007\u001a\u00020\b*\u00020\tH\u0003\u001a\f\u0010\n\u001a\u00020\u000b*\u00020\tH\u0002\u001a\f\u0010\f\u001a\u00020\r*\u00020\u000eH\u0002\u001a\f\u0010\u000f\u001a\u00020\r*\u00020\tH\u0002\u001a\u0014\u0010\u0010\u001a\u00020\r*\u00020\b2\u0006\u0010\u0011\u001a\u00020\u0012H\u0002\u001a\f\u0010\u0013\u001a\u00020\u0001*\u00020\u0012H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"TAG", "", "addOverlayDynamicColor", "", "Lcom/airbnb/lottie/LottieAnimationView;", "context", "Landroid/content/Context;", "asSideFpsAnimation", "", "Landroid/view/Display;", "asSideFpsAnimationRotation", "", "hasBigNavigationBar", "", "Landroid/view/WindowInsets;", "isPortrait", "isReasonToShow", "activityTaskManager", "Landroid/app/ActivityTaskManager;", "topClass"})
public final class SidefpsControllerKt {
    private static final java.lang.String TAG = "SidefpsController";
    
    @android.hardware.biometrics.BiometricOverlayConstants.ShowReason()
    private static final boolean isReasonToShow(int $this$isReasonToShow, android.app.ActivityTaskManager activityTaskManager) {
        return false;
    }
    
    private static final java.lang.String topClass(android.app.ActivityTaskManager $this$topClass) {
        return null;
    }
    
    @androidx.annotation.RawRes()
    private static final int asSideFpsAnimation(android.view.Display $this$asSideFpsAnimation) {
        return 0;
    }
    
    private static final float asSideFpsAnimationRotation(android.view.Display $this$asSideFpsAnimationRotation) {
        return 0.0F;
    }
    
    private static final boolean isPortrait(android.view.Display $this$isPortrait) {
        return false;
    }
    
    private static final boolean hasBigNavigationBar(android.view.WindowInsets $this$hasBigNavigationBar) {
        return false;
    }
    
    private static final void addOverlayDynamicColor(com.airbnb.lottie.LottieAnimationView $this$addOverlayDynamicColor, android.content.Context context) {
    }
}
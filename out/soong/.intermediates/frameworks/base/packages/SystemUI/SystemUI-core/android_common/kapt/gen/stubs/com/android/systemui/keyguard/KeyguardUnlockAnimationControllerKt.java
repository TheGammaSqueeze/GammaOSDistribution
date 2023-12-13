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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u000e\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0007X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DISMISS_AMOUNT_EXIT_KEYGUARD_THRESHOLD", "", "DISMISS_AMOUNT_SHOW_SURFACE_THRESHOLD", "SURFACE_BEHIND_SCALE_PIVOT_Y", "SURFACE_BEHIND_START_SCALE_FACTOR", "SURFACE_BEHIND_START_TRANSLATION_Y", "TAG", ""})
public final class KeyguardUnlockAnimationControllerKt {
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String TAG = "KeyguardUnlock";
    
    /**
     * Starting scale factor for the app/launcher surface behind the keyguard, when it's animating
     * in during keyguard exit.
     */
    public static final float SURFACE_BEHIND_START_SCALE_FACTOR = 0.95F;
    
    /**
     * How much to translate the surface behind the keyguard at the beginning of the exit animation,
     * in terms of percentage of the surface's height.
     */
    public static final float SURFACE_BEHIND_START_TRANSLATION_Y = 0.05F;
    
    /**
     * Y coordinate of the pivot point for the scale effect on the surface behind the keyguard. This
     * is expressed as percentage of the surface's height, so 0.66f means the surface will scale up
     * from the point at (width / 2, height * 0.66).
     */
    public static final float SURFACE_BEHIND_SCALE_PIVOT_Y = 0.66F;
    
    /**
     * Dismiss amount at which to fade in the surface behind the keyguard. The surface will then animate
     * along with the dismiss amount until [DISMISS_AMOUNT_EXIT_KEYGUARD_THRESHOLD] is reached.
     *
     * The dismiss amount is the inverse of the notification panel expansion, which decreases as the
     * lock screen is swiped away.
     */
    public static final float DISMISS_AMOUNT_SHOW_SURFACE_THRESHOLD = 0.25F;
    
    /**
     * Dismiss amount at which to complete the keyguard exit animation and hide the keyguard.
     *
     * The dismiss amount is the inverse of the notification panel expansion, which decreases as the
     * lock screen is swiped away.
     */
    public static final float DISMISS_AMOUNT_EXIT_KEYGUARD_THRESHOLD = 0.4F;
}
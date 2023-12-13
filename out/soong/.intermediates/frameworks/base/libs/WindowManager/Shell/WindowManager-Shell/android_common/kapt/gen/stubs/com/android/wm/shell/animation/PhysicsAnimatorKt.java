package com.android.wm.shell.animation;

import android.util.ArrayMap;
import android.util.Log;
import android.view.View;
import androidx.dynamicanimation.animation.AnimationHandler;
import androidx.dynamicanimation.animation.DynamicAnimation;
import androidx.dynamicanimation.animation.FlingAnimation;
import androidx.dynamicanimation.animation.FloatPropertyCompat;
import androidx.dynamicanimation.animation.SpringAnimation;
import androidx.dynamicanimation.animation.SpringForce;
import java.lang.ref.WeakReference;
import java.util.WeakHashMap;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000R\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0082D\u00a2\u0006\u0002\n\u0000\"$\u0010\u0005\u001a\u0012\u0012\u0004\u0012\u00020\u0007\u0012\b\u0012\u0006\u0012\u0002\b\u00030\b0\u0006X\u0080\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\n\"\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000\"%\u0010\u0011\u001a\b\u0012\u0004\u0012\u0002H\u00120\b\"\b\b\u0000\u0010\u0012*\u00020\u0013*\u0002H\u00128F\u00a2\u0006\u0006\u001a\u0004\b\u0014\u0010\u0015*\u0016\u0010\u0016\"\b\u0012\u0004\u0012\u00020\u00180\u00172\b\u0012\u0004\u0012\u00020\u00180\u0017*8\u0010\u0019\u001a\u0004\b\u0000\u0010\u0012\"\u0016\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u0002H\u00120\u001b\u0012\u0004\u0012\u00020\u001c0\u001a2\u0016\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u0002H\u00120\u001b\u0012\u0004\u0012\u00020\u001c0\u001a"}, d2 = {"FLING_FRICTION_SCALAR_MULTIPLIER", "", "TAG", "", "UNSET", "animators", "Ljava/util/WeakHashMap;", "", "Lcom/android/wm/shell/animation/PhysicsAnimator;", "getAnimators", "()Ljava/util/WeakHashMap;", "globalDefaultFling", "Lcom/android/wm/shell/animation/PhysicsAnimator$FlingConfig;", "globalDefaultSpring", "Lcom/android/wm/shell/animation/PhysicsAnimator$SpringConfig;", "verboseLogging", "", "physicsAnimator", "T", "Landroid/view/View;", "getPhysicsAnimator", "(Landroid/view/View;)Lcom/android/wm/shell/animation/PhysicsAnimator;", "EndAction", "Lkotlin/Function0;", "", "UpdateMap", "Landroid/util/ArrayMap;", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "Lcom/android/wm/shell/animation/PhysicsAnimator$AnimationUpdate;"})
public final class PhysicsAnimatorKt {
    private static final java.lang.String TAG = "PhysicsAnimator";
    private static final float UNSET = -3.4028235E38F;
    
    /**
     * [FlingAnimation] multiplies the friction set via [FlingAnimation.setFriction] by 4.2f, which is
     * where this number comes from. We use it in [PhysicsAnimator.flingThenSpring] to calculate the
     * minimum velocity for a fling to reach a certain value, given the fling's friction.
     */
    private static final float FLING_FRICTION_SCALAR_MULTIPLIER = 4.2F;
    
    /**
     * Map of the animators associated with a given object. This ensures that only one animator
     * per object exists.
     */
    @org.jetbrains.annotations.NotNull()
    private static final java.util.WeakHashMap<java.lang.Object, com.android.wm.shell.animation.PhysicsAnimator<?>> animators = null;
    
    /**
     * Default spring configuration to use for animations where stiffness and/or damping ratio
     * were not provided, and a default spring was not set via [PhysicsAnimator.setDefaultSpringConfig].
     */
    private static final com.android.wm.shell.animation.PhysicsAnimator.SpringConfig globalDefaultSpring = null;
    
    /**
     * Default fling configuration to use for animations where friction was not provided, and a default
     * fling config was not set via [PhysicsAnimator.setDefaultFlingConfig].
     */
    private static final com.android.wm.shell.animation.PhysicsAnimator.FlingConfig globalDefaultFling = null;
    
    /**
     * Whether to log helpful debug information about animations.
     */
    private static boolean verboseLogging = false;
    
    @org.jetbrains.annotations.NotNull()
    public static final <T extends android.view.View>com.android.wm.shell.animation.PhysicsAnimator<T> getPhysicsAnimator(@org.jetbrains.annotations.NotNull()
    T $this$physicsAnimator) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final java.util.WeakHashMap<java.lang.Object, com.android.wm.shell.animation.PhysicsAnimator<?>> getAnimators() {
        return null;
    }
}
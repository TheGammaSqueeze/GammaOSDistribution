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

/**
 * Animator that uses physics-based animations to animate properties on views and objects. Physics
 * animations use real-world physical concepts, such as momentum and mass, to realistically simulate
 * motion. PhysicsAnimator is heavily inspired by [android.view.ViewPropertyAnimator], and
 * also uses the builder pattern to configure and start animations.
 *
 * The physics animations are backed by [DynamicAnimation].
 *
 * @param T The type of the object being animated.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u009c\u0001\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0007\n\u0002\b\u001e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\u0018\u0000 h*\u0004\b\u0000\u0010\u00012\u00020\u0002:\u0007ghijklmB\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00028\u0000\u00a2\u0006\u0002\u0010\u0004J\u001a\u00102\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\f\u00103\u001a\b\u0012\u0004\u0012\u00028\u00000\u0018J\u001a\u00104\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\f\u00103\u001a\b\u0012\u0004\u0012\u00028\u00000,J\u001c\u00105\u001a\u0002062\u0014\u00107\u001a\u0010\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b0\u0007J\u0006\u00108\u001a\u00020\tJ/\u00108\u001a\u00020\t2\"\u00107\u001a\u0012\u0012\u000e\b\u0001\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b09\"\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b\u00a2\u0006\u0002\u0010:J#\u0010;\u001a\u00020\t2\u0014\u00107\u001a\u0010\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b0\u0007H\u0000\u00a2\u0006\u0002\b<J\b\u0010=\u001a\u00020\tH\u0002J(\u0010>\u001a\u0006\u0012\u0002\b\u00030?2\n\u0010@\u001a\u0006\u0012\u0002\b\u00030?2\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\bH\u0002J.\u0010B\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b2\u0006\u0010C\u001a\u00020D2\b\b\u0002\u0010E\u001a\u00020\u0011JB\u0010B\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b2\u0006\u0010C\u001a\u00020D2\b\b\u0002\u0010F\u001a\u00020D2\b\b\u0002\u0010G\u001a\u00020D2\b\b\u0002\u0010H\u001a\u00020DJ@\u0010I\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b2\u0006\u0010C\u001a\u00020D2\u0006\u0010J\u001a\u00020\u00112\u0006\u0010K\u001a\u00020\u00132\b\b\u0002\u0010L\u001a\u000206H\u0007J\u001b\u0010M\u001a\u0010\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b0\u0007H\u0000\u00a2\u0006\u0002\bNJ%\u0010O\u001a\u00020\u001b2\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b2\u0006\u0010\u0003\u001a\u00028\u0000H\u0002\u00a2\u0006\u0002\u0010PJ%\u0010Q\u001a\u00020$2\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b2\u0006\u0010\u0003\u001a\u00028\u0000H\u0002\u00a2\u0006\u0002\u0010RJ\u0016\u0010S\u001a\u0002062\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\bJ\u0006\u0010T\u001a\u000206J\u0010\u0010U\u001a\u0002062\u0006\u0010V\u001a\u00020DH\u0002J\u000e\u0010W\u001a\u00020\t2\u0006\u0010X\u001a\u00020\u000fJ\u000e\u0010Y\u001a\u00020\t2\u0006\u0010\u0010\u001a\u00020\u0011J\u000e\u0010Z\u001a\u00020\t2\u0006\u0010\u0012\u001a\u00020\u0013J$\u0010[\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b2\u0006\u0010\\\u001a\u00020DJ.\u0010[\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b2\u0006\u0010\\\u001a\u00020D2\b\b\u0002\u0010E\u001a\u00020\u0013J6\u0010[\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b2\u0006\u0010\\\u001a\u00020D2\u0006\u0010C\u001a\u00020D2\b\b\u0002\u0010E\u001a\u00020\u0013JB\u0010[\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\u000e\u0010A\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b2\u0006\u0010\\\u001a\u00020D2\b\b\u0002\u0010C\u001a\u00020D2\b\b\u0002\u0010]\u001a\u00020D2\b\b\u0002\u0010^\u001a\u00020DJ\u0006\u0010_\u001a\u00020\tJ\r\u0010`\u001a\u00020\tH\u0000\u00a2\u0006\u0002\baJA\u0010b\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002.\u0010\u0014\u001a\u0018\u0012\u0014\b\u0001\u0012\u0010\u0012\u0004\u0012\u00020\t\u0018\u00010\u0016j\u0004\u0018\u0001`c09\"\u0010\u0012\u0004\u0012\u00020\t\u0018\u00010\u0016j\u0004\u0018\u0001`c\u00a2\u0006\u0002\u0010dJ)\u0010b\u001a\b\u0012\u0004\u0012\u00028\u00000\u00002\u0016\u0010\u0014\u001a\f\u0012\b\b\u0001\u0012\u0004\u0018\u00010e09\"\u0004\u0018\u00010e\u00a2\u0006\u0002\u0010fR4\u0010\u0005\u001a\u001c\u0012\u0012\u0012\u0010\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b0\u0007\u0012\u0004\u0012\u00020\t0\u0006X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u0010\u0010\u000e\u001a\u0004\u0018\u00010\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0014\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\t0\u00160\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0017\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00028\u00000\u00180\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\"\u0010\u0019\u001a\u0016\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b\u0012\u0004\u0012\u00020\u001b0\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\"\u0010\u001c\u001a\u0016\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b\u0012\u0004\u0012\u00020\u00110\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R*\u0010\u001d\u001a\u0012\u0012\u000e\u0012\f0\u001eR\b\u0012\u0004\u0012\u00028\u00000\u00000\u0015X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001f\u0010 \"\u0004\b!\u0010\"R\"\u0010#\u001a\u0016\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b\u0012\u0004\u0012\u00020$0\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\"\u0010%\u001a\u0016\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b\u0012\u0004\u0012\u00020\u00130\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010&\u001a\b\u0012\u0004\u0012\u00020\t0\u0016X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\'\u0010(\"\u0004\b)\u0010*R\u001a\u0010+\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00028\u00000,0\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001f\u0010-\u001a\u0010\u0012\f\u0012\n /*\u0004\u0018\u00018\u00008\u00000.\u00a2\u0006\b\n\u0000\u001a\u0004\b0\u00101"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimator;", "T", "", "target", "(Ljava/lang/Object;)V", "cancelAction", "Lkotlin/Function1;", "", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "", "getCancelAction$main", "()Lkotlin/jvm/functions/Function1;", "setCancelAction$main", "(Lkotlin/jvm/functions/Function1;)V", "customAnimationHandler", "Landroidx/dynamicanimation/animation/AnimationHandler;", "defaultFling", "Lcom/android/wm/shell/animation/PhysicsAnimator$FlingConfig;", "defaultSpring", "Lcom/android/wm/shell/animation/PhysicsAnimator$SpringConfig;", "endActions", "Ljava/util/ArrayList;", "Lkotlin/Function0;", "endListeners", "Lcom/android/wm/shell/animation/PhysicsAnimator$EndListener;", "flingAnimations", "Landroid/util/ArrayMap;", "Landroidx/dynamicanimation/animation/FlingAnimation;", "flingConfigs", "internalListeners", "Lcom/android/wm/shell/animation/PhysicsAnimator$InternalListener;", "getInternalListeners$main", "()Ljava/util/ArrayList;", "setInternalListeners$main", "(Ljava/util/ArrayList;)V", "springAnimations", "Landroidx/dynamicanimation/animation/SpringAnimation;", "springConfigs", "startAction", "getStartAction$main", "()Lkotlin/jvm/functions/Function0;", "setStartAction$main", "(Lkotlin/jvm/functions/Function0;)V", "updateListeners", "Lcom/android/wm/shell/animation/PhysicsAnimator$UpdateListener;", "weakTarget", "Ljava/lang/ref/WeakReference;", "kotlin.jvm.PlatformType", "getWeakTarget", "()Ljava/lang/ref/WeakReference;", "addEndListener", "listener", "addUpdateListener", "arePropertiesAnimating", "", "properties", "cancel", "", "([Landroidx/dynamicanimation/animation/FloatPropertyCompat;)V", "cancelInternal", "cancelInternal$main", "clearAnimator", "configureDynamicAnimation", "Landroidx/dynamicanimation/animation/DynamicAnimation;", "anim", "property", "fling", "startVelocity", "", "config", "friction", "min", "max", "flingThenSpring", "flingConfig", "springConfig", "flingMustReachMinOrMax", "getAnimatedProperties", "getAnimatedProperties$main", "getFlingAnimation", "(Landroidx/dynamicanimation/animation/FloatPropertyCompat;Ljava/lang/Object;)Landroidx/dynamicanimation/animation/FlingAnimation;", "getSpringAnimation", "(Landroidx/dynamicanimation/animation/FloatPropertyCompat;Ljava/lang/Object;)Landroidx/dynamicanimation/animation/SpringAnimation;", "isPropertyAnimating", "isRunning", "isValidValue", "value", "setCustomAnimationHandler", "handler", "setDefaultFlingConfig", "setDefaultSpringConfig", "spring", "toPosition", "stiffness", "dampingRatio", "start", "startInternal", "startInternal$main", "withEndActions", "Lcom/android/wm/shell/animation/EndAction;", "([Lkotlin/jvm/functions/Function0;)Lcom/android/wm/shell/animation/PhysicsAnimator;", "Ljava/lang/Runnable;", "([Ljava/lang/Runnable;)Lcom/android/wm/shell/animation/PhysicsAnimator;", "AnimationUpdate", "Companion", "EndListener", "FlingConfig", "InternalListener", "SpringConfig", "UpdateListener"})
public final class PhysicsAnimator<T extends java.lang.Object> {
    
    /**
     * Weak reference to the animation target.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.lang.ref.WeakReference<T> weakTarget = null;
    
    /**
     * [DynamicAnimation] instances for the given properties.
     */
    private final android.util.ArrayMap<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>, androidx.dynamicanimation.animation.SpringAnimation> springAnimations = null;
    private final android.util.ArrayMap<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>, androidx.dynamicanimation.animation.FlingAnimation> flingAnimations = null;
    
    /**
     * Spring and fling configurations for the properties to be animated on the target. We'll
     * configure and start the DynamicAnimations for these properties according to the provided
     * configurations.
     */
    private final android.util.ArrayMap<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>, com.android.wm.shell.animation.PhysicsAnimator.SpringConfig> springConfigs = null;
    private final android.util.ArrayMap<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>, com.android.wm.shell.animation.PhysicsAnimator.FlingConfig> flingConfigs = null;
    
    /**
     * Animation listeners for the animation. These will be notified when each property animation
     * updates or ends.
     */
    private final java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator.UpdateListener<T>> updateListeners = null;
    private final java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator.EndListener<T>> endListeners = null;
    
    /**
     * End actions to run when all animations have completed.
     */
    private final java.util.ArrayList<kotlin.jvm.functions.Function0<kotlin.Unit>> endActions = null;
    
    /**
     * SpringConfig to use by default for properties whose springs were not provided.
     */
    private com.android.wm.shell.animation.PhysicsAnimator.SpringConfig defaultSpring;
    
    /**
     * FlingConfig to use by default for properties whose fling configs were not provided.
     */
    private com.android.wm.shell.animation.PhysicsAnimator.FlingConfig defaultFling;
    
    /**
     * AnimationHandler to use if it need custom AnimationHandler, if this is null, it will use
     * the default AnimationHandler in the DynamicAnimation.
     */
    private androidx.dynamicanimation.animation.AnimationHandler customAnimationHandler;
    
    /**
     * Internal listeners that respond to DynamicAnimations updating and ending, and dispatch to
     * the listeners provided via [addUpdateListener] and [addEndListener]. This allows us to add
     * just one permanent update and end listener to the DynamicAnimations.
     */
    @org.jetbrains.annotations.NotNull()
    private java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator<T>.InternalListener> internalListeners;
    
    /**
     * Action to run when [start] is called. This can be changed by
     * [PhysicsAnimatorTestUtils.prepareForTest] to enable animators to run under test and provide
     * helpful test utilities.
     */
    @org.jetbrains.annotations.NotNull()
    private kotlin.jvm.functions.Function0<kotlin.Unit> startAction;
    
    /**
     * Action to run when [cancel] is called. This can be changed by
     * [PhysicsAnimatorTestUtils.prepareForTest] to cancel animations from the main thread, which
     * is required.
     */
    @org.jetbrains.annotations.NotNull()
    private kotlin.jvm.functions.Function1<? super java.util.Set<? extends androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>>, kotlin.Unit> cancelAction;
    
    /**
     * Constructor to use to for new physics animator instances in [getInstance]. This is
     * typically the default constructor, but [PhysicsAnimatorTestUtils] can change it so that
     * all code using the physics animator is given testable instances instead.
     */
    @org.jetbrains.annotations.NotNull()
    private static kotlin.jvm.functions.Function1<java.lang.Object, ? extends com.android.wm.shell.animation.PhysicsAnimator<?>> instanceConstructor;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.wm.shell.animation.PhysicsAnimator.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.ref.WeakReference<T> getWeakTarget() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator<T>.InternalListener> getInternalListeners$main() {
        return null;
    }
    
    public final void setInternalListeners$main(@org.jetbrains.annotations.NotNull()
    java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator<T>.InternalListener> p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function0<kotlin.Unit> getStartAction$main() {
        return null;
    }
    
    public final void setStartAction$main(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function1<java.util.Set<? extends androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>>, kotlin.Unit> getCancelAction$main() {
        return null;
    }
    
    public final void setCancelAction$main(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.util.Set<? extends androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>>, kotlin.Unit> p0) {
    }
    
    /**
     * Springs a property to the given value, using the provided configuration settings.
     *
     * Springs are used when you know the exact value to which you want to animate. They can be
     * configured with a start velocity (typically used when the spring is initiated by a touch
     * event), but this velocity will be realistically attenuated as forces are applied to move the
     * property towards the end value.
     *
     * If you find yourself repeating the same stiffness and damping ratios many times, consider
     * storing a single [SpringConfig] instance and passing that in instead of individual values.
     *
     * @param property The property to spring to the given value. The property must be an instance
     * of FloatPropertyCompat&lt;? super T&gt;. For example, if this is a
     * PhysicsAnimator&lt;FrameLayout&gt;, you can use a FloatPropertyCompat&lt;FrameLayout&gt;, as
     * well as a FloatPropertyCompat&lt;ViewGroup&gt;, and so on.
     * @param toPosition The value to spring the given property to.
     * @param startVelocity The initial velocity to use for the animation.
     * @param stiffness The stiffness to use for the spring. Higher stiffness values result in
     * faster animations, while lower stiffness means a slower animation. Reasonable values for
     * low, medium, and high stiffness can be found as constants in [SpringForce].
     * @param dampingRatio The damping ratio (bounciness) to use for the spring. Higher values
     * result in a less 'springy' animation, while lower values allow the animation to bounce
     * back and forth for a longer time after reaching the final position. Reasonable values for
     * low, medium, and high damping can be found in [SpringForce].
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> spring(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float toPosition, float startVelocity, float stiffness, float dampingRatio) {
        return null;
    }
    
    /**
     * Springs a property to a given value using the provided start velocity and configuration
     * options.
     *
     * @see spring
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> spring(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float toPosition, float startVelocity, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.SpringConfig config) {
        return null;
    }
    
    /**
     * Springs a property to a given value using the provided configuration options, and a start
     * velocity of 0f.
     *
     * @see spring
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> spring(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float toPosition, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.SpringConfig config) {
        return null;
    }
    
    /**
     * Springs a property to a given value using the provided configuration options, and a start
     * velocity of 0f.
     *
     * @see spring
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> spring(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float toPosition) {
        return null;
    }
    
    /**
     * Flings a property using the given start velocity, using a [FlingAnimation] configured using
     * the provided configuration settings.
     *
     * Flings are used when you have a start velocity, and want the property value to realistically
     * decrease as friction is applied until the velocity reaches zero. Flings do not have a
     * deterministic end value. If you are attempting to animate to a specific end value, use
     * [spring].
     *
     * If you find yourself repeating the same friction/min/max values, consider storing a single
     * [FlingConfig] and passing that in instead.
     *
     * @param property The property to fling using the given start velocity.
     * @param startVelocity The start velocity (in pixels per second) with which to start the fling.
     * @param friction Friction value applied to slow down the animation over time. Higher values
     * will more quickly slow the animation. Typical friction values range from 1f to 10f.
     * @param min The minimum value allowed for the animation. If this value is reached, the
     * animation will end abruptly.
     * @param max The maximum value allowed for the animation. If this value is reached, the
     * animation will end abruptly.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> fling(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float startVelocity, float friction, float min, float max) {
        return null;
    }
    
    /**
     * Flings a property using the given start velocity, using a [FlingAnimation] configured using
     * the provided configuration settings.
     *
     * @see fling
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> fling(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float startVelocity, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.FlingConfig config) {
        return null;
    }
    
    /**
     * Flings a property using the given start velocity. If the fling animation reaches the min/max
     * bounds (from the [flingConfig]) with velocity remaining, it'll overshoot it and spring back.
     *
     * If the object is already out of the fling bounds, it will immediately spring back within
     * bounds.
     *
     * This is useful for animating objects that are bounded by constraints such as screen edges,
     * since otherwise the fling animation would end abruptly upon reaching the min/max bounds.
     *
     * @param property The property to animate.
     * @param startVelocity The velocity, in pixels/second, with which to start the fling. If the
     * object is already outside the fling bounds, this velocity will be used as the start velocity
     * of the spring that will spring it back within bounds.
     * @param flingMustReachMinOrMax If true, the fling animation is guaranteed to reach either its
     * minimum bound (if [startVelocity] is negative) or maximum bound (if it's positive). The
     * animator will use startVelocity if it's sufficient, or add more velocity if necessary. This
     * is useful when fling's deceleration-based physics are preferable to the acceleration-based
     * forces used by springs - typically, when you're allowing the user to move an object somewhere
     * on the screen, but it needs to be along an edge.
     * @param flingConfig The configuration to use for the fling portion of the animation.
     * @param springConfig The configuration to use for the spring portion of the animation.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> flingThenSpring(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float startVelocity, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.FlingConfig flingConfig, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.SpringConfig springConfig, boolean flingMustReachMinOrMax) {
        return null;
    }
    
    /**
     * Flings a property using the given start velocity. If the fling animation reaches the min/max
     * bounds (from the [flingConfig]) with velocity remaining, it'll overshoot it and spring back.
     *
     * If the object is already out of the fling bounds, it will immediately spring back within
     * bounds.
     *
     * This is useful for animating objects that are bounded by constraints such as screen edges,
     * since otherwise the fling animation would end abruptly upon reaching the min/max bounds.
     *
     * @param property The property to animate.
     * @param startVelocity The velocity, in pixels/second, with which to start the fling. If the
     * object is already outside the fling bounds, this velocity will be used as the start velocity
     * of the spring that will spring it back within bounds.
     * @param flingMustReachMinOrMax If true, the fling animation is guaranteed to reach either its
     * minimum bound (if [startVelocity] is negative) or maximum bound (if it's positive). The
     * animator will use startVelocity if it's sufficient, or add more velocity if necessary. This
     * is useful when fling's deceleration-based physics are preferable to the acceleration-based
     * forces used by springs - typically, when you're allowing the user to move an object somewhere
     * on the screen, but it needs to be along an edge.
     * @param flingConfig The configuration to use for the fling portion of the animation.
     * @param springConfig The configuration to use for the spring portion of the animation.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> flingThenSpring(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float startVelocity, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.FlingConfig flingConfig, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.SpringConfig springConfig) {
        return null;
    }
    
    private final boolean isValidValue(float value) {
        return false;
    }
    
    /**
     * Adds a listener that will be called whenever any property on the animated object is updated.
     * This will be called on every animation frame, with the current value of the animated object
     * and the new property values.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> addUpdateListener(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.UpdateListener<T> listener) {
        return null;
    }
    
    /**
     * Adds a listener that will be called when a property stops animating. This is useful if
     * you care about a specific property ending, or want to use the end value/end velocity from a
     * particular property's animation. If you just want to run an action when all property
     * animations have ended, use [withEndActions].
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> addEndListener(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.EndListener<T> listener) {
        return null;
    }
    
    /**
     * Adds end actions that will be run sequentially when animations for every property involved in
     * this specific animation have ended (unless they were explicitly canceled). For example, if
     * you call:
     *
     * animator
     *  .spring(TRANSLATION_X, ...)
     *  .spring(TRANSLATION_Y, ...)
     *  .withEndAction(action)
     *  .start()
     *
     * 'action' will be run when both TRANSLATION_X and TRANSLATION_Y end.
     *
     * Other properties may still be animating, if those animations were not started in the same
     * call. For example:
     *
     * animator
     *  .spring(ALPHA, ...)
     *  .start()
     *
     * animator
     *  .spring(TRANSLATION_X, ...)
     *  .spring(TRANSLATION_Y, ...)
     *  .withEndAction(action)
     *  .start()
     *
     * 'action' will still be run as soon as TRANSLATION_X and TRANSLATION_Y end, even if ALPHA is
     * still animating.
     *
     * If you want to run actions as soon as a subset of property animations have ended, you want
     * access to the animation's end value/velocity, or you want to run these actions even if the
     * animation is explicitly canceled, use [addEndListener]. End listeners have an allEnded param,
     * which indicates that all relevant animations have ended.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> withEndActions(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit>... endActions) {
        return null;
    }
    
    /**
     * Helper overload so that callers from Java can use Runnables or method references as end
     * actions without having to explicitly return Unit.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator<T> withEndActions(@org.jetbrains.annotations.NotNull()
    java.lang.Runnable... endActions) {
        return null;
    }
    
    public final void setDefaultSpringConfig(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.SpringConfig defaultSpring) {
    }
    
    public final void setDefaultFlingConfig(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.FlingConfig defaultFling) {
    }
    
    /**
     * Set the custom AnimationHandler for all aniatmion in this animator. Set this with null for
     * restoring to default AnimationHandler.
     */
    public final void setCustomAnimationHandler(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.AnimationHandler handler) {
    }
    
    /**
     * Starts the animations!
     */
    public final void start() {
    }
    
    /**
     * Starts the animations for real! This is typically called immediately by [start] unless this
     * animator is under test.
     */
    public final void startInternal$main() {
    }
    
    /**
     * Clear the animator's builder variables.
     */
    private final void clearAnimator() {
    }
    
    /**
     * Retrieves a spring animation for the given property, building one if needed.
     */
    private final androidx.dynamicanimation.animation.SpringAnimation getSpringAnimation(androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, T target) {
        return null;
    }
    
    /**
     * Retrieves a fling animation for the given property, building one if needed.
     */
    private final androidx.dynamicanimation.animation.FlingAnimation getFlingAnimation(androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, T target) {
        return null;
    }
    
    /**
     * Adds update and end listeners to the DynamicAnimation which will dispatch to the internal
     * listeners.
     */
    private final androidx.dynamicanimation.animation.DynamicAnimation<?> configureDynamicAnimation(androidx.dynamicanimation.animation.DynamicAnimation<?> anim, androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property) {
        return null;
    }
    
    /**
     * Return true if any animations are running on the object.
     */
    public final boolean isRunning() {
        return false;
    }
    
    /**
     * Returns whether the given property is animating.
     */
    public final boolean isPropertyAnimating(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property) {
        return false;
    }
    
    /**
     * Returns whether any of the given properties are animating.
     */
    public final boolean arePropertiesAnimating(@org.jetbrains.annotations.NotNull()
    java.util.Set<? extends androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>> properties) {
        return false;
    }
    
    /**
     * Return the set of properties that will begin animating upon calling [start].
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Set<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>> getAnimatedProperties$main() {
        return null;
    }
    
    /**
     * Cancels the given properties. This is typically called immediately by [cancel], unless this
     * animator is under test.
     */
    public final void cancelInternal$main(@org.jetbrains.annotations.NotNull()
    java.util.Set<? extends androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>> properties) {
    }
    
    /**
     * Cancels all in progress animations on all properties.
     */
    public final void cancel() {
    }
    
    /**
     * Cancels in progress animations on the provided properties only.
     */
    public final void cancel(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>... properties) {
    }
    
    private PhysicsAnimator(T target) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @kotlin.Suppress(names = {"UNCHECKED_CAST"})
    public static final <T extends java.lang.Object>com.android.wm.shell.animation.PhysicsAnimator<T> getInstance(@org.jetbrains.annotations.NotNull()
    T target) {
        return null;
    }
    
    /**
     * Set whether all physics animators should log a lot of information about animations.
     * Useful for debugging!
     */
    public static final void setVerboseLogging(boolean debug) {
    }
    
    /**
     * Estimates the end value of a fling that starts at the given value using the provided
     * start velocity and fling configuration.
     *
     * This is only an estimate. Fling animations use a timing-based physics simulation that is
     * non-deterministic, so this exact value may not be reached.
     */
    public static final float estimateFlingEndValue(float startValue, float startVelocity, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.FlingConfig flingConfig) {
        return 0.0F;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String getReadablePropertyName(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<?> property) {
        return null;
    }
    
    /**
     * Data class for representing animation frame updates.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0007\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0005J\t\u0010\t\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\n\u001a\u00020\u0003H\u00c6\u0003J\u001d\u0010\u000b\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\f\u001a\u00020\r2\b\u0010\u000e\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u000f\u001a\u00020\u0010H\u00d6\u0001J\t\u0010\u0011\u001a\u00020\u0012H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007R\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\u0007"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimator$AnimationUpdate;", "", "value", "", "velocity", "(FF)V", "getValue", "()F", "getVelocity", "component1", "component2", "copy", "equals", "", "other", "hashCode", "", "toString", ""})
    public static final class AnimationUpdate {
        private final float value = 0.0F;
        private final float velocity = 0.0F;
        
        public final float getValue() {
            return 0.0F;
        }
        
        public final float getVelocity() {
            return 0.0F;
        }
        
        public AnimationUpdate(float value, float velocity) {
            super();
        }
        
        public final float component1() {
            return 0.0F;
        }
        
        public final float component2() {
            return 0.0F;
        }
        
        /**
         * Data class for representing animation frame updates.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.wm.shell.animation.PhysicsAnimator.AnimationUpdate copy(float value, float velocity) {
            return null;
        }
        
        /**
         * Data class for representing animation frame updates.
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * Data class for representing animation frame updates.
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * Data class for representing animation frame updates.
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     * Internal listener class that receives updates from DynamicAnimation listeners, and dispatches
     * them to the appropriate update/end listeners. This class is also aware of which properties
     * were being animated when the end listeners were passed in, so that we can provide the
     * appropriate value for allEnded to [EndListener.onAnimationEnd].
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000Z\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0002\b\u0007\b\u0080\u0004\u0018\u00002\u00020\u0001Bc\u0012\u0006\u0010\u0002\u001a\u00028\u0000\u0012\u0014\u0010\u0003\u001a\u0010\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\u00050\u0004\u0012\u0012\u0010\u0006\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00028\u00000\b0\u0007\u0012\u0012\u0010\t\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00028\u00000\n0\u0007\u0012\u0016\u0010\u000b\u001a\u0012\u0012\u000e\u0012\f\u0012\u0004\u0012\u00020\r0\fj\u0002`\u000e0\u0007\u00a2\u0006\u0002\u0010\u000fJ\b\u0010\u0016\u001a\u00020\rH\u0002J=\u0010\u0017\u001a\u00020\u00182\u000e\u0010\u0019\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\u00052\u0006\u0010\u001a\u001a\u00020\u00182\u0006\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\u001c2\u0006\u0010\u001e\u001a\u00020\u0018H\u0000\u00a2\u0006\u0002\b\u001fJ-\u0010 \u001a\u00020\r2\u000e\u0010\u0019\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\u00052\u0006\u0010!\u001a\u00020\u001c2\u0006\u0010\"\u001a\u00020\u001cH\u0000\u00a2\u0006\u0002\b#R\u001e\u0010\u000b\u001a\u0012\u0012\u000e\u0012\f\u0012\u0004\u0012\u00020\r0\fj\u0002`\u000e0\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\t\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00028\u00000\n0\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u0003\u001a\u0010\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\u00050\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0002\u001a\u00028\u0000X\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0012R\"\u0010\u0013\u001a\u0016\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\u0005\u0012\u0004\u0012\u00020\u00150\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0006\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00028\u00000\b0\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimator$InternalListener;", "", "target", "properties", "", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "updateListeners", "", "Lcom/android/wm/shell/animation/PhysicsAnimator$UpdateListener;", "endListeners", "Lcom/android/wm/shell/animation/PhysicsAnimator$EndListener;", "endActions", "Lkotlin/Function0;", "", "Lcom/android/wm/shell/animation/EndAction;", "(Lcom/android/wm/shell/animation/PhysicsAnimator;Ljava/lang/Object;Ljava/util/Set;Ljava/util/List;Ljava/util/List;Ljava/util/List;)V", "numPropertiesAnimating", "", "Ljava/lang/Object;", "undispatchedUpdates", "Landroid/util/ArrayMap;", "Lcom/android/wm/shell/animation/PhysicsAnimator$AnimationUpdate;", "maybeDispatchUpdates", "onInternalAnimationEnd", "", "property", "canceled", "finalValue", "", "finalVelocity", "isFling", "onInternalAnimationEnd$main", "onInternalAnimationUpdate", "value", "velocity", "onInternalAnimationUpdate$main"})
    public final class InternalListener {
        
        /**
         * The number of properties whose animations haven't ended.
         */
        private int numPropertiesAnimating;
        
        /**
         * Update values that haven't yet been dispatched because not all property animations have
         * updated yet.
         */
        private final android.util.ArrayMap<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>, com.android.wm.shell.animation.PhysicsAnimator.AnimationUpdate> undispatchedUpdates = null;
        private final T target = null;
        private java.util.Set<? extends androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>> properties;
        private java.util.List<? extends com.android.wm.shell.animation.PhysicsAnimator.UpdateListener<T>> updateListeners;
        private java.util.List<? extends com.android.wm.shell.animation.PhysicsAnimator.EndListener<T>> endListeners;
        private java.util.List<? extends kotlin.jvm.functions.Function0<kotlin.Unit>> endActions;
        
        /**
         * Called when a DynamicAnimation updates.
         */
        public final void onInternalAnimationUpdate$main(@org.jetbrains.annotations.NotNull()
        androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float value, float velocity) {
        }
        
        /**
         * Called when a DynamicAnimation ends.
         *
         * @return True if this listener should be removed from the list of internal listeners, so
         * it no longer receives updates from DynamicAnimations.
         */
        public final boolean onInternalAnimationEnd$main(@org.jetbrains.annotations.NotNull()
        androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, boolean canceled, float finalValue, float finalVelocity, boolean isFling) {
            return false;
        }
        
        /**
         * Dispatch undispatched values if we've received an update from each of the animating
         * properties.
         */
        private final void maybeDispatchUpdates() {
        }
        
        public InternalListener(T target, @org.jetbrains.annotations.NotNull()
        java.util.Set<? extends androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>> properties, @org.jetbrains.annotations.NotNull()
        java.util.List<? extends com.android.wm.shell.animation.PhysicsAnimator.UpdateListener<T>> updateListeners, @org.jetbrains.annotations.NotNull()
        java.util.List<? extends com.android.wm.shell.animation.PhysicsAnimator.EndListener<T>> endListeners, @org.jetbrains.annotations.NotNull()
        java.util.List<? extends kotlin.jvm.functions.Function0<kotlin.Unit>> endActions) {
            super();
        }
    }
    
    /**
     * Container object for spring animation configuration settings. This allows you to store
     * default stiffness and damping ratio values in a single configuration object, which you can
     * pass to [spring].
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0010\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0007\b\u0016\u00a2\u0006\u0002\u0010\u0002B\u0017\b\u0016\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0006B+\b\u0000\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0004\u0012\b\b\u0002\u0010\u0007\u001a\u00020\u0004\u0012\b\b\u0002\u0010\b\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\tJ\u0015\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u0017H\u0000\u00a2\u0006\u0002\b\u0018J\t\u0010\u0019\u001a\u00020\u0004H\u00c6\u0003J\u000e\u0010\u001a\u001a\u00020\u0004H\u00c0\u0003\u00a2\u0006\u0002\b\u001bJ\u000e\u0010\u001c\u001a\u00020\u0004H\u00c0\u0003\u00a2\u0006\u0002\b\u001dJ\u000e\u0010\u001e\u001a\u00020\u0004H\u00c0\u0003\u00a2\u0006\u0002\b\u001fJ1\u0010 \u001a\u00020\u00002\b\b\u0002\u0010\u0003\u001a\u00020\u00042\b\b\u0002\u0010\u0005\u001a\u00020\u00042\b\b\u0002\u0010\u0007\u001a\u00020\u00042\b\b\u0002\u0010\b\u001a\u00020\u0004H\u00c6\u0001J\u0013\u0010!\u001a\u00020\"2\b\u0010#\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010$\u001a\u00020%H\u00d6\u0001J\t\u0010&\u001a\u00020\'H\u00d6\u0001R\u001a\u0010\u0005\u001a\u00020\u0004X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u001a\u0010\b\u001a\u00020\u0004X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000e\u0010\u000b\"\u0004\b\u000f\u0010\rR\u001a\u0010\u0007\u001a\u00020\u0004X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0010\u0010\u000b\"\u0004\b\u0011\u0010\rR\u001a\u0010\u0003\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u000b\"\u0004\b\u0013\u0010\r"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimator$SpringConfig;", "", "()V", "stiffness", "", "dampingRatio", "(FF)V", "startVelocity", "finalPosition", "(FFFF)V", "getDampingRatio$main", "()F", "setDampingRatio$main", "(F)V", "getFinalPosition$main", "setFinalPosition$main", "getStartVelocity$main", "setStartVelocity$main", "getStiffness", "setStiffness", "applyToAnimation", "", "anim", "Landroidx/dynamicanimation/animation/SpringAnimation;", "applyToAnimation$main", "component1", "component2", "component2$main", "component3", "component3$main", "component4", "component4$main", "copy", "equals", "", "other", "hashCode", "", "toString", ""})
    public static final class SpringConfig {
        private float stiffness;
        private float dampingRatio;
        private float startVelocity;
        private float finalPosition;
        
        /**
         * Apply these configuration settings to the given SpringAnimation.
         */
        public final void applyToAnimation$main(@org.jetbrains.annotations.NotNull()
        androidx.dynamicanimation.animation.SpringAnimation anim) {
        }
        
        public final float getStiffness() {
            return 0.0F;
        }
        
        public final void setStiffness(float p0) {
        }
        
        public final float getDampingRatio$main() {
            return 0.0F;
        }
        
        public final void setDampingRatio$main(float p0) {
        }
        
        public final float getStartVelocity$main() {
            return 0.0F;
        }
        
        public final void setStartVelocity$main(float p0) {
        }
        
        public final float getFinalPosition$main() {
            return 0.0F;
        }
        
        public final void setFinalPosition$main(float p0) {
        }
        
        public SpringConfig(float stiffness, float dampingRatio, float startVelocity, float finalPosition) {
            super();
        }
        
        public SpringConfig() {
            super();
        }
        
        public SpringConfig(float stiffness, float dampingRatio) {
            super();
        }
        
        public final float component1() {
            return 0.0F;
        }
        
        public final float component2$main() {
            return 0.0F;
        }
        
        public final float component3$main() {
            return 0.0F;
        }
        
        public final float component4$main() {
            return 0.0F;
        }
        
        /**
         * Container object for spring animation configuration settings. This allows you to store
         * default stiffness and damping ratio values in a single configuration object, which you can
         * pass to [spring].
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.wm.shell.animation.PhysicsAnimator.SpringConfig copy(float stiffness, float dampingRatio, float startVelocity, float finalPosition) {
            return null;
        }
        
        /**
         * Container object for spring animation configuration settings. This allows you to store
         * default stiffness and damping ratio values in a single configuration object, which you can
         * pass to [spring].
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * Container object for spring animation configuration settings. This allows you to store
         * default stiffness and damping ratio values in a single configuration object, which you can
         * pass to [spring].
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * Container object for spring animation configuration settings. This allows you to store
         * default stiffness and damping ratio values in a single configuration object, which you can
         * pass to [spring].
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     * Container object for fling animation configuration settings. This allows you to store default
     * friction values (as well as optional min/max values) in a single configuration object, which
     * you can pass to [fling] and related methods.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0010\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0007\b\u0016\u00a2\u0006\u0002\u0010\u0002B\u000f\b\u0016\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005B\u001f\b\u0016\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0006\u001a\u00020\u0004\u0012\u0006\u0010\u0007\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\bB\'\b\u0000\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0006\u001a\u00020\u0004\u0012\u0006\u0010\u0007\u001a\u00020\u0004\u0012\u0006\u0010\t\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\nJ\u0015\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u0017H\u0000\u00a2\u0006\u0002\b\u0018J\u000e\u0010\u0019\u001a\u00020\u0004H\u00c0\u0003\u00a2\u0006\u0002\b\u001aJ\t\u0010\u001b\u001a\u00020\u0004H\u00c6\u0003J\t\u0010\u001c\u001a\u00020\u0004H\u00c6\u0003J\u000e\u0010\u001d\u001a\u00020\u0004H\u00c0\u0003\u00a2\u0006\u0002\b\u001eJ1\u0010\u001f\u001a\u00020\u00002\b\b\u0002\u0010\u0003\u001a\u00020\u00042\b\b\u0002\u0010\u0006\u001a\u00020\u00042\b\b\u0002\u0010\u0007\u001a\u00020\u00042\b\b\u0002\u0010\t\u001a\u00020\u0004H\u00c6\u0001J\u0013\u0010 \u001a\u00020!2\b\u0010\"\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010#\u001a\u00020$H\u00d6\u0001J\t\u0010%\u001a\u00020&H\u00d6\u0001R\u001a\u0010\u0003\u001a\u00020\u0004X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u0005R\u001a\u0010\u0007\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000e\u0010\f\"\u0004\b\u000f\u0010\u0005R\u001a\u0010\u0006\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0010\u0010\f\"\u0004\b\u0011\u0010\u0005R\u001a\u0010\t\u001a\u00020\u0004X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\f\"\u0004\b\u0013\u0010\u0005"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimator$FlingConfig;", "", "()V", "friction", "", "(F)V", "min", "max", "(FFF)V", "startVelocity", "(FFFF)V", "getFriction$main", "()F", "setFriction$main", "getMax", "setMax", "getMin", "setMin", "getStartVelocity$main", "setStartVelocity$main", "applyToAnimation", "", "anim", "Landroidx/dynamicanimation/animation/FlingAnimation;", "applyToAnimation$main", "component1", "component1$main", "component2", "component3", "component4", "component4$main", "copy", "equals", "", "other", "hashCode", "", "toString", ""})
    public static final class FlingConfig {
        private float friction;
        private float min;
        private float max;
        private float startVelocity;
        
        /**
         * Apply these configuration settings to the given FlingAnimation.
         */
        public final void applyToAnimation$main(@org.jetbrains.annotations.NotNull()
        androidx.dynamicanimation.animation.FlingAnimation anim) {
        }
        
        public final float getFriction$main() {
            return 0.0F;
        }
        
        public final void setFriction$main(float p0) {
        }
        
        public final float getMin() {
            return 0.0F;
        }
        
        public final void setMin(float p0) {
        }
        
        public final float getMax() {
            return 0.0F;
        }
        
        public final void setMax(float p0) {
        }
        
        public final float getStartVelocity$main() {
            return 0.0F;
        }
        
        public final void setStartVelocity$main(float p0) {
        }
        
        public FlingConfig(float friction, float min, float max, float startVelocity) {
            super();
        }
        
        public FlingConfig() {
            super();
        }
        
        public FlingConfig(float friction) {
            super();
        }
        
        public FlingConfig(float friction, float min, float max) {
            super();
        }
        
        public final float component1$main() {
            return 0.0F;
        }
        
        public final float component2() {
            return 0.0F;
        }
        
        public final float component3() {
            return 0.0F;
        }
        
        public final float component4$main() {
            return 0.0F;
        }
        
        /**
         * Container object for fling animation configuration settings. This allows you to store default
         * friction values (as well as optional min/max values) in a single configuration object, which
         * you can pass to [fling] and related methods.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.wm.shell.animation.PhysicsAnimator.FlingConfig copy(float friction, float min, float max, float startVelocity) {
            return null;
        }
        
        /**
         * Container object for fling animation configuration settings. This allows you to store default
         * friction values (as well as optional min/max values) in a single configuration object, which
         * you can pass to [fling] and related methods.
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * Container object for fling animation configuration settings. This allows you to store default
         * friction values (as well as optional min/max values) in a single configuration object, which
         * you can pass to [fling] and related methods.
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * Container object for fling animation configuration settings. This allows you to store default
         * friction values (as well as optional min/max values) in a single configuration object, which
         * you can pass to [fling] and related methods.
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     * Listener for receiving values from in progress animations. Used with
     * [PhysicsAnimator.addUpdateListener].
     *
     * @param <T> The type of the object being animated.
     *   </T>
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\bf\u0018\u0000*\u0004\b\u0001\u0010\u00012\u00020\u0002J;\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00028\u00012$\u0010\u0006\u001a \u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00010\b\u0012\u0004\u0012\u00020\t0\u0007j\b\u0012\u0004\u0012\u00028\u0001`\nH&\u00a2\u0006\u0002\u0010\u000b"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimator$UpdateListener;", "T", "", "onAnimationUpdateForProperty", "", "target", "values", "Landroid/util/ArrayMap;", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "Lcom/android/wm/shell/animation/PhysicsAnimator$AnimationUpdate;", "Lcom/android/wm/shell/animation/UpdateMap;", "(Ljava/lang/Object;Landroid/util/ArrayMap;)V"})
    public static abstract interface UpdateListener<T extends java.lang.Object> {
        
        /**
         * Called on each animation frame with the target object, and a map of FloatPropertyCompat
         * -> AnimationUpdate, containing the latest value and velocity for that property. When
         * multiple properties are animating together, the map will typically contain one entry for
         * each property. However, you should never assume that this is the case - when a property
         * animation ends earlier than the others, you'll receive an UpdateMap containing only that
         * property's final update. Subsequently, you'll only receive updates for the properties
         * that are still animating.
         *
         * Always check that the map contains an update for the property you're interested in before
         * accessing it.
         *
         * @param target The animated object itself.
         * @param values Map of property to AnimationUpdate, which contains that property
         * animation's latest value and velocity. You should never assume that a particular property
         * is present in this map.
         */
        public abstract void onAnimationUpdateForProperty(T target, @org.jetbrains.annotations.NotNull()
        android.util.ArrayMap<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>, com.android.wm.shell.animation.PhysicsAnimator.AnimationUpdate> values);
    }
    
    /**
     * Listener for receiving callbacks when animations end.
     *
     * @param <T> The type of the object being animated.
     *   </T>
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0003\bf\u0018\u0000*\u0004\b\u0001\u0010\u00012\u00020\u0002JM\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00028\u00012\u000e\u0010\u0006\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00010\u00072\u0006\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\t2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\f2\u0006\u0010\u000e\u001a\u00020\tH&\u00a2\u0006\u0002\u0010\u000f"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimator$EndListener;", "T", "", "onAnimationEnd", "", "target", "property", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "wasFling", "", "canceled", "finalValue", "", "finalVelocity", "allRelevantPropertyAnimsEnded", "(Ljava/lang/Object;Landroidx/dynamicanimation/animation/FloatPropertyCompat;ZZFFZ)V"})
    public static abstract interface EndListener<T extends java.lang.Object> {
        
        /**
         * Called with the final animation values as each property animation ends. This can be used
         * to respond to specific property animations concluding (such as hiding a view when ALPHA
         * ends, even if the corresponding TRANSLATION animations have not ended).
         *
         * If you just want to run an action when all of the property animations have ended, you can
         * use [PhysicsAnimator.withEndActions].
         *
         * @param target The animated object itself.
         * @param property The property whose animation has just ended.
         * @param wasFling Whether this property ended after a fling animation (as opposed to a
         * spring animation). If this property was animated via [flingThenSpring], this will be true
         * if the fling animation did not reach the min/max bounds, decelerating to a stop
         * naturally. It will be false if it hit the bounds and was sprung back.
         * @param canceled Whether the animation was explicitly canceled before it naturally ended.
         * @param finalValue The final value of the animated property.
         * @param finalVelocity The final velocity (in pixels per second) of the ended animation.
         * This is typically zero, unless this was a fling animation which ended abruptly due to
         * reaching its configured min/max values.
         * @param allRelevantPropertyAnimsEnded Whether all properties relevant to this end listener
         * have ended. Relevant properties are those which were animated alongside the
         * [addEndListener] call where this animator was passed in. For example:
         *
         * animator
         *   .spring(TRANSLATION_X, 100f)
         *   .spring(TRANSLATION_Y, 200f)
         *   .withEndListener(firstEndListener)
         *   .start()
         *
         * firstEndListener will be called first for TRANSLATION_X, with allEnded = false,
         * because TRANSLATION_Y is still running. When TRANSLATION_Y ends, it'll be called with
         * allEnded = true.
         *
         * If a subsequent call to start() is made with other properties, those properties are not
         * considered relevant and allEnded will still equal true when only TRANSLATION_X and
         * TRANSLATION_Y end. For example, if immediately after the prior example, while
         * TRANSLATION_X and TRANSLATION_Y are still animating, we called:
         *
         * animator.
         *   .spring(SCALE_X, 2f, stiffness = 10f) // That will take awhile...
         *   .withEndListener(secondEndListener)
         *   .start()
         *
         * firstEndListener will still be called with allEnded = true when TRANSLATION_X/Y end, even
         * though SCALE_X is still animating. Similarly, secondEndListener will be called with
         * allEnded = true as soon as SCALE_X ends, even if the translation animations are still
         * running.
         */
        public abstract void onAnimationEnd(T target, @org.jetbrains.annotations.NotNull()
        androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, boolean wasFling, boolean canceled, float finalValue, float finalVelocity, boolean allRelevantPropertyAnimsEnded);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J \u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u000b2\u0006\u0010\r\u001a\u00020\u000b2\u0006\u0010\u000e\u001a\u00020\u000fH\u0007J%\u0010\u0010\u001a\b\u0012\u0004\u0012\u0002H\u00110\u0005\"\b\b\u0001\u0010\u0011*\u00020\u00012\u0006\u0010\u0012\u001a\u0002H\u0011H\u0007\u00a2\u0006\u0002\u0010\u0013J\u0014\u0010\u0014\u001a\u00020\u00152\n\u0010\u0016\u001a\u0006\u0012\u0002\b\u00030\u0017H\u0007J\u0010\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bH\u0007R*\u0010\u0003\u001a\u0012\u0012\u0004\u0012\u00020\u0001\u0012\b\u0012\u0006\u0012\u0002\b\u00030\u00050\u0004X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0006\u0010\u0007\"\u0004\b\b\u0010\t"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimator$Companion;", "", "()V", "instanceConstructor", "Lkotlin/Function1;", "Lcom/android/wm/shell/animation/PhysicsAnimator;", "getInstanceConstructor$main", "()Lkotlin/jvm/functions/Function1;", "setInstanceConstructor$main", "(Lkotlin/jvm/functions/Function1;)V", "estimateFlingEndValue", "", "startValue", "startVelocity", "flingConfig", "Lcom/android/wm/shell/animation/PhysicsAnimator$FlingConfig;", "getInstance", "T", "target", "(Ljava/lang/Object;)Lcom/android/wm/shell/animation/PhysicsAnimator;", "getReadablePropertyName", "", "property", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "setVerboseLogging", "", "debug", ""})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final kotlin.jvm.functions.Function1<java.lang.Object, com.android.wm.shell.animation.PhysicsAnimator<?>> getInstanceConstructor$main() {
            return null;
        }
        
        public final void setInstanceConstructor$main(@org.jetbrains.annotations.NotNull()
        kotlin.jvm.functions.Function1<java.lang.Object, ? extends com.android.wm.shell.animation.PhysicsAnimator<?>> p0) {
        }
        
        @org.jetbrains.annotations.NotNull()
        @kotlin.Suppress(names = {"UNCHECKED_CAST"})
        public final <T extends java.lang.Object>com.android.wm.shell.animation.PhysicsAnimator<T> getInstance(@org.jetbrains.annotations.NotNull()
        T target) {
            return null;
        }
        
        /**
         * Set whether all physics animators should log a lot of information about animations.
         * Useful for debugging!
         */
        public final void setVerboseLogging(boolean debug) {
        }
        
        /**
         * Estimates the end value of a fling that starts at the given value using the provided
         * start velocity and fling configuration.
         *
         * This is only an estimate. Fling animations use a timing-based physics simulation that is
         * non-deterministic, so this exact value may not be reached.
         */
        public final float estimateFlingEndValue(float startValue, float startVelocity, @org.jetbrains.annotations.NotNull()
        com.android.wm.shell.animation.PhysicsAnimator.FlingConfig flingConfig) {
            return 0.0F;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getReadablePropertyName(@org.jetbrains.annotations.NotNull()
        androidx.dynamicanimation.animation.FloatPropertyCompat<?> property) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}
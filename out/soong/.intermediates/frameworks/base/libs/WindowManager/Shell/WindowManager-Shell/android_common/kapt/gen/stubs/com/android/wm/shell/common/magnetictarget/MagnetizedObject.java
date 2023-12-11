package com.android.wm.shell.common.magnetictarget;

import android.annotation.SuppressLint;
import android.content.Context;
import android.database.ContentObserver;
import android.graphics.PointF;
import android.os.Handler;
import android.os.UserHandle;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.provider.Settings;
import android.view.MotionEvent;
import android.view.VelocityTracker;
import android.view.View;
import android.view.ViewConfiguration;
import androidx.dynamicanimation.animation.DynamicAnimation;
import androidx.dynamicanimation.animation.FloatPropertyCompat;
import androidx.dynamicanimation.animation.SpringForce;
import com.android.wm.shell.animation.PhysicsAnimator;

/**
 * Utility class for creating 'magnetized' objects that are attracted to one or more magnetic
 * targets. Magnetic targets attract objects that are dragged near them, and hold them there unless
 * they're moved away or released. Releasing objects inside a magnetic target typically performs an
 * action on the object.
 *
 * MagnetizedObject also supports flinging to targets, which will result in the object being pulled
 * into the target and released as if it was dragged into it.
 *
 * To use this class, either construct an instance with an object of arbitrary type, or use the
 * [MagnetizedObject.magnetizeView] shortcut method if you're magnetizing a view. Then, set
 * [magnetListener] to receive event callbacks. In your touch handler, pass all MotionEvents
 * that move this object to [maybeConsumeMotionEvent]. If that method returns true, consider the
 * event consumed by the MagnetizedObject and don't move the object unless it begins returning false
 * again.
 *
 * @param context Context, used to retrieve a Vibrator instance for vibration effects.
 * @param underlyingObject The actual object that we're magnetizing.
 * @param xProperty Property that sets the x value of the object's position.
 * @param yProperty Property that sets the y value of the object's position.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u009a\u0001\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0007\n\u0002\u0010\u000b\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0013\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0015\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\f\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u001c\b&\u0018\u0000 \u007f*\b\b\u0000\u0010\u0001*\u00020\u00022\u00020\u0002:\u0005\u007f\u0080\u0001\u0081\u0001B5\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00028\u0000\u0012\u000e\u0010\u0006\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\u0007\u0012\u000e\u0010\b\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\u0007\u00a2\u0006\u0002\u0010\tJ\u0010\u0010`\u001a\u00020\u00102\u0006\u0010a\u001a\u00020bH\u0002J\u0016\u0010c\u001a\u00020\f2\u0006\u0010d\u001a\u00020e2\u0006\u0010f\u001a\u00020UJ\u000e\u0010c\u001a\u00020\u00102\u0006\u0010d\u001a\u00020\fJ:\u0010g\u001a\u00020\u00102\u0006\u0010d\u001a\u00020\f2\u0006\u0010h\u001a\u00020\r2\u0006\u0010i\u001a\u00020\r2\u0006\u0010j\u001a\u00020\u000e2\u0010\b\u0002\u0010k\u001a\n\u0012\u0004\u0012\u00020\u0010\u0018\u00010\u000fH\u0002J\r\u0010l\u001a\u00020\u0010H\u0000\u00a2\u0006\u0002\bmJ\u0006\u0010n\u001a\u00020\u0010J\u0015\u0010o\u001a\u00020\r2\u0006\u0010\u0005\u001a\u00028\u0000H&\u00a2\u0006\u0002\u0010pJ\u001d\u0010q\u001a\u00020\u00102\u0006\u0010\u0005\u001a\u00028\u00002\u0006\u0010r\u001a\u00020<H&\u00a2\u0006\u0002\u0010sJ\u0015\u0010t\u001a\u00020\r2\u0006\u0010\u0005\u001a\u00028\u0000H&\u00a2\u0006\u0002\u0010pJ0\u0010u\u001a\u00020\u000e2\u0006\u0010d\u001a\u00020\f2\u0006\u0010v\u001a\u00020\r2\u0006\u0010w\u001a\u00020\r2\u0006\u0010h\u001a\u00020\r2\u0006\u0010i\u001a\u00020\rH\u0002J\u000e\u0010x\u001a\u00020\u000e2\u0006\u0010y\u001a\u00020bJ\u000e\u0010z\u001a\u00020\u00102\u0006\u0010d\u001a\u00020\fJ\r\u0010{\u001a\u00020\u0010H\u0000\u00a2\u0006\u0002\b|J\u0010\u0010}\u001a\u00020\u00102\u0006\u0010~\u001a\u00020UH\u0003RF\u0010\n\u001a.\u0012\u0004\u0012\u00020\f\u0012\u0004\u0012\u00020\r\u0012\u0004\u0012\u00020\r\u0012\u0004\u0012\u00020\u000e\u0012\f\u0012\n\u0012\u0004\u0012\u00020\u0010\u0018\u00010\u000f\u0012\u0004\u0012\u00020\u00100\u000bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u0014\u0010\u0015\u001a\b\u0012\u0004\u0012\u00028\u00000\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\f0\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\u001aR\u001a\u0010\u001b\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001c\u0010\u001d\"\u0004\b\u001e\u0010\u001fR\u001a\u0010 \u001a\u00020\rX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b!\u0010\"\"\u0004\b#\u0010$R\u001a\u0010%\u001a\u00020\rX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b&\u0010\"\"\u0004\b\'\u0010$R\u001a\u0010(\u001a\u00020\rX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b)\u0010\"\"\u0004\b*\u0010$R\u001a\u0010+\u001a\u00020,X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b-\u0010.\"\u0004\b/\u00100R\u001a\u00101\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b2\u0010\u001d\"\u0004\b3\u0010\u001fR\u001a\u00104\u001a\u000205X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b6\u00107\"\u0004\b8\u00109R\u000e\u0010:\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010;\u001a\u00020<X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010=\u001a\u00020\u000e8F\u00a2\u0006\u0006\u001a\u0004\b>\u0010\u001dR\"\u0010?\u001a\n\u0012\u0004\u0012\u00028\u0000\u0018\u00010@X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bA\u0010B\"\u0004\bC\u0010DR\"\u0010E\u001a\n\u0012\u0004\u0012\u00028\u0000\u0018\u00010FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bG\u0010H\"\u0004\bI\u0010JR\u001a\u0010K\u001a\u00020,X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bL\u0010.\"\u0004\bM\u00100R\u001a\u0010N\u001a\u00020\rX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bO\u0010\"\"\u0004\bP\u0010$R\u0010\u0010Q\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010R\u001a\u00020SX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010T\u001a\u00020UX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0013\u0010\u0005\u001a\u00028\u0000\u00a2\u0006\n\n\u0002\u0010X\u001a\u0004\bV\u0010WR\u000e\u0010Y\u001a\u00020ZX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010[\u001a\u00020\\X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0019\u0010\u0006\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b]\u0010^R\u0019\u0010\b\u001a\n\u0012\u0006\b\u0000\u0012\u00028\u00000\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b_\u0010^"}, d2 = {"Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject;", "T", "", "context", "Landroid/content/Context;", "underlyingObject", "xProperty", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "yProperty", "(Landroid/content/Context;Ljava/lang/Object;Landroidx/dynamicanimation/animation/FloatPropertyCompat;Landroidx/dynamicanimation/animation/FloatPropertyCompat;)V", "animateStuckToTarget", "Lkotlin/Function5;", "Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject$MagneticTarget;", "", "", "Lkotlin/Function0;", "", "getAnimateStuckToTarget", "()Lkotlin/jvm/functions/Function5;", "setAnimateStuckToTarget", "(Lkotlin/jvm/functions/Function5;)V", "animator", "Lcom/android/wm/shell/animation/PhysicsAnimator;", "associatedTargets", "Ljava/util/ArrayList;", "getContext", "()Landroid/content/Context;", "flingToTargetEnabled", "getFlingToTargetEnabled", "()Z", "setFlingToTargetEnabled", "(Z)V", "flingToTargetMinVelocity", "getFlingToTargetMinVelocity", "()F", "setFlingToTargetMinVelocity", "(F)V", "flingToTargetWidthPercent", "getFlingToTargetWidthPercent", "setFlingToTargetWidthPercent", "flingUnstuckFromTargetMinVelocity", "getFlingUnstuckFromTargetMinVelocity", "setFlingUnstuckFromTargetMinVelocity", "flungIntoTargetSpringConfig", "Lcom/android/wm/shell/animation/PhysicsAnimator$SpringConfig;", "getFlungIntoTargetSpringConfig", "()Lcom/android/wm/shell/animation/PhysicsAnimator$SpringConfig;", "setFlungIntoTargetSpringConfig", "(Lcom/android/wm/shell/animation/PhysicsAnimator$SpringConfig;)V", "hapticsEnabled", "getHapticsEnabled", "setHapticsEnabled", "magnetListener", "Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject$MagnetListener;", "getMagnetListener", "()Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject$MagnetListener;", "setMagnetListener", "(Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject$MagnetListener;)V", "movedBeyondSlop", "objectLocationOnScreen", "", "objectStuckToTarget", "getObjectStuckToTarget", "physicsAnimatorEndListener", "Lcom/android/wm/shell/animation/PhysicsAnimator$EndListener;", "getPhysicsAnimatorEndListener", "()Lcom/android/wm/shell/animation/PhysicsAnimator$EndListener;", "setPhysicsAnimatorEndListener", "(Lcom/android/wm/shell/animation/PhysicsAnimator$EndListener;)V", "physicsAnimatorUpdateListener", "Lcom/android/wm/shell/animation/PhysicsAnimator$UpdateListener;", "getPhysicsAnimatorUpdateListener", "()Lcom/android/wm/shell/animation/PhysicsAnimator$UpdateListener;", "setPhysicsAnimatorUpdateListener", "(Lcom/android/wm/shell/animation/PhysicsAnimator$UpdateListener;)V", "springConfig", "getSpringConfig", "setSpringConfig", "stickToTargetMaxXVelocity", "getStickToTargetMaxXVelocity", "setStickToTargetMaxXVelocity", "targetObjectIsStuckTo", "touchDown", "Landroid/graphics/PointF;", "touchSlop", "", "getUnderlyingObject", "()Ljava/lang/Object;", "Ljava/lang/Object;", "velocityTracker", "Landroid/view/VelocityTracker;", "vibrator", "Landroid/os/Vibrator;", "getXProperty", "()Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "getYProperty", "addMovement", "event", "Landroid/view/MotionEvent;", "addTarget", "target", "Landroid/view/View;", "magneticFieldRadiusPx", "animateStuckToTargetInternal", "velX", "velY", "flung", "after", "cancelAnimations", "cancelAnimations$main", "clearAllTargets", "getHeight", "(Ljava/lang/Object;)F", "getLocationOnScreen", "loc", "(Ljava/lang/Object;[I)V", "getWidth", "isForcefulFlingTowardsTarget", "rawX", "rawY", "maybeConsumeMotionEvent", "ev", "removeTarget", "updateTargetViews", "updateTargetViews$main", "vibrateIfEnabled", "effectId", "Companion", "MagnetListener", "MagneticTarget"})
public abstract class MagnetizedObject<T extends java.lang.Object> {
    private final com.android.wm.shell.animation.PhysicsAnimator<T> animator = null;
    private final int[] objectLocationOnScreen = null;
    
    /**
     * Targets that have been added to this object. These will all be considered when determining
     * magnetic fields and fling trajectories.
     */
    private final java.util.ArrayList<com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget> associatedTargets = null;
    private final android.view.VelocityTracker velocityTracker = null;
    private final android.os.Vibrator vibrator = null;
    private android.graphics.PointF touchDown;
    private int touchSlop = 0;
    private boolean movedBeyondSlop = false;
    
    /**
     * The target the object is stuck to, or null if the object is not stuck to any target.
     */
    private com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget targetObjectIsStuckTo;
    
    /**
     * Sets the listener to receive events. This must be set, or [maybeConsumeMotionEvent]
     * will always return false and no magnetic effects will occur.
     */
    public com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagnetListener magnetListener;
    
    /**
     * Optional update listener to provide to the PhysicsAnimator that is used to spring the object
     * into the target.
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.wm.shell.animation.PhysicsAnimator.UpdateListener<T> physicsAnimatorUpdateListener;
    
    /**
     * Optional end listener to provide to the PhysicsAnimator that is used to spring the object
     * into the target.
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.wm.shell.animation.PhysicsAnimator.EndListener<T> physicsAnimatorEndListener;
    
    /**
     * Method that is called when the object should be animated stuck to the target. The default
     * implementation uses the object's x and y properties to animate the object centered inside the
     * target. You can override this if you need custom animation.
     *
     * The method is invoked with the MagneticTarget that the object is sticking to, the X and Y
     * velocities of the gesture that brought the object into the magnetic radius, whether or not it
     * was flung, and a callback you must call after your animation completes.
     */
    @org.jetbrains.annotations.NotNull()
    private kotlin.jvm.functions.Function5<? super com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget, ? super java.lang.Float, ? super java.lang.Float, ? super java.lang.Boolean, ? super kotlin.jvm.functions.Function0<kotlin.Unit>, kotlin.Unit> animateStuckToTarget;
    
    /**
     * Sets whether forcefully flinging the object vertically towards a target causes it to be
     * attracted to the target and then released immediately, despite never being dragged within the
     * magnetic field.
     */
    private boolean flingToTargetEnabled = true;
    
    /**
     * If fling to target is enabled, forcefully flinging the object towards a target will cause
     * it to be attracted to the target and then released immediately, despite never being dragged
     * within the magnetic field.
     *
     * This sets the width of the area considered 'near' enough a target to be considered a fling,
     * in terms of percent of the target view's width. For example, setting this to 3f means that
     * flings towards a 100px-wide target will be considered 'near' enough if they're towards the
     * 300px-wide area around the target.
     *
     * Flings whose trajectory intersects the area will be attracted and released - even if the
     * target view itself isn't intersected:
     *
     * |             |
     * |           0 |
     * |          /  |
     * |         /   |
     * |      X /    |
     * |.....###.....|
     *
     *
     * Flings towards the target whose trajectories do not intersect the area will be treated as
     * normal flings and the magnet will leave the object alone:
     *
     * |             |
     * |             |
     * |   0         |
     * |  /          |
     * | /    X      |
     * |.....###.....|
     */
    private float flingToTargetWidthPercent = 3.0F;
    
    /**
     * Sets the minimum velocity (in pixels per second) required to fling an object to the target
     * without dragging it into the magnetic field.
     */
    private float flingToTargetMinVelocity = 4000.0F;
    
    /**
     * Sets the minimum velocity (in pixels per second) required to fling un-stuck an object stuck
     * to the target. If this velocity is reached, the object will be freed even if it wasn't moved
     * outside the magnetic field radius.
     */
    private float flingUnstuckFromTargetMinVelocity = 4000.0F;
    
    /**
     * Sets the maximum X velocity above which the object will not stick to the target. Even if the
     * object is dragged through the magnetic field, it will not stick to the target until the
     * horizontal velocity is below this value.
     */
    private float stickToTargetMaxXVelocity = 2000.0F;
    
    /**
     * Enable or disable haptic vibration effects when the object interacts with the magnetic field.
     *
     * If you're experiencing crashes when the object enters targets, ensure that you have the
     * android.permission.VIBRATE permission!
     */
    private boolean hapticsEnabled = true;
    
    /**
     * Default spring configuration to use for animating the object into a target.
     */
    @org.jetbrains.annotations.NotNull()
    private com.android.wm.shell.animation.PhysicsAnimator.SpringConfig springConfig;
    
    /**
     * Spring configuration to use to spring the object into a target specifically when it's flung
     * towards (rather than dragged near) it.
     */
    @org.jetbrains.annotations.NotNull()
    private com.android.wm.shell.animation.PhysicsAnimator.SpringConfig flungIntoTargetSpringConfig;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    
    /**
     * The actual object that is animated.
     */
    @org.jetbrains.annotations.NotNull()
    private final T underlyingObject = null;
    
    /**
     * Property that gets/sets the object's X value.
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> xProperty = null;
    
    /**
     * Property that gets/sets the object's Y value.
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> yProperty = null;
    
    /**
     * Whether the HAPTIC_FEEDBACK_ENABLED setting is true.
     *
     * We put it in the companion object because we need to register a settings observer and
     * [MagnetizedObject] doesn't have an obvious lifecycle so we don't have a good time to
     * remove that observer. Since this settings is shared among all instances we just let all
     * instances read from this value.
     */
    private static boolean systemHapticsEnabled = false;
    private static boolean hapticSettingObserverInitialized = false;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.wm.shell.common.magnetictarget.MagnetizedObject.Companion Companion = null;
    
    /**
     * Return the width of the object.
     */
    public abstract float getWidth(@org.jetbrains.annotations.NotNull()
    T underlyingObject);
    
    /**
     * Return the height of the object.
     */
    public abstract float getHeight(@org.jetbrains.annotations.NotNull()
    T underlyingObject);
    
    /**
     * Fill the provided array with the location of the top-left of the object, relative to the
     * entire screen. Compare to [View.getLocationOnScreen].
     */
    public abstract void getLocationOnScreen(@org.jetbrains.annotations.NotNull()
    T underlyingObject, @org.jetbrains.annotations.NotNull()
    int[] loc);
    
    public final boolean getObjectStuckToTarget() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagnetListener getMagnetListener() {
        return null;
    }
    
    public final void setMagnetListener(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagnetListener p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.wm.shell.animation.PhysicsAnimator.UpdateListener<T> getPhysicsAnimatorUpdateListener() {
        return null;
    }
    
    public final void setPhysicsAnimatorUpdateListener(@org.jetbrains.annotations.Nullable()
    com.android.wm.shell.animation.PhysicsAnimator.UpdateListener<T> p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.wm.shell.animation.PhysicsAnimator.EndListener<T> getPhysicsAnimatorEndListener() {
        return null;
    }
    
    public final void setPhysicsAnimatorEndListener(@org.jetbrains.annotations.Nullable()
    com.android.wm.shell.animation.PhysicsAnimator.EndListener<T> p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function5<com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget, java.lang.Float, java.lang.Float, java.lang.Boolean, kotlin.jvm.functions.Function0<kotlin.Unit>, kotlin.Unit> getAnimateStuckToTarget() {
        return null;
    }
    
    public final void setAnimateStuckToTarget(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function5<? super com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget, ? super java.lang.Float, ? super java.lang.Float, ? super java.lang.Boolean, ? super kotlin.jvm.functions.Function0<kotlin.Unit>, kotlin.Unit> p0) {
    }
    
    public final boolean getFlingToTargetEnabled() {
        return false;
    }
    
    public final void setFlingToTargetEnabled(boolean p0) {
    }
    
    public final float getFlingToTargetWidthPercent() {
        return 0.0F;
    }
    
    public final void setFlingToTargetWidthPercent(float p0) {
    }
    
    public final float getFlingToTargetMinVelocity() {
        return 0.0F;
    }
    
    public final void setFlingToTargetMinVelocity(float p0) {
    }
    
    public final float getFlingUnstuckFromTargetMinVelocity() {
        return 0.0F;
    }
    
    public final void setFlingUnstuckFromTargetMinVelocity(float p0) {
    }
    
    public final float getStickToTargetMaxXVelocity() {
        return 0.0F;
    }
    
    public final void setStickToTargetMaxXVelocity(float p0) {
    }
    
    public final boolean getHapticsEnabled() {
        return false;
    }
    
    public final void setHapticsEnabled(boolean p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator.SpringConfig getSpringConfig() {
        return null;
    }
    
    public final void setSpringConfig(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.SpringConfig p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.animation.PhysicsAnimator.SpringConfig getFlungIntoTargetSpringConfig() {
        return null;
    }
    
    public final void setFlungIntoTargetSpringConfig(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator.SpringConfig p0) {
    }
    
    /**
     * Adds the provided MagneticTarget to this object. The object will now be attracted to the
     * target if it strays within its magnetic field or is flung towards it.
     *
     * If this target (or its magnetic field) overlaps another target added to this object, the
     * prior target will take priority.
     */
    public final void addTarget(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget target) {
    }
    
    /**
     * Shortcut that accepts a View and a magnetic field radius and adds it as a magnetic target.
     *
     * @return The MagneticTarget instance for the given View. This can be used to change the
     * target's magnetic field radius after it's been added. It can also be added to other
     * magnetized objects.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget addTarget(@org.jetbrains.annotations.NotNull()
    android.view.View target, int magneticFieldRadiusPx) {
        return null;
    }
    
    /**
     * Removes the given target from this object. The target will no longer attract the object.
     */
    public final void removeTarget(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget target) {
    }
    
    /**
     * Removes all associated targets from this object.
     */
    public final void clearAllTargets() {
    }
    
    /**
     * Provide this method with all motion events that move the magnetized object. If the
     * location of the motion events moves within the magnetic field of a target, or indicate a
     * fling-to-target gesture, this method will return true and you should not move the object
     * yourself until it returns false again.
     *
     * Note that even when this method returns true, you should continue to pass along new motion
     * events so that we know when the events move back outside the magnetic field area.
     *
     * This method will always return false if you haven't set a [magnetListener].
     */
    public final boolean maybeConsumeMotionEvent(@org.jetbrains.annotations.NotNull()
    android.view.MotionEvent ev) {
        return false;
    }
    
    /**
     * Plays the given vibration effect if haptics are enabled.
     */
    @android.annotation.SuppressLint(value = {"MissingPermission"})
    private final void vibrateIfEnabled(int effectId) {
    }
    
    /**
     * Adds the movement to the velocity tracker using raw coordinates.
     */
    private final void addMovement(android.view.MotionEvent event) {
    }
    
    /**
     * Animates sticking the object to the provided target with the given start velocities.
     */
    private final void animateStuckToTargetInternal(com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget target, float velX, float velY, boolean flung, kotlin.jvm.functions.Function0<kotlin.Unit> after) {
    }
    
    /**
     * Whether or not the provided values match a 'fast fling' towards the provided target. If it
     * does, we consider it a fling-to-target gesture.
     */
    private final boolean isForcefulFlingTowardsTarget(com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget target, float rawX, float rawY, float velX, float velY) {
        return false;
    }
    
    /**
     * Cancel animations on this object's x/y properties.
     */
    public final void cancelAnimations$main() {
    }
    
    /**
     * Updates the locations on screen of all of the [associatedTargets].
     */
    public final void updateTargetViews$main() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    /**
     * The actual object that is animated.
     */
    @org.jetbrains.annotations.NotNull()
    public final T getUnderlyingObject() {
        return null;
    }
    
    /**
     * Property that gets/sets the object's X value.
     */
    @org.jetbrains.annotations.NotNull()
    public final androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> getXProperty() {
        return null;
    }
    
    /**
     * Property that gets/sets the object's Y value.
     */
    @org.jetbrains.annotations.NotNull()
    public final androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> getYProperty() {
        return null;
    }
    
    public MagnetizedObject(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    T underlyingObject, @org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> xProperty, @org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> yProperty) {
        super();
    }
    
    /**
     * Magnetizes the given view. Magnetized views are attracted to one or more magnetic
     * targets. Magnetic targets attract objects that are dragged near them, and hold them there
     * unless they're moved away or released. Releasing objects inside a magnetic target
     * typically performs an action on the object.
     *
     * Magnetized views can also be flung to targets, which will result in the view being pulled
     * into the target and released as if it was dragged into it.
     *
     * To use the returned MagnetizedObject<View> instance, first set [magnetListener] to
     * receive event callbacks. In your touch handler, pass all MotionEvents that move this view
     * to [maybeConsumeMotionEvent]. If that method returns true, consider the event consumed by
     * MagnetizedObject and don't move the view unless it begins returning false again.
     *
     * The view will be moved via translationX/Y properties, and its
     * width/height will be determined via getWidth()/getHeight(). If you are animating
     * something other than a view, or want to position your view using properties other than
     * translationX/Y, implement an instance of [MagnetizedObject].
     *
     * Note that the magnetic library can't re-order your view automatically. If the view
     * renders on top of the target views, it will obscure the target when it sticks to it.
     * You'll want to bring the view to the front in [MagnetListener.onStuckToTarget].
     */
    @org.jetbrains.annotations.NotNull()
    public static final <T extends android.view.View>com.android.wm.shell.common.magnetictarget.MagnetizedObject<T> magnetizeView(@org.jetbrains.annotations.NotNull()
    T view) {
        return null;
    }
    
    /**
     * Methods for listening to events involving a magnetized object.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0002\b\u0002\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0010\u0010\u0006\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J(\u0010\u0007\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\t2\u0006\u0010\u000b\u001a\u00020\fH&"}, d2 = {"Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject$MagnetListener;", "", "onReleasedInTarget", "", "target", "Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject$MagneticTarget;", "onStuckToTarget", "onUnstuckFromTarget", "velX", "", "velY", "wasFlungOut", ""})
    public static abstract interface MagnetListener {
        
        /**
         * Called when touch events move within the magnetic field of a target, causing the
         * object to animate to the target and become 'stuck' there. The animation happens
         * automatically here - you should not move the object. You can, however, change its state
         * to indicate to the user that it's inside the target and releasing it will have an effect.
         *
         * [maybeConsumeMotionEvent] is now returning true and will continue to do so until a call
         * to [onUnstuckFromTarget] or [onReleasedInTarget].
         *
         * @param target The target that the object is now stuck to.
         */
        public abstract void onStuckToTarget(@org.jetbrains.annotations.NotNull()
        com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget target);
        
        /**
         * Called when the object is no longer stuck to a target. This means that either touch
         * events moved outside of the magnetic field radius, or that a forceful fling out of the
         * target was detected.
         *
         * The object won't be automatically animated out of the target, since you're responsible
         * for moving the object again. You should move it (or animate it) using your own
         * movement/animation logic.
         *
         * Reverse any effects applied in [onStuckToTarget] here.
         *
         * If [wasFlungOut] is true, [maybeConsumeMotionEvent] returned true for the ACTION_UP event
         * that concluded the fling. If [wasFlungOut] is false, that means a drag gesture is ongoing
         * and [maybeConsumeMotionEvent] is now returning false.
         *
         * @param target The target that this object was just unstuck from.
         * @param velX The X velocity of the touch gesture when it exited the magnetic field.
         * @param velY The Y velocity of the touch gesture when it exited the magnetic field.
         * @param wasFlungOut Whether the object was unstuck via a fling gesture. This means that
         * an ACTION_UP event was received, and that the gesture velocity was sufficient to conclude
         * that the user wants to un-stick the object despite no touch events occurring outside of
         * the magnetic field radius.
         */
        public abstract void onUnstuckFromTarget(@org.jetbrains.annotations.NotNull()
        com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget target, float velX, float velY, boolean wasFlungOut);
        
        /**
         * Called when the object is released inside a target, or flung towards it with enough
         * velocity to reach it.
         *
         * @param target The target that the object was released in.
         */
        public abstract void onReleasedInTarget(@org.jetbrains.annotations.NotNull()
        com.android.wm.shell.common.magnetictarget.MagnetizedObject.MagneticTarget target);
    }
    
    /**
     * Represents a target view with a magnetic field radius and cached center-on-screen
     * coordinates.
     *
     * Instances of MagneticTarget are passed to a MagnetizedObject's [addTarget], and can then
     * attract the object if it's dragged near or flung towards it. MagneticTargets can be added to
     * multiple objects.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\u0015\n\u0000\n\u0002\u0010\u0002\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0006\u0010\u0013\u001a\u00020\u0014R\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u001a\u0010\u0004\u001a\u00020\u0005X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject$MagneticTarget;", "", "targetView", "Landroid/view/View;", "magneticFieldRadiusPx", "", "(Landroid/view/View;I)V", "centerOnScreen", "Landroid/graphics/PointF;", "getCenterOnScreen", "()Landroid/graphics/PointF;", "getMagneticFieldRadiusPx", "()I", "setMagneticFieldRadiusPx", "(I)V", "getTargetView", "()Landroid/view/View;", "tempLoc", "", "updateLocationOnScreen", ""})
    public static final class MagneticTarget {
        @org.jetbrains.annotations.NotNull()
        private final android.graphics.PointF centerOnScreen = null;
        private final int[] tempLoc = null;
        @org.jetbrains.annotations.NotNull()
        private final android.view.View targetView = null;
        private int magneticFieldRadiusPx;
        
        @org.jetbrains.annotations.NotNull()
        public final android.graphics.PointF getCenterOnScreen() {
            return null;
        }
        
        public final void updateLocationOnScreen() {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.view.View getTargetView() {
            return null;
        }
        
        public final int getMagneticFieldRadiusPx() {
            return 0;
        }
        
        public final void setMagneticFieldRadiusPx(int p0) {
        }
        
        public MagneticTarget(@org.jetbrains.annotations.NotNull()
        android.view.View targetView, int magneticFieldRadiusPx) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\tH\u0002J%\u0010\n\u001a\b\u0012\u0004\u0012\u0002H\f0\u000b\"\b\b\u0001\u0010\f*\u00020\r2\u0006\u0010\u000e\u001a\u0002H\fH\u0007\u00a2\u0006\u0002\u0010\u000fR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject$Companion;", "", "()V", "hapticSettingObserverInitialized", "", "systemHapticsEnabled", "initHapticSettingObserver", "", "context", "Landroid/content/Context;", "magnetizeView", "Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject;", "T", "Landroid/view/View;", "view", "(Landroid/view/View;)Lcom/android/wm/shell/common/magnetictarget/MagnetizedObject;"})
    public static final class Companion {
        
        private final void initHapticSettingObserver(android.content.Context context) {
        }
        
        /**
         * Magnetizes the given view. Magnetized views are attracted to one or more magnetic
         * targets. Magnetic targets attract objects that are dragged near them, and hold them there
         * unless they're moved away or released. Releasing objects inside a magnetic target
         * typically performs an action on the object.
         *
         * Magnetized views can also be flung to targets, which will result in the view being pulled
         * into the target and released as if it was dragged into it.
         *
         * To use the returned MagnetizedObject<View> instance, first set [magnetListener] to
         * receive event callbacks. In your touch handler, pass all MotionEvents that move this view
         * to [maybeConsumeMotionEvent]. If that method returns true, consider the event consumed by
         * MagnetizedObject and don't move the view unless it begins returning false again.
         *
         * The view will be moved via translationX/Y properties, and its
         * width/height will be determined via getWidth()/getHeight(). If you are animating
         * something other than a view, or want to position your view using properties other than
         * translationX/Y, implement an instance of [MagnetizedObject].
         *
         * Note that the magnetic library can't re-order your view automatically. If the view
         * renders on top of the target views, it will obscure the target when it sticks to it.
         * You'll want to bring the view to the front in [MagnetListener.onStuckToTarget].
         */
        @org.jetbrains.annotations.NotNull()
        public final <T extends android.view.View>com.android.wm.shell.common.magnetictarget.MagnetizedObject<T> magnetizeView(@org.jetbrains.annotations.NotNull()
        T view) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}
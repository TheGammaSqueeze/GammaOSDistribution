package com.android.wm.shell.animation;

import android.os.Handler;
import android.os.Looper;
import android.util.ArrayMap;
import androidx.dynamicanimation.animation.FloatPropertyCompat;
import java.util.*;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;
import kotlin.collections.ArrayList;
import kotlin.collections.HashMap;
import kotlin.collections.HashSet;
import kotlin.collections.Set;

/**
 * Utilities for testing code that uses [PhysicsAnimator].
 *
 * Start by calling [prepareForTest] at the beginning of each test - this will modify the behavior
 * of all PhysicsAnimator instances so that they post animations to the main thread (so they don't
 * crash). It'll also enable the use of the other static helper methods in this class, which you can
 * use to do things like block the test until animations complete (so you can test end states), or
 * verify keyframes.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0080\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\t\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0002\b\u0002\n\u0002\u0010\u0014\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001:\u00016B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\"\u0010\u0013\u001a\u00020\u0014\"\b\b\u0000\u0010\u0015*\u00020\u00012\u000e\u0010\u0016\u001a\n\u0012\u0006\b\u0000\u0012\u0002H\u00150\u0017H\u0007JI\u0010\u0013\u001a\u00020\u0014\"\b\b\u0000\u0010\u0015*\u00020\u00012\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u0002H\u00150\t2\"\u0010\u0016\u001a\u0012\u0012\u000e\b\u0001\u0012\n\u0012\u0006\b\u0000\u0012\u0002H\u00150\u00170\u0019\"\n\u0012\u0006\b\u0000\u0012\u0002H\u00150\u0017H\u0007\u00a2\u0006\u0002\u0010\u001aJ4\u0010\u001b\u001a\u00020\u0014\"\b\b\u0000\u0010\u0015*\u00020\u00012\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u0002H\u00150\t2\u0012\u0010\u001c\u001a\u000e\u0012\u0004\u0012\u0002H\u0015\u0012\u0004\u0012\u00020\f0\u001dH\u0007J\u001e\u0010\u001e\u001a\u00020\u0014\"\b\b\u0000\u0010\u0015*\u00020\u00012\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u0002H\u00150\tJ\"\u0010\u001f\u001a\b\u0012\u0004\u0012\u0002H\u00150\n\"\u0004\b\u0000\u0010\u00152\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u0002H\u00150\tH\u0002JL\u0010 \u001a0\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u0002H\u00150\u0017\u0012\u0014\u0012\u0012\u0012\u0004\u0012\u00020#0\"j\b\u0012\u0004\u0012\u00020#`$0!j\b\u0012\u0004\u0012\u0002H\u0015`%\"\b\b\u0000\u0010\u0015*\u00020\u00012\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u0002H\u00150\tJ\b\u0010&\u001a\u00020\u0014H\u0007J\u0010\u0010\'\u001a\u00020\u00142\u0006\u0010(\u001a\u00020\fH\u0007J\u0010\u0010)\u001a\u00020\u00142\u0006\u0010\r\u001a\u00020\u000eH\u0007J\b\u0010*\u001a\u00020\u0014H\u0007J\u007f\u0010+\u001a\u00020\u0014\"\b\b\u0000\u0010\u0015*\u00020\u00012\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u0002H\u00150\t2\u000e\u0010,\u001a\n\u0012\u0006\b\u0000\u0012\u0002H\u00150\u00172\u0016\u0010-\u001a\u0012\u0012\u0004\u0012\u00020#\u0012\u0004\u0012\u00020\f0\u001dj\u0002`.22\u0010/\u001a\u001a\u0012\u0016\b\u0001\u0012\u0012\u0012\u0004\u0012\u00020#\u0012\u0004\u0012\u00020\f0\u001dj\u0002`.0\u0019\"\u0012\u0012\u0004\u0012\u00020#\u0012\u0004\u0012\u00020\f0\u001dj\u0002`.\u00a2\u0006\u0002\u00100JJ\u0010+\u001a\u00020\u0014\"\b\b\u0000\u0010\u0015*\u00020\u00012\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u0002H\u00150\t2\u000e\u0010,\u001a\n\u0012\u0006\b\u0000\u0012\u0002H\u00150\u00172\u0006\u00101\u001a\u0002022\u0006\u00103\u001a\u0002022\n\u00104\u001a\u000205\"\u000202R\u0014\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00010\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\"\u0010\u0007\u001a\u0016\u0012\b\u0012\u0006\u0012\u0002\b\u00030\t\u0012\b\u0012\u0006\u0012\u0002\b\u00030\n0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\r\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000f\u0010\u0010\"\u0004\b\u0011\u0010\u0012"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimatorTestUtils;", "", "()V", "allAnimatedObjects", "Ljava/util/HashSet;", "animationThreadHandler", "Landroid/os/Handler;", "animatorTestHelpers", "Ljava/util/HashMap;", "Lcom/android/wm/shell/animation/PhysicsAnimator;", "Lcom/android/wm/shell/animation/PhysicsAnimatorTestUtils$AnimatorTestHelper;", "startBlocksUntilAnimationsEnd", "", "timeoutMs", "", "getTimeoutMs", "()J", "setTimeoutMs", "(J)V", "blockUntilAnimationsEnd", "", "T", "properties", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "animator", "", "(Lcom/android/wm/shell/animation/PhysicsAnimator;[Landroidx/dynamicanimation/animation/FloatPropertyCompat;)V", "blockUntilFirstAnimationFrameWhereTrue", "predicate", "Lkotlin/Function1;", "clearAnimationUpdateFrames", "getAnimationTestHelper", "getAnimationUpdateFrames", "Landroid/util/ArrayMap;", "Ljava/util/ArrayList;", "Lcom/android/wm/shell/animation/PhysicsAnimator$AnimationUpdate;", "Lkotlin/collections/ArrayList;", "Lcom/android/wm/shell/animation/UpdateFramesPerProperty;", "prepareForTest", "setAllAnimationsBlock", "block", "setBlockTimeout", "tearDown", "verifyAnimationUpdateFrames", "property", "firstUpdateMatcher", "Lcom/android/wm/shell/animation/UpdateMatcher;", "additionalUpdateMatchers", "(Lcom/android/wm/shell/animation/PhysicsAnimator;Landroidx/dynamicanimation/animation/FloatPropertyCompat;Lkotlin/jvm/functions/Function1;[Lkotlin/jvm/functions/Function1;)V", "startValue", "", "firstTargetValue", "additionalTargetValues", "", "AnimatorTestHelper"})
public final class PhysicsAnimatorTestUtils {
    private static long timeoutMs = 2000L;
    private static boolean startBlocksUntilAnimationsEnd = false;
    private static final android.os.Handler animationThreadHandler = null;
    private static final java.util.HashSet<java.lang.Object> allAnimatedObjects = null;
    private static final java.util.HashMap<com.android.wm.shell.animation.PhysicsAnimator<?>, com.android.wm.shell.animation.PhysicsAnimatorTestUtils.AnimatorTestHelper<?>> animatorTestHelpers = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.wm.shell.animation.PhysicsAnimatorTestUtils INSTANCE = null;
    
    public final long getTimeoutMs() {
        return 0L;
    }
    
    public final void setTimeoutMs(long p0) {
    }
    
    /**
     * Modifies the behavior of all [PhysicsAnimator] instances so that they post animations to the
     * main thread, and report all of their
     */
    public static final void prepareForTest() {
    }
    
    public static final void tearDown() {
    }
    
    /**
     * Sets the maximum time (in milliseconds) to block the test thread while waiting for animations
     * before throwing an exception.
     */
    public static final void setBlockTimeout(long timeoutMs) {
    }
    
    /**
     * Sets whether all animations should block the test thread until they end. This is typically
     * the desired behavior, since you can invoke code that runs an animation and then assert things
     * about its end state.
     */
    public static final void setAllAnimationsBlock(boolean block) {
    }
    
    /**
     * Blocks the calling thread until animations of the given property on the target object end.
     */
    public static final <T extends java.lang.Object>void blockUntilAnimationsEnd(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator<T> animator, @org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>... properties) {
    }
    
    /**
     * Blocks the calling thread until all animations of the given property (on all target objects)
     * have ended. Useful when you don't have access to the objects being animated, but still need
     * to wait for them to end so that other testable side effects occur (such as update/end
     * listeners).
     */
    @kotlin.Suppress(names = {"UNCHECKED_CAST"})
    public static final <T extends java.lang.Object>void blockUntilAnimationsEnd(@org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> properties) {
    }
    
    /**
     * Blocks the calling thread until the first animation frame in which predicate returns true. If
     * the given object isn't animating, returns without blocking.
     */
    public static final <T extends java.lang.Object>void blockUntilFirstAnimationFrameWhereTrue(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator<T> animator, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super T, java.lang.Boolean> predicate) {
    }
    
    /**
     * Verifies that the animator reported animation frame values to update listeners that satisfy
     * the given matchers, in order. Not all frames need to satisfy a matcher - we'll run through
     * all animation frames, and check them against the current predicate. If it returns false, we
     * continue through the frames until it returns true, and then move on to the next matcher.
     * Verification fails if we run out of frames while unsatisfied matchers remain.
     *
     * If verification is successful, all frames to this point are considered 'verified' and will be
     * cleared. Subsequent calls to this method will start verification at the next animation frame.
     *
     * Example: Verify that an animation surpassed x = 50f before going negative.
     * verifyAnimationUpdateFrames(
     *   animator, TRANSLATION_X,
     *   { u -> u.value > 50f },
     *   { u -> u.value < 0f })
     *
     * Example: verify that an animation went backwards at some point while still being on-screen.
     * verifyAnimationUpdateFrames(
     *   animator, TRANSLATION_X,
     *   { u -> u.velocity < 0f && u.value >= 0f })
     *
     * This method is intended to help you test longer, more complicated animations where it's
     * critical that certain values were reached. Using this method to test short animations can
     * fail due to the animation having fewer frames than provided matchers. For example, an
     * animation from x = 1f to x = 5f might only have two frames, at x = 3f and x = 5f. The
     * following would then fail despite it seeming logically sound:
     *
     * verifyAnimationUpdateFrames(
     *   animator, TRANSLATION_X,
     *   { u -> u.value > 1f },
     *   { u -> u.value > 2f },
     *   { u -> u.value > 3f })
     *
     * Tests might also fail if your matchers are too granular, such as this example test after an
     * animation from x = 0f to x = 100f. It's unlikely there was a frame specifically between 2f
     * and 3f.
     *
     * verifyAnimationUpdateFrames(
     *   animator, TRANSLATION_X,
     *   { u -> u.value > 2f && u.value < 3f },
     *   { u -> u.value >= 50f })
     *
     * Failures will print a helpful log of all animation frames so you can see what caused the test
     * to fail.
     */
    public final <T extends java.lang.Object>void verifyAnimationUpdateFrames(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator<T> animator, @org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.wm.shell.animation.PhysicsAnimator.AnimationUpdate, java.lang.Boolean> firstUpdateMatcher, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.wm.shell.animation.PhysicsAnimator.AnimationUpdate, java.lang.Boolean>... additionalUpdateMatchers) {
    }
    
    /**
     * Overload of [verifyAnimationUpdateFrames] that builds matchers for you, from given float
     * values. For example, to verify that an animations passed from 0f to 50f to 100f back to 50f:
     *
     * verifyAnimationUpdateFrames(animator, TRANSLATION_X, 0f, 50f, 100f, 50f)
     *
     * This verifies that update frames were received with values of >= 0f, >= 50f, >= 100f, and
     * <= 50f.
     *
     * The same caveats apply: short animations might not have enough frames to satisfy all of the
     * matchers, and overly specific calls (such as 0f, 1f, 2f, 3f, etc. for an animation from
     * x = 0f to x = 100f) might fail as the animation only had frames at 0f, 25f, 50f, 75f, and
     * 100f. As with [verifyAnimationUpdateFrames], failures will print a helpful log of all frames
     * so you can see what caused the test to fail.
     */
    public final <T extends java.lang.Object>void verifyAnimationUpdateFrames(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator<T> animator, @org.jetbrains.annotations.NotNull()
    androidx.dynamicanimation.animation.FloatPropertyCompat<? super T> property, float startValue, float firstTargetValue, @org.jetbrains.annotations.NotNull()
    float... additionalTargetValues) {
    }
    
    /**
     * Returns all of the values that have ever been reported to update listeners, per property.
     */
    @org.jetbrains.annotations.NotNull()
    @kotlin.Suppress(names = {"UNCHECKED_CAST"})
    public final <T extends java.lang.Object>android.util.ArrayMap<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>, java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator.AnimationUpdate>> getAnimationUpdateFrames(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator<T> animator) {
        return null;
    }
    
    /**
     * Clears animation frame updates from the given animator so they aren't used the next time its
     * passed to [verifyAnimationUpdateFrames].
     */
    public final <T extends java.lang.Object>void clearAnimationUpdateFrames(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.animation.PhysicsAnimator<T> animator) {
    }
    
    @kotlin.Suppress(names = {"UNCHECKED_CAST"})
    private final <T extends java.lang.Object>com.android.wm.shell.animation.PhysicsAnimatorTestUtils.AnimatorTestHelper<T> getAnimationTestHelper(com.android.wm.shell.animation.PhysicsAnimator<T> animator) {
        return null;
    }
    
    private PhysicsAnimatorTestUtils() {
        super();
    }
    
    /**
     * Helper class for testing an animator. This replaces the animator's start action with
     * [startForTest] and adds test listeners to enable other test utility behaviors. We build one
     * these for each Animator and keep them around so we can access the updates.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0006\n\u0002\u0010\"\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000*\u0004\b\u0000\u0010\u00012\u00020\u0002B\u0013\u0012\f\u0010\u0003\u001a\b\u0012\u0004\u0012\u00028\u00000\u0004\u00a2\u0006\u0002\u0010\u0005J\u001b\u0010\u0011\u001a\u00020\u00122\f\u0010\u0013\u001a\b\u0012\u0004\u0012\u00028\u00000\u000eH\u0000\u00a2\u0006\u0002\b\u0014J\u001b\u0010\u0015\u001a\u00020\u00122\f\u0010\u0013\u001a\b\u0012\u0004\u0012\u00028\u00000\u0010H\u0000\u00a2\u0006\u0002\b\u0016J\u001e\u0010\u0017\u001a\u00020\u00122\u0014\u0010\u0018\u001a\u0010\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b0\u0019H\u0002J\r\u0010\u001a\u001a\u00020\u0012H\u0000\u00a2\u0006\u0002\b\u001bJ;\u0010\u001c\u001a0\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b\u0012\u0014\u0012\u0012\u0012\u0004\u0012\u00020\n0\tj\b\u0012\u0004\u0012\u00020\n`\u001d0\u0007j\b\u0012\u0004\u0012\u00028\u0000`\u001eH\u0000\u00a2\u0006\u0002\b\u001fJ\b\u0010 \u001a\u00020\u0012H\u0002R(\u0010\u0006\u001a\u001c\u0012\f\u0012\n\u0012\u0006\b\u0000\u0012\u00028\u00000\b\u0012\n\u0012\b\u0012\u0004\u0012\u00020\n0\t0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0003\u001a\b\u0012\u0004\u0012\u00028\u00000\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\r\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00028\u00000\u000e0\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000f\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00028\u00000\u00100\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/animation/PhysicsAnimatorTestUtils$AnimatorTestHelper;", "T", "", "animator", "Lcom/android/wm/shell/animation/PhysicsAnimator;", "(Lcom/android/wm/shell/animation/PhysicsAnimator;)V", "allUpdates", "Landroid/util/ArrayMap;", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "Ljava/util/ArrayList;", "Lcom/android/wm/shell/animation/PhysicsAnimator$AnimationUpdate;", "currentlyRunningStartInternal", "", "testEndListeners", "Lcom/android/wm/shell/animation/PhysicsAnimator$EndListener;", "testUpdateListeners", "Lcom/android/wm/shell/animation/PhysicsAnimator$UpdateListener;", "addTestEndListener", "", "listener", "addTestEndListener$main", "addTestUpdateListener", "addTestUpdateListener$main", "cancelForTest", "properties", "", "clearUpdates", "clearUpdates$main", "getUpdates", "Lkotlin/collections/ArrayList;", "Lcom/android/wm/shell/animation/UpdateFramesPerProperty;", "getUpdates$main", "startForTest"})
    public static final class AnimatorTestHelper<T extends java.lang.Object> {
        
        /**
         * All updates received for each property animation.
         */
        private final android.util.ArrayMap<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>, java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator.AnimationUpdate>> allUpdates = null;
        private final java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator.EndListener<T>> testEndListeners = null;
        private final java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator.UpdateListener<T>> testUpdateListeners = null;
        
        /**
         * Whether we're currently in the middle of executing startInternal().
         */
        private boolean currentlyRunningStartInternal = false;
        private final com.android.wm.shell.animation.PhysicsAnimator<T> animator = null;
        
        public final void addTestEndListener$main(@org.jetbrains.annotations.NotNull()
        com.android.wm.shell.animation.PhysicsAnimator.EndListener<T> listener) {
        }
        
        public final void addTestUpdateListener$main(@org.jetbrains.annotations.NotNull()
        com.android.wm.shell.animation.PhysicsAnimator.UpdateListener<T> listener) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.util.ArrayMap<androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>, java.util.ArrayList<com.android.wm.shell.animation.PhysicsAnimator.AnimationUpdate>> getUpdates$main() {
            return null;
        }
        
        public final void clearUpdates$main() {
        }
        
        private final void startForTest() {
        }
        
        private final void cancelForTest(java.util.Set<? extends androidx.dynamicanimation.animation.FloatPropertyCompat<? super T>> properties) {
        }
        
        public AnimatorTestHelper(@org.jetbrains.annotations.NotNull()
        com.android.wm.shell.animation.PhysicsAnimator<T> animator) {
            super();
        }
    }
}
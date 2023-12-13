package com.android.systemui.util.animation;

import android.animation.ValueAnimator;
import android.graphics.PointF;
import android.util.MathUtils;
import com.android.systemui.animation.Interpolators;

/**
 * A controller for a [TransitionLayout] which handles state transitions and keeps the transition
 * layout up to date with the desired state.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0002\b\b\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0002\b\u0016\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0015\u001a\u00020\r2\u0006\u0010\u0012\u001a\u00020\u0004H\u0002J\u000e\u0010\u0016\u001a\u00020\r2\u0006\u0010\u0013\u001a\u00020\u0014J*\u0010\u0017\u001a\u00020\u00042\u0006\u0010\u0018\u001a\u00020\u00042\u0006\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u001c2\n\b\u0002\u0010\u001d\u001a\u0004\u0018\u00010\u0004J*\u0010\u001e\u001a\u00020\u00042\u0006\u0010\u001f\u001a\u00020\u00042\u0006\u0010 \u001a\u00020\u00042\u0006\u0010!\u001a\u00020\u001c2\n\b\u0002\u0010\u001d\u001a\u0004\u0018\u00010\u0004J\u000e\u0010\"\u001a\u00020\r2\u0006\u0010\u0012\u001a\u00020\u0004J2\u0010#\u001a\u00020\r2\u0006\u0010\u0012\u001a\u00020\u00042\u0006\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020%2\b\b\u0002\u0010\'\u001a\u00020(2\b\b\u0002\u0010)\u001a\u00020(J\b\u0010*\u001a\u00020\rH\u0002R\u0010\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R.\u0010\u000b\u001a\u0016\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\r\u0018\u00010\fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000e\u0010\u000f\"\u0004\b\u0010\u0010\u0011R\u000e\u0010\u0012\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0014X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/util/animation/TransitionLayoutController;", "", "()V", "animationStartState", "Lcom/android/systemui/util/animation/TransitionViewState;", "animator", "Landroid/animation/ValueAnimator;", "currentHeight", "", "currentState", "currentWidth", "sizeChangedListener", "Lkotlin/Function2;", "", "getSizeChangedListener", "()Lkotlin/jvm/functions/Function2;", "setSizeChangedListener", "(Lkotlin/jvm/functions/Function2;)V", "state", "transitionLayout", "Lcom/android/systemui/util/animation/TransitionLayout;", "applyStateToLayout", "attach", "getGoneState", "viewState", "disappearParameters", "Lcom/android/systemui/util/animation/DisappearParameters;", "goneProgress", "", "reusedState", "getInterpolatedState", "startState", "endState", "progress", "setMeasureState", "setState", "applyImmediately", "", "animate", "duration", "", "delay", "updateStateFromAnimation"})
public class TransitionLayoutController {
    
    /**
     * The layout that this controller controls
     */
    private com.android.systemui.util.animation.TransitionLayout transitionLayout;
    private com.android.systemui.util.animation.TransitionViewState currentState;
    private com.android.systemui.util.animation.TransitionViewState animationStartState;
    private com.android.systemui.util.animation.TransitionViewState state;
    private android.animation.ValueAnimator animator;
    private int currentHeight = 0;
    private int currentWidth = 0;
    @org.jetbrains.annotations.Nullable()
    private kotlin.jvm.functions.Function2<? super java.lang.Integer, ? super java.lang.Integer, kotlin.Unit> sizeChangedListener;
    
    @org.jetbrains.annotations.Nullable()
    public final kotlin.jvm.functions.Function2<java.lang.Integer, java.lang.Integer, kotlin.Unit> getSizeChangedListener() {
        return null;
    }
    
    public final void setSizeChangedListener(@org.jetbrains.annotations.Nullable()
    kotlin.jvm.functions.Function2<? super java.lang.Integer, ? super java.lang.Integer, kotlin.Unit> p0) {
    }
    
    private final void updateStateFromAnimation() {
    }
    
    private final void applyStateToLayout(com.android.systemui.util.animation.TransitionViewState state) {
    }
    
    /**
     * Obtain a state that is gone, based on parameters given.
     *
     * @param viewState the viewState to make gone
     * @param disappearParameters parameters that determine how the view should disappear
     * @param goneProgress how much is the view gone? 0 for not gone at all and 1 for fully
     *                    disappeared
     * @param reusedState optional parameter for state to be reused to avoid allocations
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.TransitionViewState getGoneState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionViewState viewState, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.DisappearParameters disappearParameters, float goneProgress, @org.jetbrains.annotations.Nullable()
    com.android.systemui.util.animation.TransitionViewState reusedState) {
        return null;
    }
    
    /**
     * Get an interpolated state between two viewstates. This interpolates all positions for all
     * widgets as well as it's bounds based on the given input.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.TransitionViewState getInterpolatedState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionViewState startState, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionViewState endState, float progress, @org.jetbrains.annotations.Nullable()
    com.android.systemui.util.animation.TransitionViewState reusedState) {
        return null;
    }
    
    public final void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionLayout transitionLayout) {
    }
    
    /**
     * Set a new state to be applied to the dynamic view.
     *
     * @param state the state to be applied
     * @param animate should this change be animated. If [false] the we will either apply the
     * state immediately if no animation is running, and if one is running, we will update the end
     * value to match the new state.
     * @param applyImmediately should this change be applied immediately, canceling all running
     * animations
     */
    public final void setState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionViewState state, boolean applyImmediately, boolean animate, long duration, long delay) {
    }
    
    /**
     * Set a new state that will be used to measure the view itself and is useful during
     * transitions, where the state set via [setState] may differ from how the view
     * should be measured.
     */
    public final void setMeasureState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionViewState state) {
    }
    
    public TransitionLayoutController() {
        super();
    }
}
package com.android.systemui.controls.management;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.annotation.IdRes;
import android.content.Intent;
import android.transition.Transition;
import android.transition.TransitionValues;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import androidx.lifecycle.Lifecycle;
import androidx.lifecycle.LifecycleObserver;
import androidx.lifecycle.OnLifecycleEvent;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.controls.ui.ControlsUiController;

/**
 * In order to animate, at least one property must be marked on each view that should move.
 * Setting "item" is just a flag to indicate that it should move by the animator.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B(\u0012!\u0010\u0002\u001a\u001d\u0012\u0013\u0012\u00110\u0004\u00a2\u0006\f\b\u0005\u0012\b\b\u0006\u0012\u0004\b\b(\u0007\u0012\u0004\u0012\u00020\b0\u0003\u00a2\u0006\u0002\u0010\tJ\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fH\u0016J\u0010\u0010\u0010\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fH\u0016J&\u0010\u0011\u001a\u0004\u0018\u00010\b2\u0006\u0010\u0012\u001a\u00020\u00132\b\u0010\u0014\u001a\u0004\u0018\u00010\u000f2\b\u0010\u0015\u001a\u0004\u0018\u00010\u000fH\u0016R,\u0010\u0002\u001a\u001d\u0012\u0013\u0012\u00110\u0004\u00a2\u0006\f\b\u0005\u0012\b\b\u0006\u0012\u0004\b\b(\u0007\u0012\u0004\u0012\u00020\b0\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/systemui/controls/management/WindowTransition;", "Landroid/transition/Transition;", "animator", "Lkotlin/Function1;", "Landroid/view/View;", "Lkotlin/ParameterName;", "name", "view", "Landroid/animation/Animator;", "(Lkotlin/jvm/functions/Function1;)V", "getAnimator", "()Lkotlin/jvm/functions/Function1;", "captureEndValues", "", "tv", "Landroid/transition/TransitionValues;", "captureStartValues", "createAnimator", "sceneRoot", "Landroid/view/ViewGroup;", "startValues", "endValues"})
public final class WindowTransition extends android.transition.Transition {
    @org.jetbrains.annotations.NotNull()
    private final kotlin.jvm.functions.Function1<android.view.View, android.animation.Animator> animator = null;
    
    @java.lang.Override()
    public void captureStartValues(@org.jetbrains.annotations.NotNull()
    android.transition.TransitionValues tv) {
    }
    
    @java.lang.Override()
    public void captureEndValues(@org.jetbrains.annotations.NotNull()
    android.transition.TransitionValues tv) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.animation.Animator createAnimator(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup sceneRoot, @org.jetbrains.annotations.Nullable()
    android.transition.TransitionValues startValues, @org.jetbrains.annotations.Nullable()
    android.transition.TransitionValues endValues) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function1<android.view.View, android.animation.Animator> getAnimator() {
        return null;
    }
    
    public WindowTransition(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super android.view.View, ? extends android.animation.Animator> animator) {
        super();
    }
}
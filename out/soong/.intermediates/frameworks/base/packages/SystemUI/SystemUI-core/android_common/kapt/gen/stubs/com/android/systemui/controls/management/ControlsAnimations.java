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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000P\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0006\n\u0002\u0010\u0007\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fJ\u000e\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013J\u001c\u0010\u0014\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000f2\n\b\u0002\u0010\u0015\u001a\u0004\u0018\u00010\u0016H\u0007J\u000e\u0010\u0017\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013J\u001e\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u000e\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\u001eR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlsAnimations;", "", "()V", "ALPHA_ENTER_DELAY", "", "ALPHA_ENTER_DURATION", "ALPHA_EXIT_DURATION", "Y_TRANSLATION_ENTER_DELAY", "Y_TRANSLATION_ENTER_DURATION", "Y_TRANSLATION_EXIT_DURATION", "translationY", "", "enterAnimation", "Landroid/animation/Animator;", "view", "Landroid/view/View;", "enterWindowTransition", "Lcom/android/systemui/controls/management/WindowTransition;", "id", "", "exitAnimation", "onEnd", "Ljava/lang/Runnable;", "exitWindowTransition", "observerForAnimations", "Landroidx/lifecycle/LifecycleObserver;", "Landroid/view/ViewGroup;", "window", "Landroid/view/Window;", "intent", "Landroid/content/Intent;"})
public final class ControlsAnimations {
    private static final long ALPHA_EXIT_DURATION = 183L;
    private static final long ALPHA_ENTER_DELAY = 183L;
    private static final long ALPHA_ENTER_DURATION = 167L;
    private static final long Y_TRANSLATION_EXIT_DURATION = 183L;
    private static final long Y_TRANSLATION_ENTER_DELAY = 0L;
    private static final long Y_TRANSLATION_ENTER_DURATION = 217L;
    private static float translationY = -1.0F;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.management.ControlsAnimations INSTANCE = null;
    
    /**
     * Setup an activity to handle enter/exit animations. [view] should be the root of the content.
     * Fade and translate together.
     */
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.LifecycleObserver observerForAnimations(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup view, @org.jetbrains.annotations.NotNull()
    android.view.Window window, @org.jetbrains.annotations.NotNull()
    android.content.Intent intent) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.animation.Animator enterAnimation(@org.jetbrains.annotations.NotNull()
    android.view.View view) {
        return null;
    }
    
    /**
     * Properly handle animations originating from dialogs. Activity transitions require
     * transitioning between two activities, so expose this method for dialogs to animate
     * on exit.
     */
    @org.jetbrains.annotations.NotNull()
    public static final android.animation.Animator exitAnimation(@org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.Nullable()
    java.lang.Runnable onEnd) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.management.WindowTransition enterWindowTransition(@android.annotation.IdRes()
    int id) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.management.WindowTransition exitWindowTransition(@android.annotation.IdRes()
    int id) {
        return null;
    }
    
    private ControlsAnimations() {
        super();
    }
}
package com.android.systemui.statusbar.notification;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.view.View;
import android.view.ViewGroup;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;

/**
 * Class to help with fading of view groups without fading one subview
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\u0018\u0000 \u00032\u00020\u0001:\u0001\u0003B\u0005\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lcom/android/systemui/statusbar/notification/ViewGroupFadeHelper;", "", "()V", "Companion"})
public final class ViewGroupFadeHelper {
    private static final kotlin.jvm.functions.Function1<android.view.View, java.lang.Boolean> visibilityIncluder = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.ViewGroupFadeHelper.Companion Companion = null;
    
    public ViewGroupFadeHelper() {
        super();
    }
    
    /**
     * Fade out all views of a root except a single child. This will iterate over all children
     * of the view and make sure that the animation works smoothly.
     * @param root the view root to fade the children away
     * @param excludedView which view should remain
     * @param duration the duration of the animation
     */
    public static final void fadeOutAllChildrenExcept(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup root, @org.jetbrains.annotations.NotNull()
    android.view.View excludedView, long duration, @org.jetbrains.annotations.Nullable()
    java.lang.Runnable endRunnable) {
    }
    
    /**
     * Reset all view alphas for views previously transformed away.
     */
    public static final void reset(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup root) {
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010#\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J*\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u00052\u0006\u0010\f\u001a\u00020\r2\b\u0010\u000e\u001a\u0004\u0018\u00010\u000fH\u0007J2\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00050\u00112\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u00052\u0012\u0010\u0012\u001a\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u00060\u0004H\u0002J\u0010\u0010\u0013\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0007R\u001a\u0010\u0003\u001a\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u00060\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/ViewGroupFadeHelper$Companion;", "", "()V", "visibilityIncluder", "Lkotlin/Function1;", "Landroid/view/View;", "", "fadeOutAllChildrenExcept", "", "root", "Landroid/view/ViewGroup;", "excludedView", "duration", "", "endRunnable", "Ljava/lang/Runnable;", "gatherViews", "", "shouldInclude", "reset"})
    public static final class Companion {
        
        /**
         * Fade out all views of a root except a single child. This will iterate over all children
         * of the view and make sure that the animation works smoothly.
         * @param root the view root to fade the children away
         * @param excludedView which view should remain
         * @param duration the duration of the animation
         */
        public final void fadeOutAllChildrenExcept(@org.jetbrains.annotations.NotNull()
        android.view.ViewGroup root, @org.jetbrains.annotations.NotNull()
        android.view.View excludedView, long duration, @org.jetbrains.annotations.Nullable()
        java.lang.Runnable endRunnable) {
        }
        
        private final java.util.Set<android.view.View> gatherViews(android.view.ViewGroup root, android.view.View excludedView, kotlin.jvm.functions.Function1<? super android.view.View, java.lang.Boolean> shouldInclude) {
            return null;
        }
        
        /**
         * Reset all view alphas for views previously transformed away.
         */
        public final void reset(@org.jetbrains.annotations.NotNull()
        android.view.ViewGroup root) {
        }
        
        private Companion() {
            super();
        }
    }
}
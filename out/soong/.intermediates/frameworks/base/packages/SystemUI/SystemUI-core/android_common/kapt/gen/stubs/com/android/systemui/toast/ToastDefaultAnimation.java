package com.android.systemui.toast;

import android.animation.ObjectAnimator;
import android.view.View;
import android.view.animation.LinearInterpolator;
import android.view.animation.PathInterpolator;
import android.animation.AnimatorSet;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\u0018\u0000 \u00032\u00020\u0001:\u0001\u0003B\u0005\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lcom/android/systemui/toast/ToastDefaultAnimation;", "", "()V", "Companion"})
public final class ToastDefaultAnimation {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.toast.ToastDefaultAnimation.Companion Companion = null;
    
    public ToastDefaultAnimation() {
        super();
    }
    
    /**
     * sum of the in and out animation durations cannot exceed
     * [com.android.server.policy.PhoneWindowManager.TOAST_WINDOW_ANIM_BUFFER] to prevent the toast
     * window from being removed before animations are completed
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u0004\u0018\u00010\u00042\u0006\u0010\u0005\u001a\u00020\u0006J\u0010\u0010\u0007\u001a\u0004\u0018\u00010\u00042\u0006\u0010\u0005\u001a\u00020\u0006"}, d2 = {"Lcom/android/systemui/toast/ToastDefaultAnimation$Companion;", "", "()V", "toastIn", "Landroid/animation/AnimatorSet;", "view", "Landroid/view/View;", "toastOut"})
    public static final class Companion {
        
        @org.jetbrains.annotations.Nullable()
        public final android.animation.AnimatorSet toastIn(@org.jetbrains.annotations.NotNull()
        android.view.View view) {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final android.animation.AnimatorSet toastOut(@org.jetbrains.annotations.NotNull()
        android.view.View view) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}
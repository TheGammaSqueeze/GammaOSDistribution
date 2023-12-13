package com.android.systemui.statusbar.events;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.AnimatorSet;
import android.animation.ValueAnimator;
import android.annotation.IntDef;
import android.content.Context;
import android.os.Process;
import android.provider.DeviceConfig;
import android.util.Log;
import android.view.View;
import com.android.systemui.Dumpable;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.policy.CallbackController;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import com.android.systemui.util.Assert;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.time.SystemClock;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\u0016J3\u0010\u0006\u001a\u00020\u00032!\u0010\u0007\u001a\u001d\u0012\u0013\u0012\u00110\t\u00a2\u0006\f\b\n\u0012\b\b\u000b\u0012\u0004\b\b(\f\u0012\u0004\u0012\u00020\r0\b2\u0006\u0010\u0004\u001a\u00020\u0005H\u0016J\u0018\u0010\u000e\u001a\u00020\u00032\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0004\u001a\u00020\u0005H\u0016"}, d2 = {"Lcom/android/systemui/statusbar/events/SystemStatusChipAnimationCallback;", "", "onChipAnimationEnd", "", "state", "", "onChipAnimationStart", "viewCreator", "Lkotlin/Function1;", "Landroid/content/Context;", "Lkotlin/ParameterName;", "name", "context", "Landroid/view/View;", "onChipAnimationUpdate", "animator", "Landroid/animation/ValueAnimator;"})
public abstract interface SystemStatusChipAnimationCallback {
    
    public abstract void onChipAnimationUpdate(@org.jetbrains.annotations.NotNull()
    android.animation.ValueAnimator animator, @SystemAnimationState()
    int state);
    
    public abstract void onChipAnimationStart(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super android.content.Context, ? extends android.view.View> viewCreator, @SystemAnimationState()
    int state);
    
    public abstract void onChipAnimationEnd(@SystemAnimationState()
    int state);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
        
        public static void onChipAnimationUpdate(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.events.SystemStatusChipAnimationCallback $this, @org.jetbrains.annotations.NotNull()
        android.animation.ValueAnimator animator, @SystemAnimationState()
        int state) {
        }
        
        public static void onChipAnimationStart(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.events.SystemStatusChipAnimationCallback $this, @org.jetbrains.annotations.NotNull()
        kotlin.jvm.functions.Function1<? super android.content.Context, ? extends android.view.View> viewCreator, @SystemAnimationState()
        int state) {
        }
        
        public static void onChipAnimationEnd(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.events.SystemStatusChipAnimationCallback $this, @SystemAnimationState()
        int state) {
        }
    }
}
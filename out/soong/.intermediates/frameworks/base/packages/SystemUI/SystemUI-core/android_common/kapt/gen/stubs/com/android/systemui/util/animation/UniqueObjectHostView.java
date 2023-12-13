package com.android.systemui.util.animation;

import android.annotation.SuppressLint;
import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import com.android.systemui.R;

/**
 * A special view that is designed to host a single "unique object". The unique object is
 * dynamically added and removed from this view and may transition to other UniqueObjectHostViews
 * available in the system.
 * This is useful to share a singular instance of a view that can transition between completely
 * independent parts of the view hierarchy.
 * If the view currently hosts the unique object, it's measuring it normally,
 * but if it's not attached, it will obtain the size by requesting a measure, as if it were
 * always attached.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\u0018\u00002\u00020\u0001:\u0001\u0018B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J$\u0010\u000b\u001a\u00020\f2\b\u0010\r\u001a\u0004\u0018\u00010\u000e2\u0006\u0010\u000f\u001a\u00020\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\u0012H\u0016J\b\u0010\u0013\u001a\u00020\u0014H\u0002J\u0018\u0010\u0015\u001a\u00020\f2\u0006\u0010\u0016\u001a\u00020\u00102\u0006\u0010\u0017\u001a\u00020\u0010H\u0015R\u001a\u0010\u0005\u001a\u00020\u0006X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0007\u0010\b\"\u0004\b\t\u0010\n"}, d2 = {"Lcom/android/systemui/util/animation/UniqueObjectHostView;", "Landroid/widget/FrameLayout;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "measurementManager", "Lcom/android/systemui/util/animation/UniqueObjectHostView$MeasurementManager;", "getMeasurementManager", "()Lcom/android/systemui/util/animation/UniqueObjectHostView$MeasurementManager;", "setMeasurementManager", "(Lcom/android/systemui/util/animation/UniqueObjectHostView$MeasurementManager;)V", "addView", "", "child", "Landroid/view/View;", "index", "", "params", "Landroid/view/ViewGroup$LayoutParams;", "isCurrentHost", "", "onMeasure", "widthMeasureSpec", "heightMeasureSpec", "MeasurementManager"})
public final class UniqueObjectHostView extends android.widget.FrameLayout {
    public com.android.systemui.util.animation.UniqueObjectHostView.MeasurementManager measurementManager;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.UniqueObjectHostView.MeasurementManager getMeasurementManager() {
        return null;
    }
    
    public final void setMeasurementManager(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.UniqueObjectHostView.MeasurementManager p0) {
    }
    
    @android.annotation.SuppressLint(value = {"DrawAllocation"})
    @java.lang.Override()
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
    }
    
    @java.lang.Override()
    public void addView(@org.jetbrains.annotations.Nullable()
    android.view.View child, int index, @org.jetbrains.annotations.Nullable()
    android.view.ViewGroup.LayoutParams params) {
    }
    
    private final boolean isCurrentHost() {
        return false;
    }
    
    public UniqueObjectHostView(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/util/animation/UniqueObjectHostView$MeasurementManager;", "", "onMeasure", "Lcom/android/systemui/util/animation/MeasurementOutput;", "input", "Lcom/android/systemui/util/animation/MeasurementInput;"})
    public static abstract interface MeasurementManager {
        
        @org.jetbrains.annotations.NotNull()
        public abstract com.android.systemui.util.animation.MeasurementOutput onMeasure(@org.jetbrains.annotations.NotNull()
        com.android.systemui.util.animation.MeasurementInput input);
    }
}
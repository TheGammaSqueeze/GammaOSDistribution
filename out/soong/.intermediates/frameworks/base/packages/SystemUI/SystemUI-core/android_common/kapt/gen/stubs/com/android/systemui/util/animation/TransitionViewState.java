package com.android.systemui.util.animation;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.PointF;
import android.graphics.Rect;
import android.text.Layout;
import android.util.AttributeSet;
import android.view.View;
import android.view.ViewTreeObserver;
import android.widget.TextView;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.constraintlayout.widget.ConstraintSet;
import com.android.systemui.statusbar.CrossFadeHelper;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0007\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0012\u0010\u001f\u001a\u00020\u00002\n\b\u0002\u0010 \u001a\u0004\u0018\u00010\u0000J\u000e\u0010!\u001a\u00020\"2\u0006\u0010#\u001a\u00020$R\u001a\u0010\u0003\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\bR\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u001a\u0010\r\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000f\u0010\u0010\"\u0004\b\u0011\u0010\u0012R\u0011\u0010\u0013\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\fR&\u0010\u0015\u001a\u000e\u0012\u0004\u0012\u00020\u000e\u0012\u0004\u0012\u00020\u00170\u0016X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0018\u0010\u0019\"\u0004\b\u001a\u0010\u001bR\u001a\u0010\u001c\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001d\u0010\u0010\"\u0004\b\u001e\u0010\u0012"}, d2 = {"Lcom/android/systemui/util/animation/TransitionViewState;", "", "()V", "alpha", "", "getAlpha", "()F", "setAlpha", "(F)V", "contentTranslation", "Landroid/graphics/PointF;", "getContentTranslation", "()Landroid/graphics/PointF;", "height", "", "getHeight", "()I", "setHeight", "(I)V", "translation", "getTranslation", "widgetStates", "", "Lcom/android/systemui/util/animation/WidgetState;", "getWidgetStates", "()Ljava/util/Map;", "setWidgetStates", "(Ljava/util/Map;)V", "width", "getWidth", "setWidth", "copy", "reusedState", "initFromLayout", "", "transitionLayout", "Lcom/android/systemui/util/animation/TransitionLayout;"})
public final class TransitionViewState {
    @org.jetbrains.annotations.NotNull()
    private java.util.Map<java.lang.Integer, com.android.systemui.util.animation.WidgetState> widgetStates;
    private int width = 0;
    private int height = 0;
    private float alpha = 1.0F;
    @org.jetbrains.annotations.NotNull()
    private final android.graphics.PointF translation = null;
    @org.jetbrains.annotations.NotNull()
    private final android.graphics.PointF contentTranslation = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.Integer, com.android.systemui.util.animation.WidgetState> getWidgetStates() {
        return null;
    }
    
    public final void setWidgetStates(@org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.Integer, com.android.systemui.util.animation.WidgetState> p0) {
    }
    
    public final int getWidth() {
        return 0;
    }
    
    public final void setWidth(int p0) {
    }
    
    public final int getHeight() {
        return 0;
    }
    
    public final void setHeight(int p0) {
    }
    
    public final float getAlpha() {
        return 0.0F;
    }
    
    public final void setAlpha(float p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.PointF getTranslation() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.PointF getContentTranslation() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.TransitionViewState copy(@org.jetbrains.annotations.Nullable()
    com.android.systemui.util.animation.TransitionViewState reusedState) {
        return null;
    }
    
    public final void initFromLayout(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionLayout transitionLayout) {
    }
    
    public TransitionViewState() {
        super();
    }
}
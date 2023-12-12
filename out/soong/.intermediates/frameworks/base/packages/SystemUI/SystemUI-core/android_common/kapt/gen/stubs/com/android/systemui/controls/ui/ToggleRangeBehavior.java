package com.android.systemui.controls.ui;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.content.Context;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.LayerDrawable;
import android.os.Bundle;
import android.service.controls.Control;
import android.service.controls.templates.ControlTemplate;
import android.service.controls.templates.RangeTemplate;
import android.service.controls.templates.TemperatureControlTemplate;
import android.service.controls.templates.ToggleRangeTemplate;
import android.util.Log;
import android.util.MathUtils;
import android.view.GestureDetector;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.accessibility.AccessibilityEvent;
import android.view.accessibility.AccessibilityNodeInfo;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;
import java.util.IllegalFormatException;

/**
 * Supports [ToggleRangeTemplate] and [RangeTemplate], as well as when one of those templates is
 * defined as the subtemplate in [TemperatureControlTemplate].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0080\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\r\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\n\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\u0018\u0000 X2\u00020\u0001:\u0002XYB\u0005\u00a2\u0006\u0002\u0010\u0002J\u0006\u0010?\u001a\u00020@J\u0018\u0010A\u001a\u00020@2\u0006\u0010B\u001a\u00020C2\u0006\u0010\t\u001a\u00020\nH\u0016J\u0006\u0010D\u001a\u00020@J\u000e\u0010E\u001a\u00020F2\u0006\u0010G\u001a\u00020FJ \u0010H\u001a\u00020\u001c2\u0006\u0010I\u001a\u00020\u001c2\u0006\u0010J\u001a\u00020\u001c2\u0006\u0010G\u001a\u00020FH\u0002J\u0010\u0010K\u001a\u00020@2\u0006\u0010\'\u001a\u00020(H\u0016J\u0010\u0010L\u001a\u00020F2\u0006\u0010M\u001a\u00020\nH\u0002J\u0010\u0010N\u001a\u00020\n2\u0006\u0010M\u001a\u00020FH\u0002J\u0010\u0010O\u001a\u00020@2\u0006\u0010P\u001a\u000207H\u0002J\u0010\u0010O\u001a\u00020@2\u0006\u0010P\u001a\u00020QH\u0002J\u0010\u0010R\u001a\u00020.2\u0006\u0010P\u001a\u00020SH\u0002J\u001e\u0010T\u001a\u00020@2\u0006\u0010U\u001a\u00020\n2\u0006\u0010V\u001a\u00020.2\u0006\u0010W\u001a\u00020.R\u001a\u0010\u0003\u001a\u00020\u0004X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\bR\u001a\u0010\t\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u001a\u0010\u000f\u001a\u00020\u0010X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u001a\u0010\u0015\u001a\u00020\u0016X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0017\u0010\u0018\"\u0004\b\u0019\u0010\u001aR\u001a\u0010\u001b\u001a\u00020\u001cX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001d\u0010\u001e\"\u0004\b\u001f\u0010 R\u001a\u0010!\u001a\u00020\"X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b#\u0010$\"\u0004\b%\u0010&R\u001a\u0010\'\u001a\u00020(X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b)\u0010*\"\u0004\b+\u0010,R\u001a\u0010-\u001a\u00020.X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b-\u0010/\"\u0004\b0\u00101R\u001a\u00102\u001a\u00020.X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b2\u0010/\"\u0004\b3\u00101R\u0010\u00104\u001a\u0004\u0018\u000105X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u00106\u001a\u000207X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b8\u00109\"\u0004\b:\u0010;R\u001a\u0010<\u001a\u00020\u001cX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b=\u0010\u001e\"\u0004\b>\u0010 "}, d2 = {"Lcom/android/systemui/controls/ui/ToggleRangeBehavior;", "Lcom/android/systemui/controls/ui/Behavior;", "()V", "clipLayer", "Landroid/graphics/drawable/Drawable;", "getClipLayer", "()Landroid/graphics/drawable/Drawable;", "setClipLayer", "(Landroid/graphics/drawable/Drawable;)V", "colorOffset", "", "getColorOffset", "()I", "setColorOffset", "(I)V", "context", "Landroid/content/Context;", "getContext", "()Landroid/content/Context;", "setContext", "(Landroid/content/Context;)V", "control", "Landroid/service/controls/Control;", "getControl", "()Landroid/service/controls/Control;", "setControl", "(Landroid/service/controls/Control;)V", "currentRangeValue", "", "getCurrentRangeValue", "()Ljava/lang/String;", "setCurrentRangeValue", "(Ljava/lang/String;)V", "currentStatusText", "", "getCurrentStatusText", "()Ljava/lang/CharSequence;", "setCurrentStatusText", "(Ljava/lang/CharSequence;)V", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "getCvh", "()Lcom/android/systemui/controls/ui/ControlViewHolder;", "setCvh", "(Lcom/android/systemui/controls/ui/ControlViewHolder;)V", "isChecked", "", "()Z", "setChecked", "(Z)V", "isToggleable", "setToggleable", "rangeAnimator", "Landroid/animation/ValueAnimator;", "rangeTemplate", "Landroid/service/controls/templates/RangeTemplate;", "getRangeTemplate", "()Landroid/service/controls/templates/RangeTemplate;", "setRangeTemplate", "(Landroid/service/controls/templates/RangeTemplate;)V", "templateId", "getTemplateId", "setTemplateId", "beginUpdateRange", "", "bind", "cws", "Lcom/android/systemui/controls/ui/ControlWithState;", "endUpdateRange", "findNearestStep", "", "value", "format", "primaryFormat", "backupFormat", "initialize", "levelToRangeValue", "i", "rangeToLevelValue", "setup", "template", "Landroid/service/controls/templates/ToggleRangeTemplate;", "setupTemplate", "Landroid/service/controls/templates/ControlTemplate;", "updateRange", "level", "checked", "isDragging", "Companion", "ToggleRangeGestureListener"})
public final class ToggleRangeBehavior implements com.android.systemui.controls.ui.Behavior {
    private android.animation.ValueAnimator rangeAnimator;
    public android.graphics.drawable.Drawable clipLayer;
    public java.lang.String templateId;
    public android.service.controls.Control control;
    public com.android.systemui.controls.ui.ControlViewHolder cvh;
    public android.service.controls.templates.RangeTemplate rangeTemplate;
    public android.content.Context context;
    @org.jetbrains.annotations.NotNull()
    private java.lang.CharSequence currentStatusText = "";
    @org.jetbrains.annotations.NotNull()
    private java.lang.String currentRangeValue = "";
    private boolean isChecked = false;
    private boolean isToggleable = false;
    private int colorOffset = 0;
    private static final java.lang.String DEFAULT_FORMAT = "%.1f";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ui.ToggleRangeBehavior.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.Drawable getClipLayer() {
        return null;
    }
    
    public final void setClipLayer(@org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getTemplateId() {
        return null;
    }
    
    public final void setTemplateId(@org.jetbrains.annotations.NotNull()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.controls.Control getControl() {
        return null;
    }
    
    public final void setControl(@org.jetbrains.annotations.NotNull()
    android.service.controls.Control p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.ControlViewHolder getCvh() {
        return null;
    }
    
    public final void setCvh(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.controls.templates.RangeTemplate getRangeTemplate() {
        return null;
    }
    
    public final void setRangeTemplate(@org.jetbrains.annotations.NotNull()
    android.service.controls.templates.RangeTemplate p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    public final void setContext(@org.jetbrains.annotations.NotNull()
    android.content.Context p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getCurrentStatusText() {
        return null;
    }
    
    public final void setCurrentStatusText(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getCurrentRangeValue() {
        return null;
    }
    
    public final void setCurrentRangeValue(@org.jetbrains.annotations.NotNull()
    java.lang.String p0) {
    }
    
    public final boolean isChecked() {
        return false;
    }
    
    public final void setChecked(boolean p0) {
    }
    
    public final boolean isToggleable() {
        return false;
    }
    
    public final void setToggleable(boolean p0) {
    }
    
    public final int getColorOffset() {
        return 0;
    }
    
    public final void setColorOffset(int p0) {
    }
    
    @java.lang.Override()
    public void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh) {
    }
    
    private final void setup(android.service.controls.templates.ToggleRangeTemplate template) {
    }
    
    private final void setup(android.service.controls.templates.RangeTemplate template) {
    }
    
    private final boolean setupTemplate(android.service.controls.templates.ControlTemplate template) {
        return false;
    }
    
    @java.lang.Override()
    public void bind(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlWithState cws, int colorOffset) {
    }
    
    public final void beginUpdateRange() {
    }
    
    public final void updateRange(int level, boolean checked, boolean isDragging) {
    }
    
    private final java.lang.String format(java.lang.String primaryFormat, java.lang.String backupFormat, float value) {
        return null;
    }
    
    private final float levelToRangeValue(int i) {
        return 0.0F;
    }
    
    private final int rangeToLevelValue(float i) {
        return 0;
    }
    
    public final void endUpdateRange() {
    }
    
    public final float findNearestStep(float value) {
        return 0.0F;
    }
    
    public ToggleRangeBehavior() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0010\u0007\n\u0002\b\u0002\b\u0086\u0004\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\f\u001a\u00020\u00062\u0006\u0010\r\u001a\u00020\u000eH\u0016J\u0010\u0010\u000f\u001a\u00020\u00102\u0006\u0010\r\u001a\u00020\u000eH\u0016J(\u0010\u0011\u001a\u00020\u00062\u0006\u0010\u0012\u001a\u00020\u000e2\u0006\u0010\u0013\u001a\u00020\u000e2\u0006\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u0015H\u0016J\u0010\u0010\u0017\u001a\u00020\u00062\u0006\u0010\r\u001a\u00020\u000eH\u0016R\u001a\u0010\u0005\u001a\u00020\u0006X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0007\"\u0004\b\b\u0010\tR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/systemui/controls/ui/ToggleRangeBehavior$ToggleRangeGestureListener;", "Landroid/view/GestureDetector$SimpleOnGestureListener;", "v", "Landroid/view/View;", "(Lcom/android/systemui/controls/ui/ToggleRangeBehavior;Landroid/view/View;)V", "isDragging", "", "()Z", "setDragging", "(Z)V", "getV", "()Landroid/view/View;", "onDown", "e", "Landroid/view/MotionEvent;", "onLongPress", "", "onScroll", "e1", "e2", "xDiff", "", "yDiff", "onSingleTapUp"})
    public final class ToggleRangeGestureListener extends android.view.GestureDetector.SimpleOnGestureListener {
        private boolean isDragging = false;
        @org.jetbrains.annotations.NotNull()
        private final android.view.View v = null;
        
        public final boolean isDragging() {
            return false;
        }
        
        public final void setDragging(boolean p0) {
        }
        
        @java.lang.Override()
        public boolean onDown(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent e) {
            return false;
        }
        
        @java.lang.Override()
        public void onLongPress(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent e) {
        }
        
        @java.lang.Override()
        public boolean onScroll(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent e1, @org.jetbrains.annotations.NotNull()
        android.view.MotionEvent e2, float xDiff, float yDiff) {
            return false;
        }
        
        @java.lang.Override()
        public boolean onSingleTapUp(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent e) {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.view.View getV() {
            return null;
        }
        
        public ToggleRangeGestureListener(@org.jetbrains.annotations.NotNull()
        android.view.View v) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/ToggleRangeBehavior$Companion;", "", "()V", "DEFAULT_FORMAT", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}
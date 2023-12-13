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

/**
 * A view that handles displaying of children and transitions of them in an optimized way,
 * minimizing the number of measure passes, while allowing for maximum flexibility
 * and interruptibility.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000l\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\b\n\u0002\u0010#\n\u0000\n\u0002\u0010%\n\u0002\u0010\u0007\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0011\u0018\u00002\u00020\u0001B%\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\b\u0010!\u001a\u00020\"H\u0002J\b\u0010#\u001a\u00020\"H\u0002J\u0010\u0010$\u001a\u00020\"2\u0006\u0010%\u001a\u00020&H\u0002J\"\u0010\'\u001a\u00020\f2\u0006\u0010(\u001a\u00020)2\u0006\u0010%\u001a\u00020&2\n\b\u0002\u0010*\u001a\u0004\u0018\u00010\fJ\u0012\u0010+\u001a\u00020\"2\b\u0010,\u001a\u0004\u0018\u00010-H\u0014J\b\u0010.\u001a\u00020\"H\u0002J\b\u0010/\u001a\u00020\"H\u0014J\b\u00100\u001a\u00020\"H\u0014J0\u00101\u001a\u00020\"2\u0006\u00102\u001a\u00020\u00102\u0006\u00103\u001a\u00020\u00072\u0006\u00104\u001a\u00020\u00072\u0006\u00105\u001a\u00020\u00072\u0006\u00106\u001a\u00020\u0007H\u0014J\u0018\u00107\u001a\u00020\"2\u0006\u00108\u001a\u00020\u00072\u0006\u00109\u001a\u00020\u0007H\u0014J\u000e\u0010:\u001a\u00020\"2\u0006\u0010;\u001a\u00020\fJ\u0010\u0010<\u001a\u00020\"2\u0006\u0010=\u001a\u00020\u0007H\u0016J\b\u0010>\u001a\u00020\"H\u0002R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R$\u0010\u0013\u001a\u00020\f2\u0006\u0010\u0012\u001a\u00020\f@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0014\u0010\u0015\"\u0004\b\u0016\u0010\u0017R\u0014\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u00070\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u001a\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u001c0\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010 \u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/util/animation/TransitionLayout;", "Landroidx/constraintlayout/widget/ConstraintLayout;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "defStyleAttr", "", "(Landroid/content/Context;Landroid/util/AttributeSet;I)V", "boundsRect", "Landroid/graphics/Rect;", "currentState", "Lcom/android/systemui/util/animation/TransitionViewState;", "desiredMeasureHeight", "desiredMeasureWidth", "isPreDrawApplicatorRegistered", "", "measureAsConstraint", "value", "measureState", "getMeasureState", "()Lcom/android/systemui/util/animation/TransitionViewState;", "setMeasureState", "(Lcom/android/systemui/util/animation/TransitionViewState;)V", "originalGoneChildrenSet", "", "originalViewAlphas", "", "", "preDrawApplicator", "Landroid/view/ViewTreeObserver$OnPreDrawListener;", "transitionVisibility", "updateScheduled", "applyCurrentState", "", "applyCurrentStateOnPredraw", "applySetToFullLayout", "constraintSet", "Landroidx/constraintlayout/widget/ConstraintSet;", "calculateViewState", "input", "Lcom/android/systemui/util/animation/MeasurementInput;", "existing", "dispatchDraw", "canvas", "Landroid/graphics/Canvas;", "ensureViewsNotGone", "onDetachedFromWindow", "onFinishInflate", "onLayout", "changed", "l", "t", "r", "b", "onMeasure", "widthMeasureSpec", "heightMeasureSpec", "setState", "state", "setTransitionVisibility", "visibility", "updateBounds"})
public final class TransitionLayout extends androidx.constraintlayout.widget.ConstraintLayout {
    private final android.graphics.Rect boundsRect = null;
    private final java.util.Set<java.lang.Integer> originalGoneChildrenSet = null;
    private final java.util.Map<java.lang.Integer, java.lang.Float> originalViewAlphas = null;
    private boolean measureAsConstraint = false;
    private com.android.systemui.util.animation.TransitionViewState currentState;
    private boolean updateScheduled = false;
    private boolean isPreDrawApplicatorRegistered = false;
    private int desiredMeasureWidth = 0;
    private int desiredMeasureHeight = 0;
    private int transitionVisibility = android.view.View.VISIBLE;
    
    /**
     * The measured state of this view which is the one we will lay ourselves out with. This
     * may differ from the currentState if there is an external animation or transition running.
     * This state will not be used to measure the widgets, where the current state is preferred.
     */
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.util.animation.TransitionViewState measureState;
    private final android.view.ViewTreeObserver.OnPreDrawListener preDrawApplicator = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.TransitionViewState getMeasureState() {
        return null;
    }
    
    public final void setMeasureState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionViewState value) {
    }
    
    @java.lang.Override()
    public void setTransitionVisibility(int visibility) {
    }
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    @java.lang.Override()
    protected void onDetachedFromWindow() {
    }
    
    /**
     * Apply the current state to the view and its widgets
     */
    private final void applyCurrentState() {
    }
    
    private final void applyCurrentStateOnPredraw() {
    }
    
    @java.lang.Override()
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
    }
    
    @java.lang.Override()
    protected void onLayout(boolean changed, int l, int t, int r, int b) {
    }
    
    @java.lang.Override()
    protected void dispatchDraw(@org.jetbrains.annotations.Nullable()
    android.graphics.Canvas canvas) {
    }
    
    private final void updateBounds() {
    }
    
    /**
     * Calculates a view state for a given ConstraintSet and measurement, saving all positions
     * of all widgets.
     *
     * @param input the measurement input this should be done with
     * @param constraintSet the constraint set to apply
     * @param resusableState the result that we can reuse to minimize memory impact
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.TransitionViewState calculateViewState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.MeasurementInput input, @org.jetbrains.annotations.NotNull()
    androidx.constraintlayout.widget.ConstraintSet constraintSet, @org.jetbrains.annotations.Nullable()
    com.android.systemui.util.animation.TransitionViewState existing) {
        return null;
    }
    
    private final void applySetToFullLayout(androidx.constraintlayout.widget.ConstraintSet constraintSet) {
    }
    
    /**
     * Ensures that our views are never gone but invisible instead, this allows us to animate them
     * without remeasuring.
     */
    private final void ensureViewsNotGone() {
    }
    
    /**
     * Set the state that should be applied to this View
     */
    public final void setState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionViewState state) {
    }
    
    public TransitionLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs, int defStyleAttr) {
        super(null);
    }
    
    public TransitionLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
    
    public TransitionLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
}
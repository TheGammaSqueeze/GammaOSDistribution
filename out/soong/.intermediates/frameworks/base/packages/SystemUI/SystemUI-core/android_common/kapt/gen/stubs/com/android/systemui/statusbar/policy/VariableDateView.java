package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.text.StaticLayout;
import android.util.AttributeSet;
import android.widget.TextView;
import com.android.systemui.R;

/**
 * View for showing a date that can toggle between two different formats depending on size.
 *
 * If no pattern can fit, it will display empty.
 *
 * @see R.styleable.VariableDateView_longDatePattern
 * @see R.styleable.VariableDateView_shortDatePattern
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0002\u0018\u00002\u00020\u0001:\u0001 B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u000e\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u0018J\u0010\u0010\u0019\u001a\u00020\u001a2\b\u0010\u001b\u001a\u0004\u0018\u00010\u0012J\u0018\u0010\u001c\u001a\u00020\u001a2\u0006\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020\u001eH\u0014R\u001a\u0010\u0007\u001a\u00020\bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\n\"\u0004\b\u000b\u0010\fR\u0011\u0010\r\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0010\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0013\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0010"}, d2 = {"Lcom/android/systemui/statusbar/policy/VariableDateView;", "Landroid/widget/TextView;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "freezeSwitching", "", "getFreezeSwitching", "()Z", "setFreezeSwitching", "(Z)V", "longerPattern", "", "getLongerPattern", "()Ljava/lang/String;", "onMeasureListener", "Lcom/android/systemui/statusbar/policy/VariableDateView$OnMeasureListener;", "shorterPattern", "getShorterPattern", "getDesiredWidthForText", "", "text", "", "onAttach", "", "listener", "onMeasure", "widthMeasureSpec", "", "heightMeasureSpec", "OnMeasureListener"})
public final class VariableDateView extends android.widget.TextView {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String longerPattern = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String shorterPattern = null;
    
    /**
     * Freeze the pattern switching
     *
     * Use during animations if the container will change its size but this view should not change
     */
    private boolean freezeSwitching = false;
    private com.android.systemui.statusbar.policy.VariableDateView.OnMeasureListener onMeasureListener;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getLongerPattern() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getShorterPattern() {
        return null;
    }
    
    public final boolean getFreezeSwitching() {
        return false;
    }
    
    public final void setFreezeSwitching(boolean p0) {
    }
    
    public final void onAttach(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.policy.VariableDateView.OnMeasureListener listener) {
    }
    
    @java.lang.Override()
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
    }
    
    public final float getDesiredWidthForText(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence text) {
        return 0.0F;
    }
    
    public VariableDateView(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.util.AttributeSet attrs) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/policy/VariableDateView$OnMeasureListener;", "", "onMeasureAction", "", "availableWidth", ""})
    public static abstract interface OnMeasureListener {
        
        public abstract void onMeasureAction(int availableWidth);
    }
}
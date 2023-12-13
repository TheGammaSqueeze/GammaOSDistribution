package com.android.systemui.util;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.LinearLayout;

/**
 * Basically a normal linear layout but doesn't grow its children with weight 1 even when its
 * measured with exactly.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B%\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\"\u0010\t\u001a\u0014\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u00070\n2\u0006\u0010\f\u001a\u00020\u0007H\u0002J\u0018\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00072\u0006\u0010\u0010\u001a\u00020\u0007H\u0014"}, d2 = {"Lcom/android/systemui/util/NeverExactlyLinearLayout;", "Landroid/widget/LinearLayout;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "defStyleAttr", "", "(Landroid/content/Context;Landroid/util/AttributeSet;I)V", "getNonExactlyMeasureSpec", "Lkotlin/Triple;", "", "measureSpec", "onMeasure", "", "widthMeasureSpec", "heightMeasureSpec"})
public final class NeverExactlyLinearLayout extends android.widget.LinearLayout {
    
    @java.lang.Override()
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
    }
    
    /**
     * Obtain a measurespec that's not exactly
     *
     * @return a triple, where we return 1. if this was exactly, 2. the new measurespec, 3. the size
     *        of the measurespec
     */
    private final kotlin.Triple<java.lang.Boolean, java.lang.Integer, java.lang.Integer> getNonExactlyMeasureSpec(int measureSpec) {
        return null;
    }
    
    public NeverExactlyLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs, int defStyleAttr) {
        super(null);
    }
    
    public NeverExactlyLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
    
    public NeverExactlyLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
}
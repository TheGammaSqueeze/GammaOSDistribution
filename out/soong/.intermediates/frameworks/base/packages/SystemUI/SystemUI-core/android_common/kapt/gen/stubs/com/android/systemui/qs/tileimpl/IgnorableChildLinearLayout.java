package com.android.systemui.qs.tileimpl;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.LinearLayout;

/**
 * [LinearLayout] that can ignore the last child for measuring.
 *
 * The view is measured as regularly, then if [ignoreLastView] is true:
 * * In [LinearLayout.VERTICAL] orientation, the height of the last view is subtracted from the
 * final measured height.
 * * In [LinearLayout.HORIZONTAL] orientation, the width of the last view is subtracted from the
 * final measured width.
 *
 * This allows to measure the view and position it where it should, without it amounting to the
 * total size (only in the direction of layout).
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\b\n\u0002\u0010\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B/\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\tJ\u0018\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00072\u0006\u0010\u0016\u001a\u00020\u0007H\u0014R\u001a\u0010\n\u001a\u00020\u000bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\f\u0010\r\"\u0004\b\u000e\u0010\u000fR\u001a\u0010\u0010\u001a\u00020\u000bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\r\"\u0004\b\u0012\u0010\u000f"}, d2 = {"Lcom/android/systemui/qs/tileimpl/IgnorableChildLinearLayout;", "Landroid/widget/LinearLayout;", "context", "Landroid/content/Context;", "attributeSet", "Landroid/util/AttributeSet;", "defStyleAttr", "", "defStyleRes", "(Landroid/content/Context;Landroid/util/AttributeSet;II)V", "forceUnspecifiedMeasure", "", "getForceUnspecifiedMeasure", "()Z", "setForceUnspecifiedMeasure", "(Z)V", "ignoreLastView", "getIgnoreLastView", "setIgnoreLastView", "onMeasure", "", "widthMeasureSpec", "heightMeasureSpec"})
public final class IgnorableChildLinearLayout extends android.widget.LinearLayout {
    private boolean ignoreLastView = false;
    
    /**
     * Forces [MeasureSpec.UNSPECIFIED] in the direction of layout
     */
    private boolean forceUnspecifiedMeasure = false;
    
    public final boolean getIgnoreLastView() {
        return false;
    }
    
    public final void setIgnoreLastView(boolean p0) {
    }
    
    public final boolean getForceUnspecifiedMeasure() {
        return false;
    }
    
    public final void setForceUnspecifiedMeasure(boolean p0) {
    }
    
    @java.lang.Override()
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
    }
    
    public IgnorableChildLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attributeSet, int defStyleAttr, int defStyleRes) {
        super(null);
    }
    
    public IgnorableChildLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attributeSet, int defStyleAttr) {
        super(null);
    }
    
    public IgnorableChildLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attributeSet) {
        super(null);
    }
    
    public IgnorableChildLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
}
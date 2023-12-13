package com.android.systemui.util;

import android.content.Context;
import android.content.res.Configuration;
import android.util.AttributeSet;
import android.util.DisplayMetrics;
import android.util.TypedValue;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.android.systemui.R;

/**
 * Horizontal [LinearLayout] to contain some text.
 *
 * The height of this container can alternate between two different heights, depending on whether
 * the text takes one line or more.
 *
 * When the text takes multiple lines, it will use the values in the regular attributes (`padding`,
 * `layout_height`). The single line behavior must be set in XML.
 *
 * XML attributes for single line behavior:
 * * `systemui:textViewId`: set the id for the [TextView] that determines the height of the
 *  container
 * * `systemui:singleLineHeight`: sets the height of the view when the text takes up only one line.
 *  By default, it will use [getMinimumHeight].
 * * `systemui:singleLineVerticalPadding`: sets the padding (top and bottom) when then text takes up
 * only one line. By default, it is 0.
 *
 * All dimensions are updated when configuration changes.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0012\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B/\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\tJ\u0012\u0010\u0017\u001a\u00020\u00182\b\u0010\u0019\u001a\u0004\u0018\u00010\u001aH\u0014J\b\u0010\u001b\u001a\u00020\u0018H\u0014J\u0018\u0010\u001c\u001a\u00020\u00182\u0006\u0010\u001d\u001a\u00020\u00072\u0006\u0010\u001e\u001a\u00020\u0007H\u0014J\u0010\u0010\u001f\u001a\u00020\u00182\u0006\u0010 \u001a\u00020\u0007H\u0016J(\u0010!\u001a\u00020\u00182\u0006\u0010\"\u001a\u00020\u00072\u0006\u0010#\u001a\u00020\u00072\u0006\u0010$\u001a\u00020\u00072\u0006\u0010%\u001a\u00020\u0007H\u0016J(\u0010&\u001a\u00020\u00182\u0006\u0010\'\u001a\u00020\u00072\u0006\u0010#\u001a\u00020\u00072\u0006\u0010(\u001a\u00020\u00072\u0006\u0010%\u001a\u00020\u0007H\u0016J/\u0010)\u001a\u00020\u00182\b\u0010*\u001a\u0004\u0018\u00010\u00112\u0006\u0010+\u001a\u00020\u00072\u0012\u0010,\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u00180-H\u0082\bJ\b\u0010.\u001a\u00020\u0018H\u0002R\u0014\u0010\n\u001a\u00020\u000b8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\rR\u000e\u0010\u000e\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0010\u001a\u0004\u0018\u00010\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/util/DualHeightHorizontalLinearLayout;", "Landroid/widget/LinearLayout;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "defStyleAttrs", "", "defStyleRes", "(Landroid/content/Context;Landroid/util/AttributeSet;II)V", "displayMetrics", "Landroid/util/DisplayMetrics;", "getDisplayMetrics", "()Landroid/util/DisplayMetrics;", "initialPadding", "singleLineHeightPx", "singleLineHeightValue", "Landroid/util/TypedValue;", "singleLineVerticalPaddingPx", "singleLineVerticalPaddingValue", "textView", "Landroid/widget/TextView;", "textViewId", "onConfigurationChanged", "", "newConfig", "Landroid/content/res/Configuration;", "onFinishInflate", "onMeasure", "widthMeasureSpec", "heightMeasureSpec", "setOrientation", "orientation", "setPadding", "left", "top", "right", "bottom", "setPaddingRelative", "start", "end", "updateDimensionValue", "tv", "defaultValue", "propertySetter", "Lkotlin/Function1;", "updateResources"})
public final class DualHeightHorizontalLinearLayout extends android.widget.LinearLayout {
    private final android.util.TypedValue singleLineHeightValue = null;
    private int singleLineHeightPx = 0;
    private final android.util.TypedValue singleLineVerticalPaddingValue = null;
    private int singleLineVerticalPaddingPx = 0;
    private final int textViewId = 0;
    private android.widget.TextView textView;
    private int initialPadding;
    
    private final android.util.DisplayMetrics getDisplayMetrics() {
        return null;
    }
    
    @java.lang.Override()
    public void setPadding(int left, int top, int right, int bottom) {
    }
    
    @java.lang.Override()
    public void setPaddingRelative(int start, int top, int end, int bottom) {
    }
    
    @java.lang.Override()
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
    }
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    @java.lang.Override()
    protected void onConfigurationChanged(@org.jetbrains.annotations.Nullable()
    android.content.res.Configuration newConfig) {
    }
    
    @java.lang.Override()
    public void setOrientation(int orientation) {
    }
    
    private final void updateResources() {
    }
    
    private final void updateDimensionValue(android.util.TypedValue tv, int defaultValue, kotlin.jvm.functions.Function1<? super java.lang.Integer, kotlin.Unit> propertySetter) {
    }
    
    public DualHeightHorizontalLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs, int defStyleAttrs, int defStyleRes) {
        super(null);
    }
    
    public DualHeightHorizontalLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs, int defStyleAttrs) {
        super(null);
    }
    
    public DualHeightHorizontalLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
    
    public DualHeightHorizontalLinearLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
}
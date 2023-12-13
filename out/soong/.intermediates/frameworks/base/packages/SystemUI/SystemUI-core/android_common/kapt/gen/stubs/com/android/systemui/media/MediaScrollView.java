package com.android.systemui.media;

import android.content.Context;
import android.os.SystemClock;
import android.util.AttributeSet;
import android.view.InputDevice;
import android.view.MotionEvent;
import android.view.ViewGroup;
import android.widget.HorizontalScrollView;
import com.android.systemui.Gefingerpoken;

/**
 * A ScrollView used in Media that doesn't limit itself to the childs bounds. This is useful
 * when only measuring children but not the parent, when trying to apply a new scroll position
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u000f\u0018\u00002\u00020\u0001B%\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0006\u0010 \u001a\u00020!J\u0006\u0010\"\u001a\u00020\nJ\b\u0010#\u001a\u00020!H\u0014J\u0012\u0010$\u001a\u00020%2\b\u0010&\u001a\u0004\u0018\u00010\'H\u0016J\u0012\u0010(\u001a\u00020%2\b\u0010&\u001a\u0004\u0018\u00010\'H\u0016JP\u0010)\u001a\u00020%2\u0006\u0010*\u001a\u00020\u00072\u0006\u0010+\u001a\u00020\u00072\u0006\u0010,\u001a\u00020\u00072\u0006\u0010-\u001a\u00020\u00072\u0006\u0010.\u001a\u00020\u00072\u0006\u0010/\u001a\u00020\u00072\u0006\u00100\u001a\u00020\u00072\u0006\u00101\u001a\u00020\u00072\u0006\u00102\u001a\u00020%H\u0014J\u0018\u00103\u001a\u00020!2\u0006\u00104\u001a\u00020\u00072\u0006\u00105\u001a\u00020\u0007H\u0016J\u0010\u00106\u001a\u00020\u00072\u0006\u0010,\u001a\u00020\u0007H\u0002R\u001a\u0010\t\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u001e\u0010\u0011\u001a\u00020\u00102\u0006\u0010\u000f\u001a\u00020\u0010@BX\u0086.\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R$\u0010\u0015\u001a\u00020\u00072\u0006\u0010\u0014\u001a\u00020\u00078F@FX\u0086\u000e\u00a2\u0006\f\u001a\u0004\b\u0016\u0010\u0017\"\u0004\b\u0018\u0010\u0019R\u001c\u0010\u001a\u001a\u0004\u0018\u00010\u001bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001c\u0010\u001d\"\u0004\b\u001e\u0010\u001f"}, d2 = {"Lcom/android/systemui/media/MediaScrollView;", "Landroid/widget/HorizontalScrollView;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "defStyleAttr", "", "(Landroid/content/Context;Landroid/util/AttributeSet;I)V", "animationTargetX", "", "getAnimationTargetX", "()F", "setAnimationTargetX", "(F)V", "<set-?>", "Landroid/view/ViewGroup;", "contentContainer", "getContentContainer", "()Landroid/view/ViewGroup;", "value", "relativeScrollX", "getRelativeScrollX", "()I", "setRelativeScrollX", "(I)V", "touchListener", "Lcom/android/systemui/Gefingerpoken;", "getTouchListener", "()Lcom/android/systemui/Gefingerpoken;", "setTouchListener", "(Lcom/android/systemui/Gefingerpoken;)V", "cancelCurrentScroll", "", "getContentTranslation", "onFinishInflate", "onInterceptTouchEvent", "", "ev", "Landroid/view/MotionEvent;", "onTouchEvent", "overScrollBy", "deltaX", "deltaY", "scrollX", "scrollY", "scrollRangeX", "scrollRangeY", "maxOverScrollX", "maxOverScrollY", "isTouchEvent", "scrollTo", "x", "y", "transformScrollX"})
public final class MediaScrollView extends android.widget.HorizontalScrollView {
    private android.view.ViewGroup contentContainer;
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.Gefingerpoken touchListener;
    
    /**
     * The target value of the translation X animation. Only valid if the physicsAnimator is running
     */
    private float animationTargetX = 0.0F;
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.ViewGroup getContentContainer() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.Gefingerpoken getTouchListener() {
        return null;
    }
    
    public final void setTouchListener(@org.jetbrains.annotations.Nullable()
    com.android.systemui.Gefingerpoken p0) {
    }
    
    public final float getAnimationTargetX() {
        return 0.0F;
    }
    
    public final void setAnimationTargetX(float p0) {
    }
    
    /**
     * Get the current content translation. This is usually the normal translationX of the content,
     * but when animating, it might differ
     */
    public final float getContentTranslation() {
        return 0.0F;
    }
    
    /**
     * Convert between the absolute (left-to-right) and relative (start-to-end) scrollX of the media
     * carousel.  The player indices are always relative (start-to-end) and the scrollView.scrollX
     * is always absolute.  This function is its own inverse.
     */
    private final int transformScrollX(int scrollX) {
        return 0;
    }
    
    public final int getRelativeScrollX() {
        return 0;
    }
    
    public final void setRelativeScrollX(int value) {
    }
    
    /**
     * Allow all scrolls to go through, use base implementation
     */
    @java.lang.Override()
    public void scrollTo(int x, int y) {
    }
    
    @java.lang.Override()
    public boolean onInterceptTouchEvent(@org.jetbrains.annotations.Nullable()
    android.view.MotionEvent ev) {
        return false;
    }
    
    @java.lang.Override()
    public boolean onTouchEvent(@org.jetbrains.annotations.Nullable()
    android.view.MotionEvent ev) {
        return false;
    }
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    @java.lang.Override()
    protected boolean overScrollBy(int deltaX, int deltaY, int scrollX, int scrollY, int scrollRangeX, int scrollRangeY, int maxOverScrollX, int maxOverScrollY, boolean isTouchEvent) {
        return false;
    }
    
    /**
     * Cancel the current touch event going on.
     */
    public final void cancelCurrentScroll() {
    }
    
    public MediaScrollView(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs, int defStyleAttr) {
        super(null);
    }
    
    public MediaScrollView(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
    
    public MediaScrollView(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
}
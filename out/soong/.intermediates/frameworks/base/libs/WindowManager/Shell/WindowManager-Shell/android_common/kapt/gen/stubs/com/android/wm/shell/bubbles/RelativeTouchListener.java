package com.android.wm.shell.bubbles;

import android.graphics.PointF;
import android.os.Handler;
import android.os.Looper;
import android.view.MotionEvent;
import android.view.VelocityTracker;
import android.view.View;
import android.view.ViewConfiguration;

/**
 * Listener which receives [onDown], [onMove], and [onUp] events, with relevant information about
 * the coordinates of the touch and the view relative to the initial ACTION_DOWN event and the
 * view's initial position.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0002\b\u0007\b&\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0002J\u0018\u0010\u0012\u001a\u00020\u00042\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0011H&J8\u0010\u0016\u001a\u00020\u000f2\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00112\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u00182\u0006\u0010\u001a\u001a\u00020\u00182\u0006\u0010\u001b\u001a\u00020\u0018H&J\u0018\u0010\u001c\u001a\u00020\u00042\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0011H\u0016JH\u0010\u001d\u001a\u00020\u000f2\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00112\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u00182\u0006\u0010\u001a\u001a\u00020\u00182\u0006\u0010\u001b\u001a\u00020\u00182\u0006\u0010\u001e\u001a\u00020\u00182\u0006\u0010\u001f\u001a\u00020\u0018H&R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010\n\u001a\n \f*\u0004\u0018\u00010\u000b0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/bubbles/RelativeTouchListener;", "Landroid/view/View$OnTouchListener;", "()V", "movedEnough", "", "performedLongClick", "touchDown", "Landroid/graphics/PointF;", "touchSlop", "", "velocityTracker", "Landroid/view/VelocityTracker;", "kotlin.jvm.PlatformType", "viewPositionOnTouchDown", "addMovement", "", "event", "Landroid/view/MotionEvent;", "onDown", "v", "Landroid/view/View;", "ev", "onMove", "viewInitialX", "", "viewInitialY", "dx", "dy", "onTouch", "onUp", "velX", "velY"})
public abstract class RelativeTouchListener implements android.view.View.OnTouchListener {
    
    /**
     * The raw coordinates of the last ACTION_DOWN event.
     */
    private final android.graphics.PointF touchDown = null;
    
    /**
     * The coordinates of the view, at the time of the last ACTION_DOWN event.
     */
    private final android.graphics.PointF viewPositionOnTouchDown = null;
    private final android.view.VelocityTracker velocityTracker = null;
    private int touchSlop = -1;
    private boolean movedEnough = false;
    private boolean performedLongClick = false;
    
    /**
     * Called when an ACTION_DOWN event is received for the given view.
     *
     * @return False if the object is not interested in MotionEvents at this time, or true if we
     * should consume this event and subsequent events, and begin calling [onMove].
     */
    public abstract boolean onDown(@org.jetbrains.annotations.NotNull()
    android.view.View v, @org.jetbrains.annotations.NotNull()
    android.view.MotionEvent ev);
    
    /**
     * Called when an ACTION_MOVE event is received for the given view. This signals that the view
     * is being dragged.
     *
     * @param viewInitialX The view's translationX value when this touch gesture started.
     * @param viewInitialY The view's translationY value when this touch gesture started.
     * @param dx Horizontal distance covered since the initial ACTION_DOWN event, in pixels.
     * @param dy Vertical distance covered since the initial ACTION_DOWN event, in pixels.
     */
    public abstract void onMove(@org.jetbrains.annotations.NotNull()
    android.view.View v, @org.jetbrains.annotations.NotNull()
    android.view.MotionEvent ev, float viewInitialX, float viewInitialY, float dx, float dy);
    
    /**
     * Called when an ACTION_UP event is received for the given view. This signals that a drag or
     * fling gesture has completed.
     *
     * @param viewInitialX The view's translationX value when this touch gesture started.
     * @param viewInitialY The view's translationY value when this touch gesture started.
     * @param dx Horizontal distance covered, in pixels.
     * @param dy Vertical distance covered, in pixels.
     * @param velX The final horizontal velocity of the gesture, in pixels/second.
     * @param velY The final vertical velocity of the gesture, in pixels/second.
     */
    public abstract void onUp(@org.jetbrains.annotations.NotNull()
    android.view.View v, @org.jetbrains.annotations.NotNull()
    android.view.MotionEvent ev, float viewInitialX, float viewInitialY, float dx, float dy, float velX, float velY);
    
    @kotlin.Suppress(names = {"UNCHECKED_CAST"})
    @java.lang.Override()
    public boolean onTouch(@org.jetbrains.annotations.NotNull()
    android.view.View v, @org.jetbrains.annotations.NotNull()
    android.view.MotionEvent ev) {
        return false;
    }
    
    /**
     * Adds a movement to the velocity tracker using raw screen coordinates.
     */
    private final void addMovement(android.view.MotionEvent event) {
    }
    
    public RelativeTouchListener() {
        super();
    }
}
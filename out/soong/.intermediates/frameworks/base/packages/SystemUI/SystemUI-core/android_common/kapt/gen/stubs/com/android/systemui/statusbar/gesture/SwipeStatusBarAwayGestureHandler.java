package com.android.systemui.statusbar.gesture;

import android.content.Context;
import android.os.Looper;
import android.view.Choreographer;
import android.view.Display;
import android.view.InputEvent;
import android.view.MotionEvent;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.shared.system.InputChannelCompat;
import com.android.systemui.shared.system.InputMonitorCompat;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import javax.inject.Inject;

/**
 * A class to detect when a user swipes away the status bar. To be notified when the swipe away
 * gesture is detected, add a callback via [addOnGestureDetectedCallback].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0017\u0018\u00002\u00020\u0001B\u001f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u001c\u0010\u001a\u001a\u00020\r2\u0006\u0010\u001b\u001a\u00020\u000b2\f\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\r0\fJ\u0010\u0010\u001d\u001a\u00020\r2\u0006\u0010\u001e\u001a\u00020\u001fH\u0002J\u000e\u0010 \u001a\u00020\r2\u0006\u0010\u001b\u001a\u00020\u000bJ\b\u0010!\u001a\u00020\rH\u0002J\b\u0010\"\u001a\u00020\rH\u0002R \u0010\t\u001a\u0014\u0012\u0004\u0012\u00020\u000b\u0012\n\u0012\b\u0012\u0004\u0012\u00020\r0\f0\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000e\u001a\u0004\u0018\u00010\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0010\u001a\u0004\u0018\u00010\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/gesture/SwipeStatusBarAwayGestureHandler;", "", "context", "Landroid/content/Context;", "statusBarWindowController", "Lcom/android/systemui/statusbar/window/StatusBarWindowController;", "logger", "Lcom/android/systemui/statusbar/gesture/SwipeStatusBarAwayGestureLogger;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/window/StatusBarWindowController;Lcom/android/systemui/statusbar/gesture/SwipeStatusBarAwayGestureLogger;)V", "callbacks", "", "", "Lkotlin/Function0;", "", "inputMonitor", "Lcom/android/systemui/shared/system/InputMonitorCompat;", "inputReceiver", "Lcom/android/systemui/shared/system/InputChannelCompat$InputEventReceiver;", "monitoringCurrentTouch", "", "startTime", "", "startY", "", "swipeDistanceThreshold", "", "addOnGestureDetectedCallback", "tag", "callback", "onInputEvent", "ev", "Landroid/view/InputEvent;", "removeOnGestureDetectedCallback", "startGestureListening", "stopGestureListening"})
@com.android.systemui.dagger.SysUISingleton()
public class SwipeStatusBarAwayGestureHandler {
    
    /**
     * Active callbacks, each associated with a tag. Gestures will only be monitored if
     * [callbacks.size] > 0.
     */
    private final java.util.Map<java.lang.String, kotlin.jvm.functions.Function0<kotlin.Unit>> callbacks = null;
    private float startY = 0.0F;
    private long startTime = 0L;
    private boolean monitoringCurrentTouch = false;
    private com.android.systemui.shared.system.InputMonitorCompat inputMonitor;
    private com.android.systemui.shared.system.InputChannelCompat.InputEventReceiver inputReceiver;
    private int swipeDistanceThreshold;
    private final com.android.systemui.statusbar.window.StatusBarWindowController statusBarWindowController = null;
    private final com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureLogger logger = null;
    
    /**
     * Adds a callback that will be triggered when the swipe away gesture is detected.
     */
    public final void addOnGestureDetectedCallback(@org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> callback) {
    }
    
    /**
     * Removes the callback.
     */
    public final void removeOnGestureDetectedCallback(@org.jetbrains.annotations.NotNull()
    java.lang.String tag) {
    }
    
    private final void onInputEvent(android.view.InputEvent ev) {
    }
    
    /**
     * Start listening for the swipe gesture.
     */
    private final void startGestureListening() {
    }
    
    /**
     * Stop listening for the swipe gesture.
     */
    private final void stopGestureListening() {
    }
    
    @javax.inject.Inject()
    public SwipeStatusBarAwayGestureHandler(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.window.StatusBarWindowController statusBarWindowController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureLogger logger) {
        super();
    }
}
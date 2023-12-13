package com.android.systemui.statusbar.events;

import android.animation.ValueAnimator;
import android.content.Context;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.FrameLayout;
import com.android.systemui.R;
import com.android.systemui.statusbar.phone.StatusBarLocationPublisher;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import javax.inject.Inject;

/**
 * Controls the view for system event animations.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\\\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u001f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\b\u0010\u0016\u001a\u00020\u0017H\u0002J\b\u0010\u0018\u001a\u00020\u0019H\u0002J\b\u0010\u001a\u001a\u00020\u001bH\u0002J\b\u0010\u001c\u001a\u00020\u0017H\u0002J\u0010\u0010\u001d\u001a\u00020\u00172\u0006\u0010\u001e\u001a\u00020\u001bH\u0016J3\u0010\u001f\u001a\u00020\u00172!\u0010 \u001a\u001d\u0012\u0013\u0012\u00110\u0003\u00a2\u0006\f\b\"\u0012\b\b#\u0012\u0004\b\b(\u0002\u0012\u0004\u0012\u00020\n0!2\u0006\u0010\u001e\u001a\u00020\u001bH\u0016J\u0018\u0010$\u001a\u00020\u00172\u0006\u0010%\u001a\u00020&2\u0006\u0010\u001e\u001a\u00020\u001bH\u0016J\b\u0010\'\u001a\u00020\u001bH\u0002J\b\u0010(\u001a\u00020\u001bH\u0002R\u000e\u0010\t\u001a\u00020\nX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\r\u001a\u0004\u0018\u00010\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\u0011\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u000f@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u0013\"\u0004\b\u0014\u0010\u0015R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/events/SystemEventChipAnimationController;", "Lcom/android/systemui/statusbar/events/SystemStatusChipAnimationCallback;", "context", "Landroid/content/Context;", "statusBarWindowController", "Lcom/android/systemui/statusbar/window/StatusBarWindowController;", "locationPublisher", "Lcom/android/systemui/statusbar/phone/StatusBarLocationPublisher;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/window/StatusBarWindowController;Lcom/android/systemui/statusbar/phone/StatusBarLocationPublisher;)V", "animationDotView", "Landroid/view/View;", "animationWindowView", "Landroid/widget/FrameLayout;", "currentAnimatedView", "initialized", "", "value", "showPersistentDot", "getShowPersistentDot", "()Z", "setShowPersistentDot", "(Z)V", "init", "", "layoutParamsDefault", "Landroid/widget/FrameLayout$LayoutParams;", "left", "", "maybeUpdateShowDot", "onChipAnimationEnd", "state", "onChipAnimationStart", "viewCreator", "Lkotlin/Function1;", "Lkotlin/ParameterName;", "name", "onChipAnimationUpdate", "animator", "Landroid/animation/ValueAnimator;", "right", "start"})
public final class SystemEventChipAnimationController implements com.android.systemui.statusbar.events.SystemStatusChipAnimationCallback {
    private boolean showPersistentDot = false;
    private android.widget.FrameLayout animationWindowView;
    private android.view.View animationDotView;
    private android.view.View currentAnimatedView;
    private boolean initialized = false;
    private final android.content.Context context = null;
    private final com.android.systemui.statusbar.window.StatusBarWindowController statusBarWindowController = null;
    private final com.android.systemui.statusbar.phone.StatusBarLocationPublisher locationPublisher = null;
    
    public final boolean getShowPersistentDot() {
        return false;
    }
    
    public final void setShowPersistentDot(boolean value) {
    }
    
    @java.lang.Override()
    public void onChipAnimationStart(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super android.content.Context, ? extends android.view.View> viewCreator, @SystemAnimationState()
    int state) {
    }
    
    @java.lang.Override()
    public void onChipAnimationEnd(@SystemAnimationState()
    int state) {
    }
    
    @java.lang.Override()
    public void onChipAnimationUpdate(@org.jetbrains.annotations.NotNull()
    android.animation.ValueAnimator animator, @SystemAnimationState()
    int state) {
    }
    
    private final void maybeUpdateShowDot() {
    }
    
    private final void init() {
    }
    
    private final int start() {
        return 0;
    }
    
    private final int right() {
        return 0;
    }
    
    private final int left() {
        return 0;
    }
    
    private final android.widget.FrameLayout.LayoutParams layoutParamsDefault() {
        return null;
    }
    
    @javax.inject.Inject()
    public SystemEventChipAnimationController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.window.StatusBarWindowController statusBarWindowController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBarLocationPublisher locationPublisher) {
        super();
    }
}
package com.android.systemui.statusbar.phone;

import android.util.DisplayMetrics;
import android.view.View;
import com.android.internal.logging.nano.MetricsProto.MetricsEvent;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogLevel;
import com.android.systemui.log.dagger.LSShadeTransitionLog;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.row.ExpandableView;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000P\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0004\n\u0002\u0010\u0007\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u000e\u0018\u00002\u00020\u0001B!\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u000e\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fJ\u000e\u0010\r\u001a\u00020\n2\u0006\u0010\u000e\u001a\u00020\u000fJ\u0006\u0010\u0010\u001a\u00020\nJ\u0006\u0010\u0011\u001a\u00020\nJ\u000e\u0010\u0012\u001a\u00020\n2\u0006\u0010\u0013\u001a\u00020\u0014J\u0010\u0010\u0015\u001a\u00020\n2\b\u0010\u0016\u001a\u0004\u0018\u00010\u0017J\u0018\u0010\u0018\u001a\u00020\n2\b\u0010\u0016\u001a\u0004\u0018\u00010\u00192\u0006\u0010\u001a\u001a\u00020\u001bJ\u0010\u0010\u001c\u001a\u00020\n2\b\u0010\u0016\u001a\u0004\u0018\u00010\u0019J\u000e\u0010\u001d\u001a\u00020\n2\u0006\u0010\u001e\u001a\u00020\fJ\u0006\u0010\u001f\u001a\u00020\nJ\u0006\u0010 \u001a\u00020\nJ\u000e\u0010!\u001a\u00020\n2\u0006\u0010\"\u001a\u00020\fJ\u0006\u0010#\u001a\u00020\nJ\u0006\u0010$\u001a\u00020\nJ\u0006\u0010%\u001a\u00020\nJ\u0006\u0010&\u001a\u00020\nJ\u000e\u0010\'\u001a\u00020\n2\u0006\u0010(\u001a\u00020\fJ\u0010\u0010)\u001a\u00020\n2\b\u0010\u0016\u001a\u0004\u0018\u00010\u0019R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/LSShadeTransitionLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "lockscreenGestureLogger", "Lcom/android/systemui/statusbar/phone/LockscreenGestureLogger;", "displayMetrics", "Landroid/util/DisplayMetrics;", "(Lcom/android/systemui/log/LogBuffer;Lcom/android/systemui/statusbar/phone/LockscreenGestureLogger;Landroid/util/DisplayMetrics;)V", "logAnimationCancelled", "", "isPulse", "", "logDefaultGoToFullShadeAnimation", "delay", "", "logDragDownAborted", "logDragDownAmountResetWhenFullyCollapsed", "logDragDownAnimation", "target", "", "logDragDownStarted", "startingChild", "Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "logDraggedDown", "Landroid/view/View;", "dragLengthY", "", "logDraggedDownLockDownShade", "logGoingToLockedShade", "customAnimationHandler", "logGoingToLockedShadeAborted", "logOnHideKeyguard", "logPulseExpansionFinished", "cancelled", "logPulseExpansionStarted", "logPulseHeightNotResetWhenFullyCollapsed", "logShadeDisabledOnGoToLockedShade", "logShowBouncerOnGoToLockedShade", "logTryGoToLockedShade", "keyguard", "logUnSuccessfulDragDown"})
public final class LSShadeTransitionLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    private final com.android.systemui.statusbar.phone.LockscreenGestureLogger lockscreenGestureLogger = null;
    private final android.util.DisplayMetrics displayMetrics = null;
    
    public final void logUnSuccessfulDragDown(@org.jetbrains.annotations.Nullable()
    android.view.View startingChild) {
    }
    
    public final void logDragDownAborted() {
    }
    
    public final void logDragDownStarted(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.row.ExpandableView startingChild) {
    }
    
    public final void logDraggedDownLockDownShade(@org.jetbrains.annotations.Nullable()
    android.view.View startingChild) {
    }
    
    public final void logDraggedDown(@org.jetbrains.annotations.Nullable()
    android.view.View startingChild, int dragLengthY) {
    }
    
    public final void logDefaultGoToFullShadeAnimation(long delay) {
    }
    
    public final void logTryGoToLockedShade(boolean keyguard) {
    }
    
    public final void logShadeDisabledOnGoToLockedShade() {
    }
    
    public final void logShowBouncerOnGoToLockedShade() {
    }
    
    public final void logGoingToLockedShade(boolean customAnimationHandler) {
    }
    
    public final void logOnHideKeyguard() {
    }
    
    public final void logPulseExpansionStarted() {
    }
    
    public final void logPulseExpansionFinished(boolean cancelled) {
    }
    
    public final void logDragDownAnimation(float target) {
    }
    
    public final void logAnimationCancelled(boolean isPulse) {
    }
    
    public final void logDragDownAmountResetWhenFullyCollapsed() {
    }
    
    public final void logPulseHeightNotResetWhenFullyCollapsed() {
    }
    
    public final void logGoingToLockedShadeAborted() {
    }
    
    @javax.inject.Inject()
    public LSShadeTransitionLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.LSShadeTransitionLog()
    com.android.systemui.log.LogBuffer buffer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.LockscreenGestureLogger lockscreenGestureLogger, @org.jetbrains.annotations.NotNull()
    android.util.DisplayMetrics displayMetrics) {
        super();
    }
}
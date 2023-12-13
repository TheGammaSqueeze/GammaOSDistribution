package com.android.systemui.statusbar.policy;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import com.android.systemui.R;
import com.android.systemui.util.concurrency.DelayableExecutor;
import javax.inject.Inject;

/**
 * Listens for important battery states and sends non-dismissible system notifications if there is a
 * problem
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\'\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0010\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u0014H\u0016J\b\u0010\u001c\u001a\u00020\u001aH\u0002J\u0006\u0010\u001d\u001a\u00020\u001aJ\u0006\u0010\u001e\u001a\u00020\u001aR\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u001a\u0010\u0013\u001a\u00020\u0014X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0015\u0010\u0016\"\u0004\b\u0017\u0010\u0018"}, d2 = {"Lcom/android/systemui/statusbar/policy/BatteryStateNotifier;", "Lcom/android/systemui/statusbar/policy/BatteryController$BatteryStateChangeCallback;", "controller", "Lcom/android/systemui/statusbar/policy/BatteryController;", "noMan", "Landroid/app/NotificationManager;", "delayableExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "context", "Landroid/content/Context;", "(Lcom/android/systemui/statusbar/policy/BatteryController;Landroid/app/NotificationManager;Lcom/android/systemui/util/concurrency/DelayableExecutor;Landroid/content/Context;)V", "getContext", "()Landroid/content/Context;", "getController", "()Lcom/android/systemui/statusbar/policy/BatteryController;", "getDelayableExecutor", "()Lcom/android/systemui/util/concurrency/DelayableExecutor;", "getNoMan", "()Landroid/app/NotificationManager;", "stateUnknown", "", "getStateUnknown", "()Z", "setStateUnknown", "(Z)V", "onBatteryUnknownStateChanged", "", "isUnknown", "scheduleNotificationCancel", "startListening", "stopListening"})
public final class BatteryStateNotifier implements com.android.systemui.statusbar.policy.BatteryController.BatteryStateChangeCallback {
    private boolean stateUnknown = false;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.policy.BatteryController controller = null;
    @org.jetbrains.annotations.NotNull()
    private final android.app.NotificationManager noMan = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.util.concurrency.DelayableExecutor delayableExecutor = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    
    public final boolean getStateUnknown() {
        return false;
    }
    
    public final void setStateUnknown(boolean p0) {
    }
    
    public final void startListening() {
    }
    
    public final void stopListening() {
    }
    
    @java.lang.Override()
    public void onBatteryUnknownStateChanged(boolean isUnknown) {
    }
    
    private final void scheduleNotificationCancel() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.policy.BatteryController getController() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.app.NotificationManager getNoMan() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.concurrency.DelayableExecutor getDelayableExecutor() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    @javax.inject.Inject()
    public BatteryStateNotifier(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.BatteryController controller, @org.jetbrains.annotations.NotNull()
    android.app.NotificationManager noMan, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.concurrency.DelayableExecutor delayableExecutor, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}
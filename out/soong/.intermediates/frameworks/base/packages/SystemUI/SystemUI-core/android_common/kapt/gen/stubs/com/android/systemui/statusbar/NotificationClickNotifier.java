package com.android.systemui.statusbar;

import android.app.Notification;
import android.os.RemoteException;
import com.android.internal.statusbar.IStatusBarService;
import com.android.internal.statusbar.NotificationVisibility;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.util.Assert;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * Class to shim calls to IStatusBarManager#onNotificationClick/#onNotificationActionClick that
 * allow an in-process notification to go out (e.g., for tracking interactions) as well as
 * sending the messages along to system server.
 *
 * NOTE: this class eats exceptions from system server, as no current client of these APIs cares
 * about errors
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001B\u0019\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u000e\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u000bJ\u0010\u0010\u0013\u001a\u00020\u00112\u0006\u0010\u0014\u001a\u00020\u0015H\u0002J.\u0010\u0016\u001a\u00020\u00112\u0006\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\u001eJ\u0016\u0010\u001f\u001a\u00020\u00112\u0006\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u001b\u001a\u00020\u001cJ\u000e\u0010 \u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u000bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0017\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u000b0\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000f"}, d2 = {"Lcom/android/systemui/statusbar/NotificationClickNotifier;", "", "barService", "Lcom/android/internal/statusbar/IStatusBarService;", "mainExecutor", "Ljava/util/concurrent/Executor;", "(Lcom/android/internal/statusbar/IStatusBarService;Ljava/util/concurrent/Executor;)V", "getBarService", "()Lcom/android/internal/statusbar/IStatusBarService;", "listeners", "", "Lcom/android/systemui/statusbar/NotificationInteractionListener;", "getListeners", "()Ljava/util/List;", "getMainExecutor", "()Ljava/util/concurrent/Executor;", "addNotificationInteractionListener", "", "listener", "notifyListenersAboutInteraction", "key", "", "onNotificationActionClick", "actionIndex", "", "action", "Landroid/app/Notification$Action;", "visibility", "Lcom/android/internal/statusbar/NotificationVisibility;", "generatedByAssistant", "", "onNotificationClick", "removeNotificationInteractionListener"})
@com.android.systemui.dagger.SysUISingleton()
public final class NotificationClickNotifier {
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<com.android.systemui.statusbar.NotificationInteractionListener> listeners = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.internal.statusbar.IStatusBarService barService = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.concurrent.Executor mainExecutor = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.statusbar.NotificationInteractionListener> getListeners() {
        return null;
    }
    
    public final void addNotificationInteractionListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationInteractionListener listener) {
    }
    
    public final void removeNotificationInteractionListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationInteractionListener listener) {
    }
    
    private final void notifyListenersAboutInteraction(java.lang.String key) {
    }
    
    public final void onNotificationActionClick(@org.jetbrains.annotations.NotNull()
    java.lang.String key, int actionIndex, @org.jetbrains.annotations.NotNull()
    android.app.Notification.Action action, @org.jetbrains.annotations.NotNull()
    com.android.internal.statusbar.NotificationVisibility visibility, boolean generatedByAssistant) {
    }
    
    public final void onNotificationClick(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    com.android.internal.statusbar.NotificationVisibility visibility) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.internal.statusbar.IStatusBarService getBarService() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.concurrent.Executor getMainExecutor() {
        return null;
    }
    
    @javax.inject.Inject()
    public NotificationClickNotifier(@org.jetbrains.annotations.NotNull()
    com.android.internal.statusbar.IStatusBarService barService, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor mainExecutor) {
        super();
    }
}
package com.android.systemui.statusbar.notification.init;

import android.service.notification.StatusBarNotification;
import com.android.systemui.plugins.statusbar.NotificationSwipeActionHelper.SnoozeOption;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.NotificationPresenter;
import com.android.systemui.statusbar.notification.NotificationActivityStarter;
import com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl;
import com.android.systemui.statusbar.notification.stack.NotificationListContainer;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.wm.shell.bubbles.Bubbles;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.Optional;
import javax.inject.Inject;

/**
 * Implementation of [NotificationsController] that's used when notifications rendering is disabled.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000r\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J3\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\r0\f2\u0006\u0010\u000e\u001a\u00020\u000fH\u0016\u00a2\u0006\u0002\u0010\u0010J\b\u0010\u0011\u001a\u00020\u0012H\u0016J>\u0010\u0013\u001a\u00020\u00062\u0006\u0010\u0014\u001a\u00020\u00152\f\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00180\u00172\u0006\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020 H\u0016J\u0010\u0010!\u001a\u00020\u00062\u0006\u0010\"\u001a\u00020\rH\u0016J\b\u0010#\u001a\u00020\u0006H\u0016J\u0018\u0010$\u001a\u00020\u00062\u0006\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020(H\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/init/NotificationsControllerStub;", "Lcom/android/systemui/statusbar/notification/init/NotificationsController;", "notificationListener", "Lcom/android/systemui/statusbar/NotificationListener;", "(Lcom/android/systemui/statusbar/NotificationListener;)V", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "dumpTruck", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;Z)V", "getActiveNotificationsCount", "", "initialize", "statusBar", "Lcom/android/systemui/statusbar/phone/StatusBar;", "bubblesOptional", "Ljava/util/Optional;", "Lcom/android/wm/shell/bubbles/Bubbles;", "presenter", "Lcom/android/systemui/statusbar/NotificationPresenter;", "listContainer", "Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;", "notificationActivityStarter", "Lcom/android/systemui/statusbar/notification/NotificationActivityStarter;", "bindRowCallback", "Lcom/android/systemui/statusbar/notification/collection/inflation/NotificationRowBinderImpl$BindRowCallback;", "requestNotificationUpdate", "reason", "resetUserExpandedStates", "setNotificationSnoozed", "sbn", "Landroid/service/notification/StatusBarNotification;", "snoozeOption", "Lcom/android/systemui/plugins/statusbar/NotificationSwipeActionHelper$SnoozeOption;"})
public final class NotificationsControllerStub implements com.android.systemui.statusbar.notification.init.NotificationsController {
    private final com.android.systemui.statusbar.NotificationListener notificationListener = null;
    
    @java.lang.Override()
    public void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBar statusBar, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.wm.shell.bubbles.Bubbles> bubblesOptional, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationPresenter presenter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationListContainer listContainer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationActivityStarter notificationActivityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl.BindRowCallback bindRowCallback) {
    }
    
    @java.lang.Override()
    public void requestNotificationUpdate(@org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    @java.lang.Override()
    public void resetUserExpandedStates() {
    }
    
    @java.lang.Override()
    public void setNotificationSnoozed(@org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.NotificationSwipeActionHelper.SnoozeOption snoozeOption) {
    }
    
    @java.lang.Override()
    public int getActiveNotificationsCount() {
        return 0;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args, boolean dumpTruck) {
    }
    
    @javax.inject.Inject()
    public NotificationsControllerStub(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationListener notificationListener) {
        super();
    }
}
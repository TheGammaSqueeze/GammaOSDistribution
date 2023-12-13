package com.android.systemui.statusbar.notification.init;

import android.service.notification.StatusBarNotification;
import com.android.systemui.plugins.statusbar.NotificationSwipeActionHelper.SnoozeOption;
import com.android.systemui.statusbar.NotificationPresenter;
import com.android.systemui.statusbar.notification.NotificationActivityStarter;
import com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl;
import com.android.systemui.statusbar.notification.stack.NotificationListContainer;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.wm.shell.bubbles.Bubbles;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.Optional;

/**
 * The master controller for all notifications-related work
 *
 * Split into two implementations: [NotificationsControllerImpl] (most cases) and
 * [NotificationsControllerStub] (for builds that disable notification rendering).
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000j\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J3\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u00072\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\t2\u0006\u0010\u000b\u001a\u00020\fH&\u00a2\u0006\u0002\u0010\rJ\b\u0010\u000e\u001a\u00020\u000fH&J>\u0010\u0010\u001a\u00020\u00032\u0006\u0010\u0011\u001a\u00020\u00122\f\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00150\u00142\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001dH&J\u0010\u0010\u001e\u001a\u00020\u00032\u0006\u0010\u001f\u001a\u00020\nH&J\b\u0010 \u001a\u00020\u0003H&J\u0018\u0010!\u001a\u00020\u00032\u0006\u0010\"\u001a\u00020#2\u0006\u0010$\u001a\u00020%H&"}, d2 = {"Lcom/android/systemui/statusbar/notification/init/NotificationsController;", "", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "dumpTruck", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;Z)V", "getActiveNotificationsCount", "", "initialize", "statusBar", "Lcom/android/systemui/statusbar/phone/StatusBar;", "bubblesOptional", "Ljava/util/Optional;", "Lcom/android/wm/shell/bubbles/Bubbles;", "presenter", "Lcom/android/systemui/statusbar/NotificationPresenter;", "listContainer", "Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;", "notificationActivityStarter", "Lcom/android/systemui/statusbar/notification/NotificationActivityStarter;", "bindRowCallback", "Lcom/android/systemui/statusbar/notification/collection/inflation/NotificationRowBinderImpl$BindRowCallback;", "requestNotificationUpdate", "reason", "resetUserExpandedStates", "setNotificationSnoozed", "sbn", "Landroid/service/notification/StatusBarNotification;", "snoozeOption", "Lcom/android/systemui/plugins/statusbar/NotificationSwipeActionHelper$SnoozeOption;"})
public abstract interface NotificationsController {
    
    public abstract void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBar statusBar, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.wm.shell.bubbles.Bubbles> bubblesOptional, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationPresenter presenter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationListContainer listContainer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationActivityStarter notificationActivityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl.BindRowCallback bindRowCallback);
    
    public abstract void requestNotificationUpdate(@org.jetbrains.annotations.NotNull()
    java.lang.String reason);
    
    public abstract void resetUserExpandedStates();
    
    public abstract void setNotificationSnoozed(@org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.NotificationSwipeActionHelper.SnoozeOption snoozeOption);
    
    public abstract int getActiveNotificationsCount();
    
    public abstract void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args, boolean dumpTruck);
}
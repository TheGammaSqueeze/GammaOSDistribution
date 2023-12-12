package com.android.systemui.statusbar.notification.init;

import android.service.notification.StatusBarNotification;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.people.widget.PeopleSpaceWidgetManager;
import com.android.systemui.plugins.statusbar.NotificationSwipeActionHelper.SnoozeOption;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.NotificationPresenter;
import com.android.systemui.statusbar.notification.AnimatedImageNotificationManager;
import com.android.systemui.statusbar.notification.NotificationActivityStarter;
import com.android.systemui.statusbar.notification.NotificationClicker;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.NotificationListController;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationRankingManager;
import com.android.systemui.statusbar.notification.collection.TargetSdkResolver;
import com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl;
import com.android.systemui.statusbar.notification.collection.init.NotifPipelineInitializer;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.interruption.HeadsUpController;
import com.android.systemui.statusbar.notification.interruption.HeadsUpViewBinder;
import com.android.systemui.statusbar.notification.row.NotifBindPipelineInitializer;
import com.android.systemui.statusbar.notification.stack.NotificationListContainer;
import com.android.systemui.statusbar.phone.NotificationGroupAlertTransferHelper;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import com.android.systemui.statusbar.policy.RemoteInputUriController;
import com.android.wm.shell.bubbles.Bubbles;
import dagger.Lazy;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.Optional;
import javax.inject.Inject;

/**
 * Master controller for all notifications-related work
 *
 * At the moment exposes a number of event-handler-esque methods; these are for historical reasons.
 * Once we migrate away from the need for such things, this class becomes primarily a place to do
 * any initialization work that notifications require.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00e2\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0007\u0018\u00002\u00020\u0001B\u00b1\u0001\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000b\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00100\u000b\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u0012\u0006\u0010\u0017\u001a\u00020\u0018\u0012\f\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u001a0\u000b\u0012\u0006\u0010\u001b\u001a\u00020\u001c\u0012\u0006\u0010\u001d\u001a\u00020\u001e\u0012\u0006\u0010\u001f\u001a\u00020 \u0012\u0006\u0010!\u001a\u00020\"\u0012\u0006\u0010#\u001a\u00020$\u0012\u0006\u0010%\u001a\u00020&\u0012\u0006\u0010\'\u001a\u00020(\u00a2\u0006\u0002\u0010)J3\u0010*\u001a\u00020+2\u0006\u0010,\u001a\u00020-2\u0006\u0010.\u001a\u00020/2\f\u00100\u001a\b\u0012\u0004\u0012\u000202012\u0006\u00103\u001a\u000204H\u0016\u00a2\u0006\u0002\u00105J\b\u00106\u001a\u000207H\u0016J>\u00108\u001a\u00020+2\u0006\u00109\u001a\u00020:2\f\u0010;\u001a\b\u0012\u0004\u0012\u00020=0<2\u0006\u0010>\u001a\u00020?2\u0006\u0010@\u001a\u00020A2\u0006\u0010B\u001a\u00020C2\u0006\u0010D\u001a\u00020EH\u0016J\u0010\u0010F\u001a\u00020+2\u0006\u0010G\u001a\u000202H\u0016J\b\u0010H\u001a\u00020+H\u0016J\u0018\u0010I\u001a\u00020+2\u0006\u0010J\u001a\u00020K2\u0006\u0010L\u001a\u00020MH\u0016R\u000e\u0010%\u001a\u00020&X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010#\u001a\u00020$X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u001cX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u001a0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020 X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010!\u001a\u00020\"X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00100\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020(X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/init/NotificationsControllerImpl;", "Lcom/android/systemui/statusbar/notification/init/NotificationsController;", "featureFlags", "Lcom/android/systemui/flags/FeatureFlags;", "notificationListener", "Lcom/android/systemui/statusbar/NotificationListener;", "entryManager", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "legacyRanker", "Lcom/android/systemui/statusbar/notification/collection/NotificationRankingManager;", "notifPipeline", "Ldagger/Lazy;", "Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;", "targetSdkResolver", "Lcom/android/systemui/statusbar/notification/collection/TargetSdkResolver;", "newNotifPipeline", "Lcom/android/systemui/statusbar/notification/collection/init/NotifPipelineInitializer;", "notifBindPipelineInitializer", "Lcom/android/systemui/statusbar/notification/row/NotifBindPipelineInitializer;", "deviceProvisionedController", "Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;", "notificationRowBinder", "Lcom/android/systemui/statusbar/notification/collection/inflation/NotificationRowBinderImpl;", "remoteInputUriController", "Lcom/android/systemui/statusbar/policy/RemoteInputUriController;", "groupManagerLegacy", "Lcom/android/systemui/statusbar/notification/collection/legacy/NotificationGroupManagerLegacy;", "groupAlertTransferHelper", "Lcom/android/systemui/statusbar/phone/NotificationGroupAlertTransferHelper;", "headsUpManager", "Lcom/android/systemui/statusbar/policy/HeadsUpManager;", "headsUpController", "Lcom/android/systemui/statusbar/notification/interruption/HeadsUpController;", "headsUpViewBinder", "Lcom/android/systemui/statusbar/notification/interruption/HeadsUpViewBinder;", "clickerBuilder", "Lcom/android/systemui/statusbar/notification/NotificationClicker$Builder;", "animatedImageNotificationManager", "Lcom/android/systemui/statusbar/notification/AnimatedImageNotificationManager;", "peopleSpaceWidgetManager", "Lcom/android/systemui/people/widget/PeopleSpaceWidgetManager;", "(Lcom/android/systemui/flags/FeatureFlags;Lcom/android/systemui/statusbar/NotificationListener;Lcom/android/systemui/statusbar/notification/NotificationEntryManager;Lcom/android/systemui/statusbar/notification/collection/NotificationRankingManager;Ldagger/Lazy;Lcom/android/systemui/statusbar/notification/collection/TargetSdkResolver;Ldagger/Lazy;Lcom/android/systemui/statusbar/notification/row/NotifBindPipelineInitializer;Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;Lcom/android/systemui/statusbar/notification/collection/inflation/NotificationRowBinderImpl;Lcom/android/systemui/statusbar/policy/RemoteInputUriController;Ldagger/Lazy;Lcom/android/systemui/statusbar/phone/NotificationGroupAlertTransferHelper;Lcom/android/systemui/statusbar/policy/HeadsUpManager;Lcom/android/systemui/statusbar/notification/interruption/HeadsUpController;Lcom/android/systemui/statusbar/notification/interruption/HeadsUpViewBinder;Lcom/android/systemui/statusbar/notification/NotificationClicker$Builder;Lcom/android/systemui/statusbar/notification/AnimatedImageNotificationManager;Lcom/android/systemui/people/widget/PeopleSpaceWidgetManager;)V", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "dumpTruck", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;Z)V", "getActiveNotificationsCount", "", "initialize", "statusBar", "Lcom/android/systemui/statusbar/phone/StatusBar;", "bubblesOptional", "Ljava/util/Optional;", "Lcom/android/wm/shell/bubbles/Bubbles;", "presenter", "Lcom/android/systemui/statusbar/NotificationPresenter;", "listContainer", "Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;", "notificationActivityStarter", "Lcom/android/systemui/statusbar/notification/NotificationActivityStarter;", "bindRowCallback", "Lcom/android/systemui/statusbar/notification/collection/inflation/NotificationRowBinderImpl$BindRowCallback;", "requestNotificationUpdate", "reason", "resetUserExpandedStates", "setNotificationSnoozed", "sbn", "Landroid/service/notification/StatusBarNotification;", "snoozeOption", "Lcom/android/systemui/plugins/statusbar/NotificationSwipeActionHelper$SnoozeOption;"})
@com.android.systemui.dagger.SysUISingleton()
public final class NotificationsControllerImpl implements com.android.systemui.statusbar.notification.init.NotificationsController {
    private final com.android.systemui.flags.FeatureFlags featureFlags = null;
    private final com.android.systemui.statusbar.NotificationListener notificationListener = null;
    private final com.android.systemui.statusbar.notification.NotificationEntryManager entryManager = null;
    private final com.android.systemui.statusbar.notification.collection.NotificationRankingManager legacyRanker = null;
    private final dagger.Lazy<com.android.systemui.statusbar.notification.collection.NotifPipeline> notifPipeline = null;
    private final com.android.systemui.statusbar.notification.collection.TargetSdkResolver targetSdkResolver = null;
    private final dagger.Lazy<com.android.systemui.statusbar.notification.collection.init.NotifPipelineInitializer> newNotifPipeline = null;
    private final com.android.systemui.statusbar.notification.row.NotifBindPipelineInitializer notifBindPipelineInitializer = null;
    private final com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController = null;
    private final com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl notificationRowBinder = null;
    private final com.android.systemui.statusbar.policy.RemoteInputUriController remoteInputUriController = null;
    private final dagger.Lazy<com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy> groupManagerLegacy = null;
    private final com.android.systemui.statusbar.phone.NotificationGroupAlertTransferHelper groupAlertTransferHelper = null;
    private final com.android.systemui.statusbar.policy.HeadsUpManager headsUpManager = null;
    private final com.android.systemui.statusbar.notification.interruption.HeadsUpController headsUpController = null;
    private final com.android.systemui.statusbar.notification.interruption.HeadsUpViewBinder headsUpViewBinder = null;
    private final com.android.systemui.statusbar.notification.NotificationClicker.Builder clickerBuilder = null;
    private final com.android.systemui.statusbar.notification.AnimatedImageNotificationManager animatedImageNotificationManager = null;
    private final com.android.systemui.people.widget.PeopleSpaceWidgetManager peopleSpaceWidgetManager = null;
    
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
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args, boolean dumpTruck) {
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
    
    @javax.inject.Inject()
    public NotificationsControllerImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.flags.FeatureFlags featureFlags, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationListener notificationListener, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager entryManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationRankingManager legacyRanker, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.statusbar.notification.collection.NotifPipeline> notifPipeline, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.TargetSdkResolver targetSdkResolver, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.statusbar.notification.collection.init.NotifPipelineInitializer> newNotifPipeline, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.NotifBindPipelineInitializer notifBindPipelineInitializer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl notificationRowBinder, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.RemoteInputUriController remoteInputUriController, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy> groupManagerLegacy, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.NotificationGroupAlertTransferHelper groupAlertTransferHelper, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.HeadsUpManager headsUpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.interruption.HeadsUpController headsUpController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.interruption.HeadsUpViewBinder headsUpViewBinder, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationClicker.Builder clickerBuilder, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.AnimatedImageNotificationManager animatedImageNotificationManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.people.widget.PeopleSpaceWidgetManager peopleSpaceWidgetManager) {
        super();
    }
}
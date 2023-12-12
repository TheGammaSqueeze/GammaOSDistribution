package com.android.systemui.statusbar.notification.init;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.people.widget.PeopleSpaceWidgetManager;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.notification.AnimatedImageNotificationManager;
import com.android.systemui.statusbar.notification.NotificationClicker;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationRankingManager;
import com.android.systemui.statusbar.notification.collection.TargetSdkResolver;
import com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl;
import com.android.systemui.statusbar.notification.collection.init.NotifPipelineInitializer;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.interruption.HeadsUpController;
import com.android.systemui.statusbar.notification.interruption.HeadsUpViewBinder;
import com.android.systemui.statusbar.notification.row.NotifBindPipelineInitializer;
import com.android.systemui.statusbar.phone.NotificationGroupAlertTransferHelper;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import com.android.systemui.statusbar.policy.RemoteInputUriController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import javax.annotation.processing.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class NotificationsControllerImpl_Factory implements Factory<NotificationsControllerImpl> {
  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotificationListener> notificationListenerProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  private final Provider<NotificationRankingManager> legacyRankerProvider;

  private final Provider<NotifPipeline> notifPipelineProvider;

  private final Provider<TargetSdkResolver> targetSdkResolverProvider;

  private final Provider<NotifPipelineInitializer> newNotifPipelineProvider;

  private final Provider<NotifBindPipelineInitializer> notifBindPipelineInitializerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<NotificationRowBinderImpl> notificationRowBinderProvider;

  private final Provider<RemoteInputUriController> remoteInputUriControllerProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerLegacyProvider;

  private final Provider<NotificationGroupAlertTransferHelper> groupAlertTransferHelperProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<HeadsUpController> headsUpControllerProvider;

  private final Provider<HeadsUpViewBinder> headsUpViewBinderProvider;

  private final Provider<NotificationClicker.Builder> clickerBuilderProvider;

  private final Provider<AnimatedImageNotificationManager> animatedImageNotificationManagerProvider;

  private final Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider;

  public NotificationsControllerImpl_Factory(Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationListener> notificationListenerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<NotificationRankingManager> legacyRankerProvider,
      Provider<NotifPipeline> notifPipelineProvider,
      Provider<TargetSdkResolver> targetSdkResolverProvider,
      Provider<NotifPipelineInitializer> newNotifPipelineProvider,
      Provider<NotifBindPipelineInitializer> notifBindPipelineInitializerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<NotificationRowBinderImpl> notificationRowBinderProvider,
      Provider<RemoteInputUriController> remoteInputUriControllerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerLegacyProvider,
      Provider<NotificationGroupAlertTransferHelper> groupAlertTransferHelperProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<HeadsUpController> headsUpControllerProvider,
      Provider<HeadsUpViewBinder> headsUpViewBinderProvider,
      Provider<NotificationClicker.Builder> clickerBuilderProvider,
      Provider<AnimatedImageNotificationManager> animatedImageNotificationManagerProvider,
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider) {
    this.featureFlagsProvider = featureFlagsProvider;
    this.notificationListenerProvider = notificationListenerProvider;
    this.entryManagerProvider = entryManagerProvider;
    this.legacyRankerProvider = legacyRankerProvider;
    this.notifPipelineProvider = notifPipelineProvider;
    this.targetSdkResolverProvider = targetSdkResolverProvider;
    this.newNotifPipelineProvider = newNotifPipelineProvider;
    this.notifBindPipelineInitializerProvider = notifBindPipelineInitializerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.notificationRowBinderProvider = notificationRowBinderProvider;
    this.remoteInputUriControllerProvider = remoteInputUriControllerProvider;
    this.groupManagerLegacyProvider = groupManagerLegacyProvider;
    this.groupAlertTransferHelperProvider = groupAlertTransferHelperProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.headsUpControllerProvider = headsUpControllerProvider;
    this.headsUpViewBinderProvider = headsUpViewBinderProvider;
    this.clickerBuilderProvider = clickerBuilderProvider;
    this.animatedImageNotificationManagerProvider = animatedImageNotificationManagerProvider;
    this.peopleSpaceWidgetManagerProvider = peopleSpaceWidgetManagerProvider;
  }

  @Override
  public NotificationsControllerImpl get() {
    return newInstance(featureFlagsProvider.get(), notificationListenerProvider.get(), entryManagerProvider.get(), legacyRankerProvider.get(), DoubleCheck.lazy(notifPipelineProvider), targetSdkResolverProvider.get(), DoubleCheck.lazy(newNotifPipelineProvider), notifBindPipelineInitializerProvider.get(), deviceProvisionedControllerProvider.get(), notificationRowBinderProvider.get(), remoteInputUriControllerProvider.get(), DoubleCheck.lazy(groupManagerLegacyProvider), groupAlertTransferHelperProvider.get(), headsUpManagerProvider.get(), headsUpControllerProvider.get(), headsUpViewBinderProvider.get(), clickerBuilderProvider.get(), animatedImageNotificationManagerProvider.get(), peopleSpaceWidgetManagerProvider.get());
  }

  public static NotificationsControllerImpl_Factory create(
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationListener> notificationListenerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<NotificationRankingManager> legacyRankerProvider,
      Provider<NotifPipeline> notifPipelineProvider,
      Provider<TargetSdkResolver> targetSdkResolverProvider,
      Provider<NotifPipelineInitializer> newNotifPipelineProvider,
      Provider<NotifBindPipelineInitializer> notifBindPipelineInitializerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<NotificationRowBinderImpl> notificationRowBinderProvider,
      Provider<RemoteInputUriController> remoteInputUriControllerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerLegacyProvider,
      Provider<NotificationGroupAlertTransferHelper> groupAlertTransferHelperProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<HeadsUpController> headsUpControllerProvider,
      Provider<HeadsUpViewBinder> headsUpViewBinderProvider,
      Provider<NotificationClicker.Builder> clickerBuilderProvider,
      Provider<AnimatedImageNotificationManager> animatedImageNotificationManagerProvider,
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider) {
    return new NotificationsControllerImpl_Factory(featureFlagsProvider, notificationListenerProvider, entryManagerProvider, legacyRankerProvider, notifPipelineProvider, targetSdkResolverProvider, newNotifPipelineProvider, notifBindPipelineInitializerProvider, deviceProvisionedControllerProvider, notificationRowBinderProvider, remoteInputUriControllerProvider, groupManagerLegacyProvider, groupAlertTransferHelperProvider, headsUpManagerProvider, headsUpControllerProvider, headsUpViewBinderProvider, clickerBuilderProvider, animatedImageNotificationManagerProvider, peopleSpaceWidgetManagerProvider);
  }

  public static NotificationsControllerImpl newInstance(FeatureFlags featureFlags,
      NotificationListener notificationListener, NotificationEntryManager entryManager,
      NotificationRankingManager legacyRanker, Lazy<NotifPipeline> notifPipeline,
      TargetSdkResolver targetSdkResolver, Lazy<NotifPipelineInitializer> newNotifPipeline,
      NotifBindPipelineInitializer notifBindPipelineInitializer,
      DeviceProvisionedController deviceProvisionedController,
      NotificationRowBinderImpl notificationRowBinder,
      RemoteInputUriController remoteInputUriController,
      Lazy<NotificationGroupManagerLegacy> groupManagerLegacy,
      NotificationGroupAlertTransferHelper groupAlertTransferHelper, HeadsUpManager headsUpManager,
      HeadsUpController headsUpController, HeadsUpViewBinder headsUpViewBinder,
      NotificationClicker.Builder clickerBuilder,
      AnimatedImageNotificationManager animatedImageNotificationManager,
      PeopleSpaceWidgetManager peopleSpaceWidgetManager) {
    return new NotificationsControllerImpl(featureFlags, notificationListener, entryManager, legacyRanker, notifPipeline, targetSdkResolver, newNotifPipeline, notifBindPipelineInitializer, deviceProvisionedController, notificationRowBinder, remoteInputUriController, groupManagerLegacy, groupAlertTransferHelper, headsUpManager, headsUpController, headsUpViewBinder, clickerBuilder, animatedImageNotificationManager, peopleSpaceWidgetManager);
  }
}

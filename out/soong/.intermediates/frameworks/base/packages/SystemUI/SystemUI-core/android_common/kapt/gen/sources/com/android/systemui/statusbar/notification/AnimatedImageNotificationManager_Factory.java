package com.android.systemui.statusbar.notification;

import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.policy.HeadsUpManager;
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
public final class AnimatedImageNotificationManager_Factory implements Factory<AnimatedImageNotificationManager> {
  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  public AnimatedImageNotificationManager_Factory(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
  }

  @Override
  public AnimatedImageNotificationManager get() {
    return newInstance(notificationEntryManagerProvider.get(), headsUpManagerProvider.get(), statusBarStateControllerProvider.get());
  }

  public static AnimatedImageNotificationManager_Factory create(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    return new AnimatedImageNotificationManager_Factory(notificationEntryManagerProvider, headsUpManagerProvider, statusBarStateControllerProvider);
  }

  public static AnimatedImageNotificationManager newInstance(
      NotificationEntryManager notificationEntryManager, HeadsUpManager headsUpManager,
      StatusBarStateController statusBarStateController) {
    return new AnimatedImageNotificationManager(notificationEntryManager, headsUpManager, statusBarStateController);
  }
}

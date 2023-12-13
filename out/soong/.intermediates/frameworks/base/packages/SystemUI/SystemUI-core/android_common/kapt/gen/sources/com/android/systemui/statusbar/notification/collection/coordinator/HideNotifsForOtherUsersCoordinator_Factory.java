package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.statusbar.NotificationLockscreenUserManager;
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
public final class HideNotifsForOtherUsersCoordinator_Factory implements Factory<HideNotifsForOtherUsersCoordinator> {
  private final Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider;

  private final Provider<SharedCoordinatorLogger> loggerProvider;

  public HideNotifsForOtherUsersCoordinator_Factory(
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<SharedCoordinatorLogger> loggerProvider) {
    this.lockscreenUserManagerProvider = lockscreenUserManagerProvider;
    this.loggerProvider = loggerProvider;
  }

  @Override
  public HideNotifsForOtherUsersCoordinator get() {
    return newInstance(lockscreenUserManagerProvider.get(), loggerProvider.get());
  }

  public static HideNotifsForOtherUsersCoordinator_Factory create(
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<SharedCoordinatorLogger> loggerProvider) {
    return new HideNotifsForOtherUsersCoordinator_Factory(lockscreenUserManagerProvider, loggerProvider);
  }

  public static HideNotifsForOtherUsersCoordinator newInstance(
      NotificationLockscreenUserManager lockscreenUserManager, SharedCoordinatorLogger logger) {
    return new HideNotifsForOtherUsersCoordinator(lockscreenUserManager, logger);
  }
}

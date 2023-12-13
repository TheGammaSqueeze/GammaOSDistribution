package com.android.systemui.statusbar.phone.dagger;

import com.android.systemui.statusbar.phone.NotificationShadeWindowView;
import com.android.systemui.statusbar.phone.NotificationsQuickSettingsContainer;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class StatusBarViewModule_GetNotificationsQuickSettingsContainerFactory implements Factory<NotificationsQuickSettingsContainer> {
  private final Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider;

  public StatusBarViewModule_GetNotificationsQuickSettingsContainerFactory(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    this.notificationShadeWindowViewProvider = notificationShadeWindowViewProvider;
  }

  @Override
  public NotificationsQuickSettingsContainer get() {
    return getNotificationsQuickSettingsContainer(notificationShadeWindowViewProvider.get());
  }

  public static StatusBarViewModule_GetNotificationsQuickSettingsContainerFactory create(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    return new StatusBarViewModule_GetNotificationsQuickSettingsContainerFactory(notificationShadeWindowViewProvider);
  }

  public static NotificationsQuickSettingsContainer getNotificationsQuickSettingsContainer(
      NotificationShadeWindowView notificationShadeWindowView) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.getNotificationsQuickSettingsContainer(notificationShadeWindowView));
  }
}

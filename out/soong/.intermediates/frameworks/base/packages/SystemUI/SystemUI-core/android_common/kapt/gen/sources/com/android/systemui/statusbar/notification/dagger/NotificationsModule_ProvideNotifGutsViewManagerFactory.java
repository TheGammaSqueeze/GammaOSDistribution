package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.statusbar.notification.collection.render.NotifGutsViewManager;
import com.android.systemui.statusbar.notification.row.NotificationGutsManager;
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
public final class NotificationsModule_ProvideNotifGutsViewManagerFactory implements Factory<NotifGutsViewManager> {
  private final Provider<NotificationGutsManager> notificationGutsManagerProvider;

  public NotificationsModule_ProvideNotifGutsViewManagerFactory(
      Provider<NotificationGutsManager> notificationGutsManagerProvider) {
    this.notificationGutsManagerProvider = notificationGutsManagerProvider;
  }

  @Override
  public NotifGutsViewManager get() {
    return provideNotifGutsViewManager(notificationGutsManagerProvider.get());
  }

  public static NotificationsModule_ProvideNotifGutsViewManagerFactory create(
      Provider<NotificationGutsManager> notificationGutsManagerProvider) {
    return new NotificationsModule_ProvideNotifGutsViewManagerFactory(notificationGutsManagerProvider);
  }

  public static NotifGutsViewManager provideNotifGutsViewManager(
      NotificationGutsManager notificationGutsManager) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideNotifGutsViewManager(notificationGutsManager));
  }
}

package com.android.systemui.statusbar.notification.init;

import com.android.systemui.statusbar.NotificationListener;
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
public final class NotificationsControllerStub_Factory implements Factory<NotificationsControllerStub> {
  private final Provider<NotificationListener> notificationListenerProvider;

  public NotificationsControllerStub_Factory(
      Provider<NotificationListener> notificationListenerProvider) {
    this.notificationListenerProvider = notificationListenerProvider;
  }

  @Override
  public NotificationsControllerStub get() {
    return newInstance(notificationListenerProvider.get());
  }

  public static NotificationsControllerStub_Factory create(
      Provider<NotificationListener> notificationListenerProvider) {
    return new NotificationsControllerStub_Factory(notificationListenerProvider);
  }

  public static NotificationsControllerStub newInstance(NotificationListener notificationListener) {
    return new NotificationsControllerStub(notificationListener);
  }
}

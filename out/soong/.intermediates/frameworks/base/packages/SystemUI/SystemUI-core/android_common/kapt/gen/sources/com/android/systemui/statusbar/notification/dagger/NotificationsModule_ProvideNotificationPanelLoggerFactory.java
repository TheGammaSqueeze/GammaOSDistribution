package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.statusbar.notification.logging.NotificationPanelLogger;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class NotificationsModule_ProvideNotificationPanelLoggerFactory implements Factory<NotificationPanelLogger> {
  @Override
  public NotificationPanelLogger get() {
    return provideNotificationPanelLogger();
  }

  public static NotificationsModule_ProvideNotificationPanelLoggerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static NotificationPanelLogger provideNotificationPanelLogger() {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideNotificationPanelLogger());
  }

  private static final class InstanceHolder {
    private static final NotificationsModule_ProvideNotificationPanelLoggerFactory INSTANCE = new NotificationsModule_ProvideNotificationPanelLoggerFactory();
  }
}

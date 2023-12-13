package com.android.systemui.statusbar.notification;

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
public final class NotificationClicker_Builder_Factory implements Factory<NotificationClicker.Builder> {
  private final Provider<NotificationClickerLogger> loggerProvider;

  public NotificationClicker_Builder_Factory(Provider<NotificationClickerLogger> loggerProvider) {
    this.loggerProvider = loggerProvider;
  }

  @Override
  public NotificationClicker.Builder get() {
    return newInstance(loggerProvider.get());
  }

  public static NotificationClicker_Builder_Factory create(
      Provider<NotificationClickerLogger> loggerProvider) {
    return new NotificationClicker_Builder_Factory(loggerProvider);
  }

  public static NotificationClicker.Builder newInstance(NotificationClickerLogger logger) {
    return new NotificationClicker.Builder(logger);
  }
}

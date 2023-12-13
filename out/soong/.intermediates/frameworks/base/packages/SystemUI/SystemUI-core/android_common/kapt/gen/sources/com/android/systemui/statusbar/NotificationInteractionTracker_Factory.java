package com.android.systemui.statusbar;

import com.android.systemui.statusbar.notification.NotificationEntryManager;
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
public final class NotificationInteractionTracker_Factory implements Factory<NotificationInteractionTracker> {
  private final Provider<NotificationClickNotifier> clickerProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  public NotificationInteractionTracker_Factory(Provider<NotificationClickNotifier> clickerProvider,
      Provider<NotificationEntryManager> entryManagerProvider) {
    this.clickerProvider = clickerProvider;
    this.entryManagerProvider = entryManagerProvider;
  }

  @Override
  public NotificationInteractionTracker get() {
    return newInstance(clickerProvider.get(), entryManagerProvider.get());
  }

  public static NotificationInteractionTracker_Factory create(
      Provider<NotificationClickNotifier> clickerProvider,
      Provider<NotificationEntryManager> entryManagerProvider) {
    return new NotificationInteractionTracker_Factory(clickerProvider, entryManagerProvider);
  }

  public static NotificationInteractionTracker newInstance(NotificationClickNotifier clicker,
      NotificationEntryManager entryManager) {
    return new NotificationInteractionTracker(clicker, entryManager);
  }
}

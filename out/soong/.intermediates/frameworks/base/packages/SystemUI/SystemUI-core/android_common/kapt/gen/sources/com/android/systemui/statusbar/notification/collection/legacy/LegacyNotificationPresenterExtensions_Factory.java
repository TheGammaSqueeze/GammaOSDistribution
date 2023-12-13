package com.android.systemui.statusbar.notification.collection.legacy;

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
public final class LegacyNotificationPresenterExtensions_Factory implements Factory<LegacyNotificationPresenterExtensions> {
  private final Provider<NotificationEntryManager> entryManagerProvider;

  public LegacyNotificationPresenterExtensions_Factory(
      Provider<NotificationEntryManager> entryManagerProvider) {
    this.entryManagerProvider = entryManagerProvider;
  }

  @Override
  public LegacyNotificationPresenterExtensions get() {
    return newInstance(entryManagerProvider.get());
  }

  public static LegacyNotificationPresenterExtensions_Factory create(
      Provider<NotificationEntryManager> entryManagerProvider) {
    return new LegacyNotificationPresenterExtensions_Factory(entryManagerProvider);
  }

  public static LegacyNotificationPresenterExtensions newInstance(
      NotificationEntryManager entryManager) {
    return new LegacyNotificationPresenterExtensions(entryManager);
  }
}

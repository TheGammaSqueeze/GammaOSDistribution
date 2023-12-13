package com.android.systemui.statusbar.notification;

import android.content.Context;
import android.os.Handler;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
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
public final class ConversationNotificationManager_Factory implements Factory<ConversationNotificationManager> {
  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<NotificationGroupManagerLegacy> notificationGroupManagerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<Handler> mainHandlerProvider;

  public ConversationNotificationManager_Factory(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotificationGroupManagerLegacy> notificationGroupManagerProvider,
      Provider<Context> contextProvider, Provider<Handler> mainHandlerProvider) {
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.notificationGroupManagerProvider = notificationGroupManagerProvider;
    this.contextProvider = contextProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public ConversationNotificationManager get() {
    return newInstance(notificationEntryManagerProvider.get(), notificationGroupManagerProvider.get(), contextProvider.get(), mainHandlerProvider.get());
  }

  public static ConversationNotificationManager_Factory create(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotificationGroupManagerLegacy> notificationGroupManagerProvider,
      Provider<Context> contextProvider, Provider<Handler> mainHandlerProvider) {
    return new ConversationNotificationManager_Factory(notificationEntryManagerProvider, notificationGroupManagerProvider, contextProvider, mainHandlerProvider);
  }

  public static ConversationNotificationManager newInstance(
      NotificationEntryManager notificationEntryManager,
      NotificationGroupManagerLegacy notificationGroupManager, Context context,
      Handler mainHandler) {
    return new ConversationNotificationManager(notificationEntryManager, notificationGroupManager, context, mainHandler);
  }
}

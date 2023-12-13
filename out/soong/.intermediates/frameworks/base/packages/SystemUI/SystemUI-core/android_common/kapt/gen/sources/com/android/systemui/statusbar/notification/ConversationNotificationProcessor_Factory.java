package com.android.systemui.statusbar.notification;

import android.content.pm.LauncherApps;
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
public final class ConversationNotificationProcessor_Factory implements Factory<ConversationNotificationProcessor> {
  private final Provider<LauncherApps> launcherAppsProvider;

  private final Provider<ConversationNotificationManager> conversationNotificationManagerProvider;

  public ConversationNotificationProcessor_Factory(Provider<LauncherApps> launcherAppsProvider,
      Provider<ConversationNotificationManager> conversationNotificationManagerProvider) {
    this.launcherAppsProvider = launcherAppsProvider;
    this.conversationNotificationManagerProvider = conversationNotificationManagerProvider;
  }

  @Override
  public ConversationNotificationProcessor get() {
    return newInstance(launcherAppsProvider.get(), conversationNotificationManagerProvider.get());
  }

  public static ConversationNotificationProcessor_Factory create(
      Provider<LauncherApps> launcherAppsProvider,
      Provider<ConversationNotificationManager> conversationNotificationManagerProvider) {
    return new ConversationNotificationProcessor_Factory(launcherAppsProvider, conversationNotificationManagerProvider);
  }

  public static ConversationNotificationProcessor newInstance(LauncherApps launcherApps,
      ConversationNotificationManager conversationNotificationManager) {
    return new ConversationNotificationProcessor(launcherApps, conversationNotificationManager);
  }
}

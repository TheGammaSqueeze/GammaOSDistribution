package com.android.systemui.statusbar.dagger;

import android.app.NotificationManager;
import android.content.Context;
import android.os.Handler;
import com.android.systemui.statusbar.NotificationListener;
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
public final class StatusBarDependenciesModule_ProvideNotificationListenerFactory implements Factory<NotificationListener> {
  private final Provider<Context> contextProvider;

  private final Provider<NotificationManager> notificationManagerProvider;

  private final Provider<Handler> mainHandlerProvider;

  public StatusBarDependenciesModule_ProvideNotificationListenerFactory(
      Provider<Context> contextProvider, Provider<NotificationManager> notificationManagerProvider,
      Provider<Handler> mainHandlerProvider) {
    this.contextProvider = contextProvider;
    this.notificationManagerProvider = notificationManagerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public NotificationListener get() {
    return provideNotificationListener(contextProvider.get(), notificationManagerProvider.get(), mainHandlerProvider.get());
  }

  public static StatusBarDependenciesModule_ProvideNotificationListenerFactory create(
      Provider<Context> contextProvider, Provider<NotificationManager> notificationManagerProvider,
      Provider<Handler> mainHandlerProvider) {
    return new StatusBarDependenciesModule_ProvideNotificationListenerFactory(contextProvider, notificationManagerProvider, mainHandlerProvider);
  }

  public static NotificationListener provideNotificationListener(Context context,
      NotificationManager notificationManager, Handler mainHandler) {
    return Preconditions.checkNotNullFromProvides(StatusBarDependenciesModule.provideNotificationListener(context, notificationManager, mainHandler));
  }
}

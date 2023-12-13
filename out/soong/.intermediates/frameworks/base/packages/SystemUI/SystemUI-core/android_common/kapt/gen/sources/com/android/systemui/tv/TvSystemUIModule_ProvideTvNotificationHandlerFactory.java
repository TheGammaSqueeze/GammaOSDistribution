package com.android.systemui.tv;

import android.content.Context;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.tv.notifications.TvNotificationHandler;
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
public final class TvSystemUIModule_ProvideTvNotificationHandlerFactory implements Factory<TvNotificationHandler> {
  private final Provider<Context> contextProvider;

  private final Provider<NotificationListener> notificationListenerProvider;

  public TvSystemUIModule_ProvideTvNotificationHandlerFactory(Provider<Context> contextProvider,
      Provider<NotificationListener> notificationListenerProvider) {
    this.contextProvider = contextProvider;
    this.notificationListenerProvider = notificationListenerProvider;
  }

  @Override
  public TvNotificationHandler get() {
    return provideTvNotificationHandler(contextProvider.get(), notificationListenerProvider.get());
  }

  public static TvSystemUIModule_ProvideTvNotificationHandlerFactory create(
      Provider<Context> contextProvider,
      Provider<NotificationListener> notificationListenerProvider) {
    return new TvSystemUIModule_ProvideTvNotificationHandlerFactory(contextProvider, notificationListenerProvider);
  }

  public static TvNotificationHandler provideTvNotificationHandler(Context context,
      NotificationListener notificationListener) {
    return Preconditions.checkNotNullFromProvides(TvSystemUIModule.provideTvNotificationHandler(context, notificationListener));
  }
}

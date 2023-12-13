package com.android.systemui.statusbar.tv.notifications;

import android.content.Context;
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
public final class TvNotificationHandler_Factory implements Factory<TvNotificationHandler> {
  private final Provider<Context> contextProvider;

  private final Provider<NotificationListener> notificationListenerProvider;

  public TvNotificationHandler_Factory(Provider<Context> contextProvider,
      Provider<NotificationListener> notificationListenerProvider) {
    this.contextProvider = contextProvider;
    this.notificationListenerProvider = notificationListenerProvider;
  }

  @Override
  public TvNotificationHandler get() {
    return newInstance(contextProvider.get(), notificationListenerProvider.get());
  }

  public static TvNotificationHandler_Factory create(Provider<Context> contextProvider,
      Provider<NotificationListener> notificationListenerProvider) {
    return new TvNotificationHandler_Factory(contextProvider, notificationListenerProvider);
  }

  public static TvNotificationHandler newInstance(Context context,
      NotificationListener notificationListener) {
    return new TvNotificationHandler(context, notificationListener);
  }
}

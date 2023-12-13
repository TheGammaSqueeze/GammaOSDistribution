package com.android.systemui.statusbar.tv.notifications;

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
public final class TvNotificationPanelActivity_Factory implements Factory<TvNotificationPanelActivity> {
  private final Provider<TvNotificationHandler> tvNotificationHandlerProvider;

  public TvNotificationPanelActivity_Factory(
      Provider<TvNotificationHandler> tvNotificationHandlerProvider) {
    this.tvNotificationHandlerProvider = tvNotificationHandlerProvider;
  }

  @Override
  public TvNotificationPanelActivity get() {
    return newInstance(tvNotificationHandlerProvider.get());
  }

  public static TvNotificationPanelActivity_Factory create(
      Provider<TvNotificationHandler> tvNotificationHandlerProvider) {
    return new TvNotificationPanelActivity_Factory(tvNotificationHandlerProvider);
  }

  public static TvNotificationPanelActivity newInstance(
      TvNotificationHandler tvNotificationHandler) {
    return new TvNotificationPanelActivity(tvNotificationHandler);
  }
}

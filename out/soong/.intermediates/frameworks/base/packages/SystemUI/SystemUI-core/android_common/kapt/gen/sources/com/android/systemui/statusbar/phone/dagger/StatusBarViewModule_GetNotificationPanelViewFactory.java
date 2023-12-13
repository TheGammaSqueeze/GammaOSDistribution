package com.android.systemui.statusbar.phone.dagger;

import com.android.systemui.statusbar.phone.NotificationPanelView;
import com.android.systemui.statusbar.phone.NotificationShadeWindowView;
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
public final class StatusBarViewModule_GetNotificationPanelViewFactory implements Factory<NotificationPanelView> {
  private final Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider;

  public StatusBarViewModule_GetNotificationPanelViewFactory(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    this.notificationShadeWindowViewProvider = notificationShadeWindowViewProvider;
  }

  @Override
  public NotificationPanelView get() {
    return getNotificationPanelView(notificationShadeWindowViewProvider.get());
  }

  public static StatusBarViewModule_GetNotificationPanelViewFactory create(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    return new StatusBarViewModule_GetNotificationPanelViewFactory(notificationShadeWindowViewProvider);
  }

  public static NotificationPanelView getNotificationPanelView(
      NotificationShadeWindowView notificationShadeWindowView) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.getNotificationPanelView(notificationShadeWindowView));
  }
}

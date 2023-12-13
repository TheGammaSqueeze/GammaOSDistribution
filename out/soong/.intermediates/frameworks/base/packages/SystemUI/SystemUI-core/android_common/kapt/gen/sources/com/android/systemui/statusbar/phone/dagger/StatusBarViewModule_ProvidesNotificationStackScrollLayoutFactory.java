package com.android.systemui.statusbar.phone.dagger;

import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayout;
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
public final class StatusBarViewModule_ProvidesNotificationStackScrollLayoutFactory implements Factory<NotificationStackScrollLayout> {
  private final Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider;

  public StatusBarViewModule_ProvidesNotificationStackScrollLayoutFactory(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    this.notificationShadeWindowViewProvider = notificationShadeWindowViewProvider;
  }

  @Override
  public NotificationStackScrollLayout get() {
    return providesNotificationStackScrollLayout(notificationShadeWindowViewProvider.get());
  }

  public static StatusBarViewModule_ProvidesNotificationStackScrollLayoutFactory create(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    return new StatusBarViewModule_ProvidesNotificationStackScrollLayoutFactory(notificationShadeWindowViewProvider);
  }

  public static NotificationStackScrollLayout providesNotificationStackScrollLayout(
      NotificationShadeWindowView notificationShadeWindowView) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.providesNotificationStackScrollLayout(notificationShadeWindowView));
  }
}

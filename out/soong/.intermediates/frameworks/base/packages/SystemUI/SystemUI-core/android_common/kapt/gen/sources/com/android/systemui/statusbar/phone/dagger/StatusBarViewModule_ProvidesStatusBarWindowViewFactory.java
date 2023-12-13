package com.android.systemui.statusbar.phone.dagger;

import com.android.systemui.statusbar.NotificationShelf;
import com.android.systemui.statusbar.NotificationShelfController;
import com.android.systemui.statusbar.notification.row.dagger.NotificationShelfComponent;
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
public final class StatusBarViewModule_ProvidesStatusBarWindowViewFactory implements Factory<NotificationShelfController> {
  private final Provider<NotificationShelfComponent.Builder> notificationShelfComponentBuilderProvider;

  private final Provider<NotificationShelf> notificationShelfProvider;

  public StatusBarViewModule_ProvidesStatusBarWindowViewFactory(
      Provider<NotificationShelfComponent.Builder> notificationShelfComponentBuilderProvider,
      Provider<NotificationShelf> notificationShelfProvider) {
    this.notificationShelfComponentBuilderProvider = notificationShelfComponentBuilderProvider;
    this.notificationShelfProvider = notificationShelfProvider;
  }

  @Override
  public NotificationShelfController get() {
    return providesStatusBarWindowView(notificationShelfComponentBuilderProvider.get(), notificationShelfProvider.get());
  }

  public static StatusBarViewModule_ProvidesStatusBarWindowViewFactory create(
      Provider<NotificationShelfComponent.Builder> notificationShelfComponentBuilderProvider,
      Provider<NotificationShelf> notificationShelfProvider) {
    return new StatusBarViewModule_ProvidesStatusBarWindowViewFactory(notificationShelfComponentBuilderProvider, notificationShelfProvider);
  }

  public static NotificationShelfController providesStatusBarWindowView(
      NotificationShelfComponent.Builder notificationShelfComponentBuilder,
      NotificationShelf notificationShelf) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.providesStatusBarWindowView(notificationShelfComponentBuilder, notificationShelf));
  }
}

package com.android.systemui.statusbar.phone.dagger;

import android.view.LayoutInflater;
import com.android.systemui.statusbar.NotificationShelf;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayout;
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
public final class StatusBarViewModule_ProvidesNotificationShelfFactory implements Factory<NotificationShelf> {
  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<NotificationStackScrollLayout> notificationStackScrollLayoutProvider;

  public StatusBarViewModule_ProvidesNotificationShelfFactory(
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<NotificationStackScrollLayout> notificationStackScrollLayoutProvider) {
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.notificationStackScrollLayoutProvider = notificationStackScrollLayoutProvider;
  }

  @Override
  public NotificationShelf get() {
    return providesNotificationShelf(layoutInflaterProvider.get(), notificationStackScrollLayoutProvider.get());
  }

  public static StatusBarViewModule_ProvidesNotificationShelfFactory create(
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<NotificationStackScrollLayout> notificationStackScrollLayoutProvider) {
    return new StatusBarViewModule_ProvidesNotificationShelfFactory(layoutInflaterProvider, notificationStackScrollLayoutProvider);
  }

  public static NotificationShelf providesNotificationShelf(LayoutInflater layoutInflater,
      NotificationStackScrollLayout notificationStackScrollLayout) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.providesNotificationShelf(layoutInflater, notificationStackScrollLayout));
  }
}

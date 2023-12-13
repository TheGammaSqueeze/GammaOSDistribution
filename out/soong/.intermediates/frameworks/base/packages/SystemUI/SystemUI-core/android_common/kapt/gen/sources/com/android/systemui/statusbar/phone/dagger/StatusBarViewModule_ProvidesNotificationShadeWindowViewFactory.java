package com.android.systemui.statusbar.phone.dagger;

import android.view.LayoutInflater;
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
public final class StatusBarViewModule_ProvidesNotificationShadeWindowViewFactory implements Factory<NotificationShadeWindowView> {
  private final Provider<LayoutInflater> layoutInflaterProvider;

  public StatusBarViewModule_ProvidesNotificationShadeWindowViewFactory(
      Provider<LayoutInflater> layoutInflaterProvider) {
    this.layoutInflaterProvider = layoutInflaterProvider;
  }

  @Override
  public NotificationShadeWindowView get() {
    return providesNotificationShadeWindowView(layoutInflaterProvider.get());
  }

  public static StatusBarViewModule_ProvidesNotificationShadeWindowViewFactory create(
      Provider<LayoutInflater> layoutInflaterProvider) {
    return new StatusBarViewModule_ProvidesNotificationShadeWindowViewFactory(layoutInflaterProvider);
  }

  public static NotificationShadeWindowView providesNotificationShadeWindowView(
      LayoutInflater layoutInflater) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.providesNotificationShadeWindowView(layoutInflater));
  }
}

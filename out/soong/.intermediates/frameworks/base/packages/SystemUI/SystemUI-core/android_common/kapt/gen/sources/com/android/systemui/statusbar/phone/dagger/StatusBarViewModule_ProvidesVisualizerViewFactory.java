package com.android.systemui.statusbar.phone.dagger;

import com.android.systemui.statusbar.VisualizerView;
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
public final class StatusBarViewModule_ProvidesVisualizerViewFactory implements Factory<VisualizerView> {
  private final Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider;

  public StatusBarViewModule_ProvidesVisualizerViewFactory(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    this.notificationShadeWindowViewProvider = notificationShadeWindowViewProvider;
  }

  @Override
  public VisualizerView get() {
    return providesVisualizerView(notificationShadeWindowViewProvider.get());
  }

  public static StatusBarViewModule_ProvidesVisualizerViewFactory create(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    return new StatusBarViewModule_ProvidesVisualizerViewFactory(notificationShadeWindowViewProvider);
  }

  public static VisualizerView providesVisualizerView(
      NotificationShadeWindowView notificationShadeWindowView) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.providesVisualizerView(notificationShadeWindowView));
  }
}

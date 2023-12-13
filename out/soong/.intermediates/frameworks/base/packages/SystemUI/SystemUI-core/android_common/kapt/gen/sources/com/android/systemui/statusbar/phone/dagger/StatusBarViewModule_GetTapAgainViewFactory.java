package com.android.systemui.statusbar.phone.dagger;

import com.android.systemui.statusbar.phone.NotificationPanelView;
import com.android.systemui.statusbar.phone.TapAgainView;
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
public final class StatusBarViewModule_GetTapAgainViewFactory implements Factory<TapAgainView> {
  private final Provider<NotificationPanelView> npvProvider;

  public StatusBarViewModule_GetTapAgainViewFactory(Provider<NotificationPanelView> npvProvider) {
    this.npvProvider = npvProvider;
  }

  @Override
  public TapAgainView get() {
    return getTapAgainView(npvProvider.get());
  }

  public static StatusBarViewModule_GetTapAgainViewFactory create(
      Provider<NotificationPanelView> npvProvider) {
    return new StatusBarViewModule_GetTapAgainViewFactory(npvProvider);
  }

  public static TapAgainView getTapAgainView(NotificationPanelView npv) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.getTapAgainView(npv));
  }
}

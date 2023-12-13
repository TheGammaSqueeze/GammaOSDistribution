package com.android.systemui.statusbar.phone.dagger;

import android.annotation.Nullable;
import com.android.systemui.biometrics.AuthRippleView;
import com.android.systemui.statusbar.phone.NotificationShadeWindowView;
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
public final class StatusBarViewModule_GetAuthRippleViewFactory implements Factory<AuthRippleView> {
  private final Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider;

  public StatusBarViewModule_GetAuthRippleViewFactory(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    this.notificationShadeWindowViewProvider = notificationShadeWindowViewProvider;
  }

  @Override
  @Nullable
  public AuthRippleView get() {
    return getAuthRippleView(notificationShadeWindowViewProvider.get());
  }

  public static StatusBarViewModule_GetAuthRippleViewFactory create(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    return new StatusBarViewModule_GetAuthRippleViewFactory(notificationShadeWindowViewProvider);
  }

  @Nullable
  public static AuthRippleView getAuthRippleView(
      NotificationShadeWindowView notificationShadeWindowView) {
    return StatusBarViewModule.getAuthRippleView(notificationShadeWindowView);
  }
}

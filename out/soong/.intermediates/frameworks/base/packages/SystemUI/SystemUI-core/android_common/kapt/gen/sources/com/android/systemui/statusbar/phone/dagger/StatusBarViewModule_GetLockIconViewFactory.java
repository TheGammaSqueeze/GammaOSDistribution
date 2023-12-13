package com.android.systemui.statusbar.phone.dagger;

import com.android.keyguard.LockIconView;
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
public final class StatusBarViewModule_GetLockIconViewFactory implements Factory<LockIconView> {
  private final Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider;

  public StatusBarViewModule_GetLockIconViewFactory(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    this.notificationShadeWindowViewProvider = notificationShadeWindowViewProvider;
  }

  @Override
  public LockIconView get() {
    return getLockIconView(notificationShadeWindowViewProvider.get());
  }

  public static StatusBarViewModule_GetLockIconViewFactory create(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider) {
    return new StatusBarViewModule_GetLockIconViewFactory(notificationShadeWindowViewProvider);
  }

  public static LockIconView getLockIconView(
      NotificationShadeWindowView notificationShadeWindowView) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.getLockIconView(notificationShadeWindowView));
  }
}

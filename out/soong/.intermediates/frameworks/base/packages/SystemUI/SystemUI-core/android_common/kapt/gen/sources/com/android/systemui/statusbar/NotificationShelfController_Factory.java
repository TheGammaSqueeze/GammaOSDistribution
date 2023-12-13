package com.android.systemui.statusbar;

import com.android.systemui.statusbar.notification.row.ActivatableNotificationViewController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
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
public final class NotificationShelfController_Factory implements Factory<NotificationShelfController> {
  private final Provider<NotificationShelf> notificationShelfProvider;

  private final Provider<ActivatableNotificationViewController> activatableNotificationViewControllerProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  public NotificationShelfController_Factory(Provider<NotificationShelf> notificationShelfProvider,
      Provider<ActivatableNotificationViewController> activatableNotificationViewControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider) {
    this.notificationShelfProvider = notificationShelfProvider;
    this.activatableNotificationViewControllerProvider = activatableNotificationViewControllerProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
  }

  @Override
  public NotificationShelfController get() {
    return newInstance(notificationShelfProvider.get(), activatableNotificationViewControllerProvider.get(), keyguardBypassControllerProvider.get(), statusBarStateControllerProvider.get());
  }

  public static NotificationShelfController_Factory create(
      Provider<NotificationShelf> notificationShelfProvider,
      Provider<ActivatableNotificationViewController> activatableNotificationViewControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider) {
    return new NotificationShelfController_Factory(notificationShelfProvider, activatableNotificationViewControllerProvider, keyguardBypassControllerProvider, statusBarStateControllerProvider);
  }

  public static NotificationShelfController newInstance(NotificationShelf notificationShelf,
      ActivatableNotificationViewController activatableNotificationViewController,
      KeyguardBypassController keyguardBypassController,
      SysuiStatusBarStateController statusBarStateController) {
    return new NotificationShelfController(notificationShelf, activatableNotificationViewController, keyguardBypassController, statusBarStateController);
  }
}

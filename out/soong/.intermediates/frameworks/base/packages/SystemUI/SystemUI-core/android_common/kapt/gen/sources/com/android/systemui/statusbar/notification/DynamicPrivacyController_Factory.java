package com.android.systemui.statusbar.notification;

import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class DynamicPrivacyController_Factory implements Factory<DynamicPrivacyController> {
  private final Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<StatusBarStateController> stateControllerProvider;

  public DynamicPrivacyController_Factory(
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<StatusBarStateController> stateControllerProvider) {
    this.notificationLockscreenUserManagerProvider = notificationLockscreenUserManagerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.stateControllerProvider = stateControllerProvider;
  }

  @Override
  public DynamicPrivacyController get() {
    return newInstance(notificationLockscreenUserManagerProvider.get(), keyguardStateControllerProvider.get(), stateControllerProvider.get());
  }

  public static DynamicPrivacyController_Factory create(
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<StatusBarStateController> stateControllerProvider) {
    return new DynamicPrivacyController_Factory(notificationLockscreenUserManagerProvider, keyguardStateControllerProvider, stateControllerProvider);
  }

  public static DynamicPrivacyController newInstance(
      NotificationLockscreenUserManager notificationLockscreenUserManager,
      KeyguardStateController keyguardStateController, StatusBarStateController stateController) {
    return new DynamicPrivacyController(notificationLockscreenUserManager, keyguardStateController, stateController);
  }
}

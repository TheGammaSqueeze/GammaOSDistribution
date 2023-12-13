package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.notification.DynamicPrivacyController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class SensitiveContentCoordinatorModule_ProvideCoordinatorFactory implements Factory<SensitiveContentCoordinator> {
  private final Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider;

  private final Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  public SensitiveContentCoordinatorModule_ProvideCoordinatorFactory(
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    this.dynamicPrivacyControllerProvider = dynamicPrivacyControllerProvider;
    this.lockscreenUserManagerProvider = lockscreenUserManagerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
  }

  @Override
  public SensitiveContentCoordinator get() {
    return provideCoordinator(dynamicPrivacyControllerProvider.get(), lockscreenUserManagerProvider.get(), keyguardUpdateMonitorProvider.get(), statusBarStateControllerProvider.get(), keyguardStateControllerProvider.get());
  }

  public static SensitiveContentCoordinatorModule_ProvideCoordinatorFactory create(
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    return new SensitiveContentCoordinatorModule_ProvideCoordinatorFactory(dynamicPrivacyControllerProvider, lockscreenUserManagerProvider, keyguardUpdateMonitorProvider, statusBarStateControllerProvider, keyguardStateControllerProvider);
  }

  public static SensitiveContentCoordinator provideCoordinator(
      DynamicPrivacyController dynamicPrivacyController,
      NotificationLockscreenUserManager lockscreenUserManager,
      KeyguardUpdateMonitor keyguardUpdateMonitor,
      StatusBarStateController statusBarStateController,
      KeyguardStateController keyguardStateController) {
    return Preconditions.checkNotNullFromProvides(SensitiveContentCoordinatorModule.provideCoordinator(dynamicPrivacyController, lockscreenUserManager, keyguardUpdateMonitor, statusBarStateController, keyguardStateController));
  }
}

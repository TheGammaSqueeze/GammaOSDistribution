package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.NotificationLockscreenUserManagerImpl;
import com.android.systemui.statusbar.notification.row.NotificationGutsManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class ViewConfigCoordinator_Factory implements Factory<ViewConfigCoordinator> {
  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<NotificationLockscreenUserManagerImpl> lockscreenUserManagerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotificationGutsManager> mGutsManagerProvider;

  private final Provider<KeyguardUpdateMonitor> mKeyguardUpdateMonitorProvider;

  public ViewConfigCoordinator_Factory(
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<NotificationLockscreenUserManagerImpl> lockscreenUserManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationGutsManager> mGutsManagerProvider,
      Provider<KeyguardUpdateMonitor> mKeyguardUpdateMonitorProvider) {
    this.configurationControllerProvider = configurationControllerProvider;
    this.lockscreenUserManagerProvider = lockscreenUserManagerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.mGutsManagerProvider = mGutsManagerProvider;
    this.mKeyguardUpdateMonitorProvider = mKeyguardUpdateMonitorProvider;
  }

  @Override
  public ViewConfigCoordinator get() {
    return newInstance(configurationControllerProvider.get(), lockscreenUserManagerProvider.get(), featureFlagsProvider.get(), mGutsManagerProvider.get(), mKeyguardUpdateMonitorProvider.get());
  }

  public static ViewConfigCoordinator_Factory create(
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<NotificationLockscreenUserManagerImpl> lockscreenUserManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationGutsManager> mGutsManagerProvider,
      Provider<KeyguardUpdateMonitor> mKeyguardUpdateMonitorProvider) {
    return new ViewConfigCoordinator_Factory(configurationControllerProvider, lockscreenUserManagerProvider, featureFlagsProvider, mGutsManagerProvider, mKeyguardUpdateMonitorProvider);
  }

  public static ViewConfigCoordinator newInstance(ConfigurationController configurationController,
      NotificationLockscreenUserManagerImpl lockscreenUserManager, FeatureFlags featureFlags,
      NotificationGutsManager mGutsManager, KeyguardUpdateMonitor mKeyguardUpdateMonitor) {
    return new ViewConfigCoordinator(configurationController, lockscreenUserManager, featureFlags, mGutsManager, mKeyguardUpdateMonitor);
  }
}

package com.android.keyguard;

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
public final class KeyguardMessageAreaController_Factory_Factory implements Factory<KeyguardMessageAreaController.Factory> {
  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  public KeyguardMessageAreaController_Factory_Factory(
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.configurationControllerProvider = configurationControllerProvider;
  }

  @Override
  public KeyguardMessageAreaController.Factory get() {
    return newInstance(keyguardUpdateMonitorProvider.get(), configurationControllerProvider.get());
  }

  public static KeyguardMessageAreaController_Factory_Factory create(
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    return new KeyguardMessageAreaController_Factory_Factory(keyguardUpdateMonitorProvider, configurationControllerProvider);
  }

  public static KeyguardMessageAreaController.Factory newInstance(
      KeyguardUpdateMonitor keyguardUpdateMonitor,
      ConfigurationController configurationController) {
    return new KeyguardMessageAreaController.Factory(keyguardUpdateMonitor, configurationController);
  }
}

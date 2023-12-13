package com.android.systemui.statusbar.policy;

import android.hardware.devicestate.DeviceStateManager;
import com.android.systemui.util.settings.SecureSettings;
import com.android.systemui.util.wrapper.RotationPolicyWrapper;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
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
public final class DeviceStateRotationLockSettingController_Factory implements Factory<DeviceStateRotationLockSettingController> {
  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<RotationPolicyWrapper> rotationPolicyWrapperProvider;

  private final Provider<DeviceStateManager> deviceStateManagerProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<String[]> deviceStateRotationLockDefaultsProvider;

  public DeviceStateRotationLockSettingController_Factory(
      Provider<SecureSettings> secureSettingsProvider,
      Provider<RotationPolicyWrapper> rotationPolicyWrapperProvider,
      Provider<DeviceStateManager> deviceStateManagerProvider, Provider<Executor> executorProvider,
      Provider<String[]> deviceStateRotationLockDefaultsProvider) {
    this.secureSettingsProvider = secureSettingsProvider;
    this.rotationPolicyWrapperProvider = rotationPolicyWrapperProvider;
    this.deviceStateManagerProvider = deviceStateManagerProvider;
    this.executorProvider = executorProvider;
    this.deviceStateRotationLockDefaultsProvider = deviceStateRotationLockDefaultsProvider;
  }

  @Override
  public DeviceStateRotationLockSettingController get() {
    return newInstance(secureSettingsProvider.get(), rotationPolicyWrapperProvider.get(), deviceStateManagerProvider.get(), executorProvider.get(), deviceStateRotationLockDefaultsProvider.get());
  }

  public static DeviceStateRotationLockSettingController_Factory create(
      Provider<SecureSettings> secureSettingsProvider,
      Provider<RotationPolicyWrapper> rotationPolicyWrapperProvider,
      Provider<DeviceStateManager> deviceStateManagerProvider, Provider<Executor> executorProvider,
      Provider<String[]> deviceStateRotationLockDefaultsProvider) {
    return new DeviceStateRotationLockSettingController_Factory(secureSettingsProvider, rotationPolicyWrapperProvider, deviceStateManagerProvider, executorProvider, deviceStateRotationLockDefaultsProvider);
  }

  public static DeviceStateRotationLockSettingController newInstance(SecureSettings secureSettings,
      RotationPolicyWrapper rotationPolicyWrapper, DeviceStateManager deviceStateManager,
      Executor executor, String[] deviceStateRotationLockDefaults) {
    return new DeviceStateRotationLockSettingController(secureSettings, rotationPolicyWrapper, deviceStateManager, executor, deviceStateRotationLockDefaults);
  }
}

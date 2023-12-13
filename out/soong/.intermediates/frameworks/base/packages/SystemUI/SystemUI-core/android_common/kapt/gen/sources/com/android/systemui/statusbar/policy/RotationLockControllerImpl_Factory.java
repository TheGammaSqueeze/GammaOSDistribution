package com.android.systemui.statusbar.policy;

import com.android.systemui.util.wrapper.RotationPolicyWrapper;
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
public final class RotationLockControllerImpl_Factory implements Factory<RotationLockControllerImpl> {
  private final Provider<RotationPolicyWrapper> rotationPolicyWrapperProvider;

  private final Provider<DeviceStateRotationLockSettingController> deviceStateRotationLockSettingControllerProvider;

  private final Provider<String[]> deviceStateRotationLockDefaultsProvider;

  public RotationLockControllerImpl_Factory(
      Provider<RotationPolicyWrapper> rotationPolicyWrapperProvider,
      Provider<DeviceStateRotationLockSettingController> deviceStateRotationLockSettingControllerProvider,
      Provider<String[]> deviceStateRotationLockDefaultsProvider) {
    this.rotationPolicyWrapperProvider = rotationPolicyWrapperProvider;
    this.deviceStateRotationLockSettingControllerProvider = deviceStateRotationLockSettingControllerProvider;
    this.deviceStateRotationLockDefaultsProvider = deviceStateRotationLockDefaultsProvider;
  }

  @Override
  public RotationLockControllerImpl get() {
    return newInstance(rotationPolicyWrapperProvider.get(), deviceStateRotationLockSettingControllerProvider.get(), deviceStateRotationLockDefaultsProvider.get());
  }

  public static RotationLockControllerImpl_Factory create(
      Provider<RotationPolicyWrapper> rotationPolicyWrapperProvider,
      Provider<DeviceStateRotationLockSettingController> deviceStateRotationLockSettingControllerProvider,
      Provider<String[]> deviceStateRotationLockDefaultsProvider) {
    return new RotationLockControllerImpl_Factory(rotationPolicyWrapperProvider, deviceStateRotationLockSettingControllerProvider, deviceStateRotationLockDefaultsProvider);
  }

  public static RotationLockControllerImpl newInstance(RotationPolicyWrapper rotationPolicyWrapper,
      DeviceStateRotationLockSettingController deviceStateRotationLockSettingController,
      String[] deviceStateRotationLockDefaults) {
    return new RotationLockControllerImpl(rotationPolicyWrapper, deviceStateRotationLockSettingController, deviceStateRotationLockDefaults);
  }
}

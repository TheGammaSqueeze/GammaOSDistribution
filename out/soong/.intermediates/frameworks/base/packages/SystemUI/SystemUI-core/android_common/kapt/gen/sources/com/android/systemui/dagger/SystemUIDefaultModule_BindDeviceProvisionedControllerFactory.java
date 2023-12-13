package com.android.systemui.dagger;

import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.DeviceProvisionedControllerImpl;
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
public final class SystemUIDefaultModule_BindDeviceProvisionedControllerFactory implements Factory<DeviceProvisionedController> {
  private final Provider<DeviceProvisionedControllerImpl> deviceProvisionedControllerProvider;

  public SystemUIDefaultModule_BindDeviceProvisionedControllerFactory(
      Provider<DeviceProvisionedControllerImpl> deviceProvisionedControllerProvider) {
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
  }

  @Override
  public DeviceProvisionedController get() {
    return bindDeviceProvisionedController(deviceProvisionedControllerProvider.get());
  }

  public static SystemUIDefaultModule_BindDeviceProvisionedControllerFactory create(
      Provider<DeviceProvisionedControllerImpl> deviceProvisionedControllerProvider) {
    return new SystemUIDefaultModule_BindDeviceProvisionedControllerFactory(deviceProvisionedControllerProvider);
  }

  public static DeviceProvisionedController bindDeviceProvisionedController(
      DeviceProvisionedControllerImpl deviceProvisionedController) {
    return Preconditions.checkNotNullFromProvides(SystemUIDefaultModule.bindDeviceProvisionedController(deviceProvisionedController));
  }
}

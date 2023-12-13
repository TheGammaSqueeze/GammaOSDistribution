package com.android.systemui.tv;

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
public final class TvSystemUIModule_ProvidesDeviceProvisionedControllerFactory implements Factory<DeviceProvisionedController> {
  private final Provider<DeviceProvisionedControllerImpl> deviceProvisionedControllerProvider;

  public TvSystemUIModule_ProvidesDeviceProvisionedControllerFactory(
      Provider<DeviceProvisionedControllerImpl> deviceProvisionedControllerProvider) {
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
  }

  @Override
  public DeviceProvisionedController get() {
    return providesDeviceProvisionedController(deviceProvisionedControllerProvider.get());
  }

  public static TvSystemUIModule_ProvidesDeviceProvisionedControllerFactory create(
      Provider<DeviceProvisionedControllerImpl> deviceProvisionedControllerProvider) {
    return new TvSystemUIModule_ProvidesDeviceProvisionedControllerFactory(deviceProvisionedControllerProvider);
  }

  public static DeviceProvisionedController providesDeviceProvisionedController(
      DeviceProvisionedControllerImpl deviceProvisionedController) {
    return Preconditions.checkNotNullFromProvides(TvSystemUIModule.providesDeviceProvisionedController(deviceProvisionedController));
  }
}

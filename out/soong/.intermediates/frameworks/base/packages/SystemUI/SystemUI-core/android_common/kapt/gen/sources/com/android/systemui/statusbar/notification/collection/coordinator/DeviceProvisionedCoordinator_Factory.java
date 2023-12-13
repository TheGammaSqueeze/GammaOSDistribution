package com.android.systemui.statusbar.notification.collection.coordinator;

import android.content.pm.IPackageManager;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
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
public final class DeviceProvisionedCoordinator_Factory implements Factory<DeviceProvisionedCoordinator> {
  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<IPackageManager> packageManagerProvider;

  public DeviceProvisionedCoordinator_Factory(
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<IPackageManager> packageManagerProvider) {
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.packageManagerProvider = packageManagerProvider;
  }

  @Override
  public DeviceProvisionedCoordinator get() {
    return newInstance(deviceProvisionedControllerProvider.get(), packageManagerProvider.get());
  }

  public static DeviceProvisionedCoordinator_Factory create(
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<IPackageManager> packageManagerProvider) {
    return new DeviceProvisionedCoordinator_Factory(deviceProvisionedControllerProvider, packageManagerProvider);
  }

  public static DeviceProvisionedCoordinator newInstance(
      DeviceProvisionedController deviceProvisionedController, IPackageManager packageManager) {
    return new DeviceProvisionedCoordinator(deviceProvisionedController, packageManager);
  }
}

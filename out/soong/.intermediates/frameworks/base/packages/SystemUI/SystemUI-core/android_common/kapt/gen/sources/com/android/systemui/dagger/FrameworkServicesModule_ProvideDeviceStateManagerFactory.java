package com.android.systemui.dagger;

import android.content.Context;
import android.hardware.devicestate.DeviceStateManager;
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
public final class FrameworkServicesModule_ProvideDeviceStateManagerFactory implements Factory<DeviceStateManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideDeviceStateManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public DeviceStateManager get() {
    return provideDeviceStateManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideDeviceStateManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideDeviceStateManagerFactory(contextProvider);
  }

  public static DeviceStateManager provideDeviceStateManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideDeviceStateManager(context));
  }
}

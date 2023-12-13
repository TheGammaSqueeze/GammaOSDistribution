package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.hardware.devicestate.DeviceStateManager;
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
public final class DevicePostureControllerImpl_Factory implements Factory<DevicePostureControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<DeviceStateManager> deviceStateManagerProvider;

  private final Provider<Executor> executorProvider;

  public DevicePostureControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<DeviceStateManager> deviceStateManagerProvider,
      Provider<Executor> executorProvider) {
    this.contextProvider = contextProvider;
    this.deviceStateManagerProvider = deviceStateManagerProvider;
    this.executorProvider = executorProvider;
  }

  @Override
  public DevicePostureControllerImpl get() {
    return newInstance(contextProvider.get(), deviceStateManagerProvider.get(), executorProvider.get());
  }

  public static DevicePostureControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<DeviceStateManager> deviceStateManagerProvider,
      Provider<Executor> executorProvider) {
    return new DevicePostureControllerImpl_Factory(contextProvider, deviceStateManagerProvider, executorProvider);
  }

  public static DevicePostureControllerImpl newInstance(Context context,
      DeviceStateManager deviceStateManager, Executor executor) {
    return new DevicePostureControllerImpl(context, deviceStateManager, executor);
  }
}

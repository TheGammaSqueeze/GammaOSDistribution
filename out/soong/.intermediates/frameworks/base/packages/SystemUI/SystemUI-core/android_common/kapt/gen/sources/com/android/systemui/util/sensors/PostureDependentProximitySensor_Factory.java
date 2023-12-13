package com.android.systemui.util.sensors;

import com.android.systemui.statusbar.policy.DevicePostureController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.concurrency.Execution;
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
public final class PostureDependentProximitySensor_Factory implements Factory<PostureDependentProximitySensor> {
  private final Provider<ThresholdSensor[]> postureToPrimaryProxSensorMapProvider;

  private final Provider<ThresholdSensor[]> postureToSecondaryProxSensorMapProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  private final Provider<Execution> executionProvider;

  private final Provider<DevicePostureController> devicePostureControllerProvider;

  public PostureDependentProximitySensor_Factory(
      Provider<ThresholdSensor[]> postureToPrimaryProxSensorMapProvider,
      Provider<ThresholdSensor[]> postureToSecondaryProxSensorMapProvider,
      Provider<DelayableExecutor> delayableExecutorProvider, Provider<Execution> executionProvider,
      Provider<DevicePostureController> devicePostureControllerProvider) {
    this.postureToPrimaryProxSensorMapProvider = postureToPrimaryProxSensorMapProvider;
    this.postureToSecondaryProxSensorMapProvider = postureToSecondaryProxSensorMapProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
    this.executionProvider = executionProvider;
    this.devicePostureControllerProvider = devicePostureControllerProvider;
  }

  @Override
  public PostureDependentProximitySensor get() {
    return newInstance(postureToPrimaryProxSensorMapProvider.get(), postureToSecondaryProxSensorMapProvider.get(), delayableExecutorProvider.get(), executionProvider.get(), devicePostureControllerProvider.get());
  }

  public static PostureDependentProximitySensor_Factory create(
      Provider<ThresholdSensor[]> postureToPrimaryProxSensorMapProvider,
      Provider<ThresholdSensor[]> postureToSecondaryProxSensorMapProvider,
      Provider<DelayableExecutor> delayableExecutorProvider, Provider<Execution> executionProvider,
      Provider<DevicePostureController> devicePostureControllerProvider) {
    return new PostureDependentProximitySensor_Factory(postureToPrimaryProxSensorMapProvider, postureToSecondaryProxSensorMapProvider, delayableExecutorProvider, executionProvider, devicePostureControllerProvider);
  }

  public static PostureDependentProximitySensor newInstance(
      ThresholdSensor[] postureToPrimaryProxSensorMap,
      ThresholdSensor[] postureToSecondaryProxSensorMap, DelayableExecutor delayableExecutor,
      Execution execution, DevicePostureController devicePostureController) {
    return new PostureDependentProximitySensor(postureToPrimaryProxSensorMap, postureToSecondaryProxSensorMap, delayableExecutor, execution, devicePostureController);
  }
}

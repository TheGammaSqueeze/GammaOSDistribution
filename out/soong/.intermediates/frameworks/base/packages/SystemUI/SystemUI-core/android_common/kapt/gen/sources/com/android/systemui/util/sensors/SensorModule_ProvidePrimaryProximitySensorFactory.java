package com.android.systemui.util.sensors;

import android.hardware.SensorManager;
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
public final class SensorModule_ProvidePrimaryProximitySensorFactory implements Factory<ThresholdSensor> {
  private final Provider<SensorManager> sensorManagerProvider;

  private final Provider<ThresholdSensorImpl.Builder> thresholdSensorBuilderProvider;

  public SensorModule_ProvidePrimaryProximitySensorFactory(
      Provider<SensorManager> sensorManagerProvider,
      Provider<ThresholdSensorImpl.Builder> thresholdSensorBuilderProvider) {
    this.sensorManagerProvider = sensorManagerProvider;
    this.thresholdSensorBuilderProvider = thresholdSensorBuilderProvider;
  }

  @Override
  public ThresholdSensor get() {
    return providePrimaryProximitySensor(sensorManagerProvider.get(), thresholdSensorBuilderProvider.get());
  }

  public static SensorModule_ProvidePrimaryProximitySensorFactory create(
      Provider<SensorManager> sensorManagerProvider,
      Provider<ThresholdSensorImpl.Builder> thresholdSensorBuilderProvider) {
    return new SensorModule_ProvidePrimaryProximitySensorFactory(sensorManagerProvider, thresholdSensorBuilderProvider);
  }

  public static ThresholdSensor providePrimaryProximitySensor(SensorManager sensorManager,
      ThresholdSensorImpl.Builder thresholdSensorBuilder) {
    return Preconditions.checkNotNullFromProvides(SensorModule.providePrimaryProximitySensor(sensorManager, thresholdSensorBuilder));
  }
}

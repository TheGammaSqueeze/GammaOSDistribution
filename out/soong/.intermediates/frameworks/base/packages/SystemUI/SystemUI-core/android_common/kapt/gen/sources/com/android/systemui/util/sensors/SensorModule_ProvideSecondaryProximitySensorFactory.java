package com.android.systemui.util.sensors;

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
public final class SensorModule_ProvideSecondaryProximitySensorFactory implements Factory<ThresholdSensor> {
  private final Provider<ThresholdSensorImpl.Builder> thresholdSensorBuilderProvider;

  public SensorModule_ProvideSecondaryProximitySensorFactory(
      Provider<ThresholdSensorImpl.Builder> thresholdSensorBuilderProvider) {
    this.thresholdSensorBuilderProvider = thresholdSensorBuilderProvider;
  }

  @Override
  public ThresholdSensor get() {
    return provideSecondaryProximitySensor(thresholdSensorBuilderProvider.get());
  }

  public static SensorModule_ProvideSecondaryProximitySensorFactory create(
      Provider<ThresholdSensorImpl.Builder> thresholdSensorBuilderProvider) {
    return new SensorModule_ProvideSecondaryProximitySensorFactory(thresholdSensorBuilderProvider);
  }

  public static ThresholdSensor provideSecondaryProximitySensor(
      ThresholdSensorImpl.Builder thresholdSensorBuilder) {
    return Preconditions.checkNotNullFromProvides(SensorModule.provideSecondaryProximitySensor(thresholdSensorBuilder));
  }
}

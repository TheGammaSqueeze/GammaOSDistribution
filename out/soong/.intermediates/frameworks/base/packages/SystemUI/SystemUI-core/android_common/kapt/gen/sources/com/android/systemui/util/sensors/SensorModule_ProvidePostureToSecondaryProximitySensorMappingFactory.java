package com.android.systemui.util.sensors;

import android.content.res.Resources;
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
public final class SensorModule_ProvidePostureToSecondaryProximitySensorMappingFactory implements Factory<ThresholdSensor[]> {
  private final Provider<ThresholdSensorImpl.BuilderFactory> thresholdSensorImplBuilderFactoryProvider;

  private final Provider<Resources> resourcesProvider;

  public SensorModule_ProvidePostureToSecondaryProximitySensorMappingFactory(
      Provider<ThresholdSensorImpl.BuilderFactory> thresholdSensorImplBuilderFactoryProvider,
      Provider<Resources> resourcesProvider) {
    this.thresholdSensorImplBuilderFactoryProvider = thresholdSensorImplBuilderFactoryProvider;
    this.resourcesProvider = resourcesProvider;
  }

  @Override
  public ThresholdSensor[] get() {
    return providePostureToSecondaryProximitySensorMapping(thresholdSensorImplBuilderFactoryProvider.get(), resourcesProvider.get());
  }

  public static SensorModule_ProvidePostureToSecondaryProximitySensorMappingFactory create(
      Provider<ThresholdSensorImpl.BuilderFactory> thresholdSensorImplBuilderFactoryProvider,
      Provider<Resources> resourcesProvider) {
    return new SensorModule_ProvidePostureToSecondaryProximitySensorMappingFactory(thresholdSensorImplBuilderFactoryProvider, resourcesProvider);
  }

  public static ThresholdSensor[] providePostureToSecondaryProximitySensorMapping(
      ThresholdSensorImpl.BuilderFactory thresholdSensorImplBuilderFactory, Resources resources) {
    return Preconditions.checkNotNullFromProvides(SensorModule.providePostureToSecondaryProximitySensorMapping(thresholdSensorImplBuilderFactory, resources));
  }
}

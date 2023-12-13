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
public final class SensorModule_ProvidePostureToProximitySensorMappingFactory implements Factory<ThresholdSensor[]> {
  private final Provider<ThresholdSensorImpl.BuilderFactory> thresholdSensorImplBuilderFactoryProvider;

  private final Provider<Resources> resourcesProvider;

  public SensorModule_ProvidePostureToProximitySensorMappingFactory(
      Provider<ThresholdSensorImpl.BuilderFactory> thresholdSensorImplBuilderFactoryProvider,
      Provider<Resources> resourcesProvider) {
    this.thresholdSensorImplBuilderFactoryProvider = thresholdSensorImplBuilderFactoryProvider;
    this.resourcesProvider = resourcesProvider;
  }

  @Override
  public ThresholdSensor[] get() {
    return providePostureToProximitySensorMapping(thresholdSensorImplBuilderFactoryProvider.get(), resourcesProvider.get());
  }

  public static SensorModule_ProvidePostureToProximitySensorMappingFactory create(
      Provider<ThresholdSensorImpl.BuilderFactory> thresholdSensorImplBuilderFactoryProvider,
      Provider<Resources> resourcesProvider) {
    return new SensorModule_ProvidePostureToProximitySensorMappingFactory(thresholdSensorImplBuilderFactoryProvider, resourcesProvider);
  }

  public static ThresholdSensor[] providePostureToProximitySensorMapping(
      ThresholdSensorImpl.BuilderFactory thresholdSensorImplBuilderFactory, Resources resources) {
    return Preconditions.checkNotNullFromProvides(SensorModule.providePostureToProximitySensorMapping(thresholdSensorImplBuilderFactory, resources));
  }
}

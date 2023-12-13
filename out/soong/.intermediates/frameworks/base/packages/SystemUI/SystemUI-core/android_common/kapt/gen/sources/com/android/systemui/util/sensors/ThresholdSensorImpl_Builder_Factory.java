package com.android.systemui.util.sensors;

import android.content.res.Resources;
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
public final class ThresholdSensorImpl_Builder_Factory implements Factory<ThresholdSensorImpl.Builder> {
  private final Provider<Resources> resourcesProvider;

  private final Provider<AsyncSensorManager> sensorManagerProvider;

  private final Provider<Execution> executionProvider;

  public ThresholdSensorImpl_Builder_Factory(Provider<Resources> resourcesProvider,
      Provider<AsyncSensorManager> sensorManagerProvider, Provider<Execution> executionProvider) {
    this.resourcesProvider = resourcesProvider;
    this.sensorManagerProvider = sensorManagerProvider;
    this.executionProvider = executionProvider;
  }

  @Override
  public ThresholdSensorImpl.Builder get() {
    return newInstance(resourcesProvider.get(), sensorManagerProvider.get(), executionProvider.get());
  }

  public static ThresholdSensorImpl_Builder_Factory create(Provider<Resources> resourcesProvider,
      Provider<AsyncSensorManager> sensorManagerProvider, Provider<Execution> executionProvider) {
    return new ThresholdSensorImpl_Builder_Factory(resourcesProvider, sensorManagerProvider, executionProvider);
  }

  public static ThresholdSensorImpl.Builder newInstance(Resources resources,
      AsyncSensorManager sensorManager, Execution execution) {
    return new ThresholdSensorImpl.Builder(resources, sensorManager, execution);
  }
}

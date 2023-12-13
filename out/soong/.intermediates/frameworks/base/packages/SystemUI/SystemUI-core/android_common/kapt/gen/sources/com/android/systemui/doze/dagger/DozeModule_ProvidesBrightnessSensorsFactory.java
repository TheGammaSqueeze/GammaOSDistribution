package com.android.systemui.doze.dagger;

import android.content.Context;
import android.hardware.Sensor;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.util.sensors.AsyncSensorManager;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Optional;
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
public final class DozeModule_ProvidesBrightnessSensorsFactory implements Factory<Optional<Sensor>[]> {
  private final Provider<AsyncSensorManager> sensorManagerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  public DozeModule_ProvidesBrightnessSensorsFactory(
      Provider<AsyncSensorManager> sensorManagerProvider, Provider<Context> contextProvider,
      Provider<DozeParameters> dozeParametersProvider) {
    this.sensorManagerProvider = sensorManagerProvider;
    this.contextProvider = contextProvider;
    this.dozeParametersProvider = dozeParametersProvider;
  }

  @Override
  public Optional<Sensor>[] get() {
    return providesBrightnessSensors(sensorManagerProvider.get(), contextProvider.get(), dozeParametersProvider.get());
  }

  public static DozeModule_ProvidesBrightnessSensorsFactory create(
      Provider<AsyncSensorManager> sensorManagerProvider, Provider<Context> contextProvider,
      Provider<DozeParameters> dozeParametersProvider) {
    return new DozeModule_ProvidesBrightnessSensorsFactory(sensorManagerProvider, contextProvider, dozeParametersProvider);
  }

  public static Optional<Sensor>[] providesBrightnessSensors(AsyncSensorManager sensorManager,
      Context context, DozeParameters dozeParameters) {
    return Preconditions.checkNotNullFromProvides(DozeModule.providesBrightnessSensors(sensorManager, context, dozeParameters));
  }
}

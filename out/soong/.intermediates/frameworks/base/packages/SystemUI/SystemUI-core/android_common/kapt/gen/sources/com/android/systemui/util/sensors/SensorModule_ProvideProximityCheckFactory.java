package com.android.systemui.util.sensors;

import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class SensorModule_ProvideProximityCheckFactory implements Factory<ProximityCheck> {
  private final Provider<ProximitySensor> proximitySensorProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  public SensorModule_ProvideProximityCheckFactory(
      Provider<ProximitySensor> proximitySensorProvider,
      Provider<DelayableExecutor> delayableExecutorProvider) {
    this.proximitySensorProvider = proximitySensorProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
  }

  @Override
  public ProximityCheck get() {
    return provideProximityCheck(proximitySensorProvider.get(), delayableExecutorProvider.get());
  }

  public static SensorModule_ProvideProximityCheckFactory create(
      Provider<ProximitySensor> proximitySensorProvider,
      Provider<DelayableExecutor> delayableExecutorProvider) {
    return new SensorModule_ProvideProximityCheckFactory(proximitySensorProvider, delayableExecutorProvider);
  }

  public static ProximityCheck provideProximityCheck(ProximitySensor proximitySensor,
      DelayableExecutor delayableExecutor) {
    return Preconditions.checkNotNullFromProvides(SensorModule.provideProximityCheck(proximitySensor, delayableExecutor));
  }
}

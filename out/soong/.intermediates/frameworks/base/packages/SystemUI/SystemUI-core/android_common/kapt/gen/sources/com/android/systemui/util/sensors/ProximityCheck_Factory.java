package com.android.systemui.util.sensors;

import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class ProximityCheck_Factory implements Factory<ProximityCheck> {
  private final Provider<ProximitySensor> sensorProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  public ProximityCheck_Factory(Provider<ProximitySensor> sensorProvider,
      Provider<DelayableExecutor> delayableExecutorProvider) {
    this.sensorProvider = sensorProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
  }

  @Override
  public ProximityCheck get() {
    return newInstance(sensorProvider.get(), delayableExecutorProvider.get());
  }

  public static ProximityCheck_Factory create(Provider<ProximitySensor> sensorProvider,
      Provider<DelayableExecutor> delayableExecutorProvider) {
    return new ProximityCheck_Factory(sensorProvider, delayableExecutorProvider);
  }

  public static ProximityCheck newInstance(ProximitySensor sensor,
      DelayableExecutor delayableExecutor) {
    return new ProximityCheck(sensor, delayableExecutor);
  }
}

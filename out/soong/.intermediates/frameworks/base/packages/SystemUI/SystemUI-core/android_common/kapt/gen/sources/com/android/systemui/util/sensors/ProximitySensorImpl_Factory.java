package com.android.systemui.util.sensors;

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
public final class ProximitySensorImpl_Factory implements Factory<ProximitySensorImpl> {
  private final Provider<ThresholdSensor> primaryProvider;

  private final Provider<ThresholdSensor> secondaryProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  private final Provider<Execution> executionProvider;

  public ProximitySensorImpl_Factory(Provider<ThresholdSensor> primaryProvider,
      Provider<ThresholdSensor> secondaryProvider,
      Provider<DelayableExecutor> delayableExecutorProvider,
      Provider<Execution> executionProvider) {
    this.primaryProvider = primaryProvider;
    this.secondaryProvider = secondaryProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
    this.executionProvider = executionProvider;
  }

  @Override
  public ProximitySensorImpl get() {
    return newInstance(primaryProvider.get(), secondaryProvider.get(), delayableExecutorProvider.get(), executionProvider.get());
  }

  public static ProximitySensorImpl_Factory create(Provider<ThresholdSensor> primaryProvider,
      Provider<ThresholdSensor> secondaryProvider,
      Provider<DelayableExecutor> delayableExecutorProvider,
      Provider<Execution> executionProvider) {
    return new ProximitySensorImpl_Factory(primaryProvider, secondaryProvider, delayableExecutorProvider, executionProvider);
  }

  public static ProximitySensorImpl newInstance(ThresholdSensor primary, ThresholdSensor secondary,
      DelayableExecutor delayableExecutor, Execution execution) {
    return new ProximitySensorImpl(primary, secondary, delayableExecutor, execution);
  }
}

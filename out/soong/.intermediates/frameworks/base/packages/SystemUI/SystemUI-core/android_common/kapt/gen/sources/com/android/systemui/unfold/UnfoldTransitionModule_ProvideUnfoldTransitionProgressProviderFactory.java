package com.android.systemui.unfold;

import android.content.Context;
import android.hardware.SensorManager;
import android.hardware.devicestate.DeviceStateManager;
import android.os.Handler;
import com.android.systemui.keyguard.LifecycleScreenStatusProvider;
import com.android.systemui.unfold.config.UnfoldTransitionConfig;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Optional;
import java.util.concurrent.Executor;
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
public final class UnfoldTransitionModule_ProvideUnfoldTransitionProgressProviderFactory implements Factory<Optional<UnfoldTransitionProgressProvider>> {
  private final UnfoldTransitionModule module;

  private final Provider<Context> contextProvider;

  private final Provider<UnfoldTransitionConfig> configProvider;

  private final Provider<LifecycleScreenStatusProvider> screenStatusProvider;

  private final Provider<DeviceStateManager> deviceStateManagerProvider;

  private final Provider<SensorManager> sensorManagerProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<Handler> handlerProvider;

  public UnfoldTransitionModule_ProvideUnfoldTransitionProgressProviderFactory(
      UnfoldTransitionModule module, Provider<Context> contextProvider,
      Provider<UnfoldTransitionConfig> configProvider,
      Provider<LifecycleScreenStatusProvider> screenStatusProvider,
      Provider<DeviceStateManager> deviceStateManagerProvider,
      Provider<SensorManager> sensorManagerProvider, Provider<Executor> executorProvider,
      Provider<Handler> handlerProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
    this.configProvider = configProvider;
    this.screenStatusProvider = screenStatusProvider;
    this.deviceStateManagerProvider = deviceStateManagerProvider;
    this.sensorManagerProvider = sensorManagerProvider;
    this.executorProvider = executorProvider;
    this.handlerProvider = handlerProvider;
  }

  @Override
  public Optional<UnfoldTransitionProgressProvider> get() {
    return provideUnfoldTransitionProgressProvider(module, contextProvider.get(), configProvider.get(), DoubleCheck.lazy(screenStatusProvider), deviceStateManagerProvider.get(), sensorManagerProvider.get(), executorProvider.get(), handlerProvider.get());
  }

  public static UnfoldTransitionModule_ProvideUnfoldTransitionProgressProviderFactory create(
      UnfoldTransitionModule module, Provider<Context> contextProvider,
      Provider<UnfoldTransitionConfig> configProvider,
      Provider<LifecycleScreenStatusProvider> screenStatusProvider,
      Provider<DeviceStateManager> deviceStateManagerProvider,
      Provider<SensorManager> sensorManagerProvider, Provider<Executor> executorProvider,
      Provider<Handler> handlerProvider) {
    return new UnfoldTransitionModule_ProvideUnfoldTransitionProgressProviderFactory(module, contextProvider, configProvider, screenStatusProvider, deviceStateManagerProvider, sensorManagerProvider, executorProvider, handlerProvider);
  }

  public static Optional<UnfoldTransitionProgressProvider> provideUnfoldTransitionProgressProvider(
      UnfoldTransitionModule instance, Context context, UnfoldTransitionConfig config,
      Lazy<LifecycleScreenStatusProvider> screenStatusProvider,
      DeviceStateManager deviceStateManager, SensorManager sensorManager, Executor executor,
      Handler handler) {
    return Preconditions.checkNotNullFromProvides(instance.provideUnfoldTransitionProgressProvider(context, config, screenStatusProvider, deviceStateManager, sensorManager, executor, handler));
  }
}

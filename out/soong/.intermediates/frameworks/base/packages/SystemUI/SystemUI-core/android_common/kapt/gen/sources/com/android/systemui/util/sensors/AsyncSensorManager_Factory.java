package com.android.systemui.util.sensors;

import android.hardware.SensorManager;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.util.concurrency.ThreadFactory;
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
public final class AsyncSensorManager_Factory implements Factory<AsyncSensorManager> {
  private final Provider<SensorManager> sensorManagerProvider;

  private final Provider<ThreadFactory> threadFactoryProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  public AsyncSensorManager_Factory(Provider<SensorManager> sensorManagerProvider,
      Provider<ThreadFactory> threadFactoryProvider,
      Provider<PluginManager> pluginManagerProvider) {
    this.sensorManagerProvider = sensorManagerProvider;
    this.threadFactoryProvider = threadFactoryProvider;
    this.pluginManagerProvider = pluginManagerProvider;
  }

  @Override
  public AsyncSensorManager get() {
    return newInstance(sensorManagerProvider.get(), threadFactoryProvider.get(), pluginManagerProvider.get());
  }

  public static AsyncSensorManager_Factory create(Provider<SensorManager> sensorManagerProvider,
      Provider<ThreadFactory> threadFactoryProvider,
      Provider<PluginManager> pluginManagerProvider) {
    return new AsyncSensorManager_Factory(sensorManagerProvider, threadFactoryProvider, pluginManagerProvider);
  }

  public static AsyncSensorManager newInstance(SensorManager sensorManager,
      ThreadFactory threadFactory, PluginManager pluginManager) {
    return new AsyncSensorManager(sensorManager, threadFactory, pluginManager);
  }
}

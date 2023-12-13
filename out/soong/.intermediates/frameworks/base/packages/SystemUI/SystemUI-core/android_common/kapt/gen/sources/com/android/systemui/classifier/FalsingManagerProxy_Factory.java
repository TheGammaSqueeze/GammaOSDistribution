package com.android.systemui.classifier;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.util.DeviceConfigProxy;
import dagger.internal.Factory;
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
public final class FalsingManagerProxy_Factory implements Factory<FalsingManagerProxy> {
  private final Provider<PluginManager> pluginManagerProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<DeviceConfigProxy> deviceConfigProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<BrightLineFalsingManager> brightLineFalsingManagerProvider;

  public FalsingManagerProxy_Factory(Provider<PluginManager> pluginManagerProvider,
      Provider<Executor> executorProvider, Provider<DeviceConfigProxy> deviceConfigProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<BrightLineFalsingManager> brightLineFalsingManagerProvider) {
    this.pluginManagerProvider = pluginManagerProvider;
    this.executorProvider = executorProvider;
    this.deviceConfigProvider = deviceConfigProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.brightLineFalsingManagerProvider = brightLineFalsingManagerProvider;
  }

  @Override
  public FalsingManagerProxy get() {
    return newInstance(pluginManagerProvider.get(), executorProvider.get(), deviceConfigProvider.get(), dumpManagerProvider.get(), brightLineFalsingManagerProvider);
  }

  public static FalsingManagerProxy_Factory create(Provider<PluginManager> pluginManagerProvider,
      Provider<Executor> executorProvider, Provider<DeviceConfigProxy> deviceConfigProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<BrightLineFalsingManager> brightLineFalsingManagerProvider) {
    return new FalsingManagerProxy_Factory(pluginManagerProvider, executorProvider, deviceConfigProvider, dumpManagerProvider, brightLineFalsingManagerProvider);
  }

  public static FalsingManagerProxy newInstance(PluginManager pluginManager, Executor executor,
      DeviceConfigProxy deviceConfig, DumpManager dumpManager,
      Provider<BrightLineFalsingManager> brightLineFalsingManagerProvider) {
    return new FalsingManagerProxy(pluginManager, executor, deviceConfig, dumpManager, brightLineFalsingManagerProvider);
  }
}

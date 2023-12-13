package com.android.systemui.statusbar.policy;

import android.content.Context;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.leak.LeakDetector;
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
public final class ExtensionControllerImpl_Factory implements Factory<ExtensionControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<LeakDetector> leakDetectorProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  public ExtensionControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<LeakDetector> leakDetectorProvider, Provider<PluginManager> pluginManagerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    this.contextProvider = contextProvider;
    this.leakDetectorProvider = leakDetectorProvider;
    this.pluginManagerProvider = pluginManagerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.configurationControllerProvider = configurationControllerProvider;
  }

  @Override
  public ExtensionControllerImpl get() {
    return newInstance(contextProvider.get(), leakDetectorProvider.get(), pluginManagerProvider.get(), tunerServiceProvider.get(), configurationControllerProvider.get());
  }

  public static ExtensionControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<LeakDetector> leakDetectorProvider, Provider<PluginManager> pluginManagerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    return new ExtensionControllerImpl_Factory(contextProvider, leakDetectorProvider, pluginManagerProvider, tunerServiceProvider, configurationControllerProvider);
  }

  public static ExtensionControllerImpl newInstance(Context context, LeakDetector leakDetector,
      PluginManager pluginManager, TunerService tunerService,
      ConfigurationController configurationController) {
    return new ExtensionControllerImpl(context, leakDetector, pluginManager, tunerService, configurationController);
  }
}

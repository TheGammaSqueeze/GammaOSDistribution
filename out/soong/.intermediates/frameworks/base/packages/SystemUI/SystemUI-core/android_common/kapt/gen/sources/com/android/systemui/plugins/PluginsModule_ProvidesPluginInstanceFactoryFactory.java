package com.android.systemui.plugins;

import com.android.systemui.shared.plugins.PluginInstance;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.List;
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
public final class PluginsModule_ProvidesPluginInstanceFactoryFactory implements Factory<PluginInstance.Factory> {
  private final Provider<List<String>> privilegedPluginsProvider;

  private final Provider<Boolean> isDebugProvider;

  public PluginsModule_ProvidesPluginInstanceFactoryFactory(
      Provider<List<String>> privilegedPluginsProvider, Provider<Boolean> isDebugProvider) {
    this.privilegedPluginsProvider = privilegedPluginsProvider;
    this.isDebugProvider = isDebugProvider;
  }

  @Override
  public PluginInstance.Factory get() {
    return providesPluginInstanceFactory(privilegedPluginsProvider.get(), isDebugProvider.get());
  }

  public static PluginsModule_ProvidesPluginInstanceFactoryFactory create(
      Provider<List<String>> privilegedPluginsProvider, Provider<Boolean> isDebugProvider) {
    return new PluginsModule_ProvidesPluginInstanceFactoryFactory(privilegedPluginsProvider, isDebugProvider);
  }

  public static PluginInstance.Factory providesPluginInstanceFactory(List<String> privilegedPlugins,
      boolean isDebug) {
    return Preconditions.checkNotNullFromProvides(PluginsModule.providesPluginInstanceFactory(privilegedPlugins, isDebug));
  }
}

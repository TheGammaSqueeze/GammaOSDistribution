package com.android.systemui.doze;

import com.android.systemui.doze.dagger.DozeComponent;
import com.android.systemui.shared.plugins.PluginManager;
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
public final class DozeService_Factory implements Factory<DozeService> {
  private final Provider<DozeComponent.Builder> dozeComponentBuilderProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  public DozeService_Factory(Provider<DozeComponent.Builder> dozeComponentBuilderProvider,
      Provider<PluginManager> pluginManagerProvider) {
    this.dozeComponentBuilderProvider = dozeComponentBuilderProvider;
    this.pluginManagerProvider = pluginManagerProvider;
  }

  @Override
  public DozeService get() {
    return newInstance(dozeComponentBuilderProvider.get(), pluginManagerProvider.get());
  }

  public static DozeService_Factory create(
      Provider<DozeComponent.Builder> dozeComponentBuilderProvider,
      Provider<PluginManager> pluginManagerProvider) {
    return new DozeService_Factory(dozeComponentBuilderProvider, pluginManagerProvider);
  }

  public static DozeService newInstance(DozeComponent.Builder dozeComponentBuilder,
      PluginManager pluginManager) {
    return new DozeService(dozeComponentBuilder, pluginManager);
  }
}

package com.android.systemui.plugins;

import com.android.systemui.shared.plugins.PluginManager;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class PluginDependencyProvider_Factory implements Factory<PluginDependencyProvider> {
  private final Provider<PluginManager> managerLazyProvider;

  public PluginDependencyProvider_Factory(Provider<PluginManager> managerLazyProvider) {
    this.managerLazyProvider = managerLazyProvider;
  }

  @Override
  public PluginDependencyProvider get() {
    return newInstance(DoubleCheck.lazy(managerLazyProvider));
  }

  public static PluginDependencyProvider_Factory create(
      Provider<PluginManager> managerLazyProvider) {
    return new PluginDependencyProvider_Factory(managerLazyProvider);
  }

  public static PluginDependencyProvider newInstance(Lazy<PluginManager> managerLazy) {
    return new PluginDependencyProvider(managerLazy);
  }
}

package com.android.systemui.dagger;

import android.content.Context;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class DependencyProvider_ProvideConfigurationControllerFactory implements Factory<ConfigurationController> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  public DependencyProvider_ProvideConfigurationControllerFactory(DependencyProvider module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public ConfigurationController get() {
    return provideConfigurationController(module, contextProvider.get());
  }

  public static DependencyProvider_ProvideConfigurationControllerFactory create(
      DependencyProvider module, Provider<Context> contextProvider) {
    return new DependencyProvider_ProvideConfigurationControllerFactory(module, contextProvider);
  }

  public static ConfigurationController provideConfigurationController(DependencyProvider instance,
      Context context) {
    return Preconditions.checkNotNullFromProvides(instance.provideConfigurationController(context));
  }
}

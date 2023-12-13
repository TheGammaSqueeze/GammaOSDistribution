package com.android.systemui.dagger;

import android.content.Context;
import android.hardware.display.AmbientDisplayConfiguration;
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
public final class DependencyProvider_ProvideAmbientDisplayConfigurationFactory implements Factory<AmbientDisplayConfiguration> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  public DependencyProvider_ProvideAmbientDisplayConfigurationFactory(DependencyProvider module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public AmbientDisplayConfiguration get() {
    return provideAmbientDisplayConfiguration(module, contextProvider.get());
  }

  public static DependencyProvider_ProvideAmbientDisplayConfigurationFactory create(
      DependencyProvider module, Provider<Context> contextProvider) {
    return new DependencyProvider_ProvideAmbientDisplayConfigurationFactory(module, contextProvider);
  }

  public static AmbientDisplayConfiguration provideAmbientDisplayConfiguration(
      DependencyProvider instance, Context context) {
    return Preconditions.checkNotNullFromProvides(instance.provideAmbientDisplayConfiguration(context));
  }
}

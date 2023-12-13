package com.android.systemui.dagger;

import android.content.Context;
import android.view.ViewConfiguration;
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
public final class FrameworkServicesModule_ProvideViewConfigurationFactory implements Factory<ViewConfiguration> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideViewConfigurationFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public ViewConfiguration get() {
    return provideViewConfiguration(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideViewConfigurationFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideViewConfigurationFactory(contextProvider);
  }

  public static ViewConfiguration provideViewConfiguration(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideViewConfiguration(context));
  }
}

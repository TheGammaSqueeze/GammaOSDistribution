package com.android.systemui.dagger;

import com.android.internal.logging.MetricsLogger;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class DependencyProvider_ProvideMetricsLoggerFactory implements Factory<MetricsLogger> {
  private final DependencyProvider module;

  public DependencyProvider_ProvideMetricsLoggerFactory(DependencyProvider module) {
    this.module = module;
  }

  @Override
  public MetricsLogger get() {
    return provideMetricsLogger(module);
  }

  public static DependencyProvider_ProvideMetricsLoggerFactory create(DependencyProvider module) {
    return new DependencyProvider_ProvideMetricsLoggerFactory(module);
  }

  public static MetricsLogger provideMetricsLogger(DependencyProvider instance) {
    return Preconditions.checkNotNullFromProvides(instance.provideMetricsLogger());
  }
}

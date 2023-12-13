package com.android.systemui.dagger;

import android.os.Handler;
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
public final class DependencyProvider_ProvideTimeTickHandlerFactory implements Factory<Handler> {
  private final DependencyProvider module;

  public DependencyProvider_ProvideTimeTickHandlerFactory(DependencyProvider module) {
    this.module = module;
  }

  @Override
  public Handler get() {
    return provideTimeTickHandler(module);
  }

  public static DependencyProvider_ProvideTimeTickHandlerFactory create(DependencyProvider module) {
    return new DependencyProvider_ProvideTimeTickHandlerFactory(module);
  }

  public static Handler provideTimeTickHandler(DependencyProvider instance) {
    return Preconditions.checkNotNullFromProvides(instance.provideTimeTickHandler());
  }
}

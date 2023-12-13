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
public final class DependencyProvider_ProvideHandlerFactory implements Factory<Handler> {
  private final DependencyProvider module;

  public DependencyProvider_ProvideHandlerFactory(DependencyProvider module) {
    this.module = module;
  }

  @Override
  public Handler get() {
    return provideHandler(module);
  }

  public static DependencyProvider_ProvideHandlerFactory create(DependencyProvider module) {
    return new DependencyProvider_ProvideHandlerFactory(module);
  }

  public static Handler provideHandler(DependencyProvider instance) {
    return Preconditions.checkNotNullFromProvides(instance.provideHandler());
  }
}

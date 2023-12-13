package com.android.systemui.util.concurrency;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Optional;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class GlobalConcurrencyModule_ProvidesUncaughtExceptionHandlerFactory implements Factory<Optional<Thread.UncaughtExceptionHandler>> {
  @Override
  public Optional<Thread.UncaughtExceptionHandler> get() {
    return providesUncaughtExceptionHandler();
  }

  public static GlobalConcurrencyModule_ProvidesUncaughtExceptionHandlerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static Optional<Thread.UncaughtExceptionHandler> providesUncaughtExceptionHandler() {
    return Preconditions.checkNotNullFromProvides(GlobalConcurrencyModule.providesUncaughtExceptionHandler());
  }

  private static final class InstanceHolder {
    private static final GlobalConcurrencyModule_ProvidesUncaughtExceptionHandlerFactory INSTANCE = new GlobalConcurrencyModule_ProvidesUncaughtExceptionHandlerFactory();
  }
}

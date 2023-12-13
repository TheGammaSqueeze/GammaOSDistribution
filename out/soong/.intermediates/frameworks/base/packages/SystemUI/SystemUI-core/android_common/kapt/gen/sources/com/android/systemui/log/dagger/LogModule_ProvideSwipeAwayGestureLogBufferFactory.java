package com.android.systemui.log.dagger;

import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogBufferFactory;
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
public final class LogModule_ProvideSwipeAwayGestureLogBufferFactory implements Factory<LogBuffer> {
  private final Provider<LogBufferFactory> factoryProvider;

  public LogModule_ProvideSwipeAwayGestureLogBufferFactory(
      Provider<LogBufferFactory> factoryProvider) {
    this.factoryProvider = factoryProvider;
  }

  @Override
  public LogBuffer get() {
    return provideSwipeAwayGestureLogBuffer(factoryProvider.get());
  }

  public static LogModule_ProvideSwipeAwayGestureLogBufferFactory create(
      Provider<LogBufferFactory> factoryProvider) {
    return new LogModule_ProvideSwipeAwayGestureLogBufferFactory(factoryProvider);
  }

  public static LogBuffer provideSwipeAwayGestureLogBuffer(LogBufferFactory factory) {
    return Preconditions.checkNotNullFromProvides(LogModule.provideSwipeAwayGestureLogBuffer(factory));
  }
}

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
public final class LogModule_ProvideToastLogBufferFactory implements Factory<LogBuffer> {
  private final Provider<LogBufferFactory> factoryProvider;

  public LogModule_ProvideToastLogBufferFactory(Provider<LogBufferFactory> factoryProvider) {
    this.factoryProvider = factoryProvider;
  }

  @Override
  public LogBuffer get() {
    return provideToastLogBuffer(factoryProvider.get());
  }

  public static LogModule_ProvideToastLogBufferFactory create(
      Provider<LogBufferFactory> factoryProvider) {
    return new LogModule_ProvideToastLogBufferFactory(factoryProvider);
  }

  public static LogBuffer provideToastLogBuffer(LogBufferFactory factory) {
    return Preconditions.checkNotNullFromProvides(LogModule.provideToastLogBuffer(factory));
  }
}

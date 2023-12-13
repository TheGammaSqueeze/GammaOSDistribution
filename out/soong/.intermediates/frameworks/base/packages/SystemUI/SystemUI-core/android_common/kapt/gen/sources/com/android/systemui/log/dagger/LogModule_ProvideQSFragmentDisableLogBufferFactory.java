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
public final class LogModule_ProvideQSFragmentDisableLogBufferFactory implements Factory<LogBuffer> {
  private final Provider<LogBufferFactory> factoryProvider;

  public LogModule_ProvideQSFragmentDisableLogBufferFactory(
      Provider<LogBufferFactory> factoryProvider) {
    this.factoryProvider = factoryProvider;
  }

  @Override
  public LogBuffer get() {
    return provideQSFragmentDisableLogBuffer(factoryProvider.get());
  }

  public static LogModule_ProvideQSFragmentDisableLogBufferFactory create(
      Provider<LogBufferFactory> factoryProvider) {
    return new LogModule_ProvideQSFragmentDisableLogBufferFactory(factoryProvider);
  }

  public static LogBuffer provideQSFragmentDisableLogBuffer(LogBufferFactory factory) {
    return Preconditions.checkNotNullFromProvides(LogModule.provideQSFragmentDisableLogBuffer(factory));
  }
}

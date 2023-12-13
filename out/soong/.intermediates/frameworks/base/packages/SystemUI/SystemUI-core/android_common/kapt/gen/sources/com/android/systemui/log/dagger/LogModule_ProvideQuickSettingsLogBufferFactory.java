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
public final class LogModule_ProvideQuickSettingsLogBufferFactory implements Factory<LogBuffer> {
  private final Provider<LogBufferFactory> factoryProvider;

  public LogModule_ProvideQuickSettingsLogBufferFactory(
      Provider<LogBufferFactory> factoryProvider) {
    this.factoryProvider = factoryProvider;
  }

  @Override
  public LogBuffer get() {
    return provideQuickSettingsLogBuffer(factoryProvider.get());
  }

  public static LogModule_ProvideQuickSettingsLogBufferFactory create(
      Provider<LogBufferFactory> factoryProvider) {
    return new LogModule_ProvideQuickSettingsLogBufferFactory(factoryProvider);
  }

  public static LogBuffer provideQuickSettingsLogBuffer(LogBufferFactory factory) {
    return Preconditions.checkNotNullFromProvides(LogModule.provideQuickSettingsLogBuffer(factory));
  }
}

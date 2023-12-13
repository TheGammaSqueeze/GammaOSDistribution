package com.android.systemui.qs;

import com.android.systemui.log.LogBuffer;
import com.android.systemui.statusbar.DisableFlagsLogger;
import dagger.internal.Factory;
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
public final class QSFragmentDisableFlagsLogger_Factory implements Factory<QSFragmentDisableFlagsLogger> {
  private final Provider<LogBuffer> bufferProvider;

  private final Provider<DisableFlagsLogger> disableFlagsLoggerProvider;

  public QSFragmentDisableFlagsLogger_Factory(Provider<LogBuffer> bufferProvider,
      Provider<DisableFlagsLogger> disableFlagsLoggerProvider) {
    this.bufferProvider = bufferProvider;
    this.disableFlagsLoggerProvider = disableFlagsLoggerProvider;
  }

  @Override
  public QSFragmentDisableFlagsLogger get() {
    return newInstance(bufferProvider.get(), disableFlagsLoggerProvider.get());
  }

  public static QSFragmentDisableFlagsLogger_Factory create(Provider<LogBuffer> bufferProvider,
      Provider<DisableFlagsLogger> disableFlagsLoggerProvider) {
    return new QSFragmentDisableFlagsLogger_Factory(bufferProvider, disableFlagsLoggerProvider);
  }

  public static QSFragmentDisableFlagsLogger newInstance(LogBuffer buffer,
      DisableFlagsLogger disableFlagsLogger) {
    return new QSFragmentDisableFlagsLogger(buffer, disableFlagsLogger);
  }
}

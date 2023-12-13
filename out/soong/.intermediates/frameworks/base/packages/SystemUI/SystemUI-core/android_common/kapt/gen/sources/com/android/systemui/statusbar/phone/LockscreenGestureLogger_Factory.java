package com.android.systemui.statusbar.phone;

import com.android.internal.logging.MetricsLogger;
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
public final class LockscreenGestureLogger_Factory implements Factory<LockscreenGestureLogger> {
  private final Provider<MetricsLogger> metricsLoggerProvider;

  public LockscreenGestureLogger_Factory(Provider<MetricsLogger> metricsLoggerProvider) {
    this.metricsLoggerProvider = metricsLoggerProvider;
  }

  @Override
  public LockscreenGestureLogger get() {
    return newInstance(metricsLoggerProvider.get());
  }

  public static LockscreenGestureLogger_Factory create(
      Provider<MetricsLogger> metricsLoggerProvider) {
    return new LockscreenGestureLogger_Factory(metricsLoggerProvider);
  }

  public static LockscreenGestureLogger newInstance(MetricsLogger metricsLogger) {
    return new LockscreenGestureLogger(metricsLogger);
  }
}

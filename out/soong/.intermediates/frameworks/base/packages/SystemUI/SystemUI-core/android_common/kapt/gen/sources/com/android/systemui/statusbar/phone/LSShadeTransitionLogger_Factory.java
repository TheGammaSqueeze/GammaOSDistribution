package com.android.systemui.statusbar.phone;

import android.util.DisplayMetrics;
import com.android.systemui.log.LogBuffer;
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
public final class LSShadeTransitionLogger_Factory implements Factory<LSShadeTransitionLogger> {
  private final Provider<LogBuffer> bufferProvider;

  private final Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider;

  private final Provider<DisplayMetrics> displayMetricsProvider;

  public LSShadeTransitionLogger_Factory(Provider<LogBuffer> bufferProvider,
      Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider,
      Provider<DisplayMetrics> displayMetricsProvider) {
    this.bufferProvider = bufferProvider;
    this.lockscreenGestureLoggerProvider = lockscreenGestureLoggerProvider;
    this.displayMetricsProvider = displayMetricsProvider;
  }

  @Override
  public LSShadeTransitionLogger get() {
    return newInstance(bufferProvider.get(), lockscreenGestureLoggerProvider.get(), displayMetricsProvider.get());
  }

  public static LSShadeTransitionLogger_Factory create(Provider<LogBuffer> bufferProvider,
      Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider,
      Provider<DisplayMetrics> displayMetricsProvider) {
    return new LSShadeTransitionLogger_Factory(bufferProvider, lockscreenGestureLoggerProvider, displayMetricsProvider);
  }

  public static LSShadeTransitionLogger newInstance(LogBuffer buffer,
      LockscreenGestureLogger lockscreenGestureLogger, DisplayMetrics displayMetrics) {
    return new LSShadeTransitionLogger(buffer, lockscreenGestureLogger, displayMetrics);
  }
}

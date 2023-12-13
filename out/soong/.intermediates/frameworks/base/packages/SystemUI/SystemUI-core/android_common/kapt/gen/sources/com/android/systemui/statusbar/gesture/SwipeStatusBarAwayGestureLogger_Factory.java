package com.android.systemui.statusbar.gesture;

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
public final class SwipeStatusBarAwayGestureLogger_Factory implements Factory<SwipeStatusBarAwayGestureLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public SwipeStatusBarAwayGestureLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public SwipeStatusBarAwayGestureLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static SwipeStatusBarAwayGestureLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new SwipeStatusBarAwayGestureLogger_Factory(bufferProvider);
  }

  public static SwipeStatusBarAwayGestureLogger newInstance(LogBuffer buffer) {
    return new SwipeStatusBarAwayGestureLogger(buffer);
  }
}

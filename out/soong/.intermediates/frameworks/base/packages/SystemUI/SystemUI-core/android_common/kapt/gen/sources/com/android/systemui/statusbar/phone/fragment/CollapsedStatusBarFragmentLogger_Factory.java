package com.android.systemui.statusbar.phone.fragment;

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
public final class CollapsedStatusBarFragmentLogger_Factory implements Factory<CollapsedStatusBarFragmentLogger> {
  private final Provider<LogBuffer> bufferProvider;

  private final Provider<DisableFlagsLogger> disableFlagsLoggerProvider;

  public CollapsedStatusBarFragmentLogger_Factory(Provider<LogBuffer> bufferProvider,
      Provider<DisableFlagsLogger> disableFlagsLoggerProvider) {
    this.bufferProvider = bufferProvider;
    this.disableFlagsLoggerProvider = disableFlagsLoggerProvider;
  }

  @Override
  public CollapsedStatusBarFragmentLogger get() {
    return newInstance(bufferProvider.get(), disableFlagsLoggerProvider.get());
  }

  public static CollapsedStatusBarFragmentLogger_Factory create(Provider<LogBuffer> bufferProvider,
      Provider<DisableFlagsLogger> disableFlagsLoggerProvider) {
    return new CollapsedStatusBarFragmentLogger_Factory(bufferProvider, disableFlagsLoggerProvider);
  }

  public static CollapsedStatusBarFragmentLogger newInstance(LogBuffer buffer,
      DisableFlagsLogger disableFlagsLogger) {
    return new CollapsedStatusBarFragmentLogger(buffer, disableFlagsLogger);
  }
}

package com.android.systemui.log;

import com.android.systemui.dump.DumpManager;
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
public final class LogBufferFactory_Factory implements Factory<LogBufferFactory> {
  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<LogcatEchoTracker> logcatEchoTrackerProvider;

  public LogBufferFactory_Factory(Provider<DumpManager> dumpManagerProvider,
      Provider<LogcatEchoTracker> logcatEchoTrackerProvider) {
    this.dumpManagerProvider = dumpManagerProvider;
    this.logcatEchoTrackerProvider = logcatEchoTrackerProvider;
  }

  @Override
  public LogBufferFactory get() {
    return newInstance(dumpManagerProvider.get(), logcatEchoTrackerProvider.get());
  }

  public static LogBufferFactory_Factory create(Provider<DumpManager> dumpManagerProvider,
      Provider<LogcatEchoTracker> logcatEchoTrackerProvider) {
    return new LogBufferFactory_Factory(dumpManagerProvider, logcatEchoTrackerProvider);
  }

  public static LogBufferFactory newInstance(DumpManager dumpManager,
      LogcatEchoTracker logcatEchoTracker) {
    return new LogBufferFactory(dumpManager, logcatEchoTracker);
  }
}

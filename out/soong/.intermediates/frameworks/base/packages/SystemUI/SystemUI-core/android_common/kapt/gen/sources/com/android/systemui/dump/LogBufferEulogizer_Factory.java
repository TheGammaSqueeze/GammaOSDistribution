package com.android.systemui.dump;

import android.content.Context;
import com.android.systemui.util.io.Files;
import com.android.systemui.util.time.SystemClock;
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
public final class LogBufferEulogizer_Factory implements Factory<LogBufferEulogizer> {
  private final Provider<Context> contextProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<SystemClock> systemClockProvider;

  private final Provider<Files> filesProvider;

  public LogBufferEulogizer_Factory(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<SystemClock> systemClockProvider,
      Provider<Files> filesProvider) {
    this.contextProvider = contextProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.systemClockProvider = systemClockProvider;
    this.filesProvider = filesProvider;
  }

  @Override
  public LogBufferEulogizer get() {
    return newInstance(contextProvider.get(), dumpManagerProvider.get(), systemClockProvider.get(), filesProvider.get());
  }

  public static LogBufferEulogizer_Factory create(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<SystemClock> systemClockProvider,
      Provider<Files> filesProvider) {
    return new LogBufferEulogizer_Factory(contextProvider, dumpManagerProvider, systemClockProvider, filesProvider);
  }

  public static LogBufferEulogizer newInstance(Context context, DumpManager dumpManager,
      SystemClock systemClock, Files files) {
    return new LogBufferEulogizer(context, dumpManager, systemClock, files);
  }
}

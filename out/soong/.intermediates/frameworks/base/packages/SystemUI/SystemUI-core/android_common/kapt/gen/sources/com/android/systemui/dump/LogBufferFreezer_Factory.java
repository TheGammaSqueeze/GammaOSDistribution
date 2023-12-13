package com.android.systemui.dump;

import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class LogBufferFreezer_Factory implements Factory<LogBufferFreezer> {
  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<DelayableExecutor> executorProvider;

  public LogBufferFreezer_Factory(Provider<DumpManager> dumpManagerProvider,
      Provider<DelayableExecutor> executorProvider) {
    this.dumpManagerProvider = dumpManagerProvider;
    this.executorProvider = executorProvider;
  }

  @Override
  public LogBufferFreezer get() {
    return newInstance(dumpManagerProvider.get(), executorProvider.get());
  }

  public static LogBufferFreezer_Factory create(Provider<DumpManager> dumpManagerProvider,
      Provider<DelayableExecutor> executorProvider) {
    return new LogBufferFreezer_Factory(dumpManagerProvider, executorProvider);
  }

  public static LogBufferFreezer newInstance(DumpManager dumpManager, DelayableExecutor executor) {
    return new LogBufferFreezer(dumpManager, executor);
  }
}

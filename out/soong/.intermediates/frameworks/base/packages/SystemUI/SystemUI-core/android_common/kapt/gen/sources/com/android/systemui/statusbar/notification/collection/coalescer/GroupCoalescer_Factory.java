package com.android.systemui.statusbar.notification.collection.coalescer;

import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class GroupCoalescer_Factory implements Factory<GroupCoalescer> {
  private final Provider<DelayableExecutor> mainExecutorProvider;

  private final Provider<SystemClock> clockProvider;

  private final Provider<GroupCoalescerLogger> loggerProvider;

  public GroupCoalescer_Factory(Provider<DelayableExecutor> mainExecutorProvider,
      Provider<SystemClock> clockProvider, Provider<GroupCoalescerLogger> loggerProvider) {
    this.mainExecutorProvider = mainExecutorProvider;
    this.clockProvider = clockProvider;
    this.loggerProvider = loggerProvider;
  }

  @Override
  public GroupCoalescer get() {
    return newInstance(mainExecutorProvider.get(), clockProvider.get(), loggerProvider.get());
  }

  public static GroupCoalescer_Factory create(Provider<DelayableExecutor> mainExecutorProvider,
      Provider<SystemClock> clockProvider, Provider<GroupCoalescerLogger> loggerProvider) {
    return new GroupCoalescer_Factory(mainExecutorProvider, clockProvider, loggerProvider);
  }

  public static GroupCoalescer newInstance(DelayableExecutor mainExecutor, SystemClock clock,
      GroupCoalescerLogger logger) {
    return new GroupCoalescer(mainExecutor, clock, logger);
  }
}

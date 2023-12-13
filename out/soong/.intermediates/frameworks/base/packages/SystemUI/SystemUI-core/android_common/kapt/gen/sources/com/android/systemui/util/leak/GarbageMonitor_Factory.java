package com.android.systemui.util.leak;

import android.content.Context;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.concurrency.MessageRouter;
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
public final class GarbageMonitor_Factory implements Factory<GarbageMonitor> {
  private final Provider<Context> contextProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  private final Provider<MessageRouter> messageRouterProvider;

  private final Provider<LeakDetector> leakDetectorProvider;

  private final Provider<LeakReporter> leakReporterProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public GarbageMonitor_Factory(Provider<Context> contextProvider,
      Provider<DelayableExecutor> delayableExecutorProvider,
      Provider<MessageRouter> messageRouterProvider, Provider<LeakDetector> leakDetectorProvider,
      Provider<LeakReporter> leakReporterProvider, Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
    this.messageRouterProvider = messageRouterProvider;
    this.leakDetectorProvider = leakDetectorProvider;
    this.leakReporterProvider = leakReporterProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public GarbageMonitor get() {
    return newInstance(contextProvider.get(), delayableExecutorProvider.get(), messageRouterProvider.get(), leakDetectorProvider.get(), leakReporterProvider.get(), dumpManagerProvider.get());
  }

  public static GarbageMonitor_Factory create(Provider<Context> contextProvider,
      Provider<DelayableExecutor> delayableExecutorProvider,
      Provider<MessageRouter> messageRouterProvider, Provider<LeakDetector> leakDetectorProvider,
      Provider<LeakReporter> leakReporterProvider, Provider<DumpManager> dumpManagerProvider) {
    return new GarbageMonitor_Factory(contextProvider, delayableExecutorProvider, messageRouterProvider, leakDetectorProvider, leakReporterProvider, dumpManagerProvider);
  }

  public static GarbageMonitor newInstance(Context context, DelayableExecutor delayableExecutor,
      MessageRouter messageRouter, LeakDetector leakDetector, LeakReporter leakReporter,
      DumpManager dumpManager) {
    return new GarbageMonitor(context, delayableExecutor, messageRouter, leakDetector, leakReporter, dumpManager);
  }
}

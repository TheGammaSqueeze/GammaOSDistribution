package com.android.systemui.dagger;

import android.content.Context;
import android.os.Looper;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.broadcast.logging.BroadcastDispatcherLogger;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.settings.UserTracker;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.concurrent.Executor;
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
public final class DependencyProvider_ProvidesBroadcastDispatcherFactory implements Factory<BroadcastDispatcher> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<BroadcastDispatcherLogger> loggerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  public DependencyProvider_ProvidesBroadcastDispatcherFactory(DependencyProvider module,
      Provider<Context> contextProvider, Provider<Looper> backgroundLooperProvider,
      Provider<Executor> backgroundExecutorProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<BroadcastDispatcherLogger> loggerProvider,
      Provider<UserTracker> userTrackerProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.loggerProvider = loggerProvider;
    this.userTrackerProvider = userTrackerProvider;
  }

  @Override
  public BroadcastDispatcher get() {
    return providesBroadcastDispatcher(module, contextProvider.get(), backgroundLooperProvider.get(), backgroundExecutorProvider.get(), dumpManagerProvider.get(), loggerProvider.get(), userTrackerProvider.get());
  }

  public static DependencyProvider_ProvidesBroadcastDispatcherFactory create(
      DependencyProvider module, Provider<Context> contextProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Executor> backgroundExecutorProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<BroadcastDispatcherLogger> loggerProvider,
      Provider<UserTracker> userTrackerProvider) {
    return new DependencyProvider_ProvidesBroadcastDispatcherFactory(module, contextProvider, backgroundLooperProvider, backgroundExecutorProvider, dumpManagerProvider, loggerProvider, userTrackerProvider);
  }

  public static BroadcastDispatcher providesBroadcastDispatcher(DependencyProvider instance,
      Context context, Looper backgroundLooper, Executor backgroundExecutor,
      DumpManager dumpManager, BroadcastDispatcherLogger logger, UserTracker userTracker) {
    return Preconditions.checkNotNullFromProvides(instance.providesBroadcastDispatcher(context, backgroundLooper, backgroundExecutor, dumpManager, logger, userTracker));
  }
}

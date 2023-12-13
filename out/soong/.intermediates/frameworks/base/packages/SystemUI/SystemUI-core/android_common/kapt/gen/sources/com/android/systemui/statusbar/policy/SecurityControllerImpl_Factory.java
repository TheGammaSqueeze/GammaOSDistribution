package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.os.Handler;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import dagger.internal.Factory;
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
public final class SecurityControllerImpl_Factory implements Factory<SecurityControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> bgHandlerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public SecurityControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<Handler> bgHandlerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> bgExecutorProvider, Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.bgHandlerProvider = bgHandlerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public SecurityControllerImpl get() {
    return newInstance(contextProvider.get(), bgHandlerProvider.get(), broadcastDispatcherProvider.get(), bgExecutorProvider.get(), dumpManagerProvider.get());
  }

  public static SecurityControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<Handler> bgHandlerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> bgExecutorProvider, Provider<DumpManager> dumpManagerProvider) {
    return new SecurityControllerImpl_Factory(contextProvider, bgHandlerProvider, broadcastDispatcherProvider, bgExecutorProvider, dumpManagerProvider);
  }

  public static SecurityControllerImpl newInstance(Context context, Handler bgHandler,
      BroadcastDispatcher broadcastDispatcher, Executor bgExecutor, DumpManager dumpManager) {
    return new SecurityControllerImpl(context, bgHandler, broadcastDispatcher, bgExecutor, dumpManager);
  }
}

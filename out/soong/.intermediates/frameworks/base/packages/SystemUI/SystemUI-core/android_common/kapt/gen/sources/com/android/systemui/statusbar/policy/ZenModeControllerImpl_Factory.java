package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.os.Handler;
import com.android.systemui.broadcast.BroadcastDispatcher;
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
public final class ZenModeControllerImpl_Factory implements Factory<ZenModeControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public ZenModeControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<Handler> handlerProvider, Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.handlerProvider = handlerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public ZenModeControllerImpl get() {
    return newInstance(contextProvider.get(), handlerProvider.get(), broadcastDispatcherProvider.get(), dumpManagerProvider.get());
  }

  public static ZenModeControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<Handler> handlerProvider, Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new ZenModeControllerImpl_Factory(contextProvider, handlerProvider, broadcastDispatcherProvider, dumpManagerProvider);
  }

  public static ZenModeControllerImpl newInstance(Context context, Handler handler,
      BroadcastDispatcher broadcastDispatcher, DumpManager dumpManager) {
    return new ZenModeControllerImpl(context, handler, broadcastDispatcher, dumpManager);
  }
}

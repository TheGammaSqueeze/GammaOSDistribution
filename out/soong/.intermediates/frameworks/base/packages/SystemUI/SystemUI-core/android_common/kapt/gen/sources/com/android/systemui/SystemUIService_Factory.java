package com.android.systemui;

import android.os.Handler;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpHandler;
import com.android.systemui.dump.LogBufferFreezer;
import com.android.systemui.statusbar.policy.BatteryStateNotifier;
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
public final class SystemUIService_Factory implements Factory<SystemUIService> {
  private final Provider<Handler> mainHandlerProvider;

  private final Provider<DumpHandler> dumpHandlerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<LogBufferFreezer> logBufferFreezerProvider;

  private final Provider<BatteryStateNotifier> batteryStateNotifierProvider;

  public SystemUIService_Factory(Provider<Handler> mainHandlerProvider,
      Provider<DumpHandler> dumpHandlerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<LogBufferFreezer> logBufferFreezerProvider,
      Provider<BatteryStateNotifier> batteryStateNotifierProvider) {
    this.mainHandlerProvider = mainHandlerProvider;
    this.dumpHandlerProvider = dumpHandlerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.logBufferFreezerProvider = logBufferFreezerProvider;
    this.batteryStateNotifierProvider = batteryStateNotifierProvider;
  }

  @Override
  public SystemUIService get() {
    return newInstance(mainHandlerProvider.get(), dumpHandlerProvider.get(), broadcastDispatcherProvider.get(), logBufferFreezerProvider.get(), batteryStateNotifierProvider.get());
  }

  public static SystemUIService_Factory create(Provider<Handler> mainHandlerProvider,
      Provider<DumpHandler> dumpHandlerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<LogBufferFreezer> logBufferFreezerProvider,
      Provider<BatteryStateNotifier> batteryStateNotifierProvider) {
    return new SystemUIService_Factory(mainHandlerProvider, dumpHandlerProvider, broadcastDispatcherProvider, logBufferFreezerProvider, batteryStateNotifierProvider);
  }

  public static SystemUIService newInstance(Handler mainHandler, DumpHandler dumpHandler,
      BroadcastDispatcher broadcastDispatcher, LogBufferFreezer logBufferFreezer,
      BatteryStateNotifier batteryStateNotifier) {
    return new SystemUIService(mainHandler, dumpHandler, broadcastDispatcher, logBufferFreezer, batteryStateNotifier);
  }
}

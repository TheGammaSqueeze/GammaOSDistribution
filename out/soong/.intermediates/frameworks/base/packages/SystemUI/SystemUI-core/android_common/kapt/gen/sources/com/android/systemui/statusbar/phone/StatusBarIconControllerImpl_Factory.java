package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.CommandQueue;
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
public final class StatusBarIconControllerImpl_Factory implements Factory<StatusBarIconControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<DemoModeController> demoModeControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public StatusBarIconControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.demoModeControllerProvider = demoModeControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public StatusBarIconControllerImpl get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), demoModeControllerProvider.get(), dumpManagerProvider.get());
  }

  public static StatusBarIconControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new StatusBarIconControllerImpl_Factory(contextProvider, commandQueueProvider, demoModeControllerProvider, dumpManagerProvider);
  }

  public static StatusBarIconControllerImpl newInstance(Context context, CommandQueue commandQueue,
      DemoModeController demoModeController, DumpManager dumpManager) {
    return new StatusBarIconControllerImpl(context, commandQueue, demoModeController, dumpManager);
  }
}

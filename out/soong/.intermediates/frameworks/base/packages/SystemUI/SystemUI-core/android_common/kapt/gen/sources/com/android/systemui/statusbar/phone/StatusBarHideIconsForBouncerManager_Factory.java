package com.android.systemui.statusbar.phone;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.CommandQueue;
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
public final class StatusBarHideIconsForBouncerManager_Factory implements Factory<StatusBarHideIconsForBouncerManager> {
  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<DelayableExecutor> mainExecutorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public StatusBarHideIconsForBouncerManager_Factory(Provider<CommandQueue> commandQueueProvider,
      Provider<DelayableExecutor> mainExecutorProvider, Provider<DumpManager> dumpManagerProvider) {
    this.commandQueueProvider = commandQueueProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public StatusBarHideIconsForBouncerManager get() {
    return newInstance(commandQueueProvider.get(), mainExecutorProvider.get(), dumpManagerProvider.get());
  }

  public static StatusBarHideIconsForBouncerManager_Factory create(
      Provider<CommandQueue> commandQueueProvider, Provider<DelayableExecutor> mainExecutorProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new StatusBarHideIconsForBouncerManager_Factory(commandQueueProvider, mainExecutorProvider, dumpManagerProvider);
  }

  public static StatusBarHideIconsForBouncerManager newInstance(CommandQueue commandQueue,
      DelayableExecutor mainExecutor, DumpManager dumpManager) {
    return new StatusBarHideIconsForBouncerManager(commandQueue, mainExecutor, dumpManager);
  }
}

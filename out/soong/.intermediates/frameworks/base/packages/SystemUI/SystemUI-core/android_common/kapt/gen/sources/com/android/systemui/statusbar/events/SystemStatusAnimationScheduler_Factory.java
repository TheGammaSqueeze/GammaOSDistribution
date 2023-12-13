package com.android.systemui.statusbar.events;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.window.StatusBarWindowController;
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
public final class SystemStatusAnimationScheduler_Factory implements Factory<SystemStatusAnimationScheduler> {
  private final Provider<SystemEventCoordinator> coordinatorProvider;

  private final Provider<SystemEventChipAnimationController> chipAnimationControllerProvider;

  private final Provider<StatusBarWindowController> statusBarWindowControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<SystemClock> systemClockProvider;

  private final Provider<DelayableExecutor> executorProvider;

  public SystemStatusAnimationScheduler_Factory(
      Provider<SystemEventCoordinator> coordinatorProvider,
      Provider<SystemEventChipAnimationController> chipAnimationControllerProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<SystemClock> systemClockProvider,
      Provider<DelayableExecutor> executorProvider) {
    this.coordinatorProvider = coordinatorProvider;
    this.chipAnimationControllerProvider = chipAnimationControllerProvider;
    this.statusBarWindowControllerProvider = statusBarWindowControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.systemClockProvider = systemClockProvider;
    this.executorProvider = executorProvider;
  }

  @Override
  public SystemStatusAnimationScheduler get() {
    return newInstance(coordinatorProvider.get(), chipAnimationControllerProvider.get(), statusBarWindowControllerProvider.get(), dumpManagerProvider.get(), systemClockProvider.get(), executorProvider.get());
  }

  public static SystemStatusAnimationScheduler_Factory create(
      Provider<SystemEventCoordinator> coordinatorProvider,
      Provider<SystemEventChipAnimationController> chipAnimationControllerProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<SystemClock> systemClockProvider,
      Provider<DelayableExecutor> executorProvider) {
    return new SystemStatusAnimationScheduler_Factory(coordinatorProvider, chipAnimationControllerProvider, statusBarWindowControllerProvider, dumpManagerProvider, systemClockProvider, executorProvider);
  }

  public static SystemStatusAnimationScheduler newInstance(SystemEventCoordinator coordinator,
      SystemEventChipAnimationController chipAnimationController,
      StatusBarWindowController statusBarWindowController, DumpManager dumpManager,
      SystemClock systemClock, DelayableExecutor executor) {
    return new SystemStatusAnimationScheduler(coordinator, chipAnimationController, statusBarWindowController, dumpManager, systemClock, executor);
  }
}

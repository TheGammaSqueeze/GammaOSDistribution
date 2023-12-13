package com.android.wm.shell.dagger;

import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.TaskViewFactoryController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class WMShellBaseModule_ProvideTaskViewFactoryControllerFactory implements Factory<TaskViewFactoryController> {
  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<SyncTransactionQueue> syncQueueProvider;

  public WMShellBaseModule_ProvideTaskViewFactoryControllerFactory(
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<SyncTransactionQueue> syncQueueProvider) {
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.syncQueueProvider = syncQueueProvider;
  }

  @Override
  public TaskViewFactoryController get() {
    return provideTaskViewFactoryController(shellTaskOrganizerProvider.get(), mainExecutorProvider.get(), syncQueueProvider.get());
  }

  public static WMShellBaseModule_ProvideTaskViewFactoryControllerFactory create(
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<SyncTransactionQueue> syncQueueProvider) {
    return new WMShellBaseModule_ProvideTaskViewFactoryControllerFactory(shellTaskOrganizerProvider, mainExecutorProvider, syncQueueProvider);
  }

  public static TaskViewFactoryController provideTaskViewFactoryController(
      ShellTaskOrganizer shellTaskOrganizer, ShellExecutor mainExecutor,
      SyncTransactionQueue syncQueue) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideTaskViewFactoryController(shellTaskOrganizer, mainExecutor, syncQueue));
  }
}

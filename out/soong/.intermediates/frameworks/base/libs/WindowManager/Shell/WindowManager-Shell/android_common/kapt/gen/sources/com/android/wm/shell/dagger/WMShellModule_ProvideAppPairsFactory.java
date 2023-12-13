package com.android.wm.shell.dagger;

import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.apppairs.AppPairsController;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.DisplayImeController;
import com.android.wm.shell.common.DisplayInsetsController;
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
public final class WMShellModule_ProvideAppPairsFactory implements Factory<AppPairsController> {
  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<SyncTransactionQueue> syncQueueProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<DisplayImeController> displayImeControllerProvider;

  private final Provider<DisplayInsetsController> displayInsetsControllerProvider;

  public WMShellModule_ProvideAppPairsFactory(
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<DisplayImeController> displayImeControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider) {
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.syncQueueProvider = syncQueueProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.displayImeControllerProvider = displayImeControllerProvider;
    this.displayInsetsControllerProvider = displayInsetsControllerProvider;
  }

  @Override
  public AppPairsController get() {
    return provideAppPairs(shellTaskOrganizerProvider.get(), syncQueueProvider.get(), displayControllerProvider.get(), mainExecutorProvider.get(), displayImeControllerProvider.get(), displayInsetsControllerProvider.get());
  }

  public static WMShellModule_ProvideAppPairsFactory create(
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<DisplayImeController> displayImeControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider) {
    return new WMShellModule_ProvideAppPairsFactory(shellTaskOrganizerProvider, syncQueueProvider, displayControllerProvider, mainExecutorProvider, displayImeControllerProvider, displayInsetsControllerProvider);
  }

  public static AppPairsController provideAppPairs(ShellTaskOrganizer shellTaskOrganizer,
      SyncTransactionQueue syncQueue, DisplayController displayController,
      ShellExecutor mainExecutor, DisplayImeController displayImeController,
      DisplayInsetsController displayInsetsController) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.provideAppPairs(shellTaskOrganizer, syncQueue, displayController, mainExecutor, displayImeController, displayInsetsController));
  }
}

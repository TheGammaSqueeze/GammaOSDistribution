package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.DisplayImeController;
import com.android.wm.shell.common.DisplayInsetsController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.compatui.CompatUIController;
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
public final class WMShellBaseModule_ProvideCompatUIControllerFactory implements Factory<CompatUIController> {
  private final Provider<Context> contextProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<DisplayInsetsController> displayInsetsControllerProvider;

  private final Provider<DisplayImeController> imeControllerProvider;

  private final Provider<SyncTransactionQueue> syncQueueProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideCompatUIControllerFactory(Provider<Context> contextProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<DisplayImeController> imeControllerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.displayInsetsControllerProvider = displayInsetsControllerProvider;
    this.imeControllerProvider = imeControllerProvider;
    this.syncQueueProvider = syncQueueProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public CompatUIController get() {
    return provideCompatUIController(contextProvider.get(), displayControllerProvider.get(), displayInsetsControllerProvider.get(), imeControllerProvider.get(), syncQueueProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideCompatUIControllerFactory create(
      Provider<Context> contextProvider, Provider<DisplayController> displayControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<DisplayImeController> imeControllerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideCompatUIControllerFactory(contextProvider, displayControllerProvider, displayInsetsControllerProvider, imeControllerProvider, syncQueueProvider, mainExecutorProvider);
  }

  public static CompatUIController provideCompatUIController(Context context,
      DisplayController displayController, DisplayInsetsController displayInsetsController,
      DisplayImeController imeController, SyncTransactionQueue syncQueue,
      ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideCompatUIController(context, displayController, displayInsetsController, imeController, syncQueue, mainExecutor));
  }
}

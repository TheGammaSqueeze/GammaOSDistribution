package com.android.wm.shell.dagger;

import android.view.IWindowManager;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.DisplayImeController;
import com.android.wm.shell.common.DisplayInsetsController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.TransactionPool;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Optional;
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
public final class WMShellBaseModule_ProvideDisplayImeControllerFactory implements Factory<DisplayImeController> {
  private final Provider<Optional<DisplayImeController>> overrideDisplayImeControllerProvider;

  private final Provider<IWindowManager> wmServiceProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<DisplayInsetsController> displayInsetsControllerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<TransactionPool> transactionPoolProvider;

  public WMShellBaseModule_ProvideDisplayImeControllerFactory(
      Provider<Optional<DisplayImeController>> overrideDisplayImeControllerProvider,
      Provider<IWindowManager> wmServiceProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<TransactionPool> transactionPoolProvider) {
    this.overrideDisplayImeControllerProvider = overrideDisplayImeControllerProvider;
    this.wmServiceProvider = wmServiceProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.displayInsetsControllerProvider = displayInsetsControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.transactionPoolProvider = transactionPoolProvider;
  }

  @Override
  public DisplayImeController get() {
    return provideDisplayImeController(overrideDisplayImeControllerProvider.get(), wmServiceProvider.get(), displayControllerProvider.get(), displayInsetsControllerProvider.get(), mainExecutorProvider.get(), transactionPoolProvider.get());
  }

  public static WMShellBaseModule_ProvideDisplayImeControllerFactory create(
      Provider<Optional<DisplayImeController>> overrideDisplayImeControllerProvider,
      Provider<IWindowManager> wmServiceProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<TransactionPool> transactionPoolProvider) {
    return new WMShellBaseModule_ProvideDisplayImeControllerFactory(overrideDisplayImeControllerProvider, wmServiceProvider, displayControllerProvider, displayInsetsControllerProvider, mainExecutorProvider, transactionPoolProvider);
  }

  public static DisplayImeController provideDisplayImeController(
      Optional<DisplayImeController> overrideDisplayImeController, IWindowManager wmService,
      DisplayController displayController, DisplayInsetsController displayInsetsController,
      ShellExecutor mainExecutor, TransactionPool transactionPool) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideDisplayImeController(overrideDisplayImeController, wmService, displayController, displayInsetsController, mainExecutor, transactionPool));
  }
}

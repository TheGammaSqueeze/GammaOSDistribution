package com.android.wm.shell.dagger;

import android.view.IWindowManager;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.DisplayInsetsController;
import com.android.wm.shell.common.ShellExecutor;
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
public final class WMShellBaseModule_ProvideDisplayInsetsControllerFactory implements Factory<DisplayInsetsController> {
  private final Provider<IWindowManager> wmServiceProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideDisplayInsetsControllerFactory(
      Provider<IWindowManager> wmServiceProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.wmServiceProvider = wmServiceProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public DisplayInsetsController get() {
    return provideDisplayInsetsController(wmServiceProvider.get(), displayControllerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideDisplayInsetsControllerFactory create(
      Provider<IWindowManager> wmServiceProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideDisplayInsetsControllerFactory(wmServiceProvider, displayControllerProvider, mainExecutorProvider);
  }

  public static DisplayInsetsController provideDisplayInsetsController(IWindowManager wmService,
      DisplayController displayController, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideDisplayInsetsController(wmService, displayController, mainExecutor));
  }
}

package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.hidedisplaycutout.HideDisplayCutoutController;
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
public final class WMShellBaseModule_ProvideHideDisplayCutoutControllerFactory implements Factory<Optional<HideDisplayCutoutController>> {
  private final Provider<Context> contextProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideHideDisplayCutoutControllerFactory(
      Provider<Context> contextProvider, Provider<DisplayController> displayControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public Optional<HideDisplayCutoutController> get() {
    return provideHideDisplayCutoutController(contextProvider.get(), displayControllerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideHideDisplayCutoutControllerFactory create(
      Provider<Context> contextProvider, Provider<DisplayController> displayControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideHideDisplayCutoutControllerFactory(contextProvider, displayControllerProvider, mainExecutorProvider);
  }

  public static Optional<HideDisplayCutoutController> provideHideDisplayCutoutController(
      Context context, DisplayController displayController, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideHideDisplayCutoutController(context, displayController, mainExecutor));
  }
}

package com.android.wm.shell.dagger;

import android.content.Context;
import android.view.IWindowManager;
import com.android.wm.shell.common.DisplayController;
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
public final class WMShellBaseModule_ProvideDisplayControllerFactory implements Factory<DisplayController> {
  private final Provider<Context> contextProvider;

  private final Provider<IWindowManager> wmServiceProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideDisplayControllerFactory(Provider<Context> contextProvider,
      Provider<IWindowManager> wmServiceProvider, Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.wmServiceProvider = wmServiceProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public DisplayController get() {
    return provideDisplayController(contextProvider.get(), wmServiceProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideDisplayControllerFactory create(
      Provider<Context> contextProvider, Provider<IWindowManager> wmServiceProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideDisplayControllerFactory(contextProvider, wmServiceProvider, mainExecutorProvider);
  }

  public static DisplayController provideDisplayController(Context context,
      IWindowManager wmService, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideDisplayController(context, wmService, mainExecutor));
  }
}

package com.android.wm.shell.dagger;

import com.android.wm.shell.WindowManagerShellWrapper;
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
public final class WMShellBaseModule_ProvideWindowManagerShellWrapperFactory implements Factory<WindowManagerShellWrapper> {
  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideWindowManagerShellWrapperFactory(
      Provider<ShellExecutor> mainExecutorProvider) {
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public WindowManagerShellWrapper get() {
    return provideWindowManagerShellWrapper(mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideWindowManagerShellWrapperFactory create(
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideWindowManagerShellWrapperFactory(mainExecutorProvider);
  }

  public static WindowManagerShellWrapper provideWindowManagerShellWrapper(
      ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideWindowManagerShellWrapper(mainExecutor));
  }
}

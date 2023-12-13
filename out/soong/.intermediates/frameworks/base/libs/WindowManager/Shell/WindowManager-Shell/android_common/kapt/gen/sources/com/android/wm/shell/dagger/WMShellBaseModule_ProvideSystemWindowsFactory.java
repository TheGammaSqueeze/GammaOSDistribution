package com.android.wm.shell.dagger;

import android.view.IWindowManager;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.SystemWindows;
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
public final class WMShellBaseModule_ProvideSystemWindowsFactory implements Factory<SystemWindows> {
  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<IWindowManager> wmServiceProvider;

  public WMShellBaseModule_ProvideSystemWindowsFactory(
      Provider<DisplayController> displayControllerProvider,
      Provider<IWindowManager> wmServiceProvider) {
    this.displayControllerProvider = displayControllerProvider;
    this.wmServiceProvider = wmServiceProvider;
  }

  @Override
  public SystemWindows get() {
    return provideSystemWindows(displayControllerProvider.get(), wmServiceProvider.get());
  }

  public static WMShellBaseModule_ProvideSystemWindowsFactory create(
      Provider<DisplayController> displayControllerProvider,
      Provider<IWindowManager> wmServiceProvider) {
    return new WMShellBaseModule_ProvideSystemWindowsFactory(displayControllerProvider, wmServiceProvider);
  }

  public static SystemWindows provideSystemWindows(DisplayController displayController,
      IWindowManager wmService) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideSystemWindows(displayController, wmService));
  }
}

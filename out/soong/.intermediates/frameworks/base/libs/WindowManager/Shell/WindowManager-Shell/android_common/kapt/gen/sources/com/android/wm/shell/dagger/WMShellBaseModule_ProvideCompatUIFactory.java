package com.android.wm.shell.dagger;

import com.android.wm.shell.compatui.CompatUI;
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
public final class WMShellBaseModule_ProvideCompatUIFactory implements Factory<CompatUI> {
  private final Provider<CompatUIController> compatUIControllerProvider;

  public WMShellBaseModule_ProvideCompatUIFactory(
      Provider<CompatUIController> compatUIControllerProvider) {
    this.compatUIControllerProvider = compatUIControllerProvider;
  }

  @Override
  public CompatUI get() {
    return provideCompatUI(compatUIControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideCompatUIFactory create(
      Provider<CompatUIController> compatUIControllerProvider) {
    return new WMShellBaseModule_ProvideCompatUIFactory(compatUIControllerProvider);
  }

  public static CompatUI provideCompatUI(CompatUIController compatUIController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideCompatUI(compatUIController));
  }
}

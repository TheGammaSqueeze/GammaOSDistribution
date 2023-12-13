package com.android.wm.shell.dagger;

import com.android.wm.shell.onehanded.OneHanded;
import com.android.wm.shell.onehanded.OneHandedController;
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
public final class WMShellBaseModule_ProvideOneHandedFactory implements Factory<Optional<OneHanded>> {
  private final Provider<Optional<OneHandedController>> oneHandedControllerProvider;

  public WMShellBaseModule_ProvideOneHandedFactory(
      Provider<Optional<OneHandedController>> oneHandedControllerProvider) {
    this.oneHandedControllerProvider = oneHandedControllerProvider;
  }

  @Override
  public Optional<OneHanded> get() {
    return provideOneHanded(oneHandedControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideOneHandedFactory create(
      Provider<Optional<OneHandedController>> oneHandedControllerProvider) {
    return new WMShellBaseModule_ProvideOneHandedFactory(oneHandedControllerProvider);
  }

  public static Optional<OneHanded> provideOneHanded(
      Optional<OneHandedController> oneHandedController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideOneHanded(oneHandedController));
  }
}

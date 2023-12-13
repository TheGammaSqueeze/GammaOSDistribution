package com.android.wm.shell.dagger;

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
public final class WMShellBaseModule_ProvidesOneHandedControllerFactory implements Factory<Optional<OneHandedController>> {
  private final Provider<Optional<OneHandedController>> oneHandedControllerProvider;

  public WMShellBaseModule_ProvidesOneHandedControllerFactory(
      Provider<Optional<OneHandedController>> oneHandedControllerProvider) {
    this.oneHandedControllerProvider = oneHandedControllerProvider;
  }

  @Override
  public Optional<OneHandedController> get() {
    return providesOneHandedController(oneHandedControllerProvider.get());
  }

  public static WMShellBaseModule_ProvidesOneHandedControllerFactory create(
      Provider<Optional<OneHandedController>> oneHandedControllerProvider) {
    return new WMShellBaseModule_ProvidesOneHandedControllerFactory(oneHandedControllerProvider);
  }

  public static Optional<OneHandedController> providesOneHandedController(
      Optional<OneHandedController> oneHandedController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.providesOneHandedController(oneHandedController));
  }
}

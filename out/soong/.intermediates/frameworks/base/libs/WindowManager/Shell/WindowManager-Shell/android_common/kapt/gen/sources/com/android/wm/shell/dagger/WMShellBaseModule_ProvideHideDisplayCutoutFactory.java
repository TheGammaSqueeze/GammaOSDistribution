package com.android.wm.shell.dagger;

import com.android.wm.shell.hidedisplaycutout.HideDisplayCutout;
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
public final class WMShellBaseModule_ProvideHideDisplayCutoutFactory implements Factory<Optional<HideDisplayCutout>> {
  private final Provider<Optional<HideDisplayCutoutController>> hideDisplayCutoutControllerProvider;

  public WMShellBaseModule_ProvideHideDisplayCutoutFactory(
      Provider<Optional<HideDisplayCutoutController>> hideDisplayCutoutControllerProvider) {
    this.hideDisplayCutoutControllerProvider = hideDisplayCutoutControllerProvider;
  }

  @Override
  public Optional<HideDisplayCutout> get() {
    return provideHideDisplayCutout(hideDisplayCutoutControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideHideDisplayCutoutFactory create(
      Provider<Optional<HideDisplayCutoutController>> hideDisplayCutoutControllerProvider) {
    return new WMShellBaseModule_ProvideHideDisplayCutoutFactory(hideDisplayCutoutControllerProvider);
  }

  public static Optional<HideDisplayCutout> provideHideDisplayCutout(
      Optional<HideDisplayCutoutController> hideDisplayCutoutController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideHideDisplayCutout(hideDisplayCutoutController));
  }
}

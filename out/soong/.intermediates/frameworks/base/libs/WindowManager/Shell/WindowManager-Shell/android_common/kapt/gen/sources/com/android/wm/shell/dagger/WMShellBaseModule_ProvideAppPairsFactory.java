package com.android.wm.shell.dagger;

import com.android.wm.shell.apppairs.AppPairs;
import com.android.wm.shell.apppairs.AppPairsController;
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
public final class WMShellBaseModule_ProvideAppPairsFactory implements Factory<Optional<AppPairs>> {
  private final Provider<Optional<AppPairsController>> appPairsControllerProvider;

  public WMShellBaseModule_ProvideAppPairsFactory(
      Provider<Optional<AppPairsController>> appPairsControllerProvider) {
    this.appPairsControllerProvider = appPairsControllerProvider;
  }

  @Override
  public Optional<AppPairs> get() {
    return provideAppPairs(appPairsControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideAppPairsFactory create(
      Provider<Optional<AppPairsController>> appPairsControllerProvider) {
    return new WMShellBaseModule_ProvideAppPairsFactory(appPairsControllerProvider);
  }

  public static Optional<AppPairs> provideAppPairs(
      Optional<AppPairsController> appPairsController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideAppPairs(appPairsController));
  }
}

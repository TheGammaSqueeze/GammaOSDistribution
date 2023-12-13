package com.android.wm.shell.dagger;

import com.android.wm.shell.fullscreen.FullscreenUnfoldController;
import com.android.wm.shell.unfold.ShellUnfoldProgressProvider;
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
public final class WMShellBaseModule_ProvideFullscreenUnfoldControllerFactory implements Factory<Optional<FullscreenUnfoldController>> {
  private final Provider<Optional<FullscreenUnfoldController>> fullscreenUnfoldControllerProvider;

  private final Provider<Optional<ShellUnfoldProgressProvider>> progressProvider;

  public WMShellBaseModule_ProvideFullscreenUnfoldControllerFactory(
      Provider<Optional<FullscreenUnfoldController>> fullscreenUnfoldControllerProvider,
      Provider<Optional<ShellUnfoldProgressProvider>> progressProvider) {
    this.fullscreenUnfoldControllerProvider = fullscreenUnfoldControllerProvider;
    this.progressProvider = progressProvider;
  }

  @Override
  public Optional<FullscreenUnfoldController> get() {
    return provideFullscreenUnfoldController(fullscreenUnfoldControllerProvider.get(), progressProvider.get());
  }

  public static WMShellBaseModule_ProvideFullscreenUnfoldControllerFactory create(
      Provider<Optional<FullscreenUnfoldController>> fullscreenUnfoldControllerProvider,
      Provider<Optional<ShellUnfoldProgressProvider>> progressProvider) {
    return new WMShellBaseModule_ProvideFullscreenUnfoldControllerFactory(fullscreenUnfoldControllerProvider, progressProvider);
  }

  public static Optional<FullscreenUnfoldController> provideFullscreenUnfoldController(
      Optional<FullscreenUnfoldController> fullscreenUnfoldController,
      Optional<ShellUnfoldProgressProvider> progressProvider) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideFullscreenUnfoldController(fullscreenUnfoldController, progressProvider));
  }
}

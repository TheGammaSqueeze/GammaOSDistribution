package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.common.DisplayInsetsController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.fullscreen.FullscreenUnfoldController;
import com.android.wm.shell.unfold.ShellUnfoldProgressProvider;
import com.android.wm.shell.unfold.UnfoldBackgroundController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class WMShellModule_ProvideFullscreenUnfoldControllerFactory implements Factory<FullscreenUnfoldController> {
  private final Provider<Context> contextProvider;

  private final Provider<Optional<ShellUnfoldProgressProvider>> progressProvider;

  private final Provider<UnfoldBackgroundController> unfoldBackgroundControllerProvider;

  private final Provider<DisplayInsetsController> displayInsetsControllerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellModule_ProvideFullscreenUnfoldControllerFactory(Provider<Context> contextProvider,
      Provider<Optional<ShellUnfoldProgressProvider>> progressProvider,
      Provider<UnfoldBackgroundController> unfoldBackgroundControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.progressProvider = progressProvider;
    this.unfoldBackgroundControllerProvider = unfoldBackgroundControllerProvider;
    this.displayInsetsControllerProvider = displayInsetsControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public FullscreenUnfoldController get() {
    return provideFullscreenUnfoldController(contextProvider.get(), progressProvider.get(), DoubleCheck.lazy(unfoldBackgroundControllerProvider), displayInsetsControllerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellModule_ProvideFullscreenUnfoldControllerFactory create(
      Provider<Context> contextProvider,
      Provider<Optional<ShellUnfoldProgressProvider>> progressProvider,
      Provider<UnfoldBackgroundController> unfoldBackgroundControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellModule_ProvideFullscreenUnfoldControllerFactory(contextProvider, progressProvider, unfoldBackgroundControllerProvider, displayInsetsControllerProvider, mainExecutorProvider);
  }

  public static FullscreenUnfoldController provideFullscreenUnfoldController(Context context,
      Optional<ShellUnfoldProgressProvider> progressProvider,
      Lazy<UnfoldBackgroundController> unfoldBackgroundController,
      DisplayInsetsController displayInsetsController, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.provideFullscreenUnfoldController(context, progressProvider, unfoldBackgroundController, displayInsetsController, mainExecutor));
  }
}

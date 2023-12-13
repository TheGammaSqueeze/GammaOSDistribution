package com.android.wm.shell.dagger;

import android.animation.AnimationHandler;
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
public final class WMShellConcurrencyModule_ProvideShellMainExecutorSfVsyncAnimationHandlerFactory implements Factory<AnimationHandler> {
  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellConcurrencyModule_ProvideShellMainExecutorSfVsyncAnimationHandlerFactory(
      Provider<ShellExecutor> mainExecutorProvider) {
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public AnimationHandler get() {
    return provideShellMainExecutorSfVsyncAnimationHandler(mainExecutorProvider.get());
  }

  public static WMShellConcurrencyModule_ProvideShellMainExecutorSfVsyncAnimationHandlerFactory create(
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellConcurrencyModule_ProvideShellMainExecutorSfVsyncAnimationHandlerFactory(mainExecutorProvider);
  }

  public static AnimationHandler provideShellMainExecutorSfVsyncAnimationHandler(
      ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellConcurrencyModule.provideShellMainExecutorSfVsyncAnimationHandler(mainExecutor));
  }
}

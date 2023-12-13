package com.android.wm.shell.dagger;

import com.android.wm.shell.pip.PipAnimationController;
import com.android.wm.shell.pip.PipSurfaceTransactionHelper;
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
public final class WMShellModule_ProvidePipAnimationControllerFactory implements Factory<PipAnimationController> {
  private final Provider<PipSurfaceTransactionHelper> pipSurfaceTransactionHelperProvider;

  public WMShellModule_ProvidePipAnimationControllerFactory(
      Provider<PipSurfaceTransactionHelper> pipSurfaceTransactionHelperProvider) {
    this.pipSurfaceTransactionHelperProvider = pipSurfaceTransactionHelperProvider;
  }

  @Override
  public PipAnimationController get() {
    return providePipAnimationController(pipSurfaceTransactionHelperProvider.get());
  }

  public static WMShellModule_ProvidePipAnimationControllerFactory create(
      Provider<PipSurfaceTransactionHelper> pipSurfaceTransactionHelperProvider) {
    return new WMShellModule_ProvidePipAnimationControllerFactory(pipSurfaceTransactionHelperProvider);
  }

  public static PipAnimationController providePipAnimationController(
      PipSurfaceTransactionHelper pipSurfaceTransactionHelper) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.providePipAnimationController(pipSurfaceTransactionHelper));
  }
}

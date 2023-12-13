package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.common.FloatingContentCoordinator;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipSnapAlgorithm;
import com.android.wm.shell.pip.PipTaskOrganizer;
import com.android.wm.shell.pip.PipTransitionController;
import com.android.wm.shell.pip.phone.PhonePipMenuController;
import com.android.wm.shell.pip.phone.PipMotionHelper;
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
public final class WMShellModule_ProvidePipMotionHelperFactory implements Factory<PipMotionHelper> {
  private final Provider<Context> contextProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<PipTaskOrganizer> pipTaskOrganizerProvider;

  private final Provider<PhonePipMenuController> menuControllerProvider;

  private final Provider<PipSnapAlgorithm> pipSnapAlgorithmProvider;

  private final Provider<PipTransitionController> pipTransitionControllerProvider;

  private final Provider<FloatingContentCoordinator> floatingContentCoordinatorProvider;

  public WMShellModule_ProvidePipMotionHelperFactory(Provider<Context> contextProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipTaskOrganizer> pipTaskOrganizerProvider,
      Provider<PhonePipMenuController> menuControllerProvider,
      Provider<PipSnapAlgorithm> pipSnapAlgorithmProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<FloatingContentCoordinator> floatingContentCoordinatorProvider) {
    this.contextProvider = contextProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipTaskOrganizerProvider = pipTaskOrganizerProvider;
    this.menuControllerProvider = menuControllerProvider;
    this.pipSnapAlgorithmProvider = pipSnapAlgorithmProvider;
    this.pipTransitionControllerProvider = pipTransitionControllerProvider;
    this.floatingContentCoordinatorProvider = floatingContentCoordinatorProvider;
  }

  @Override
  public PipMotionHelper get() {
    return providePipMotionHelper(contextProvider.get(), pipBoundsStateProvider.get(), pipTaskOrganizerProvider.get(), menuControllerProvider.get(), pipSnapAlgorithmProvider.get(), pipTransitionControllerProvider.get(), floatingContentCoordinatorProvider.get());
  }

  public static WMShellModule_ProvidePipMotionHelperFactory create(
      Provider<Context> contextProvider, Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipTaskOrganizer> pipTaskOrganizerProvider,
      Provider<PhonePipMenuController> menuControllerProvider,
      Provider<PipSnapAlgorithm> pipSnapAlgorithmProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<FloatingContentCoordinator> floatingContentCoordinatorProvider) {
    return new WMShellModule_ProvidePipMotionHelperFactory(contextProvider, pipBoundsStateProvider, pipTaskOrganizerProvider, menuControllerProvider, pipSnapAlgorithmProvider, pipTransitionControllerProvider, floatingContentCoordinatorProvider);
  }

  public static PipMotionHelper providePipMotionHelper(Context context,
      PipBoundsState pipBoundsState, PipTaskOrganizer pipTaskOrganizer,
      PhonePipMenuController menuController, PipSnapAlgorithm pipSnapAlgorithm,
      PipTransitionController pipTransitionController,
      FloatingContentCoordinator floatingContentCoordinator) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.providePipMotionHelper(context, pipBoundsState, pipTaskOrganizer, menuController, pipSnapAlgorithm, pipTransitionController, floatingContentCoordinator));
  }
}

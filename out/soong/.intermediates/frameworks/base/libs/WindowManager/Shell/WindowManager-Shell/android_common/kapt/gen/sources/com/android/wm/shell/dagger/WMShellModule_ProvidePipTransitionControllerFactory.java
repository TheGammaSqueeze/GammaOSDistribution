package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.pip.PipAnimationController;
import com.android.wm.shell.pip.PipBoundsAlgorithm;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipTransitionController;
import com.android.wm.shell.pip.PipTransitionState;
import com.android.wm.shell.pip.phone.PhonePipMenuController;
import com.android.wm.shell.transition.Transitions;
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
public final class WMShellModule_ProvidePipTransitionControllerFactory implements Factory<PipTransitionController> {
  private final Provider<Context> contextProvider;

  private final Provider<Transitions> transitionsProvider;

  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<PipAnimationController> pipAnimationControllerProvider;

  private final Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<PipTransitionState> pipTransitionStateProvider;

  private final Provider<PhonePipMenuController> pipMenuControllerProvider;

  public WMShellModule_ProvidePipTransitionControllerFactory(Provider<Context> contextProvider,
      Provider<Transitions> transitionsProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<PipAnimationController> pipAnimationControllerProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipTransitionState> pipTransitionStateProvider,
      Provider<PhonePipMenuController> pipMenuControllerProvider) {
    this.contextProvider = contextProvider;
    this.transitionsProvider = transitionsProvider;
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.pipAnimationControllerProvider = pipAnimationControllerProvider;
    this.pipBoundsAlgorithmProvider = pipBoundsAlgorithmProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipTransitionStateProvider = pipTransitionStateProvider;
    this.pipMenuControllerProvider = pipMenuControllerProvider;
  }

  @Override
  public PipTransitionController get() {
    return providePipTransitionController(contextProvider.get(), transitionsProvider.get(), shellTaskOrganizerProvider.get(), pipAnimationControllerProvider.get(), pipBoundsAlgorithmProvider.get(), pipBoundsStateProvider.get(), pipTransitionStateProvider.get(), pipMenuControllerProvider.get());
  }

  public static WMShellModule_ProvidePipTransitionControllerFactory create(
      Provider<Context> contextProvider, Provider<Transitions> transitionsProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<PipAnimationController> pipAnimationControllerProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipTransitionState> pipTransitionStateProvider,
      Provider<PhonePipMenuController> pipMenuControllerProvider) {
    return new WMShellModule_ProvidePipTransitionControllerFactory(contextProvider, transitionsProvider, shellTaskOrganizerProvider, pipAnimationControllerProvider, pipBoundsAlgorithmProvider, pipBoundsStateProvider, pipTransitionStateProvider, pipMenuControllerProvider);
  }

  public static PipTransitionController providePipTransitionController(Context context,
      Transitions transitions, ShellTaskOrganizer shellTaskOrganizer,
      PipAnimationController pipAnimationController, PipBoundsAlgorithm pipBoundsAlgorithm,
      PipBoundsState pipBoundsState, PipTransitionState pipTransitionState,
      PhonePipMenuController pipMenuController) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.providePipTransitionController(context, transitions, shellTaskOrganizer, pipAnimationController, pipBoundsAlgorithm, pipBoundsState, pipTransitionState, pipMenuController));
  }
}

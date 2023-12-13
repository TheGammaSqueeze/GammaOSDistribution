package com.android.wm.shell.dagger;

import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.pip.PipAnimationController;
import com.android.wm.shell.pip.PipBoundsAlgorithm;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipTransitionController;
import com.android.wm.shell.pip.tv.TvPipMenuController;
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
public final class TvPipModule_ProvideTvPipTransitionFactory implements Factory<PipTransitionController> {
  private final Provider<Transitions> transitionsProvider;

  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<PipAnimationController> pipAnimationControllerProvider;

  private final Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<TvPipMenuController> pipMenuControllerProvider;

  public TvPipModule_ProvideTvPipTransitionFactory(Provider<Transitions> transitionsProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<PipAnimationController> pipAnimationControllerProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<TvPipMenuController> pipMenuControllerProvider) {
    this.transitionsProvider = transitionsProvider;
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.pipAnimationControllerProvider = pipAnimationControllerProvider;
    this.pipBoundsAlgorithmProvider = pipBoundsAlgorithmProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipMenuControllerProvider = pipMenuControllerProvider;
  }

  @Override
  public PipTransitionController get() {
    return provideTvPipTransition(transitionsProvider.get(), shellTaskOrganizerProvider.get(), pipAnimationControllerProvider.get(), pipBoundsAlgorithmProvider.get(), pipBoundsStateProvider.get(), pipMenuControllerProvider.get());
  }

  public static TvPipModule_ProvideTvPipTransitionFactory create(
      Provider<Transitions> transitionsProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<PipAnimationController> pipAnimationControllerProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<TvPipMenuController> pipMenuControllerProvider) {
    return new TvPipModule_ProvideTvPipTransitionFactory(transitionsProvider, shellTaskOrganizerProvider, pipAnimationControllerProvider, pipBoundsAlgorithmProvider, pipBoundsStateProvider, pipMenuControllerProvider);
  }

  public static PipTransitionController provideTvPipTransition(Transitions transitions,
      ShellTaskOrganizer shellTaskOrganizer, PipAnimationController pipAnimationController,
      PipBoundsAlgorithm pipBoundsAlgorithm, PipBoundsState pipBoundsState,
      TvPipMenuController pipMenuController) {
    return Preconditions.checkNotNullFromProvides(TvPipModule.provideTvPipTransition(transitions, shellTaskOrganizer, pipAnimationController, pipBoundsAlgorithm, pipBoundsState, pipMenuController));
  }
}

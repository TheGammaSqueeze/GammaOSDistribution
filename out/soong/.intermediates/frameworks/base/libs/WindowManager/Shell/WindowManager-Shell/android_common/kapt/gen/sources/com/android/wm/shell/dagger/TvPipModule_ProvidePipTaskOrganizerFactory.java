package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreenController;
import com.android.wm.shell.pip.PipAnimationController;
import com.android.wm.shell.pip.PipBoundsAlgorithm;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipSurfaceTransactionHelper;
import com.android.wm.shell.pip.PipTaskOrganizer;
import com.android.wm.shell.pip.PipTransitionController;
import com.android.wm.shell.pip.PipTransitionState;
import com.android.wm.shell.pip.PipUiEventLogger;
import com.android.wm.shell.pip.tv.TvPipMenuController;
import com.android.wm.shell.splitscreen.SplitScreenController;
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
public final class TvPipModule_ProvidePipTaskOrganizerFactory implements Factory<PipTaskOrganizer> {
  private final Provider<Context> contextProvider;

  private final Provider<TvPipMenuController> tvPipMenuControllerProvider;

  private final Provider<SyncTransactionQueue> syncTransactionQueueProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<PipTransitionState> pipTransitionStateProvider;

  private final Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider;

  private final Provider<PipAnimationController> pipAnimationControllerProvider;

  private final Provider<PipTransitionController> pipTransitionControllerProvider;

  private final Provider<PipSurfaceTransactionHelper> pipSurfaceTransactionHelperProvider;

  private final Provider<Optional<LegacySplitScreenController>> splitScreenOptionalProvider;

  private final Provider<Optional<SplitScreenController>> newSplitScreenOptionalProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<PipUiEventLogger> pipUiEventLoggerProvider;

  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public TvPipModule_ProvidePipTaskOrganizerFactory(Provider<Context> contextProvider,
      Provider<TvPipMenuController> tvPipMenuControllerProvider,
      Provider<SyncTransactionQueue> syncTransactionQueueProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipTransitionState> pipTransitionStateProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipAnimationController> pipAnimationControllerProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<PipSurfaceTransactionHelper> pipSurfaceTransactionHelperProvider,
      Provider<Optional<LegacySplitScreenController>> splitScreenOptionalProvider,
      Provider<Optional<SplitScreenController>> newSplitScreenOptionalProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<PipUiEventLogger> pipUiEventLoggerProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.tvPipMenuControllerProvider = tvPipMenuControllerProvider;
    this.syncTransactionQueueProvider = syncTransactionQueueProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipTransitionStateProvider = pipTransitionStateProvider;
    this.pipBoundsAlgorithmProvider = pipBoundsAlgorithmProvider;
    this.pipAnimationControllerProvider = pipAnimationControllerProvider;
    this.pipTransitionControllerProvider = pipTransitionControllerProvider;
    this.pipSurfaceTransactionHelperProvider = pipSurfaceTransactionHelperProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.newSplitScreenOptionalProvider = newSplitScreenOptionalProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.pipUiEventLoggerProvider = pipUiEventLoggerProvider;
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public PipTaskOrganizer get() {
    return providePipTaskOrganizer(contextProvider.get(), tvPipMenuControllerProvider.get(), syncTransactionQueueProvider.get(), pipBoundsStateProvider.get(), pipTransitionStateProvider.get(), pipBoundsAlgorithmProvider.get(), pipAnimationControllerProvider.get(), pipTransitionControllerProvider.get(), pipSurfaceTransactionHelperProvider.get(), splitScreenOptionalProvider.get(), newSplitScreenOptionalProvider.get(), displayControllerProvider.get(), pipUiEventLoggerProvider.get(), shellTaskOrganizerProvider.get(), mainExecutorProvider.get());
  }

  public static TvPipModule_ProvidePipTaskOrganizerFactory create(Provider<Context> contextProvider,
      Provider<TvPipMenuController> tvPipMenuControllerProvider,
      Provider<SyncTransactionQueue> syncTransactionQueueProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipTransitionState> pipTransitionStateProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipAnimationController> pipAnimationControllerProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<PipSurfaceTransactionHelper> pipSurfaceTransactionHelperProvider,
      Provider<Optional<LegacySplitScreenController>> splitScreenOptionalProvider,
      Provider<Optional<SplitScreenController>> newSplitScreenOptionalProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<PipUiEventLogger> pipUiEventLoggerProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new TvPipModule_ProvidePipTaskOrganizerFactory(contextProvider, tvPipMenuControllerProvider, syncTransactionQueueProvider, pipBoundsStateProvider, pipTransitionStateProvider, pipBoundsAlgorithmProvider, pipAnimationControllerProvider, pipTransitionControllerProvider, pipSurfaceTransactionHelperProvider, splitScreenOptionalProvider, newSplitScreenOptionalProvider, displayControllerProvider, pipUiEventLoggerProvider, shellTaskOrganizerProvider, mainExecutorProvider);
  }

  public static PipTaskOrganizer providePipTaskOrganizer(Context context,
      TvPipMenuController tvPipMenuController, SyncTransactionQueue syncTransactionQueue,
      PipBoundsState pipBoundsState, PipTransitionState pipTransitionState,
      PipBoundsAlgorithm pipBoundsAlgorithm, PipAnimationController pipAnimationController,
      PipTransitionController pipTransitionController,
      PipSurfaceTransactionHelper pipSurfaceTransactionHelper,
      Optional<LegacySplitScreenController> splitScreenOptional,
      Optional<SplitScreenController> newSplitScreenOptional, DisplayController displayController,
      PipUiEventLogger pipUiEventLogger, ShellTaskOrganizer shellTaskOrganizer,
      ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(TvPipModule.providePipTaskOrganizer(context, tvPipMenuController, syncTransactionQueue, pipBoundsState, pipTransitionState, pipBoundsAlgorithm, pipAnimationController, pipTransitionController, pipSurfaceTransactionHelper, splitScreenOptional, newSplitScreenOptional, displayController, pipUiEventLogger, shellTaskOrganizer, mainExecutor));
  }
}

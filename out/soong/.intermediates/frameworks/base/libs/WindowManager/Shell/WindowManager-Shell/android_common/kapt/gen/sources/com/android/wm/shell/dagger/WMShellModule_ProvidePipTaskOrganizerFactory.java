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
import com.android.wm.shell.pip.phone.PhonePipMenuController;
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
public final class WMShellModule_ProvidePipTaskOrganizerFactory implements Factory<PipTaskOrganizer> {
  private final Provider<Context> contextProvider;

  private final Provider<SyncTransactionQueue> syncTransactionQueueProvider;

  private final Provider<PipTransitionState> pipTransitionStateProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider;

  private final Provider<PhonePipMenuController> menuPhoneControllerProvider;

  private final Provider<PipAnimationController> pipAnimationControllerProvider;

  private final Provider<PipSurfaceTransactionHelper> pipSurfaceTransactionHelperProvider;

  private final Provider<PipTransitionController> pipTransitionControllerProvider;

  private final Provider<Optional<LegacySplitScreenController>> splitScreenOptionalProvider;

  private final Provider<Optional<SplitScreenController>> newSplitScreenOptionalProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<PipUiEventLogger> pipUiEventLoggerProvider;

  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellModule_ProvidePipTaskOrganizerFactory(Provider<Context> contextProvider,
      Provider<SyncTransactionQueue> syncTransactionQueueProvider,
      Provider<PipTransitionState> pipTransitionStateProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PhonePipMenuController> menuPhoneControllerProvider,
      Provider<PipAnimationController> pipAnimationControllerProvider,
      Provider<PipSurfaceTransactionHelper> pipSurfaceTransactionHelperProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<Optional<LegacySplitScreenController>> splitScreenOptionalProvider,
      Provider<Optional<SplitScreenController>> newSplitScreenOptionalProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<PipUiEventLogger> pipUiEventLoggerProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.syncTransactionQueueProvider = syncTransactionQueueProvider;
    this.pipTransitionStateProvider = pipTransitionStateProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipBoundsAlgorithmProvider = pipBoundsAlgorithmProvider;
    this.menuPhoneControllerProvider = menuPhoneControllerProvider;
    this.pipAnimationControllerProvider = pipAnimationControllerProvider;
    this.pipSurfaceTransactionHelperProvider = pipSurfaceTransactionHelperProvider;
    this.pipTransitionControllerProvider = pipTransitionControllerProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.newSplitScreenOptionalProvider = newSplitScreenOptionalProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.pipUiEventLoggerProvider = pipUiEventLoggerProvider;
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public PipTaskOrganizer get() {
    return providePipTaskOrganizer(contextProvider.get(), syncTransactionQueueProvider.get(), pipTransitionStateProvider.get(), pipBoundsStateProvider.get(), pipBoundsAlgorithmProvider.get(), menuPhoneControllerProvider.get(), pipAnimationControllerProvider.get(), pipSurfaceTransactionHelperProvider.get(), pipTransitionControllerProvider.get(), splitScreenOptionalProvider.get(), newSplitScreenOptionalProvider.get(), displayControllerProvider.get(), pipUiEventLoggerProvider.get(), shellTaskOrganizerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellModule_ProvidePipTaskOrganizerFactory create(
      Provider<Context> contextProvider,
      Provider<SyncTransactionQueue> syncTransactionQueueProvider,
      Provider<PipTransitionState> pipTransitionStateProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PhonePipMenuController> menuPhoneControllerProvider,
      Provider<PipAnimationController> pipAnimationControllerProvider,
      Provider<PipSurfaceTransactionHelper> pipSurfaceTransactionHelperProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<Optional<LegacySplitScreenController>> splitScreenOptionalProvider,
      Provider<Optional<SplitScreenController>> newSplitScreenOptionalProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<PipUiEventLogger> pipUiEventLoggerProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellModule_ProvidePipTaskOrganizerFactory(contextProvider, syncTransactionQueueProvider, pipTransitionStateProvider, pipBoundsStateProvider, pipBoundsAlgorithmProvider, menuPhoneControllerProvider, pipAnimationControllerProvider, pipSurfaceTransactionHelperProvider, pipTransitionControllerProvider, splitScreenOptionalProvider, newSplitScreenOptionalProvider, displayControllerProvider, pipUiEventLoggerProvider, shellTaskOrganizerProvider, mainExecutorProvider);
  }

  public static PipTaskOrganizer providePipTaskOrganizer(Context context,
      SyncTransactionQueue syncTransactionQueue, PipTransitionState pipTransitionState,
      PipBoundsState pipBoundsState, PipBoundsAlgorithm pipBoundsAlgorithm,
      PhonePipMenuController menuPhoneController, PipAnimationController pipAnimationController,
      PipSurfaceTransactionHelper pipSurfaceTransactionHelper,
      PipTransitionController pipTransitionController,
      Optional<LegacySplitScreenController> splitScreenOptional,
      Optional<SplitScreenController> newSplitScreenOptional, DisplayController displayController,
      PipUiEventLogger pipUiEventLogger, ShellTaskOrganizer shellTaskOrganizer,
      ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.providePipTaskOrganizer(context, syncTransactionQueue, pipTransitionState, pipBoundsState, pipBoundsAlgorithm, menuPhoneController, pipAnimationController, pipSurfaceTransactionHelper, pipTransitionController, splitScreenOptional, newSplitScreenOptional, displayController, pipUiEventLogger, shellTaskOrganizer, mainExecutor));
  }
}

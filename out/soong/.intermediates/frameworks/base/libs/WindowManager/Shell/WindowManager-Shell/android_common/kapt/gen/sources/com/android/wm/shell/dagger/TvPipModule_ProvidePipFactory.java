package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.WindowManagerShellWrapper;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.TaskStackListenerImpl;
import com.android.wm.shell.pip.Pip;
import com.android.wm.shell.pip.PipBoundsAlgorithm;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipMediaController;
import com.android.wm.shell.pip.PipTaskOrganizer;
import com.android.wm.shell.pip.PipTransitionController;
import com.android.wm.shell.pip.tv.TvPipMenuController;
import com.android.wm.shell.pip.tv.TvPipNotificationController;
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
public final class TvPipModule_ProvidePipFactory implements Factory<Optional<Pip>> {
  private final Provider<Context> contextProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider;

  private final Provider<PipTaskOrganizer> pipTaskOrganizerProvider;

  private final Provider<TvPipMenuController> tvPipMenuControllerProvider;

  private final Provider<PipMediaController> pipMediaControllerProvider;

  private final Provider<PipTransitionController> pipTransitionControllerProvider;

  private final Provider<TvPipNotificationController> tvPipNotificationControllerProvider;

  private final Provider<TaskStackListenerImpl> taskStackListenerProvider;

  private final Provider<WindowManagerShellWrapper> windowManagerShellWrapperProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public TvPipModule_ProvidePipFactory(Provider<Context> contextProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipTaskOrganizer> pipTaskOrganizerProvider,
      Provider<TvPipMenuController> tvPipMenuControllerProvider,
      Provider<PipMediaController> pipMediaControllerProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<TvPipNotificationController> tvPipNotificationControllerProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<WindowManagerShellWrapper> windowManagerShellWrapperProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipBoundsAlgorithmProvider = pipBoundsAlgorithmProvider;
    this.pipTaskOrganizerProvider = pipTaskOrganizerProvider;
    this.tvPipMenuControllerProvider = tvPipMenuControllerProvider;
    this.pipMediaControllerProvider = pipMediaControllerProvider;
    this.pipTransitionControllerProvider = pipTransitionControllerProvider;
    this.tvPipNotificationControllerProvider = tvPipNotificationControllerProvider;
    this.taskStackListenerProvider = taskStackListenerProvider;
    this.windowManagerShellWrapperProvider = windowManagerShellWrapperProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public Optional<Pip> get() {
    return providePip(contextProvider.get(), pipBoundsStateProvider.get(), pipBoundsAlgorithmProvider.get(), pipTaskOrganizerProvider.get(), tvPipMenuControllerProvider.get(), pipMediaControllerProvider.get(), pipTransitionControllerProvider.get(), tvPipNotificationControllerProvider.get(), taskStackListenerProvider.get(), windowManagerShellWrapperProvider.get(), mainExecutorProvider.get());
  }

  public static TvPipModule_ProvidePipFactory create(Provider<Context> contextProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipTaskOrganizer> pipTaskOrganizerProvider,
      Provider<TvPipMenuController> tvPipMenuControllerProvider,
      Provider<PipMediaController> pipMediaControllerProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<TvPipNotificationController> tvPipNotificationControllerProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<WindowManagerShellWrapper> windowManagerShellWrapperProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new TvPipModule_ProvidePipFactory(contextProvider, pipBoundsStateProvider, pipBoundsAlgorithmProvider, pipTaskOrganizerProvider, tvPipMenuControllerProvider, pipMediaControllerProvider, pipTransitionControllerProvider, tvPipNotificationControllerProvider, taskStackListenerProvider, windowManagerShellWrapperProvider, mainExecutorProvider);
  }

  public static Optional<Pip> providePip(Context context, PipBoundsState pipBoundsState,
      PipBoundsAlgorithm pipBoundsAlgorithm, PipTaskOrganizer pipTaskOrganizer,
      TvPipMenuController tvPipMenuController, PipMediaController pipMediaController,
      PipTransitionController pipTransitionController,
      TvPipNotificationController tvPipNotificationController,
      TaskStackListenerImpl taskStackListener, WindowManagerShellWrapper windowManagerShellWrapper,
      ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(TvPipModule.providePip(context, pipBoundsState, pipBoundsAlgorithm, pipTaskOrganizer, tvPipMenuController, pipMediaController, pipTransitionController, tvPipNotificationController, taskStackListener, windowManagerShellWrapper, mainExecutor));
  }
}

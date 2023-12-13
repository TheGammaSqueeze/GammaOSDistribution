package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.common.FloatingContentCoordinator;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.pip.PipBoundsAlgorithm;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipTaskOrganizer;
import com.android.wm.shell.pip.PipUiEventLogger;
import com.android.wm.shell.pip.phone.PhonePipMenuController;
import com.android.wm.shell.pip.phone.PipMotionHelper;
import com.android.wm.shell.pip.phone.PipTouchHandler;
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
public final class WMShellModule_ProvidePipTouchHandlerFactory implements Factory<PipTouchHandler> {
  private final Provider<Context> contextProvider;

  private final Provider<PhonePipMenuController> menuPhoneControllerProvider;

  private final Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<PipTaskOrganizer> pipTaskOrganizerProvider;

  private final Provider<PipMotionHelper> pipMotionHelperProvider;

  private final Provider<FloatingContentCoordinator> floatingContentCoordinatorProvider;

  private final Provider<PipUiEventLogger> pipUiEventLoggerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellModule_ProvidePipTouchHandlerFactory(Provider<Context> contextProvider,
      Provider<PhonePipMenuController> menuPhoneControllerProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipTaskOrganizer> pipTaskOrganizerProvider,
      Provider<PipMotionHelper> pipMotionHelperProvider,
      Provider<FloatingContentCoordinator> floatingContentCoordinatorProvider,
      Provider<PipUiEventLogger> pipUiEventLoggerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.menuPhoneControllerProvider = menuPhoneControllerProvider;
    this.pipBoundsAlgorithmProvider = pipBoundsAlgorithmProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipTaskOrganizerProvider = pipTaskOrganizerProvider;
    this.pipMotionHelperProvider = pipMotionHelperProvider;
    this.floatingContentCoordinatorProvider = floatingContentCoordinatorProvider;
    this.pipUiEventLoggerProvider = pipUiEventLoggerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public PipTouchHandler get() {
    return providePipTouchHandler(contextProvider.get(), menuPhoneControllerProvider.get(), pipBoundsAlgorithmProvider.get(), pipBoundsStateProvider.get(), pipTaskOrganizerProvider.get(), pipMotionHelperProvider.get(), floatingContentCoordinatorProvider.get(), pipUiEventLoggerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellModule_ProvidePipTouchHandlerFactory create(
      Provider<Context> contextProvider,
      Provider<PhonePipMenuController> menuPhoneControllerProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipTaskOrganizer> pipTaskOrganizerProvider,
      Provider<PipMotionHelper> pipMotionHelperProvider,
      Provider<FloatingContentCoordinator> floatingContentCoordinatorProvider,
      Provider<PipUiEventLogger> pipUiEventLoggerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellModule_ProvidePipTouchHandlerFactory(contextProvider, menuPhoneControllerProvider, pipBoundsAlgorithmProvider, pipBoundsStateProvider, pipTaskOrganizerProvider, pipMotionHelperProvider, floatingContentCoordinatorProvider, pipUiEventLoggerProvider, mainExecutorProvider);
  }

  public static PipTouchHandler providePipTouchHandler(Context context,
      PhonePipMenuController menuPhoneController, PipBoundsAlgorithm pipBoundsAlgorithm,
      PipBoundsState pipBoundsState, PipTaskOrganizer pipTaskOrganizer,
      PipMotionHelper pipMotionHelper, FloatingContentCoordinator floatingContentCoordinator,
      PipUiEventLogger pipUiEventLogger, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.providePipTouchHandler(context, menuPhoneController, pipBoundsAlgorithm, pipBoundsState, pipTaskOrganizer, pipMotionHelper, floatingContentCoordinator, pipUiEventLogger, mainExecutor));
  }
}

package com.android.wm.shell.dagger;

import android.content.Context;
import android.content.pm.LauncherApps;
import android.os.Handler;
import android.view.WindowManager;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.statusbar.IStatusBarService;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.WindowManagerShellWrapper;
import com.android.wm.shell.bubbles.BubbleController;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.FloatingContentCoordinator;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.common.TaskStackListenerImpl;
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
public final class WMShellModule_ProvideBubbleControllerFactory implements Factory<BubbleController> {
  private final Provider<Context> contextProvider;

  private final Provider<FloatingContentCoordinator> floatingContentCoordinatorProvider;

  private final Provider<IStatusBarService> statusBarServiceProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<WindowManagerShellWrapper> windowManagerShellWrapperProvider;

  private final Provider<LauncherApps> launcherAppsProvider;

  private final Provider<TaskStackListenerImpl> taskStackListenerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<ShellTaskOrganizer> organizerProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<SyncTransactionQueue> syncQueueProvider;

  public WMShellModule_ProvideBubbleControllerFactory(Provider<Context> contextProvider,
      Provider<FloatingContentCoordinator> floatingContentCoordinatorProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<WindowManagerShellWrapper> windowManagerShellWrapperProvider,
      Provider<LauncherApps> launcherAppsProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<ShellTaskOrganizer> organizerProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider, Provider<Handler> mainHandlerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider) {
    this.contextProvider = contextProvider;
    this.floatingContentCoordinatorProvider = floatingContentCoordinatorProvider;
    this.statusBarServiceProvider = statusBarServiceProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.windowManagerShellWrapperProvider = windowManagerShellWrapperProvider;
    this.launcherAppsProvider = launcherAppsProvider;
    this.taskStackListenerProvider = taskStackListenerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.organizerProvider = organizerProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.syncQueueProvider = syncQueueProvider;
  }

  @Override
  public BubbleController get() {
    return provideBubbleController(contextProvider.get(), floatingContentCoordinatorProvider.get(), statusBarServiceProvider.get(), windowManagerProvider.get(), windowManagerShellWrapperProvider.get(), launcherAppsProvider.get(), taskStackListenerProvider.get(), uiEventLoggerProvider.get(), organizerProvider.get(), displayControllerProvider.get(), mainExecutorProvider.get(), mainHandlerProvider.get(), syncQueueProvider.get());
  }

  public static WMShellModule_ProvideBubbleControllerFactory create(
      Provider<Context> contextProvider,
      Provider<FloatingContentCoordinator> floatingContentCoordinatorProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<WindowManagerShellWrapper> windowManagerShellWrapperProvider,
      Provider<LauncherApps> launcherAppsProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<ShellTaskOrganizer> organizerProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider, Provider<Handler> mainHandlerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider) {
    return new WMShellModule_ProvideBubbleControllerFactory(contextProvider, floatingContentCoordinatorProvider, statusBarServiceProvider, windowManagerProvider, windowManagerShellWrapperProvider, launcherAppsProvider, taskStackListenerProvider, uiEventLoggerProvider, organizerProvider, displayControllerProvider, mainExecutorProvider, mainHandlerProvider, syncQueueProvider);
  }

  public static BubbleController provideBubbleController(Context context,
      FloatingContentCoordinator floatingContentCoordinator, IStatusBarService statusBarService,
      WindowManager windowManager, WindowManagerShellWrapper windowManagerShellWrapper,
      LauncherApps launcherApps, TaskStackListenerImpl taskStackListener,
      UiEventLogger uiEventLogger, ShellTaskOrganizer organizer,
      DisplayController displayController, ShellExecutor mainExecutor, Handler mainHandler,
      SyncTransactionQueue syncQueue) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.provideBubbleController(context, floatingContentCoordinator, statusBarService, windowManager, windowManagerShellWrapper, launcherApps, taskStackListener, uiEventLogger, organizer, displayController, mainExecutor, mainHandler, syncQueue));
  }
}

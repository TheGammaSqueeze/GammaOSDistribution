package com.android.systemui.recents;

import android.content.Context;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.keyguard.ScreenLifecycle;
import com.android.systemui.model.SysUiState;
import com.android.systemui.navigationbar.NavigationBarController;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.shared.system.smartspace.SmartspaceTransitionController;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreen;
import com.android.wm.shell.onehanded.OneHanded;
import com.android.wm.shell.pip.Pip;
import com.android.wm.shell.recents.RecentTasks;
import com.android.wm.shell.splitscreen.SplitScreen;
import com.android.wm.shell.startingsurface.StartingSurface;
import com.android.wm.shell.transition.ShellTransitions;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
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
public final class OverviewProxyService_Factory implements Factory<OverviewProxyService> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<NavigationBarController> navBarControllerLazyProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  private final Provider<NavigationModeController> navModeControllerProvider;

  private final Provider<NotificationShadeWindowController> statusBarWinControllerProvider;

  private final Provider<SysUiState> sysUiStateProvider;

  private final Provider<Optional<Pip>> pipOptionalProvider;

  private final Provider<Optional<LegacySplitScreen>> legacySplitScreenOptionalProvider;

  private final Provider<Optional<SplitScreen>> splitScreenOptionalProvider;

  private final Provider<Optional<OneHanded>> oneHandedOptionalProvider;

  private final Provider<Optional<RecentTasks>> recentTasksProvider;

  private final Provider<Optional<StartingSurface>> startingSurfaceProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<ShellTransitions> shellTransitionsProvider;

  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  private final Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public OverviewProxyService_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<NavigationBarController> navBarControllerLazyProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<NavigationModeController> navModeControllerProvider,
      Provider<NotificationShadeWindowController> statusBarWinControllerProvider,
      Provider<SysUiState> sysUiStateProvider, Provider<Optional<Pip>> pipOptionalProvider,
      Provider<Optional<LegacySplitScreen>> legacySplitScreenOptionalProvider,
      Provider<Optional<SplitScreen>> splitScreenOptionalProvider,
      Provider<Optional<OneHanded>> oneHandedOptionalProvider,
      Provider<Optional<RecentTasks>> recentTasksProvider,
      Provider<Optional<StartingSurface>> startingSurfaceProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ShellTransitions> shellTransitionsProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.navBarControllerLazyProvider = navBarControllerLazyProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
    this.navModeControllerProvider = navModeControllerProvider;
    this.statusBarWinControllerProvider = statusBarWinControllerProvider;
    this.sysUiStateProvider = sysUiStateProvider;
    this.pipOptionalProvider = pipOptionalProvider;
    this.legacySplitScreenOptionalProvider = legacySplitScreenOptionalProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.oneHandedOptionalProvider = oneHandedOptionalProvider;
    this.recentTasksProvider = recentTasksProvider;
    this.startingSurfaceProvider = startingSurfaceProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.shellTransitionsProvider = shellTransitionsProvider;
    this.screenLifecycleProvider = screenLifecycleProvider;
    this.smartspaceTransitionControllerProvider = smartspaceTransitionControllerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public OverviewProxyService get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), DoubleCheck.lazy(navBarControllerLazyProvider), DoubleCheck.lazy(statusBarOptionalLazyProvider), navModeControllerProvider.get(), statusBarWinControllerProvider.get(), sysUiStateProvider.get(), pipOptionalProvider.get(), legacySplitScreenOptionalProvider.get(), splitScreenOptionalProvider.get(), oneHandedOptionalProvider.get(), recentTasksProvider.get(), startingSurfaceProvider.get(), broadcastDispatcherProvider.get(), shellTransitionsProvider.get(), screenLifecycleProvider.get(), smartspaceTransitionControllerProvider.get(), uiEventLoggerProvider.get(), dumpManagerProvider.get());
  }

  public static OverviewProxyService_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<NavigationBarController> navBarControllerLazyProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<NavigationModeController> navModeControllerProvider,
      Provider<NotificationShadeWindowController> statusBarWinControllerProvider,
      Provider<SysUiState> sysUiStateProvider, Provider<Optional<Pip>> pipOptionalProvider,
      Provider<Optional<LegacySplitScreen>> legacySplitScreenOptionalProvider,
      Provider<Optional<SplitScreen>> splitScreenOptionalProvider,
      Provider<Optional<OneHanded>> oneHandedOptionalProvider,
      Provider<Optional<RecentTasks>> recentTasksProvider,
      Provider<Optional<StartingSurface>> startingSurfaceProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ShellTransitions> shellTransitionsProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<DumpManager> dumpManagerProvider) {
    return new OverviewProxyService_Factory(contextProvider, commandQueueProvider, navBarControllerLazyProvider, statusBarOptionalLazyProvider, navModeControllerProvider, statusBarWinControllerProvider, sysUiStateProvider, pipOptionalProvider, legacySplitScreenOptionalProvider, splitScreenOptionalProvider, oneHandedOptionalProvider, recentTasksProvider, startingSurfaceProvider, broadcastDispatcherProvider, shellTransitionsProvider, screenLifecycleProvider, smartspaceTransitionControllerProvider, uiEventLoggerProvider, dumpManagerProvider);
  }

  public static OverviewProxyService newInstance(Context context, CommandQueue commandQueue,
      Lazy<NavigationBarController> navBarControllerLazy,
      Lazy<Optional<StatusBar>> statusBarOptionalLazy, NavigationModeController navModeController,
      NotificationShadeWindowController statusBarWinController, SysUiState sysUiState,
      Optional<Pip> pipOptional, Optional<LegacySplitScreen> legacySplitScreenOptional,
      Optional<SplitScreen> splitScreenOptional, Optional<OneHanded> oneHandedOptional,
      Optional<RecentTasks> recentTasks, Optional<StartingSurface> startingSurface,
      BroadcastDispatcher broadcastDispatcher, ShellTransitions shellTransitions,
      ScreenLifecycle screenLifecycle,
      SmartspaceTransitionController smartspaceTransitionController, UiEventLogger uiEventLogger,
      DumpManager dumpManager) {
    return new OverviewProxyService(context, commandQueue, navBarControllerLazy, statusBarOptionalLazy, navModeController, statusBarWinController, sysUiState, pipOptional, legacySplitScreenOptional, splitScreenOptional, oneHandedOptional, recentTasks, startingSurface, broadcastDispatcher, shellTransitions, screenLifecycle, smartspaceTransitionController, uiEventLogger, dumpManager);
  }
}

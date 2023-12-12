package com.android.systemui.navigationbar;

import android.os.Handler;
import android.telecom.TelecomManager;
import android.view.accessibility.AccessibilityManager;
import android.view.inputmethod.InputMethodManager;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.accessibility.AccessibilityButtonModeObserver;
import com.android.systemui.accessibility.SystemActions;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.model.SysUiState;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.recents.Recents;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.NotificationShadeDepthController;
import com.android.systemui.statusbar.phone.AutoHideController;
import com.android.systemui.statusbar.phone.LightBarController;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreen;
import com.android.wm.shell.pip.Pip;
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
public final class NavigationBar_Factory_Factory implements Factory<NavigationBar.Factory> {
  private final Provider<AssistManager> assistManagerLazyProvider;

  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<OverviewProxyService> overviewProxyServiceProvider;

  private final Provider<NavigationModeController> navigationModeControllerProvider;

  private final Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<SysUiState> sysUiFlagsContainerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<Optional<Pip>> pipOptionalProvider;

  private final Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider;

  private final Provider<Optional<Recents>> recentsOptionalProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<NotificationRemoteInputManager> notificationRemoteInputManagerProvider;

  private final Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider;

  private final Provider<SystemActions> systemActionsProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<NavigationBarOverlayController> navbarOverlayControllerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<NavBarHelper> navBarHelperProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<LightBarController> mainLightBarControllerProvider;

  private final Provider<LightBarController.Factory> lightBarControllerFactoryProvider;

  private final Provider<AutoHideController> mainAutoHideControllerProvider;

  private final Provider<AutoHideController.Factory> autoHideControllerFactoryProvider;

  private final Provider<Optional<TelecomManager>> telecomManagerOptionalProvider;

  private final Provider<InputMethodManager> inputMethodManagerProvider;

  public NavigationBar_Factory_Factory(Provider<AssistManager> assistManagerLazyProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<SysUiState> sysUiFlagsContainerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<Optional<Pip>> pipOptionalProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider,
      Provider<Optional<Recents>> recentsOptionalProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<NotificationRemoteInputManager> notificationRemoteInputManagerProvider,
      Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider,
      Provider<SystemActions> systemActionsProvider, Provider<Handler> mainHandlerProvider,
      Provider<NavigationBarOverlayController> navbarOverlayControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<NavBarHelper> navBarHelperProvider,
      Provider<UserTracker> userTrackerProvider,
      Provider<LightBarController> mainLightBarControllerProvider,
      Provider<LightBarController.Factory> lightBarControllerFactoryProvider,
      Provider<AutoHideController> mainAutoHideControllerProvider,
      Provider<AutoHideController.Factory> autoHideControllerFactoryProvider,
      Provider<Optional<TelecomManager>> telecomManagerOptionalProvider,
      Provider<InputMethodManager> inputMethodManagerProvider) {
    this.assistManagerLazyProvider = assistManagerLazyProvider;
    this.accessibilityManagerProvider = accessibilityManagerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.overviewProxyServiceProvider = overviewProxyServiceProvider;
    this.navigationModeControllerProvider = navigationModeControllerProvider;
    this.accessibilityButtonModeObserverProvider = accessibilityButtonModeObserverProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.sysUiFlagsContainerProvider = sysUiFlagsContainerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.pipOptionalProvider = pipOptionalProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.recentsOptionalProvider = recentsOptionalProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.notificationRemoteInputManagerProvider = notificationRemoteInputManagerProvider;
    this.notificationShadeDepthControllerProvider = notificationShadeDepthControllerProvider;
    this.systemActionsProvider = systemActionsProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.navbarOverlayControllerProvider = navbarOverlayControllerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.navBarHelperProvider = navBarHelperProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.mainLightBarControllerProvider = mainLightBarControllerProvider;
    this.lightBarControllerFactoryProvider = lightBarControllerFactoryProvider;
    this.mainAutoHideControllerProvider = mainAutoHideControllerProvider;
    this.autoHideControllerFactoryProvider = autoHideControllerFactoryProvider;
    this.telecomManagerOptionalProvider = telecomManagerOptionalProvider;
    this.inputMethodManagerProvider = inputMethodManagerProvider;
  }

  @Override
  public NavigationBar.Factory get() {
    return newInstance(DoubleCheck.lazy(assistManagerLazyProvider), accessibilityManagerProvider.get(), deviceProvisionedControllerProvider.get(), metricsLoggerProvider.get(), overviewProxyServiceProvider.get(), navigationModeControllerProvider.get(), accessibilityButtonModeObserverProvider.get(), statusBarStateControllerProvider.get(), sysUiFlagsContainerProvider.get(), broadcastDispatcherProvider.get(), commandQueueProvider.get(), pipOptionalProvider.get(), splitScreenOptionalProvider.get(), recentsOptionalProvider.get(), DoubleCheck.lazy(statusBarOptionalLazyProvider), shadeControllerProvider.get(), notificationRemoteInputManagerProvider.get(), notificationShadeDepthControllerProvider.get(), systemActionsProvider.get(), mainHandlerProvider.get(), navbarOverlayControllerProvider.get(), uiEventLoggerProvider.get(), navBarHelperProvider.get(), userTrackerProvider.get(), mainLightBarControllerProvider.get(), lightBarControllerFactoryProvider.get(), mainAutoHideControllerProvider.get(), autoHideControllerFactoryProvider.get(), telecomManagerOptionalProvider.get(), inputMethodManagerProvider.get());
  }

  public static NavigationBar_Factory_Factory create(
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<SysUiState> sysUiFlagsContainerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<Optional<Pip>> pipOptionalProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider,
      Provider<Optional<Recents>> recentsOptionalProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<NotificationRemoteInputManager> notificationRemoteInputManagerProvider,
      Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider,
      Provider<SystemActions> systemActionsProvider, Provider<Handler> mainHandlerProvider,
      Provider<NavigationBarOverlayController> navbarOverlayControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<NavBarHelper> navBarHelperProvider,
      Provider<UserTracker> userTrackerProvider,
      Provider<LightBarController> mainLightBarControllerProvider,
      Provider<LightBarController.Factory> lightBarControllerFactoryProvider,
      Provider<AutoHideController> mainAutoHideControllerProvider,
      Provider<AutoHideController.Factory> autoHideControllerFactoryProvider,
      Provider<Optional<TelecomManager>> telecomManagerOptionalProvider,
      Provider<InputMethodManager> inputMethodManagerProvider) {
    return new NavigationBar_Factory_Factory(assistManagerLazyProvider, accessibilityManagerProvider, deviceProvisionedControllerProvider, metricsLoggerProvider, overviewProxyServiceProvider, navigationModeControllerProvider, accessibilityButtonModeObserverProvider, statusBarStateControllerProvider, sysUiFlagsContainerProvider, broadcastDispatcherProvider, commandQueueProvider, pipOptionalProvider, splitScreenOptionalProvider, recentsOptionalProvider, statusBarOptionalLazyProvider, shadeControllerProvider, notificationRemoteInputManagerProvider, notificationShadeDepthControllerProvider, systemActionsProvider, mainHandlerProvider, navbarOverlayControllerProvider, uiEventLoggerProvider, navBarHelperProvider, userTrackerProvider, mainLightBarControllerProvider, lightBarControllerFactoryProvider, mainAutoHideControllerProvider, autoHideControllerFactoryProvider, telecomManagerOptionalProvider, inputMethodManagerProvider);
  }

  public static NavigationBar.Factory newInstance(Lazy<AssistManager> assistManagerLazy,
      AccessibilityManager accessibilityManager,
      DeviceProvisionedController deviceProvisionedController, MetricsLogger metricsLogger,
      OverviewProxyService overviewProxyService, NavigationModeController navigationModeController,
      AccessibilityButtonModeObserver accessibilityButtonModeObserver,
      StatusBarStateController statusBarStateController, SysUiState sysUiFlagsContainer,
      BroadcastDispatcher broadcastDispatcher, CommandQueue commandQueue, Optional<Pip> pipOptional,
      Optional<LegacySplitScreen> splitScreenOptional, Optional<Recents> recentsOptional,
      Lazy<Optional<StatusBar>> statusBarOptionalLazy, ShadeController shadeController,
      NotificationRemoteInputManager notificationRemoteInputManager,
      NotificationShadeDepthController notificationShadeDepthController,
      SystemActions systemActions, Handler mainHandler,
      NavigationBarOverlayController navbarOverlayController, UiEventLogger uiEventLogger,
      NavBarHelper navBarHelper, UserTracker userTracker, LightBarController mainLightBarController,
      LightBarController.Factory lightBarControllerFactory,
      AutoHideController mainAutoHideController,
      AutoHideController.Factory autoHideControllerFactory,
      Optional<TelecomManager> telecomManagerOptional, InputMethodManager inputMethodManager) {
    return new NavigationBar.Factory(assistManagerLazy, accessibilityManager, deviceProvisionedController, metricsLogger, overviewProxyService, navigationModeController, accessibilityButtonModeObserver, statusBarStateController, sysUiFlagsContainer, broadcastDispatcher, commandQueue, pipOptional, splitScreenOptional, recentsOptional, statusBarOptionalLazy, shadeController, notificationRemoteInputManager, notificationShadeDepthController, systemActions, mainHandler, navbarOverlayController, uiEventLogger, navBarHelper, userTracker, mainLightBarController, lightBarControllerFactory, mainAutoHideController, autoHideControllerFactory, telecomManagerOptional, inputMethodManager);
  }
}

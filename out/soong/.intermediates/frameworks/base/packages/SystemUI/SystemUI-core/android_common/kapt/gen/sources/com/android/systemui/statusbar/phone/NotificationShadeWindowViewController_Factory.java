package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.keyguard.LockIconViewController;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.dock.DockManager;
import com.android.systemui.doze.DozeLog;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.LockscreenShadeTransitionController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationShadeDepthController;
import com.android.systemui.statusbar.PulseExpansionHandler;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.notification.DynamicPrivacyController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionStateManager;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import com.android.systemui.tuner.TunerService;
import dagger.internal.Factory;
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
public final class NotificationShadeWindowViewController_Factory implements Factory<NotificationShadeWindowViewController> {
  private final Provider<NotificationWakeUpCoordinator> coordinatorProvider;

  private final Provider<PulseExpansionHandler> pulseExpansionHandlerProvider;

  private final Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<LockscreenShadeTransitionController> transitionControllerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<DozeLog> dozeLogProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<DockManager> dockManagerProvider;

  private final Provider<NotificationShadeDepthController> depthControllerProvider;

  private final Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider;

  private final Provider<NotificationPanelViewController> notificationPanelViewControllerProvider;

  private final Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider;

  private final Provider<StatusBarWindowController> statusBarWindowControllerProvider;

  private final Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  private final Provider<LockIconViewController> lockIconViewControllerProvider;

  private final Provider<Context> contextProvider;

  public NotificationShadeWindowViewController_Factory(
      Provider<NotificationWakeUpCoordinator> coordinatorProvider,
      Provider<PulseExpansionHandler> pulseExpansionHandlerProvider,
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<LockscreenShadeTransitionController> transitionControllerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<PluginManager> pluginManagerProvider, Provider<TunerService> tunerServiceProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<DozeLog> dozeLogProvider, Provider<DozeParameters> dozeParametersProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<ShadeController> shadeControllerProvider, Provider<DockManager> dockManagerProvider,
      Provider<NotificationShadeDepthController> depthControllerProvider,
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<LockIconViewController> lockIconViewControllerProvider,
      Provider<Context> contextProvider) {
    this.coordinatorProvider = coordinatorProvider;
    this.pulseExpansionHandlerProvider = pulseExpansionHandlerProvider;
    this.dynamicPrivacyControllerProvider = dynamicPrivacyControllerProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.transitionControllerProvider = transitionControllerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.pluginManagerProvider = pluginManagerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.notificationLockscreenUserManagerProvider = notificationLockscreenUserManagerProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.dozeLogProvider = dozeLogProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.dockManagerProvider = dockManagerProvider;
    this.depthControllerProvider = depthControllerProvider;
    this.notificationShadeWindowViewProvider = notificationShadeWindowViewProvider;
    this.notificationPanelViewControllerProvider = notificationPanelViewControllerProvider;
    this.panelExpansionStateManagerProvider = panelExpansionStateManagerProvider;
    this.statusBarWindowControllerProvider = statusBarWindowControllerProvider;
    this.notificationStackScrollLayoutControllerProvider = notificationStackScrollLayoutControllerProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
    this.lockIconViewControllerProvider = lockIconViewControllerProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public NotificationShadeWindowViewController get() {
    return newInstance(coordinatorProvider.get(), pulseExpansionHandlerProvider.get(), dynamicPrivacyControllerProvider.get(), bypassControllerProvider.get(), transitionControllerProvider.get(), falsingCollectorProvider.get(), pluginManagerProvider.get(), tunerServiceProvider.get(), notificationLockscreenUserManagerProvider.get(), notificationEntryManagerProvider.get(), keyguardStateControllerProvider.get(), statusBarStateControllerProvider.get(), dozeLogProvider.get(), dozeParametersProvider.get(), commandQueueProvider.get(), shadeControllerProvider.get(), dockManagerProvider.get(), depthControllerProvider.get(), notificationShadeWindowViewProvider.get(), notificationPanelViewControllerProvider.get(), panelExpansionStateManagerProvider.get(), statusBarWindowControllerProvider.get(), notificationStackScrollLayoutControllerProvider.get(), statusBarKeyguardViewManagerProvider.get(), lockIconViewControllerProvider.get(), contextProvider.get());
  }

  public static NotificationShadeWindowViewController_Factory create(
      Provider<NotificationWakeUpCoordinator> coordinatorProvider,
      Provider<PulseExpansionHandler> pulseExpansionHandlerProvider,
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<LockscreenShadeTransitionController> transitionControllerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<PluginManager> pluginManagerProvider, Provider<TunerService> tunerServiceProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<DozeLog> dozeLogProvider, Provider<DozeParameters> dozeParametersProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<ShadeController> shadeControllerProvider, Provider<DockManager> dockManagerProvider,
      Provider<NotificationShadeDepthController> depthControllerProvider,
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<LockIconViewController> lockIconViewControllerProvider,
      Provider<Context> contextProvider) {
    return new NotificationShadeWindowViewController_Factory(coordinatorProvider, pulseExpansionHandlerProvider, dynamicPrivacyControllerProvider, bypassControllerProvider, transitionControllerProvider, falsingCollectorProvider, pluginManagerProvider, tunerServiceProvider, notificationLockscreenUserManagerProvider, notificationEntryManagerProvider, keyguardStateControllerProvider, statusBarStateControllerProvider, dozeLogProvider, dozeParametersProvider, commandQueueProvider, shadeControllerProvider, dockManagerProvider, depthControllerProvider, notificationShadeWindowViewProvider, notificationPanelViewControllerProvider, panelExpansionStateManagerProvider, statusBarWindowControllerProvider, notificationStackScrollLayoutControllerProvider, statusBarKeyguardViewManagerProvider, lockIconViewControllerProvider, contextProvider);
  }

  public static NotificationShadeWindowViewController newInstance(
      NotificationWakeUpCoordinator coordinator, PulseExpansionHandler pulseExpansionHandler,
      DynamicPrivacyController dynamicPrivacyController, KeyguardBypassController bypassController,
      LockscreenShadeTransitionController transitionController, FalsingCollector falsingCollector,
      PluginManager pluginManager, TunerService tunerService,
      NotificationLockscreenUserManager notificationLockscreenUserManager,
      NotificationEntryManager notificationEntryManager,
      KeyguardStateController keyguardStateController,
      SysuiStatusBarStateController statusBarStateController, DozeLog dozeLog,
      DozeParameters dozeParameters, CommandQueue commandQueue, ShadeController shadeController,
      DockManager dockManager, NotificationShadeDepthController depthController,
      NotificationShadeWindowView notificationShadeWindowView,
      NotificationPanelViewController notificationPanelViewController,
      PanelExpansionStateManager panelExpansionStateManager,
      StatusBarWindowController statusBarWindowController,
      NotificationStackScrollLayoutController notificationStackScrollLayoutController,
      StatusBarKeyguardViewManager statusBarKeyguardViewManager,
      LockIconViewController lockIconViewController, Context context) {
    return new NotificationShadeWindowViewController(coordinator, pulseExpansionHandler, dynamicPrivacyController, bypassController, transitionController, falsingCollector, pluginManager, tunerService, notificationLockscreenUserManager, notificationEntryManager, keyguardStateController, statusBarStateController, dozeLog, dozeParameters, commandQueue, shadeController, dockManager, depthController, notificationShadeWindowView, notificationPanelViewController, panelExpansionStateManager, statusBarWindowController, notificationStackScrollLayoutController, statusBarKeyguardViewManager, lockIconViewController, context);
  }
}

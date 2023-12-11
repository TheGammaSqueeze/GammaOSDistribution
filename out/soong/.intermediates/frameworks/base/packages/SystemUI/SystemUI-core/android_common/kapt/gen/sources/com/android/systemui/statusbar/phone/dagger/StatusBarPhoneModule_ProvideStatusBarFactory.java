package com.android.systemui.statusbar.phone.dagger;

import android.app.WallpaperManager;
import android.content.Context;
import android.os.Handler;
import android.os.PowerManager;
import android.util.DisplayMetrics;
import com.android.internal.logging.MetricsLogger;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.keyguard.ViewMediatorCallback;
import com.android.systemui.InitController;
import com.android.systemui.accessibility.floatingmenu.AccessibilityFloatingMenuController;
import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.colorextraction.SysuiColorExtractor;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.fragments.FragmentService;
import com.android.systemui.keyguard.KeyguardUnlockAnimationController;
import com.android.systemui.keyguard.KeyguardViewMediator;
import com.android.systemui.keyguard.ScreenLifecycle;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.navigationbar.NavigationBarController;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.PluginDependencyProvider;
import com.android.systemui.recents.ScreenPinningRequest;
import com.android.systemui.settings.brightness.BrightnessSliderController;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.KeyguardIndicationController;
import com.android.systemui.statusbar.LockscreenShadeTransitionController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.NotificationShadeDepthController;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.NotificationViewHierarchyManager;
import com.android.systemui.statusbar.OperatorNameViewController;
import com.android.systemui.statusbar.PulseExpansionHandler;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.charging.WiredChargingRippleController;
import com.android.systemui.statusbar.connectivity.NetworkController;
import com.android.systemui.statusbar.events.SystemStatusAnimationScheduler;
import com.android.systemui.statusbar.notification.DynamicPrivacyController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.notification.collection.render.NotifShadeEventSource;
import com.android.systemui.statusbar.notification.init.NotificationsController;
import com.android.systemui.statusbar.notification.interruption.BypassHeadsUpNotifier;
import com.android.systemui.statusbar.notification.interruption.NotificationInterruptStateProvider;
import com.android.systemui.statusbar.notification.logging.NotificationLogger;
import com.android.systemui.statusbar.notification.row.NotificationGutsManager;
import com.android.systemui.statusbar.phone.AutoHideController;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.DozeScrimController;
import com.android.systemui.statusbar.phone.DozeServiceHost;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
import com.android.systemui.statusbar.phone.LightBarController;
import com.android.systemui.statusbar.phone.LightsOutNotifController;
import com.android.systemui.statusbar.phone.LockscreenGestureLogger;
import com.android.systemui.statusbar.phone.LockscreenWallpaper;
import com.android.systemui.statusbar.phone.NotificationIconAreaController;
import com.android.systemui.statusbar.phone.PhoneStatusBarPolicy;
import com.android.systemui.statusbar.phone.ScrimController;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.phone.StatusBarHideIconsForBouncerManager;
import com.android.systemui.statusbar.phone.StatusBarIconController;
import com.android.systemui.statusbar.phone.StatusBarKeyguardViewManager;
import com.android.systemui.statusbar.phone.StatusBarLocationPublisher;
import com.android.systemui.statusbar.phone.StatusBarNotificationActivityStarter;
import com.android.systemui.statusbar.phone.StatusBarSignalPolicy;
import com.android.systemui.statusbar.phone.StatusBarTouchableRegionManager;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
import com.android.systemui.statusbar.phone.fragment.CollapsedStatusBarFragmentLogger;
import com.android.systemui.statusbar.phone.ongoingcall.OngoingCallController;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionStateManager;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.ExtensionController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.statusbar.policy.UserInfoControllerImpl;
import com.android.systemui.statusbar.policy.UserSwitcherController;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.WallpaperController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.concurrency.MessageRouter;
import com.android.systemui.volume.VolumeComponent;
import com.android.systemui.wmshell.BubblesManager;
import com.android.wm.shell.bubbles.Bubbles;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreen;
import com.android.wm.shell.startingsurface.StartingSurface;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Optional;
import java.util.concurrent.Executor;
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
public final class StatusBarPhoneModule_ProvideStatusBarFactory implements Factory<StatusBar> {
  private final Provider<Context> contextProvider;

  private final Provider<NotificationsController> notificationsControllerProvider;

  private final Provider<FragmentService> fragmentServiceProvider;

  private final Provider<LightBarController> lightBarControllerProvider;

  private final Provider<AutoHideController> autoHideControllerProvider;

  private final Provider<StatusBarWindowController> statusBarWindowControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<StatusBarSignalPolicy> statusBarSignalPolicyProvider;

  private final Provider<PulseExpansionHandler> pulseExpansionHandlerProvider;

  private final Provider<NotificationWakeUpCoordinator> notificationWakeUpCoordinatorProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<HeadsUpManagerPhone> headsUpManagerPhoneProvider;

  private final Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider;

  private final Provider<BypassHeadsUpNotifier> bypassHeadsUpNotifierProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<NotifShadeEventSource> notifShadeEventSourceProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<NotificationGutsManager> notificationGutsManagerProvider;

  private final Provider<NotificationLogger> notificationLoggerProvider;

  private final Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider;

  private final Provider<NotificationViewHierarchyManager> notificationViewHierarchyManagerProvider;

  private final Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider;

  private final Provider<KeyguardViewMediator> keyguardViewMediatorProvider;

  private final Provider<DisplayMetrics> displayMetricsProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<Executor> uiBgExecutorProvider;

  private final Provider<NotificationMediaManager> notificationMediaManagerProvider;

  private final Provider<NotificationLockscreenUserManager> lockScreenUserManagerProvider;

  private final Provider<NotificationRemoteInputManager> remoteInputManagerProvider;

  private final Provider<UserSwitcherController> userSwitcherControllerProvider;

  private final Provider<NetworkController> networkControllerProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<SysuiColorExtractor> colorExtractorProvider;

  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider;

  private final Provider<Optional<Bubbles>> bubblesOptionalProvider;

  private final Provider<VisualStabilityManager> visualStabilityManagerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<NavigationBarController> navigationBarControllerProvider;

  private final Provider<AccessibilityFloatingMenuController> accessibilityFloatingMenuControllerProvider;

  private final Provider<AssistManager> assistManagerLazyProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<ScrimController> scrimControllerProvider;

  private final Provider<LockscreenWallpaper> lockscreenWallpaperLazyProvider;

  private final Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider;

  private final Provider<BiometricUnlockController> biometricUnlockControllerLazyProvider;

  private final Provider<DozeServiceHost> dozeServiceHostProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<ScreenPinningRequest> screenPinningRequestProvider;

  private final Provider<DozeScrimController> dozeScrimControllerProvider;

  private final Provider<VolumeComponent> volumeComponentProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<CollapsedStatusBarFragmentLogger> collapsedStatusBarFragmentLoggerProvider;

  private final Provider<StatusBarComponent.Factory> statusBarComponentFactoryProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  private final Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider;

  private final Provider<LightsOutNotifController> lightsOutNotifControllerProvider;

  private final Provider<StatusBarNotificationActivityStarter.Builder> statusBarNotificationActivityStarterBuilderProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  private final Provider<ViewMediatorCallback> viewMediatorCallbackProvider;

  private final Provider<InitController> initControllerProvider;

  private final Provider<Handler> timeTickHandlerProvider;

  private final Provider<PluginDependencyProvider> pluginDependencyProvider;

  private final Provider<KeyguardDismissUtil> keyguardDismissUtilProvider;

  private final Provider<ExtensionController> extensionControllerProvider;

  private final Provider<UserInfoControllerImpl> userInfoControllerImplProvider;

  private final Provider<OperatorNameViewController.Factory> operatorNameViewControllerFactoryProvider;

  private final Provider<PhoneStatusBarPolicy> phoneStatusBarPolicyProvider;

  private final Provider<KeyguardIndicationController> keyguardIndicationControllerProvider;

  private final Provider<DemoModeController> demoModeControllerProvider;

  private final Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider;

  private final Provider<StatusBarTouchableRegionManager> statusBarTouchableRegionManagerProvider;

  private final Provider<NotificationIconAreaController> notificationIconAreaControllerProvider;

  private final Provider<BrightnessSliderController.Factory> brightnessSliderFactoryProvider;

  private final Provider<WiredChargingRippleController> chargingRippleAnimationControllerProvider;

  private final Provider<WallpaperController> wallpaperControllerProvider;

  private final Provider<OngoingCallController> ongoingCallControllerProvider;

  private final Provider<SystemStatusAnimationScheduler> animationSchedulerProvider;

  private final Provider<StatusBarLocationPublisher> locationPublisherProvider;

  private final Provider<StatusBarIconController> statusBarIconControllerProvider;

  private final Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider;

  private final Provider<LockscreenShadeTransitionController> transitionControllerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  private final Provider<MessageRouter> messageRouterProvider;

  private final Provider<WallpaperManager> wallpaperManagerProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  private final Provider<Optional<StartingSurface>> startingSurfaceOptionalProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<ActivityLaunchAnimator> activityLaunchAnimatorProvider;

  public StatusBarPhoneModule_ProvideStatusBarFactory(Provider<Context> contextProvider,
      Provider<NotificationsController> notificationsControllerProvider,
      Provider<FragmentService> fragmentServiceProvider,
      Provider<LightBarController> lightBarControllerProvider,
      Provider<AutoHideController> autoHideControllerProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<StatusBarSignalPolicy> statusBarSignalPolicyProvider,
      Provider<PulseExpansionHandler> pulseExpansionHandlerProvider,
      Provider<NotificationWakeUpCoordinator> notificationWakeUpCoordinatorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerPhoneProvider,
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<BypassHeadsUpNotifier> bypassHeadsUpNotifierProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<NotifShadeEventSource> notifShadeEventSourceProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotificationGutsManager> notificationGutsManagerProvider,
      Provider<NotificationLogger> notificationLoggerProvider,
      Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider,
      Provider<NotificationViewHierarchyManager> notificationViewHierarchyManagerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<DisplayMetrics> displayMetricsProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<Executor> uiBgExecutorProvider,
      Provider<NotificationMediaManager> notificationMediaManagerProvider,
      Provider<NotificationLockscreenUserManager> lockScreenUserManagerProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<NavigationBarController> navigationBarControllerProvider,
      Provider<AccessibilityFloatingMenuController> accessibilityFloatingMenuControllerProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<ScrimController> scrimControllerProvider,
      Provider<LockscreenWallpaper> lockscreenWallpaperLazyProvider,
      Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerLazyProvider,
      Provider<DozeServiceHost> dozeServiceHostProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<ScreenPinningRequest> screenPinningRequestProvider,
      Provider<DozeScrimController> dozeScrimControllerProvider,
      Provider<VolumeComponent> volumeComponentProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<CollapsedStatusBarFragmentLogger> collapsedStatusBarFragmentLoggerProvider,
      Provider<StatusBarComponent.Factory> statusBarComponentFactoryProvider,
      Provider<PluginManager> pluginManagerProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider,
      Provider<LightsOutNotifController> lightsOutNotifControllerProvider,
      Provider<StatusBarNotificationActivityStarter.Builder> statusBarNotificationActivityStarterBuilderProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<ViewMediatorCallback> viewMediatorCallbackProvider,
      Provider<InitController> initControllerProvider, Provider<Handler> timeTickHandlerProvider,
      Provider<PluginDependencyProvider> pluginDependencyProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<ExtensionController> extensionControllerProvider,
      Provider<UserInfoControllerImpl> userInfoControllerImplProvider,
      Provider<OperatorNameViewController.Factory> operatorNameViewControllerFactoryProvider,
      Provider<PhoneStatusBarPolicy> phoneStatusBarPolicyProvider,
      Provider<KeyguardIndicationController> keyguardIndicationControllerProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider,
      Provider<StatusBarTouchableRegionManager> statusBarTouchableRegionManagerProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<BrightnessSliderController.Factory> brightnessSliderFactoryProvider,
      Provider<WiredChargingRippleController> chargingRippleAnimationControllerProvider,
      Provider<WallpaperController> wallpaperControllerProvider,
      Provider<OngoingCallController> ongoingCallControllerProvider,
      Provider<SystemStatusAnimationScheduler> animationSchedulerProvider,
      Provider<StatusBarLocationPublisher> locationPublisherProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider,
      Provider<LockscreenShadeTransitionController> transitionControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider,
      Provider<Handler> mainHandlerProvider, Provider<DelayableExecutor> delayableExecutorProvider,
      Provider<MessageRouter> messageRouterProvider,
      Provider<WallpaperManager> wallpaperManagerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<Optional<StartingSurface>> startingSurfaceOptionalProvider,
      Provider<TunerService> tunerServiceProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<ActivityLaunchAnimator> activityLaunchAnimatorProvider) {
    this.contextProvider = contextProvider;
    this.notificationsControllerProvider = notificationsControllerProvider;
    this.fragmentServiceProvider = fragmentServiceProvider;
    this.lightBarControllerProvider = lightBarControllerProvider;
    this.autoHideControllerProvider = autoHideControllerProvider;
    this.statusBarWindowControllerProvider = statusBarWindowControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.statusBarSignalPolicyProvider = statusBarSignalPolicyProvider;
    this.pulseExpansionHandlerProvider = pulseExpansionHandlerProvider;
    this.notificationWakeUpCoordinatorProvider = notificationWakeUpCoordinatorProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.headsUpManagerPhoneProvider = headsUpManagerPhoneProvider;
    this.dynamicPrivacyControllerProvider = dynamicPrivacyControllerProvider;
    this.bypassHeadsUpNotifierProvider = bypassHeadsUpNotifierProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.notifShadeEventSourceProvider = notifShadeEventSourceProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.notificationGutsManagerProvider = notificationGutsManagerProvider;
    this.notificationLoggerProvider = notificationLoggerProvider;
    this.notificationInterruptStateProvider = notificationInterruptStateProvider;
    this.notificationViewHierarchyManagerProvider = notificationViewHierarchyManagerProvider;
    this.panelExpansionStateManagerProvider = panelExpansionStateManagerProvider;
    this.keyguardViewMediatorProvider = keyguardViewMediatorProvider;
    this.displayMetricsProvider = displayMetricsProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.uiBgExecutorProvider = uiBgExecutorProvider;
    this.notificationMediaManagerProvider = notificationMediaManagerProvider;
    this.lockScreenUserManagerProvider = lockScreenUserManagerProvider;
    this.remoteInputManagerProvider = remoteInputManagerProvider;
    this.userSwitcherControllerProvider = userSwitcherControllerProvider;
    this.networkControllerProvider = networkControllerProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.colorExtractorProvider = colorExtractorProvider;
    this.screenLifecycleProvider = screenLifecycleProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.bubblesManagerOptionalProvider = bubblesManagerOptionalProvider;
    this.bubblesOptionalProvider = bubblesOptionalProvider;
    this.visualStabilityManagerProvider = visualStabilityManagerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.navigationBarControllerProvider = navigationBarControllerProvider;
    this.accessibilityFloatingMenuControllerProvider = accessibilityFloatingMenuControllerProvider;
    this.assistManagerLazyProvider = assistManagerLazyProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.scrimControllerProvider = scrimControllerProvider;
    this.lockscreenWallpaperLazyProvider = lockscreenWallpaperLazyProvider;
    this.lockscreenGestureLoggerProvider = lockscreenGestureLoggerProvider;
    this.biometricUnlockControllerLazyProvider = biometricUnlockControllerLazyProvider;
    this.dozeServiceHostProvider = dozeServiceHostProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.screenPinningRequestProvider = screenPinningRequestProvider;
    this.dozeScrimControllerProvider = dozeScrimControllerProvider;
    this.volumeComponentProvider = volumeComponentProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.collapsedStatusBarFragmentLoggerProvider = collapsedStatusBarFragmentLoggerProvider;
    this.statusBarComponentFactoryProvider = statusBarComponentFactoryProvider;
    this.pluginManagerProvider = pluginManagerProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.lightsOutNotifControllerProvider = lightsOutNotifControllerProvider;
    this.statusBarNotificationActivityStarterBuilderProvider = statusBarNotificationActivityStarterBuilderProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
    this.viewMediatorCallbackProvider = viewMediatorCallbackProvider;
    this.initControllerProvider = initControllerProvider;
    this.timeTickHandlerProvider = timeTickHandlerProvider;
    this.pluginDependencyProvider = pluginDependencyProvider;
    this.keyguardDismissUtilProvider = keyguardDismissUtilProvider;
    this.extensionControllerProvider = extensionControllerProvider;
    this.userInfoControllerImplProvider = userInfoControllerImplProvider;
    this.operatorNameViewControllerFactoryProvider = operatorNameViewControllerFactoryProvider;
    this.phoneStatusBarPolicyProvider = phoneStatusBarPolicyProvider;
    this.keyguardIndicationControllerProvider = keyguardIndicationControllerProvider;
    this.demoModeControllerProvider = demoModeControllerProvider;
    this.notificationShadeDepthControllerProvider = notificationShadeDepthControllerProvider;
    this.statusBarTouchableRegionManagerProvider = statusBarTouchableRegionManagerProvider;
    this.notificationIconAreaControllerProvider = notificationIconAreaControllerProvider;
    this.brightnessSliderFactoryProvider = brightnessSliderFactoryProvider;
    this.chargingRippleAnimationControllerProvider = chargingRippleAnimationControllerProvider;
    this.wallpaperControllerProvider = wallpaperControllerProvider;
    this.ongoingCallControllerProvider = ongoingCallControllerProvider;
    this.animationSchedulerProvider = animationSchedulerProvider;
    this.locationPublisherProvider = locationPublisherProvider;
    this.statusBarIconControllerProvider = statusBarIconControllerProvider;
    this.statusBarHideIconsForBouncerManagerProvider = statusBarHideIconsForBouncerManagerProvider;
    this.transitionControllerProvider = transitionControllerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.keyguardUnlockAnimationControllerProvider = keyguardUnlockAnimationControllerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
    this.messageRouterProvider = messageRouterProvider;
    this.wallpaperManagerProvider = wallpaperManagerProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
    this.startingSurfaceOptionalProvider = startingSurfaceOptionalProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.activityLaunchAnimatorProvider = activityLaunchAnimatorProvider;
  }

  @Override
  public StatusBar get() {
    return provideStatusBar(contextProvider.get(), notificationsControllerProvider.get(), fragmentServiceProvider.get(), lightBarControllerProvider.get(), autoHideControllerProvider.get(), statusBarWindowControllerProvider.get(), keyguardUpdateMonitorProvider.get(), statusBarSignalPolicyProvider.get(), pulseExpansionHandlerProvider.get(), notificationWakeUpCoordinatorProvider.get(), keyguardBypassControllerProvider.get(), keyguardStateControllerProvider.get(), headsUpManagerPhoneProvider.get(), dynamicPrivacyControllerProvider.get(), bypassHeadsUpNotifierProvider.get(), falsingManagerProvider.get(), falsingCollectorProvider.get(), broadcastDispatcherProvider.get(), notifShadeEventSourceProvider.get(), notificationEntryManagerProvider.get(), notificationGutsManagerProvider.get(), notificationLoggerProvider.get(), notificationInterruptStateProvider.get(), notificationViewHierarchyManagerProvider.get(), panelExpansionStateManagerProvider.get(), keyguardViewMediatorProvider.get(), displayMetricsProvider.get(), metricsLoggerProvider.get(), uiBgExecutorProvider.get(), notificationMediaManagerProvider.get(), lockScreenUserManagerProvider.get(), remoteInputManagerProvider.get(), userSwitcherControllerProvider.get(), networkControllerProvider.get(), batteryControllerProvider.get(), colorExtractorProvider.get(), screenLifecycleProvider.get(), wakefulnessLifecycleProvider.get(), statusBarStateControllerProvider.get(), bubblesManagerOptionalProvider.get(), bubblesOptionalProvider.get(), visualStabilityManagerProvider.get(), deviceProvisionedControllerProvider.get(), navigationBarControllerProvider.get(), accessibilityFloatingMenuControllerProvider.get(), DoubleCheck.lazy(assistManagerLazyProvider), configurationControllerProvider.get(), notificationShadeWindowControllerProvider.get(), dozeParametersProvider.get(), scrimControllerProvider.get(), DoubleCheck.lazy(lockscreenWallpaperLazyProvider), lockscreenGestureLoggerProvider.get(), DoubleCheck.lazy(biometricUnlockControllerLazyProvider), dozeServiceHostProvider.get(), powerManagerProvider.get(), screenPinningRequestProvider.get(), dozeScrimControllerProvider.get(), volumeComponentProvider.get(), commandQueueProvider.get(), collapsedStatusBarFragmentLoggerProvider.get(), statusBarComponentFactoryProvider.get(), pluginManagerProvider.get(), splitScreenOptionalProvider.get(), lightsOutNotifControllerProvider.get(), statusBarNotificationActivityStarterBuilderProvider.get(), shadeControllerProvider.get(), statusBarKeyguardViewManagerProvider.get(), viewMediatorCallbackProvider.get(), initControllerProvider.get(), timeTickHandlerProvider.get(), pluginDependencyProvider.get(), keyguardDismissUtilProvider.get(), extensionControllerProvider.get(), userInfoControllerImplProvider.get(), operatorNameViewControllerFactoryProvider.get(), phoneStatusBarPolicyProvider.get(), keyguardIndicationControllerProvider.get(), demoModeControllerProvider.get(), DoubleCheck.lazy(notificationShadeDepthControllerProvider), statusBarTouchableRegionManagerProvider.get(), notificationIconAreaControllerProvider.get(), brightnessSliderFactoryProvider.get(), chargingRippleAnimationControllerProvider.get(), wallpaperControllerProvider.get(), ongoingCallControllerProvider.get(), animationSchedulerProvider.get(), locationPublisherProvider.get(), statusBarIconControllerProvider.get(), statusBarHideIconsForBouncerManagerProvider.get(), transitionControllerProvider.get(), featureFlagsProvider.get(), keyguardUnlockAnimationControllerProvider.get(), mainHandlerProvider.get(), delayableExecutorProvider.get(), messageRouterProvider.get(), wallpaperManagerProvider.get(), unlockedScreenOffAnimationControllerProvider.get(), startingSurfaceOptionalProvider.get(), tunerServiceProvider.get(), dumpManagerProvider.get(), activityLaunchAnimatorProvider.get());
  }

  public static StatusBarPhoneModule_ProvideStatusBarFactory create(
      Provider<Context> contextProvider,
      Provider<NotificationsController> notificationsControllerProvider,
      Provider<FragmentService> fragmentServiceProvider,
      Provider<LightBarController> lightBarControllerProvider,
      Provider<AutoHideController> autoHideControllerProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<StatusBarSignalPolicy> statusBarSignalPolicyProvider,
      Provider<PulseExpansionHandler> pulseExpansionHandlerProvider,
      Provider<NotificationWakeUpCoordinator> notificationWakeUpCoordinatorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerPhoneProvider,
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<BypassHeadsUpNotifier> bypassHeadsUpNotifierProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<NotifShadeEventSource> notifShadeEventSourceProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotificationGutsManager> notificationGutsManagerProvider,
      Provider<NotificationLogger> notificationLoggerProvider,
      Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider,
      Provider<NotificationViewHierarchyManager> notificationViewHierarchyManagerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<DisplayMetrics> displayMetricsProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<Executor> uiBgExecutorProvider,
      Provider<NotificationMediaManager> notificationMediaManagerProvider,
      Provider<NotificationLockscreenUserManager> lockScreenUserManagerProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<NavigationBarController> navigationBarControllerProvider,
      Provider<AccessibilityFloatingMenuController> accessibilityFloatingMenuControllerProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<ScrimController> scrimControllerProvider,
      Provider<LockscreenWallpaper> lockscreenWallpaperLazyProvider,
      Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerLazyProvider,
      Provider<DozeServiceHost> dozeServiceHostProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<ScreenPinningRequest> screenPinningRequestProvider,
      Provider<DozeScrimController> dozeScrimControllerProvider,
      Provider<VolumeComponent> volumeComponentProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<CollapsedStatusBarFragmentLogger> collapsedStatusBarFragmentLoggerProvider,
      Provider<StatusBarComponent.Factory> statusBarComponentFactoryProvider,
      Provider<PluginManager> pluginManagerProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider,
      Provider<LightsOutNotifController> lightsOutNotifControllerProvider,
      Provider<StatusBarNotificationActivityStarter.Builder> statusBarNotificationActivityStarterBuilderProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<ViewMediatorCallback> viewMediatorCallbackProvider,
      Provider<InitController> initControllerProvider, Provider<Handler> timeTickHandlerProvider,
      Provider<PluginDependencyProvider> pluginDependencyProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<ExtensionController> extensionControllerProvider,
      Provider<UserInfoControllerImpl> userInfoControllerImplProvider,
      Provider<OperatorNameViewController.Factory> operatorNameViewControllerFactoryProvider,
      Provider<PhoneStatusBarPolicy> phoneStatusBarPolicyProvider,
      Provider<KeyguardIndicationController> keyguardIndicationControllerProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider,
      Provider<StatusBarTouchableRegionManager> statusBarTouchableRegionManagerProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<BrightnessSliderController.Factory> brightnessSliderFactoryProvider,
      Provider<WiredChargingRippleController> chargingRippleAnimationControllerProvider,
      Provider<WallpaperController> wallpaperControllerProvider,
      Provider<OngoingCallController> ongoingCallControllerProvider,
      Provider<SystemStatusAnimationScheduler> animationSchedulerProvider,
      Provider<StatusBarLocationPublisher> locationPublisherProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider,
      Provider<LockscreenShadeTransitionController> transitionControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider,
      Provider<Handler> mainHandlerProvider, Provider<DelayableExecutor> delayableExecutorProvider,
      Provider<MessageRouter> messageRouterProvider,
      Provider<WallpaperManager> wallpaperManagerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<Optional<StartingSurface>> startingSurfaceOptionalProvider,
      Provider<TunerService> tunerServiceProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<ActivityLaunchAnimator> activityLaunchAnimatorProvider) {
    return new StatusBarPhoneModule_ProvideStatusBarFactory(contextProvider, notificationsControllerProvider, fragmentServiceProvider, lightBarControllerProvider, autoHideControllerProvider, statusBarWindowControllerProvider, keyguardUpdateMonitorProvider, statusBarSignalPolicyProvider, pulseExpansionHandlerProvider, notificationWakeUpCoordinatorProvider, keyguardBypassControllerProvider, keyguardStateControllerProvider, headsUpManagerPhoneProvider, dynamicPrivacyControllerProvider, bypassHeadsUpNotifierProvider, falsingManagerProvider, falsingCollectorProvider, broadcastDispatcherProvider, notifShadeEventSourceProvider, notificationEntryManagerProvider, notificationGutsManagerProvider, notificationLoggerProvider, notificationInterruptStateProvider, notificationViewHierarchyManagerProvider, panelExpansionStateManagerProvider, keyguardViewMediatorProvider, displayMetricsProvider, metricsLoggerProvider, uiBgExecutorProvider, notificationMediaManagerProvider, lockScreenUserManagerProvider, remoteInputManagerProvider, userSwitcherControllerProvider, networkControllerProvider, batteryControllerProvider, colorExtractorProvider, screenLifecycleProvider, wakefulnessLifecycleProvider, statusBarStateControllerProvider, bubblesManagerOptionalProvider, bubblesOptionalProvider, visualStabilityManagerProvider, deviceProvisionedControllerProvider, navigationBarControllerProvider, accessibilityFloatingMenuControllerProvider, assistManagerLazyProvider, configurationControllerProvider, notificationShadeWindowControllerProvider, dozeParametersProvider, scrimControllerProvider, lockscreenWallpaperLazyProvider, lockscreenGestureLoggerProvider, biometricUnlockControllerLazyProvider, dozeServiceHostProvider, powerManagerProvider, screenPinningRequestProvider, dozeScrimControllerProvider, volumeComponentProvider, commandQueueProvider, collapsedStatusBarFragmentLoggerProvider, statusBarComponentFactoryProvider, pluginManagerProvider, splitScreenOptionalProvider, lightsOutNotifControllerProvider, statusBarNotificationActivityStarterBuilderProvider, shadeControllerProvider, statusBarKeyguardViewManagerProvider, viewMediatorCallbackProvider, initControllerProvider, timeTickHandlerProvider, pluginDependencyProvider, keyguardDismissUtilProvider, extensionControllerProvider, userInfoControllerImplProvider, operatorNameViewControllerFactoryProvider, phoneStatusBarPolicyProvider, keyguardIndicationControllerProvider, demoModeControllerProvider, notificationShadeDepthControllerProvider, statusBarTouchableRegionManagerProvider, notificationIconAreaControllerProvider, brightnessSliderFactoryProvider, chargingRippleAnimationControllerProvider, wallpaperControllerProvider, ongoingCallControllerProvider, animationSchedulerProvider, locationPublisherProvider, statusBarIconControllerProvider, statusBarHideIconsForBouncerManagerProvider, transitionControllerProvider, featureFlagsProvider, keyguardUnlockAnimationControllerProvider, mainHandlerProvider, delayableExecutorProvider, messageRouterProvider, wallpaperManagerProvider, unlockedScreenOffAnimationControllerProvider, startingSurfaceOptionalProvider, tunerServiceProvider, dumpManagerProvider, activityLaunchAnimatorProvider);
  }

  public static StatusBar provideStatusBar(Context context,
      NotificationsController notificationsController, FragmentService fragmentService,
      LightBarController lightBarController, AutoHideController autoHideController,
      StatusBarWindowController statusBarWindowController,
      KeyguardUpdateMonitor keyguardUpdateMonitor, StatusBarSignalPolicy statusBarSignalPolicy,
      PulseExpansionHandler pulseExpansionHandler,
      NotificationWakeUpCoordinator notificationWakeUpCoordinator,
      KeyguardBypassController keyguardBypassController,
      KeyguardStateController keyguardStateController, HeadsUpManagerPhone headsUpManagerPhone,
      DynamicPrivacyController dynamicPrivacyController,
      BypassHeadsUpNotifier bypassHeadsUpNotifier, FalsingManager falsingManager,
      FalsingCollector falsingCollector, BroadcastDispatcher broadcastDispatcher,
      NotifShadeEventSource notifShadeEventSource,
      NotificationEntryManager notificationEntryManager,
      NotificationGutsManager notificationGutsManager, NotificationLogger notificationLogger,
      NotificationInterruptStateProvider notificationInterruptStateProvider,
      NotificationViewHierarchyManager notificationViewHierarchyManager,
      PanelExpansionStateManager panelExpansionStateManager,
      KeyguardViewMediator keyguardViewMediator, DisplayMetrics displayMetrics,
      MetricsLogger metricsLogger, Executor uiBgExecutor,
      NotificationMediaManager notificationMediaManager,
      NotificationLockscreenUserManager lockScreenUserManager,
      NotificationRemoteInputManager remoteInputManager,
      UserSwitcherController userSwitcherController, NetworkController networkController,
      BatteryController batteryController, SysuiColorExtractor colorExtractor,
      ScreenLifecycle screenLifecycle, WakefulnessLifecycle wakefulnessLifecycle,
      SysuiStatusBarStateController statusBarStateController,
      Optional<BubblesManager> bubblesManagerOptional, Optional<Bubbles> bubblesOptional,
      VisualStabilityManager visualStabilityManager,
      DeviceProvisionedController deviceProvisionedController,
      NavigationBarController navigationBarController,
      AccessibilityFloatingMenuController accessibilityFloatingMenuController,
      Lazy<AssistManager> assistManagerLazy, ConfigurationController configurationController,
      NotificationShadeWindowController notificationShadeWindowController,
      DozeParameters dozeParameters, ScrimController scrimController,
      Lazy<LockscreenWallpaper> lockscreenWallpaperLazy,
      LockscreenGestureLogger lockscreenGestureLogger,
      Lazy<BiometricUnlockController> biometricUnlockControllerLazy,
      DozeServiceHost dozeServiceHost, PowerManager powerManager,
      ScreenPinningRequest screenPinningRequest, DozeScrimController dozeScrimController,
      VolumeComponent volumeComponent, CommandQueue commandQueue,
      CollapsedStatusBarFragmentLogger collapsedStatusBarFragmentLogger,
      StatusBarComponent.Factory statusBarComponentFactory, PluginManager pluginManager,
      Optional<LegacySplitScreen> splitScreenOptional,
      LightsOutNotifController lightsOutNotifController,
      StatusBarNotificationActivityStarter.Builder statusBarNotificationActivityStarterBuilder,
      ShadeController shadeController, StatusBarKeyguardViewManager statusBarKeyguardViewManager,
      ViewMediatorCallback viewMediatorCallback, InitController initController,
      Handler timeTickHandler, PluginDependencyProvider pluginDependencyProvider,
      KeyguardDismissUtil keyguardDismissUtil, ExtensionController extensionController,
      UserInfoControllerImpl userInfoControllerImpl,
      OperatorNameViewController.Factory operatorNameViewControllerFactory,
      PhoneStatusBarPolicy phoneStatusBarPolicy,
      KeyguardIndicationController keyguardIndicationController,
      DemoModeController demoModeController,
      Lazy<NotificationShadeDepthController> notificationShadeDepthController,
      StatusBarTouchableRegionManager statusBarTouchableRegionManager,
      NotificationIconAreaController notificationIconAreaController,
      BrightnessSliderController.Factory brightnessSliderFactory,
      WiredChargingRippleController chargingRippleAnimationController,
      WallpaperController wallpaperController, OngoingCallController ongoingCallController,
      SystemStatusAnimationScheduler animationScheduler,
      StatusBarLocationPublisher locationPublisher, StatusBarIconController statusBarIconController,
      StatusBarHideIconsForBouncerManager statusBarHideIconsForBouncerManager,
      LockscreenShadeTransitionController transitionController, FeatureFlags featureFlags,
      KeyguardUnlockAnimationController keyguardUnlockAnimationController, Handler mainHandler,
      DelayableExecutor delayableExecutor, MessageRouter messageRouter,
      WallpaperManager wallpaperManager,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController,
      Optional<StartingSurface> startingSurfaceOptional, TunerService tunerService,
      DumpManager dumpManager, ActivityLaunchAnimator activityLaunchAnimator) {
    return Preconditions.checkNotNullFromProvides(StatusBarPhoneModule.provideStatusBar(context, notificationsController, fragmentService, lightBarController, autoHideController, statusBarWindowController, keyguardUpdateMonitor, statusBarSignalPolicy, pulseExpansionHandler, notificationWakeUpCoordinator, keyguardBypassController, keyguardStateController, headsUpManagerPhone, dynamicPrivacyController, bypassHeadsUpNotifier, falsingManager, falsingCollector, broadcastDispatcher, notifShadeEventSource, notificationEntryManager, notificationGutsManager, notificationLogger, notificationInterruptStateProvider, notificationViewHierarchyManager, panelExpansionStateManager, keyguardViewMediator, displayMetrics, metricsLogger, uiBgExecutor, notificationMediaManager, lockScreenUserManager, remoteInputManager, userSwitcherController, networkController, batteryController, colorExtractor, screenLifecycle, wakefulnessLifecycle, statusBarStateController, bubblesManagerOptional, bubblesOptional, visualStabilityManager, deviceProvisionedController, navigationBarController, accessibilityFloatingMenuController, assistManagerLazy, configurationController, notificationShadeWindowController, dozeParameters, scrimController, lockscreenWallpaperLazy, lockscreenGestureLogger, biometricUnlockControllerLazy, dozeServiceHost, powerManager, screenPinningRequest, dozeScrimController, volumeComponent, commandQueue, collapsedStatusBarFragmentLogger, statusBarComponentFactory, pluginManager, splitScreenOptional, lightsOutNotifController, statusBarNotificationActivityStarterBuilder, shadeController, statusBarKeyguardViewManager, viewMediatorCallback, initController, timeTickHandler, pluginDependencyProvider, keyguardDismissUtil, extensionController, userInfoControllerImpl, operatorNameViewControllerFactory, phoneStatusBarPolicy, keyguardIndicationController, demoModeController, notificationShadeDepthController, statusBarTouchableRegionManager, notificationIconAreaController, brightnessSliderFactory, chargingRippleAnimationController, wallpaperController, ongoingCallController, animationScheduler, locationPublisher, statusBarIconController, statusBarHideIconsForBouncerManager, transitionController, featureFlags, keyguardUnlockAnimationController, mainHandler, delayableExecutor, messageRouter, wallpaperManager, unlockedScreenOffAnimationController, startingSurfaceOptional, tunerService, dumpManager, activityLaunchAnimator));
  }
}

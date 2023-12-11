package com.android.systemui.statusbar.phone;

import android.app.ActivityManager;
import android.content.ContentResolver;
import android.content.Context;
import android.content.res.Resources;
import android.os.Handler;
import android.os.PowerManager;
import android.os.UserManager;
import android.view.LayoutInflater;
import android.view.accessibility.AccessibilityManager;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.util.LatencyTracker;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.keyguard.LockIconViewController;
import com.android.keyguard.dagger.KeyguardQsUserSwitchComponent;
import com.android.keyguard.dagger.KeyguardStatusBarViewComponent;
import com.android.keyguard.dagger.KeyguardStatusViewComponent;
import com.android.keyguard.dagger.KeyguardUserSwitcherComponent;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.controls.dagger.ControlsComponent;
import com.android.systemui.doze.DozeLog;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.fragments.FragmentService;
import com.android.systemui.media.KeyguardMediaController;
import com.android.systemui.media.MediaDataManager;
import com.android.systemui.media.MediaHierarchyManager;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSDetailDisplayer;
import com.android.systemui.screenrecord.RecordingController;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.LockscreenShadeTransitionController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.NotificationShadeDepthController;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.PulseExpansionHandler;
import com.android.systemui.statusbar.VibratorHelper;
import com.android.systemui.statusbar.events.PrivacyDotViewController;
import com.android.systemui.statusbar.notification.ConversationNotificationManager;
import com.android.systemui.statusbar.notification.DynamicPrivacyController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.stack.AmbientState;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionStateManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.unfold.SysUIUnfoldComponent;
import com.android.systemui.util.settings.SecureSettings;
import com.android.systemui.wallet.controller.QuickAccessWalletController;
import com.android.wm.shell.animation.FlingAnimationUtils;
import dagger.internal.Factory;
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
public final class NotificationPanelViewController_Factory implements Factory<NotificationPanelViewController> {
  private final Provider<NotificationPanelView> viewProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<NotificationWakeUpCoordinator> coordinatorProvider;

  private final Provider<PulseExpansionHandler> pulseExpansionHandlerProvider;

  private final Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<DozeLog> dozeLogProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<VibratorHelper> vibratorHelperProvider;

  private final Provider<LatencyTracker> latencyTrackerProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  private final Provider<Integer> displayIdProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<ActivityManager> activityManagerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<FlingAnimationUtils.Builder> flingAnimationUtilsBuilderProvider;

  private final Provider<StatusBarTouchableRegionManager> statusBarTouchableRegionManagerProvider;

  private final Provider<ConversationNotificationManager> conversationNotificationManagerProvider;

  private final Provider<MediaHierarchyManager> mediaHierarchyManagerProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  private final Provider<NotificationsQSContainerController> notificationsQSContainerControllerProvider;

  private final Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider;

  private final Provider<KeyguardStatusViewComponent.Factory> keyguardStatusViewComponentFactoryProvider;

  private final Provider<KeyguardQsUserSwitchComponent.Factory> keyguardQsUserSwitchComponentFactoryProvider;

  private final Provider<KeyguardUserSwitcherComponent.Factory> keyguardUserSwitcherComponentFactoryProvider;

  private final Provider<KeyguardStatusBarViewComponent.Factory> keyguardStatusBarViewComponentFactoryProvider;

  private final Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider;

  private final Provider<QSDetailDisplayer> qsDetailDisplayerProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerProvider;

  private final Provider<NotificationIconAreaController> notificationIconAreaControllerProvider;

  private final Provider<AuthController> authControllerProvider;

  private final Provider<ScrimController> scrimControllerProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<MediaDataManager> mediaDataManagerProvider;

  private final Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider;

  private final Provider<AmbientState> ambientStateProvider;

  private final Provider<LockIconViewController> lockIconViewControllerProvider;

  private final Provider<KeyguardMediaController> keyguardMediaControllerProvider;

  private final Provider<PrivacyDotViewController> privacyDotViewControllerProvider;

  private final Provider<TapAgainViewController> tapAgainViewControllerProvider;

  private final Provider<NavigationModeController> navigationModeControllerProvider;

  private final Provider<FragmentService> fragmentServiceProvider;

  private final Provider<ContentResolver> contentResolverProvider;

  private final Provider<QuickAccessWalletController> quickAccessWalletControllerProvider;

  private final Provider<RecordingController> recordingControllerProvider;

  private final Provider<Executor> uiExecutorProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<SplitShadeHeaderController> splitShadeHeaderControllerProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  private final Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider;

  private final Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider;

  private final Provider<NotificationRemoteInputManager> remoteInputManagerProvider;

  private final Provider<Optional<SysUIUnfoldComponent>> unfoldComponentProvider;

  private final Provider<ControlsComponent> controlsComponentProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<Context> contextProvider;

  public NotificationPanelViewController_Factory(Provider<NotificationPanelView> viewProvider,
      Provider<Resources> resourcesProvider, Provider<Handler> handlerProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<NotificationWakeUpCoordinator> coordinatorProvider,
      Provider<PulseExpansionHandler> pulseExpansionHandlerProvider,
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<DozeLog> dozeLogProvider, Provider<DozeParameters> dozeParametersProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<VibratorHelper> vibratorHelperProvider,
      Provider<LatencyTracker> latencyTrackerProvider, Provider<PowerManager> powerManagerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<Integer> displayIdProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<ActivityManager> activityManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FlingAnimationUtils.Builder> flingAnimationUtilsBuilderProvider,
      Provider<StatusBarTouchableRegionManager> statusBarTouchableRegionManagerProvider,
      Provider<ConversationNotificationManager> conversationNotificationManagerProvider,
      Provider<MediaHierarchyManager> mediaHierarchyManagerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<NotificationsQSContainerController> notificationsQSContainerControllerProvider,
      Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider,
      Provider<KeyguardStatusViewComponent.Factory> keyguardStatusViewComponentFactoryProvider,
      Provider<KeyguardQsUserSwitchComponent.Factory> keyguardQsUserSwitchComponentFactoryProvider,
      Provider<KeyguardUserSwitcherComponent.Factory> keyguardUserSwitcherComponentFactoryProvider,
      Provider<KeyguardStatusBarViewComponent.Factory> keyguardStatusBarViewComponentFactoryProvider,
      Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider,
      Provider<QSDetailDisplayer> qsDetailDisplayerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<AuthController> authControllerProvider,
      Provider<ScrimController> scrimControllerProvider, Provider<UserManager> userManagerProvider,
      Provider<MediaDataManager> mediaDataManagerProvider,
      Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider,
      Provider<AmbientState> ambientStateProvider,
      Provider<LockIconViewController> lockIconViewControllerProvider,
      Provider<KeyguardMediaController> keyguardMediaControllerProvider,
      Provider<PrivacyDotViewController> privacyDotViewControllerProvider,
      Provider<TapAgainViewController> tapAgainViewControllerProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<FragmentService> fragmentServiceProvider,
      Provider<ContentResolver> contentResolverProvider,
      Provider<QuickAccessWalletController> quickAccessWalletControllerProvider,
      Provider<RecordingController> recordingControllerProvider,
      Provider<Executor> uiExecutorProvider, Provider<SecureSettings> secureSettingsProvider,
      Provider<SplitShadeHeaderController> splitShadeHeaderControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<Optional<SysUIUnfoldComponent>> unfoldComponentProvider,
      Provider<ControlsComponent> controlsComponentProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<TunerService> tunerServiceProvider,
      Provider<Context> contextProvider) {
    this.viewProvider = viewProvider;
    this.resourcesProvider = resourcesProvider;
    this.handlerProvider = handlerProvider;
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.coordinatorProvider = coordinatorProvider;
    this.pulseExpansionHandlerProvider = pulseExpansionHandlerProvider;
    this.dynamicPrivacyControllerProvider = dynamicPrivacyControllerProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.notificationLockscreenUserManagerProvider = notificationLockscreenUserManagerProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.dozeLogProvider = dozeLogProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.vibratorHelperProvider = vibratorHelperProvider;
    this.latencyTrackerProvider = latencyTrackerProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.accessibilityManagerProvider = accessibilityManagerProvider;
    this.displayIdProvider = displayIdProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.activityManagerProvider = activityManagerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.flingAnimationUtilsBuilderProvider = flingAnimationUtilsBuilderProvider;
    this.statusBarTouchableRegionManagerProvider = statusBarTouchableRegionManagerProvider;
    this.conversationNotificationManagerProvider = conversationNotificationManagerProvider;
    this.mediaHierarchyManagerProvider = mediaHierarchyManagerProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
    this.notificationsQSContainerControllerProvider = notificationsQSContainerControllerProvider;
    this.notificationStackScrollLayoutControllerProvider = notificationStackScrollLayoutControllerProvider;
    this.keyguardStatusViewComponentFactoryProvider = keyguardStatusViewComponentFactoryProvider;
    this.keyguardQsUserSwitchComponentFactoryProvider = keyguardQsUserSwitchComponentFactoryProvider;
    this.keyguardUserSwitcherComponentFactoryProvider = keyguardUserSwitcherComponentFactoryProvider;
    this.keyguardStatusBarViewComponentFactoryProvider = keyguardStatusBarViewComponentFactoryProvider;
    this.lockscreenShadeTransitionControllerProvider = lockscreenShadeTransitionControllerProvider;
    this.qsDetailDisplayerProvider = qsDetailDisplayerProvider;
    this.groupManagerProvider = groupManagerProvider;
    this.notificationIconAreaControllerProvider = notificationIconAreaControllerProvider;
    this.authControllerProvider = authControllerProvider;
    this.scrimControllerProvider = scrimControllerProvider;
    this.userManagerProvider = userManagerProvider;
    this.mediaDataManagerProvider = mediaDataManagerProvider;
    this.notificationShadeDepthControllerProvider = notificationShadeDepthControllerProvider;
    this.ambientStateProvider = ambientStateProvider;
    this.lockIconViewControllerProvider = lockIconViewControllerProvider;
    this.keyguardMediaControllerProvider = keyguardMediaControllerProvider;
    this.privacyDotViewControllerProvider = privacyDotViewControllerProvider;
    this.tapAgainViewControllerProvider = tapAgainViewControllerProvider;
    this.navigationModeControllerProvider = navigationModeControllerProvider;
    this.fragmentServiceProvider = fragmentServiceProvider;
    this.contentResolverProvider = contentResolverProvider;
    this.quickAccessWalletControllerProvider = quickAccessWalletControllerProvider;
    this.recordingControllerProvider = recordingControllerProvider;
    this.uiExecutorProvider = uiExecutorProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.splitShadeHeaderControllerProvider = splitShadeHeaderControllerProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
    this.lockscreenGestureLoggerProvider = lockscreenGestureLoggerProvider;
    this.panelExpansionStateManagerProvider = panelExpansionStateManagerProvider;
    this.remoteInputManagerProvider = remoteInputManagerProvider;
    this.unfoldComponentProvider = unfoldComponentProvider;
    this.controlsComponentProvider = controlsComponentProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public NotificationPanelViewController get() {
    return newInstance(viewProvider.get(), resourcesProvider.get(), handlerProvider.get(), layoutInflaterProvider.get(), coordinatorProvider.get(), pulseExpansionHandlerProvider.get(), dynamicPrivacyControllerProvider.get(), bypassControllerProvider.get(), falsingManagerProvider.get(), falsingCollectorProvider.get(), notificationLockscreenUserManagerProvider.get(), notificationEntryManagerProvider.get(), keyguardStateControllerProvider.get(), statusBarStateControllerProvider.get(), notificationShadeWindowControllerProvider.get(), dozeLogProvider.get(), dozeParametersProvider.get(), commandQueueProvider.get(), vibratorHelperProvider.get(), latencyTrackerProvider.get(), powerManagerProvider.get(), accessibilityManagerProvider.get(), displayIdProvider.get(), keyguardUpdateMonitorProvider.get(), metricsLoggerProvider.get(), activityManagerProvider.get(), configurationControllerProvider.get(), flingAnimationUtilsBuilderProvider, statusBarTouchableRegionManagerProvider.get(), conversationNotificationManagerProvider.get(), mediaHierarchyManagerProvider.get(), statusBarKeyguardViewManagerProvider.get(), notificationsQSContainerControllerProvider.get(), notificationStackScrollLayoutControllerProvider.get(), keyguardStatusViewComponentFactoryProvider.get(), keyguardQsUserSwitchComponentFactoryProvider.get(), keyguardUserSwitcherComponentFactoryProvider.get(), keyguardStatusBarViewComponentFactoryProvider.get(), lockscreenShadeTransitionControllerProvider.get(), qsDetailDisplayerProvider.get(), groupManagerProvider.get(), notificationIconAreaControllerProvider.get(), authControllerProvider.get(), scrimControllerProvider.get(), userManagerProvider.get(), mediaDataManagerProvider.get(), notificationShadeDepthControllerProvider.get(), ambientStateProvider.get(), lockIconViewControllerProvider.get(), keyguardMediaControllerProvider.get(), privacyDotViewControllerProvider.get(), tapAgainViewControllerProvider.get(), navigationModeControllerProvider.get(), fragmentServiceProvider.get(), contentResolverProvider.get(), quickAccessWalletControllerProvider.get(), recordingControllerProvider.get(), uiExecutorProvider.get(), secureSettingsProvider.get(), splitShadeHeaderControllerProvider.get(), unlockedScreenOffAnimationControllerProvider.get(), lockscreenGestureLoggerProvider.get(), panelExpansionStateManagerProvider.get(), remoteInputManagerProvider.get(), unfoldComponentProvider.get(), controlsComponentProvider.get(), featureFlagsProvider.get(), tunerServiceProvider.get(), contextProvider.get());
  }

  public static NotificationPanelViewController_Factory create(
      Provider<NotificationPanelView> viewProvider, Provider<Resources> resourcesProvider,
      Provider<Handler> handlerProvider, Provider<LayoutInflater> layoutInflaterProvider,
      Provider<NotificationWakeUpCoordinator> coordinatorProvider,
      Provider<PulseExpansionHandler> pulseExpansionHandlerProvider,
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<DozeLog> dozeLogProvider, Provider<DozeParameters> dozeParametersProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<VibratorHelper> vibratorHelperProvider,
      Provider<LatencyTracker> latencyTrackerProvider, Provider<PowerManager> powerManagerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<Integer> displayIdProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<ActivityManager> activityManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FlingAnimationUtils.Builder> flingAnimationUtilsBuilderProvider,
      Provider<StatusBarTouchableRegionManager> statusBarTouchableRegionManagerProvider,
      Provider<ConversationNotificationManager> conversationNotificationManagerProvider,
      Provider<MediaHierarchyManager> mediaHierarchyManagerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<NotificationsQSContainerController> notificationsQSContainerControllerProvider,
      Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider,
      Provider<KeyguardStatusViewComponent.Factory> keyguardStatusViewComponentFactoryProvider,
      Provider<KeyguardQsUserSwitchComponent.Factory> keyguardQsUserSwitchComponentFactoryProvider,
      Provider<KeyguardUserSwitcherComponent.Factory> keyguardUserSwitcherComponentFactoryProvider,
      Provider<KeyguardStatusBarViewComponent.Factory> keyguardStatusBarViewComponentFactoryProvider,
      Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider,
      Provider<QSDetailDisplayer> qsDetailDisplayerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<AuthController> authControllerProvider,
      Provider<ScrimController> scrimControllerProvider, Provider<UserManager> userManagerProvider,
      Provider<MediaDataManager> mediaDataManagerProvider,
      Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider,
      Provider<AmbientState> ambientStateProvider,
      Provider<LockIconViewController> lockIconViewControllerProvider,
      Provider<KeyguardMediaController> keyguardMediaControllerProvider,
      Provider<PrivacyDotViewController> privacyDotViewControllerProvider,
      Provider<TapAgainViewController> tapAgainViewControllerProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<FragmentService> fragmentServiceProvider,
      Provider<ContentResolver> contentResolverProvider,
      Provider<QuickAccessWalletController> quickAccessWalletControllerProvider,
      Provider<RecordingController> recordingControllerProvider,
      Provider<Executor> uiExecutorProvider, Provider<SecureSettings> secureSettingsProvider,
      Provider<SplitShadeHeaderController> splitShadeHeaderControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<Optional<SysUIUnfoldComponent>> unfoldComponentProvider,
      Provider<ControlsComponent> controlsComponentProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<TunerService> tunerServiceProvider,
      Provider<Context> contextProvider) {
    return new NotificationPanelViewController_Factory(viewProvider, resourcesProvider, handlerProvider, layoutInflaterProvider, coordinatorProvider, pulseExpansionHandlerProvider, dynamicPrivacyControllerProvider, bypassControllerProvider, falsingManagerProvider, falsingCollectorProvider, notificationLockscreenUserManagerProvider, notificationEntryManagerProvider, keyguardStateControllerProvider, statusBarStateControllerProvider, notificationShadeWindowControllerProvider, dozeLogProvider, dozeParametersProvider, commandQueueProvider, vibratorHelperProvider, latencyTrackerProvider, powerManagerProvider, accessibilityManagerProvider, displayIdProvider, keyguardUpdateMonitorProvider, metricsLoggerProvider, activityManagerProvider, configurationControllerProvider, flingAnimationUtilsBuilderProvider, statusBarTouchableRegionManagerProvider, conversationNotificationManagerProvider, mediaHierarchyManagerProvider, statusBarKeyguardViewManagerProvider, notificationsQSContainerControllerProvider, notificationStackScrollLayoutControllerProvider, keyguardStatusViewComponentFactoryProvider, keyguardQsUserSwitchComponentFactoryProvider, keyguardUserSwitcherComponentFactoryProvider, keyguardStatusBarViewComponentFactoryProvider, lockscreenShadeTransitionControllerProvider, qsDetailDisplayerProvider, groupManagerProvider, notificationIconAreaControllerProvider, authControllerProvider, scrimControllerProvider, userManagerProvider, mediaDataManagerProvider, notificationShadeDepthControllerProvider, ambientStateProvider, lockIconViewControllerProvider, keyguardMediaControllerProvider, privacyDotViewControllerProvider, tapAgainViewControllerProvider, navigationModeControllerProvider, fragmentServiceProvider, contentResolverProvider, quickAccessWalletControllerProvider, recordingControllerProvider, uiExecutorProvider, secureSettingsProvider, splitShadeHeaderControllerProvider, unlockedScreenOffAnimationControllerProvider, lockscreenGestureLoggerProvider, panelExpansionStateManagerProvider, remoteInputManagerProvider, unfoldComponentProvider, controlsComponentProvider, featureFlagsProvider, tunerServiceProvider, contextProvider);
  }

  public static NotificationPanelViewController newInstance(NotificationPanelView view,
      Resources resources, Handler handler, LayoutInflater layoutInflater,
      NotificationWakeUpCoordinator coordinator, PulseExpansionHandler pulseExpansionHandler,
      DynamicPrivacyController dynamicPrivacyController, KeyguardBypassController bypassController,
      FalsingManager falsingManager, FalsingCollector falsingCollector,
      NotificationLockscreenUserManager notificationLockscreenUserManager,
      NotificationEntryManager notificationEntryManager,
      KeyguardStateController keyguardStateController,
      StatusBarStateController statusBarStateController,
      NotificationShadeWindowController notificationShadeWindowController, DozeLog dozeLog,
      DozeParameters dozeParameters, CommandQueue commandQueue, VibratorHelper vibratorHelper,
      LatencyTracker latencyTracker, PowerManager powerManager,
      AccessibilityManager accessibilityManager, int displayId,
      KeyguardUpdateMonitor keyguardUpdateMonitor, MetricsLogger metricsLogger,
      ActivityManager activityManager, ConfigurationController configurationController,
      Provider<FlingAnimationUtils.Builder> flingAnimationUtilsBuilder,
      StatusBarTouchableRegionManager statusBarTouchableRegionManager,
      ConversationNotificationManager conversationNotificationManager,
      MediaHierarchyManager mediaHierarchyManager,
      StatusBarKeyguardViewManager statusBarKeyguardViewManager,
      NotificationsQSContainerController notificationsQSContainerController,
      NotificationStackScrollLayoutController notificationStackScrollLayoutController,
      KeyguardStatusViewComponent.Factory keyguardStatusViewComponentFactory,
      KeyguardQsUserSwitchComponent.Factory keyguardQsUserSwitchComponentFactory,
      KeyguardUserSwitcherComponent.Factory keyguardUserSwitcherComponentFactory,
      KeyguardStatusBarViewComponent.Factory keyguardStatusBarViewComponentFactory,
      LockscreenShadeTransitionController lockscreenShadeTransitionController,
      QSDetailDisplayer qsDetailDisplayer, NotificationGroupManagerLegacy groupManager,
      NotificationIconAreaController notificationIconAreaController, AuthController authController,
      ScrimController scrimController, UserManager userManager, MediaDataManager mediaDataManager,
      NotificationShadeDepthController notificationShadeDepthController, AmbientState ambientState,
      LockIconViewController lockIconViewController,
      KeyguardMediaController keyguardMediaController,
      PrivacyDotViewController privacyDotViewController,
      TapAgainViewController tapAgainViewController,
      NavigationModeController navigationModeController, FragmentService fragmentService,
      ContentResolver contentResolver, QuickAccessWalletController quickAccessWalletController,
      RecordingController recordingController, Executor uiExecutor, SecureSettings secureSettings,
      SplitShadeHeaderController splitShadeHeaderController,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController,
      LockscreenGestureLogger lockscreenGestureLogger,
      PanelExpansionStateManager panelExpansionStateManager,
      NotificationRemoteInputManager remoteInputManager,
      Optional<SysUIUnfoldComponent> unfoldComponent, ControlsComponent controlsComponent,
      FeatureFlags featureFlags, TunerService tunerService, Context context) {
    return new NotificationPanelViewController(view, resources, handler, layoutInflater, coordinator, pulseExpansionHandler, dynamicPrivacyController, bypassController, falsingManager, falsingCollector, notificationLockscreenUserManager, notificationEntryManager, keyguardStateController, statusBarStateController, notificationShadeWindowController, dozeLog, dozeParameters, commandQueue, vibratorHelper, latencyTracker, powerManager, accessibilityManager, displayId, keyguardUpdateMonitor, metricsLogger, activityManager, configurationController, flingAnimationUtilsBuilder, statusBarTouchableRegionManager, conversationNotificationManager, mediaHierarchyManager, statusBarKeyguardViewManager, notificationsQSContainerController, notificationStackScrollLayoutController, keyguardStatusViewComponentFactory, keyguardQsUserSwitchComponentFactory, keyguardUserSwitcherComponentFactory, keyguardStatusBarViewComponentFactory, lockscreenShadeTransitionController, qsDetailDisplayer, groupManager, notificationIconAreaController, authController, scrimController, userManager, mediaDataManager, notificationShadeDepthController, ambientState, lockIconViewController, keyguardMediaController, privacyDotViewController, tapAgainViewController, navigationModeController, fragmentService, contentResolver, quickAccessWalletController, recordingController, uiExecutor, secureSettings, splitShadeHeaderController, unlockedScreenOffAnimationController, lockscreenGestureLogger, panelExpansionStateManager, remoteInputManager, unfoldComponent, controlsComponent, featureFlags, tunerService, context);
  }
}

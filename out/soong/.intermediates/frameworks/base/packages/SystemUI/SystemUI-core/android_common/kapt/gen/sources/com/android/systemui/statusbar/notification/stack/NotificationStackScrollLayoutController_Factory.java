package com.android.systemui.statusbar.notification.stack;

import android.content.res.Resources;
import android.view.LayoutInflater;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.statusbar.IStatusBarService;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.colorextraction.SysuiColorExtractor;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.media.KeyguardMediaController;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.statusbar.LockscreenShadeTransitionController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.notification.DynamicPrivacyController;
import com.android.systemui.statusbar.notification.ForegroundServiceDismissalFeatureController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifCollection;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.notification.collection.render.GroupExpansionManager;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderController;
import com.android.systemui.statusbar.notification.row.NotificationGutsManager;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.ScrimController;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.ZenModeController;
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
public final class NotificationStackScrollLayoutController_Factory implements Factory<NotificationStackScrollLayoutController> {
  private final Provider<Boolean> allowLongPressProvider;

  private final Provider<NotificationGutsManager> notificationGutsManagerProvider;

  private final Provider<HeadsUpManagerPhone> headsUpManagerProvider;

  private final Provider<NotificationRoundnessManager> notificationRoundnessManagerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardMediaController> keyguardMediaControllerProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<ZenModeController> zenModeControllerProvider;

  private final Provider<SysuiColorExtractor> colorExtractorProvider;

  private final Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<NotificationSwipeHelper.Builder> notificationSwipeHelperBuilderProvider;

  private final Provider<StatusBar> statusBarProvider;

  private final Provider<ScrimController> scrimControllerProvider;

  private final Provider<NotificationGroupManagerLegacy> legacyGroupManagerProvider;

  private final Provider<GroupExpansionManager> groupManagerProvider;

  private final Provider<SectionHeaderController> silentHeaderControllerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotifPipeline> notifPipelineProvider;

  private final Provider<NotifCollection> notifCollectionProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider;

  private final Provider<IStatusBarService> iStatusBarServiceProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<ForegroundServiceDismissalFeatureController> fgFeatureControllerProvider;

  private final Provider<ForegroundServiceSectionController> fgServicesSectionControllerProvider;

  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<NotificationRemoteInputManager> remoteInputManagerProvider;

  private final Provider<VisualStabilityManager> visualStabilityManagerProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  public NotificationStackScrollLayoutController_Factory(Provider<Boolean> allowLongPressProvider,
      Provider<NotificationGutsManager> notificationGutsManagerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<NotificationRoundnessManager> notificationRoundnessManagerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardMediaController> keyguardMediaControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<ZenModeController> zenModeControllerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<Resources> resourcesProvider,
      Provider<NotificationSwipeHelper.Builder> notificationSwipeHelperBuilderProvider,
      Provider<StatusBar> statusBarProvider, Provider<ScrimController> scrimControllerProvider,
      Provider<NotificationGroupManagerLegacy> legacyGroupManagerProvider,
      Provider<GroupExpansionManager> groupManagerProvider,
      Provider<SectionHeaderController> silentHeaderControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<NotifPipeline> notifPipelineProvider,
      Provider<NotifCollection> notifCollectionProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider,
      Provider<IStatusBarService> iStatusBarServiceProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<ForegroundServiceDismissalFeatureController> fgFeatureControllerProvider,
      Provider<ForegroundServiceSectionController> fgServicesSectionControllerProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<ShadeController> shadeControllerProvider) {
    this.allowLongPressProvider = allowLongPressProvider;
    this.notificationGutsManagerProvider = notificationGutsManagerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.notificationRoundnessManagerProvider = notificationRoundnessManagerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.dynamicPrivacyControllerProvider = dynamicPrivacyControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardMediaControllerProvider = keyguardMediaControllerProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.zenModeControllerProvider = zenModeControllerProvider;
    this.colorExtractorProvider = colorExtractorProvider;
    this.lockscreenUserManagerProvider = lockscreenUserManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.resourcesProvider = resourcesProvider;
    this.notificationSwipeHelperBuilderProvider = notificationSwipeHelperBuilderProvider;
    this.statusBarProvider = statusBarProvider;
    this.scrimControllerProvider = scrimControllerProvider;
    this.legacyGroupManagerProvider = legacyGroupManagerProvider;
    this.groupManagerProvider = groupManagerProvider;
    this.silentHeaderControllerProvider = silentHeaderControllerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.notifPipelineProvider = notifPipelineProvider;
    this.notifCollectionProvider = notifCollectionProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.lockscreenShadeTransitionControllerProvider = lockscreenShadeTransitionControllerProvider;
    this.iStatusBarServiceProvider = iStatusBarServiceProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.fgFeatureControllerProvider = fgFeatureControllerProvider;
    this.fgServicesSectionControllerProvider = fgServicesSectionControllerProvider;
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.remoteInputManagerProvider = remoteInputManagerProvider;
    this.visualStabilityManagerProvider = visualStabilityManagerProvider;
    this.shadeControllerProvider = shadeControllerProvider;
  }

  @Override
  public NotificationStackScrollLayoutController get() {
    return newInstance(allowLongPressProvider.get(), notificationGutsManagerProvider.get(), headsUpManagerProvider.get(), notificationRoundnessManagerProvider.get(), tunerServiceProvider.get(), deviceProvisionedControllerProvider.get(), dynamicPrivacyControllerProvider.get(), configurationControllerProvider.get(), statusBarStateControllerProvider.get(), keyguardMediaControllerProvider.get(), keyguardBypassControllerProvider.get(), zenModeControllerProvider.get(), colorExtractorProvider.get(), lockscreenUserManagerProvider.get(), metricsLoggerProvider.get(), falsingCollectorProvider.get(), falsingManagerProvider.get(), resourcesProvider.get(), notificationSwipeHelperBuilderProvider.get(), statusBarProvider.get(), scrimControllerProvider.get(), legacyGroupManagerProvider.get(), groupManagerProvider.get(), silentHeaderControllerProvider.get(), featureFlagsProvider.get(), notifPipelineProvider.get(), notifCollectionProvider.get(), notificationEntryManagerProvider.get(), lockscreenShadeTransitionControllerProvider.get(), iStatusBarServiceProvider.get(), uiEventLoggerProvider.get(), fgFeatureControllerProvider.get(), fgServicesSectionControllerProvider.get(), layoutInflaterProvider.get(), remoteInputManagerProvider.get(), visualStabilityManagerProvider.get(), shadeControllerProvider.get());
  }

  public static NotificationStackScrollLayoutController_Factory create(
      Provider<Boolean> allowLongPressProvider,
      Provider<NotificationGutsManager> notificationGutsManagerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<NotificationRoundnessManager> notificationRoundnessManagerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardMediaController> keyguardMediaControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<ZenModeController> zenModeControllerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<Resources> resourcesProvider,
      Provider<NotificationSwipeHelper.Builder> notificationSwipeHelperBuilderProvider,
      Provider<StatusBar> statusBarProvider, Provider<ScrimController> scrimControllerProvider,
      Provider<NotificationGroupManagerLegacy> legacyGroupManagerProvider,
      Provider<GroupExpansionManager> groupManagerProvider,
      Provider<SectionHeaderController> silentHeaderControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<NotifPipeline> notifPipelineProvider,
      Provider<NotifCollection> notifCollectionProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider,
      Provider<IStatusBarService> iStatusBarServiceProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<ForegroundServiceDismissalFeatureController> fgFeatureControllerProvider,
      Provider<ForegroundServiceSectionController> fgServicesSectionControllerProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<ShadeController> shadeControllerProvider) {
    return new NotificationStackScrollLayoutController_Factory(allowLongPressProvider, notificationGutsManagerProvider, headsUpManagerProvider, notificationRoundnessManagerProvider, tunerServiceProvider, deviceProvisionedControllerProvider, dynamicPrivacyControllerProvider, configurationControllerProvider, statusBarStateControllerProvider, keyguardMediaControllerProvider, keyguardBypassControllerProvider, zenModeControllerProvider, colorExtractorProvider, lockscreenUserManagerProvider, metricsLoggerProvider, falsingCollectorProvider, falsingManagerProvider, resourcesProvider, notificationSwipeHelperBuilderProvider, statusBarProvider, scrimControllerProvider, legacyGroupManagerProvider, groupManagerProvider, silentHeaderControllerProvider, featureFlagsProvider, notifPipelineProvider, notifCollectionProvider, notificationEntryManagerProvider, lockscreenShadeTransitionControllerProvider, iStatusBarServiceProvider, uiEventLoggerProvider, fgFeatureControllerProvider, fgServicesSectionControllerProvider, layoutInflaterProvider, remoteInputManagerProvider, visualStabilityManagerProvider, shadeControllerProvider);
  }

  public static NotificationStackScrollLayoutController newInstance(boolean allowLongPress,
      NotificationGutsManager notificationGutsManager, HeadsUpManagerPhone headsUpManager,
      NotificationRoundnessManager notificationRoundnessManager, TunerService tunerService,
      DeviceProvisionedController deviceProvisionedController,
      DynamicPrivacyController dynamicPrivacyController,
      ConfigurationController configurationController,
      SysuiStatusBarStateController statusBarStateController,
      KeyguardMediaController keyguardMediaController,
      KeyguardBypassController keyguardBypassController, ZenModeController zenModeController,
      SysuiColorExtractor colorExtractor, NotificationLockscreenUserManager lockscreenUserManager,
      MetricsLogger metricsLogger, FalsingCollector falsingCollector, FalsingManager falsingManager,
      Resources resources, Object notificationSwipeHelperBuilder, StatusBar statusBar,
      ScrimController scrimController, NotificationGroupManagerLegacy legacyGroupManager,
      GroupExpansionManager groupManager, SectionHeaderController silentHeaderController,
      FeatureFlags featureFlags, NotifPipeline notifPipeline, NotifCollection notifCollection,
      NotificationEntryManager notificationEntryManager,
      LockscreenShadeTransitionController lockscreenShadeTransitionController,
      IStatusBarService iStatusBarService, UiEventLogger uiEventLogger,
      ForegroundServiceDismissalFeatureController fgFeatureController,
      ForegroundServiceSectionController fgServicesSectionController, LayoutInflater layoutInflater,
      NotificationRemoteInputManager remoteInputManager,
      VisualStabilityManager visualStabilityManager, ShadeController shadeController) {
    return new NotificationStackScrollLayoutController(allowLongPress, notificationGutsManager, headsUpManager, notificationRoundnessManager, tunerService, deviceProvisionedController, dynamicPrivacyController, configurationController, statusBarStateController, keyguardMediaController, keyguardBypassController, zenModeController, colorExtractor, lockscreenUserManager, metricsLogger, falsingCollector, falsingManager, resources, (NotificationSwipeHelper.Builder) notificationSwipeHelperBuilder, statusBar, scrimController, legacyGroupManager, groupManager, silentHeaderController, featureFlags, notifPipeline, notifCollection, notificationEntryManager, lockscreenShadeTransitionController, iStatusBarService, uiEventLogger, fgFeatureController, fgServicesSectionController, layoutInflater, remoteInputManager, visualStabilityManager, shadeController);
  }
}

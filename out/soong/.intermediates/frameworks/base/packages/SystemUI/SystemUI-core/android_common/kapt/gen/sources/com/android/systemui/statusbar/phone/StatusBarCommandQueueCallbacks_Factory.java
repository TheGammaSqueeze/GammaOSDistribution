package com.android.systemui.statusbar.phone;

import android.content.Context;
import android.content.res.Resources;
import android.os.PowerManager;
import android.os.Vibrator;
import com.android.internal.logging.MetricsLogger;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.DisableFlagsLogger;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.VibratorHelper;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.statusbar.policy.RemoteInputQuickSettingsDisabler;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreen;
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
public final class StatusBarCommandQueueCallbacks_Factory implements Factory<StatusBarCommandQueueCallbacks> {
  private final Provider<StatusBar> statusBarProvider;

  private final Provider<Context> contextProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<NotificationPanelViewController> notificationPanelViewControllerProvider;

  private final Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider;

  private final Provider<RemoteInputQuickSettingsDisabler> remoteInputQuickSettingsDisablerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  private final Provider<AssistManager> assistManagerProvider;

  private final Provider<DozeServiceHost> dozeServiceHostProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider;

  private final Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider;

  private final Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<VibratorHelper> vibratorHelperProvider;

  private final Provider<Optional<Vibrator>> vibratorOptionalProvider;

  private final Provider<LightBarController> lightBarControllerProvider;

  private final Provider<DisableFlagsLogger> disableFlagsLoggerProvider;

  private final Provider<Integer> displayIdProvider;

  public StatusBarCommandQueueCallbacks_Factory(Provider<StatusBar> statusBarProvider,
      Provider<Context> contextProvider, Provider<Resources> resourcesProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider,
      Provider<RemoteInputQuickSettingsDisabler> remoteInputQuickSettingsDisablerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<AssistManager> assistManagerProvider,
      Provider<DozeServiceHost> dozeServiceHostProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider,
      Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider,
      Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider,
      Provider<PowerManager> powerManagerProvider, Provider<VibratorHelper> vibratorHelperProvider,
      Provider<Optional<Vibrator>> vibratorOptionalProvider,
      Provider<LightBarController> lightBarControllerProvider,
      Provider<DisableFlagsLogger> disableFlagsLoggerProvider,
      Provider<Integer> displayIdProvider) {
    this.statusBarProvider = statusBarProvider;
    this.contextProvider = contextProvider;
    this.resourcesProvider = resourcesProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.notificationPanelViewControllerProvider = notificationPanelViewControllerProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.remoteInputQuickSettingsDisablerProvider = remoteInputQuickSettingsDisablerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
    this.assistManagerProvider = assistManagerProvider;
    this.dozeServiceHostProvider = dozeServiceHostProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.notificationShadeWindowViewProvider = notificationShadeWindowViewProvider;
    this.notificationStackScrollLayoutControllerProvider = notificationStackScrollLayoutControllerProvider;
    this.statusBarHideIconsForBouncerManagerProvider = statusBarHideIconsForBouncerManagerProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.vibratorHelperProvider = vibratorHelperProvider;
    this.vibratorOptionalProvider = vibratorOptionalProvider;
    this.lightBarControllerProvider = lightBarControllerProvider;
    this.disableFlagsLoggerProvider = disableFlagsLoggerProvider;
    this.displayIdProvider = displayIdProvider;
  }

  @Override
  public StatusBarCommandQueueCallbacks get() {
    return newInstance(statusBarProvider.get(), contextProvider.get(), resourcesProvider.get(), shadeControllerProvider.get(), commandQueueProvider.get(), notificationPanelViewControllerProvider.get(), splitScreenOptionalProvider.get(), remoteInputQuickSettingsDisablerProvider.get(), metricsLoggerProvider.get(), keyguardUpdateMonitorProvider.get(), keyguardStateControllerProvider.get(), headsUpManagerProvider.get(), wakefulnessLifecycleProvider.get(), deviceProvisionedControllerProvider.get(), statusBarKeyguardViewManagerProvider.get(), assistManagerProvider.get(), dozeServiceHostProvider.get(), statusBarStateControllerProvider.get(), notificationShadeWindowViewProvider.get(), notificationStackScrollLayoutControllerProvider.get(), statusBarHideIconsForBouncerManagerProvider.get(), powerManagerProvider.get(), vibratorHelperProvider.get(), vibratorOptionalProvider.get(), lightBarControllerProvider.get(), disableFlagsLoggerProvider.get(), displayIdProvider.get());
  }

  public static StatusBarCommandQueueCallbacks_Factory create(Provider<StatusBar> statusBarProvider,
      Provider<Context> contextProvider, Provider<Resources> resourcesProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider,
      Provider<RemoteInputQuickSettingsDisabler> remoteInputQuickSettingsDisablerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<AssistManager> assistManagerProvider,
      Provider<DozeServiceHost> dozeServiceHostProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider,
      Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider,
      Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider,
      Provider<PowerManager> powerManagerProvider, Provider<VibratorHelper> vibratorHelperProvider,
      Provider<Optional<Vibrator>> vibratorOptionalProvider,
      Provider<LightBarController> lightBarControllerProvider,
      Provider<DisableFlagsLogger> disableFlagsLoggerProvider,
      Provider<Integer> displayIdProvider) {
    return new StatusBarCommandQueueCallbacks_Factory(statusBarProvider, contextProvider, resourcesProvider, shadeControllerProvider, commandQueueProvider, notificationPanelViewControllerProvider, splitScreenOptionalProvider, remoteInputQuickSettingsDisablerProvider, metricsLoggerProvider, keyguardUpdateMonitorProvider, keyguardStateControllerProvider, headsUpManagerProvider, wakefulnessLifecycleProvider, deviceProvisionedControllerProvider, statusBarKeyguardViewManagerProvider, assistManagerProvider, dozeServiceHostProvider, statusBarStateControllerProvider, notificationShadeWindowViewProvider, notificationStackScrollLayoutControllerProvider, statusBarHideIconsForBouncerManagerProvider, powerManagerProvider, vibratorHelperProvider, vibratorOptionalProvider, lightBarControllerProvider, disableFlagsLoggerProvider, displayIdProvider);
  }

  public static StatusBarCommandQueueCallbacks newInstance(StatusBar statusBar, Context context,
      Resources resources, ShadeController shadeController, CommandQueue commandQueue,
      NotificationPanelViewController notificationPanelViewController,
      Optional<LegacySplitScreen> splitScreenOptional,
      RemoteInputQuickSettingsDisabler remoteInputQuickSettingsDisabler,
      MetricsLogger metricsLogger, KeyguardUpdateMonitor keyguardUpdateMonitor,
      KeyguardStateController keyguardStateController, HeadsUpManager headsUpManager,
      WakefulnessLifecycle wakefulnessLifecycle,
      DeviceProvisionedController deviceProvisionedController,
      StatusBarKeyguardViewManager statusBarKeyguardViewManager, AssistManager assistManager,
      DozeServiceHost dozeServiceHost, SysuiStatusBarStateController statusBarStateController,
      NotificationShadeWindowView notificationShadeWindowView,
      NotificationStackScrollLayoutController notificationStackScrollLayoutController,
      StatusBarHideIconsForBouncerManager statusBarHideIconsForBouncerManager,
      PowerManager powerManager, VibratorHelper vibratorHelper, Optional<Vibrator> vibratorOptional,
      LightBarController lightBarController, DisableFlagsLogger disableFlagsLogger, int displayId) {
    return new StatusBarCommandQueueCallbacks(statusBar, context, resources, shadeController, commandQueue, notificationPanelViewController, splitScreenOptional, remoteInputQuickSettingsDisabler, metricsLogger, keyguardUpdateMonitor, keyguardStateController, headsUpManager, wakefulnessLifecycle, deviceProvisionedController, statusBarKeyguardViewManager, assistManager, dozeServiceHost, statusBarStateController, notificationShadeWindowView, notificationStackScrollLayoutController, statusBarHideIconsForBouncerManager, powerManager, vibratorHelper, vibratorOptional, lightBarController, disableFlagsLogger, displayId);
  }
}

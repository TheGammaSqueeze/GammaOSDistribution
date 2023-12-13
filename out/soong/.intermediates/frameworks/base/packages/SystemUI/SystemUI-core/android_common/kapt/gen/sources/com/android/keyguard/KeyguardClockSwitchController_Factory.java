package com.android.keyguard;

import android.content.res.Resources;
import com.android.keyguard.clock.ClockManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.colorextraction.SysuiColorExtractor;
import com.android.systemui.keyguard.KeyguardUnlockAnimationController;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.shared.system.smartspace.SmartspaceTransitionController;
import com.android.systemui.statusbar.lockscreen.LockscreenSmartspaceController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.NotificationIconAreaController;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.util.settings.SecureSettings;
import dagger.internal.Factory;
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
public final class KeyguardClockSwitchController_Factory implements Factory<KeyguardClockSwitchController> {
  private final Provider<KeyguardClockSwitch> keyguardClockSwitchProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<SysuiColorExtractor> colorExtractorProvider;

  private final Provider<ClockManager> clockManagerProvider;

  private final Provider<KeyguardSliceViewController> keyguardSliceViewControllerProvider;

  private final Provider<NotificationIconAreaController> notificationIconAreaControllerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<LockscreenSmartspaceController> smartspaceControllerProvider;

  private final Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider;

  private final Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<Executor> uiExecutorProvider;

  private final Provider<Resources> resourcesProvider;

  public KeyguardClockSwitchController_Factory(
      Provider<KeyguardClockSwitch> keyguardClockSwitchProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<ClockManager> clockManagerProvider,
      Provider<KeyguardSliceViewController> keyguardSliceViewControllerProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<LockscreenSmartspaceController> smartspaceControllerProvider,
      Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<Executor> uiExecutorProvider,
      Provider<Resources> resourcesProvider) {
    this.keyguardClockSwitchProvider = keyguardClockSwitchProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.colorExtractorProvider = colorExtractorProvider;
    this.clockManagerProvider = clockManagerProvider;
    this.keyguardSliceViewControllerProvider = keyguardSliceViewControllerProvider;
    this.notificationIconAreaControllerProvider = notificationIconAreaControllerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.smartspaceControllerProvider = smartspaceControllerProvider;
    this.keyguardUnlockAnimationControllerProvider = keyguardUnlockAnimationControllerProvider;
    this.smartspaceTransitionControllerProvider = smartspaceTransitionControllerProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.uiExecutorProvider = uiExecutorProvider;
    this.resourcesProvider = resourcesProvider;
  }

  @Override
  public KeyguardClockSwitchController get() {
    return newInstance(keyguardClockSwitchProvider.get(), statusBarStateControllerProvider.get(), colorExtractorProvider.get(), clockManagerProvider.get(), keyguardSliceViewControllerProvider.get(), notificationIconAreaControllerProvider.get(), broadcastDispatcherProvider.get(), batteryControllerProvider.get(), keyguardUpdateMonitorProvider.get(), bypassControllerProvider.get(), smartspaceControllerProvider.get(), keyguardUnlockAnimationControllerProvider.get(), smartspaceTransitionControllerProvider.get(), secureSettingsProvider.get(), uiExecutorProvider.get(), resourcesProvider.get());
  }

  public static KeyguardClockSwitchController_Factory create(
      Provider<KeyguardClockSwitch> keyguardClockSwitchProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<ClockManager> clockManagerProvider,
      Provider<KeyguardSliceViewController> keyguardSliceViewControllerProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<LockscreenSmartspaceController> smartspaceControllerProvider,
      Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<Executor> uiExecutorProvider,
      Provider<Resources> resourcesProvider) {
    return new KeyguardClockSwitchController_Factory(keyguardClockSwitchProvider, statusBarStateControllerProvider, colorExtractorProvider, clockManagerProvider, keyguardSliceViewControllerProvider, notificationIconAreaControllerProvider, broadcastDispatcherProvider, batteryControllerProvider, keyguardUpdateMonitorProvider, bypassControllerProvider, smartspaceControllerProvider, keyguardUnlockAnimationControllerProvider, smartspaceTransitionControllerProvider, secureSettingsProvider, uiExecutorProvider, resourcesProvider);
  }

  public static KeyguardClockSwitchController newInstance(KeyguardClockSwitch keyguardClockSwitch,
      StatusBarStateController statusBarStateController, SysuiColorExtractor colorExtractor,
      ClockManager clockManager, KeyguardSliceViewController keyguardSliceViewController,
      NotificationIconAreaController notificationIconAreaController,
      BroadcastDispatcher broadcastDispatcher, BatteryController batteryController,
      KeyguardUpdateMonitor keyguardUpdateMonitor, KeyguardBypassController bypassController,
      LockscreenSmartspaceController smartspaceController,
      KeyguardUnlockAnimationController keyguardUnlockAnimationController,
      SmartspaceTransitionController smartspaceTransitionController, SecureSettings secureSettings,
      Executor uiExecutor, Resources resources) {
    return new KeyguardClockSwitchController(keyguardClockSwitch, statusBarStateController, colorExtractor, clockManager, keyguardSliceViewController, notificationIconAreaController, broadcastDispatcher, batteryController, keyguardUpdateMonitor, bypassController, smartspaceController, keyguardUnlockAnimationController, smartspaceTransitionController, secureSettings, uiExecutor, resources);
  }
}

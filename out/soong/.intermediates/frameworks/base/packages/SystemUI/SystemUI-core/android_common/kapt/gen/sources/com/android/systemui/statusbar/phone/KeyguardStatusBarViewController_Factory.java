package com.android.systemui.statusbar.phone;

import com.android.keyguard.CarrierTextController;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.battery.BatteryMeterViewController;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.events.SystemStatusAnimationScheduler;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.statusbar.policy.UserInfoController;
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
public final class KeyguardStatusBarViewController_Factory implements Factory<KeyguardStatusBarViewController> {
  private final Provider<KeyguardStatusBarView> viewProvider;

  private final Provider<CarrierTextController> carrierTextControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<SystemStatusAnimationScheduler> animationSchedulerProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<UserInfoController> userInfoControllerProvider;

  private final Provider<StatusBarIconController> statusBarIconControllerProvider;

  private final Provider<StatusBarIconController.TintedIconManager.Factory> tintedIconManagerFactoryProvider;

  private final Provider<BatteryMeterViewController> batteryMeterViewControllerProvider;

  private final Provider<NotificationPanelViewController.NotificationPanelViewStateProvider> notificationPanelViewStateProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<BiometricUnlockController> biometricUnlockControllerProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<StatusBarContentInsetsProvider> statusBarContentInsetsProvider;

  public KeyguardStatusBarViewController_Factory(Provider<KeyguardStatusBarView> viewProvider,
      Provider<CarrierTextController> carrierTextControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SystemStatusAnimationScheduler> animationSchedulerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<UserInfoController> userInfoControllerProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<StatusBarIconController.TintedIconManager.Factory> tintedIconManagerFactoryProvider,
      Provider<BatteryMeterViewController> batteryMeterViewControllerProvider,
      Provider<NotificationPanelViewController.NotificationPanelViewStateProvider> notificationPanelViewStateProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<StatusBarContentInsetsProvider> statusBarContentInsetsProvider) {
    this.viewProvider = viewProvider;
    this.carrierTextControllerProvider = carrierTextControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.animationSchedulerProvider = animationSchedulerProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.userInfoControllerProvider = userInfoControllerProvider;
    this.statusBarIconControllerProvider = statusBarIconControllerProvider;
    this.tintedIconManagerFactoryProvider = tintedIconManagerFactoryProvider;
    this.batteryMeterViewControllerProvider = batteryMeterViewControllerProvider;
    this.notificationPanelViewStateProvider = notificationPanelViewStateProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.biometricUnlockControllerProvider = biometricUnlockControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.statusBarContentInsetsProvider = statusBarContentInsetsProvider;
  }

  @Override
  public KeyguardStatusBarViewController get() {
    return newInstance(viewProvider.get(), carrierTextControllerProvider.get(), configurationControllerProvider.get(), animationSchedulerProvider.get(), batteryControllerProvider.get(), userInfoControllerProvider.get(), statusBarIconControllerProvider.get(), tintedIconManagerFactoryProvider.get(), batteryMeterViewControllerProvider.get(), notificationPanelViewStateProvider.get(), keyguardStateControllerProvider.get(), bypassControllerProvider.get(), keyguardUpdateMonitorProvider.get(), biometricUnlockControllerProvider.get(), statusBarStateControllerProvider.get(), statusBarContentInsetsProvider.get());
  }

  public static KeyguardStatusBarViewController_Factory create(
      Provider<KeyguardStatusBarView> viewProvider,
      Provider<CarrierTextController> carrierTextControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SystemStatusAnimationScheduler> animationSchedulerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<UserInfoController> userInfoControllerProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<StatusBarIconController.TintedIconManager.Factory> tintedIconManagerFactoryProvider,
      Provider<BatteryMeterViewController> batteryMeterViewControllerProvider,
      Provider<NotificationPanelViewController.NotificationPanelViewStateProvider> notificationPanelViewStateProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<StatusBarContentInsetsProvider> statusBarContentInsetsProvider) {
    return new KeyguardStatusBarViewController_Factory(viewProvider, carrierTextControllerProvider, configurationControllerProvider, animationSchedulerProvider, batteryControllerProvider, userInfoControllerProvider, statusBarIconControllerProvider, tintedIconManagerFactoryProvider, batteryMeterViewControllerProvider, notificationPanelViewStateProvider, keyguardStateControllerProvider, bypassControllerProvider, keyguardUpdateMonitorProvider, biometricUnlockControllerProvider, statusBarStateControllerProvider, statusBarContentInsetsProvider);
  }

  public static KeyguardStatusBarViewController newInstance(KeyguardStatusBarView view,
      CarrierTextController carrierTextController, ConfigurationController configurationController,
      SystemStatusAnimationScheduler animationScheduler, BatteryController batteryController,
      UserInfoController userInfoController, StatusBarIconController statusBarIconController,
      StatusBarIconController.TintedIconManager.Factory tintedIconManagerFactory,
      BatteryMeterViewController batteryMeterViewController,
      NotificationPanelViewController.NotificationPanelViewStateProvider notificationPanelViewStateProvider,
      KeyguardStateController keyguardStateController, KeyguardBypassController bypassController,
      KeyguardUpdateMonitor keyguardUpdateMonitor,
      BiometricUnlockController biometricUnlockController,
      SysuiStatusBarStateController statusBarStateController,
      StatusBarContentInsetsProvider statusBarContentInsetsProvider) {
    return new KeyguardStatusBarViewController(view, carrierTextController, configurationController, animationScheduler, batteryController, userInfoController, statusBarIconController, tintedIconManagerFactory, batteryMeterViewController, notificationPanelViewStateProvider, keyguardStateController, bypassController, keyguardUpdateMonitor, biometricUnlockController, statusBarStateController, statusBarContentInsetsProvider);
  }
}

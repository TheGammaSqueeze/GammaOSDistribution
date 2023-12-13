package com.android.systemui.statusbar.phone;

import android.os.PowerManager;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.doze.DozeLog;
import com.android.systemui.keyguard.KeyguardViewMediator;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.PulseExpansionHandler;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class DozeServiceHost_Factory implements Factory<DozeServiceHost> {
  private final Provider<DozeLog> dozeLogProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<HeadsUpManagerPhone> headsUpManagerPhoneProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<ScrimController> scrimControllerProvider;

  private final Provider<BiometricUnlockController> biometricUnlockControllerLazyProvider;

  private final Provider<KeyguardViewMediator> keyguardViewMediatorProvider;

  private final Provider<AssistManager> assistManagerLazyProvider;

  private final Provider<DozeScrimController> dozeScrimControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<PulseExpansionHandler> pulseExpansionHandlerProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<NotificationWakeUpCoordinator> notificationWakeUpCoordinatorProvider;

  private final Provider<AuthController> authControllerProvider;

  private final Provider<NotificationIconAreaController> notificationIconAreaControllerProvider;

  public DozeServiceHost_Factory(Provider<DozeLog> dozeLogProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerPhoneProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<ScrimController> scrimControllerProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerLazyProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<DozeScrimController> dozeScrimControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<PulseExpansionHandler> pulseExpansionHandlerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<NotificationWakeUpCoordinator> notificationWakeUpCoordinatorProvider,
      Provider<AuthController> authControllerProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider) {
    this.dozeLogProvider = dozeLogProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.headsUpManagerPhoneProvider = headsUpManagerPhoneProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.scrimControllerProvider = scrimControllerProvider;
    this.biometricUnlockControllerLazyProvider = biometricUnlockControllerLazyProvider;
    this.keyguardViewMediatorProvider = keyguardViewMediatorProvider;
    this.assistManagerLazyProvider = assistManagerLazyProvider;
    this.dozeScrimControllerProvider = dozeScrimControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.pulseExpansionHandlerProvider = pulseExpansionHandlerProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.notificationWakeUpCoordinatorProvider = notificationWakeUpCoordinatorProvider;
    this.authControllerProvider = authControllerProvider;
    this.notificationIconAreaControllerProvider = notificationIconAreaControllerProvider;
  }

  @Override
  public DozeServiceHost get() {
    return newInstance(dozeLogProvider.get(), powerManagerProvider.get(), wakefulnessLifecycleProvider.get(), statusBarStateControllerProvider.get(), deviceProvisionedControllerProvider.get(), headsUpManagerPhoneProvider.get(), batteryControllerProvider.get(), scrimControllerProvider.get(), DoubleCheck.lazy(biometricUnlockControllerLazyProvider), keyguardViewMediatorProvider.get(), DoubleCheck.lazy(assistManagerLazyProvider), dozeScrimControllerProvider.get(), keyguardUpdateMonitorProvider.get(), pulseExpansionHandlerProvider.get(), notificationShadeWindowControllerProvider.get(), notificationWakeUpCoordinatorProvider.get(), authControllerProvider.get(), notificationIconAreaControllerProvider.get());
  }

  public static DozeServiceHost_Factory create(Provider<DozeLog> dozeLogProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerPhoneProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<ScrimController> scrimControllerProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerLazyProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<DozeScrimController> dozeScrimControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<PulseExpansionHandler> pulseExpansionHandlerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<NotificationWakeUpCoordinator> notificationWakeUpCoordinatorProvider,
      Provider<AuthController> authControllerProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider) {
    return new DozeServiceHost_Factory(dozeLogProvider, powerManagerProvider, wakefulnessLifecycleProvider, statusBarStateControllerProvider, deviceProvisionedControllerProvider, headsUpManagerPhoneProvider, batteryControllerProvider, scrimControllerProvider, biometricUnlockControllerLazyProvider, keyguardViewMediatorProvider, assistManagerLazyProvider, dozeScrimControllerProvider, keyguardUpdateMonitorProvider, pulseExpansionHandlerProvider, notificationShadeWindowControllerProvider, notificationWakeUpCoordinatorProvider, authControllerProvider, notificationIconAreaControllerProvider);
  }

  public static DozeServiceHost newInstance(DozeLog dozeLog, PowerManager powerManager,
      WakefulnessLifecycle wakefulnessLifecycle,
      SysuiStatusBarStateController statusBarStateController,
      DeviceProvisionedController deviceProvisionedController,
      HeadsUpManagerPhone headsUpManagerPhone, BatteryController batteryController,
      ScrimController scrimController,
      Lazy<BiometricUnlockController> biometricUnlockControllerLazy,
      KeyguardViewMediator keyguardViewMediator, Lazy<AssistManager> assistManagerLazy,
      DozeScrimController dozeScrimController, KeyguardUpdateMonitor keyguardUpdateMonitor,
      PulseExpansionHandler pulseExpansionHandler,
      NotificationShadeWindowController notificationShadeWindowController,
      NotificationWakeUpCoordinator notificationWakeUpCoordinator, AuthController authController,
      NotificationIconAreaController notificationIconAreaController) {
    return new DozeServiceHost(dozeLog, powerManager, wakefulnessLifecycle, statusBarStateController, deviceProvisionedController, headsUpManagerPhone, batteryController, scrimController, biometricUnlockControllerLazy, keyguardViewMediator, assistManagerLazy, dozeScrimController, keyguardUpdateMonitor, pulseExpansionHandler, notificationShadeWindowController, notificationWakeUpCoordinator, authController, notificationIconAreaController);
  }
}

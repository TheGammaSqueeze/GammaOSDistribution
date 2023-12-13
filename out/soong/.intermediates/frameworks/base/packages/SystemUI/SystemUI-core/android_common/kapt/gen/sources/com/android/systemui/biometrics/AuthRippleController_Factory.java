package com.android.systemui.biometrics;

import android.content.Context;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.commandline.CommandRegistry;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class AuthRippleController_Factory implements Factory<AuthRippleController> {
  private final Provider<StatusBar> statusBarProvider;

  private final Provider<Context> sysuiContextProvider;

  private final Provider<AuthController> authControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<CommandRegistry> commandRegistryProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<BiometricUnlockController> biometricUnlockControllerProvider;

  private final Provider<UdfpsController> udfpsControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<AuthRippleView> rippleViewProvider;

  public AuthRippleController_Factory(Provider<StatusBar> statusBarProvider,
      Provider<Context> sysuiContextProvider, Provider<AuthController> authControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<CommandRegistry> commandRegistryProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<UdfpsController> udfpsControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<AuthRippleView> rippleViewProvider) {
    this.statusBarProvider = statusBarProvider;
    this.sysuiContextProvider = sysuiContextProvider;
    this.authControllerProvider = authControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.commandRegistryProvider = commandRegistryProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.biometricUnlockControllerProvider = biometricUnlockControllerProvider;
    this.udfpsControllerProvider = udfpsControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.rippleViewProvider = rippleViewProvider;
  }

  @Override
  public AuthRippleController get() {
    return newInstance(statusBarProvider.get(), sysuiContextProvider.get(), authControllerProvider.get(), configurationControllerProvider.get(), keyguardUpdateMonitorProvider.get(), keyguardStateControllerProvider.get(), wakefulnessLifecycleProvider.get(), commandRegistryProvider.get(), notificationShadeWindowControllerProvider.get(), bypassControllerProvider.get(), biometricUnlockControllerProvider.get(), udfpsControllerProvider, statusBarStateControllerProvider.get(), rippleViewProvider.get());
  }

  public static AuthRippleController_Factory create(Provider<StatusBar> statusBarProvider,
      Provider<Context> sysuiContextProvider, Provider<AuthController> authControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<CommandRegistry> commandRegistryProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<UdfpsController> udfpsControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<AuthRippleView> rippleViewProvider) {
    return new AuthRippleController_Factory(statusBarProvider, sysuiContextProvider, authControllerProvider, configurationControllerProvider, keyguardUpdateMonitorProvider, keyguardStateControllerProvider, wakefulnessLifecycleProvider, commandRegistryProvider, notificationShadeWindowControllerProvider, bypassControllerProvider, biometricUnlockControllerProvider, udfpsControllerProvider, statusBarStateControllerProvider, rippleViewProvider);
  }

  public static AuthRippleController newInstance(StatusBar statusBar, Context sysuiContext,
      AuthController authController, ConfigurationController configurationController,
      KeyguardUpdateMonitor keyguardUpdateMonitor, KeyguardStateController keyguardStateController,
      WakefulnessLifecycle wakefulnessLifecycle, CommandRegistry commandRegistry,
      NotificationShadeWindowController notificationShadeWindowController,
      KeyguardBypassController bypassController,
      BiometricUnlockController biometricUnlockController,
      Provider<UdfpsController> udfpsControllerProvider,
      StatusBarStateController statusBarStateController, AuthRippleView rippleView) {
    return new AuthRippleController(statusBar, sysuiContext, authController, configurationController, keyguardUpdateMonitor, keyguardStateController, wakefulnessLifecycle, commandRegistry, notificationShadeWindowController, bypassController, biometricUnlockController, udfpsControllerProvider, statusBarStateController, rippleView);
  }
}

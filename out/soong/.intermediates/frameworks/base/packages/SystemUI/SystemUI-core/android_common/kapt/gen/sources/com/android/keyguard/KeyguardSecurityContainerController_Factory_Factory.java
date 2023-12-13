package com.android.keyguard;

import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.widget.LockPatternUtils;
import com.android.systemui.classifier.FalsingCollector;
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
public final class KeyguardSecurityContainerController_Factory_Factory implements Factory<KeyguardSecurityContainerController.Factory> {
  private final Provider<KeyguardSecurityContainer> viewProvider;

  private final Provider<AdminSecondaryLockScreenController.Factory> adminSecondaryLockScreenControllerFactoryProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<KeyguardSecurityModel> keyguardSecurityModelProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardSecurityViewFlipperController> securityViewFlipperControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  public KeyguardSecurityContainerController_Factory_Factory(
      Provider<KeyguardSecurityContainer> viewProvider,
      Provider<AdminSecondaryLockScreenController.Factory> adminSecondaryLockScreenControllerFactoryProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardSecurityModel> keyguardSecurityModelProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardSecurityViewFlipperController> securityViewFlipperControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FalsingCollector> falsingCollectorProvider) {
    this.viewProvider = viewProvider;
    this.adminSecondaryLockScreenControllerFactoryProvider = adminSecondaryLockScreenControllerFactoryProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.keyguardSecurityModelProvider = keyguardSecurityModelProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.securityViewFlipperControllerProvider = securityViewFlipperControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
  }

  @Override
  public KeyguardSecurityContainerController.Factory get() {
    return newInstance(viewProvider.get(), adminSecondaryLockScreenControllerFactoryProvider.get(), lockPatternUtilsProvider.get(), keyguardUpdateMonitorProvider.get(), keyguardSecurityModelProvider.get(), metricsLoggerProvider.get(), uiEventLoggerProvider.get(), keyguardStateControllerProvider.get(), securityViewFlipperControllerProvider.get(), configurationControllerProvider.get(), falsingCollectorProvider.get());
  }

  public static KeyguardSecurityContainerController_Factory_Factory create(
      Provider<KeyguardSecurityContainer> viewProvider,
      Provider<AdminSecondaryLockScreenController.Factory> adminSecondaryLockScreenControllerFactoryProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardSecurityModel> keyguardSecurityModelProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardSecurityViewFlipperController> securityViewFlipperControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FalsingCollector> falsingCollectorProvider) {
    return new KeyguardSecurityContainerController_Factory_Factory(viewProvider, adminSecondaryLockScreenControllerFactoryProvider, lockPatternUtilsProvider, keyguardUpdateMonitorProvider, keyguardSecurityModelProvider, metricsLoggerProvider, uiEventLoggerProvider, keyguardStateControllerProvider, securityViewFlipperControllerProvider, configurationControllerProvider, falsingCollectorProvider);
  }

  public static KeyguardSecurityContainerController.Factory newInstance(
      KeyguardSecurityContainer view,
      AdminSecondaryLockScreenController.Factory adminSecondaryLockScreenControllerFactory,
      LockPatternUtils lockPatternUtils, KeyguardUpdateMonitor keyguardUpdateMonitor,
      KeyguardSecurityModel keyguardSecurityModel, MetricsLogger metricsLogger,
      UiEventLogger uiEventLogger, KeyguardStateController keyguardStateController,
      KeyguardSecurityViewFlipperController securityViewFlipperController,
      ConfigurationController configurationController, FalsingCollector falsingCollector) {
    return new KeyguardSecurityContainerController.Factory(view, adminSecondaryLockScreenControllerFactory, lockPatternUtils, keyguardUpdateMonitor, keyguardSecurityModel, metricsLogger, uiEventLogger, keyguardStateController, securityViewFlipperController, configurationController, falsingCollector);
  }
}

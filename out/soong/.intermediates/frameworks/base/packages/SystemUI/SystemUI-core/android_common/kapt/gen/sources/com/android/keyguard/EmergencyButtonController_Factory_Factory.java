package com.android.keyguard;

import android.app.ActivityTaskManager;
import android.os.PowerManager;
import android.telecom.TelecomManager;
import android.telephony.TelephonyManager;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class EmergencyButtonController_Factory_Factory implements Factory<EmergencyButtonController.Factory> {
  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<TelephonyManager> telephonyManagerProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<ActivityTaskManager> activityTaskManagerProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<TelecomManager> telecomManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  public EmergencyButtonController_Factory_Factory(
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<ActivityTaskManager> activityTaskManagerProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<TelecomManager> telecomManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider) {
    this.configurationControllerProvider = configurationControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.telephonyManagerProvider = telephonyManagerProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.activityTaskManagerProvider = activityTaskManagerProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.telecomManagerProvider = telecomManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
  }

  @Override
  public EmergencyButtonController.Factory get() {
    return newInstance(configurationControllerProvider.get(), keyguardUpdateMonitorProvider.get(), telephonyManagerProvider.get(), powerManagerProvider.get(), activityTaskManagerProvider.get(), shadeControllerProvider.get(), telecomManagerProvider.get(), metricsLoggerProvider.get());
  }

  public static EmergencyButtonController_Factory_Factory create(
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<ActivityTaskManager> activityTaskManagerProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<TelecomManager> telecomManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider) {
    return new EmergencyButtonController_Factory_Factory(configurationControllerProvider, keyguardUpdateMonitorProvider, telephonyManagerProvider, powerManagerProvider, activityTaskManagerProvider, shadeControllerProvider, telecomManagerProvider, metricsLoggerProvider);
  }

  public static EmergencyButtonController.Factory newInstance(
      ConfigurationController configurationController, KeyguardUpdateMonitor keyguardUpdateMonitor,
      TelephonyManager telephonyManager, PowerManager powerManager,
      ActivityTaskManager activityTaskManager, ShadeController shadeController,
      TelecomManager telecomManager, MetricsLogger metricsLogger) {
    return new EmergencyButtonController.Factory(configurationController, keyguardUpdateMonitor, telephonyManager, powerManager, activityTaskManager, shadeController, telecomManager, metricsLogger);
  }
}

package com.android.systemui.qs.tiles;

import android.os.Handler;
import android.os.Looper;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.LocationController;
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
public final class UiModeNightTile_Factory implements Factory<UiModeNightTile> {
  private final Provider<QSHost> hostProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<LocationController> locationControllerProvider;

  public UiModeNightTile_Factory(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<LocationController> locationControllerProvider) {
    this.hostProvider = hostProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.locationControllerProvider = locationControllerProvider;
  }

  @Override
  public UiModeNightTile get() {
    return newInstance(hostProvider.get(), backgroundLooperProvider.get(), mainHandlerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), statusBarStateControllerProvider.get(), activityStarterProvider.get(), qsLoggerProvider.get(), configurationControllerProvider.get(), batteryControllerProvider.get(), locationControllerProvider.get());
  }

  public static UiModeNightTile_Factory create(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<LocationController> locationControllerProvider) {
    return new UiModeNightTile_Factory(hostProvider, backgroundLooperProvider, mainHandlerProvider, falsingManagerProvider, metricsLoggerProvider, statusBarStateControllerProvider, activityStarterProvider, qsLoggerProvider, configurationControllerProvider, batteryControllerProvider, locationControllerProvider);
  }

  public static UiModeNightTile newInstance(QSHost host, Looper backgroundLooper,
      Handler mainHandler, FalsingManager falsingManager, MetricsLogger metricsLogger,
      StatusBarStateController statusBarStateController, ActivityStarter activityStarter,
      QSLogger qsLogger, ConfigurationController configurationController,
      BatteryController batteryController, LocationController locationController) {
    return new UiModeNightTile(host, backgroundLooper, mainHandler, falsingManager, metricsLogger, statusBarStateController, activityStarter, qsLogger, configurationController, batteryController, locationController);
  }
}

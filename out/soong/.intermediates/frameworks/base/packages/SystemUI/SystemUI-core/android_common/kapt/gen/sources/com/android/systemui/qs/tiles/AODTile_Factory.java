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
import com.android.systemui.util.settings.SecureSettings;
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
public final class AODTile_Factory implements Factory<AODTile> {
  private final Provider<QSHost> hostProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  public AODTile_Factory(Provider<QSHost> hostProvider, Provider<Looper> backgroundLooperProvider,
      Provider<Handler> mainHandlerProvider, Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<BatteryController> batteryControllerProvider) {
    this.hostProvider = hostProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.batteryControllerProvider = batteryControllerProvider;
  }

  @Override
  public AODTile get() {
    return newInstance(hostProvider.get(), backgroundLooperProvider.get(), mainHandlerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), statusBarStateControllerProvider.get(), activityStarterProvider.get(), qsLoggerProvider.get(), secureSettingsProvider.get(), batteryControllerProvider.get());
  }

  public static AODTile_Factory create(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<BatteryController> batteryControllerProvider) {
    return new AODTile_Factory(hostProvider, backgroundLooperProvider, mainHandlerProvider, falsingManagerProvider, metricsLoggerProvider, statusBarStateControllerProvider, activityStarterProvider, qsLoggerProvider, secureSettingsProvider, batteryControllerProvider);
  }

  public static AODTile newInstance(QSHost host, Looper backgroundLooper, Handler mainHandler,
      FalsingManager falsingManager, MetricsLogger metricsLogger,
      StatusBarStateController statusBarStateController, ActivityStarter activityStarter,
      QSLogger qsLogger, SecureSettings secureSettings, BatteryController batteryController) {
    return new AODTile(host, backgroundLooper, mainHandler, falsingManager, metricsLogger, statusBarStateController, activityStarter, qsLogger, secureSettings, batteryController);
  }
}

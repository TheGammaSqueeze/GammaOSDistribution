package com.android.systemui.qs.tiles;

import android.hardware.display.ColorDisplayManager;
import android.os.Handler;
import android.os.Looper;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.dagger.NightDisplayListenerModule;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
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
public final class NightDisplayTile_Factory implements Factory<NightDisplayTile> {
  private final Provider<QSHost> hostProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<LocationController> locationControllerProvider;

  private final Provider<ColorDisplayManager> colorDisplayManagerProvider;

  private final Provider<NightDisplayListenerModule.Builder> nightDisplayListenerBuilderProvider;

  public NightDisplayTile_Factory(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<LocationController> locationControllerProvider,
      Provider<ColorDisplayManager> colorDisplayManagerProvider,
      Provider<NightDisplayListenerModule.Builder> nightDisplayListenerBuilderProvider) {
    this.hostProvider = hostProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.locationControllerProvider = locationControllerProvider;
    this.colorDisplayManagerProvider = colorDisplayManagerProvider;
    this.nightDisplayListenerBuilderProvider = nightDisplayListenerBuilderProvider;
  }

  @Override
  public NightDisplayTile get() {
    return newInstance(hostProvider.get(), backgroundLooperProvider.get(), mainHandlerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), statusBarStateControllerProvider.get(), activityStarterProvider.get(), qsLoggerProvider.get(), locationControllerProvider.get(), colorDisplayManagerProvider.get(), nightDisplayListenerBuilderProvider.get());
  }

  public static NightDisplayTile_Factory create(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<LocationController> locationControllerProvider,
      Provider<ColorDisplayManager> colorDisplayManagerProvider,
      Provider<NightDisplayListenerModule.Builder> nightDisplayListenerBuilderProvider) {
    return new NightDisplayTile_Factory(hostProvider, backgroundLooperProvider, mainHandlerProvider, falsingManagerProvider, metricsLoggerProvider, statusBarStateControllerProvider, activityStarterProvider, qsLoggerProvider, locationControllerProvider, colorDisplayManagerProvider, nightDisplayListenerBuilderProvider);
  }

  public static NightDisplayTile newInstance(QSHost host, Looper backgroundLooper,
      Handler mainHandler, FalsingManager falsingManager, MetricsLogger metricsLogger,
      StatusBarStateController statusBarStateController, ActivityStarter activityStarter,
      QSLogger qsLogger, LocationController locationController,
      ColorDisplayManager colorDisplayManager,
      NightDisplayListenerModule.Builder nightDisplayListenerBuilder) {
    return new NightDisplayTile(host, backgroundLooper, mainHandler, falsingManager, metricsLogger, statusBarStateController, activityStarter, qsLogger, locationController, colorDisplayManager, nightDisplayListenerBuilder);
  }
}

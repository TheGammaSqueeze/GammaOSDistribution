package com.android.systemui.qs.tiles;

import android.net.ConnectivityManager;
import android.os.Handler;
import android.os.Looper;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
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
public final class AirplaneModeTile_Factory implements Factory<AirplaneModeTile> {
  private final Provider<QSHost> hostProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<ConnectivityManager> connectivityManagerProvider;

  public AirplaneModeTile_Factory(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ConnectivityManager> connectivityManagerProvider) {
    this.hostProvider = hostProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.connectivityManagerProvider = connectivityManagerProvider;
  }

  @Override
  public AirplaneModeTile get() {
    return newInstance(hostProvider.get(), backgroundLooperProvider.get(), mainHandlerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), statusBarStateControllerProvider.get(), activityStarterProvider.get(), qsLoggerProvider.get(), broadcastDispatcherProvider.get(), DoubleCheck.lazy(connectivityManagerProvider));
  }

  public static AirplaneModeTile_Factory create(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ConnectivityManager> connectivityManagerProvider) {
    return new AirplaneModeTile_Factory(hostProvider, backgroundLooperProvider, mainHandlerProvider, falsingManagerProvider, metricsLoggerProvider, statusBarStateControllerProvider, activityStarterProvider, qsLoggerProvider, broadcastDispatcherProvider, connectivityManagerProvider);
  }

  public static AirplaneModeTile newInstance(QSHost host, Looper backgroundLooper,
      Handler mainHandler, FalsingManager falsingManager, MetricsLogger metricsLogger,
      StatusBarStateController statusBarStateController, ActivityStarter activityStarter,
      QSLogger qsLogger, BroadcastDispatcher broadcastDispatcher,
      Lazy<ConnectivityManager> lazyConnectivityManager) {
    return new AirplaneModeTile(host, backgroundLooper, mainHandler, falsingManager, metricsLogger, statusBarStateController, activityStarter, qsLogger, broadcastDispatcher, lazyConnectivityManager);
  }
}

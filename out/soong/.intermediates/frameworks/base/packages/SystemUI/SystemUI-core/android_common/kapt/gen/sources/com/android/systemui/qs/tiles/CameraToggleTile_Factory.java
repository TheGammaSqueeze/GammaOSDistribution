package com.android.systemui.qs.tiles;

import android.os.Handler;
import android.os.Looper;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.statusbar.policy.IndividualSensorPrivacyController;
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
public final class CameraToggleTile_Factory implements Factory<CameraToggleTile> {
  private final Provider<QSHost> hostProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<IndividualSensorPrivacyController> sensorPrivacyControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  public CameraToggleTile_Factory(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<IndividualSensorPrivacyController> sensorPrivacyControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    this.hostProvider = hostProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.sensorPrivacyControllerProvider = sensorPrivacyControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
  }

  @Override
  public CameraToggleTile get() {
    return newInstance(hostProvider.get(), backgroundLooperProvider.get(), mainHandlerProvider.get(), metricsLoggerProvider.get(), falsingManagerProvider.get(), statusBarStateControllerProvider.get(), activityStarterProvider.get(), qsLoggerProvider.get(), sensorPrivacyControllerProvider.get(), keyguardStateControllerProvider.get());
  }

  public static CameraToggleTile_Factory create(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<IndividualSensorPrivacyController> sensorPrivacyControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    return new CameraToggleTile_Factory(hostProvider, backgroundLooperProvider, mainHandlerProvider, metricsLoggerProvider, falsingManagerProvider, statusBarStateControllerProvider, activityStarterProvider, qsLoggerProvider, sensorPrivacyControllerProvider, keyguardStateControllerProvider);
  }

  public static CameraToggleTile newInstance(QSHost host, Looper backgroundLooper,
      Handler mainHandler, MetricsLogger metricsLogger, FalsingManager falsingManager,
      StatusBarStateController statusBarStateController, ActivityStarter activityStarter,
      QSLogger qsLogger, IndividualSensorPrivacyController sensorPrivacyController,
      KeyguardStateController keyguardStateController) {
    return new CameraToggleTile(host, backgroundLooper, mainHandler, metricsLogger, falsingManager, statusBarStateController, activityStarter, qsLogger, sensorPrivacyController, keyguardStateController);
  }
}

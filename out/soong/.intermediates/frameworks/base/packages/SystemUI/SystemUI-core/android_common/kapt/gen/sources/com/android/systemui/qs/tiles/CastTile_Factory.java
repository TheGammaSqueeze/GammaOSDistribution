package com.android.systemui.qs.tiles;

import android.os.Handler;
import android.os.Looper;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.statusbar.connectivity.NetworkController;
import com.android.systemui.statusbar.policy.CastController;
import com.android.systemui.statusbar.policy.HotspotController;
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
public final class CastTile_Factory implements Factory<CastTile> {
  private final Provider<QSHost> hostProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<CastController> castControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<NetworkController> networkControllerProvider;

  private final Provider<HotspotController> hotspotControllerProvider;

  private final Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider;

  public CastTile_Factory(Provider<QSHost> hostProvider, Provider<Looper> backgroundLooperProvider,
      Provider<Handler> mainHandlerProvider, Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<CastController> castControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<HotspotController> hotspotControllerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    this.hostProvider = hostProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.castControllerProvider = castControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.networkControllerProvider = networkControllerProvider;
    this.hotspotControllerProvider = hotspotControllerProvider;
    this.dialogLaunchAnimatorProvider = dialogLaunchAnimatorProvider;
  }

  @Override
  public CastTile get() {
    return newInstance(hostProvider.get(), backgroundLooperProvider.get(), mainHandlerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), statusBarStateControllerProvider.get(), activityStarterProvider.get(), qsLoggerProvider.get(), castControllerProvider.get(), keyguardStateControllerProvider.get(), networkControllerProvider.get(), hotspotControllerProvider.get(), dialogLaunchAnimatorProvider.get());
  }

  public static CastTile_Factory create(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<CastController> castControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<HotspotController> hotspotControllerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    return new CastTile_Factory(hostProvider, backgroundLooperProvider, mainHandlerProvider, falsingManagerProvider, metricsLoggerProvider, statusBarStateControllerProvider, activityStarterProvider, qsLoggerProvider, castControllerProvider, keyguardStateControllerProvider, networkControllerProvider, hotspotControllerProvider, dialogLaunchAnimatorProvider);
  }

  public static CastTile newInstance(QSHost host, Looper backgroundLooper, Handler mainHandler,
      FalsingManager falsingManager, MetricsLogger metricsLogger,
      StatusBarStateController statusBarStateController, ActivityStarter activityStarter,
      QSLogger qsLogger, CastController castController,
      KeyguardStateController keyguardStateController, NetworkController networkController,
      HotspotController hotspotController, DialogLaunchAnimator dialogLaunchAnimator) {
    return new CastTile(host, backgroundLooper, mainHandler, falsingManager, metricsLogger, statusBarStateController, activityStarter, qsLogger, castController, keyguardStateController, networkController, hotspotController, dialogLaunchAnimator);
  }
}

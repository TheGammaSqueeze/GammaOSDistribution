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
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
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
public final class ProfilesTile_Factory implements Factory<ProfilesTile> {
  private final Provider<QSHost> hostProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider;

  private final Provider<KeyguardDismissUtil> keyguardDismissUtilProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  public ProfilesTile_Factory(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    this.hostProvider = hostProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.dialogLaunchAnimatorProvider = dialogLaunchAnimatorProvider;
    this.keyguardDismissUtilProvider = keyguardDismissUtilProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
  }

  @Override
  public ProfilesTile get() {
    return newInstance(hostProvider.get(), backgroundLooperProvider.get(), mainHandlerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), statusBarStateControllerProvider.get(), activityStarterProvider.get(), qsLoggerProvider.get(), dialogLaunchAnimatorProvider.get(), keyguardDismissUtilProvider.get(), keyguardStateControllerProvider.get());
  }

  public static ProfilesTile_Factory create(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    return new ProfilesTile_Factory(hostProvider, backgroundLooperProvider, mainHandlerProvider, falsingManagerProvider, metricsLoggerProvider, statusBarStateControllerProvider, activityStarterProvider, qsLoggerProvider, dialogLaunchAnimatorProvider, keyguardDismissUtilProvider, keyguardStateControllerProvider);
  }

  public static ProfilesTile newInstance(QSHost host, Looper backgroundLooper, Handler mainHandler,
      FalsingManager falsingManager, MetricsLogger metricsLogger,
      StatusBarStateController statusBarStateController, ActivityStarter activityStarter,
      QSLogger qsLogger, DialogLaunchAnimator dialogLaunchAnimator,
      KeyguardDismissUtil keyguardDismissUtil, KeyguardStateController keyguardStateController) {
    return new ProfilesTile(host, backgroundLooper, mainHandler, falsingManager, metricsLogger, statusBarStateController, activityStarter, qsLogger, dialogLaunchAnimator, keyguardDismissUtil, keyguardStateController);
  }
}

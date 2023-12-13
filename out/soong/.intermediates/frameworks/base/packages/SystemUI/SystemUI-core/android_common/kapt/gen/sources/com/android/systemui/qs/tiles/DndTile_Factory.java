package com.android.systemui.qs.tiles;

import android.content.SharedPreferences;
import android.os.Handler;
import android.os.Looper;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.statusbar.policy.ZenModeController;
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
public final class DndTile_Factory implements Factory<DndTile> {
  private final Provider<QSHost> hostProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<ZenModeController> zenModeControllerProvider;

  private final Provider<SharedPreferences> sharedPreferencesProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider;

  public DndTile_Factory(Provider<QSHost> hostProvider, Provider<Looper> backgroundLooperProvider,
      Provider<Handler> mainHandlerProvider, Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<ZenModeController> zenModeControllerProvider,
      Provider<SharedPreferences> sharedPreferencesProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    this.hostProvider = hostProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.zenModeControllerProvider = zenModeControllerProvider;
    this.sharedPreferencesProvider = sharedPreferencesProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.dialogLaunchAnimatorProvider = dialogLaunchAnimatorProvider;
  }

  @Override
  public DndTile get() {
    return newInstance(hostProvider.get(), backgroundLooperProvider.get(), mainHandlerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), statusBarStateControllerProvider.get(), activityStarterProvider.get(), qsLoggerProvider.get(), zenModeControllerProvider.get(), sharedPreferencesProvider.get(), secureSettingsProvider.get(), dialogLaunchAnimatorProvider.get());
  }

  public static DndTile_Factory create(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<ZenModeController> zenModeControllerProvider,
      Provider<SharedPreferences> sharedPreferencesProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    return new DndTile_Factory(hostProvider, backgroundLooperProvider, mainHandlerProvider, falsingManagerProvider, metricsLoggerProvider, statusBarStateControllerProvider, activityStarterProvider, qsLoggerProvider, zenModeControllerProvider, sharedPreferencesProvider, secureSettingsProvider, dialogLaunchAnimatorProvider);
  }

  public static DndTile newInstance(QSHost host, Looper backgroundLooper, Handler mainHandler,
      FalsingManager falsingManager, MetricsLogger metricsLogger,
      StatusBarStateController statusBarStateController, ActivityStarter activityStarter,
      QSLogger qsLogger, ZenModeController zenModeController, SharedPreferences sharedPreferences,
      SecureSettings secureSettings, DialogLaunchAnimator dialogLaunchAnimator) {
    return new DndTile(host, backgroundLooper, mainHandler, falsingManager, metricsLogger, statusBarStateController, activityStarter, qsLogger, zenModeController, sharedPreferences, secureSettings, dialogLaunchAnimator);
  }
}

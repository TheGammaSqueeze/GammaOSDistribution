package com.android.systemui.qs.tiles;

import android.content.pm.PackageManager;
import android.os.Handler;
import android.os.Looper;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.settings.SecureSettings;
import com.android.systemui.wallet.controller.QuickAccessWalletController;
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
public final class QuickAccessWalletTile_Factory implements Factory<QuickAccessWalletTile> {
  private final Provider<QSHost> hostProvider;

  private final Provider<Looper> backgroundLooperProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<PackageManager> packageManagerProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<QuickAccessWalletController> quickAccessWalletControllerProvider;

  public QuickAccessWalletTile_Factory(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<QuickAccessWalletController> quickAccessWalletControllerProvider) {
    this.hostProvider = hostProvider;
    this.backgroundLooperProvider = backgroundLooperProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.packageManagerProvider = packageManagerProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.quickAccessWalletControllerProvider = quickAccessWalletControllerProvider;
  }

  @Override
  public QuickAccessWalletTile get() {
    return newInstance(hostProvider.get(), backgroundLooperProvider.get(), mainHandlerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), statusBarStateControllerProvider.get(), activityStarterProvider.get(), qsLoggerProvider.get(), keyguardStateControllerProvider.get(), packageManagerProvider.get(), secureSettingsProvider.get(), quickAccessWalletControllerProvider.get());
  }

  public static QuickAccessWalletTile_Factory create(Provider<QSHost> hostProvider,
      Provider<Looper> backgroundLooperProvider, Provider<Handler> mainHandlerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<QuickAccessWalletController> quickAccessWalletControllerProvider) {
    return new QuickAccessWalletTile_Factory(hostProvider, backgroundLooperProvider, mainHandlerProvider, falsingManagerProvider, metricsLoggerProvider, statusBarStateControllerProvider, activityStarterProvider, qsLoggerProvider, keyguardStateControllerProvider, packageManagerProvider, secureSettingsProvider, quickAccessWalletControllerProvider);
  }

  public static QuickAccessWalletTile newInstance(QSHost host, Looper backgroundLooper,
      Handler mainHandler, FalsingManager falsingManager, MetricsLogger metricsLogger,
      StatusBarStateController statusBarStateController, ActivityStarter activityStarter,
      QSLogger qsLogger, KeyguardStateController keyguardStateController,
      PackageManager packageManager, SecureSettings secureSettings,
      QuickAccessWalletController quickAccessWalletController) {
    return new QuickAccessWalletTile(host, backgroundLooper, mainHandler, falsingManager, metricsLogger, statusBarStateController, activityStarter, qsLogger, keyguardStateController, packageManager, secureSettings, quickAccessWalletController);
  }
}

package com.android.systemui.wallet.ui;

import android.os.Handler;
import com.android.internal.logging.UiEventLogger;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
import com.android.systemui.statusbar.phone.StatusBarKeyguardViewManager;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
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
public final class WalletActivity_Factory implements Factory<WalletActivity> {
  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardDismissUtil> keyguardDismissUtilProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<StatusBarKeyguardViewManager> keyguardViewManagerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  public WalletActivity_Factory(Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<Executor> executorProvider,
      Provider<Handler> handlerProvider, Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<UserTracker> userTrackerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<StatusBarKeyguardViewManager> keyguardViewManagerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider) {
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.keyguardDismissUtilProvider = keyguardDismissUtilProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.executorProvider = executorProvider;
    this.handlerProvider = handlerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.keyguardViewManagerProvider = keyguardViewManagerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
  }

  @Override
  public WalletActivity get() {
    return newInstance(keyguardStateControllerProvider.get(), keyguardDismissUtilProvider.get(), activityStarterProvider.get(), executorProvider.get(), handlerProvider.get(), falsingManagerProvider.get(), falsingCollectorProvider.get(), userTrackerProvider.get(), keyguardUpdateMonitorProvider.get(), keyguardViewManagerProvider.get(), uiEventLoggerProvider.get());
  }

  public static WalletActivity_Factory create(
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<Executor> executorProvider,
      Provider<Handler> handlerProvider, Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<UserTracker> userTrackerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<StatusBarKeyguardViewManager> keyguardViewManagerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider) {
    return new WalletActivity_Factory(keyguardStateControllerProvider, keyguardDismissUtilProvider, activityStarterProvider, executorProvider, handlerProvider, falsingManagerProvider, falsingCollectorProvider, userTrackerProvider, keyguardUpdateMonitorProvider, keyguardViewManagerProvider, uiEventLoggerProvider);
  }

  public static WalletActivity newInstance(KeyguardStateController keyguardStateController,
      KeyguardDismissUtil keyguardDismissUtil, ActivityStarter activityStarter, Executor executor,
      Handler handler, FalsingManager falsingManager, FalsingCollector falsingCollector,
      UserTracker userTracker, KeyguardUpdateMonitor keyguardUpdateMonitor,
      StatusBarKeyguardViewManager keyguardViewManager, UiEventLogger uiEventLogger) {
    return new WalletActivity(keyguardStateController, keyguardDismissUtil, activityStarter, executor, handler, falsingManager, falsingCollector, userTracker, keyguardUpdateMonitor, keyguardViewManager, uiEventLogger);
  }
}

package com.android.systemui.privacy;

import com.android.systemui.appops.AppOpsController;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.privacy.logging.PrivacyLogger;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.DeviceConfigProxy;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.time.SystemClock;
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
public final class PrivacyItemController_Factory implements Factory<PrivacyItemController> {
  private final Provider<AppOpsController> appOpsControllerProvider;

  private final Provider<DelayableExecutor> uiExecutorProvider;

  private final Provider<DelayableExecutor> bgExecutorProvider;

  private final Provider<DeviceConfigProxy> deviceConfigProxyProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<PrivacyLogger> loggerProvider;

  private final Provider<SystemClock> systemClockProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public PrivacyItemController_Factory(Provider<AppOpsController> appOpsControllerProvider,
      Provider<DelayableExecutor> uiExecutorProvider,
      Provider<DelayableExecutor> bgExecutorProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider,
      Provider<UserTracker> userTrackerProvider, Provider<PrivacyLogger> loggerProvider,
      Provider<SystemClock> systemClockProvider, Provider<DumpManager> dumpManagerProvider) {
    this.appOpsControllerProvider = appOpsControllerProvider;
    this.uiExecutorProvider = uiExecutorProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.deviceConfigProxyProvider = deviceConfigProxyProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.loggerProvider = loggerProvider;
    this.systemClockProvider = systemClockProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public PrivacyItemController get() {
    return newInstance(appOpsControllerProvider.get(), uiExecutorProvider.get(), bgExecutorProvider.get(), deviceConfigProxyProvider.get(), userTrackerProvider.get(), loggerProvider.get(), systemClockProvider.get(), dumpManagerProvider.get());
  }

  public static PrivacyItemController_Factory create(
      Provider<AppOpsController> appOpsControllerProvider,
      Provider<DelayableExecutor> uiExecutorProvider,
      Provider<DelayableExecutor> bgExecutorProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider,
      Provider<UserTracker> userTrackerProvider, Provider<PrivacyLogger> loggerProvider,
      Provider<SystemClock> systemClockProvider, Provider<DumpManager> dumpManagerProvider) {
    return new PrivacyItemController_Factory(appOpsControllerProvider, uiExecutorProvider, bgExecutorProvider, deviceConfigProxyProvider, userTrackerProvider, loggerProvider, systemClockProvider, dumpManagerProvider);
  }

  public static PrivacyItemController newInstance(AppOpsController appOpsController,
      DelayableExecutor uiExecutor, DelayableExecutor bgExecutor,
      DeviceConfigProxy deviceConfigProxy, UserTracker userTracker, PrivacyLogger logger,
      SystemClock systemClock, DumpManager dumpManager) {
    return new PrivacyItemController(appOpsController, uiExecutor, bgExecutor, deviceConfigProxy, userTracker, logger, systemClock, dumpManager);
  }
}

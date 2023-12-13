package com.android.systemui.privacy;

import android.content.pm.PackageManager;
import android.permission.PermissionManager;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.appops.AppOpsController;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.privacy.logging.PrivacyLogger;
import com.android.systemui.settings.UserTracker;
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
public final class PrivacyDialogController_Factory implements Factory<PrivacyDialogController> {
  private final Provider<PermissionManager> permissionManagerProvider;

  private final Provider<PackageManager> packageManagerProvider;

  private final Provider<PrivacyItemController> privacyItemControllerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  private final Provider<Executor> uiExecutorProvider;

  private final Provider<PrivacyLogger> privacyLoggerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<AppOpsController> appOpsControllerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  public PrivacyDialogController_Factory(Provider<PermissionManager> permissionManagerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<PrivacyItemController> privacyItemControllerProvider,
      Provider<UserTracker> userTrackerProvider, Provider<ActivityStarter> activityStarterProvider,
      Provider<Executor> backgroundExecutorProvider, Provider<Executor> uiExecutorProvider,
      Provider<PrivacyLogger> privacyLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<AppOpsController> appOpsControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider) {
    this.permissionManagerProvider = permissionManagerProvider;
    this.packageManagerProvider = packageManagerProvider;
    this.privacyItemControllerProvider = privacyItemControllerProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
    this.uiExecutorProvider = uiExecutorProvider;
    this.privacyLoggerProvider = privacyLoggerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.appOpsControllerProvider = appOpsControllerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
  }

  @Override
  public PrivacyDialogController get() {
    return newInstance(permissionManagerProvider.get(), packageManagerProvider.get(), privacyItemControllerProvider.get(), userTrackerProvider.get(), activityStarterProvider.get(), backgroundExecutorProvider.get(), uiExecutorProvider.get(), privacyLoggerProvider.get(), keyguardStateControllerProvider.get(), appOpsControllerProvider.get(), uiEventLoggerProvider.get());
  }

  public static PrivacyDialogController_Factory create(
      Provider<PermissionManager> permissionManagerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<PrivacyItemController> privacyItemControllerProvider,
      Provider<UserTracker> userTrackerProvider, Provider<ActivityStarter> activityStarterProvider,
      Provider<Executor> backgroundExecutorProvider, Provider<Executor> uiExecutorProvider,
      Provider<PrivacyLogger> privacyLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<AppOpsController> appOpsControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider) {
    return new PrivacyDialogController_Factory(permissionManagerProvider, packageManagerProvider, privacyItemControllerProvider, userTrackerProvider, activityStarterProvider, backgroundExecutorProvider, uiExecutorProvider, privacyLoggerProvider, keyguardStateControllerProvider, appOpsControllerProvider, uiEventLoggerProvider);
  }

  public static PrivacyDialogController newInstance(PermissionManager permissionManager,
      PackageManager packageManager, PrivacyItemController privacyItemController,
      UserTracker userTracker, ActivityStarter activityStarter, Executor backgroundExecutor,
      Executor uiExecutor, PrivacyLogger privacyLogger,
      KeyguardStateController keyguardStateController, AppOpsController appOpsController,
      UiEventLogger uiEventLogger) {
    return new PrivacyDialogController(permissionManager, packageManager, privacyItemController, userTracker, activityStarter, backgroundExecutor, uiExecutor, privacyLogger, keyguardStateController, appOpsController, uiEventLogger);
  }
}

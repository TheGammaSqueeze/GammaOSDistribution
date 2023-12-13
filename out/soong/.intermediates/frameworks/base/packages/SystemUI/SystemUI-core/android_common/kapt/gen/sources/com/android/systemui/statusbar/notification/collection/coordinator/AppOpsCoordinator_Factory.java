package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.ForegroundServiceController;
import com.android.systemui.appops.AppOpsController;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class AppOpsCoordinator_Factory implements Factory<AppOpsCoordinator> {
  private final Provider<ForegroundServiceController> foregroundServiceControllerProvider;

  private final Provider<AppOpsController> appOpsControllerProvider;

  private final Provider<DelayableExecutor> mainExecutorProvider;

  public AppOpsCoordinator_Factory(
      Provider<ForegroundServiceController> foregroundServiceControllerProvider,
      Provider<AppOpsController> appOpsControllerProvider,
      Provider<DelayableExecutor> mainExecutorProvider) {
    this.foregroundServiceControllerProvider = foregroundServiceControllerProvider;
    this.appOpsControllerProvider = appOpsControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public AppOpsCoordinator get() {
    return newInstance(foregroundServiceControllerProvider.get(), appOpsControllerProvider.get(), mainExecutorProvider.get());
  }

  public static AppOpsCoordinator_Factory create(
      Provider<ForegroundServiceController> foregroundServiceControllerProvider,
      Provider<AppOpsController> appOpsControllerProvider,
      Provider<DelayableExecutor> mainExecutorProvider) {
    return new AppOpsCoordinator_Factory(foregroundServiceControllerProvider, appOpsControllerProvider, mainExecutorProvider);
  }

  public static AppOpsCoordinator newInstance(
      ForegroundServiceController foregroundServiceController, AppOpsController appOpsController,
      DelayableExecutor mainExecutor) {
    return new AppOpsCoordinator(foregroundServiceController, appOpsController, mainExecutor);
  }
}

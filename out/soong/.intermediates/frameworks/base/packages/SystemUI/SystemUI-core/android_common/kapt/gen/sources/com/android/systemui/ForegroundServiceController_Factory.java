package com.android.systemui;

import android.os.Handler;
import com.android.systemui.appops.AppOpsController;
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
public final class ForegroundServiceController_Factory implements Factory<ForegroundServiceController> {
  private final Provider<AppOpsController> appOpsControllerProvider;

  private final Provider<Handler> mainHandlerProvider;

  public ForegroundServiceController_Factory(Provider<AppOpsController> appOpsControllerProvider,
      Provider<Handler> mainHandlerProvider) {
    this.appOpsControllerProvider = appOpsControllerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public ForegroundServiceController get() {
    return newInstance(appOpsControllerProvider.get(), mainHandlerProvider.get());
  }

  public static ForegroundServiceController_Factory create(
      Provider<AppOpsController> appOpsControllerProvider, Provider<Handler> mainHandlerProvider) {
    return new ForegroundServiceController_Factory(appOpsControllerProvider, mainHandlerProvider);
  }

  public static ForegroundServiceController newInstance(AppOpsController appOpsController,
      Handler mainHandler) {
    return new ForegroundServiceController(appOpsController, mainHandler);
  }
}

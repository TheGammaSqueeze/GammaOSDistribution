package com.android.systemui.biometrics;

import android.app.ActivityTaskManager;
import android.content.Context;
import android.hardware.display.DisplayManager;
import android.hardware.fingerprint.FingerprintManager;
import android.os.Handler;
import android.view.LayoutInflater;
import android.view.WindowManager;
import com.android.systemui.recents.OverviewProxyService;
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
public final class SidefpsController_Factory implements Factory<SidefpsController> {
  private final Provider<Context> contextProvider;

  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<FingerprintManager> fingerprintManagerProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<ActivityTaskManager> activityTaskManagerProvider;

  private final Provider<OverviewProxyService> overviewProxyServiceProvider;

  private final Provider<DisplayManager> displayManagerProvider;

  private final Provider<DelayableExecutor> mainExecutorProvider;

  private final Provider<Handler> handlerProvider;

  public SidefpsController_Factory(Provider<Context> contextProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<FingerprintManager> fingerprintManagerProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<ActivityTaskManager> activityTaskManagerProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<DisplayManager> displayManagerProvider,
      Provider<DelayableExecutor> mainExecutorProvider, Provider<Handler> handlerProvider) {
    this.contextProvider = contextProvider;
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.fingerprintManagerProvider = fingerprintManagerProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.activityTaskManagerProvider = activityTaskManagerProvider;
    this.overviewProxyServiceProvider = overviewProxyServiceProvider;
    this.displayManagerProvider = displayManagerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.handlerProvider = handlerProvider;
  }

  @Override
  public SidefpsController get() {
    return newInstance(contextProvider.get(), layoutInflaterProvider.get(), fingerprintManagerProvider.get(), windowManagerProvider.get(), activityTaskManagerProvider.get(), overviewProxyServiceProvider.get(), displayManagerProvider.get(), mainExecutorProvider.get(), handlerProvider.get());
  }

  public static SidefpsController_Factory create(Provider<Context> contextProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<FingerprintManager> fingerprintManagerProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<ActivityTaskManager> activityTaskManagerProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<DisplayManager> displayManagerProvider,
      Provider<DelayableExecutor> mainExecutorProvider, Provider<Handler> handlerProvider) {
    return new SidefpsController_Factory(contextProvider, layoutInflaterProvider, fingerprintManagerProvider, windowManagerProvider, activityTaskManagerProvider, overviewProxyServiceProvider, displayManagerProvider, mainExecutorProvider, handlerProvider);
  }

  public static SidefpsController newInstance(Context context, LayoutInflater layoutInflater,
      FingerprintManager fingerprintManager, WindowManager windowManager,
      ActivityTaskManager activityTaskManager, OverviewProxyService overviewProxyService,
      DisplayManager displayManager, DelayableExecutor mainExecutor, Handler handler) {
    return new SidefpsController(context, layoutInflater, fingerprintManager, windowManager, activityTaskManager, overviewProxyService, displayManager, mainExecutor, handler);
  }
}

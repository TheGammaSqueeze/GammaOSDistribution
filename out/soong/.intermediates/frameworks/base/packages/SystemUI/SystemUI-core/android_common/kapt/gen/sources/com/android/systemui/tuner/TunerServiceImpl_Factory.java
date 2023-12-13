package com.android.systemui.tuner;

import android.content.Context;
import android.os.Handler;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.leak.LeakDetector;
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
public final class TunerServiceImpl_Factory implements Factory<TunerServiceImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<LeakDetector> leakDetectorProvider;

  private final Provider<DemoModeController> demoModeControllerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  public TunerServiceImpl_Factory(Provider<Context> contextProvider,
      Provider<Handler> mainHandlerProvider, Provider<LeakDetector> leakDetectorProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<UserTracker> userTrackerProvider) {
    this.contextProvider = contextProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.leakDetectorProvider = leakDetectorProvider;
    this.demoModeControllerProvider = demoModeControllerProvider;
    this.userTrackerProvider = userTrackerProvider;
  }

  @Override
  public TunerServiceImpl get() {
    return newInstance(contextProvider.get(), mainHandlerProvider.get(), leakDetectorProvider.get(), demoModeControllerProvider.get(), userTrackerProvider.get());
  }

  public static TunerServiceImpl_Factory create(Provider<Context> contextProvider,
      Provider<Handler> mainHandlerProvider, Provider<LeakDetector> leakDetectorProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<UserTracker> userTrackerProvider) {
    return new TunerServiceImpl_Factory(contextProvider, mainHandlerProvider, leakDetectorProvider, demoModeControllerProvider, userTrackerProvider);
  }

  public static TunerServiceImpl newInstance(Context context, Handler mainHandler,
      LeakDetector leakDetector, DemoModeController demoModeController, UserTracker userTracker) {
    return new TunerServiceImpl(context, mainHandler, leakDetector, demoModeController, userTracker);
  }
}

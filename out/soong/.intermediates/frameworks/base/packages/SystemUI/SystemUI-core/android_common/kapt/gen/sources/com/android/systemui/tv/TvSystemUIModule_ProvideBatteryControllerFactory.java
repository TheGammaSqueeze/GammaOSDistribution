package com.android.systemui.tv;

import android.content.Context;
import android.os.Handler;
import android.os.PowerManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.power.EnhancedEstimates;
import com.android.systemui.statusbar.policy.BatteryController;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class TvSystemUIModule_ProvideBatteryControllerFactory implements Factory<BatteryController> {
  private final Provider<Context> contextProvider;

  private final Provider<EnhancedEstimates> enhancedEstimatesProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<DemoModeController> demoModeControllerProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<Handler> bgHandlerProvider;

  public TvSystemUIModule_ProvideBatteryControllerFactory(Provider<Context> contextProvider,
      Provider<EnhancedEstimates> enhancedEstimatesProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<Handler> mainHandlerProvider, Provider<Handler> bgHandlerProvider) {
    this.contextProvider = contextProvider;
    this.enhancedEstimatesProvider = enhancedEstimatesProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.demoModeControllerProvider = demoModeControllerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.bgHandlerProvider = bgHandlerProvider;
  }

  @Override
  public BatteryController get() {
    return provideBatteryController(contextProvider.get(), enhancedEstimatesProvider.get(), powerManagerProvider.get(), broadcastDispatcherProvider.get(), demoModeControllerProvider.get(), mainHandlerProvider.get(), bgHandlerProvider.get());
  }

  public static TvSystemUIModule_ProvideBatteryControllerFactory create(
      Provider<Context> contextProvider, Provider<EnhancedEstimates> enhancedEstimatesProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<Handler> mainHandlerProvider, Provider<Handler> bgHandlerProvider) {
    return new TvSystemUIModule_ProvideBatteryControllerFactory(contextProvider, enhancedEstimatesProvider, powerManagerProvider, broadcastDispatcherProvider, demoModeControllerProvider, mainHandlerProvider, bgHandlerProvider);
  }

  public static BatteryController provideBatteryController(Context context,
      EnhancedEstimates enhancedEstimates, PowerManager powerManager,
      BroadcastDispatcher broadcastDispatcher, DemoModeController demoModeController,
      Handler mainHandler, Handler bgHandler) {
    return Preconditions.checkNotNullFromProvides(TvSystemUIModule.provideBatteryController(context, enhancedEstimates, powerManager, broadcastDispatcher, demoModeController, mainHandler, bgHandler));
  }
}

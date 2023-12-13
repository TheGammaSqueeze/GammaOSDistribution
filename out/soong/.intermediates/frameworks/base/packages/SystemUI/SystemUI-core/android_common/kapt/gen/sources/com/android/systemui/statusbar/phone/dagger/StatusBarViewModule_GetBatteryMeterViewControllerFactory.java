package com.android.systemui.statusbar.phone.dagger;

import android.content.ContentResolver;
import android.os.Handler;
import com.android.systemui.battery.BatteryMeterView;
import com.android.systemui.battery.BatteryMeterViewController;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.tuner.TunerService;
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
public final class StatusBarViewModule_GetBatteryMeterViewControllerFactory implements Factory<BatteryMeterViewController> {
  private final Provider<BatteryMeterView> batteryMeterViewProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<ContentResolver> contentResolverProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  public StatusBarViewModule_GetBatteryMeterViewControllerFactory(
      Provider<BatteryMeterView> batteryMeterViewProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> mainHandlerProvider, Provider<ContentResolver> contentResolverProvider,
      Provider<BatteryController> batteryControllerProvider) {
    this.batteryMeterViewProvider = batteryMeterViewProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.contentResolverProvider = contentResolverProvider;
    this.batteryControllerProvider = batteryControllerProvider;
  }

  @Override
  public BatteryMeterViewController get() {
    return getBatteryMeterViewController(batteryMeterViewProvider.get(), configurationControllerProvider.get(), tunerServiceProvider.get(), broadcastDispatcherProvider.get(), mainHandlerProvider.get(), contentResolverProvider.get(), batteryControllerProvider.get());
  }

  public static StatusBarViewModule_GetBatteryMeterViewControllerFactory create(
      Provider<BatteryMeterView> batteryMeterViewProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> mainHandlerProvider, Provider<ContentResolver> contentResolverProvider,
      Provider<BatteryController> batteryControllerProvider) {
    return new StatusBarViewModule_GetBatteryMeterViewControllerFactory(batteryMeterViewProvider, configurationControllerProvider, tunerServiceProvider, broadcastDispatcherProvider, mainHandlerProvider, contentResolverProvider, batteryControllerProvider);
  }

  public static BatteryMeterViewController getBatteryMeterViewController(
      BatteryMeterView batteryMeterView, ConfigurationController configurationController,
      TunerService tunerService, BroadcastDispatcher broadcastDispatcher, Handler mainHandler,
      ContentResolver contentResolver, BatteryController batteryController) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.getBatteryMeterViewController(batteryMeterView, configurationController, tunerService, broadcastDispatcher, mainHandler, contentResolver, batteryController));
  }
}

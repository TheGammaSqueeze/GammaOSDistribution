package com.android.systemui.battery;

import android.content.ContentResolver;
import android.os.Handler;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.tuner.TunerService;
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
public final class BatteryMeterViewController_Factory implements Factory<BatteryMeterViewController> {
  private final Provider<BatteryMeterView> viewProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<ContentResolver> contentResolverProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  public BatteryMeterViewController_Factory(Provider<BatteryMeterView> viewProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> mainHandlerProvider, Provider<ContentResolver> contentResolverProvider,
      Provider<BatteryController> batteryControllerProvider) {
    this.viewProvider = viewProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.contentResolverProvider = contentResolverProvider;
    this.batteryControllerProvider = batteryControllerProvider;
  }

  @Override
  public BatteryMeterViewController get() {
    return newInstance(viewProvider.get(), configurationControllerProvider.get(), tunerServiceProvider.get(), broadcastDispatcherProvider.get(), mainHandlerProvider.get(), contentResolverProvider.get(), batteryControllerProvider.get());
  }

  public static BatteryMeterViewController_Factory create(Provider<BatteryMeterView> viewProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> mainHandlerProvider, Provider<ContentResolver> contentResolverProvider,
      Provider<BatteryController> batteryControllerProvider) {
    return new BatteryMeterViewController_Factory(viewProvider, configurationControllerProvider, tunerServiceProvider, broadcastDispatcherProvider, mainHandlerProvider, contentResolverProvider, batteryControllerProvider);
  }

  public static BatteryMeterViewController newInstance(BatteryMeterView view,
      ConfigurationController configurationController, TunerService tunerService,
      BroadcastDispatcher broadcastDispatcher, Handler mainHandler, ContentResolver contentResolver,
      BatteryController batteryController) {
    return new BatteryMeterViewController(view, configurationController, tunerService, broadcastDispatcher, mainHandler, contentResolver, batteryController);
  }
}

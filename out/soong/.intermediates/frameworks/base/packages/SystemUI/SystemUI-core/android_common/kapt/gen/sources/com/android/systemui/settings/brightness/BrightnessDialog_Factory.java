package com.android.systemui.settings.brightness;

import android.os.Handler;
import com.android.systemui.broadcast.BroadcastDispatcher;
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
public final class BrightnessDialog_Factory implements Factory<BrightnessDialog> {
  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<BrightnessSliderController.Factory> factoryProvider;

  private final Provider<Handler> bgHandlerProvider;

  public BrightnessDialog_Factory(Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<BrightnessSliderController.Factory> factoryProvider,
      Provider<Handler> bgHandlerProvider) {
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.factoryProvider = factoryProvider;
    this.bgHandlerProvider = bgHandlerProvider;
  }

  @Override
  public BrightnessDialog get() {
    return newInstance(broadcastDispatcherProvider.get(), factoryProvider.get(), bgHandlerProvider.get());
  }

  public static BrightnessDialog_Factory create(
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<BrightnessSliderController.Factory> factoryProvider,
      Provider<Handler> bgHandlerProvider) {
    return new BrightnessDialog_Factory(broadcastDispatcherProvider, factoryProvider, bgHandlerProvider);
  }

  public static BrightnessDialog newInstance(BroadcastDispatcher broadcastDispatcher,
      BrightnessSliderController.Factory factory, Handler bgHandler) {
    return new BrightnessDialog(broadcastDispatcher, factory, bgHandler);
  }
}

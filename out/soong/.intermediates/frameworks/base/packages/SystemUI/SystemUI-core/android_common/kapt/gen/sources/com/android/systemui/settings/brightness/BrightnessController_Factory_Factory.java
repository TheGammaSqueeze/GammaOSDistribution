package com.android.systemui.settings.brightness;

import android.content.Context;
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
public final class BrightnessController_Factory_Factory implements Factory<BrightnessController.Factory> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Handler> bgHandlerProvider;

  public BrightnessController_Factory_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> bgHandlerProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.bgHandlerProvider = bgHandlerProvider;
  }

  @Override
  public BrightnessController.Factory get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get(), bgHandlerProvider.get());
  }

  public static BrightnessController_Factory_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> bgHandlerProvider) {
    return new BrightnessController_Factory_Factory(contextProvider, broadcastDispatcherProvider, bgHandlerProvider);
  }

  public static BrightnessController.Factory newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher, Handler bgHandler) {
    return new BrightnessController.Factory(context, broadcastDispatcher, bgHandler);
  }
}

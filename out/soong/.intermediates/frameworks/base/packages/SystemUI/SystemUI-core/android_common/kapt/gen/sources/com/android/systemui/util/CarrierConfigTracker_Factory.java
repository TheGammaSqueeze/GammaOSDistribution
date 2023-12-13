package com.android.systemui.util;

import android.content.Context;
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
public final class CarrierConfigTracker_Factory implements Factory<CarrierConfigTracker> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  public CarrierConfigTracker_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
  }

  @Override
  public CarrierConfigTracker get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get());
  }

  public static CarrierConfigTracker_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    return new CarrierConfigTracker_Factory(contextProvider, broadcastDispatcherProvider);
  }

  public static CarrierConfigTracker newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher) {
    return new CarrierConfigTracker(context, broadcastDispatcher);
  }
}

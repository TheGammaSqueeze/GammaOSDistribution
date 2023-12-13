package com.android.systemui.statusbar.policy;

import android.os.Handler;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.util.time.SystemClock;
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
public final class VariableDateViewController_Factory_Factory implements Factory<VariableDateViewController.Factory> {
  private final Provider<SystemClock> systemClockProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Handler> handlerProvider;

  public VariableDateViewController_Factory_Factory(Provider<SystemClock> systemClockProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> handlerProvider) {
    this.systemClockProvider = systemClockProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.handlerProvider = handlerProvider;
  }

  @Override
  public VariableDateViewController.Factory get() {
    return newInstance(systemClockProvider.get(), broadcastDispatcherProvider.get(), handlerProvider.get());
  }

  public static VariableDateViewController_Factory_Factory create(
      Provider<SystemClock> systemClockProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> handlerProvider) {
    return new VariableDateViewController_Factory_Factory(systemClockProvider, broadcastDispatcherProvider, handlerProvider);
  }

  public static VariableDateViewController.Factory newInstance(SystemClock systemClock,
      BroadcastDispatcher broadcastDispatcher, Handler handler) {
    return new VariableDateViewController.Factory(systemClock, broadcastDispatcher, handler);
  }
}

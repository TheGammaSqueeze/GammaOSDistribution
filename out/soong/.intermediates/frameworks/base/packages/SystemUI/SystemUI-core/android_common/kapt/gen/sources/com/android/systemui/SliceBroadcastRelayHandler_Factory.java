package com.android.systemui;

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
public final class SliceBroadcastRelayHandler_Factory implements Factory<SliceBroadcastRelayHandler> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  public SliceBroadcastRelayHandler_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
  }

  @Override
  public SliceBroadcastRelayHandler get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get());
  }

  public static SliceBroadcastRelayHandler_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    return new SliceBroadcastRelayHandler_Factory(contextProvider, broadcastDispatcherProvider);
  }

  public static SliceBroadcastRelayHandler newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher) {
    return new SliceBroadcastRelayHandler(context, broadcastDispatcher);
  }
}

package com.android.systemui.power;

import android.content.Context;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.phone.StatusBar;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class PowerUI_Factory implements Factory<PowerUI> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  public PowerUI_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
  }

  @Override
  public PowerUI get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get(), commandQueueProvider.get(), DoubleCheck.lazy(statusBarOptionalLazyProvider));
  }

  public static PowerUI_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    return new PowerUI_Factory(contextProvider, broadcastDispatcherProvider, commandQueueProvider, statusBarOptionalLazyProvider);
  }

  public static PowerUI newInstance(Context context, BroadcastDispatcher broadcastDispatcher,
      CommandQueue commandQueue, Lazy<Optional<StatusBar>> statusBarOptionalLazy) {
    return new PowerUI(context, broadcastDispatcher, commandQueue, statusBarOptionalLazy);
  }
}

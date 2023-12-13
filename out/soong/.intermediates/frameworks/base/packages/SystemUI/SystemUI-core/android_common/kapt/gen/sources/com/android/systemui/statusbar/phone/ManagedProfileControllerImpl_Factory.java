package com.android.systemui.statusbar.phone;

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
public final class ManagedProfileControllerImpl_Factory implements Factory<ManagedProfileControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  public ManagedProfileControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
  }

  @Override
  public ManagedProfileControllerImpl get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get());
  }

  public static ManagedProfileControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    return new ManagedProfileControllerImpl_Factory(contextProvider, broadcastDispatcherProvider);
  }

  public static ManagedProfileControllerImpl newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher) {
    return new ManagedProfileControllerImpl(context, broadcastDispatcher);
  }
}

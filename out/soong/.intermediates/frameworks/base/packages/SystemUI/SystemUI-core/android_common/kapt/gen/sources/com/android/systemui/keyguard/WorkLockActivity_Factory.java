package com.android.systemui.keyguard;

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
public final class WorkLockActivity_Factory implements Factory<WorkLockActivity> {
  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  public WorkLockActivity_Factory(Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
  }

  @Override
  public WorkLockActivity get() {
    return newInstance(broadcastDispatcherProvider.get());
  }

  public static WorkLockActivity_Factory create(
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    return new WorkLockActivity_Factory(broadcastDispatcherProvider);
  }

  public static WorkLockActivity newInstance(BroadcastDispatcher broadcastDispatcher) {
    return new WorkLockActivity(broadcastDispatcher);
  }
}

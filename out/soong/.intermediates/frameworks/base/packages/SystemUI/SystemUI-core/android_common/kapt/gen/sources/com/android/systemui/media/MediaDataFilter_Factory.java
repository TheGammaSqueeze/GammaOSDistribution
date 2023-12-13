package com.android.systemui.media;

import android.content.Context;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.util.time.SystemClock;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
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
public final class MediaDataFilter_Factory implements Factory<MediaDataFilter> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<SystemClock> systemClockProvider;

  public MediaDataFilter_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<Executor> executorProvider, Provider<SystemClock> systemClockProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.lockscreenUserManagerProvider = lockscreenUserManagerProvider;
    this.executorProvider = executorProvider;
    this.systemClockProvider = systemClockProvider;
  }

  @Override
  public MediaDataFilter get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get(), lockscreenUserManagerProvider.get(), executorProvider.get(), systemClockProvider.get());
  }

  public static MediaDataFilter_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<Executor> executorProvider, Provider<SystemClock> systemClockProvider) {
    return new MediaDataFilter_Factory(contextProvider, broadcastDispatcherProvider, lockscreenUserManagerProvider, executorProvider, systemClockProvider);
  }

  public static MediaDataFilter newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher,
      NotificationLockscreenUserManager lockscreenUserManager, Executor executor,
      SystemClock systemClock) {
    return new MediaDataFilter(context, broadcastDispatcher, lockscreenUserManager, executor, systemClock);
  }
}

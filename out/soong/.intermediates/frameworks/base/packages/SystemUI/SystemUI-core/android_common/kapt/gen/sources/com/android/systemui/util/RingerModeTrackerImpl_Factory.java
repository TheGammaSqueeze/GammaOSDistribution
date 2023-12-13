package com.android.systemui.util;

import android.media.AudioManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
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
public final class RingerModeTrackerImpl_Factory implements Factory<RingerModeTrackerImpl> {
  private final Provider<AudioManager> audioManagerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Executor> executorProvider;

  public RingerModeTrackerImpl_Factory(Provider<AudioManager> audioManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> executorProvider) {
    this.audioManagerProvider = audioManagerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.executorProvider = executorProvider;
  }

  @Override
  public RingerModeTrackerImpl get() {
    return newInstance(audioManagerProvider.get(), broadcastDispatcherProvider.get(), executorProvider.get());
  }

  public static RingerModeTrackerImpl_Factory create(Provider<AudioManager> audioManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> executorProvider) {
    return new RingerModeTrackerImpl_Factory(audioManagerProvider, broadcastDispatcherProvider, executorProvider);
  }

  public static RingerModeTrackerImpl newInstance(AudioManager audioManager,
      BroadcastDispatcher broadcastDispatcher, Executor executor) {
    return new RingerModeTrackerImpl(audioManager, broadcastDispatcher, executor);
  }
}

package com.android.systemui.media;

import android.content.Context;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.tuner.TunerService;
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
public final class MediaResumeListener_Factory implements Factory<MediaResumeListener> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<ResumeMediaBrowserFactory> mediaBrowserFactoryProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<SystemClock> systemClockProvider;

  public MediaResumeListener_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> backgroundExecutorProvider, Provider<TunerService> tunerServiceProvider,
      Provider<ResumeMediaBrowserFactory> mediaBrowserFactoryProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<SystemClock> systemClockProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.mediaBrowserFactoryProvider = mediaBrowserFactoryProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.systemClockProvider = systemClockProvider;
  }

  @Override
  public MediaResumeListener get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get(), backgroundExecutorProvider.get(), tunerServiceProvider.get(), mediaBrowserFactoryProvider.get(), dumpManagerProvider.get(), systemClockProvider.get());
  }

  public static MediaResumeListener_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> backgroundExecutorProvider, Provider<TunerService> tunerServiceProvider,
      Provider<ResumeMediaBrowserFactory> mediaBrowserFactoryProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<SystemClock> systemClockProvider) {
    return new MediaResumeListener_Factory(contextProvider, broadcastDispatcherProvider, backgroundExecutorProvider, tunerServiceProvider, mediaBrowserFactoryProvider, dumpManagerProvider, systemClockProvider);
  }

  public static MediaResumeListener newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher, Executor backgroundExecutor,
      TunerService tunerService, ResumeMediaBrowserFactory mediaBrowserFactory,
      DumpManager dumpManager, SystemClock systemClock) {
    return new MediaResumeListener(context, broadcastDispatcher, backgroundExecutor, tunerService, mediaBrowserFactory, dumpManager, systemClock);
  }
}

package com.android.systemui.media;

import android.content.Context;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class MediaDataManager_Factory implements Factory<MediaDataManager> {
  private final Provider<Context> contextProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  private final Provider<DelayableExecutor> foregroundExecutorProvider;

  private final Provider<MediaControllerFactory> mediaControllerFactoryProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<MediaTimeoutListener> mediaTimeoutListenerProvider;

  private final Provider<MediaResumeListener> mediaResumeListenerProvider;

  private final Provider<MediaSessionBasedFilter> mediaSessionBasedFilterProvider;

  private final Provider<MediaDeviceManager> mediaDeviceManagerProvider;

  private final Provider<MediaDataCombineLatest> mediaDataCombineLatestProvider;

  private final Provider<MediaDataFilter> mediaDataFilterProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<SmartspaceMediaDataProvider> smartspaceMediaDataProvider;

  private final Provider<SystemClock> clockProvider;

  private final Provider<TunerService> tunerServiceProvider;

  public MediaDataManager_Factory(Provider<Context> contextProvider,
      Provider<Executor> backgroundExecutorProvider,
      Provider<DelayableExecutor> foregroundExecutorProvider,
      Provider<MediaControllerFactory> mediaControllerFactoryProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<MediaTimeoutListener> mediaTimeoutListenerProvider,
      Provider<MediaResumeListener> mediaResumeListenerProvider,
      Provider<MediaSessionBasedFilter> mediaSessionBasedFilterProvider,
      Provider<MediaDeviceManager> mediaDeviceManagerProvider,
      Provider<MediaDataCombineLatest> mediaDataCombineLatestProvider,
      Provider<MediaDataFilter> mediaDataFilterProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<SmartspaceMediaDataProvider> smartspaceMediaDataProvider,
      Provider<SystemClock> clockProvider, Provider<TunerService> tunerServiceProvider) {
    this.contextProvider = contextProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
    this.foregroundExecutorProvider = foregroundExecutorProvider;
    this.mediaControllerFactoryProvider = mediaControllerFactoryProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.mediaTimeoutListenerProvider = mediaTimeoutListenerProvider;
    this.mediaResumeListenerProvider = mediaResumeListenerProvider;
    this.mediaSessionBasedFilterProvider = mediaSessionBasedFilterProvider;
    this.mediaDeviceManagerProvider = mediaDeviceManagerProvider;
    this.mediaDataCombineLatestProvider = mediaDataCombineLatestProvider;
    this.mediaDataFilterProvider = mediaDataFilterProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.smartspaceMediaDataProvider = smartspaceMediaDataProvider;
    this.clockProvider = clockProvider;
    this.tunerServiceProvider = tunerServiceProvider;
  }

  @Override
  public MediaDataManager get() {
    return newInstance(contextProvider.get(), backgroundExecutorProvider.get(), foregroundExecutorProvider.get(), mediaControllerFactoryProvider.get(), dumpManagerProvider.get(), broadcastDispatcherProvider.get(), mediaTimeoutListenerProvider.get(), mediaResumeListenerProvider.get(), mediaSessionBasedFilterProvider.get(), mediaDeviceManagerProvider.get(), mediaDataCombineLatestProvider.get(), mediaDataFilterProvider.get(), activityStarterProvider.get(), smartspaceMediaDataProvider.get(), clockProvider.get(), tunerServiceProvider.get());
  }

  public static MediaDataManager_Factory create(Provider<Context> contextProvider,
      Provider<Executor> backgroundExecutorProvider,
      Provider<DelayableExecutor> foregroundExecutorProvider,
      Provider<MediaControllerFactory> mediaControllerFactoryProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<MediaTimeoutListener> mediaTimeoutListenerProvider,
      Provider<MediaResumeListener> mediaResumeListenerProvider,
      Provider<MediaSessionBasedFilter> mediaSessionBasedFilterProvider,
      Provider<MediaDeviceManager> mediaDeviceManagerProvider,
      Provider<MediaDataCombineLatest> mediaDataCombineLatestProvider,
      Provider<MediaDataFilter> mediaDataFilterProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<SmartspaceMediaDataProvider> smartspaceMediaDataProvider,
      Provider<SystemClock> clockProvider, Provider<TunerService> tunerServiceProvider) {
    return new MediaDataManager_Factory(contextProvider, backgroundExecutorProvider, foregroundExecutorProvider, mediaControllerFactoryProvider, dumpManagerProvider, broadcastDispatcherProvider, mediaTimeoutListenerProvider, mediaResumeListenerProvider, mediaSessionBasedFilterProvider, mediaDeviceManagerProvider, mediaDataCombineLatestProvider, mediaDataFilterProvider, activityStarterProvider, smartspaceMediaDataProvider, clockProvider, tunerServiceProvider);
  }

  public static MediaDataManager newInstance(Context context, Executor backgroundExecutor,
      DelayableExecutor foregroundExecutor, MediaControllerFactory mediaControllerFactory,
      DumpManager dumpManager, BroadcastDispatcher broadcastDispatcher,
      MediaTimeoutListener mediaTimeoutListener, MediaResumeListener mediaResumeListener,
      MediaSessionBasedFilter mediaSessionBasedFilter, MediaDeviceManager mediaDeviceManager,
      MediaDataCombineLatest mediaDataCombineLatest, MediaDataFilter mediaDataFilter,
      ActivityStarter activityStarter, SmartspaceMediaDataProvider smartspaceMediaDataProvider,
      SystemClock clock, TunerService tunerService) {
    return new MediaDataManager(context, backgroundExecutor, foregroundExecutor, mediaControllerFactory, dumpManager, broadcastDispatcher, mediaTimeoutListener, mediaResumeListener, mediaSessionBasedFilter, mediaDeviceManager, mediaDataCombineLatest, mediaDataFilter, activityStarter, smartspaceMediaDataProvider, clock, tunerService);
  }
}

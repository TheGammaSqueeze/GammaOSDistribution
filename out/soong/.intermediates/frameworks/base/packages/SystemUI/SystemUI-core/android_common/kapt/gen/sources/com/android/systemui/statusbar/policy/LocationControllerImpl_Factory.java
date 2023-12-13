package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import com.android.systemui.BootCompleteCache;
import com.android.systemui.appops.AppOpsController;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.settings.UserTracker;
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
public final class LocationControllerImpl_Factory implements Factory<LocationControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<AppOpsController> appOpsControllerProvider;

  private final Provider<Looper> mainLooperProvider;

  private final Provider<Handler> backgroundHandlerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<BootCompleteCache> bootCompleteCacheProvider;

  private final Provider<UserTracker> userTrackerProvider;

  public LocationControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<AppOpsController> appOpsControllerProvider, Provider<Looper> mainLooperProvider,
      Provider<Handler> backgroundHandlerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<BootCompleteCache> bootCompleteCacheProvider,
      Provider<UserTracker> userTrackerProvider) {
    this.contextProvider = contextProvider;
    this.appOpsControllerProvider = appOpsControllerProvider;
    this.mainLooperProvider = mainLooperProvider;
    this.backgroundHandlerProvider = backgroundHandlerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.bootCompleteCacheProvider = bootCompleteCacheProvider;
    this.userTrackerProvider = userTrackerProvider;
  }

  @Override
  public LocationControllerImpl get() {
    return newInstance(contextProvider.get(), appOpsControllerProvider.get(), mainLooperProvider.get(), backgroundHandlerProvider.get(), broadcastDispatcherProvider.get(), bootCompleteCacheProvider.get(), userTrackerProvider.get());
  }

  public static LocationControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<AppOpsController> appOpsControllerProvider, Provider<Looper> mainLooperProvider,
      Provider<Handler> backgroundHandlerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<BootCompleteCache> bootCompleteCacheProvider,
      Provider<UserTracker> userTrackerProvider) {
    return new LocationControllerImpl_Factory(contextProvider, appOpsControllerProvider, mainLooperProvider, backgroundHandlerProvider, broadcastDispatcherProvider, bootCompleteCacheProvider, userTrackerProvider);
  }

  public static LocationControllerImpl newInstance(Context context,
      AppOpsController appOpsController, Looper mainLooper, Handler backgroundHandler,
      BroadcastDispatcher broadcastDispatcher, BootCompleteCache bootCompleteCache,
      UserTracker userTracker) {
    return new LocationControllerImpl(context, appOpsController, mainLooper, backgroundHandler, broadcastDispatcher, bootCompleteCache, userTracker);
  }
}

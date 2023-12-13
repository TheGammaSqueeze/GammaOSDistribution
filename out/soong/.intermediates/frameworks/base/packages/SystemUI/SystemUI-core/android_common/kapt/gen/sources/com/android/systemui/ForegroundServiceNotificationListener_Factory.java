package com.android.systemui;

import android.content.Context;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
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
public final class ForegroundServiceNotificationListener_Factory implements Factory<ForegroundServiceNotificationListener> {
  private final Provider<Context> contextProvider;

  private final Provider<ForegroundServiceController> foregroundServiceControllerProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<NotifPipeline> notifPipelineProvider;

  private final Provider<SystemClock> systemClockProvider;

  public ForegroundServiceNotificationListener_Factory(Provider<Context> contextProvider,
      Provider<ForegroundServiceController> foregroundServiceControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider, Provider<SystemClock> systemClockProvider) {
    this.contextProvider = contextProvider;
    this.foregroundServiceControllerProvider = foregroundServiceControllerProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.notifPipelineProvider = notifPipelineProvider;
    this.systemClockProvider = systemClockProvider;
  }

  @Override
  public ForegroundServiceNotificationListener get() {
    return newInstance(contextProvider.get(), foregroundServiceControllerProvider.get(), notificationEntryManagerProvider.get(), notifPipelineProvider.get(), systemClockProvider.get());
  }

  public static ForegroundServiceNotificationListener_Factory create(
      Provider<Context> contextProvider,
      Provider<ForegroundServiceController> foregroundServiceControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider, Provider<SystemClock> systemClockProvider) {
    return new ForegroundServiceNotificationListener_Factory(contextProvider, foregroundServiceControllerProvider, notificationEntryManagerProvider, notifPipelineProvider, systemClockProvider);
  }

  public static ForegroundServiceNotificationListener newInstance(Context context,
      ForegroundServiceController foregroundServiceController,
      NotificationEntryManager notificationEntryManager, NotifPipeline notifPipeline,
      SystemClock systemClock) {
    return new ForegroundServiceNotificationListener(context, foregroundServiceController, notificationEntryManager, notifPipeline, systemClock);
  }
}

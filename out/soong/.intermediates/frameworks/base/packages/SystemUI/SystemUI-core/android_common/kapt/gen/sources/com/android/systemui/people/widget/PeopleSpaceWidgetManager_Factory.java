package com.android.systemui.people.widget;

import android.app.NotificationManager;
import android.content.Context;
import android.content.pm.LauncherApps;
import android.content.pm.PackageManager;
import android.os.UserManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.wm.shell.bubbles.Bubbles;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class PeopleSpaceWidgetManager_Factory implements Factory<PeopleSpaceWidgetManager> {
  private final Provider<Context> contextProvider;

  private final Provider<LauncherApps> launcherAppsProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<PackageManager> packageManagerProvider;

  private final Provider<Optional<Bubbles>> bubblesOptionalProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<NotificationManager> notificationManagerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Executor> bgExecutorProvider;

  public PeopleSpaceWidgetManager_Factory(Provider<Context> contextProvider,
      Provider<LauncherApps> launcherAppsProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<UserManager> userManagerProvider,
      Provider<NotificationManager> notificationManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> bgExecutorProvider) {
    this.contextProvider = contextProvider;
    this.launcherAppsProvider = launcherAppsProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.packageManagerProvider = packageManagerProvider;
    this.bubblesOptionalProvider = bubblesOptionalProvider;
    this.userManagerProvider = userManagerProvider;
    this.notificationManagerProvider = notificationManagerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.bgExecutorProvider = bgExecutorProvider;
  }

  @Override
  public PeopleSpaceWidgetManager get() {
    return newInstance(contextProvider.get(), launcherAppsProvider.get(), notificationEntryManagerProvider.get(), packageManagerProvider.get(), bubblesOptionalProvider.get(), userManagerProvider.get(), notificationManagerProvider.get(), broadcastDispatcherProvider.get(), bgExecutorProvider.get());
  }

  public static PeopleSpaceWidgetManager_Factory create(Provider<Context> contextProvider,
      Provider<LauncherApps> launcherAppsProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<UserManager> userManagerProvider,
      Provider<NotificationManager> notificationManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> bgExecutorProvider) {
    return new PeopleSpaceWidgetManager_Factory(contextProvider, launcherAppsProvider, notificationEntryManagerProvider, packageManagerProvider, bubblesOptionalProvider, userManagerProvider, notificationManagerProvider, broadcastDispatcherProvider, bgExecutorProvider);
  }

  public static PeopleSpaceWidgetManager newInstance(Context context, LauncherApps launcherApps,
      NotificationEntryManager notificationEntryManager, PackageManager packageManager,
      Optional<Bubbles> bubblesOptional, UserManager userManager,
      NotificationManager notificationManager, BroadcastDispatcher broadcastDispatcher,
      Executor bgExecutor) {
    return new PeopleSpaceWidgetManager(context, launcherApps, notificationEntryManager, packageManager, bubblesOptional, userManager, notificationManager, broadcastDispatcher, bgExecutor);
  }
}

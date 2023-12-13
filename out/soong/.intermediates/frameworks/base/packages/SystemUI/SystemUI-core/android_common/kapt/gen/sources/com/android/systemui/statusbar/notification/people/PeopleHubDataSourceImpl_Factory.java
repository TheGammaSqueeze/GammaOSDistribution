package com.android.systemui.statusbar.notification.people;

import android.content.Context;
import android.content.pm.LauncherApps;
import android.content.pm.PackageManager;
import android.os.UserManager;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
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
public final class PeopleHubDataSourceImpl_Factory implements Factory<PeopleHubDataSourceImpl> {
  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<NotificationPersonExtractor> extractorProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<LauncherApps> launcherAppsProvider;

  private final Provider<PackageManager> packageManagerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<NotificationListener> notificationListenerProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<NotificationLockscreenUserManager> notifLockscreenUserMgrProvider;

  private final Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider;

  public PeopleHubDataSourceImpl_Factory(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotificationPersonExtractor> extractorProvider,
      Provider<UserManager> userManagerProvider, Provider<LauncherApps> launcherAppsProvider,
      Provider<PackageManager> packageManagerProvider, Provider<Context> contextProvider,
      Provider<NotificationListener> notificationListenerProvider,
      Provider<Executor> bgExecutorProvider, Provider<Executor> mainExecutorProvider,
      Provider<NotificationLockscreenUserManager> notifLockscreenUserMgrProvider,
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider) {
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.extractorProvider = extractorProvider;
    this.userManagerProvider = userManagerProvider;
    this.launcherAppsProvider = launcherAppsProvider;
    this.packageManagerProvider = packageManagerProvider;
    this.contextProvider = contextProvider;
    this.notificationListenerProvider = notificationListenerProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.notifLockscreenUserMgrProvider = notifLockscreenUserMgrProvider;
    this.peopleNotificationIdentifierProvider = peopleNotificationIdentifierProvider;
  }

  @Override
  public PeopleHubDataSourceImpl get() {
    return newInstance(notificationEntryManagerProvider.get(), extractorProvider.get(), userManagerProvider.get(), launcherAppsProvider.get(), packageManagerProvider.get(), contextProvider.get(), notificationListenerProvider.get(), bgExecutorProvider.get(), mainExecutorProvider.get(), notifLockscreenUserMgrProvider.get(), peopleNotificationIdentifierProvider.get());
  }

  public static PeopleHubDataSourceImpl_Factory create(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotificationPersonExtractor> extractorProvider,
      Provider<UserManager> userManagerProvider, Provider<LauncherApps> launcherAppsProvider,
      Provider<PackageManager> packageManagerProvider, Provider<Context> contextProvider,
      Provider<NotificationListener> notificationListenerProvider,
      Provider<Executor> bgExecutorProvider, Provider<Executor> mainExecutorProvider,
      Provider<NotificationLockscreenUserManager> notifLockscreenUserMgrProvider,
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider) {
    return new PeopleHubDataSourceImpl_Factory(notificationEntryManagerProvider, extractorProvider, userManagerProvider, launcherAppsProvider, packageManagerProvider, contextProvider, notificationListenerProvider, bgExecutorProvider, mainExecutorProvider, notifLockscreenUserMgrProvider, peopleNotificationIdentifierProvider);
  }

  public static PeopleHubDataSourceImpl newInstance(
      NotificationEntryManager notificationEntryManager, NotificationPersonExtractor extractor,
      UserManager userManager, LauncherApps launcherApps, PackageManager packageManager,
      Context context, NotificationListener notificationListener, Executor bgExecutor,
      Executor mainExecutor, NotificationLockscreenUserManager notifLockscreenUserMgr,
      PeopleNotificationIdentifier peopleNotificationIdentifier) {
    return new PeopleHubDataSourceImpl(notificationEntryManager, extractor, userManager, launcherApps, packageManager, context, notificationListener, bgExecutor, mainExecutor, notifLockscreenUserMgr, peopleNotificationIdentifier);
  }
}

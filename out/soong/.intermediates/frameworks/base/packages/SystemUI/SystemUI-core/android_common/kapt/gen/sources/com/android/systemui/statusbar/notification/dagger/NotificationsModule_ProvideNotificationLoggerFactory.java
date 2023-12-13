package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.logging.NotificationLogger;
import com.android.systemui.statusbar.notification.logging.NotificationPanelLogger;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class NotificationsModule_ProvideNotificationLoggerFactory implements Factory<NotificationLogger> {
  private final Provider<NotificationListener> notificationListenerProvider;

  private final Provider<Executor> uiBgExecutorProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationLogger.ExpansionStateLogger> expansionStateLoggerProvider;

  private final Provider<NotificationPanelLogger> notificationPanelLoggerProvider;

  public NotificationsModule_ProvideNotificationLoggerFactory(
      Provider<NotificationListener> notificationListenerProvider,
      Provider<Executor> uiBgExecutorProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationLogger.ExpansionStateLogger> expansionStateLoggerProvider,
      Provider<NotificationPanelLogger> notificationPanelLoggerProvider) {
    this.notificationListenerProvider = notificationListenerProvider;
    this.uiBgExecutorProvider = uiBgExecutorProvider;
    this.entryManagerProvider = entryManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.expansionStateLoggerProvider = expansionStateLoggerProvider;
    this.notificationPanelLoggerProvider = notificationPanelLoggerProvider;
  }

  @Override
  public NotificationLogger get() {
    return provideNotificationLogger(notificationListenerProvider.get(), uiBgExecutorProvider.get(), entryManagerProvider.get(), statusBarStateControllerProvider.get(), expansionStateLoggerProvider.get(), notificationPanelLoggerProvider.get());
  }

  public static NotificationsModule_ProvideNotificationLoggerFactory create(
      Provider<NotificationListener> notificationListenerProvider,
      Provider<Executor> uiBgExecutorProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationLogger.ExpansionStateLogger> expansionStateLoggerProvider,
      Provider<NotificationPanelLogger> notificationPanelLoggerProvider) {
    return new NotificationsModule_ProvideNotificationLoggerFactory(notificationListenerProvider, uiBgExecutorProvider, entryManagerProvider, statusBarStateControllerProvider, expansionStateLoggerProvider, notificationPanelLoggerProvider);
  }

  public static NotificationLogger provideNotificationLogger(
      NotificationListener notificationListener, Executor uiBgExecutor,
      NotificationEntryManager entryManager, StatusBarStateController statusBarStateController,
      NotificationLogger.ExpansionStateLogger expansionStateLogger,
      NotificationPanelLogger notificationPanelLogger) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideNotificationLogger(notificationListener, uiBgExecutor, entryManager, statusBarStateController, expansionStateLogger, notificationPanelLogger));
  }
}

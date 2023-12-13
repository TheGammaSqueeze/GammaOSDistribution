package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.lockscreen.LockscreenSmartspaceController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class SmartspaceDedupingCoordinator_Factory implements Factory<SmartspaceDedupingCoordinator> {
  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<LockscreenSmartspaceController> smartspaceControllerProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider;

  private final Provider<NotifPipeline> notifPipelineProvider;

  private final Provider<DelayableExecutor> executorProvider;

  private final Provider<SystemClock> clockProvider;

  public SmartspaceDedupingCoordinator_Factory(
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<LockscreenSmartspaceController> smartspaceControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider, Provider<DelayableExecutor> executorProvider,
      Provider<SystemClock> clockProvider) {
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.smartspaceControllerProvider = smartspaceControllerProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.notificationLockscreenUserManagerProvider = notificationLockscreenUserManagerProvider;
    this.notifPipelineProvider = notifPipelineProvider;
    this.executorProvider = executorProvider;
    this.clockProvider = clockProvider;
  }

  @Override
  public SmartspaceDedupingCoordinator get() {
    return newInstance(statusBarStateControllerProvider.get(), smartspaceControllerProvider.get(), notificationEntryManagerProvider.get(), notificationLockscreenUserManagerProvider.get(), notifPipelineProvider.get(), executorProvider.get(), clockProvider.get());
  }

  public static SmartspaceDedupingCoordinator_Factory create(
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<LockscreenSmartspaceController> smartspaceControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider, Provider<DelayableExecutor> executorProvider,
      Provider<SystemClock> clockProvider) {
    return new SmartspaceDedupingCoordinator_Factory(statusBarStateControllerProvider, smartspaceControllerProvider, notificationEntryManagerProvider, notificationLockscreenUserManagerProvider, notifPipelineProvider, executorProvider, clockProvider);
  }

  public static SmartspaceDedupingCoordinator newInstance(
      SysuiStatusBarStateController statusBarStateController,
      LockscreenSmartspaceController smartspaceController,
      NotificationEntryManager notificationEntryManager,
      NotificationLockscreenUserManager notificationLockscreenUserManager,
      NotifPipeline notifPipeline, DelayableExecutor executor, SystemClock clock) {
    return new SmartspaceDedupingCoordinator(statusBarStateController, smartspaceController, notificationEntryManager, notificationLockscreenUserManager, notifPipeline, executor, clock);
  }
}

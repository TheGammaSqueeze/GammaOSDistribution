package com.android.systemui.statusbar.notification.dagger;

import android.os.Handler;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class NotificationsModule_ProvideVisualStabilityManagerFactory implements Factory<VisualStabilityManager> {
  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NotificationsModule_ProvideVisualStabilityManagerFactory(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<Handler> handlerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.handlerProvider = handlerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public VisualStabilityManager get() {
    return provideVisualStabilityManager(notificationEntryManagerProvider.get(), handlerProvider.get(), statusBarStateControllerProvider.get(), wakefulnessLifecycleProvider.get(), dumpManagerProvider.get());
  }

  public static NotificationsModule_ProvideVisualStabilityManagerFactory create(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<Handler> handlerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new NotificationsModule_ProvideVisualStabilityManagerFactory(notificationEntryManagerProvider, handlerProvider, statusBarStateControllerProvider, wakefulnessLifecycleProvider, dumpManagerProvider);
  }

  public static VisualStabilityManager provideVisualStabilityManager(
      NotificationEntryManager notificationEntryManager, Handler handler,
      StatusBarStateController statusBarStateController, WakefulnessLifecycle wakefulnessLifecycle,
      DumpManager dumpManager) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideVisualStabilityManager(notificationEntryManager, handler, statusBarStateController, wakefulnessLifecycle, dumpManager));
  }
}

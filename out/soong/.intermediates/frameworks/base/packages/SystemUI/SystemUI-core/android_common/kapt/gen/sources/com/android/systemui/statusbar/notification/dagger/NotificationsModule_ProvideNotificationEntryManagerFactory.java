package com.android.systemui.statusbar.notification.dagger;

import com.android.internal.statusbar.IStatusBarService;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.notification.ForegroundServiceDismissalFeatureController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.NotificationEntryManagerLogger;
import com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinder;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.util.leak.LeakDetector;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class NotificationsModule_ProvideNotificationEntryManagerFactory implements Factory<NotificationEntryManager> {
  private final Provider<NotificationEntryManagerLogger> loggerProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotificationRowBinder> notificationRowBinderLazyProvider;

  private final Provider<NotificationRemoteInputManager> notificationRemoteInputManagerLazyProvider;

  private final Provider<LeakDetector> leakDetectorProvider;

  private final Provider<ForegroundServiceDismissalFeatureController> fgsFeatureControllerProvider;

  private final Provider<IStatusBarService> statusBarServiceProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NotificationsModule_ProvideNotificationEntryManagerFactory(
      Provider<NotificationEntryManagerLogger> loggerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationRowBinder> notificationRowBinderLazyProvider,
      Provider<NotificationRemoteInputManager> notificationRemoteInputManagerLazyProvider,
      Provider<LeakDetector> leakDetectorProvider,
      Provider<ForegroundServiceDismissalFeatureController> fgsFeatureControllerProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.loggerProvider = loggerProvider;
    this.groupManagerProvider = groupManagerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.notificationRowBinderLazyProvider = notificationRowBinderLazyProvider;
    this.notificationRemoteInputManagerLazyProvider = notificationRemoteInputManagerLazyProvider;
    this.leakDetectorProvider = leakDetectorProvider;
    this.fgsFeatureControllerProvider = fgsFeatureControllerProvider;
    this.statusBarServiceProvider = statusBarServiceProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NotificationEntryManager get() {
    return provideNotificationEntryManager(loggerProvider.get(), groupManagerProvider.get(), featureFlagsProvider.get(), DoubleCheck.lazy(notificationRowBinderLazyProvider), DoubleCheck.lazy(notificationRemoteInputManagerLazyProvider), leakDetectorProvider.get(), fgsFeatureControllerProvider.get(), statusBarServiceProvider.get(), dumpManagerProvider.get());
  }

  public static NotificationsModule_ProvideNotificationEntryManagerFactory create(
      Provider<NotificationEntryManagerLogger> loggerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationRowBinder> notificationRowBinderLazyProvider,
      Provider<NotificationRemoteInputManager> notificationRemoteInputManagerLazyProvider,
      Provider<LeakDetector> leakDetectorProvider,
      Provider<ForegroundServiceDismissalFeatureController> fgsFeatureControllerProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new NotificationsModule_ProvideNotificationEntryManagerFactory(loggerProvider, groupManagerProvider, featureFlagsProvider, notificationRowBinderLazyProvider, notificationRemoteInputManagerLazyProvider, leakDetectorProvider, fgsFeatureControllerProvider, statusBarServiceProvider, dumpManagerProvider);
  }

  public static NotificationEntryManager provideNotificationEntryManager(
      NotificationEntryManagerLogger logger, NotificationGroupManagerLegacy groupManager,
      FeatureFlags featureFlags, Lazy<NotificationRowBinder> notificationRowBinderLazy,
      Lazy<NotificationRemoteInputManager> notificationRemoteInputManagerLazy,
      LeakDetector leakDetector, ForegroundServiceDismissalFeatureController fgsFeatureController,
      IStatusBarService statusBarService, DumpManager dumpManager) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideNotificationEntryManager(logger, groupManager, featureFlags, notificationRowBinderLazy, notificationRemoteInputManagerLazy, leakDetector, fgsFeatureController, statusBarService, dumpManager));
  }
}

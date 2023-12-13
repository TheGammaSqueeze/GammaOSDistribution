package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.notification.collection.render.NotifGutsViewManager;
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
public final class GutsCoordinator_Factory implements Factory<GutsCoordinator> {
  private final Provider<NotifGutsViewManager> notifGutsViewManagerProvider;

  private final Provider<GutsCoordinatorLogger> loggerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public GutsCoordinator_Factory(Provider<NotifGutsViewManager> notifGutsViewManagerProvider,
      Provider<GutsCoordinatorLogger> loggerProvider, Provider<DumpManager> dumpManagerProvider) {
    this.notifGutsViewManagerProvider = notifGutsViewManagerProvider;
    this.loggerProvider = loggerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public GutsCoordinator get() {
    return newInstance(notifGutsViewManagerProvider.get(), loggerProvider.get(), dumpManagerProvider.get());
  }

  public static GutsCoordinator_Factory create(
      Provider<NotifGutsViewManager> notifGutsViewManagerProvider,
      Provider<GutsCoordinatorLogger> loggerProvider, Provider<DumpManager> dumpManagerProvider) {
    return new GutsCoordinator_Factory(notifGutsViewManagerProvider, loggerProvider, dumpManagerProvider);
  }

  public static GutsCoordinator newInstance(NotifGutsViewManager notifGutsViewManager,
      GutsCoordinatorLogger logger, DumpManager dumpManager) {
    return new GutsCoordinator(notifGutsViewManager, logger, dumpManager);
  }
}

package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.internal.statusbar.IStatusBarService;
import com.android.systemui.statusbar.notification.collection.inflation.NotifInflater;
import com.android.systemui.statusbar.notification.collection.render.NotifViewBarn;
import com.android.systemui.statusbar.notification.row.NotifInflationErrorManager;
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
public final class PreparationCoordinator_Factory implements Factory<PreparationCoordinator> {
  private final Provider<PreparationCoordinatorLogger> loggerProvider;

  private final Provider<NotifInflater> notifInflaterProvider;

  private final Provider<NotifInflationErrorManager> errorManagerProvider;

  private final Provider<NotifViewBarn> viewBarnProvider;

  private final Provider<IStatusBarService> serviceProvider;

  public PreparationCoordinator_Factory(Provider<PreparationCoordinatorLogger> loggerProvider,
      Provider<NotifInflater> notifInflaterProvider,
      Provider<NotifInflationErrorManager> errorManagerProvider,
      Provider<NotifViewBarn> viewBarnProvider, Provider<IStatusBarService> serviceProvider) {
    this.loggerProvider = loggerProvider;
    this.notifInflaterProvider = notifInflaterProvider;
    this.errorManagerProvider = errorManagerProvider;
    this.viewBarnProvider = viewBarnProvider;
    this.serviceProvider = serviceProvider;
  }

  @Override
  public PreparationCoordinator get() {
    return newInstance(loggerProvider.get(), notifInflaterProvider.get(), errorManagerProvider.get(), viewBarnProvider.get(), serviceProvider.get());
  }

  public static PreparationCoordinator_Factory create(
      Provider<PreparationCoordinatorLogger> loggerProvider,
      Provider<NotifInflater> notifInflaterProvider,
      Provider<NotifInflationErrorManager> errorManagerProvider,
      Provider<NotifViewBarn> viewBarnProvider, Provider<IStatusBarService> serviceProvider) {
    return new PreparationCoordinator_Factory(loggerProvider, notifInflaterProvider, errorManagerProvider, viewBarnProvider, serviceProvider);
  }

  public static PreparationCoordinator newInstance(PreparationCoordinatorLogger logger,
      NotifInflater notifInflater, NotifInflationErrorManager errorManager, NotifViewBarn viewBarn,
      IStatusBarService service) {
    return new PreparationCoordinator(logger, notifInflater, errorManager, viewBarn, service);
  }
}

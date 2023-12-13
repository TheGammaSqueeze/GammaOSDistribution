package com.android.systemui.statusbar.notification.row;

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
public final class RowContentBindStage_Factory implements Factory<RowContentBindStage> {
  private final Provider<NotificationRowContentBinder> binderProvider;

  private final Provider<NotifInflationErrorManager> errorManagerProvider;

  private final Provider<RowContentBindStageLogger> loggerProvider;

  public RowContentBindStage_Factory(Provider<NotificationRowContentBinder> binderProvider,
      Provider<NotifInflationErrorManager> errorManagerProvider,
      Provider<RowContentBindStageLogger> loggerProvider) {
    this.binderProvider = binderProvider;
    this.errorManagerProvider = errorManagerProvider;
    this.loggerProvider = loggerProvider;
  }

  @Override
  public RowContentBindStage get() {
    return newInstance(binderProvider.get(), errorManagerProvider.get(), loggerProvider.get());
  }

  public static RowContentBindStage_Factory create(
      Provider<NotificationRowContentBinder> binderProvider,
      Provider<NotifInflationErrorManager> errorManagerProvider,
      Provider<RowContentBindStageLogger> loggerProvider) {
    return new RowContentBindStage_Factory(binderProvider, errorManagerProvider, loggerProvider);
  }

  public static RowContentBindStage newInstance(NotificationRowContentBinder binder,
      NotifInflationErrorManager errorManager, RowContentBindStageLogger logger) {
    return new RowContentBindStage(binder, errorManager, logger);
  }
}

package com.android.systemui.statusbar.notification.logging;

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
public final class NotificationLogger_ExpansionStateLogger_Factory implements Factory<NotificationLogger.ExpansionStateLogger> {
  private final Provider<Executor> uiBgExecutorProvider;

  public NotificationLogger_ExpansionStateLogger_Factory(Provider<Executor> uiBgExecutorProvider) {
    this.uiBgExecutorProvider = uiBgExecutorProvider;
  }

  @Override
  public NotificationLogger.ExpansionStateLogger get() {
    return newInstance(uiBgExecutorProvider.get());
  }

  public static NotificationLogger_ExpansionStateLogger_Factory create(
      Provider<Executor> uiBgExecutorProvider) {
    return new NotificationLogger_ExpansionStateLogger_Factory(uiBgExecutorProvider);
  }

  public static NotificationLogger.ExpansionStateLogger newInstance(Executor uiBgExecutor) {
    return new NotificationLogger.ExpansionStateLogger(uiBgExecutor);
  }
}

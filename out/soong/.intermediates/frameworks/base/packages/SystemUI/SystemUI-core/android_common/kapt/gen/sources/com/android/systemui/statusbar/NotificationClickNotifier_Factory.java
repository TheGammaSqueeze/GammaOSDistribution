package com.android.systemui.statusbar;

import com.android.internal.statusbar.IStatusBarService;
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
public final class NotificationClickNotifier_Factory implements Factory<NotificationClickNotifier> {
  private final Provider<IStatusBarService> barServiceProvider;

  private final Provider<Executor> mainExecutorProvider;

  public NotificationClickNotifier_Factory(Provider<IStatusBarService> barServiceProvider,
      Provider<Executor> mainExecutorProvider) {
    this.barServiceProvider = barServiceProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public NotificationClickNotifier get() {
    return newInstance(barServiceProvider.get(), mainExecutorProvider.get());
  }

  public static NotificationClickNotifier_Factory create(
      Provider<IStatusBarService> barServiceProvider, Provider<Executor> mainExecutorProvider) {
    return new NotificationClickNotifier_Factory(barServiceProvider, mainExecutorProvider);
  }

  public static NotificationClickNotifier newInstance(IStatusBarService barService,
      Executor mainExecutor) {
    return new NotificationClickNotifier(barService, mainExecutor);
  }
}

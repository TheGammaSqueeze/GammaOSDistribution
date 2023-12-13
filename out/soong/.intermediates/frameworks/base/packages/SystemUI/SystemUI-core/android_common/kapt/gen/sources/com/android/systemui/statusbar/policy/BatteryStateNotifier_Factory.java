package com.android.systemui.statusbar.policy;

import android.app.NotificationManager;
import android.content.Context;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class BatteryStateNotifier_Factory implements Factory<BatteryStateNotifier> {
  private final Provider<BatteryController> controllerProvider;

  private final Provider<NotificationManager> noManProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  private final Provider<Context> contextProvider;

  public BatteryStateNotifier_Factory(Provider<BatteryController> controllerProvider,
      Provider<NotificationManager> noManProvider,
      Provider<DelayableExecutor> delayableExecutorProvider, Provider<Context> contextProvider) {
    this.controllerProvider = controllerProvider;
    this.noManProvider = noManProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public BatteryStateNotifier get() {
    return newInstance(controllerProvider.get(), noManProvider.get(), delayableExecutorProvider.get(), contextProvider.get());
  }

  public static BatteryStateNotifier_Factory create(Provider<BatteryController> controllerProvider,
      Provider<NotificationManager> noManProvider,
      Provider<DelayableExecutor> delayableExecutorProvider, Provider<Context> contextProvider) {
    return new BatteryStateNotifier_Factory(controllerProvider, noManProvider, delayableExecutorProvider, contextProvider);
  }

  public static BatteryStateNotifier newInstance(BatteryController controller,
      NotificationManager noMan, DelayableExecutor delayableExecutor, Context context) {
    return new BatteryStateNotifier(controller, noMan, delayableExecutor, context);
  }
}

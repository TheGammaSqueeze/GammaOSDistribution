package com.android.systemui.controls.ui;

import android.content.Context;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.ControlsMetricsLogger;
import com.android.systemui.globalactions.GlobalActionsComponent;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.wm.shell.TaskViewFactory;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class ControlActionCoordinatorImpl_Factory implements Factory<ControlActionCoordinatorImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<DelayableExecutor> bgExecutorProvider;

  private final Provider<DelayableExecutor> uiExecutorProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<GlobalActionsComponent> globalActionsComponentProvider;

  private final Provider<Optional<TaskViewFactory>> taskViewFactoryProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<ControlsUiController> uiControllerProvider;

  private final Provider<ControlsMetricsLogger> controlsMetricsLoggerProvider;

  public ControlActionCoordinatorImpl_Factory(Provider<Context> contextProvider,
      Provider<DelayableExecutor> bgExecutorProvider,
      Provider<DelayableExecutor> uiExecutorProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<GlobalActionsComponent> globalActionsComponentProvider,
      Provider<Optional<TaskViewFactory>> taskViewFactoryProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ControlsUiController> uiControllerProvider,
      Provider<ControlsMetricsLogger> controlsMetricsLoggerProvider) {
    this.contextProvider = contextProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.uiExecutorProvider = uiExecutorProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.globalActionsComponentProvider = globalActionsComponentProvider;
    this.taskViewFactoryProvider = taskViewFactoryProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.uiControllerProvider = uiControllerProvider;
    this.controlsMetricsLoggerProvider = controlsMetricsLoggerProvider;
  }

  @Override
  public ControlActionCoordinatorImpl get() {
    return newInstance(contextProvider.get(), bgExecutorProvider.get(), uiExecutorProvider.get(), activityStarterProvider.get(), keyguardStateControllerProvider.get(), globalActionsComponentProvider.get(), taskViewFactoryProvider.get(), broadcastDispatcherProvider.get(), DoubleCheck.lazy(uiControllerProvider), controlsMetricsLoggerProvider.get());
  }

  public static ControlActionCoordinatorImpl_Factory create(Provider<Context> contextProvider,
      Provider<DelayableExecutor> bgExecutorProvider,
      Provider<DelayableExecutor> uiExecutorProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<GlobalActionsComponent> globalActionsComponentProvider,
      Provider<Optional<TaskViewFactory>> taskViewFactoryProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ControlsUiController> uiControllerProvider,
      Provider<ControlsMetricsLogger> controlsMetricsLoggerProvider) {
    return new ControlActionCoordinatorImpl_Factory(contextProvider, bgExecutorProvider, uiExecutorProvider, activityStarterProvider, keyguardStateControllerProvider, globalActionsComponentProvider, taskViewFactoryProvider, broadcastDispatcherProvider, uiControllerProvider, controlsMetricsLoggerProvider);
  }

  public static ControlActionCoordinatorImpl newInstance(Context context,
      DelayableExecutor bgExecutor, DelayableExecutor uiExecutor, ActivityStarter activityStarter,
      KeyguardStateController keyguardStateController,
      GlobalActionsComponent globalActionsComponent, Optional<TaskViewFactory> taskViewFactory,
      BroadcastDispatcher broadcastDispatcher, Lazy<ControlsUiController> lazyUiController,
      ControlsMetricsLogger controlsMetricsLogger) {
    return new ControlActionCoordinatorImpl(context, bgExecutor, uiExecutor, activityStarter, keyguardStateController, globalActionsComponent, taskViewFactory, broadcastDispatcher, lazyUiController, controlsMetricsLogger);
  }
}

package com.android.wm.shell.dagger;

import android.content.Context;
import android.os.Handler;
import android.view.WindowManager;
import com.android.internal.logging.UiEventLogger;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.DisplayLayout;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.TaskStackListenerImpl;
import com.android.wm.shell.onehanded.OneHandedController;
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
public final class WMShellModule_ProvideOneHandedControllerFactory implements Factory<OneHandedController> {
  private final Provider<Context> contextProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<DisplayLayout> displayLayoutProvider;

  private final Provider<TaskStackListenerImpl> taskStackListenerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<Handler> mainHandlerProvider;

  public WMShellModule_ProvideOneHandedControllerFactory(Provider<Context> contextProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<DisplayLayout> displayLayoutProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<ShellExecutor> mainExecutorProvider,
      Provider<Handler> mainHandlerProvider) {
    this.contextProvider = contextProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.displayLayoutProvider = displayLayoutProvider;
    this.taskStackListenerProvider = taskStackListenerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public OneHandedController get() {
    return provideOneHandedController(contextProvider.get(), windowManagerProvider.get(), displayControllerProvider.get(), displayLayoutProvider.get(), taskStackListenerProvider.get(), uiEventLoggerProvider.get(), mainExecutorProvider.get(), mainHandlerProvider.get());
  }

  public static WMShellModule_ProvideOneHandedControllerFactory create(
      Provider<Context> contextProvider, Provider<WindowManager> windowManagerProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<DisplayLayout> displayLayoutProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<ShellExecutor> mainExecutorProvider,
      Provider<Handler> mainHandlerProvider) {
    return new WMShellModule_ProvideOneHandedControllerFactory(contextProvider, windowManagerProvider, displayControllerProvider, displayLayoutProvider, taskStackListenerProvider, uiEventLoggerProvider, mainExecutorProvider, mainHandlerProvider);
  }

  public static OneHandedController provideOneHandedController(Context context,
      WindowManager windowManager, DisplayController displayController, DisplayLayout displayLayout,
      TaskStackListenerImpl taskStackListener, UiEventLogger uiEventLogger,
      ShellExecutor mainExecutor, Handler mainHandler) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.provideOneHandedController(context, windowManager, displayController, displayLayout, taskStackListener, uiEventLogger, mainExecutor, mainHandler));
  }
}

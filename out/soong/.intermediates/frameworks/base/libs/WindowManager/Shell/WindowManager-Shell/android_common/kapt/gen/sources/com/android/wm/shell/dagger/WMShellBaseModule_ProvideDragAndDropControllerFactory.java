package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.internal.logging.UiEventLogger;
import com.android.launcher3.icons.IconProvider;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.draganddrop.DragAndDropController;
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
public final class WMShellBaseModule_ProvideDragAndDropControllerFactory implements Factory<DragAndDropController> {
  private final Provider<Context> contextProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<IconProvider> iconProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideDragAndDropControllerFactory(Provider<Context> contextProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<IconProvider> iconProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.iconProvider = iconProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public DragAndDropController get() {
    return provideDragAndDropController(contextProvider.get(), displayControllerProvider.get(), uiEventLoggerProvider.get(), iconProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideDragAndDropControllerFactory create(
      Provider<Context> contextProvider, Provider<DisplayController> displayControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<IconProvider> iconProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideDragAndDropControllerFactory(contextProvider, displayControllerProvider, uiEventLoggerProvider, iconProvider, mainExecutorProvider);
  }

  public static DragAndDropController provideDragAndDropController(Context context,
      DisplayController displayController, UiEventLogger uiEventLogger, IconProvider iconProvider,
      ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideDragAndDropController(context, displayController, uiEventLogger, iconProvider, mainExecutor));
  }
}

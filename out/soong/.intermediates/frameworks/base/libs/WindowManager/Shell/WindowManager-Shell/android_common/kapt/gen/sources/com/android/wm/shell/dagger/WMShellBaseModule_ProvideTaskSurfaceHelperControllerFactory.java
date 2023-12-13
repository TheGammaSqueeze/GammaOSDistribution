package com.android.wm.shell.dagger;

import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.tasksurfacehelper.TaskSurfaceHelperController;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class WMShellBaseModule_ProvideTaskSurfaceHelperControllerFactory implements Factory<Optional<TaskSurfaceHelperController>> {
  private final Provider<ShellTaskOrganizer> taskOrganizerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideTaskSurfaceHelperControllerFactory(
      Provider<ShellTaskOrganizer> taskOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.taskOrganizerProvider = taskOrganizerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public Optional<TaskSurfaceHelperController> get() {
    return provideTaskSurfaceHelperController(taskOrganizerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideTaskSurfaceHelperControllerFactory create(
      Provider<ShellTaskOrganizer> taskOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideTaskSurfaceHelperControllerFactory(taskOrganizerProvider, mainExecutorProvider);
  }

  public static Optional<TaskSurfaceHelperController> provideTaskSurfaceHelperController(
      ShellTaskOrganizer taskOrganizer, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideTaskSurfaceHelperController(taskOrganizer, mainExecutor));
  }
}

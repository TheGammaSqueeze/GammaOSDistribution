package com.android.wm.shell.dagger;

import com.android.wm.shell.tasksurfacehelper.TaskSurfaceHelper;
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
public final class WMShellBaseModule_ProvideTaskSurfaceHelperFactory implements Factory<Optional<TaskSurfaceHelper>> {
  private final Provider<Optional<TaskSurfaceHelperController>> taskSurfaceControllerProvider;

  public WMShellBaseModule_ProvideTaskSurfaceHelperFactory(
      Provider<Optional<TaskSurfaceHelperController>> taskSurfaceControllerProvider) {
    this.taskSurfaceControllerProvider = taskSurfaceControllerProvider;
  }

  @Override
  public Optional<TaskSurfaceHelper> get() {
    return provideTaskSurfaceHelper(taskSurfaceControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideTaskSurfaceHelperFactory create(
      Provider<Optional<TaskSurfaceHelperController>> taskSurfaceControllerProvider) {
    return new WMShellBaseModule_ProvideTaskSurfaceHelperFactory(taskSurfaceControllerProvider);
  }

  public static Optional<TaskSurfaceHelper> provideTaskSurfaceHelper(
      Optional<TaskSurfaceHelperController> taskSurfaceController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideTaskSurfaceHelper(taskSurfaceController));
  }
}

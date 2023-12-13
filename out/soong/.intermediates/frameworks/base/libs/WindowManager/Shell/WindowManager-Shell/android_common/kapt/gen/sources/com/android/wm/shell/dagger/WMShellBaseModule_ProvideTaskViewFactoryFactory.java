package com.android.wm.shell.dagger;

import com.android.wm.shell.TaskViewFactory;
import com.android.wm.shell.TaskViewFactoryController;
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
public final class WMShellBaseModule_ProvideTaskViewFactoryFactory implements Factory<Optional<TaskViewFactory>> {
  private final Provider<TaskViewFactoryController> taskViewFactoryControllerProvider;

  public WMShellBaseModule_ProvideTaskViewFactoryFactory(
      Provider<TaskViewFactoryController> taskViewFactoryControllerProvider) {
    this.taskViewFactoryControllerProvider = taskViewFactoryControllerProvider;
  }

  @Override
  public Optional<TaskViewFactory> get() {
    return provideTaskViewFactory(taskViewFactoryControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideTaskViewFactoryFactory create(
      Provider<TaskViewFactoryController> taskViewFactoryControllerProvider) {
    return new WMShellBaseModule_ProvideTaskViewFactoryFactory(taskViewFactoryControllerProvider);
  }

  public static Optional<TaskViewFactory> provideTaskViewFactory(
      TaskViewFactoryController taskViewFactoryController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideTaskViewFactory(taskViewFactoryController));
  }
}

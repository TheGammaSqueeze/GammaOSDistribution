package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.TaskStackListenerImpl;
import com.android.wm.shell.recents.RecentTasksController;
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
public final class WMShellBaseModule_ProvideRecentTasksControllerFactory implements Factory<Optional<RecentTasksController>> {
  private final Provider<Context> contextProvider;

  private final Provider<TaskStackListenerImpl> taskStackListenerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideRecentTasksControllerFactory(Provider<Context> contextProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.taskStackListenerProvider = taskStackListenerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public Optional<RecentTasksController> get() {
    return provideRecentTasksController(contextProvider.get(), taskStackListenerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideRecentTasksControllerFactory create(
      Provider<Context> contextProvider, Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideRecentTasksControllerFactory(contextProvider, taskStackListenerProvider, mainExecutorProvider);
  }

  public static Optional<RecentTasksController> provideRecentTasksController(Context context,
      TaskStackListenerImpl taskStackListener, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideRecentTasksController(context, taskStackListener, mainExecutor));
  }
}

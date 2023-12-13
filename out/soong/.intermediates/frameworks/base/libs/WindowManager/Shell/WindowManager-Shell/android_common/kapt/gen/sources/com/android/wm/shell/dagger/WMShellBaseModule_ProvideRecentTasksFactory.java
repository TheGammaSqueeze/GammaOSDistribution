package com.android.wm.shell.dagger;

import com.android.wm.shell.recents.RecentTasks;
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
public final class WMShellBaseModule_ProvideRecentTasksFactory implements Factory<Optional<RecentTasks>> {
  private final Provider<Optional<RecentTasksController>> recentTasksControllerProvider;

  public WMShellBaseModule_ProvideRecentTasksFactory(
      Provider<Optional<RecentTasksController>> recentTasksControllerProvider) {
    this.recentTasksControllerProvider = recentTasksControllerProvider;
  }

  @Override
  public Optional<RecentTasks> get() {
    return provideRecentTasks(recentTasksControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideRecentTasksFactory create(
      Provider<Optional<RecentTasksController>> recentTasksControllerProvider) {
    return new WMShellBaseModule_ProvideRecentTasksFactory(recentTasksControllerProvider);
  }

  public static Optional<RecentTasks> provideRecentTasks(
      Optional<RecentTasksController> recentTasksController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideRecentTasks(recentTasksController));
  }
}

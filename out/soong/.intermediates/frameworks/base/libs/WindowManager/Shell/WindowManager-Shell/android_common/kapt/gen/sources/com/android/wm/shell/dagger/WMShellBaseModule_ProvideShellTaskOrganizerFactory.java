package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.compatui.CompatUIController;
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
public final class WMShellBaseModule_ProvideShellTaskOrganizerFactory implements Factory<ShellTaskOrganizer> {
  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<Context> contextProvider;

  private final Provider<CompatUIController> compatUIProvider;

  private final Provider<Optional<RecentTasksController>> recentTasksOptionalProvider;

  public WMShellBaseModule_ProvideShellTaskOrganizerFactory(
      Provider<ShellExecutor> mainExecutorProvider, Provider<Context> contextProvider,
      Provider<CompatUIController> compatUIProvider,
      Provider<Optional<RecentTasksController>> recentTasksOptionalProvider) {
    this.mainExecutorProvider = mainExecutorProvider;
    this.contextProvider = contextProvider;
    this.compatUIProvider = compatUIProvider;
    this.recentTasksOptionalProvider = recentTasksOptionalProvider;
  }

  @Override
  public ShellTaskOrganizer get() {
    return provideShellTaskOrganizer(mainExecutorProvider.get(), contextProvider.get(), compatUIProvider.get(), recentTasksOptionalProvider.get());
  }

  public static WMShellBaseModule_ProvideShellTaskOrganizerFactory create(
      Provider<ShellExecutor> mainExecutorProvider, Provider<Context> contextProvider,
      Provider<CompatUIController> compatUIProvider,
      Provider<Optional<RecentTasksController>> recentTasksOptionalProvider) {
    return new WMShellBaseModule_ProvideShellTaskOrganizerFactory(mainExecutorProvider, contextProvider, compatUIProvider, recentTasksOptionalProvider);
  }

  public static ShellTaskOrganizer provideShellTaskOrganizer(ShellExecutor mainExecutor,
      Context context, CompatUIController compatUI,
      Optional<RecentTasksController> recentTasksOptional) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideShellTaskOrganizer(mainExecutor, context, compatUI, recentTasksOptional));
  }
}

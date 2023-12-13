package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.TransactionPool;
import com.android.wm.shell.transition.Transitions;
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
public final class WMShellBaseModule_ProvideTransitionsFactory implements Factory<Transitions> {
  private final Provider<ShellTaskOrganizer> organizerProvider;

  private final Provider<TransactionPool> poolProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<ShellExecutor> animExecutorProvider;

  public WMShellBaseModule_ProvideTransitionsFactory(Provider<ShellTaskOrganizer> organizerProvider,
      Provider<TransactionPool> poolProvider, Provider<DisplayController> displayControllerProvider,
      Provider<Context> contextProvider, Provider<ShellExecutor> mainExecutorProvider,
      Provider<ShellExecutor> animExecutorProvider) {
    this.organizerProvider = organizerProvider;
    this.poolProvider = poolProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.contextProvider = contextProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.animExecutorProvider = animExecutorProvider;
  }

  @Override
  public Transitions get() {
    return provideTransitions(organizerProvider.get(), poolProvider.get(), displayControllerProvider.get(), contextProvider.get(), mainExecutorProvider.get(), animExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideTransitionsFactory create(
      Provider<ShellTaskOrganizer> organizerProvider, Provider<TransactionPool> poolProvider,
      Provider<DisplayController> displayControllerProvider, Provider<Context> contextProvider,
      Provider<ShellExecutor> mainExecutorProvider, Provider<ShellExecutor> animExecutorProvider) {
    return new WMShellBaseModule_ProvideTransitionsFactory(organizerProvider, poolProvider, displayControllerProvider, contextProvider, mainExecutorProvider, animExecutorProvider);
  }

  public static Transitions provideTransitions(ShellTaskOrganizer organizer, TransactionPool pool,
      DisplayController displayController, Context context, ShellExecutor mainExecutor,
      ShellExecutor animExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideTransitions(organizer, pool, displayController, context, mainExecutor, animExecutor));
  }
}

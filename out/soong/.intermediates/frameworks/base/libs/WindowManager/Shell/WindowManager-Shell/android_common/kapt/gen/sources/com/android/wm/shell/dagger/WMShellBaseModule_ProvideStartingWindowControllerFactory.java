package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.launcher3.icons.IconProvider;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.TransactionPool;
import com.android.wm.shell.startingsurface.StartingWindowController;
import com.android.wm.shell.startingsurface.StartingWindowTypeAlgorithm;
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
public final class WMShellBaseModule_ProvideStartingWindowControllerFactory implements Factory<StartingWindowController> {
  private final Provider<Context> contextProvider;

  private final Provider<ShellExecutor> splashScreenExecutorProvider;

  private final Provider<StartingWindowTypeAlgorithm> startingWindowTypeAlgorithmProvider;

  private final Provider<IconProvider> iconProvider;

  private final Provider<TransactionPool> poolProvider;

  public WMShellBaseModule_ProvideStartingWindowControllerFactory(Provider<Context> contextProvider,
      Provider<ShellExecutor> splashScreenExecutorProvider,
      Provider<StartingWindowTypeAlgorithm> startingWindowTypeAlgorithmProvider,
      Provider<IconProvider> iconProvider, Provider<TransactionPool> poolProvider) {
    this.contextProvider = contextProvider;
    this.splashScreenExecutorProvider = splashScreenExecutorProvider;
    this.startingWindowTypeAlgorithmProvider = startingWindowTypeAlgorithmProvider;
    this.iconProvider = iconProvider;
    this.poolProvider = poolProvider;
  }

  @Override
  public StartingWindowController get() {
    return provideStartingWindowController(contextProvider.get(), splashScreenExecutorProvider.get(), startingWindowTypeAlgorithmProvider.get(), iconProvider.get(), poolProvider.get());
  }

  public static WMShellBaseModule_ProvideStartingWindowControllerFactory create(
      Provider<Context> contextProvider, Provider<ShellExecutor> splashScreenExecutorProvider,
      Provider<StartingWindowTypeAlgorithm> startingWindowTypeAlgorithmProvider,
      Provider<IconProvider> iconProvider, Provider<TransactionPool> poolProvider) {
    return new WMShellBaseModule_ProvideStartingWindowControllerFactory(contextProvider, splashScreenExecutorProvider, startingWindowTypeAlgorithmProvider, iconProvider, poolProvider);
  }

  public static StartingWindowController provideStartingWindowController(Context context,
      ShellExecutor splashScreenExecutor, StartingWindowTypeAlgorithm startingWindowTypeAlgorithm,
      IconProvider iconProvider, TransactionPool pool) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideStartingWindowController(context, splashScreenExecutor, startingWindowTypeAlgorithm, iconProvider, pool));
  }
}

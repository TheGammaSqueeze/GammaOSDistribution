package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.common.DisplayInsetsController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.TransactionPool;
import com.android.wm.shell.splitscreen.StageTaskUnfoldController;
import com.android.wm.shell.unfold.ShellUnfoldProgressProvider;
import com.android.wm.shell.unfold.UnfoldBackgroundController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class WMShellModule_ProvideStageTaskUnfoldControllerFactory implements Factory<Optional<StageTaskUnfoldController>> {
  private final Provider<Optional<ShellUnfoldProgressProvider>> progressProvider;

  private final Provider<Context> contextProvider;

  private final Provider<TransactionPool> transactionPoolProvider;

  private final Provider<UnfoldBackgroundController> unfoldBackgroundControllerProvider;

  private final Provider<DisplayInsetsController> displayInsetsControllerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellModule_ProvideStageTaskUnfoldControllerFactory(
      Provider<Optional<ShellUnfoldProgressProvider>> progressProvider,
      Provider<Context> contextProvider, Provider<TransactionPool> transactionPoolProvider,
      Provider<UnfoldBackgroundController> unfoldBackgroundControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.progressProvider = progressProvider;
    this.contextProvider = contextProvider;
    this.transactionPoolProvider = transactionPoolProvider;
    this.unfoldBackgroundControllerProvider = unfoldBackgroundControllerProvider;
    this.displayInsetsControllerProvider = displayInsetsControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public Optional<StageTaskUnfoldController> get() {
    return provideStageTaskUnfoldController(progressProvider.get(), contextProvider.get(), transactionPoolProvider.get(), DoubleCheck.lazy(unfoldBackgroundControllerProvider), displayInsetsControllerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellModule_ProvideStageTaskUnfoldControllerFactory create(
      Provider<Optional<ShellUnfoldProgressProvider>> progressProvider,
      Provider<Context> contextProvider, Provider<TransactionPool> transactionPoolProvider,
      Provider<UnfoldBackgroundController> unfoldBackgroundControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellModule_ProvideStageTaskUnfoldControllerFactory(progressProvider, contextProvider, transactionPoolProvider, unfoldBackgroundControllerProvider, displayInsetsControllerProvider, mainExecutorProvider);
  }

  public static Optional<StageTaskUnfoldController> provideStageTaskUnfoldController(
      Optional<ShellUnfoldProgressProvider> progressProvider, Context context,
      TransactionPool transactionPool, Lazy<UnfoldBackgroundController> unfoldBackgroundController,
      DisplayInsetsController displayInsetsController, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.provideStageTaskUnfoldController(progressProvider, context, transactionPool, unfoldBackgroundController, displayInsetsController, mainExecutor));
  }
}

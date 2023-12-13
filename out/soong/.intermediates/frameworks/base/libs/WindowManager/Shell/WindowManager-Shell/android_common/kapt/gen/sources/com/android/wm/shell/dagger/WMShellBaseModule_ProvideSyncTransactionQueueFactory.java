package com.android.wm.shell.dagger;

import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.common.TransactionPool;
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
public final class WMShellBaseModule_ProvideSyncTransactionQueueFactory implements Factory<SyncTransactionQueue> {
  private final Provider<TransactionPool> poolProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideSyncTransactionQueueFactory(
      Provider<TransactionPool> poolProvider, Provider<ShellExecutor> mainExecutorProvider) {
    this.poolProvider = poolProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public SyncTransactionQueue get() {
    return provideSyncTransactionQueue(poolProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideSyncTransactionQueueFactory create(
      Provider<TransactionPool> poolProvider, Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideSyncTransactionQueueFactory(poolProvider, mainExecutorProvider);
  }

  public static SyncTransactionQueue provideSyncTransactionQueue(TransactionPool pool,
      ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideSyncTransactionQueue(pool, mainExecutor));
  }
}

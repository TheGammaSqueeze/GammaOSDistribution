package com.android.wm.shell.dagger;

import com.android.wm.shell.common.TransactionPool;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class WMShellBaseModule_ProvideTransactionPoolFactory implements Factory<TransactionPool> {
  @Override
  public TransactionPool get() {
    return provideTransactionPool();
  }

  public static WMShellBaseModule_ProvideTransactionPoolFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static TransactionPool provideTransactionPool() {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideTransactionPool());
  }

  private static final class InstanceHolder {
    private static final WMShellBaseModule_ProvideTransactionPoolFactory INSTANCE = new WMShellBaseModule_ProvideTransactionPoolFactory();
  }
}

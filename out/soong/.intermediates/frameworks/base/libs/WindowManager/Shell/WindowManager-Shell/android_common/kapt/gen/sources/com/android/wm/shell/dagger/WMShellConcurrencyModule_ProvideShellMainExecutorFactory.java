package com.android.wm.shell.dagger;

import android.content.Context;
import android.os.Handler;
import com.android.wm.shell.common.ShellExecutor;
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
public final class WMShellConcurrencyModule_ProvideShellMainExecutorFactory implements Factory<ShellExecutor> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<ShellExecutor> sysuiMainExecutorProvider;

  public WMShellConcurrencyModule_ProvideShellMainExecutorFactory(Provider<Context> contextProvider,
      Provider<Handler> mainHandlerProvider, Provider<ShellExecutor> sysuiMainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.sysuiMainExecutorProvider = sysuiMainExecutorProvider;
  }

  @Override
  public ShellExecutor get() {
    return provideShellMainExecutor(contextProvider.get(), mainHandlerProvider.get(), sysuiMainExecutorProvider.get());
  }

  public static WMShellConcurrencyModule_ProvideShellMainExecutorFactory create(
      Provider<Context> contextProvider, Provider<Handler> mainHandlerProvider,
      Provider<ShellExecutor> sysuiMainExecutorProvider) {
    return new WMShellConcurrencyModule_ProvideShellMainExecutorFactory(contextProvider, mainHandlerProvider, sysuiMainExecutorProvider);
  }

  public static ShellExecutor provideShellMainExecutor(Context context, Handler mainHandler,
      ShellExecutor sysuiMainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellConcurrencyModule.provideShellMainExecutor(context, mainHandler, sysuiMainExecutor));
  }
}

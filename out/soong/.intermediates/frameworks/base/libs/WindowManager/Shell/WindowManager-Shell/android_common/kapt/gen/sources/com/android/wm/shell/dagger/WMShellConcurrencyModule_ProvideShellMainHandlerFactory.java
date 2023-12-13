package com.android.wm.shell.dagger;

import android.content.Context;
import android.os.Handler;
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
public final class WMShellConcurrencyModule_ProvideShellMainHandlerFactory implements Factory<Handler> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> sysuiMainHandlerProvider;

  public WMShellConcurrencyModule_ProvideShellMainHandlerFactory(Provider<Context> contextProvider,
      Provider<Handler> sysuiMainHandlerProvider) {
    this.contextProvider = contextProvider;
    this.sysuiMainHandlerProvider = sysuiMainHandlerProvider;
  }

  @Override
  public Handler get() {
    return provideShellMainHandler(contextProvider.get(), sysuiMainHandlerProvider.get());
  }

  public static WMShellConcurrencyModule_ProvideShellMainHandlerFactory create(
      Provider<Context> contextProvider, Provider<Handler> sysuiMainHandlerProvider) {
    return new WMShellConcurrencyModule_ProvideShellMainHandlerFactory(contextProvider, sysuiMainHandlerProvider);
  }

  public static Handler provideShellMainHandler(Context context, Handler sysuiMainHandler) {
    return Preconditions.checkNotNullFromProvides(WMShellConcurrencyModule.provideShellMainHandler(context, sysuiMainHandler));
  }
}

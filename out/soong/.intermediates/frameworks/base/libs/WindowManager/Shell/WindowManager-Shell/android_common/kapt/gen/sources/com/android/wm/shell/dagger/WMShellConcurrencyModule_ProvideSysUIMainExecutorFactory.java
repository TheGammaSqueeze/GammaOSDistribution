package com.android.wm.shell.dagger;

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
public final class WMShellConcurrencyModule_ProvideSysUIMainExecutorFactory implements Factory<ShellExecutor> {
  private final Provider<Handler> sysuiMainHandlerProvider;

  public WMShellConcurrencyModule_ProvideSysUIMainExecutorFactory(
      Provider<Handler> sysuiMainHandlerProvider) {
    this.sysuiMainHandlerProvider = sysuiMainHandlerProvider;
  }

  @Override
  public ShellExecutor get() {
    return provideSysUIMainExecutor(sysuiMainHandlerProvider.get());
  }

  public static WMShellConcurrencyModule_ProvideSysUIMainExecutorFactory create(
      Provider<Handler> sysuiMainHandlerProvider) {
    return new WMShellConcurrencyModule_ProvideSysUIMainExecutorFactory(sysuiMainHandlerProvider);
  }

  public static ShellExecutor provideSysUIMainExecutor(Handler sysuiMainHandler) {
    return Preconditions.checkNotNullFromProvides(WMShellConcurrencyModule.provideSysUIMainExecutor(sysuiMainHandler));
  }
}

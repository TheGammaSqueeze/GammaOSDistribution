package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.pip.phone.PipAppOpsListener;
import com.android.wm.shell.pip.phone.PipTouchHandler;
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
public final class WMShellBaseModule_ProvidePipAppOpsListenerFactory implements Factory<PipAppOpsListener> {
  private final Provider<Context> contextProvider;

  private final Provider<PipTouchHandler> pipTouchHandlerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvidePipAppOpsListenerFactory(Provider<Context> contextProvider,
      Provider<PipTouchHandler> pipTouchHandlerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.pipTouchHandlerProvider = pipTouchHandlerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public PipAppOpsListener get() {
    return providePipAppOpsListener(contextProvider.get(), pipTouchHandlerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvidePipAppOpsListenerFactory create(
      Provider<Context> contextProvider, Provider<PipTouchHandler> pipTouchHandlerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvidePipAppOpsListenerFactory(contextProvider, pipTouchHandlerProvider, mainExecutorProvider);
  }

  public static PipAppOpsListener providePipAppOpsListener(Context context,
      PipTouchHandler pipTouchHandler, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.providePipAppOpsListener(context, pipTouchHandler, mainExecutor));
  }
}

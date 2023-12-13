package com.android.wm.shell.dagger;

import android.content.Context;
import android.os.Handler;
import com.android.wm.shell.pip.PipMediaController;
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
public final class WMShellBaseModule_ProvidePipMediaControllerFactory implements Factory<PipMediaController> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> mainHandlerProvider;

  public WMShellBaseModule_ProvidePipMediaControllerFactory(Provider<Context> contextProvider,
      Provider<Handler> mainHandlerProvider) {
    this.contextProvider = contextProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public PipMediaController get() {
    return providePipMediaController(contextProvider.get(), mainHandlerProvider.get());
  }

  public static WMShellBaseModule_ProvidePipMediaControllerFactory create(
      Provider<Context> contextProvider, Provider<Handler> mainHandlerProvider) {
    return new WMShellBaseModule_ProvidePipMediaControllerFactory(contextProvider, mainHandlerProvider);
  }

  public static PipMediaController providePipMediaController(Context context, Handler mainHandler) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.providePipMediaController(context, mainHandler));
  }
}

package com.android.wm.shell.dagger;

import android.os.Handler;
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
public final class WMShellConcurrencyModule_ProvideMainHandlerFactory implements Factory<Handler> {
  @Override
  public Handler get() {
    return provideMainHandler();
  }

  public static WMShellConcurrencyModule_ProvideMainHandlerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static Handler provideMainHandler() {
    return Preconditions.checkNotNullFromProvides(WMShellConcurrencyModule.provideMainHandler());
  }

  private static final class InstanceHolder {
    private static final WMShellConcurrencyModule_ProvideMainHandlerFactory INSTANCE = new WMShellConcurrencyModule_ProvideMainHandlerFactory();
  }
}

package com.android.systemui.util.concurrency;

import android.os.Handler;
import android.os.Looper;
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
public final class SysUIConcurrencyModule_ProvideBgHandlerFactory implements Factory<Handler> {
  private final Provider<Looper> bgLooperProvider;

  public SysUIConcurrencyModule_ProvideBgHandlerFactory(Provider<Looper> bgLooperProvider) {
    this.bgLooperProvider = bgLooperProvider;
  }

  @Override
  public Handler get() {
    return provideBgHandler(bgLooperProvider.get());
  }

  public static SysUIConcurrencyModule_ProvideBgHandlerFactory create(
      Provider<Looper> bgLooperProvider) {
    return new SysUIConcurrencyModule_ProvideBgHandlerFactory(bgLooperProvider);
  }

  public static Handler provideBgHandler(Looper bgLooper) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideBgHandler(bgLooper));
  }
}

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
public final class GlobalConcurrencyModule_ProvideMainHandlerFactory implements Factory<Handler> {
  private final Provider<Looper> mainLooperProvider;

  public GlobalConcurrencyModule_ProvideMainHandlerFactory(Provider<Looper> mainLooperProvider) {
    this.mainLooperProvider = mainLooperProvider;
  }

  @Override
  public Handler get() {
    return provideMainHandler(mainLooperProvider.get());
  }

  public static GlobalConcurrencyModule_ProvideMainHandlerFactory create(
      Provider<Looper> mainLooperProvider) {
    return new GlobalConcurrencyModule_ProvideMainHandlerFactory(mainLooperProvider);
  }

  public static Handler provideMainHandler(Looper mainLooper) {
    return Preconditions.checkNotNullFromProvides(GlobalConcurrencyModule.provideMainHandler(mainLooper));
  }
}

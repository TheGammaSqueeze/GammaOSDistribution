package com.android.systemui.util.concurrency;

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
public final class GlobalConcurrencyModule_ProvideMainDelayableExecutorFactory implements Factory<DelayableExecutor> {
  private final Provider<Looper> looperProvider;

  public GlobalConcurrencyModule_ProvideMainDelayableExecutorFactory(
      Provider<Looper> looperProvider) {
    this.looperProvider = looperProvider;
  }

  @Override
  public DelayableExecutor get() {
    return provideMainDelayableExecutor(looperProvider.get());
  }

  public static GlobalConcurrencyModule_ProvideMainDelayableExecutorFactory create(
      Provider<Looper> looperProvider) {
    return new GlobalConcurrencyModule_ProvideMainDelayableExecutorFactory(looperProvider);
  }

  public static DelayableExecutor provideMainDelayableExecutor(Looper looper) {
    return Preconditions.checkNotNullFromProvides(GlobalConcurrencyModule.provideMainDelayableExecutor(looper));
  }
}

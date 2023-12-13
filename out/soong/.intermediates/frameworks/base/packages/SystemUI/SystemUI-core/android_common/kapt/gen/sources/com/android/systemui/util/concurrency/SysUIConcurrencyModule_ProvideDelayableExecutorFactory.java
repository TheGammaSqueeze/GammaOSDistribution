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
public final class SysUIConcurrencyModule_ProvideDelayableExecutorFactory implements Factory<DelayableExecutor> {
  private final Provider<Looper> looperProvider;

  public SysUIConcurrencyModule_ProvideDelayableExecutorFactory(Provider<Looper> looperProvider) {
    this.looperProvider = looperProvider;
  }

  @Override
  public DelayableExecutor get() {
    return provideDelayableExecutor(looperProvider.get());
  }

  public static SysUIConcurrencyModule_ProvideDelayableExecutorFactory create(
      Provider<Looper> looperProvider) {
    return new SysUIConcurrencyModule_ProvideDelayableExecutorFactory(looperProvider);
  }

  public static DelayableExecutor provideDelayableExecutor(Looper looper) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideDelayableExecutor(looper));
  }
}

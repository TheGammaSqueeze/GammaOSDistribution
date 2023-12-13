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
public final class SysUIConcurrencyModule_ProvideBackgroundDelayableExecutorFactory implements Factory<DelayableExecutor> {
  private final Provider<Looper> looperProvider;

  public SysUIConcurrencyModule_ProvideBackgroundDelayableExecutorFactory(
      Provider<Looper> looperProvider) {
    this.looperProvider = looperProvider;
  }

  @Override
  public DelayableExecutor get() {
    return provideBackgroundDelayableExecutor(looperProvider.get());
  }

  public static SysUIConcurrencyModule_ProvideBackgroundDelayableExecutorFactory create(
      Provider<Looper> looperProvider) {
    return new SysUIConcurrencyModule_ProvideBackgroundDelayableExecutorFactory(looperProvider);
  }

  public static DelayableExecutor provideBackgroundDelayableExecutor(Looper looper) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideBackgroundDelayableExecutor(looper));
  }
}

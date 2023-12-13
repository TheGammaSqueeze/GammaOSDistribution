package com.android.systemui.util.concurrency;

import android.os.Looper;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.concurrent.Executor;
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
public final class SysUIConcurrencyModule_ProvideExecutorFactory implements Factory<Executor> {
  private final Provider<Looper> looperProvider;

  public SysUIConcurrencyModule_ProvideExecutorFactory(Provider<Looper> looperProvider) {
    this.looperProvider = looperProvider;
  }

  @Override
  public Executor get() {
    return provideExecutor(looperProvider.get());
  }

  public static SysUIConcurrencyModule_ProvideExecutorFactory create(
      Provider<Looper> looperProvider) {
    return new SysUIConcurrencyModule_ProvideExecutorFactory(looperProvider);
  }

  public static Executor provideExecutor(Looper looper) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideExecutor(looper));
  }
}

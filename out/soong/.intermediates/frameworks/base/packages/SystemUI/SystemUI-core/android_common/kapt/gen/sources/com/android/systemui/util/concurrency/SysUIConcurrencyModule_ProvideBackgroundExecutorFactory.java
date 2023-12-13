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
public final class SysUIConcurrencyModule_ProvideBackgroundExecutorFactory implements Factory<Executor> {
  private final Provider<Looper> looperProvider;

  public SysUIConcurrencyModule_ProvideBackgroundExecutorFactory(Provider<Looper> looperProvider) {
    this.looperProvider = looperProvider;
  }

  @Override
  public Executor get() {
    return provideBackgroundExecutor(looperProvider.get());
  }

  public static SysUIConcurrencyModule_ProvideBackgroundExecutorFactory create(
      Provider<Looper> looperProvider) {
    return new SysUIConcurrencyModule_ProvideBackgroundExecutorFactory(looperProvider);
  }

  public static Executor provideBackgroundExecutor(Looper looper) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideBackgroundExecutor(looper));
  }
}

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
public final class SysUIConcurrencyModule_ProvideLongRunningExecutorFactory implements Factory<Executor> {
  private final Provider<Looper> looperProvider;

  public SysUIConcurrencyModule_ProvideLongRunningExecutorFactory(Provider<Looper> looperProvider) {
    this.looperProvider = looperProvider;
  }

  @Override
  public Executor get() {
    return provideLongRunningExecutor(looperProvider.get());
  }

  public static SysUIConcurrencyModule_ProvideLongRunningExecutorFactory create(
      Provider<Looper> looperProvider) {
    return new SysUIConcurrencyModule_ProvideLongRunningExecutorFactory(looperProvider);
  }

  public static Executor provideLongRunningExecutor(Looper looper) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideLongRunningExecutor(looper));
  }
}

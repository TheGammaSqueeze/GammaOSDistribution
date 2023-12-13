package com.android.systemui.util.concurrency;

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
public final class SysUIConcurrencyModule_ProvideRepeatableExecutorFactory implements Factory<RepeatableExecutor> {
  private final Provider<DelayableExecutor> execProvider;

  public SysUIConcurrencyModule_ProvideRepeatableExecutorFactory(
      Provider<DelayableExecutor> execProvider) {
    this.execProvider = execProvider;
  }

  @Override
  public RepeatableExecutor get() {
    return provideRepeatableExecutor(execProvider.get());
  }

  public static SysUIConcurrencyModule_ProvideRepeatableExecutorFactory create(
      Provider<DelayableExecutor> execProvider) {
    return new SysUIConcurrencyModule_ProvideRepeatableExecutorFactory(execProvider);
  }

  public static RepeatableExecutor provideRepeatableExecutor(DelayableExecutor exec) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideRepeatableExecutor(exec));
  }
}

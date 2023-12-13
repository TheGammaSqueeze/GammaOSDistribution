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
public final class SysUIConcurrencyModule_ProvideBackgroundRepeatableExecutorFactory implements Factory<RepeatableExecutor> {
  private final Provider<DelayableExecutor> execProvider;

  public SysUIConcurrencyModule_ProvideBackgroundRepeatableExecutorFactory(
      Provider<DelayableExecutor> execProvider) {
    this.execProvider = execProvider;
  }

  @Override
  public RepeatableExecutor get() {
    return provideBackgroundRepeatableExecutor(execProvider.get());
  }

  public static SysUIConcurrencyModule_ProvideBackgroundRepeatableExecutorFactory create(
      Provider<DelayableExecutor> execProvider) {
    return new SysUIConcurrencyModule_ProvideBackgroundRepeatableExecutorFactory(execProvider);
  }

  public static RepeatableExecutor provideBackgroundRepeatableExecutor(DelayableExecutor exec) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideBackgroundRepeatableExecutor(exec));
  }
}

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
public final class SysUIConcurrencyModule_ProvideMainRepeatableExecutorFactory implements Factory<RepeatableExecutor> {
  private final Provider<DelayableExecutor> execProvider;

  public SysUIConcurrencyModule_ProvideMainRepeatableExecutorFactory(
      Provider<DelayableExecutor> execProvider) {
    this.execProvider = execProvider;
  }

  @Override
  public RepeatableExecutor get() {
    return provideMainRepeatableExecutor(execProvider.get());
  }

  public static SysUIConcurrencyModule_ProvideMainRepeatableExecutorFactory create(
      Provider<DelayableExecutor> execProvider) {
    return new SysUIConcurrencyModule_ProvideMainRepeatableExecutorFactory(execProvider);
  }

  public static RepeatableExecutor provideMainRepeatableExecutor(DelayableExecutor exec) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideMainRepeatableExecutor(exec));
  }
}

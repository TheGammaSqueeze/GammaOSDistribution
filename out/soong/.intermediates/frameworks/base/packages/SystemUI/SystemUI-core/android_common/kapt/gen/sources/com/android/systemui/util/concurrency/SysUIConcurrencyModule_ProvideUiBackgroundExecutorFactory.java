package com.android.systemui.util.concurrency;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.concurrent.Executor;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class SysUIConcurrencyModule_ProvideUiBackgroundExecutorFactory implements Factory<Executor> {
  @Override
  public Executor get() {
    return provideUiBackgroundExecutor();
  }

  public static SysUIConcurrencyModule_ProvideUiBackgroundExecutorFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static Executor provideUiBackgroundExecutor() {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideUiBackgroundExecutor());
  }

  private static final class InstanceHolder {
    private static final SysUIConcurrencyModule_ProvideUiBackgroundExecutorFactory INSTANCE = new SysUIConcurrencyModule_ProvideUiBackgroundExecutorFactory();
  }
}

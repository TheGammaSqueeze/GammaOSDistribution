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
public final class SysUIConcurrencyModule_ProvidesMainMessageRouterFactory implements Factory<MessageRouter> {
  private final Provider<DelayableExecutor> executorProvider;

  public SysUIConcurrencyModule_ProvidesMainMessageRouterFactory(
      Provider<DelayableExecutor> executorProvider) {
    this.executorProvider = executorProvider;
  }

  @Override
  public MessageRouter get() {
    return providesMainMessageRouter(executorProvider.get());
  }

  public static SysUIConcurrencyModule_ProvidesMainMessageRouterFactory create(
      Provider<DelayableExecutor> executorProvider) {
    return new SysUIConcurrencyModule_ProvidesMainMessageRouterFactory(executorProvider);
  }

  public static MessageRouter providesMainMessageRouter(DelayableExecutor executor) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.providesMainMessageRouter(executor));
  }
}

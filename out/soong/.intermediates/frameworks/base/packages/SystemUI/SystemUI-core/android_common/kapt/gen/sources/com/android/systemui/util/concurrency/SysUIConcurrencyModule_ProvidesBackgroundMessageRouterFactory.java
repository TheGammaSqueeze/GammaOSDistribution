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
public final class SysUIConcurrencyModule_ProvidesBackgroundMessageRouterFactory implements Factory<MessageRouter> {
  private final Provider<DelayableExecutor> executorProvider;

  public SysUIConcurrencyModule_ProvidesBackgroundMessageRouterFactory(
      Provider<DelayableExecutor> executorProvider) {
    this.executorProvider = executorProvider;
  }

  @Override
  public MessageRouter get() {
    return providesBackgroundMessageRouter(executorProvider.get());
  }

  public static SysUIConcurrencyModule_ProvidesBackgroundMessageRouterFactory create(
      Provider<DelayableExecutor> executorProvider) {
    return new SysUIConcurrencyModule_ProvidesBackgroundMessageRouterFactory(executorProvider);
  }

  public static MessageRouter providesBackgroundMessageRouter(DelayableExecutor executor) {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.providesBackgroundMessageRouter(executor));
  }
}

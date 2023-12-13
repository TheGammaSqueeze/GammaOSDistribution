package com.android.systemui.keyguard;

import dagger.internal.Factory;
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
public final class DismissCallbackRegistry_Factory implements Factory<DismissCallbackRegistry> {
  private final Provider<Executor> uiBgExecutorProvider;

  public DismissCallbackRegistry_Factory(Provider<Executor> uiBgExecutorProvider) {
    this.uiBgExecutorProvider = uiBgExecutorProvider;
  }

  @Override
  public DismissCallbackRegistry get() {
    return newInstance(uiBgExecutorProvider.get());
  }

  public static DismissCallbackRegistry_Factory create(Provider<Executor> uiBgExecutorProvider) {
    return new DismissCallbackRegistry_Factory(uiBgExecutorProvider);
  }

  public static DismissCallbackRegistry newInstance(Executor uiBgExecutor) {
    return new DismissCallbackRegistry(uiBgExecutor);
  }
}

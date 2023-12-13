package com.android.systemui.util.concurrency;

import android.content.Context;
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
public final class GlobalConcurrencyModule_ProvideMainExecutorFactory implements Factory<Executor> {
  private final Provider<Context> contextProvider;

  public GlobalConcurrencyModule_ProvideMainExecutorFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public Executor get() {
    return provideMainExecutor(contextProvider.get());
  }

  public static GlobalConcurrencyModule_ProvideMainExecutorFactory create(
      Provider<Context> contextProvider) {
    return new GlobalConcurrencyModule_ProvideMainExecutorFactory(contextProvider);
  }

  public static Executor provideMainExecutor(Context context) {
    return Preconditions.checkNotNullFromProvides(GlobalConcurrencyModule.provideMainExecutor(context));
  }
}

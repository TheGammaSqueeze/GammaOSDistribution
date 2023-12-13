package com.android.systemui.statusbar.commandline;

import android.content.Context;
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
public final class CommandRegistry_Factory implements Factory<CommandRegistry> {
  private final Provider<Context> contextProvider;

  private final Provider<Executor> mainExecutorProvider;

  public CommandRegistry_Factory(Provider<Context> contextProvider,
      Provider<Executor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public CommandRegistry get() {
    return newInstance(contextProvider.get(), mainExecutorProvider.get());
  }

  public static CommandRegistry_Factory create(Provider<Context> contextProvider,
      Provider<Executor> mainExecutorProvider) {
    return new CommandRegistry_Factory(contextProvider, mainExecutorProvider);
  }

  public static CommandRegistry newInstance(Context context, Executor mainExecutor) {
    return new CommandRegistry(context, mainExecutor);
  }
}

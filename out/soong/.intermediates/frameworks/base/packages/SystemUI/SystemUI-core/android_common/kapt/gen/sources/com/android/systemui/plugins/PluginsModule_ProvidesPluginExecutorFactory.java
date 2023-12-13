package com.android.systemui.plugins;

import com.android.systemui.util.concurrency.ThreadFactory;
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
public final class PluginsModule_ProvidesPluginExecutorFactory implements Factory<Executor> {
  private final Provider<ThreadFactory> threadFactoryProvider;

  public PluginsModule_ProvidesPluginExecutorFactory(
      Provider<ThreadFactory> threadFactoryProvider) {
    this.threadFactoryProvider = threadFactoryProvider;
  }

  @Override
  public Executor get() {
    return providesPluginExecutor(threadFactoryProvider.get());
  }

  public static PluginsModule_ProvidesPluginExecutorFactory create(
      Provider<ThreadFactory> threadFactoryProvider) {
    return new PluginsModule_ProvidesPluginExecutorFactory(threadFactoryProvider);
  }

  public static Executor providesPluginExecutor(ThreadFactory threadFactory) {
    return Preconditions.checkNotNullFromProvides(PluginsModule.providesPluginExecutor(threadFactory));
  }
}

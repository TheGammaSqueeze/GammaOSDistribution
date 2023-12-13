package dagger.internal.codegen;

import com.google.common.collect.ImmutableSet;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import dagger.spi.BindingGraphPlugin;
import java.util.Optional;
import javax.annotation.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class SpiModule_ExternalPluginsFactory implements Factory<ImmutableSet<BindingGraphPlugin>> {
  private final Provider<Optional<ImmutableSet<BindingGraphPlugin>>> testingPluginsProvider;

  private final Provider<ClassLoader> processorClassLoaderProvider;

  public SpiModule_ExternalPluginsFactory(
      Provider<Optional<ImmutableSet<BindingGraphPlugin>>> testingPluginsProvider,
      Provider<ClassLoader> processorClassLoaderProvider) {
    this.testingPluginsProvider = testingPluginsProvider;
    this.processorClassLoaderProvider = processorClassLoaderProvider;
  }

  @Override
  public ImmutableSet<BindingGraphPlugin> get() {
    return externalPlugins(testingPluginsProvider.get(), processorClassLoaderProvider.get());
  }

  public static SpiModule_ExternalPluginsFactory create(
      Provider<Optional<ImmutableSet<BindingGraphPlugin>>> testingPluginsProvider,
      Provider<ClassLoader> processorClassLoaderProvider) {
    return new SpiModule_ExternalPluginsFactory(testingPluginsProvider, processorClassLoaderProvider);
  }

  public static ImmutableSet<BindingGraphPlugin> externalPlugins(
      Optional<ImmutableSet<BindingGraphPlugin>> testingPlugins, ClassLoader processorClassLoader) {
    return Preconditions.checkNotNull(SpiModule.externalPlugins(testingPlugins, processorClassLoader), "Cannot return null from a non-@Nullable @Provides method");
  }
}

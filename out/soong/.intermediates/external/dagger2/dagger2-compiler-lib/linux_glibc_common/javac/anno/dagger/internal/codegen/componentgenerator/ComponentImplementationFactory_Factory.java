package dagger.internal.codegen.componentgenerator;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.KeyFactory;
import dagger.internal.codegen.compileroption.CompilerOptions;
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
public final class ComponentImplementationFactory_Factory implements Factory<ComponentImplementationFactory> {
  private final Provider<KeyFactory> keyFactoryProvider;

  private final Provider<CompilerOptions> compilerOptionsProvider;

  private final Provider<TopLevelImplementationComponent.Builder> topLevelImplementationComponentBuilderProvider;

  public ComponentImplementationFactory_Factory(Provider<KeyFactory> keyFactoryProvider,
      Provider<CompilerOptions> compilerOptionsProvider,
      Provider<TopLevelImplementationComponent.Builder> topLevelImplementationComponentBuilderProvider) {
    this.keyFactoryProvider = keyFactoryProvider;
    this.compilerOptionsProvider = compilerOptionsProvider;
    this.topLevelImplementationComponentBuilderProvider = topLevelImplementationComponentBuilderProvider;
  }

  @Override
  public ComponentImplementationFactory get() {
    return new ComponentImplementationFactory(keyFactoryProvider.get(), compilerOptionsProvider.get(), topLevelImplementationComponentBuilderProvider.get());
  }

  public static ComponentImplementationFactory_Factory create(
      Provider<KeyFactory> keyFactoryProvider, Provider<CompilerOptions> compilerOptionsProvider,
      Provider<TopLevelImplementationComponent.Builder> topLevelImplementationComponentBuilderProvider) {
    return new ComponentImplementationFactory_Factory(keyFactoryProvider, compilerOptionsProvider, topLevelImplementationComponentBuilderProvider);
  }

  public static ComponentImplementationFactory newInstance(KeyFactory keyFactory,
      CompilerOptions compilerOptions,
      TopLevelImplementationComponent.Builder topLevelImplementationComponentBuilder) {
    return new ComponentImplementationFactory(keyFactory, compilerOptions, topLevelImplementationComponentBuilder);
  }
}

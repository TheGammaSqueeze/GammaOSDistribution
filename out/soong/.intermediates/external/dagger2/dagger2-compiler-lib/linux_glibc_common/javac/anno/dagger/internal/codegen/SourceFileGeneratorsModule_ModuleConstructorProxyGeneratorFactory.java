package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import dagger.internal.codegen.base.SourceFileGenerator;
import dagger.internal.codegen.compileroption.CompilerOptions;
import dagger.internal.codegen.writing.ModuleProxies;
import javax.annotation.Generated;
import javax.inject.Provider;
import javax.lang.model.element.TypeElement;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class SourceFileGeneratorsModule_ModuleConstructorProxyGeneratorFactory implements Factory<SourceFileGenerator<TypeElement>> {
  private final Provider<ModuleProxies.ModuleConstructorProxyGenerator> generatorProvider;

  private final Provider<CompilerOptions> compilerOptionsProvider;

  public SourceFileGeneratorsModule_ModuleConstructorProxyGeneratorFactory(
      Provider<ModuleProxies.ModuleConstructorProxyGenerator> generatorProvider,
      Provider<CompilerOptions> compilerOptionsProvider) {
    this.generatorProvider = generatorProvider;
    this.compilerOptionsProvider = compilerOptionsProvider;
  }

  @Override
  public SourceFileGenerator<TypeElement> get() {
    return moduleConstructorProxyGenerator(generatorProvider.get(), compilerOptionsProvider.get());
  }

  public static SourceFileGeneratorsModule_ModuleConstructorProxyGeneratorFactory create(
      Provider<ModuleProxies.ModuleConstructorProxyGenerator> generatorProvider,
      Provider<CompilerOptions> compilerOptionsProvider) {
    return new SourceFileGeneratorsModule_ModuleConstructorProxyGeneratorFactory(generatorProvider, compilerOptionsProvider);
  }

  public static SourceFileGenerator<TypeElement> moduleConstructorProxyGenerator(
      ModuleProxies.ModuleConstructorProxyGenerator generator, CompilerOptions compilerOptions) {
    return Preconditions.checkNotNull(SourceFileGeneratorsModule.moduleConstructorProxyGenerator(generator, compilerOptions), "Cannot return null from a non-@Nullable @Provides method");
  }
}

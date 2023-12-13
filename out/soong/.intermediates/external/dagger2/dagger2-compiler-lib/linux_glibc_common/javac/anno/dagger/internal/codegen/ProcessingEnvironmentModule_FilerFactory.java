package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import dagger.internal.codegen.compileroption.CompilerOptions;
import javax.annotation.Generated;
import javax.annotation.processing.Filer;
import javax.annotation.processing.ProcessingEnvironment;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class ProcessingEnvironmentModule_FilerFactory implements Factory<Filer> {
  private final Provider<CompilerOptions> compilerOptionsProvider;

  private final Provider<ProcessingEnvironment> processingEnvironmentProvider;

  public ProcessingEnvironmentModule_FilerFactory(Provider<CompilerOptions> compilerOptionsProvider,
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    this.compilerOptionsProvider = compilerOptionsProvider;
    this.processingEnvironmentProvider = processingEnvironmentProvider;
  }

  @Override
  public Filer get() {
    return filer(compilerOptionsProvider.get(), processingEnvironmentProvider.get());
  }

  public static ProcessingEnvironmentModule_FilerFactory create(
      Provider<CompilerOptions> compilerOptionsProvider,
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    return new ProcessingEnvironmentModule_FilerFactory(compilerOptionsProvider, processingEnvironmentProvider);
  }

  public static Filer filer(CompilerOptions compilerOptions,
      ProcessingEnvironment processingEnvironment) {
    return Preconditions.checkNotNull(ProcessingEnvironmentModule.filer(compilerOptions, processingEnvironment), "Cannot return null from a non-@Nullable @Provides method");
  }
}

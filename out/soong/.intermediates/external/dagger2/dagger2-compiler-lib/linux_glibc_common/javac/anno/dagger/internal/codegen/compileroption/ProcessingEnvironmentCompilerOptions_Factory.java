package dagger.internal.codegen.compileroption;

import dagger.internal.Factory;
import dagger.internal.codegen.langmodel.DaggerElements;
import javax.annotation.Generated;
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
public final class ProcessingEnvironmentCompilerOptions_Factory implements Factory<ProcessingEnvironmentCompilerOptions> {
  private final Provider<ProcessingEnvironment> processingEnvironmentProvider;

  private final Provider<DaggerElements> daggerElementsProvider;

  public ProcessingEnvironmentCompilerOptions_Factory(
      Provider<ProcessingEnvironment> processingEnvironmentProvider,
      Provider<DaggerElements> daggerElementsProvider) {
    this.processingEnvironmentProvider = processingEnvironmentProvider;
    this.daggerElementsProvider = daggerElementsProvider;
  }

  @Override
  public ProcessingEnvironmentCompilerOptions get() {
    return new ProcessingEnvironmentCompilerOptions(processingEnvironmentProvider.get(), daggerElementsProvider.get());
  }

  public static ProcessingEnvironmentCompilerOptions_Factory create(
      Provider<ProcessingEnvironment> processingEnvironmentProvider,
      Provider<DaggerElements> daggerElementsProvider) {
    return new ProcessingEnvironmentCompilerOptions_Factory(processingEnvironmentProvider, daggerElementsProvider);
  }

  public static ProcessingEnvironmentCompilerOptions newInstance(
      ProcessingEnvironment processingEnvironment, DaggerElements daggerElements) {
    return new ProcessingEnvironmentCompilerOptions(processingEnvironment, daggerElements);
  }
}

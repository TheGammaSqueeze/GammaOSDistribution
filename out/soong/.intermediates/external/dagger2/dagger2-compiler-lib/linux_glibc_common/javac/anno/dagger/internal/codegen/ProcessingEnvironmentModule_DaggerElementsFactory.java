package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class ProcessingEnvironmentModule_DaggerElementsFactory implements Factory<DaggerElements> {
  private final Provider<ProcessingEnvironment> processingEnvironmentProvider;

  public ProcessingEnvironmentModule_DaggerElementsFactory(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    this.processingEnvironmentProvider = processingEnvironmentProvider;
  }

  @Override
  public DaggerElements get() {
    return daggerElements(processingEnvironmentProvider.get());
  }

  public static ProcessingEnvironmentModule_DaggerElementsFactory create(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    return new ProcessingEnvironmentModule_DaggerElementsFactory(processingEnvironmentProvider);
  }

  public static DaggerElements daggerElements(ProcessingEnvironment processingEnvironment) {
    return Preconditions.checkNotNull(ProcessingEnvironmentModule.daggerElements(processingEnvironment), "Cannot return null from a non-@Nullable @Provides method");
  }
}

package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.Generated;
import javax.annotation.processing.ProcessingEnvironment;
import javax.inject.Provider;
import javax.lang.model.util.Types;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class ProcessingEnvironmentModule_TypesFactory implements Factory<Types> {
  private final Provider<ProcessingEnvironment> processingEnvironmentProvider;

  public ProcessingEnvironmentModule_TypesFactory(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    this.processingEnvironmentProvider = processingEnvironmentProvider;
  }

  @Override
  public Types get() {
    return types(processingEnvironmentProvider.get());
  }

  public static ProcessingEnvironmentModule_TypesFactory create(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    return new ProcessingEnvironmentModule_TypesFactory(processingEnvironmentProvider);
  }

  public static Types types(ProcessingEnvironment processingEnvironment) {
    return Preconditions.checkNotNull(ProcessingEnvironmentModule.types(processingEnvironment), "Cannot return null from a non-@Nullable @Provides method");
  }
}

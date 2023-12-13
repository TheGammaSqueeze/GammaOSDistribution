package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.Generated;
import javax.annotation.processing.Messager;
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
public final class ProcessingEnvironmentModule_MessagerFactory implements Factory<Messager> {
  private final Provider<ProcessingEnvironment> processingEnvironmentProvider;

  public ProcessingEnvironmentModule_MessagerFactory(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    this.processingEnvironmentProvider = processingEnvironmentProvider;
  }

  @Override
  public Messager get() {
    return messager(processingEnvironmentProvider.get());
  }

  public static ProcessingEnvironmentModule_MessagerFactory create(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    return new ProcessingEnvironmentModule_MessagerFactory(processingEnvironmentProvider);
  }

  public static Messager messager(ProcessingEnvironment processingEnvironment) {
    return Preconditions.checkNotNull(ProcessingEnvironmentModule.messager(processingEnvironment), "Cannot return null from a non-@Nullable @Provides method");
  }
}

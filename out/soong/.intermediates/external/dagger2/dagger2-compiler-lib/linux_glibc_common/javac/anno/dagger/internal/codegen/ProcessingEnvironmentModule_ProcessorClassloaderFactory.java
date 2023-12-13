package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class ProcessingEnvironmentModule_ProcessorClassloaderFactory implements Factory<ClassLoader> {
  private final Provider<ProcessingEnvironment> processingEnvironmentProvider;

  public ProcessingEnvironmentModule_ProcessorClassloaderFactory(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    this.processingEnvironmentProvider = processingEnvironmentProvider;
  }

  @Override
  public ClassLoader get() {
    return processorClassloader(processingEnvironmentProvider.get());
  }

  public static ProcessingEnvironmentModule_ProcessorClassloaderFactory create(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    return new ProcessingEnvironmentModule_ProcessorClassloaderFactory(processingEnvironmentProvider);
  }

  public static ClassLoader processorClassloader(ProcessingEnvironment processingEnvironment) {
    return Preconditions.checkNotNull(ProcessingEnvironmentModule.processorClassloader(processingEnvironment), "Cannot return null from a non-@Nullable @Provides method");
  }
}

package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.Generated;
import javax.annotation.processing.ProcessingEnvironment;
import javax.inject.Provider;
import javax.lang.model.SourceVersion;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class ProcessingEnvironmentModule_SourceVersionFactory implements Factory<SourceVersion> {
  private final Provider<ProcessingEnvironment> processingEnvironmentProvider;

  public ProcessingEnvironmentModule_SourceVersionFactory(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    this.processingEnvironmentProvider = processingEnvironmentProvider;
  }

  @Override
  public SourceVersion get() {
    return sourceVersion(processingEnvironmentProvider.get());
  }

  public static ProcessingEnvironmentModule_SourceVersionFactory create(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    return new ProcessingEnvironmentModule_SourceVersionFactory(processingEnvironmentProvider);
  }

  public static SourceVersion sourceVersion(ProcessingEnvironment processingEnvironment) {
    return Preconditions.checkNotNull(ProcessingEnvironmentModule.sourceVersion(processingEnvironment), "Cannot return null from a non-@Nullable @Provides method");
  }
}

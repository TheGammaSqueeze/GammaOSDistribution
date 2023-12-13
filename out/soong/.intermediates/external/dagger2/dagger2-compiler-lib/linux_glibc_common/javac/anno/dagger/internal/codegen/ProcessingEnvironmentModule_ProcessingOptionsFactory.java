package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Map;
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
public final class ProcessingEnvironmentModule_ProcessingOptionsFactory implements Factory<Map<String, String>> {
  private final Provider<ProcessingEnvironment> processingEnvironmentProvider;

  public ProcessingEnvironmentModule_ProcessingOptionsFactory(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    this.processingEnvironmentProvider = processingEnvironmentProvider;
  }

  @Override
  public Map<String, String> get() {
    return processingOptions(processingEnvironmentProvider.get());
  }

  public static ProcessingEnvironmentModule_ProcessingOptionsFactory create(
      Provider<ProcessingEnvironment> processingEnvironmentProvider) {
    return new ProcessingEnvironmentModule_ProcessingOptionsFactory(processingEnvironmentProvider);
  }

  public static Map<String, String> processingOptions(ProcessingEnvironment processingEnvironment) {
    return Preconditions.checkNotNull(ProcessingEnvironmentModule.processingOptions(processingEnvironment), "Cannot return null from a non-@Nullable @Provides method");
  }
}

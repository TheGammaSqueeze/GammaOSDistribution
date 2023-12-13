package dagger.internal.codegen.bindinggraphvalidation;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.DependencyRequestFormatter;
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
public final class DependencyCycleValidator_Factory implements Factory<DependencyCycleValidator> {
  private final Provider<DependencyRequestFormatter> dependencyRequestFormatterProvider;

  public DependencyCycleValidator_Factory(
      Provider<DependencyRequestFormatter> dependencyRequestFormatterProvider) {
    this.dependencyRequestFormatterProvider = dependencyRequestFormatterProvider;
  }

  @Override
  public DependencyCycleValidator get() {
    return new DependencyCycleValidator(dependencyRequestFormatterProvider.get());
  }

  public static DependencyCycleValidator_Factory create(
      Provider<DependencyRequestFormatter> dependencyRequestFormatterProvider) {
    return new DependencyCycleValidator_Factory(dependencyRequestFormatterProvider);
  }

  public static DependencyCycleValidator newInstance(
      DependencyRequestFormatter dependencyRequestFormatter) {
    return new DependencyCycleValidator(dependencyRequestFormatter);
  }
}

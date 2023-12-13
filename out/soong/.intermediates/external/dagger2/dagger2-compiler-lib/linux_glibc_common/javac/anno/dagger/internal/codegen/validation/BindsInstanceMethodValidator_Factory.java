package dagger.internal.codegen.validation;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.InjectionAnnotations;
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
public final class BindsInstanceMethodValidator_Factory implements Factory<BindsInstanceMethodValidator> {
  private final Provider<InjectionAnnotations> injectionAnnotationsProvider;

  public BindsInstanceMethodValidator_Factory(
      Provider<InjectionAnnotations> injectionAnnotationsProvider) {
    this.injectionAnnotationsProvider = injectionAnnotationsProvider;
  }

  @Override
  public BindsInstanceMethodValidator get() {
    return new BindsInstanceMethodValidator(injectionAnnotationsProvider.get());
  }

  public static BindsInstanceMethodValidator_Factory create(
      Provider<InjectionAnnotations> injectionAnnotationsProvider) {
    return new BindsInstanceMethodValidator_Factory(injectionAnnotationsProvider);
  }

  public static BindsInstanceMethodValidator newInstance(
      InjectionAnnotations injectionAnnotations) {
    return new BindsInstanceMethodValidator(injectionAnnotations);
  }
}

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
public final class BindsInstanceParameterValidator_Factory implements Factory<BindsInstanceParameterValidator> {
  private final Provider<InjectionAnnotations> injectionAnnotationsProvider;

  public BindsInstanceParameterValidator_Factory(
      Provider<InjectionAnnotations> injectionAnnotationsProvider) {
    this.injectionAnnotationsProvider = injectionAnnotationsProvider;
  }

  @Override
  public BindsInstanceParameterValidator get() {
    return new BindsInstanceParameterValidator(injectionAnnotationsProvider.get());
  }

  public static BindsInstanceParameterValidator_Factory create(
      Provider<InjectionAnnotations> injectionAnnotationsProvider) {
    return new BindsInstanceParameterValidator_Factory(injectionAnnotationsProvider);
  }

  public static BindsInstanceParameterValidator newInstance(
      InjectionAnnotations injectionAnnotations) {
    return new BindsInstanceParameterValidator(injectionAnnotations);
  }
}

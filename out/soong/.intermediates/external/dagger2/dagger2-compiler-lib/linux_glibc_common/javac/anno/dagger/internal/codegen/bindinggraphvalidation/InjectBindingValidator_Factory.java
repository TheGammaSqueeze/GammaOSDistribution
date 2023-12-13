package dagger.internal.codegen.bindinggraphvalidation;

import dagger.internal.Factory;
import dagger.internal.codegen.validation.InjectValidator;
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
public final class InjectBindingValidator_Factory implements Factory<InjectBindingValidator> {
  private final Provider<InjectValidator> injectValidatorProvider;

  public InjectBindingValidator_Factory(Provider<InjectValidator> injectValidatorProvider) {
    this.injectValidatorProvider = injectValidatorProvider;
  }

  @Override
  public InjectBindingValidator get() {
    return new InjectBindingValidator(injectValidatorProvider.get());
  }

  public static InjectBindingValidator_Factory create(
      Provider<InjectValidator> injectValidatorProvider) {
    return new InjectBindingValidator_Factory(injectValidatorProvider);
  }

  public static InjectBindingValidator newInstance(InjectValidator injectValidator) {
    return new InjectBindingValidator(injectValidator);
  }
}

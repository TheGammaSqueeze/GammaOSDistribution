package dagger.internal.codegen.validation;

import dagger.internal.Factory;
import javax.annotation.Generated;
import javax.annotation.processing.Messager;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class BindingMethodProcessingStep_Factory implements Factory<BindingMethodProcessingStep> {
  private final Provider<Messager> messagerProvider;

  private final Provider<AnyBindingMethodValidator> anyBindingMethodValidatorProvider;

  public BindingMethodProcessingStep_Factory(Provider<Messager> messagerProvider,
      Provider<AnyBindingMethodValidator> anyBindingMethodValidatorProvider) {
    this.messagerProvider = messagerProvider;
    this.anyBindingMethodValidatorProvider = anyBindingMethodValidatorProvider;
  }

  @Override
  public BindingMethodProcessingStep get() {
    return new BindingMethodProcessingStep(messagerProvider.get(), anyBindingMethodValidatorProvider.get());
  }

  public static BindingMethodProcessingStep_Factory create(Provider<Messager> messagerProvider,
      Provider<AnyBindingMethodValidator> anyBindingMethodValidatorProvider) {
    return new BindingMethodProcessingStep_Factory(messagerProvider, anyBindingMethodValidatorProvider);
  }

  public static BindingMethodProcessingStep newInstance(Messager messager,
      AnyBindingMethodValidator anyBindingMethodValidator) {
    return new BindingMethodProcessingStep(messager, anyBindingMethodValidator);
  }
}

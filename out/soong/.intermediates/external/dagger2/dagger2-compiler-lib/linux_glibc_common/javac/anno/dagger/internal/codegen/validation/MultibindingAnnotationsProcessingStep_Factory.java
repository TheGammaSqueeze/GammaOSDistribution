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
public final class MultibindingAnnotationsProcessingStep_Factory implements Factory<MultibindingAnnotationsProcessingStep> {
  private final Provider<AnyBindingMethodValidator> anyBindingMethodValidatorProvider;

  private final Provider<Messager> messagerProvider;

  public MultibindingAnnotationsProcessingStep_Factory(
      Provider<AnyBindingMethodValidator> anyBindingMethodValidatorProvider,
      Provider<Messager> messagerProvider) {
    this.anyBindingMethodValidatorProvider = anyBindingMethodValidatorProvider;
    this.messagerProvider = messagerProvider;
  }

  @Override
  public MultibindingAnnotationsProcessingStep get() {
    return new MultibindingAnnotationsProcessingStep(anyBindingMethodValidatorProvider.get(), messagerProvider.get());
  }

  public static MultibindingAnnotationsProcessingStep_Factory create(
      Provider<AnyBindingMethodValidator> anyBindingMethodValidatorProvider,
      Provider<Messager> messagerProvider) {
    return new MultibindingAnnotationsProcessingStep_Factory(anyBindingMethodValidatorProvider, messagerProvider);
  }

  public static MultibindingAnnotationsProcessingStep newInstance(
      AnyBindingMethodValidator anyBindingMethodValidator, Messager messager) {
    return new MultibindingAnnotationsProcessingStep(anyBindingMethodValidator, messager);
  }
}

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
public final class BindsInstanceProcessingStep_Factory implements Factory<BindsInstanceProcessingStep> {
  private final Provider<BindsInstanceMethodValidator> methodValidatorProvider;

  private final Provider<BindsInstanceParameterValidator> parameterValidatorProvider;

  private final Provider<Messager> messagerProvider;

  public BindsInstanceProcessingStep_Factory(
      Provider<BindsInstanceMethodValidator> methodValidatorProvider,
      Provider<BindsInstanceParameterValidator> parameterValidatorProvider,
      Provider<Messager> messagerProvider) {
    this.methodValidatorProvider = methodValidatorProvider;
    this.parameterValidatorProvider = parameterValidatorProvider;
    this.messagerProvider = messagerProvider;
  }

  @Override
  public BindsInstanceProcessingStep get() {
    return new BindsInstanceProcessingStep(methodValidatorProvider.get(), parameterValidatorProvider.get(), messagerProvider.get());
  }

  public static BindsInstanceProcessingStep_Factory create(
      Provider<BindsInstanceMethodValidator> methodValidatorProvider,
      Provider<BindsInstanceParameterValidator> parameterValidatorProvider,
      Provider<Messager> messagerProvider) {
    return new BindsInstanceProcessingStep_Factory(methodValidatorProvider, parameterValidatorProvider, messagerProvider);
  }

  public static BindsInstanceProcessingStep newInstance(Object methodValidator,
      Object parameterValidator, Messager messager) {
    return new BindsInstanceProcessingStep((BindsInstanceMethodValidator) methodValidator, (BindsInstanceParameterValidator) parameterValidator, messager);
  }
}

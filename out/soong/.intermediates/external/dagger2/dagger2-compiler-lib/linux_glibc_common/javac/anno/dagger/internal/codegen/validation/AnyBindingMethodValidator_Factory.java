package dagger.internal.codegen.validation;

import com.google.common.collect.ImmutableMap;
import dagger.internal.Factory;
import java.lang.annotation.Annotation;
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
public final class AnyBindingMethodValidator_Factory implements Factory<AnyBindingMethodValidator> {
  private final Provider<ImmutableMap<Class<? extends Annotation>, BindingMethodValidator>> validatorsProvider;

  public AnyBindingMethodValidator_Factory(
      Provider<ImmutableMap<Class<? extends Annotation>, BindingMethodValidator>> validatorsProvider) {
    this.validatorsProvider = validatorsProvider;
  }

  @Override
  public AnyBindingMethodValidator get() {
    return new AnyBindingMethodValidator(validatorsProvider.get());
  }

  public static AnyBindingMethodValidator_Factory create(
      Provider<ImmutableMap<Class<? extends Annotation>, BindingMethodValidator>> validatorsProvider) {
    return new AnyBindingMethodValidator_Factory(validatorsProvider);
  }

  public static AnyBindingMethodValidator newInstance(
      ImmutableMap<Class<? extends Annotation>, BindingMethodValidator> validators) {
    return new AnyBindingMethodValidator(validators);
  }
}

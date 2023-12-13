package dagger.internal.codegen.validation;

import com.google.common.collect.ImmutableMap;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.lang.annotation.Annotation;
import java.util.Set;
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
public final class BindingMethodValidatorsModule_IndexValidatorsFactory implements Factory<ImmutableMap<Class<? extends Annotation>, BindingMethodValidator>> {
  private final Provider<Set<BindingMethodValidator>> validatorsProvider;

  public BindingMethodValidatorsModule_IndexValidatorsFactory(
      Provider<Set<BindingMethodValidator>> validatorsProvider) {
    this.validatorsProvider = validatorsProvider;
  }

  @Override
  public ImmutableMap<Class<? extends Annotation>, BindingMethodValidator> get() {
    return indexValidators(validatorsProvider.get());
  }

  public static BindingMethodValidatorsModule_IndexValidatorsFactory create(
      Provider<Set<BindingMethodValidator>> validatorsProvider) {
    return new BindingMethodValidatorsModule_IndexValidatorsFactory(validatorsProvider);
  }

  public static ImmutableMap<Class<? extends Annotation>, BindingMethodValidator> indexValidators(
      Set<BindingMethodValidator> validators) {
    return Preconditions.checkNotNull(BindingMethodValidatorsModule.indexValidators(validators), "Cannot return null from a non-@Nullable @Provides method");
  }
}

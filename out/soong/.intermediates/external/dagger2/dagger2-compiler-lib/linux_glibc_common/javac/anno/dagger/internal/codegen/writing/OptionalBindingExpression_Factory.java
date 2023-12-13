package dagger.internal.codegen.writing;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.ProvisionBinding;
import dagger.internal.codegen.langmodel.DaggerTypes;
import javax.annotation.Generated;
import javax.inject.Provider;
import javax.lang.model.SourceVersion;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class OptionalBindingExpression_Factory implements Factory<OptionalBindingExpression> {
  private final Provider<ProvisionBinding> bindingProvider;

  private final Provider<ComponentBindingExpressions> componentBindingExpressionsProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  public OptionalBindingExpression_Factory(Provider<ProvisionBinding> bindingProvider,
      Provider<ComponentBindingExpressions> componentBindingExpressionsProvider,
      Provider<DaggerTypes> typesProvider, Provider<SourceVersion> sourceVersionProvider) {
    this.bindingProvider = bindingProvider;
    this.componentBindingExpressionsProvider = componentBindingExpressionsProvider;
    this.typesProvider = typesProvider;
    this.sourceVersionProvider = sourceVersionProvider;
  }

  @Override
  public OptionalBindingExpression get() {
    return new OptionalBindingExpression(bindingProvider.get(), componentBindingExpressionsProvider.get(), typesProvider.get(), sourceVersionProvider.get());
  }

  public static OptionalBindingExpression_Factory create(Provider<ProvisionBinding> bindingProvider,
      Provider<ComponentBindingExpressions> componentBindingExpressionsProvider,
      Provider<DaggerTypes> typesProvider, Provider<SourceVersion> sourceVersionProvider) {
    return new OptionalBindingExpression_Factory(bindingProvider, componentBindingExpressionsProvider, typesProvider, sourceVersionProvider);
  }

  public static OptionalBindingExpression newInstance(ProvisionBinding binding,
      ComponentBindingExpressions componentBindingExpressions, DaggerTypes types,
      SourceVersion sourceVersion) {
    return new OptionalBindingExpression(binding, componentBindingExpressions, types, sourceVersion);
  }
}

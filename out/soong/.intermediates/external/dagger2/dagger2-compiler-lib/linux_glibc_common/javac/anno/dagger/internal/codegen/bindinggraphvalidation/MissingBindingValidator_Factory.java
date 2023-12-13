package dagger.internal.codegen.bindinggraphvalidation;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.InjectBindingRegistry;
import dagger.internal.codegen.langmodel.DaggerTypes;
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
public final class MissingBindingValidator_Factory implements Factory<MissingBindingValidator> {
  private final Provider<DaggerTypes> typesProvider;

  private final Provider<InjectBindingRegistry> injectBindingRegistryProvider;

  public MissingBindingValidator_Factory(Provider<DaggerTypes> typesProvider,
      Provider<InjectBindingRegistry> injectBindingRegistryProvider) {
    this.typesProvider = typesProvider;
    this.injectBindingRegistryProvider = injectBindingRegistryProvider;
  }

  @Override
  public MissingBindingValidator get() {
    return new MissingBindingValidator(typesProvider.get(), injectBindingRegistryProvider.get());
  }

  public static MissingBindingValidator_Factory create(Provider<DaggerTypes> typesProvider,
      Provider<InjectBindingRegistry> injectBindingRegistryProvider) {
    return new MissingBindingValidator_Factory(typesProvider, injectBindingRegistryProvider);
  }

  public static MissingBindingValidator newInstance(DaggerTypes types,
      InjectBindingRegistry injectBindingRegistry) {
    return new MissingBindingValidator(types, injectBindingRegistry);
  }
}

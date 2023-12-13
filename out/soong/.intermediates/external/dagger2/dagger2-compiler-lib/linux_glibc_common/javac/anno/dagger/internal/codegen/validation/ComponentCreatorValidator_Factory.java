package dagger.internal.codegen.validation;

import dagger.internal.Factory;
import dagger.internal.codegen.langmodel.DaggerElements;
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
public final class ComponentCreatorValidator_Factory implements Factory<ComponentCreatorValidator> {
  private final Provider<DaggerElements> elementsProvider;

  private final Provider<DaggerTypes> typesProvider;

  public ComponentCreatorValidator_Factory(Provider<DaggerElements> elementsProvider,
      Provider<DaggerTypes> typesProvider) {
    this.elementsProvider = elementsProvider;
    this.typesProvider = typesProvider;
  }

  @Override
  public ComponentCreatorValidator get() {
    return new ComponentCreatorValidator(elementsProvider.get(), typesProvider.get());
  }

  public static ComponentCreatorValidator_Factory create(Provider<DaggerElements> elementsProvider,
      Provider<DaggerTypes> typesProvider) {
    return new ComponentCreatorValidator_Factory(elementsProvider, typesProvider);
  }

  public static ComponentCreatorValidator newInstance(DaggerElements elements, DaggerTypes types) {
    return new ComponentCreatorValidator(elements, types);
  }
}

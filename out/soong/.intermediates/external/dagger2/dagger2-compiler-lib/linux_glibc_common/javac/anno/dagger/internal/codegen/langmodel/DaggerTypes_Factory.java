package dagger.internal.codegen.langmodel;

import dagger.internal.Factory;
import javax.annotation.Generated;
import javax.inject.Provider;
import javax.lang.model.util.Types;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class DaggerTypes_Factory implements Factory<DaggerTypes> {
  private final Provider<Types> typesProvider;

  private final Provider<DaggerElements> elementsProvider;

  public DaggerTypes_Factory(Provider<Types> typesProvider,
      Provider<DaggerElements> elementsProvider) {
    this.typesProvider = typesProvider;
    this.elementsProvider = elementsProvider;
  }

  @Override
  public DaggerTypes get() {
    return new DaggerTypes(typesProvider.get(), elementsProvider.get());
  }

  public static DaggerTypes_Factory create(Provider<Types> typesProvider,
      Provider<DaggerElements> elementsProvider) {
    return new DaggerTypes_Factory(typesProvider, elementsProvider);
  }

  public static DaggerTypes newInstance(Types types, DaggerElements elements) {
    return new DaggerTypes(types, elements);
  }
}

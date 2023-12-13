package dagger.internal.codegen.validation;

import dagger.internal.Factory;
import dagger.internal.codegen.langmodel.DaggerElements;
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
public final class MapKeyValidator_Factory implements Factory<MapKeyValidator> {
  private final Provider<DaggerElements> elementsProvider;

  public MapKeyValidator_Factory(Provider<DaggerElements> elementsProvider) {
    this.elementsProvider = elementsProvider;
  }

  @Override
  public MapKeyValidator get() {
    return new MapKeyValidator(elementsProvider.get());
  }

  public static MapKeyValidator_Factory create(Provider<DaggerElements> elementsProvider) {
    return new MapKeyValidator_Factory(elementsProvider);
  }

  public static MapKeyValidator newInstance(DaggerElements elements) {
    return new MapKeyValidator(elements);
  }
}

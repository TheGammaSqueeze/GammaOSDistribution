package dagger.internal.codegen.binding;

import dagger.internal.Factory;
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
public final class DependencyRequestFormatter_Factory implements Factory<DependencyRequestFormatter> {
  private final Provider<DaggerTypes> typesProvider;

  public DependencyRequestFormatter_Factory(Provider<DaggerTypes> typesProvider) {
    this.typesProvider = typesProvider;
  }

  @Override
  public DependencyRequestFormatter get() {
    return new DependencyRequestFormatter(typesProvider.get());
  }

  public static DependencyRequestFormatter_Factory create(Provider<DaggerTypes> typesProvider) {
    return new DependencyRequestFormatter_Factory(typesProvider);
  }

  public static DependencyRequestFormatter newInstance(DaggerTypes types) {
    return new DependencyRequestFormatter(types);
  }
}

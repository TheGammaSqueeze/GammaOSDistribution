package dagger.internal.codegen.writing;

import dagger.internal.Factory;
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
public final class OptionalFactories_Factory implements Factory<OptionalFactories> {
  private final Provider<ComponentImplementation> componentImplementationProvider;

  public OptionalFactories_Factory(
      Provider<ComponentImplementation> componentImplementationProvider) {
    this.componentImplementationProvider = componentImplementationProvider;
  }

  @Override
  public OptionalFactories get() {
    return new OptionalFactories(componentImplementationProvider.get());
  }

  public static OptionalFactories_Factory create(
      Provider<ComponentImplementation> componentImplementationProvider) {
    return new OptionalFactories_Factory(componentImplementationProvider);
  }

  public static OptionalFactories newInstance(ComponentImplementation componentImplementation) {
    return new OptionalFactories(componentImplementation);
  }
}

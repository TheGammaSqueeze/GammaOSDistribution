package dagger.internal.codegen.componentgenerator;

import dagger.internal.Factory;
import dagger.internal.codegen.langmodel.DaggerElements;
import javax.annotation.Generated;
import javax.annotation.processing.Filer;
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
public final class ComponentGenerator_Factory implements Factory<ComponentGenerator> {
  private final Provider<Filer> filerProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  private final Provider<ComponentImplementationFactory> componentImplementationFactoryProvider;

  public ComponentGenerator_Factory(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider,
      Provider<ComponentImplementationFactory> componentImplementationFactoryProvider) {
    this.filerProvider = filerProvider;
    this.elementsProvider = elementsProvider;
    this.sourceVersionProvider = sourceVersionProvider;
    this.componentImplementationFactoryProvider = componentImplementationFactoryProvider;
  }

  @Override
  public ComponentGenerator get() {
    return new ComponentGenerator(filerProvider.get(), elementsProvider.get(), sourceVersionProvider.get(), componentImplementationFactoryProvider.get());
  }

  public static ComponentGenerator_Factory create(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider,
      Provider<ComponentImplementationFactory> componentImplementationFactoryProvider) {
    return new ComponentGenerator_Factory(filerProvider, elementsProvider, sourceVersionProvider, componentImplementationFactoryProvider);
  }

  public static ComponentGenerator newInstance(Filer filer, DaggerElements elements,
      SourceVersion sourceVersion, Object componentImplementationFactory) {
    return new ComponentGenerator(filer, elements, sourceVersion, (ComponentImplementationFactory) componentImplementationFactory);
  }
}

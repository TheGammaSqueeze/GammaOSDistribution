package dagger.internal.codegen.writing;

import dagger.internal.Factory;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
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
public final class InaccessibleMapKeyProxyGenerator_Factory implements Factory<InaccessibleMapKeyProxyGenerator> {
  private final Provider<Filer> filerProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  public InaccessibleMapKeyProxyGenerator_Factory(Provider<Filer> filerProvider,
      Provider<DaggerTypes> typesProvider, Provider<DaggerElements> elementsProvider,
      Provider<SourceVersion> sourceVersionProvider) {
    this.filerProvider = filerProvider;
    this.typesProvider = typesProvider;
    this.elementsProvider = elementsProvider;
    this.sourceVersionProvider = sourceVersionProvider;
  }

  @Override
  public InaccessibleMapKeyProxyGenerator get() {
    return new InaccessibleMapKeyProxyGenerator(filerProvider.get(), typesProvider.get(), elementsProvider.get(), sourceVersionProvider.get());
  }

  public static InaccessibleMapKeyProxyGenerator_Factory create(Provider<Filer> filerProvider,
      Provider<DaggerTypes> typesProvider, Provider<DaggerElements> elementsProvider,
      Provider<SourceVersion> sourceVersionProvider) {
    return new InaccessibleMapKeyProxyGenerator_Factory(filerProvider, typesProvider, elementsProvider, sourceVersionProvider);
  }

  public static InaccessibleMapKeyProxyGenerator newInstance(Filer filer, DaggerTypes types,
      DaggerElements elements, SourceVersion sourceVersion) {
    return new InaccessibleMapKeyProxyGenerator(filer, types, elements, sourceVersion);
  }
}

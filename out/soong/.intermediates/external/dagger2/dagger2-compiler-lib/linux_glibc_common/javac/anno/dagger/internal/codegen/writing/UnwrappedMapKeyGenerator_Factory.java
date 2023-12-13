package dagger.internal.codegen.writing;

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
public final class UnwrappedMapKeyGenerator_Factory implements Factory<UnwrappedMapKeyGenerator> {
  private final Provider<Filer> filerProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  public UnwrappedMapKeyGenerator_Factory(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider) {
    this.filerProvider = filerProvider;
    this.elementsProvider = elementsProvider;
    this.sourceVersionProvider = sourceVersionProvider;
  }

  @Override
  public UnwrappedMapKeyGenerator get() {
    return new UnwrappedMapKeyGenerator(filerProvider.get(), elementsProvider.get(), sourceVersionProvider.get());
  }

  public static UnwrappedMapKeyGenerator_Factory create(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider) {
    return new UnwrappedMapKeyGenerator_Factory(filerProvider, elementsProvider, sourceVersionProvider);
  }

  public static UnwrappedMapKeyGenerator newInstance(Filer filer, DaggerElements elements,
      SourceVersion sourceVersion) {
    return new UnwrappedMapKeyGenerator(filer, elements, sourceVersion);
  }
}

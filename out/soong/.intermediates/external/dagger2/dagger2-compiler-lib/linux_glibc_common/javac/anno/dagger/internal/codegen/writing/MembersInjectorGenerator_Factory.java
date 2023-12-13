package dagger.internal.codegen.writing;

import dagger.internal.Factory;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
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
public final class MembersInjectorGenerator_Factory implements Factory<MembersInjectorGenerator> {
  private final Provider<Filer> filerProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  private final Provider<KotlinMetadataUtil> metadataUtilProvider;

  public MembersInjectorGenerator_Factory(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<DaggerTypes> typesProvider,
      Provider<SourceVersion> sourceVersionProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    this.filerProvider = filerProvider;
    this.elementsProvider = elementsProvider;
    this.typesProvider = typesProvider;
    this.sourceVersionProvider = sourceVersionProvider;
    this.metadataUtilProvider = metadataUtilProvider;
  }

  @Override
  public MembersInjectorGenerator get() {
    return new MembersInjectorGenerator(filerProvider.get(), elementsProvider.get(), typesProvider.get(), sourceVersionProvider.get(), metadataUtilProvider.get());
  }

  public static MembersInjectorGenerator_Factory create(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<DaggerTypes> typesProvider,
      Provider<SourceVersion> sourceVersionProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    return new MembersInjectorGenerator_Factory(filerProvider, elementsProvider, typesProvider, sourceVersionProvider, metadataUtilProvider);
  }

  public static MembersInjectorGenerator newInstance(Filer filer, DaggerElements elements,
      DaggerTypes types, SourceVersion sourceVersion, KotlinMetadataUtil metadataUtil) {
    return new MembersInjectorGenerator(filer, elements, types, sourceVersion, metadataUtil);
  }
}

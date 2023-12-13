package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.InjectionAnnotations;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import javax.annotation.Generated;
import javax.annotation.processing.Messager;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class AssistedProcessingStep_Factory implements Factory<AssistedProcessingStep> {
  private final Provider<KotlinMetadataUtil> kotlinMetadataUtilProvider;

  private final Provider<InjectionAnnotations> injectionAnnotationsProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<Messager> messagerProvider;

  public AssistedProcessingStep_Factory(Provider<KotlinMetadataUtil> kotlinMetadataUtilProvider,
      Provider<InjectionAnnotations> injectionAnnotationsProvider,
      Provider<DaggerElements> elementsProvider, Provider<DaggerTypes> typesProvider,
      Provider<Messager> messagerProvider) {
    this.kotlinMetadataUtilProvider = kotlinMetadataUtilProvider;
    this.injectionAnnotationsProvider = injectionAnnotationsProvider;
    this.elementsProvider = elementsProvider;
    this.typesProvider = typesProvider;
    this.messagerProvider = messagerProvider;
  }

  @Override
  public AssistedProcessingStep get() {
    return new AssistedProcessingStep(kotlinMetadataUtilProvider.get(), injectionAnnotationsProvider.get(), elementsProvider.get(), typesProvider.get(), messagerProvider.get());
  }

  public static AssistedProcessingStep_Factory create(
      Provider<KotlinMetadataUtil> kotlinMetadataUtilProvider,
      Provider<InjectionAnnotations> injectionAnnotationsProvider,
      Provider<DaggerElements> elementsProvider, Provider<DaggerTypes> typesProvider,
      Provider<Messager> messagerProvider) {
    return new AssistedProcessingStep_Factory(kotlinMetadataUtilProvider, injectionAnnotationsProvider, elementsProvider, typesProvider, messagerProvider);
  }

  public static AssistedProcessingStep newInstance(KotlinMetadataUtil kotlinMetadataUtil,
      InjectionAnnotations injectionAnnotations, DaggerElements elements, DaggerTypes types,
      Messager messager) {
    return new AssistedProcessingStep(kotlinMetadataUtil, injectionAnnotations, elements, types, messager);
  }
}

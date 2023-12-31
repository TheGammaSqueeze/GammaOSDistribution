package dagger.internal.codegen.validation;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.InjectionAnnotations;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
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
public final class ProducesMethodValidator_Factory implements Factory<ProducesMethodValidator> {
  private final Provider<DaggerElements> elementsProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<KotlinMetadataUtil> kotlinMetadataUtilProvider;

  private final Provider<DependencyRequestValidator> dependencyRequestValidatorProvider;

  private final Provider<InjectionAnnotations> injectionAnnotationsProvider;

  public ProducesMethodValidator_Factory(Provider<DaggerElements> elementsProvider,
      Provider<DaggerTypes> typesProvider, Provider<KotlinMetadataUtil> kotlinMetadataUtilProvider,
      Provider<DependencyRequestValidator> dependencyRequestValidatorProvider,
      Provider<InjectionAnnotations> injectionAnnotationsProvider) {
    this.elementsProvider = elementsProvider;
    this.typesProvider = typesProvider;
    this.kotlinMetadataUtilProvider = kotlinMetadataUtilProvider;
    this.dependencyRequestValidatorProvider = dependencyRequestValidatorProvider;
    this.injectionAnnotationsProvider = injectionAnnotationsProvider;
  }

  @Override
  public ProducesMethodValidator get() {
    return new ProducesMethodValidator(elementsProvider.get(), typesProvider.get(), kotlinMetadataUtilProvider.get(), dependencyRequestValidatorProvider.get(), injectionAnnotationsProvider.get());
  }

  public static ProducesMethodValidator_Factory create(Provider<DaggerElements> elementsProvider,
      Provider<DaggerTypes> typesProvider, Provider<KotlinMetadataUtil> kotlinMetadataUtilProvider,
      Provider<DependencyRequestValidator> dependencyRequestValidatorProvider,
      Provider<InjectionAnnotations> injectionAnnotationsProvider) {
    return new ProducesMethodValidator_Factory(elementsProvider, typesProvider, kotlinMetadataUtilProvider, dependencyRequestValidatorProvider, injectionAnnotationsProvider);
  }

  public static ProducesMethodValidator newInstance(DaggerElements elements, DaggerTypes types,
      KotlinMetadataUtil kotlinMetadataUtil, Object dependencyRequestValidator,
      InjectionAnnotations injectionAnnotations) {
    return new ProducesMethodValidator(elements, types, kotlinMetadataUtil, (DependencyRequestValidator) dependencyRequestValidator, injectionAnnotations);
  }
}

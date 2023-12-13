package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.internal.codegen.validation.MapKeyValidator;
import dagger.internal.codegen.writing.AnnotationCreatorGenerator;
import dagger.internal.codegen.writing.UnwrappedMapKeyGenerator;
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
public final class MapKeyProcessingStep_Factory implements Factory<MapKeyProcessingStep> {
  private final Provider<Messager> messagerProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<MapKeyValidator> mapKeyValidatorProvider;

  private final Provider<AnnotationCreatorGenerator> annotationCreatorGeneratorProvider;

  private final Provider<UnwrappedMapKeyGenerator> unwrappedMapKeyGeneratorProvider;

  public MapKeyProcessingStep_Factory(Provider<Messager> messagerProvider,
      Provider<DaggerTypes> typesProvider, Provider<MapKeyValidator> mapKeyValidatorProvider,
      Provider<AnnotationCreatorGenerator> annotationCreatorGeneratorProvider,
      Provider<UnwrappedMapKeyGenerator> unwrappedMapKeyGeneratorProvider) {
    this.messagerProvider = messagerProvider;
    this.typesProvider = typesProvider;
    this.mapKeyValidatorProvider = mapKeyValidatorProvider;
    this.annotationCreatorGeneratorProvider = annotationCreatorGeneratorProvider;
    this.unwrappedMapKeyGeneratorProvider = unwrappedMapKeyGeneratorProvider;
  }

  @Override
  public MapKeyProcessingStep get() {
    return new MapKeyProcessingStep(messagerProvider.get(), typesProvider.get(), mapKeyValidatorProvider.get(), annotationCreatorGeneratorProvider.get(), unwrappedMapKeyGeneratorProvider.get());
  }

  public static MapKeyProcessingStep_Factory create(Provider<Messager> messagerProvider,
      Provider<DaggerTypes> typesProvider, Provider<MapKeyValidator> mapKeyValidatorProvider,
      Provider<AnnotationCreatorGenerator> annotationCreatorGeneratorProvider,
      Provider<UnwrappedMapKeyGenerator> unwrappedMapKeyGeneratorProvider) {
    return new MapKeyProcessingStep_Factory(messagerProvider, typesProvider, mapKeyValidatorProvider, annotationCreatorGeneratorProvider, unwrappedMapKeyGeneratorProvider);
  }

  public static MapKeyProcessingStep newInstance(Messager messager, DaggerTypes types,
      MapKeyValidator mapKeyValidator, AnnotationCreatorGenerator annotationCreatorGenerator,
      UnwrappedMapKeyGenerator unwrappedMapKeyGenerator) {
    return new MapKeyProcessingStep(messager, types, mapKeyValidator, annotationCreatorGenerator, unwrappedMapKeyGenerator);
  }
}

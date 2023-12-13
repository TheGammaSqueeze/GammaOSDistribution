package dagger.internal.codegen;

import dagger.internal.Factory;
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
public final class AssistedInjectProcessingStep_Factory implements Factory<AssistedInjectProcessingStep> {
  private final Provider<DaggerTypes> typesProvider;

  private final Provider<Messager> messagerProvider;

  public AssistedInjectProcessingStep_Factory(Provider<DaggerTypes> typesProvider,
      Provider<Messager> messagerProvider) {
    this.typesProvider = typesProvider;
    this.messagerProvider = messagerProvider;
  }

  @Override
  public AssistedInjectProcessingStep get() {
    return new AssistedInjectProcessingStep(typesProvider.get(), messagerProvider.get());
  }

  public static AssistedInjectProcessingStep_Factory create(Provider<DaggerTypes> typesProvider,
      Provider<Messager> messagerProvider) {
    return new AssistedInjectProcessingStep_Factory(typesProvider, messagerProvider);
  }

  public static AssistedInjectProcessingStep newInstance(DaggerTypes types, Messager messager) {
    return new AssistedInjectProcessingStep(types, messager);
  }
}

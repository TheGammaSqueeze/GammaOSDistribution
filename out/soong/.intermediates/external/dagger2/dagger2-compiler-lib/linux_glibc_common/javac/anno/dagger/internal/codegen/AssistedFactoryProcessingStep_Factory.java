package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.BindingFactory;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import javax.annotation.Generated;
import javax.annotation.processing.Filer;
import javax.annotation.processing.Messager;
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
public final class AssistedFactoryProcessingStep_Factory implements Factory<AssistedFactoryProcessingStep> {
  private final Provider<Messager> messagerProvider;

  private final Provider<Filer> filerProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<BindingFactory> bindingFactoryProvider;

  public AssistedFactoryProcessingStep_Factory(Provider<Messager> messagerProvider,
      Provider<Filer> filerProvider, Provider<SourceVersion> sourceVersionProvider,
      Provider<DaggerElements> elementsProvider, Provider<DaggerTypes> typesProvider,
      Provider<BindingFactory> bindingFactoryProvider) {
    this.messagerProvider = messagerProvider;
    this.filerProvider = filerProvider;
    this.sourceVersionProvider = sourceVersionProvider;
    this.elementsProvider = elementsProvider;
    this.typesProvider = typesProvider;
    this.bindingFactoryProvider = bindingFactoryProvider;
  }

  @Override
  public AssistedFactoryProcessingStep get() {
    return new AssistedFactoryProcessingStep(messagerProvider.get(), filerProvider.get(), sourceVersionProvider.get(), elementsProvider.get(), typesProvider.get(), bindingFactoryProvider.get());
  }

  public static AssistedFactoryProcessingStep_Factory create(Provider<Messager> messagerProvider,
      Provider<Filer> filerProvider, Provider<SourceVersion> sourceVersionProvider,
      Provider<DaggerElements> elementsProvider, Provider<DaggerTypes> typesProvider,
      Provider<BindingFactory> bindingFactoryProvider) {
    return new AssistedFactoryProcessingStep_Factory(messagerProvider, filerProvider, sourceVersionProvider, elementsProvider, typesProvider, bindingFactoryProvider);
  }

  public static AssistedFactoryProcessingStep newInstance(Messager messager, Filer filer,
      SourceVersion sourceVersion, DaggerElements elements, DaggerTypes types,
      BindingFactory bindingFactory) {
    return new AssistedFactoryProcessingStep(messager, filer, sourceVersion, elements, types, bindingFactory);
  }
}

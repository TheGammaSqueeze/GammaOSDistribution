package dagger.internal.codegen.validation;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.BindingFactory;
import dagger.internal.codegen.binding.KeyFactory;
import dagger.internal.codegen.compileroption.CompilerOptions;
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
public final class InjectBindingRegistryImpl_Factory implements Factory<InjectBindingRegistryImpl> {
  private final Provider<DaggerElements> elementsProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<Messager> messagerProvider;

  private final Provider<InjectValidator> injectValidatorProvider;

  private final Provider<KeyFactory> keyFactoryProvider;

  private final Provider<BindingFactory> bindingFactoryProvider;

  private final Provider<CompilerOptions> compilerOptionsProvider;

  public InjectBindingRegistryImpl_Factory(Provider<DaggerElements> elementsProvider,
      Provider<DaggerTypes> typesProvider, Provider<Messager> messagerProvider,
      Provider<InjectValidator> injectValidatorProvider, Provider<KeyFactory> keyFactoryProvider,
      Provider<BindingFactory> bindingFactoryProvider,
      Provider<CompilerOptions> compilerOptionsProvider) {
    this.elementsProvider = elementsProvider;
    this.typesProvider = typesProvider;
    this.messagerProvider = messagerProvider;
    this.injectValidatorProvider = injectValidatorProvider;
    this.keyFactoryProvider = keyFactoryProvider;
    this.bindingFactoryProvider = bindingFactoryProvider;
    this.compilerOptionsProvider = compilerOptionsProvider;
  }

  @Override
  public InjectBindingRegistryImpl get() {
    return new InjectBindingRegistryImpl(elementsProvider.get(), typesProvider.get(), messagerProvider.get(), injectValidatorProvider.get(), keyFactoryProvider.get(), bindingFactoryProvider.get(), compilerOptionsProvider.get());
  }

  public static InjectBindingRegistryImpl_Factory create(Provider<DaggerElements> elementsProvider,
      Provider<DaggerTypes> typesProvider, Provider<Messager> messagerProvider,
      Provider<InjectValidator> injectValidatorProvider, Provider<KeyFactory> keyFactoryProvider,
      Provider<BindingFactory> bindingFactoryProvider,
      Provider<CompilerOptions> compilerOptionsProvider) {
    return new InjectBindingRegistryImpl_Factory(elementsProvider, typesProvider, messagerProvider, injectValidatorProvider, keyFactoryProvider, bindingFactoryProvider, compilerOptionsProvider);
  }

  public static InjectBindingRegistryImpl newInstance(DaggerElements elements, DaggerTypes types,
      Messager messager, InjectValidator injectValidator, KeyFactory keyFactory,
      BindingFactory bindingFactory, CompilerOptions compilerOptions) {
    return new InjectBindingRegistryImpl(elements, types, messager, injectValidator, keyFactory, bindingFactory, compilerOptions);
  }
}

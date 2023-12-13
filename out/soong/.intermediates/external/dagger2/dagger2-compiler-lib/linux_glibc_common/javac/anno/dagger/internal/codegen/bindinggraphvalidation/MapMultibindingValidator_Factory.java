package dagger.internal.codegen.bindinggraphvalidation;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.BindingDeclarationFormatter;
import dagger.internal.codegen.binding.KeyFactory;
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
public final class MapMultibindingValidator_Factory implements Factory<MapMultibindingValidator> {
  private final Provider<BindingDeclarationFormatter> bindingDeclarationFormatterProvider;

  private final Provider<KeyFactory> keyFactoryProvider;

  public MapMultibindingValidator_Factory(
      Provider<BindingDeclarationFormatter> bindingDeclarationFormatterProvider,
      Provider<KeyFactory> keyFactoryProvider) {
    this.bindingDeclarationFormatterProvider = bindingDeclarationFormatterProvider;
    this.keyFactoryProvider = keyFactoryProvider;
  }

  @Override
  public MapMultibindingValidator get() {
    return new MapMultibindingValidator(bindingDeclarationFormatterProvider.get(), keyFactoryProvider.get());
  }

  public static MapMultibindingValidator_Factory create(
      Provider<BindingDeclarationFormatter> bindingDeclarationFormatterProvider,
      Provider<KeyFactory> keyFactoryProvider) {
    return new MapMultibindingValidator_Factory(bindingDeclarationFormatterProvider, keyFactoryProvider);
  }

  public static MapMultibindingValidator newInstance(
      BindingDeclarationFormatter bindingDeclarationFormatter, KeyFactory keyFactory) {
    return new MapMultibindingValidator(bindingDeclarationFormatter, keyFactory);
  }
}

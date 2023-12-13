package dagger.internal.codegen.binding;

import dagger.internal.Factory;
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
public final class BindingGraphConverter_Factory implements Factory<BindingGraphConverter> {
  private final Provider<BindingDeclarationFormatter> bindingDeclarationFormatterProvider;

  public BindingGraphConverter_Factory(
      Provider<BindingDeclarationFormatter> bindingDeclarationFormatterProvider) {
    this.bindingDeclarationFormatterProvider = bindingDeclarationFormatterProvider;
  }

  @Override
  public BindingGraphConverter get() {
    return new BindingGraphConverter(bindingDeclarationFormatterProvider.get());
  }

  public static BindingGraphConverter_Factory create(
      Provider<BindingDeclarationFormatter> bindingDeclarationFormatterProvider) {
    return new BindingGraphConverter_Factory(bindingDeclarationFormatterProvider);
  }

  public static BindingGraphConverter newInstance(
      BindingDeclarationFormatter bindingDeclarationFormatter) {
    return new BindingGraphConverter(bindingDeclarationFormatter);
  }
}

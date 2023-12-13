package dagger.internal.codegen.binding;

import dagger.internal.Factory;
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
public final class MethodSignatureFormatter_Factory implements Factory<MethodSignatureFormatter> {
  private final Provider<DaggerTypes> typesProvider;

  private final Provider<InjectionAnnotations> injectionAnnotationsProvider;

  public MethodSignatureFormatter_Factory(Provider<DaggerTypes> typesProvider,
      Provider<InjectionAnnotations> injectionAnnotationsProvider) {
    this.typesProvider = typesProvider;
    this.injectionAnnotationsProvider = injectionAnnotationsProvider;
  }

  @Override
  public MethodSignatureFormatter get() {
    return new MethodSignatureFormatter(typesProvider.get(), injectionAnnotationsProvider.get());
  }

  public static MethodSignatureFormatter_Factory create(Provider<DaggerTypes> typesProvider,
      Provider<InjectionAnnotations> injectionAnnotationsProvider) {
    return new MethodSignatureFormatter_Factory(typesProvider, injectionAnnotationsProvider);
  }

  public static MethodSignatureFormatter newInstance(DaggerTypes types,
      InjectionAnnotations injectionAnnotations) {
    return new MethodSignatureFormatter(types, injectionAnnotations);
  }
}

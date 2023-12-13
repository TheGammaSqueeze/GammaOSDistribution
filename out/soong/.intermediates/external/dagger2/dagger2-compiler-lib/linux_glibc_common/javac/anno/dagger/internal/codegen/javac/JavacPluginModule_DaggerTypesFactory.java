package dagger.internal.codegen.javac;

import com.sun.tools.javac.util.Context;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class JavacPluginModule_DaggerTypesFactory implements Factory<DaggerTypes> {
  private final Provider<Context> javaContextProvider;

  private final Provider<DaggerElements> elementsProvider;

  public JavacPluginModule_DaggerTypesFactory(Provider<Context> javaContextProvider,
      Provider<DaggerElements> elementsProvider) {
    this.javaContextProvider = javaContextProvider;
    this.elementsProvider = elementsProvider;
  }

  @Override
  public DaggerTypes get() {
    return daggerTypes(javaContextProvider.get(), elementsProvider.get());
  }

  public static JavacPluginModule_DaggerTypesFactory create(Provider<Context> javaContextProvider,
      Provider<DaggerElements> elementsProvider) {
    return new JavacPluginModule_DaggerTypesFactory(javaContextProvider, elementsProvider);
  }

  public static DaggerTypes daggerTypes(Context javaContext, DaggerElements elements) {
    return Preconditions.checkNotNull(JavacPluginModule.daggerTypes(javaContext, elements), "Cannot return null from a non-@Nullable @Provides method");
  }
}

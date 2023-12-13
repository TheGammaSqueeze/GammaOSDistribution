package dagger.internal.codegen.javac;

import com.sun.tools.javac.util.Context;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import dagger.internal.codegen.langmodel.DaggerElements;
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
public final class JavacPluginModule_DaggerElementsFactory implements Factory<DaggerElements> {
  private final Provider<Context> javaContextProvider;

  public JavacPluginModule_DaggerElementsFactory(Provider<Context> javaContextProvider) {
    this.javaContextProvider = javaContextProvider;
  }

  @Override
  public DaggerElements get() {
    return daggerElements(javaContextProvider.get());
  }

  public static JavacPluginModule_DaggerElementsFactory create(
      Provider<Context> javaContextProvider) {
    return new JavacPluginModule_DaggerElementsFactory(javaContextProvider);
  }

  public static DaggerElements daggerElements(Context javaContext) {
    return Preconditions.checkNotNull(JavacPluginModule.daggerElements(javaContext), "Cannot return null from a non-@Nullable @Provides method");
  }
}

package dagger.internal.codegen.javac;

import dagger.internal.Factory;
import javax.annotation.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class JavacPluginModule_NullMessager_Factory implements Factory<JavacPluginModule.NullMessager> {
  private static final JavacPluginModule_NullMessager_Factory INSTANCE = new JavacPluginModule_NullMessager_Factory();

  @Override
  public JavacPluginModule.NullMessager get() {
    return new JavacPluginModule.NullMessager();
  }

  public static JavacPluginModule_NullMessager_Factory create() {
    return INSTANCE;
  }

  public static JavacPluginModule.NullMessager newInstance() {
    return new JavacPluginModule.NullMessager();
  }
}

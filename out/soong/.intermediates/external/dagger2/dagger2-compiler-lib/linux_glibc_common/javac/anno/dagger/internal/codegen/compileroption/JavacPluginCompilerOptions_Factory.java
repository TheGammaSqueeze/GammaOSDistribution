package dagger.internal.codegen.compileroption;

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
public final class JavacPluginCompilerOptions_Factory implements Factory<JavacPluginCompilerOptions> {
  private static final JavacPluginCompilerOptions_Factory INSTANCE = new JavacPluginCompilerOptions_Factory();

  @Override
  public JavacPluginCompilerOptions get() {
    return new JavacPluginCompilerOptions();
  }

  public static JavacPluginCompilerOptions_Factory create() {
    return INSTANCE;
  }

  public static JavacPluginCompilerOptions newInstance() {
    return new JavacPluginCompilerOptions();
  }
}

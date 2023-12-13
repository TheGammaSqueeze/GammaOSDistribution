package dagger.internal.codegen.base;

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
public final class ElementFormatter_Factory implements Factory<ElementFormatter> {
  private static final ElementFormatter_Factory INSTANCE = new ElementFormatter_Factory();

  @Override
  public ElementFormatter get() {
    return new ElementFormatter();
  }

  public static ElementFormatter_Factory create() {
    return INSTANCE;
  }

  public static ElementFormatter newInstance() {
    return new ElementFormatter();
  }
}

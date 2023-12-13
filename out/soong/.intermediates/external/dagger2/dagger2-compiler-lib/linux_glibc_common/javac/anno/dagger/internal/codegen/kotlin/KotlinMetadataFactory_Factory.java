package dagger.internal.codegen.kotlin;

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
public final class KotlinMetadataFactory_Factory implements Factory<KotlinMetadataFactory> {
  private static final KotlinMetadataFactory_Factory INSTANCE = new KotlinMetadataFactory_Factory();

  @Override
  public KotlinMetadataFactory get() {
    return new KotlinMetadataFactory();
  }

  public static KotlinMetadataFactory_Factory create() {
    return INSTANCE;
  }

  public static KotlinMetadataFactory newInstance() {
    return new KotlinMetadataFactory();
  }
}

package dagger.internal.codegen.kotlin;

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
public final class KotlinMetadataUtil_Factory implements Factory<KotlinMetadataUtil> {
  private final Provider<KotlinMetadataFactory> metadataFactoryProvider;

  public KotlinMetadataUtil_Factory(Provider<KotlinMetadataFactory> metadataFactoryProvider) {
    this.metadataFactoryProvider = metadataFactoryProvider;
  }

  @Override
  public KotlinMetadataUtil get() {
    return new KotlinMetadataUtil(metadataFactoryProvider.get());
  }

  public static KotlinMetadataUtil_Factory create(
      Provider<KotlinMetadataFactory> metadataFactoryProvider) {
    return new KotlinMetadataUtil_Factory(metadataFactoryProvider);
  }

  public static KotlinMetadataUtil newInstance(KotlinMetadataFactory metadataFactory) {
    return new KotlinMetadataUtil(metadataFactory);
  }
}

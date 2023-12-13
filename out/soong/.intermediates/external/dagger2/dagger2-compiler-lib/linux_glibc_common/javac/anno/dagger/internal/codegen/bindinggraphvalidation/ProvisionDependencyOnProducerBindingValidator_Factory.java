package dagger.internal.codegen.bindinggraphvalidation;

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
public final class ProvisionDependencyOnProducerBindingValidator_Factory implements Factory<ProvisionDependencyOnProducerBindingValidator> {
  private static final ProvisionDependencyOnProducerBindingValidator_Factory INSTANCE = new ProvisionDependencyOnProducerBindingValidator_Factory();

  @Override
  public ProvisionDependencyOnProducerBindingValidator get() {
    return new ProvisionDependencyOnProducerBindingValidator();
  }

  public static ProvisionDependencyOnProducerBindingValidator_Factory create() {
    return INSTANCE;
  }

  public static ProvisionDependencyOnProducerBindingValidator newInstance() {
    return new ProvisionDependencyOnProducerBindingValidator();
  }
}

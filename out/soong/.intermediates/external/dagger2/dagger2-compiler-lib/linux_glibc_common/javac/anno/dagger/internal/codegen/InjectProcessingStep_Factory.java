package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.InjectBindingRegistry;
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
public final class InjectProcessingStep_Factory implements Factory<InjectProcessingStep> {
  private final Provider<InjectBindingRegistry> injectBindingRegistryProvider;

  public InjectProcessingStep_Factory(
      Provider<InjectBindingRegistry> injectBindingRegistryProvider) {
    this.injectBindingRegistryProvider = injectBindingRegistryProvider;
  }

  @Override
  public InjectProcessingStep get() {
    return new InjectProcessingStep(injectBindingRegistryProvider.get());
  }

  public static InjectProcessingStep_Factory create(
      Provider<InjectBindingRegistry> injectBindingRegistryProvider) {
    return new InjectProcessingStep_Factory(injectBindingRegistryProvider);
  }

  public static InjectProcessingStep newInstance(InjectBindingRegistry injectBindingRegistry) {
    return new InjectProcessingStep(injectBindingRegistry);
  }
}

package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.codegen.base.SourceFileGenerator;
import dagger.internal.codegen.binding.ComponentDescriptor;
import dagger.internal.codegen.binding.ComponentDescriptorFactory;
import dagger.internal.codegen.validation.ComponentCreatorValidator;
import dagger.internal.codegen.validation.ComponentValidator;
import javax.annotation.Generated;
import javax.annotation.processing.Messager;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class ComponentHjarProcessingStep_Factory implements Factory<ComponentHjarProcessingStep> {
  private final Provider<Messager> messagerProvider;

  private final Provider<ComponentValidator> componentValidatorProvider;

  private final Provider<ComponentCreatorValidator> creatorValidatorProvider;

  private final Provider<ComponentDescriptorFactory> componentDescriptorFactoryProvider;

  private final Provider<SourceFileGenerator<ComponentDescriptor>> componentGeneratorProvider;

  public ComponentHjarProcessingStep_Factory(Provider<Messager> messagerProvider,
      Provider<ComponentValidator> componentValidatorProvider,
      Provider<ComponentCreatorValidator> creatorValidatorProvider,
      Provider<ComponentDescriptorFactory> componentDescriptorFactoryProvider,
      Provider<SourceFileGenerator<ComponentDescriptor>> componentGeneratorProvider) {
    this.messagerProvider = messagerProvider;
    this.componentValidatorProvider = componentValidatorProvider;
    this.creatorValidatorProvider = creatorValidatorProvider;
    this.componentDescriptorFactoryProvider = componentDescriptorFactoryProvider;
    this.componentGeneratorProvider = componentGeneratorProvider;
  }

  @Override
  public ComponentHjarProcessingStep get() {
    return new ComponentHjarProcessingStep(messagerProvider.get(), componentValidatorProvider.get(), creatorValidatorProvider.get(), componentDescriptorFactoryProvider.get(), componentGeneratorProvider.get());
  }

  public static ComponentHjarProcessingStep_Factory create(Provider<Messager> messagerProvider,
      Provider<ComponentValidator> componentValidatorProvider,
      Provider<ComponentCreatorValidator> creatorValidatorProvider,
      Provider<ComponentDescriptorFactory> componentDescriptorFactoryProvider,
      Provider<SourceFileGenerator<ComponentDescriptor>> componentGeneratorProvider) {
    return new ComponentHjarProcessingStep_Factory(messagerProvider, componentValidatorProvider, creatorValidatorProvider, componentDescriptorFactoryProvider, componentGeneratorProvider);
  }

  public static ComponentHjarProcessingStep newInstance(Messager messager,
      ComponentValidator componentValidator, ComponentCreatorValidator creatorValidator,
      ComponentDescriptorFactory componentDescriptorFactory,
      SourceFileGenerator<ComponentDescriptor> componentGenerator) {
    return new ComponentHjarProcessingStep(messager, componentValidator, creatorValidator, componentDescriptorFactory, componentGenerator);
  }
}

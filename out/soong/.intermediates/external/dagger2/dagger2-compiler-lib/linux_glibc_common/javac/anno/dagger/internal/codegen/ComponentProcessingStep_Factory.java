package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.codegen.base.SourceFileGenerator;
import dagger.internal.codegen.binding.BindingGraph;
import dagger.internal.codegen.binding.BindingGraphFactory;
import dagger.internal.codegen.binding.ComponentDescriptorFactory;
import dagger.internal.codegen.validation.BindingGraphValidator;
import dagger.internal.codegen.validation.ComponentCreatorValidator;
import dagger.internal.codegen.validation.ComponentDescriptorValidator;
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
public final class ComponentProcessingStep_Factory implements Factory<ComponentProcessingStep> {
  private final Provider<Messager> messagerProvider;

  private final Provider<ComponentValidator> componentValidatorProvider;

  private final Provider<ComponentCreatorValidator> creatorValidatorProvider;

  private final Provider<ComponentDescriptorValidator> componentDescriptorValidatorProvider;

  private final Provider<ComponentDescriptorFactory> componentDescriptorFactoryProvider;

  private final Provider<BindingGraphFactory> bindingGraphFactoryProvider;

  private final Provider<SourceFileGenerator<BindingGraph>> componentGeneratorProvider;

  private final Provider<BindingGraphValidator> bindingGraphValidatorProvider;

  public ComponentProcessingStep_Factory(Provider<Messager> messagerProvider,
      Provider<ComponentValidator> componentValidatorProvider,
      Provider<ComponentCreatorValidator> creatorValidatorProvider,
      Provider<ComponentDescriptorValidator> componentDescriptorValidatorProvider,
      Provider<ComponentDescriptorFactory> componentDescriptorFactoryProvider,
      Provider<BindingGraphFactory> bindingGraphFactoryProvider,
      Provider<SourceFileGenerator<BindingGraph>> componentGeneratorProvider,
      Provider<BindingGraphValidator> bindingGraphValidatorProvider) {
    this.messagerProvider = messagerProvider;
    this.componentValidatorProvider = componentValidatorProvider;
    this.creatorValidatorProvider = creatorValidatorProvider;
    this.componentDescriptorValidatorProvider = componentDescriptorValidatorProvider;
    this.componentDescriptorFactoryProvider = componentDescriptorFactoryProvider;
    this.bindingGraphFactoryProvider = bindingGraphFactoryProvider;
    this.componentGeneratorProvider = componentGeneratorProvider;
    this.bindingGraphValidatorProvider = bindingGraphValidatorProvider;
  }

  @Override
  public ComponentProcessingStep get() {
    return new ComponentProcessingStep(messagerProvider.get(), componentValidatorProvider.get(), creatorValidatorProvider.get(), componentDescriptorValidatorProvider.get(), componentDescriptorFactoryProvider.get(), bindingGraphFactoryProvider.get(), componentGeneratorProvider.get(), bindingGraphValidatorProvider.get());
  }

  public static ComponentProcessingStep_Factory create(Provider<Messager> messagerProvider,
      Provider<ComponentValidator> componentValidatorProvider,
      Provider<ComponentCreatorValidator> creatorValidatorProvider,
      Provider<ComponentDescriptorValidator> componentDescriptorValidatorProvider,
      Provider<ComponentDescriptorFactory> componentDescriptorFactoryProvider,
      Provider<BindingGraphFactory> bindingGraphFactoryProvider,
      Provider<SourceFileGenerator<BindingGraph>> componentGeneratorProvider,
      Provider<BindingGraphValidator> bindingGraphValidatorProvider) {
    return new ComponentProcessingStep_Factory(messagerProvider, componentValidatorProvider, creatorValidatorProvider, componentDescriptorValidatorProvider, componentDescriptorFactoryProvider, bindingGraphFactoryProvider, componentGeneratorProvider, bindingGraphValidatorProvider);
  }

  public static ComponentProcessingStep newInstance(Messager messager,
      ComponentValidator componentValidator, ComponentCreatorValidator creatorValidator,
      ComponentDescriptorValidator componentDescriptorValidator,
      ComponentDescriptorFactory componentDescriptorFactory,
      BindingGraphFactory bindingGraphFactory, SourceFileGenerator<BindingGraph> componentGenerator,
      BindingGraphValidator bindingGraphValidator) {
    return new ComponentProcessingStep(messager, componentValidator, creatorValidator, componentDescriptorValidator, componentDescriptorFactory, bindingGraphFactory, componentGenerator, bindingGraphValidator);
  }
}

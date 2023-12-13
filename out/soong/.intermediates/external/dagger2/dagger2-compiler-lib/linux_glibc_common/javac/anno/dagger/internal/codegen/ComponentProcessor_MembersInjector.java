package dagger.internal.codegen;

import com.google.auto.common.BasicAnnotationProcessor;
import com.google.common.collect.ImmutableList;
import dagger.MembersInjector;
import dagger.internal.codegen.base.ClearableCache;
import dagger.internal.codegen.base.SourceFileGenerator;
import dagger.internal.codegen.binding.InjectBindingRegistry;
import dagger.internal.codegen.binding.MembersInjectionBinding;
import dagger.internal.codegen.binding.ProvisionBinding;
import dagger.internal.codegen.validation.BindingGraphPlugins;
import java.util.Set;
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
public final class ComponentProcessor_MembersInjector implements MembersInjector<ComponentProcessor> {
  private final Provider<InjectBindingRegistry> injectBindingRegistryProvider;

  private final Provider<SourceFileGenerator<ProvisionBinding>> factoryGeneratorProvider;

  private final Provider<SourceFileGenerator<MembersInjectionBinding>> membersInjectorGeneratorProvider;

  private final Provider<ImmutableList<BasicAnnotationProcessor.ProcessingStep>> processingStepsProvider;

  private final Provider<BindingGraphPlugins> bindingGraphPluginsProvider;

  private final Provider<Set<ClearableCache>> clearableCachesProvider;

  public ComponentProcessor_MembersInjector(
      Provider<InjectBindingRegistry> injectBindingRegistryProvider,
      Provider<SourceFileGenerator<ProvisionBinding>> factoryGeneratorProvider,
      Provider<SourceFileGenerator<MembersInjectionBinding>> membersInjectorGeneratorProvider,
      Provider<ImmutableList<BasicAnnotationProcessor.ProcessingStep>> processingStepsProvider,
      Provider<BindingGraphPlugins> bindingGraphPluginsProvider,
      Provider<Set<ClearableCache>> clearableCachesProvider) {
    this.injectBindingRegistryProvider = injectBindingRegistryProvider;
    this.factoryGeneratorProvider = factoryGeneratorProvider;
    this.membersInjectorGeneratorProvider = membersInjectorGeneratorProvider;
    this.processingStepsProvider = processingStepsProvider;
    this.bindingGraphPluginsProvider = bindingGraphPluginsProvider;
    this.clearableCachesProvider = clearableCachesProvider;
  }

  public static MembersInjector<ComponentProcessor> create(
      Provider<InjectBindingRegistry> injectBindingRegistryProvider,
      Provider<SourceFileGenerator<ProvisionBinding>> factoryGeneratorProvider,
      Provider<SourceFileGenerator<MembersInjectionBinding>> membersInjectorGeneratorProvider,
      Provider<ImmutableList<BasicAnnotationProcessor.ProcessingStep>> processingStepsProvider,
      Provider<BindingGraphPlugins> bindingGraphPluginsProvider,
      Provider<Set<ClearableCache>> clearableCachesProvider) {
    return new ComponentProcessor_MembersInjector(injectBindingRegistryProvider, factoryGeneratorProvider, membersInjectorGeneratorProvider, processingStepsProvider, bindingGraphPluginsProvider, clearableCachesProvider);
  }

  @Override
  public void injectMembers(ComponentProcessor instance) {
    injectInjectBindingRegistry(instance, injectBindingRegistryProvider.get());
    injectFactoryGenerator(instance, factoryGeneratorProvider.get());
    injectMembersInjectorGenerator(instance, membersInjectorGeneratorProvider.get());
    injectProcessingSteps(instance, processingStepsProvider.get());
    injectBindingGraphPlugins(instance, bindingGraphPluginsProvider.get());
    injectClearableCaches(instance, clearableCachesProvider.get());
  }

  public static void injectInjectBindingRegistry(ComponentProcessor instance,
      InjectBindingRegistry injectBindingRegistry) {
    instance.injectBindingRegistry = injectBindingRegistry;
  }

  public static void injectFactoryGenerator(ComponentProcessor instance,
      SourceFileGenerator<ProvisionBinding> factoryGenerator) {
    instance.factoryGenerator = factoryGenerator;
  }

  public static void injectMembersInjectorGenerator(ComponentProcessor instance,
      SourceFileGenerator<MembersInjectionBinding> membersInjectorGenerator) {
    instance.membersInjectorGenerator = membersInjectorGenerator;
  }

  public static void injectProcessingSteps(ComponentProcessor instance,
      ImmutableList<BasicAnnotationProcessor.ProcessingStep> processingSteps) {
    instance.processingSteps = processingSteps;
  }

  public static void injectBindingGraphPlugins(ComponentProcessor instance,
      BindingGraphPlugins bindingGraphPlugins) {
    instance.bindingGraphPlugins = bindingGraphPlugins;
  }

  public static void injectClearableCaches(ComponentProcessor instance,
      Set<ClearableCache> clearableCaches) {
    instance.clearableCaches = clearableCaches;
  }
}

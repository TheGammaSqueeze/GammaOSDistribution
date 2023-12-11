package dagger.internal.codegen;

import com.google.auto.common.BasicAnnotationProcessor;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.errorprone.annotations.CanIgnoreReturnValue;
import dagger.internal.DoubleCheck;
import dagger.internal.InstanceFactory;
import dagger.internal.Preconditions;
import dagger.internal.SetBuilder;
import dagger.internal.SetFactory;
import dagger.internal.SingleCheck;
import dagger.internal.codegen.base.ClearableCache;
import dagger.internal.codegen.base.ElementFormatter_Factory;
import dagger.internal.codegen.base.SourceFileGenerator;
import dagger.internal.codegen.binding.BindingDeclarationFormatter;
import dagger.internal.codegen.binding.BindingDeclarationFormatter_Factory;
import dagger.internal.codegen.binding.BindingFactory;
import dagger.internal.codegen.binding.BindingFactory_Factory;
import dagger.internal.codegen.binding.BindingGraph;
import dagger.internal.codegen.binding.BindingGraphConverter_Factory;
import dagger.internal.codegen.binding.BindingGraphFactory;
import dagger.internal.codegen.binding.BindingGraphFactory_Factory;
import dagger.internal.codegen.binding.BindsTypeChecker;
import dagger.internal.codegen.binding.BindsTypeChecker_Factory;
import dagger.internal.codegen.binding.ComponentDescriptor;
import dagger.internal.codegen.binding.ComponentDescriptorFactory;
import dagger.internal.codegen.binding.ComponentDescriptorFactory_Factory;
import dagger.internal.codegen.binding.DelegateDeclaration;
import dagger.internal.codegen.binding.DelegateDeclaration_Factory_Factory;
import dagger.internal.codegen.binding.DependencyRequestFactory;
import dagger.internal.codegen.binding.DependencyRequestFactory_Factory;
import dagger.internal.codegen.binding.DependencyRequestFormatter;
import dagger.internal.codegen.binding.DependencyRequestFormatter_Factory;
import dagger.internal.codegen.binding.InjectBindingRegistry;
import dagger.internal.codegen.binding.InjectionAnnotations;
import dagger.internal.codegen.binding.InjectionAnnotations_Factory;
import dagger.internal.codegen.binding.InjectionSiteFactory_Factory;
import dagger.internal.codegen.binding.KeyFactory;
import dagger.internal.codegen.binding.KeyFactory_Factory;
import dagger.internal.codegen.binding.MembersInjectionBinding;
import dagger.internal.codegen.binding.MethodSignatureFormatter;
import dagger.internal.codegen.binding.MethodSignatureFormatter_Factory;
import dagger.internal.codegen.binding.ModuleDescriptor;
import dagger.internal.codegen.binding.ModuleDescriptor_Factory_Factory;
import dagger.internal.codegen.binding.MultibindingDeclaration;
import dagger.internal.codegen.binding.MultibindingDeclaration_Factory_Factory;
import dagger.internal.codegen.binding.OptionalBindingDeclaration_Factory_Factory;
import dagger.internal.codegen.binding.ProductionBinding;
import dagger.internal.codegen.binding.ProvisionBinding;
import dagger.internal.codegen.binding.SubcomponentDeclaration;
import dagger.internal.codegen.binding.SubcomponentDeclaration_Factory_Factory;
import dagger.internal.codegen.bindinggraphvalidation.BindingGraphValidationModule_ProvidePluginsFactory;
import dagger.internal.codegen.bindinggraphvalidation.DependencyCycleValidator_Factory;
import dagger.internal.codegen.bindinggraphvalidation.DependsOnProductionExecutorValidator_Factory;
import dagger.internal.codegen.bindinggraphvalidation.DuplicateBindingsValidator_Factory;
import dagger.internal.codegen.bindinggraphvalidation.IncompatiblyScopedBindingsValidator_Factory;
import dagger.internal.codegen.bindinggraphvalidation.InjectBindingValidator_Factory;
import dagger.internal.codegen.bindinggraphvalidation.MapMultibindingValidator_Factory;
import dagger.internal.codegen.bindinggraphvalidation.MissingBindingValidator_Factory;
import dagger.internal.codegen.bindinggraphvalidation.NullableBindingValidator_Factory;
import dagger.internal.codegen.bindinggraphvalidation.ProvisionDependencyOnProducerBindingValidator_Factory;
import dagger.internal.codegen.bindinggraphvalidation.SubcomponentFactoryMethodValidator_Factory;
import dagger.internal.codegen.compileroption.CompilerOptions;
import dagger.internal.codegen.compileroption.ProcessingEnvironmentCompilerOptions;
import dagger.internal.codegen.compileroption.ProcessingEnvironmentCompilerOptions_Factory;
import dagger.internal.codegen.componentgenerator.ComponentCreatorImplementationFactory_Factory;
import dagger.internal.codegen.componentgenerator.ComponentGenerator_Factory;
import dagger.internal.codegen.componentgenerator.ComponentHjarGenerator_Factory;
import dagger.internal.codegen.componentgenerator.ComponentImplementationBuilder;
import dagger.internal.codegen.componentgenerator.ComponentImplementationBuilder_Factory;
import dagger.internal.codegen.componentgenerator.ComponentImplementationFactory_Factory;
import dagger.internal.codegen.componentgenerator.CurrentImplementationSubcomponent;
import dagger.internal.codegen.componentgenerator.TopLevelImplementationComponent;
import dagger.internal.codegen.kotlin.KotlinMetadataFactory;
import dagger.internal.codegen.kotlin.KotlinMetadataFactory_Factory;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil_Factory;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.internal.codegen.langmodel.DaggerTypes_Factory;
import dagger.internal.codegen.validation.AnyBindingMethodValidator;
import dagger.internal.codegen.validation.AnyBindingMethodValidator_Factory;
import dagger.internal.codegen.validation.BindingGraphPlugins;
import dagger.internal.codegen.validation.BindingGraphPlugins_Factory;
import dagger.internal.codegen.validation.BindingGraphValidator;
import dagger.internal.codegen.validation.BindingGraphValidator_Factory;
import dagger.internal.codegen.validation.BindingMethodProcessingStep;
import dagger.internal.codegen.validation.BindingMethodProcessingStep_Factory;
import dagger.internal.codegen.validation.BindingMethodValidatorsModule_IndexValidatorsFactory;
import dagger.internal.codegen.validation.BindsInstanceMethodValidator_Factory;
import dagger.internal.codegen.validation.BindsInstanceParameterValidator_Factory;
import dagger.internal.codegen.validation.BindsInstanceProcessingStep;
import dagger.internal.codegen.validation.BindsInstanceProcessingStep_Factory;
import dagger.internal.codegen.validation.BindsMethodValidator_Factory;
import dagger.internal.codegen.validation.BindsOptionalOfMethodValidator_Factory;
import dagger.internal.codegen.validation.ComponentCreatorValidator;
import dagger.internal.codegen.validation.ComponentCreatorValidator_Factory;
import dagger.internal.codegen.validation.ComponentDescriptorValidator;
import dagger.internal.codegen.validation.ComponentDescriptorValidator_Factory;
import dagger.internal.codegen.validation.ComponentHierarchyValidator_Factory;
import dagger.internal.codegen.validation.ComponentValidator;
import dagger.internal.codegen.validation.ComponentValidator_Factory;
import dagger.internal.codegen.validation.CompositeBindingGraphPlugin;
import dagger.internal.codegen.validation.CompositeBindingGraphPlugin_Factory_Factory;
import dagger.internal.codegen.validation.DependencyRequestValidator_Factory;
import dagger.internal.codegen.validation.DiagnosticMessageGenerator;
import dagger.internal.codegen.validation.DiagnosticMessageGenerator_Factory_Factory;
import dagger.internal.codegen.validation.DiagnosticReporterFactory_Factory;
import dagger.internal.codegen.validation.InjectBindingRegistryImpl_Factory;
import dagger.internal.codegen.validation.InjectValidator;
import dagger.internal.codegen.validation.InjectValidator_Factory;
import dagger.internal.codegen.validation.MapKeyValidator;
import dagger.internal.codegen.validation.MapKeyValidator_Factory;
import dagger.internal.codegen.validation.MembersInjectionValidator_Factory;
import dagger.internal.codegen.validation.ModuleValidator;
import dagger.internal.codegen.validation.ModuleValidator_Factory;
import dagger.internal.codegen.validation.MonitoringModuleGenerator_Factory;
import dagger.internal.codegen.validation.MonitoringModuleProcessingStep;
import dagger.internal.codegen.validation.MonitoringModuleProcessingStep_Factory;
import dagger.internal.codegen.validation.MultibindingAnnotationsProcessingStep;
import dagger.internal.codegen.validation.MultibindingAnnotationsProcessingStep_Factory;
import dagger.internal.codegen.validation.MultibindsMethodValidator_Factory;
import dagger.internal.codegen.validation.ProducesMethodValidator_Factory;
import dagger.internal.codegen.validation.ProvidesMethodValidator_Factory;
import dagger.internal.codegen.writing.AnnotationCreatorGenerator;
import dagger.internal.codegen.writing.AnnotationCreatorGenerator_Factory;
import dagger.internal.codegen.writing.ComponentBindingExpressions;
import dagger.internal.codegen.writing.ComponentBindingExpressions_Factory;
import dagger.internal.codegen.writing.ComponentImplementation;
import dagger.internal.codegen.writing.ComponentRequirementExpressions;
import dagger.internal.codegen.writing.ComponentRequirementExpressions_Factory;
import dagger.internal.codegen.writing.FactoryGenerator;
import dagger.internal.codegen.writing.FactoryGenerator_Factory;
import dagger.internal.codegen.writing.InaccessibleMapKeyProxyGenerator;
import dagger.internal.codegen.writing.InaccessibleMapKeyProxyGenerator_Factory;
import dagger.internal.codegen.writing.MembersInjectorGenerator;
import dagger.internal.codegen.writing.MembersInjectorGenerator_Factory;
import dagger.internal.codegen.writing.ModuleProxies;
import dagger.internal.codegen.writing.ModuleProxies_Factory;
import dagger.internal.codegen.writing.ModuleProxies_ModuleConstructorProxyGenerator_Factory;
import dagger.internal.codegen.writing.OptionalFactories_Factory;
import dagger.internal.codegen.writing.ProducerFactoryGenerator;
import dagger.internal.codegen.writing.ProducerFactoryGenerator_Factory;
import dagger.internal.codegen.writing.UnwrappedMapKeyGenerator;
import dagger.internal.codegen.writing.UnwrappedMapKeyGenerator_Factory;
import dagger.spi.BindingGraphPlugin;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import javax.annotation.Generated;
import javax.annotation.processing.Filer;
import javax.annotation.processing.Messager;
import javax.annotation.processing.ProcessingEnvironment;
import javax.inject.Provider;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.TypeElement;
import javax.lang.model.util.Types;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
final class DaggerComponentProcessor_ProcessorComponent implements ComponentProcessor.ProcessorComponent {
  private final ProcessingEnvironment processingEnv;

  private Provider<ProcessingEnvironment> processingEnvProvider;

  private Provider<DaggerElements> daggerElementsProvider;

  private Provider<Types> typesProvider;

  private Provider<DaggerTypes> daggerTypesProvider;

  private Provider<Messager> messagerProvider;

  private Provider<KotlinMetadataFactory> kotlinMetadataFactoryProvider;

  private Provider<KotlinMetadataUtil> kotlinMetadataUtilProvider;

  private Provider<InjectionAnnotations> injectionAnnotationsProvider;

  @SuppressWarnings("rawtypes")
  private Provider membersInjectionValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider dependencyRequestValidatorProvider;

  private Provider<ProcessingEnvironmentCompilerOptions> processingEnvironmentCompilerOptionsProvider;

  private Provider<CompilerOptions> bindCompilerOptionsProvider;

  private Provider<InjectValidator> injectValidatorProvider;

  private Provider<KeyFactory> keyFactoryProvider;

  private Provider<DependencyRequestFactory> dependencyRequestFactoryProvider;

  @SuppressWarnings("rawtypes")
  private Provider injectionSiteFactoryProvider;

  private Provider<BindingFactory> bindingFactoryProvider;

  @SuppressWarnings("rawtypes")
  private Provider injectBindingRegistryImplProvider;

  @SuppressWarnings("rawtypes")
  private Provider providesMethodValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider producesMethodValidatorProvider;

  private Provider<BindsTypeChecker> bindsTypeCheckerProvider;

  @SuppressWarnings("rawtypes")
  private Provider bindsMethodValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider multibindsMethodValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider bindsOptionalOfMethodValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider setOfBindingMethodValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider indexValidatorsProvider;

  private Provider<AnyBindingMethodValidator> anyBindingMethodValidatorProvider;

  private Provider<MethodSignatureFormatter> methodSignatureFormatterProvider;

  private Provider<MultibindingDeclaration.Factory> factoryProvider;

  private Provider<DelegateDeclaration.Factory> factoryProvider2;

  private Provider<SubcomponentDeclaration.Factory> factoryProvider3;

  @SuppressWarnings("rawtypes")
  private Provider factoryProvider4;

  private Provider<ModuleDescriptor.Factory> factoryProvider5;

  private Provider<ComponentDescriptorFactory> componentDescriptorFactoryProvider;

  private Provider<BindingDeclarationFormatter> bindingDeclarationFormatterProvider;

  @SuppressWarnings("rawtypes")
  private Provider bindingGraphConverterProvider;

  private Provider<BindingGraphFactory> bindingGraphFactoryProvider;

  private Provider<DependencyRequestFormatter> dependencyRequestFormatterProvider;

  private Provider<DiagnosticMessageGenerator.Factory> factoryProvider6;

  private Provider<CompositeBindingGraphPlugin.Factory> factoryProvider7;

  @SuppressWarnings("rawtypes")
  private Provider dependencyCycleValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider dependsOnProductionExecutorValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider duplicateBindingsValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider incompatiblyScopedBindingsValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider injectBindingValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider mapMultibindingValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider missingBindingValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider nullableBindingValidatorProvider;

  @SuppressWarnings("rawtypes")
  private Provider subcomponentFactoryMethodValidatorProvider;

  private Provider<ImmutableSet<BindingGraphPlugin>> providePluginsProvider;

  private Provider<Optional<ImmutableSet<BindingGraphPlugin>>> testingPluginsProvider;

  private Provider<ClassLoader> processorClassloaderProvider;

  private Provider<ImmutableSet<BindingGraphPlugin>> externalPluginsProvider;

  @SuppressWarnings("rawtypes")
  private Provider diagnosticReporterFactoryProvider;

  private Provider<BindingGraphValidator> bindingGraphValidatorProvider;

  private Provider<ModuleValidator> moduleValidatorProvider;

  private Provider<ComponentCreatorValidator> componentCreatorValidatorProvider;

  private Provider<ComponentValidator> componentValidatorProvider;

  private Provider<TopLevelImplementationComponent.Builder> topLevelImplementationComponentBuilderProvider;

  @SuppressWarnings("rawtypes")
  private Provider componentImplementationFactoryProvider;

  private Provider<ModuleProxies> moduleProxiesProvider;

  private Provider<SourceVersion> sourceVersionProvider;

  private DaggerComponentProcessor_ProcessorComponent(ProcessingEnvironment processingEnvParam,
      Optional<ImmutableSet<BindingGraphPlugin>> testingPluginsParam) {
    this.processingEnv = processingEnvParam;
    initialize(processingEnvParam, testingPluginsParam);
  }

  public static ComponentProcessor.ProcessorComponent.Factory factory() {
    return new Factory();
  }

  private Filer getFiler() {
    return ProcessingEnvironmentModule_FilerFactory.filer(bindCompilerOptionsProvider.get(), processingEnv);
  }

  private SourceVersion getSourceVersion() {
    return ProcessingEnvironmentModule_SourceVersionFactory.sourceVersion(processingEnv);
  }

  private Types getTypes() {
    return ProcessingEnvironmentModule_TypesFactory.types(processingEnv);
  }

  private DaggerElements getDaggerElements() {
    return ProcessingEnvironmentModule_DaggerElementsFactory.daggerElements(processingEnv);
  }

  private DaggerTypes getDaggerTypes() {
    return new DaggerTypes(getTypes(), getDaggerElements());
  }

  private KotlinMetadataUtil getKotlinMetadataUtil() {
    return KotlinMetadataUtil_Factory.newInstance(kotlinMetadataFactoryProvider.get());
  }

  private FactoryGenerator getFactoryGenerator() {
    return FactoryGenerator_Factory.newInstance(getFiler(), getSourceVersion(), getDaggerTypes(), getDaggerElements(), bindCompilerOptionsProvider.get(), getKotlinMetadataUtil());
  }

  private SourceFileGenerator<ProvisionBinding> getSourceFileGeneratorOfProvisionBinding() {
    return SourceFileGeneratorsModule_FactoryGeneratorFactory.factoryGenerator(getFactoryGenerator(), bindCompilerOptionsProvider.get());
  }

  private MembersInjectorGenerator getMembersInjectorGenerator() {
    return MembersInjectorGenerator_Factory.newInstance(getFiler(), getDaggerElements(), getDaggerTypes(), getSourceVersion(), getKotlinMetadataUtil());
  }

  private SourceFileGenerator<MembersInjectionBinding> getSourceFileGeneratorOfMembersInjectionBinding(
      ) {
    return SourceFileGeneratorsModule_MembersInjectorGeneratorFactory.membersInjectorGenerator(getMembersInjectorGenerator(), bindCompilerOptionsProvider.get());
  }

  private Messager getMessager() {
    return ProcessingEnvironmentModule_MessagerFactory.messager(processingEnv);
  }

  private MapKeyValidator getMapKeyValidator() {
    return MapKeyValidator_Factory.newInstance(getDaggerElements());
  }

  private AnnotationCreatorGenerator getAnnotationCreatorGenerator() {
    return AnnotationCreatorGenerator_Factory.newInstance(getFiler(), getDaggerElements(), getSourceVersion());
  }

  private UnwrappedMapKeyGenerator getUnwrappedMapKeyGenerator() {
    return UnwrappedMapKeyGenerator_Factory.newInstance(getFiler(), getDaggerElements(), getSourceVersion());
  }

  private MapKeyProcessingStep getMapKeyProcessingStep() {
    return new MapKeyProcessingStep(getMessager(), getDaggerTypes(), getMapKeyValidator(), getAnnotationCreatorGenerator(), getUnwrappedMapKeyGenerator());
  }

  private InjectProcessingStep getInjectProcessingStep() {
    return new InjectProcessingStep((InjectBindingRegistry) injectBindingRegistryImplProvider.get());
  }

  private AssistedInjectProcessingStep getAssistedInjectProcessingStep() {
    return new AssistedInjectProcessingStep(getDaggerTypes(), getMessager());
  }

  private InjectionAnnotations getInjectionAnnotations() {
    return InjectionAnnotations_Factory.newInstance(getDaggerElements(), getKotlinMetadataUtil());
  }

  private KeyFactory getKeyFactory() {
    return KeyFactory_Factory.newInstance(getDaggerTypes(), getDaggerElements(), getInjectionAnnotations());
  }

  private DependencyRequestFactory getDependencyRequestFactory() {
    return DependencyRequestFactory_Factory.newInstance(getKeyFactory(), getInjectionAnnotations());
  }

  private Object getInjectionSiteFactory() {
    return InjectionSiteFactory_Factory.newInstance(getDaggerTypes(), getDaggerElements(), getDependencyRequestFactory());
  }

  private BindingFactory getBindingFactory() {
    return BindingFactory_Factory.newInstance(getDaggerTypes(), getDaggerElements(), getKeyFactory(), getDependencyRequestFactory(), getInjectionSiteFactory(), getInjectionAnnotations(), getKotlinMetadataUtil());
  }

  private AssistedFactoryProcessingStep getAssistedFactoryProcessingStep() {
    return new AssistedFactoryProcessingStep(getMessager(), getFiler(), getSourceVersion(), getDaggerElements(), getDaggerTypes(), getBindingFactory());
  }

  private AssistedProcessingStep getAssistedProcessingStep() {
    return new AssistedProcessingStep(getKotlinMetadataUtil(), getInjectionAnnotations(), getDaggerElements(), getDaggerTypes(), getMessager());
  }

  private Object getMonitoringModuleGenerator() {
    return MonitoringModuleGenerator_Factory.newInstance(getFiler(), getDaggerElements(), getSourceVersion());
  }

  private MonitoringModuleProcessingStep getMonitoringModuleProcessingStep() {
    return MonitoringModuleProcessingStep_Factory.newInstance(getMessager(), getMonitoringModuleGenerator());
  }

  private MultibindingAnnotationsProcessingStep getMultibindingAnnotationsProcessingStep() {
    return MultibindingAnnotationsProcessingStep_Factory.newInstance(anyBindingMethodValidatorProvider.get(), getMessager());
  }

  private Object getBindsInstanceMethodValidator() {
    return BindsInstanceMethodValidator_Factory.newInstance(getInjectionAnnotations());
  }

  private Object getBindsInstanceParameterValidator() {
    return BindsInstanceParameterValidator_Factory.newInstance(getInjectionAnnotations());
  }

  private BindsInstanceProcessingStep getBindsInstanceProcessingStep() {
    return BindsInstanceProcessingStep_Factory.newInstance(getBindsInstanceMethodValidator(), getBindsInstanceParameterValidator(), getMessager());
  }

  private ProducerFactoryGenerator getProducerFactoryGenerator() {
    return ProducerFactoryGenerator_Factory.newInstance(getFiler(), getDaggerElements(), getSourceVersion(), bindCompilerOptionsProvider.get(), getKeyFactory());
  }

  private SourceFileGenerator<ProductionBinding> getSourceFileGeneratorOfProductionBinding() {
    return SourceFileGeneratorsModule_ProducerFactoryGeneratorFactory.producerFactoryGenerator(getProducerFactoryGenerator(), bindCompilerOptionsProvider.get());
  }

  private ModuleProxies getModuleProxies() {
    return new ModuleProxies(getDaggerElements(), getKotlinMetadataUtil());
  }

  private ModuleProxies.ModuleConstructorProxyGenerator getModuleConstructorProxyGenerator() {
    return ModuleProxies_ModuleConstructorProxyGenerator_Factory.newInstance(getFiler(), getDaggerElements(), getSourceVersion(), getModuleProxies(), getKotlinMetadataUtil());
  }

  private SourceFileGenerator<TypeElement> getModuleGeneratorSourceFileGeneratorOfTypeElement() {
    return SourceFileGeneratorsModule_ModuleConstructorProxyGeneratorFactory.moduleConstructorProxyGenerator(getModuleConstructorProxyGenerator(), bindCompilerOptionsProvider.get());
  }

  private InaccessibleMapKeyProxyGenerator getInaccessibleMapKeyProxyGenerator() {
    return InaccessibleMapKeyProxyGenerator_Factory.newInstance(getFiler(), getDaggerTypes(), getDaggerElements(), getSourceVersion());
  }

  private DelegateDeclaration.Factory getDelegateDeclarationFactory() {
    return DelegateDeclaration_Factory_Factory.newInstance(getDaggerTypes(), getKeyFactory(), getDependencyRequestFactory());
  }

  private ModuleProcessingStep getModuleProcessingStep() {
    return new ModuleProcessingStep(getMessager(), moduleValidatorProvider.get(), getBindingFactory(), getSourceFileGeneratorOfProvisionBinding(), getSourceFileGeneratorOfProductionBinding(), getModuleGeneratorSourceFileGeneratorOfTypeElement(), getInaccessibleMapKeyProxyGenerator(), getDelegateDeclarationFactory(), getKotlinMetadataUtil());
  }

  private MethodSignatureFormatter getMethodSignatureFormatter() {
    return new MethodSignatureFormatter(getDaggerTypes(), getInjectionAnnotations());
  }

  private Object getComponentHierarchyValidator() {
    return ComponentHierarchyValidator_Factory.newInstance(bindCompilerOptionsProvider.get());
  }

  private ComponentDescriptorValidator getComponentDescriptorValidator() {
    return ComponentDescriptorValidator_Factory.newInstance(getDaggerElements(), getDaggerTypes(), bindCompilerOptionsProvider.get(), getMethodSignatureFormatter(), getComponentHierarchyValidator(), getKotlinMetadataUtil());
  }

  private ComponentDescriptorFactory getComponentDescriptorFactory() {
    return ComponentDescriptorFactory_Factory.newInstance(getDaggerElements(), getDaggerTypes(), getDependencyRequestFactory(), factoryProvider5.get(), getInjectionAnnotations());
  }

  private Object getComponentGenerator() {
    return ComponentGenerator_Factory.newInstance(getFiler(), getDaggerElements(), getSourceVersion(), componentImplementationFactoryProvider.get());
  }

  private ComponentProcessingStep getComponentProcessingStep() {
    return new ComponentProcessingStep(getMessager(), componentValidatorProvider.get(), componentCreatorValidatorProvider.get(), getComponentDescriptorValidator(), getComponentDescriptorFactory(), bindingGraphFactoryProvider.get(), (SourceFileGenerator<BindingGraph>) getComponentGenerator(), bindingGraphValidatorProvider.get());
  }

  private Object getComponentHjarGenerator() {
    return ComponentHjarGenerator_Factory.newInstance(getFiler(), getDaggerElements(), getDaggerTypes(), getSourceVersion(), getKotlinMetadataUtil());
  }

  private ComponentHjarProcessingStep getComponentHjarProcessingStep() {
    return new ComponentHjarProcessingStep(getMessager(), componentValidatorProvider.get(), componentCreatorValidatorProvider.get(), getComponentDescriptorFactory(), (SourceFileGenerator<ComponentDescriptor>) getComponentHjarGenerator());
  }

  private BindingMethodProcessingStep getBindingMethodProcessingStep() {
    return BindingMethodProcessingStep_Factory.newInstance(getMessager(), anyBindingMethodValidatorProvider.get());
  }

  private ImmutableList<BasicAnnotationProcessor.ProcessingStep> getImmutableListOfProcessingStep(
      ) {
    return ComponentProcessor_ProcessingStepsModule_ProcessingStepsFactory.processingSteps(getMapKeyProcessingStep(), getInjectProcessingStep(), getAssistedInjectProcessingStep(), getAssistedFactoryProcessingStep(), getAssistedProcessingStep(), getMonitoringModuleProcessingStep(), getMultibindingAnnotationsProcessingStep(), getBindsInstanceProcessingStep(), getModuleProcessingStep(), getComponentProcessingStep(), getComponentHjarProcessingStep(), getBindingMethodProcessingStep(), bindCompilerOptionsProvider.get());
  }

  private DependencyRequestFormatter getDependencyRequestFormatter() {
    return DependencyRequestFormatter_Factory.newInstance(getDaggerTypes());
  }

  private DiagnosticMessageGenerator.Factory getDiagnosticMessageGeneratorFactory() {
    return DiagnosticMessageGenerator_Factory_Factory.newInstance(getDaggerTypes(), getDependencyRequestFormatter(), ElementFormatter_Factory.newInstance());
  }

  private CompositeBindingGraphPlugin.Factory getCompositeBindingGraphPluginFactory() {
    return CompositeBindingGraphPlugin_Factory_Factory.newInstance(getDiagnosticMessageGeneratorFactory());
  }

  private Object getDependencyCycleValidator() {
    return DependencyCycleValidator_Factory.newInstance(getDependencyRequestFormatter());
  }

  private Object getDependsOnProductionExecutorValidator() {
    return DependsOnProductionExecutorValidator_Factory.newInstance(bindCompilerOptionsProvider.get(), getKeyFactory());
  }

  private BindingDeclarationFormatter getBindingDeclarationFormatter() {
    return BindingDeclarationFormatter_Factory.newInstance(getMethodSignatureFormatter());
  }

  private Object getDuplicateBindingsValidator() {
    return DuplicateBindingsValidator_Factory.newInstance(getBindingDeclarationFormatter(), bindCompilerOptionsProvider.get());
  }

  private Object getIncompatiblyScopedBindingsValidator() {
    return IncompatiblyScopedBindingsValidator_Factory.newInstance(getMethodSignatureFormatter(), bindCompilerOptionsProvider.get());
  }

  private Object getInjectBindingValidator() {
    return InjectBindingValidator_Factory.newInstance(injectValidatorProvider.get());
  }

  private Object getMapMultibindingValidator() {
    return MapMultibindingValidator_Factory.newInstance(getBindingDeclarationFormatter(), getKeyFactory());
  }

  private Object getMissingBindingValidator() {
    return MissingBindingValidator_Factory.newInstance(getDaggerTypes(), (InjectBindingRegistry) injectBindingRegistryImplProvider.get());
  }

  private Object getNullableBindingValidator() {
    return NullableBindingValidator_Factory.newInstance(bindCompilerOptionsProvider.get());
  }

  private Object getSubcomponentFactoryMethodValidator() {
    return SubcomponentFactoryMethodValidator_Factory.newInstance(getDaggerTypes(), getKotlinMetadataUtil());
  }

  private ImmutableSet<BindingGraphPlugin> getValidationImmutableSetOfBindingGraphPlugin() {
    return BindingGraphValidationModule_ProvidePluginsFactory.providePlugins(getCompositeBindingGraphPluginFactory(), bindCompilerOptionsProvider.get(), getDependencyCycleValidator(), getDependsOnProductionExecutorValidator(), getDuplicateBindingsValidator(), getIncompatiblyScopedBindingsValidator(), getInjectBindingValidator(), getMapMultibindingValidator(), getMissingBindingValidator(), getNullableBindingValidator(), ProvisionDependencyOnProducerBindingValidator_Factory.newInstance(), getSubcomponentFactoryMethodValidator());
  }

  private Map<String, String> getProcessingOptionsMapOfStringAndString() {
    return ProcessingEnvironmentModule_ProcessingOptionsFactory.processingOptions(processingEnv);
  }

  private BindingGraphPlugins getBindingGraphPlugins() {
    return BindingGraphPlugins_Factory.newInstance(getValidationImmutableSetOfBindingGraphPlugin(), externalPluginsProvider.get(), getFiler(), getDaggerTypes(), getDaggerElements(), getProcessingOptionsMapOfStringAndString());
  }

  private Set<ClearableCache> getSetOfClearableCache() {
    return SetBuilder.<ClearableCache>newSetBuilder(8).add((ClearableCache) componentImplementationFactoryProvider.get()).add(anyBindingMethodValidatorProvider.get()).add(injectValidatorProvider.get()).add(factoryProvider5.get()).add(bindingGraphFactoryProvider.get()).add(componentValidatorProvider.get()).add(componentCreatorValidatorProvider.get()).add(kotlinMetadataFactoryProvider.get()).build();
  }

  @SuppressWarnings("unchecked")
  private void initialize(final ProcessingEnvironment processingEnvParam,
      final Optional<ImmutableSet<BindingGraphPlugin>> testingPluginsParam) {
    this.processingEnvProvider = InstanceFactory.create(processingEnvParam);
    this.daggerElementsProvider = ProcessingEnvironmentModule_DaggerElementsFactory.create(processingEnvProvider);
    this.typesProvider = ProcessingEnvironmentModule_TypesFactory.create(processingEnvProvider);
    this.daggerTypesProvider = DaggerTypes_Factory.create(typesProvider, daggerElementsProvider);
    this.messagerProvider = ProcessingEnvironmentModule_MessagerFactory.create(processingEnvProvider);
    this.kotlinMetadataFactoryProvider = DoubleCheck.provider(KotlinMetadataFactory_Factory.create());
    this.kotlinMetadataUtilProvider = KotlinMetadataUtil_Factory.create(kotlinMetadataFactoryProvider);
    this.injectionAnnotationsProvider = InjectionAnnotations_Factory.create(daggerElementsProvider, kotlinMetadataUtilProvider);
    this.membersInjectionValidatorProvider = MembersInjectionValidator_Factory.create(injectionAnnotationsProvider);
    this.dependencyRequestValidatorProvider = DependencyRequestValidator_Factory.create(membersInjectionValidatorProvider, injectionAnnotationsProvider, kotlinMetadataUtilProvider, daggerElementsProvider);
    this.processingEnvironmentCompilerOptionsProvider = ProcessingEnvironmentCompilerOptions_Factory.create(processingEnvProvider, daggerElementsProvider);
    this.bindCompilerOptionsProvider = SingleCheck.provider((Provider) processingEnvironmentCompilerOptionsProvider);
    this.injectValidatorProvider = DoubleCheck.provider(InjectValidator_Factory.create(daggerTypesProvider, daggerElementsProvider, dependencyRequestValidatorProvider, bindCompilerOptionsProvider, injectionAnnotationsProvider, kotlinMetadataUtilProvider));
    this.keyFactoryProvider = KeyFactory_Factory.create(daggerTypesProvider, daggerElementsProvider, injectionAnnotationsProvider);
    this.dependencyRequestFactoryProvider = DependencyRequestFactory_Factory.create(keyFactoryProvider, injectionAnnotationsProvider);
    this.injectionSiteFactoryProvider = InjectionSiteFactory_Factory.create(daggerTypesProvider, daggerElementsProvider, dependencyRequestFactoryProvider);
    this.bindingFactoryProvider = BindingFactory_Factory.create(daggerTypesProvider, daggerElementsProvider, keyFactoryProvider, dependencyRequestFactoryProvider, injectionSiteFactoryProvider, injectionAnnotationsProvider, kotlinMetadataUtilProvider);
    this.injectBindingRegistryImplProvider = DoubleCheck.provider(InjectBindingRegistryImpl_Factory.create(daggerElementsProvider, daggerTypesProvider, messagerProvider, injectValidatorProvider, keyFactoryProvider, bindingFactoryProvider, bindCompilerOptionsProvider));
    this.providesMethodValidatorProvider = ProvidesMethodValidator_Factory.create(daggerElementsProvider, daggerTypesProvider, kotlinMetadataUtilProvider, dependencyRequestValidatorProvider, injectionAnnotationsProvider);
    this.producesMethodValidatorProvider = ProducesMethodValidator_Factory.create(daggerElementsProvider, daggerTypesProvider, kotlinMetadataUtilProvider, dependencyRequestValidatorProvider, injectionAnnotationsProvider);
    this.bindsTypeCheckerProvider = BindsTypeChecker_Factory.create(daggerTypesProvider, daggerElementsProvider);
    this.bindsMethodValidatorProvider = BindsMethodValidator_Factory.create(daggerElementsProvider, daggerTypesProvider, kotlinMetadataUtilProvider, bindsTypeCheckerProvider, dependencyRequestValidatorProvider, injectionAnnotationsProvider);
    this.multibindsMethodValidatorProvider = MultibindsMethodValidator_Factory.create(daggerElementsProvider, daggerTypesProvider, kotlinMetadataUtilProvider, dependencyRequestValidatorProvider, injectionAnnotationsProvider);
    this.bindsOptionalOfMethodValidatorProvider = BindsOptionalOfMethodValidator_Factory.create(daggerElementsProvider, daggerTypesProvider, kotlinMetadataUtilProvider, dependencyRequestValidatorProvider, injectionAnnotationsProvider);
    this.setOfBindingMethodValidatorProvider = SetFactory.builder(5, 0).addProvider((Provider) providesMethodValidatorProvider).addProvider((Provider) producesMethodValidatorProvider).addProvider((Provider) bindsMethodValidatorProvider).addProvider((Provider) multibindsMethodValidatorProvider).addProvider((Provider) bindsOptionalOfMethodValidatorProvider).build();
    this.indexValidatorsProvider = BindingMethodValidatorsModule_IndexValidatorsFactory.create(setOfBindingMethodValidatorProvider);
    this.anyBindingMethodValidatorProvider = DoubleCheck.provider(AnyBindingMethodValidator_Factory.create(indexValidatorsProvider));
    this.methodSignatureFormatterProvider = MethodSignatureFormatter_Factory.create(daggerTypesProvider, injectionAnnotationsProvider);
    this.factoryProvider = MultibindingDeclaration_Factory_Factory.create(daggerTypesProvider, keyFactoryProvider);
    this.factoryProvider2 = DelegateDeclaration_Factory_Factory.create(daggerTypesProvider, keyFactoryProvider, dependencyRequestFactoryProvider);
    this.factoryProvider3 = SubcomponentDeclaration_Factory_Factory.create(keyFactoryProvider);
    this.factoryProvider4 = OptionalBindingDeclaration_Factory_Factory.create(keyFactoryProvider);
    this.factoryProvider5 = DoubleCheck.provider(ModuleDescriptor_Factory_Factory.create(daggerElementsProvider, kotlinMetadataUtilProvider, bindingFactoryProvider, factoryProvider, factoryProvider2, factoryProvider3, factoryProvider4));
    this.componentDescriptorFactoryProvider = ComponentDescriptorFactory_Factory.create(daggerElementsProvider, daggerTypesProvider, dependencyRequestFactoryProvider, factoryProvider5, injectionAnnotationsProvider);
    this.bindingDeclarationFormatterProvider = BindingDeclarationFormatter_Factory.create(methodSignatureFormatterProvider);
    this.bindingGraphConverterProvider = BindingGraphConverter_Factory.create(bindingDeclarationFormatterProvider);
    this.bindingGraphFactoryProvider = DoubleCheck.provider(BindingGraphFactory_Factory.create(daggerElementsProvider, injectBindingRegistryImplProvider, keyFactoryProvider, bindingFactoryProvider, factoryProvider5, bindingGraphConverterProvider, bindCompilerOptionsProvider));
    this.dependencyRequestFormatterProvider = DependencyRequestFormatter_Factory.create(daggerTypesProvider);
    this.factoryProvider6 = DiagnosticMessageGenerator_Factory_Factory.create(daggerTypesProvider, dependencyRequestFormatterProvider, ElementFormatter_Factory.create());
    this.factoryProvider7 = CompositeBindingGraphPlugin_Factory_Factory.create(factoryProvider6);
    this.dependencyCycleValidatorProvider = DependencyCycleValidator_Factory.create(dependencyRequestFormatterProvider);
    this.dependsOnProductionExecutorValidatorProvider = DependsOnProductionExecutorValidator_Factory.create(bindCompilerOptionsProvider, keyFactoryProvider);
    this.duplicateBindingsValidatorProvider = DuplicateBindingsValidator_Factory.create(bindingDeclarationFormatterProvider, bindCompilerOptionsProvider);
    this.incompatiblyScopedBindingsValidatorProvider = IncompatiblyScopedBindingsValidator_Factory.create(methodSignatureFormatterProvider, bindCompilerOptionsProvider);
    this.injectBindingValidatorProvider = InjectBindingValidator_Factory.create(injectValidatorProvider);
    this.mapMultibindingValidatorProvider = MapMultibindingValidator_Factory.create(bindingDeclarationFormatterProvider, keyFactoryProvider);
    this.missingBindingValidatorProvider = MissingBindingValidator_Factory.create(daggerTypesProvider, injectBindingRegistryImplProvider);
    this.nullableBindingValidatorProvider = NullableBindingValidator_Factory.create(bindCompilerOptionsProvider);
    this.subcomponentFactoryMethodValidatorProvider = SubcomponentFactoryMethodValidator_Factory.create(daggerTypesProvider, kotlinMetadataUtilProvider);
    this.providePluginsProvider = BindingGraphValidationModule_ProvidePluginsFactory.create(factoryProvider7, bindCompilerOptionsProvider, dependencyCycleValidatorProvider, dependsOnProductionExecutorValidatorProvider, duplicateBindingsValidatorProvider, incompatiblyScopedBindingsValidatorProvider, injectBindingValidatorProvider, mapMultibindingValidatorProvider, missingBindingValidatorProvider, nullableBindingValidatorProvider, ProvisionDependencyOnProducerBindingValidator_Factory.create(), subcomponentFactoryMethodValidatorProvider);
    this.testingPluginsProvider = InstanceFactory.create(testingPluginsParam);
    this.processorClassloaderProvider = ProcessingEnvironmentModule_ProcessorClassloaderFactory.create(processingEnvProvider);
    this.externalPluginsProvider = DoubleCheck.provider(SpiModule_ExternalPluginsFactory.create(testingPluginsProvider, processorClassloaderProvider));
    this.diagnosticReporterFactoryProvider = DiagnosticReporterFactory_Factory.create(messagerProvider, factoryProvider6);
    this.bindingGraphValidatorProvider = DoubleCheck.provider(BindingGraphValidator_Factory.create(providePluginsProvider, externalPluginsProvider, diagnosticReporterFactoryProvider, bindCompilerOptionsProvider));
    this.moduleValidatorProvider = DoubleCheck.provider(ModuleValidator_Factory.create(daggerTypesProvider, daggerElementsProvider, anyBindingMethodValidatorProvider, methodSignatureFormatterProvider, componentDescriptorFactoryProvider, bindingGraphFactoryProvider, bindingGraphValidatorProvider, kotlinMetadataUtilProvider));
    this.componentCreatorValidatorProvider = DoubleCheck.provider(ComponentCreatorValidator_Factory.create(daggerElementsProvider, daggerTypesProvider));
    this.componentValidatorProvider = DoubleCheck.provider(ComponentValidator_Factory.create(daggerElementsProvider, daggerTypesProvider, moduleValidatorProvider, componentCreatorValidatorProvider, dependencyRequestValidatorProvider, membersInjectionValidatorProvider, methodSignatureFormatterProvider, dependencyRequestFactoryProvider));
    this.topLevelImplementationComponentBuilderProvider = new Provider<TopLevelImplementationComponent.Builder>() {
      @Override
      public TopLevelImplementationComponent.Builder get() {
        return new TopLevelImplementationComponentBuilder();
      }
    };
    this.componentImplementationFactoryProvider = DoubleCheck.provider(ComponentImplementationFactory_Factory.create(keyFactoryProvider, bindCompilerOptionsProvider, topLevelImplementationComponentBuilderProvider));
    this.moduleProxiesProvider = ModuleProxies_Factory.create(daggerElementsProvider, kotlinMetadataUtilProvider);
    this.sourceVersionProvider = ProcessingEnvironmentModule_SourceVersionFactory.create(processingEnvProvider);
  }

  @Override
  public void inject(ComponentProcessor processor) {
    injectComponentProcessor(processor);
  }

  @CanIgnoreReturnValue
  private ComponentProcessor injectComponentProcessor(ComponentProcessor instance) {
    ComponentProcessor_MembersInjector.injectInjectBindingRegistry(instance, (InjectBindingRegistry) injectBindingRegistryImplProvider.get());
    ComponentProcessor_MembersInjector.injectFactoryGenerator(instance, getSourceFileGeneratorOfProvisionBinding());
    ComponentProcessor_MembersInjector.injectMembersInjectorGenerator(instance, getSourceFileGeneratorOfMembersInjectionBinding());
    ComponentProcessor_MembersInjector.injectProcessingSteps(instance, getImmutableListOfProcessingStep());
    ComponentProcessor_MembersInjector.injectBindingGraphPlugins(instance, getBindingGraphPlugins());
    ComponentProcessor_MembersInjector.injectClearableCaches(instance, getSetOfClearableCache());
    return instance;
  }

  private static final class Factory implements ComponentProcessor.ProcessorComponent.Factory {
    @Override
    public ComponentProcessor.ProcessorComponent create(ProcessingEnvironment processingEnv,
        Optional<ImmutableSet<BindingGraphPlugin>> testingPlugins) {
      Preconditions.checkNotNull(processingEnv);
      Preconditions.checkNotNull(testingPlugins);
      return new DaggerComponentProcessor_ProcessorComponent(processingEnv, testingPlugins);
    }
  }

  private final class TopLevelImplementationComponentBuilder implements TopLevelImplementationComponent.Builder {
    private ComponentImplementation topLevelComponent;

    @Override
    public TopLevelImplementationComponentBuilder topLevelComponent(
        ComponentImplementation topLevelImplementation) {
      this.topLevelComponent = Preconditions.checkNotNull(topLevelImplementation);
      return this;
    }

    @Override
    public TopLevelImplementationComponent build() {
      Preconditions.checkBuilderRequirement(topLevelComponent, ComponentImplementation.class);
      return new TopLevelImplementationComponentImpl(topLevelComponent);
    }
  }

  private final class TopLevelImplementationComponentImpl implements TopLevelImplementationComponent {
    private Provider<ComponentImplementation> topLevelComponentProvider;

    @SuppressWarnings("rawtypes")
    private Provider optionalFactoriesProvider;

    private TopLevelImplementationComponentImpl(ComponentImplementation topLevelComponentParam) {

      initialize(topLevelComponentParam);
    }

    @SuppressWarnings("unchecked")
    private void initialize(final ComponentImplementation topLevelComponentParam) {
      this.topLevelComponentProvider = InstanceFactory.create(topLevelComponentParam);
      this.optionalFactoriesProvider = DoubleCheck.provider(OptionalFactories_Factory.create(topLevelComponentProvider));
    }

    @Override
    public CurrentImplementationSubcomponent.Builder currentImplementationSubcomponentBuilder() {
      return new CurrentImplementationSubcomponentBuilder();
    }

    private final class CurrentImplementationSubcomponentBuilder implements CurrentImplementationSubcomponent.Builder {
      private ComponentImplementation componentImplementation;

      private BindingGraph bindingGraph;

      private Optional<ComponentImplementationBuilder> parentBuilder;

      private Optional<ComponentBindingExpressions> parentBindingExpressions;

      private Optional<ComponentRequirementExpressions> parentRequirementExpressions;

      @Override
      public CurrentImplementationSubcomponentBuilder componentImplementation(
          ComponentImplementation componentImplementation) {
        this.componentImplementation = Preconditions.checkNotNull(componentImplementation);
        return this;
      }

      @Override
      public CurrentImplementationSubcomponentBuilder bindingGraph(BindingGraph bindingGraph) {
        this.bindingGraph = Preconditions.checkNotNull(bindingGraph);
        return this;
      }

      @Override
      public CurrentImplementationSubcomponentBuilder parentBuilder(
          Optional<ComponentImplementationBuilder> parentBuilder) {
        this.parentBuilder = Preconditions.checkNotNull(parentBuilder);
        return this;
      }

      @Override
      public CurrentImplementationSubcomponentBuilder parentBindingExpressions(
          Optional<ComponentBindingExpressions> parentBindingExpressions) {
        this.parentBindingExpressions = Preconditions.checkNotNull(parentBindingExpressions);
        return this;
      }

      @Override
      public CurrentImplementationSubcomponentBuilder parentRequirementExpressions(
          Optional<ComponentRequirementExpressions> parentRequirementExpressions) {
        this.parentRequirementExpressions = Preconditions.checkNotNull(parentRequirementExpressions);
        return this;
      }

      @Override
      public CurrentImplementationSubcomponent build() {
        Preconditions.checkBuilderRequirement(componentImplementation, ComponentImplementation.class);
        Preconditions.checkBuilderRequirement(bindingGraph, BindingGraph.class);
        Preconditions.checkBuilderRequirement(parentBuilder, Optional.class);
        Preconditions.checkBuilderRequirement(parentBindingExpressions, Optional.class);
        Preconditions.checkBuilderRequirement(parentRequirementExpressions, Optional.class);
        return new CurrentImplementationSubcomponentImpl(componentImplementation, bindingGraph, parentBuilder, parentBindingExpressions, parentRequirementExpressions);
      }
    }

    private final class CurrentImplementationSubcomponentImpl implements CurrentImplementationSubcomponent {
      private final Optional<ComponentImplementationBuilder> parentBuilder;

      private final BindingGraph bindingGraph;

      private final ComponentImplementation componentImplementation;

      private Provider<Optional<ComponentBindingExpressions>> parentBindingExpressionsProvider;

      private Provider<BindingGraph> bindingGraphProvider;

      private Provider<ComponentImplementation> componentImplementationProvider;

      private Provider<Optional<ComponentRequirementExpressions>> parentRequirementExpressionsProvider;

      private Provider<ComponentRequirementExpressions> componentRequirementExpressionsProvider;

      private Provider<ComponentBindingExpressions> componentBindingExpressionsProvider;

      private CurrentImplementationSubcomponentImpl(
          ComponentImplementation componentImplementationParam, BindingGraph bindingGraphParam,
          Optional<ComponentImplementationBuilder> parentBuilderParam,
          Optional<ComponentBindingExpressions> parentBindingExpressionsParam,
          Optional<ComponentRequirementExpressions> parentRequirementExpressionsParam) {
        this.parentBuilder = parentBuilderParam;
        this.bindingGraph = bindingGraphParam;
        this.componentImplementation = componentImplementationParam;
        initialize(componentImplementationParam, bindingGraphParam, parentBuilderParam, parentBindingExpressionsParam, parentRequirementExpressionsParam);
      }

      private Object getComponentCreatorImplementationFactory() {
        return ComponentCreatorImplementationFactory_Factory.newInstance(componentImplementation, DaggerComponentProcessor_ProcessorComponent.this.getDaggerElements(), DaggerComponentProcessor_ProcessorComponent.this.getDaggerTypes(), DaggerComponentProcessor_ProcessorComponent.this.getKotlinMetadataUtil(), DaggerComponentProcessor_ProcessorComponent.this.getModuleProxies());
      }

      @SuppressWarnings("unchecked")
      private void initialize(final ComponentImplementation componentImplementationParam,
          final BindingGraph bindingGraphParam,
          final Optional<ComponentImplementationBuilder> parentBuilderParam,
          final Optional<ComponentBindingExpressions> parentBindingExpressionsParam,
          final Optional<ComponentRequirementExpressions> parentRequirementExpressionsParam) {
        this.parentBindingExpressionsProvider = InstanceFactory.create(parentBindingExpressionsParam);
        this.bindingGraphProvider = InstanceFactory.create(bindingGraphParam);
        this.componentImplementationProvider = InstanceFactory.create(componentImplementationParam);
        this.parentRequirementExpressionsProvider = InstanceFactory.create(parentRequirementExpressionsParam);
        this.componentRequirementExpressionsProvider = DoubleCheck.provider(ComponentRequirementExpressions_Factory.create(parentRequirementExpressionsProvider, bindingGraphProvider, componentImplementationProvider, DaggerComponentProcessor_ProcessorComponent.this.daggerElementsProvider, DaggerComponentProcessor_ProcessorComponent.this.moduleProxiesProvider));
        this.componentBindingExpressionsProvider = DoubleCheck.provider(ComponentBindingExpressions_Factory.create(parentBindingExpressionsProvider, bindingGraphProvider, componentImplementationProvider, TopLevelImplementationComponentImpl.this.topLevelComponentProvider, componentRequirementExpressionsProvider, TopLevelImplementationComponentImpl.this.optionalFactoriesProvider, DaggerComponentProcessor_ProcessorComponent.this.daggerTypesProvider, DaggerComponentProcessor_ProcessorComponent.this.daggerElementsProvider, DaggerComponentProcessor_ProcessorComponent.this.sourceVersionProvider, DaggerComponentProcessor_ProcessorComponent.this.bindCompilerOptionsProvider, DaggerComponentProcessor_ProcessorComponent.this.kotlinMetadataUtilProvider));
      }

      @Override
      public ComponentImplementationBuilder componentImplementationBuilder() {
        return ComponentImplementationBuilder_Factory.newInstance(parentBuilder, bindingGraph, componentBindingExpressionsProvider.get(), componentRequirementExpressionsProvider.get(), componentImplementation, getComponentCreatorImplementationFactory(), TopLevelImplementationComponentImpl.this, DaggerComponentProcessor_ProcessorComponent.this.getDaggerTypes(), DaggerComponentProcessor_ProcessorComponent.this.getDaggerElements(), DaggerComponentProcessor_ProcessorComponent.this.getKotlinMetadataUtil());
      }
    }
  }
}

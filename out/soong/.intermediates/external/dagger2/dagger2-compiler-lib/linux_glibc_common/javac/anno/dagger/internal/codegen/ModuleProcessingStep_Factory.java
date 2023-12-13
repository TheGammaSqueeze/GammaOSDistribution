package dagger.internal.codegen;

import dagger.internal.Factory;
import dagger.internal.codegen.base.SourceFileGenerator;
import dagger.internal.codegen.binding.BindingFactory;
import dagger.internal.codegen.binding.DelegateDeclaration;
import dagger.internal.codegen.binding.ProductionBinding;
import dagger.internal.codegen.binding.ProvisionBinding;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
import dagger.internal.codegen.validation.ModuleValidator;
import dagger.internal.codegen.writing.InaccessibleMapKeyProxyGenerator;
import javax.annotation.Generated;
import javax.annotation.processing.Messager;
import javax.inject.Provider;
import javax.lang.model.element.TypeElement;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class ModuleProcessingStep_Factory implements Factory<ModuleProcessingStep> {
  private final Provider<Messager> messagerProvider;

  private final Provider<ModuleValidator> moduleValidatorProvider;

  private final Provider<BindingFactory> bindingFactoryProvider;

  private final Provider<SourceFileGenerator<ProvisionBinding>> factoryGeneratorProvider;

  private final Provider<SourceFileGenerator<ProductionBinding>> producerFactoryGeneratorProvider;

  private final Provider<SourceFileGenerator<TypeElement>> moduleConstructorProxyGeneratorProvider;

  private final Provider<InaccessibleMapKeyProxyGenerator> inaccessibleMapKeyProxyGeneratorProvider;

  private final Provider<DelegateDeclaration.Factory> delegateDeclarationFactoryProvider;

  private final Provider<KotlinMetadataUtil> metadataUtilProvider;

  public ModuleProcessingStep_Factory(Provider<Messager> messagerProvider,
      Provider<ModuleValidator> moduleValidatorProvider,
      Provider<BindingFactory> bindingFactoryProvider,
      Provider<SourceFileGenerator<ProvisionBinding>> factoryGeneratorProvider,
      Provider<SourceFileGenerator<ProductionBinding>> producerFactoryGeneratorProvider,
      Provider<SourceFileGenerator<TypeElement>> moduleConstructorProxyGeneratorProvider,
      Provider<InaccessibleMapKeyProxyGenerator> inaccessibleMapKeyProxyGeneratorProvider,
      Provider<DelegateDeclaration.Factory> delegateDeclarationFactoryProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    this.messagerProvider = messagerProvider;
    this.moduleValidatorProvider = moduleValidatorProvider;
    this.bindingFactoryProvider = bindingFactoryProvider;
    this.factoryGeneratorProvider = factoryGeneratorProvider;
    this.producerFactoryGeneratorProvider = producerFactoryGeneratorProvider;
    this.moduleConstructorProxyGeneratorProvider = moduleConstructorProxyGeneratorProvider;
    this.inaccessibleMapKeyProxyGeneratorProvider = inaccessibleMapKeyProxyGeneratorProvider;
    this.delegateDeclarationFactoryProvider = delegateDeclarationFactoryProvider;
    this.metadataUtilProvider = metadataUtilProvider;
  }

  @Override
  public ModuleProcessingStep get() {
    return new ModuleProcessingStep(messagerProvider.get(), moduleValidatorProvider.get(), bindingFactoryProvider.get(), factoryGeneratorProvider.get(), producerFactoryGeneratorProvider.get(), moduleConstructorProxyGeneratorProvider.get(), inaccessibleMapKeyProxyGeneratorProvider.get(), delegateDeclarationFactoryProvider.get(), metadataUtilProvider.get());
  }

  public static ModuleProcessingStep_Factory create(Provider<Messager> messagerProvider,
      Provider<ModuleValidator> moduleValidatorProvider,
      Provider<BindingFactory> bindingFactoryProvider,
      Provider<SourceFileGenerator<ProvisionBinding>> factoryGeneratorProvider,
      Provider<SourceFileGenerator<ProductionBinding>> producerFactoryGeneratorProvider,
      Provider<SourceFileGenerator<TypeElement>> moduleConstructorProxyGeneratorProvider,
      Provider<InaccessibleMapKeyProxyGenerator> inaccessibleMapKeyProxyGeneratorProvider,
      Provider<DelegateDeclaration.Factory> delegateDeclarationFactoryProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    return new ModuleProcessingStep_Factory(messagerProvider, moduleValidatorProvider, bindingFactoryProvider, factoryGeneratorProvider, producerFactoryGeneratorProvider, moduleConstructorProxyGeneratorProvider, inaccessibleMapKeyProxyGeneratorProvider, delegateDeclarationFactoryProvider, metadataUtilProvider);
  }

  public static ModuleProcessingStep newInstance(Messager messager, ModuleValidator moduleValidator,
      BindingFactory bindingFactory, SourceFileGenerator<ProvisionBinding> factoryGenerator,
      SourceFileGenerator<ProductionBinding> producerFactoryGenerator,
      SourceFileGenerator<TypeElement> moduleConstructorProxyGenerator,
      InaccessibleMapKeyProxyGenerator inaccessibleMapKeyProxyGenerator,
      DelegateDeclaration.Factory delegateDeclarationFactory, KotlinMetadataUtil metadataUtil) {
    return new ModuleProcessingStep(messager, moduleValidator, bindingFactory, factoryGenerator, producerFactoryGenerator, moduleConstructorProxyGenerator, inaccessibleMapKeyProxyGenerator, delegateDeclarationFactory, metadataUtil);
  }
}

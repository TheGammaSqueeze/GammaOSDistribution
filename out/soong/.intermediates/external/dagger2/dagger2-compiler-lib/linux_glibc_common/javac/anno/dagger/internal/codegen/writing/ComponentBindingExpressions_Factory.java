package dagger.internal.codegen.writing;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.BindingGraph;
import dagger.internal.codegen.compileroption.CompilerOptions;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import java.util.Optional;
import javax.annotation.Generated;
import javax.inject.Provider;
import javax.lang.model.SourceVersion;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class ComponentBindingExpressions_Factory implements Factory<ComponentBindingExpressions> {
  private final Provider<Optional<ComponentBindingExpressions>> parentProvider;

  private final Provider<BindingGraph> graphProvider;

  private final Provider<ComponentImplementation> componentImplementationProvider;

  private final Provider<ComponentImplementation> topLevelComponentImplementationProvider;

  private final Provider<ComponentRequirementExpressions> componentRequirementExpressionsProvider;

  private final Provider<OptionalFactories> optionalFactoriesProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  private final Provider<CompilerOptions> compilerOptionsProvider;

  private final Provider<KotlinMetadataUtil> metadataUtilProvider;

  public ComponentBindingExpressions_Factory(
      Provider<Optional<ComponentBindingExpressions>> parentProvider,
      Provider<BindingGraph> graphProvider,
      Provider<ComponentImplementation> componentImplementationProvider,
      Provider<ComponentImplementation> topLevelComponentImplementationProvider,
      Provider<ComponentRequirementExpressions> componentRequirementExpressionsProvider,
      Provider<OptionalFactories> optionalFactoriesProvider, Provider<DaggerTypes> typesProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider,
      Provider<CompilerOptions> compilerOptionsProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    this.parentProvider = parentProvider;
    this.graphProvider = graphProvider;
    this.componentImplementationProvider = componentImplementationProvider;
    this.topLevelComponentImplementationProvider = topLevelComponentImplementationProvider;
    this.componentRequirementExpressionsProvider = componentRequirementExpressionsProvider;
    this.optionalFactoriesProvider = optionalFactoriesProvider;
    this.typesProvider = typesProvider;
    this.elementsProvider = elementsProvider;
    this.sourceVersionProvider = sourceVersionProvider;
    this.compilerOptionsProvider = compilerOptionsProvider;
    this.metadataUtilProvider = metadataUtilProvider;
  }

  @Override
  public ComponentBindingExpressions get() {
    return new ComponentBindingExpressions(parentProvider.get(), graphProvider.get(), componentImplementationProvider.get(), topLevelComponentImplementationProvider.get(), componentRequirementExpressionsProvider.get(), optionalFactoriesProvider.get(), typesProvider.get(), elementsProvider.get(), sourceVersionProvider.get(), compilerOptionsProvider.get(), metadataUtilProvider.get());
  }

  public static ComponentBindingExpressions_Factory create(
      Provider<Optional<ComponentBindingExpressions>> parentProvider,
      Provider<BindingGraph> graphProvider,
      Provider<ComponentImplementation> componentImplementationProvider,
      Provider<ComponentImplementation> topLevelComponentImplementationProvider,
      Provider<ComponentRequirementExpressions> componentRequirementExpressionsProvider,
      Provider<OptionalFactories> optionalFactoriesProvider, Provider<DaggerTypes> typesProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider,
      Provider<CompilerOptions> compilerOptionsProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    return new ComponentBindingExpressions_Factory(parentProvider, graphProvider, componentImplementationProvider, topLevelComponentImplementationProvider, componentRequirementExpressionsProvider, optionalFactoriesProvider, typesProvider, elementsProvider, sourceVersionProvider, compilerOptionsProvider, metadataUtilProvider);
  }

  public static ComponentBindingExpressions newInstance(
      Optional<ComponentBindingExpressions> parent, BindingGraph graph,
      ComponentImplementation componentImplementation,
      ComponentImplementation topLevelComponentImplementation,
      ComponentRequirementExpressions componentRequirementExpressions, Object optionalFactories,
      DaggerTypes types, DaggerElements elements, SourceVersion sourceVersion,
      CompilerOptions compilerOptions, KotlinMetadataUtil metadataUtil) {
    return new ComponentBindingExpressions(parent, graph, componentImplementation, topLevelComponentImplementation, componentRequirementExpressions, (OptionalFactories) optionalFactories, types, elements, sourceVersion, compilerOptions, metadataUtil);
  }
}

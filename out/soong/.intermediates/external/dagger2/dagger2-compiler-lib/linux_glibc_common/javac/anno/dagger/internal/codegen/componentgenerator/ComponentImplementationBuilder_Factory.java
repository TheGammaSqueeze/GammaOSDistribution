package dagger.internal.codegen.componentgenerator;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.BindingGraph;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.internal.codegen.writing.ComponentBindingExpressions;
import dagger.internal.codegen.writing.ComponentImplementation;
import dagger.internal.codegen.writing.ComponentRequirementExpressions;
import java.util.Optional;
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
public final class ComponentImplementationBuilder_Factory implements Factory<ComponentImplementationBuilder> {
  private final Provider<Optional<ComponentImplementationBuilder>> parentProvider;

  private final Provider<BindingGraph> graphProvider;

  private final Provider<ComponentBindingExpressions> bindingExpressionsProvider;

  private final Provider<ComponentRequirementExpressions> componentRequirementExpressionsProvider;

  private final Provider<ComponentImplementation> componentImplementationProvider;

  private final Provider<ComponentCreatorImplementationFactory> componentCreatorImplementationFactoryProvider;

  private final Provider<TopLevelImplementationComponent> topLevelImplementationComponentProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<KotlinMetadataUtil> metadataUtilProvider;

  public ComponentImplementationBuilder_Factory(
      Provider<Optional<ComponentImplementationBuilder>> parentProvider,
      Provider<BindingGraph> graphProvider,
      Provider<ComponentBindingExpressions> bindingExpressionsProvider,
      Provider<ComponentRequirementExpressions> componentRequirementExpressionsProvider,
      Provider<ComponentImplementation> componentImplementationProvider,
      Provider<ComponentCreatorImplementationFactory> componentCreatorImplementationFactoryProvider,
      Provider<TopLevelImplementationComponent> topLevelImplementationComponentProvider,
      Provider<DaggerTypes> typesProvider, Provider<DaggerElements> elementsProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    this.parentProvider = parentProvider;
    this.graphProvider = graphProvider;
    this.bindingExpressionsProvider = bindingExpressionsProvider;
    this.componentRequirementExpressionsProvider = componentRequirementExpressionsProvider;
    this.componentImplementationProvider = componentImplementationProvider;
    this.componentCreatorImplementationFactoryProvider = componentCreatorImplementationFactoryProvider;
    this.topLevelImplementationComponentProvider = topLevelImplementationComponentProvider;
    this.typesProvider = typesProvider;
    this.elementsProvider = elementsProvider;
    this.metadataUtilProvider = metadataUtilProvider;
  }

  @Override
  public ComponentImplementationBuilder get() {
    return new ComponentImplementationBuilder(parentProvider.get(), graphProvider.get(), bindingExpressionsProvider.get(), componentRequirementExpressionsProvider.get(), componentImplementationProvider.get(), componentCreatorImplementationFactoryProvider.get(), topLevelImplementationComponentProvider.get(), typesProvider.get(), elementsProvider.get(), metadataUtilProvider.get());
  }

  public static ComponentImplementationBuilder_Factory create(
      Provider<Optional<ComponentImplementationBuilder>> parentProvider,
      Provider<BindingGraph> graphProvider,
      Provider<ComponentBindingExpressions> bindingExpressionsProvider,
      Provider<ComponentRequirementExpressions> componentRequirementExpressionsProvider,
      Provider<ComponentImplementation> componentImplementationProvider,
      Provider<ComponentCreatorImplementationFactory> componentCreatorImplementationFactoryProvider,
      Provider<TopLevelImplementationComponent> topLevelImplementationComponentProvider,
      Provider<DaggerTypes> typesProvider, Provider<DaggerElements> elementsProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    return new ComponentImplementationBuilder_Factory(parentProvider, graphProvider, bindingExpressionsProvider, componentRequirementExpressionsProvider, componentImplementationProvider, componentCreatorImplementationFactoryProvider, topLevelImplementationComponentProvider, typesProvider, elementsProvider, metadataUtilProvider);
  }

  public static ComponentImplementationBuilder newInstance(
      Optional<ComponentImplementationBuilder> parent, BindingGraph graph,
      ComponentBindingExpressions bindingExpressions,
      ComponentRequirementExpressions componentRequirementExpressions,
      ComponentImplementation componentImplementation, Object componentCreatorImplementationFactory,
      TopLevelImplementationComponent topLevelImplementationComponent, DaggerTypes types,
      DaggerElements elements, KotlinMetadataUtil metadataUtil) {
    return new ComponentImplementationBuilder(parent, graph, bindingExpressions, componentRequirementExpressions, componentImplementation, (ComponentCreatorImplementationFactory) componentCreatorImplementationFactory, topLevelImplementationComponent, types, elements, metadataUtil);
  }
}

/*
 * Copyright (C) 2014 The Dagger Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package dagger.internal.codegen.binding;

import static com.google.auto.common.MoreTypes.asTypeElement;
import static com.google.auto.common.MoreTypes.isType;
import static com.google.auto.common.MoreTypes.isTypeOf;
import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.base.Preconditions.checkNotNull;
import static dagger.internal.codegen.base.RequestKinds.getRequestKind;
import static dagger.internal.codegen.base.Util.reentrantComputeIfAbsent;
import static dagger.internal.codegen.binding.AssistedInjectionAnnotations.isAssistedFactoryType;
import static dagger.internal.codegen.binding.ComponentDescriptor.isComponentContributionMethod;
import static dagger.internal.codegen.binding.SourceFiles.generatedMonitoringModuleName;
import static dagger.model.BindingKind.ASSISTED_INJECTION;
import static dagger.model.BindingKind.DELEGATE;
import static dagger.model.BindingKind.INJECTION;
import static dagger.model.BindingKind.OPTIONAL;
import static dagger.model.BindingKind.SUBCOMPONENT_CREATOR;
import static dagger.model.RequestKind.MEMBERS_INJECTION;
import static java.util.function.Predicate.isEqual;
import static javax.lang.model.util.ElementFilter.methodsIn;

import com.google.auto.common.MoreTypes;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.ImmutableSetMultimap;
import com.google.common.collect.Iterables;
import com.google.common.collect.Multimaps;
import dagger.MembersInjector;
import dagger.Reusable;
import dagger.internal.codegen.base.ClearableCache;
import dagger.internal.codegen.base.ContributionType;
import dagger.internal.codegen.base.MapType;
import dagger.internal.codegen.base.OptionalType;
import dagger.internal.codegen.compileroption.CompilerOptions;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.model.DependencyRequest;
import dagger.model.Key;
import dagger.model.Scope;
import dagger.producers.Produced;
import dagger.producers.Producer;
import dagger.producers.internal.ProductionExecutorModule;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Queue;
import java.util.Set;
import javax.inject.Inject;
import javax.inject.Provider;
import javax.inject.Singleton;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.TypeKind;

/** A factory for {@link BindingGraph} objects. */
@Singleton
public final class BindingGraphFactory implements ClearableCache {

  private final DaggerElements elements;
  private final InjectBindingRegistry injectBindingRegistry;
  private final KeyFactory keyFactory;
  private final BindingFactory bindingFactory;
  private final ModuleDescriptor.Factory moduleDescriptorFactory;
  private final BindingGraphConverter bindingGraphConverter;
  private final Map<Key, ImmutableSet<Key>> keysMatchingRequestCache = new HashMap<>();
  private final CompilerOptions compilerOptions;

  @Inject
  BindingGraphFactory(
      DaggerElements elements,
      InjectBindingRegistry injectBindingRegistry,
      KeyFactory keyFactory,
      BindingFactory bindingFactory,
      ModuleDescriptor.Factory moduleDescriptorFactory,
      BindingGraphConverter bindingGraphConverter,
      CompilerOptions compilerOptions) {
    this.elements = elements;
    this.injectBindingRegistry = injectBindingRegistry;
    this.keyFactory = keyFactory;
    this.bindingFactory = bindingFactory;
    this.moduleDescriptorFactory = moduleDescriptorFactory;
    this.bindingGraphConverter = bindingGraphConverter;
    this.compilerOptions = compilerOptions;
  }

  /**
   * Creates a binding graph for a component.
   *
   * @param createFullBindingGraph if {@code true}, the binding graph will include all bindings;
   *     otherwise it will include only bindings reachable from at least one entry point
   */
  public BindingGraph create(
      ComponentDescriptor componentDescriptor, boolean createFullBindingGraph) {
    return bindingGraphConverter.convert(
        createLegacyBindingGraph(Optional.empty(), componentDescriptor, createFullBindingGraph),
        createFullBindingGraph);
  }

  private LegacyBindingGraph createLegacyBindingGraph(
      Optional<Resolver> parentResolver,
      ComponentDescriptor componentDescriptor,
      boolean createFullBindingGraph) {
    ImmutableSet.Builder<ContributionBinding> explicitBindingsBuilder = ImmutableSet.builder();
    ImmutableSet.Builder<DelegateDeclaration> delegatesBuilder = ImmutableSet.builder();
    ImmutableSet.Builder<OptionalBindingDeclaration> optionalsBuilder = ImmutableSet.builder();

    if (componentDescriptor.isRealComponent()) {
      // binding for the component itself
      explicitBindingsBuilder.add(
          bindingFactory.componentBinding(componentDescriptor.typeElement()));
    }

    // Collect Component dependencies.
    for (ComponentRequirement dependency : componentDescriptor.dependencies()) {
      explicitBindingsBuilder.add(bindingFactory.componentDependencyBinding(dependency));
      List<ExecutableElement> dependencyMethods =
          methodsIn(elements.getAllMembers(dependency.typeElement()));

      // Within a component dependency, we want to allow the same method to appear multiple
      // times assuming it is the exact same method. We do this by tracking a set of bindings
      // we've already added with the binding element removed since that is the only thing
      // allowed to differ.
      HashMultimap<String, ContributionBinding> dedupeBindings = HashMultimap.create();
      for (ExecutableElement method : dependencyMethods) {
        // MembersInjection methods aren't "provided" explicitly, so ignore them.
        if (isComponentContributionMethod(elements, method)) {
          ContributionBinding binding = bindingFactory.componentDependencyMethodBinding(
              componentDescriptor, method);
          if (dedupeBindings.put(
              method.getSimpleName().toString(),
              // Remove the binding element since we know that will be different, but everything
              // else we want to be the same to consider it a duplicate.
              binding.toBuilder().clearBindingElement().build())) {
            explicitBindingsBuilder.add(binding);
          }
        }
      }
    }

    // Collect bindings on the creator.
    componentDescriptor
        .creatorDescriptor()
        .ifPresent(
            creatorDescriptor ->
                creatorDescriptor.boundInstanceRequirements().stream()
                    .map(
                        requirement ->
                            bindingFactory.boundInstanceBinding(
                                requirement, creatorDescriptor.elementForRequirement(requirement)))
                    .forEach(explicitBindingsBuilder::add));

    componentDescriptor
        .childComponentsDeclaredByBuilderEntryPoints()
        .forEach(
            (builderEntryPoint, childComponent) -> {
              if (!componentDescriptor
                  .childComponentsDeclaredByModules()
                  .contains(childComponent)) {
                explicitBindingsBuilder.add(
                    bindingFactory.subcomponentCreatorBinding(
                        builderEntryPoint.methodElement(), componentDescriptor.typeElement()));
              }
            });

    ImmutableSet.Builder<MultibindingDeclaration> multibindingDeclarations = ImmutableSet.builder();
    ImmutableSet.Builder<SubcomponentDeclaration> subcomponentDeclarations = ImmutableSet.builder();

    // Collect transitive module bindings and multibinding declarations.
    for (ModuleDescriptor moduleDescriptor : modules(componentDescriptor, parentResolver)) {
      explicitBindingsBuilder.addAll(moduleDescriptor.bindings());
      multibindingDeclarations.addAll(moduleDescriptor.multibindingDeclarations());
      subcomponentDeclarations.addAll(moduleDescriptor.subcomponentDeclarations());
      delegatesBuilder.addAll(moduleDescriptor.delegateDeclarations());
      optionalsBuilder.addAll(moduleDescriptor.optionalDeclarations());
    }

    final Resolver requestResolver =
        new Resolver(
            parentResolver,
            componentDescriptor,
            indexBindingDeclarationsByKey(explicitBindingsBuilder.build()),
            indexBindingDeclarationsByKey(multibindingDeclarations.build()),
            indexBindingDeclarationsByKey(subcomponentDeclarations.build()),
            indexBindingDeclarationsByKey(delegatesBuilder.build()),
            indexBindingDeclarationsByKey(optionalsBuilder.build()));

    componentDescriptor.entryPointMethods().stream()
        .map(method -> method.dependencyRequest().get())
        .forEach(
            entryPoint -> {
              if (entryPoint.kind().equals(MEMBERS_INJECTION)) {
                requestResolver.resolveMembersInjection(entryPoint.key());
              } else {
                requestResolver.resolve(entryPoint.key());
              }
            });

    if (createFullBindingGraph) {
      // Resolve the keys for all bindings in all modules, stripping any multibinding contribution
      // identifier so that the multibinding itself is resolved.
      modules(componentDescriptor, parentResolver).stream()
          .flatMap(module -> module.allBindingKeys().stream())
          .map(key -> key.toBuilder().multibindingContributionIdentifier(Optional.empty()).build())
          .forEach(requestResolver::resolve);
    }

    // Resolve all bindings for subcomponents, creating subgraphs for all subcomponents that have
    // been detected during binding resolution. If a binding for a subcomponent is never resolved,
    // no BindingGraph will be created for it and no implementation will be generated. This is
    // done in a queue since resolving one subcomponent might resolve a key for a subcomponent
    // from a parent graph. This is done until no more new subcomponents are resolved.
    Set<ComponentDescriptor> resolvedSubcomponents = new HashSet<>();
    ImmutableList.Builder<LegacyBindingGraph> subgraphs = ImmutableList.builder();
    for (ComponentDescriptor subcomponent :
        Iterables.consumingIterable(requestResolver.subcomponentsToResolve)) {
      if (resolvedSubcomponents.add(subcomponent)) {
        subgraphs.add(
            createLegacyBindingGraph(
                Optional.of(requestResolver), subcomponent, createFullBindingGraph));
      }
    }

    return new LegacyBindingGraph(
        componentDescriptor,
        ImmutableMap.copyOf(requestResolver.getResolvedContributionBindings()),
        ImmutableMap.copyOf(requestResolver.getResolvedMembersInjectionBindings()),
        ImmutableList.copyOf(subgraphs.build()));
  }

  /**
   * Returns all the modules that should be installed in the component. For production components
   * and production subcomponents that have a parent that is not a production component or
   * subcomponent, also includes the production monitoring module for the component and the
   * production executor module.
   */
  private ImmutableSet<ModuleDescriptor> modules(
      ComponentDescriptor componentDescriptor, Optional<Resolver> parentResolver) {
    return shouldIncludeImplicitProductionModules(componentDescriptor, parentResolver)
        ? new ImmutableSet.Builder<ModuleDescriptor>()
            .addAll(componentDescriptor.modules())
            .add(descriptorForMonitoringModule(componentDescriptor.typeElement()))
            .add(descriptorForProductionExecutorModule())
            .build()
        : componentDescriptor.modules();
  }

  private boolean shouldIncludeImplicitProductionModules(
      ComponentDescriptor component, Optional<Resolver> parentResolver) {
    return component.isProduction()
        && ((!component.isSubcomponent() && component.isRealComponent())
            || (parentResolver.isPresent()
                && !parentResolver.get().componentDescriptor.isProduction()));
  }

  /**
   * Returns a descriptor for a generated module that handles monitoring for production components.
   * This module is generated in the {@link
   * dagger.internal.codegen.validation.MonitoringModuleProcessingStep}.
   *
   * @throws TypeNotPresentException if the module has not been generated yet. This will cause the
   *     processor to retry in a later processing round.
   */
  private ModuleDescriptor descriptorForMonitoringModule(TypeElement componentDefinitionType) {
    return moduleDescriptorFactory.create(
        elements.checkTypePresent(
            generatedMonitoringModuleName(componentDefinitionType).toString()));
  }

  /** Returns a descriptor {@link ProductionExecutorModule}. */
  private ModuleDescriptor descriptorForProductionExecutorModule() {
    return moduleDescriptorFactory.create(elements.getTypeElement(ProductionExecutorModule.class));
  }

  /** Indexes {@code bindingDeclarations} by {@link BindingDeclaration#key()}. */
  private static <T extends BindingDeclaration>
      ImmutableSetMultimap<Key, T> indexBindingDeclarationsByKey(Iterable<T> declarations) {
    return ImmutableSetMultimap.copyOf(Multimaps.index(declarations, BindingDeclaration::key));
  }

  @Override
  public void clearCache() {
    keysMatchingRequestCache.clear();
  }

  private final class Resolver {
    final Optional<Resolver> parentResolver;
    final ComponentDescriptor componentDescriptor;
    final ImmutableSetMultimap<Key, ContributionBinding> explicitBindings;
    final ImmutableSet<ContributionBinding> explicitBindingsSet;
    final ImmutableSetMultimap<Key, ContributionBinding> explicitMultibindings;
    final ImmutableSetMultimap<Key, MultibindingDeclaration> multibindingDeclarations;
    final ImmutableSetMultimap<Key, SubcomponentDeclaration> subcomponentDeclarations;
    final ImmutableSetMultimap<Key, DelegateDeclaration> delegateDeclarations;
    final ImmutableSetMultimap<Key, OptionalBindingDeclaration> optionalBindingDeclarations;
    final ImmutableSetMultimap<Key, DelegateDeclaration> delegateMultibindingDeclarations;
    final Map<Key, ResolvedBindings> resolvedContributionBindings = new LinkedHashMap<>();
    final Map<Key, ResolvedBindings> resolvedMembersInjectionBindings = new LinkedHashMap<>();
    final Deque<Key> cycleStack = new ArrayDeque<>();
    final Map<Key, Boolean> keyDependsOnLocalBindingsCache = new HashMap<>();
    final Map<Binding, Boolean> bindingDependsOnLocalBindingsCache = new HashMap<>();
    final Queue<ComponentDescriptor> subcomponentsToResolve = new ArrayDeque<>();

    Resolver(
        Optional<Resolver> parentResolver,
        ComponentDescriptor componentDescriptor,
        ImmutableSetMultimap<Key, ContributionBinding> explicitBindings,
        ImmutableSetMultimap<Key, MultibindingDeclaration> multibindingDeclarations,
        ImmutableSetMultimap<Key, SubcomponentDeclaration> subcomponentDeclarations,
        ImmutableSetMultimap<Key, DelegateDeclaration> delegateDeclarations,
        ImmutableSetMultimap<Key, OptionalBindingDeclaration> optionalBindingDeclarations) {
      this.parentResolver = parentResolver;
      this.componentDescriptor = checkNotNull(componentDescriptor);
      this.explicitBindings = checkNotNull(explicitBindings);
      this.explicitBindingsSet = ImmutableSet.copyOf(explicitBindings.values());
      this.multibindingDeclarations = checkNotNull(multibindingDeclarations);
      this.subcomponentDeclarations = checkNotNull(subcomponentDeclarations);
      this.delegateDeclarations = checkNotNull(delegateDeclarations);
      this.optionalBindingDeclarations = checkNotNull(optionalBindingDeclarations);
      this.explicitMultibindings = multibindingContributionsByMultibindingKey(explicitBindingsSet);
      this.delegateMultibindingDeclarations =
          multibindingContributionsByMultibindingKey(delegateDeclarations.values());
      subcomponentsToResolve.addAll(
          componentDescriptor.childComponentsDeclaredByFactoryMethods().values());
      subcomponentsToResolve.addAll(
          componentDescriptor.childComponentsDeclaredByBuilderEntryPoints().values());
    }

    /**
     * Returns the resolved contribution bindings for the given {@link Key}:
     *
     * <ul>
     *   <li>All explicit bindings for:
     *       <ul>
     *         <li>the requested key
     *         <li>{@code Set<T>} if the requested key's type is {@code Set<Produced<T>>}
     *         <li>{@code Map<K, Provider<V>>} if the requested key's type is {@code Map<K,
     *             Producer<V>>}.
     *       </ul>
     *   <li>An implicit {@link Inject @Inject}-annotated constructor binding if there is one and
     *       there are no explicit bindings or synthetic bindings.
     * </ul>
     */
    ResolvedBindings lookUpBindings(Key requestKey) {
      Set<ContributionBinding> bindings = new LinkedHashSet<>();
      Set<ContributionBinding> multibindingContributions = new LinkedHashSet<>();
      Set<MultibindingDeclaration> multibindingDeclarations = new LinkedHashSet<>();
      Set<OptionalBindingDeclaration> optionalBindingDeclarations = new LinkedHashSet<>();
      Set<SubcomponentDeclaration> subcomponentDeclarations = new LinkedHashSet<>();

      // Gather all bindings, multibindings, optional, and subcomponent declarations/contributions.
      ImmutableSet<Key> keysMatchingRequest = keysMatchingRequest(requestKey);
      for (Resolver resolver : getResolverLineage()) {
        bindings.addAll(resolver.getLocalExplicitBindings(requestKey));

        for (Key key : keysMatchingRequest) {
          multibindingContributions.addAll(resolver.getLocalExplicitMultibindings(key));
          multibindingDeclarations.addAll(resolver.multibindingDeclarations.get(key));
          subcomponentDeclarations.addAll(resolver.subcomponentDeclarations.get(key));
          // The optional binding declarations are keyed by the unwrapped type.
          keyFactory.unwrapOptional(key)
              .map(resolver.optionalBindingDeclarations::get)
              .ifPresent(optionalBindingDeclarations::addAll);
        }
      }

      // Add synthetic multibinding
      if (!multibindingContributions.isEmpty() || !multibindingDeclarations.isEmpty()) {
        bindings.add(bindingFactory.syntheticMultibinding(requestKey, multibindingContributions));
      }

      // Add synthetic optional binding
      if (!optionalBindingDeclarations.isEmpty()) {
        bindings.add(
            bindingFactory.syntheticOptionalBinding(
                requestKey,
                getRequestKind(OptionalType.from(requestKey).valueType()),
                lookUpBindings(keyFactory.unwrapOptional(requestKey).get()).bindings()));
      }

      // Add subcomponent creator binding
      if (!subcomponentDeclarations.isEmpty()) {
        ProvisionBinding binding =
            bindingFactory.subcomponentCreatorBinding(
                ImmutableSet.copyOf(subcomponentDeclarations));
        bindings.add(binding);
        addSubcomponentToOwningResolver(binding);
      }

      // Add members injector binding
      if (isType(requestKey.type()) && isTypeOf(MembersInjector.class, requestKey.type())) {
        injectBindingRegistry
            .getOrFindMembersInjectorProvisionBinding(requestKey)
            .ifPresent(bindings::add);
      }

      // Add Assisted Factory binding
      if (isType(requestKey.type())
          && requestKey.type().getKind() == TypeKind.DECLARED
          && isAssistedFactoryType(asTypeElement(requestKey.type()))) {
        bindings.add(
            bindingFactory.assistedFactoryBinding(
                asTypeElement(requestKey.type()), Optional.of(requestKey.type())));
      }

      // If there are no bindings, add the implicit @Inject-constructed binding if there is one.
      if (bindings.isEmpty()) {
        injectBindingRegistry
            .getOrFindProvisionBinding(requestKey)
            .filter(this::isCorrectlyScopedInSubcomponent)
            .ifPresent(bindings::add);
      }

      return ResolvedBindings.forContributionBindings(
          requestKey,
          Multimaps.index(bindings, binding -> getOwningComponent(requestKey, binding)),
          multibindingDeclarations,
          subcomponentDeclarations,
          optionalBindingDeclarations);
    }

    /**
     * Returns true if this binding graph resolution is for a subcomponent and the {@code @Inject}
     * binding's scope correctly matches one of the components in the current component ancestry.
     * If not, it means the binding is not owned by any of the currently known components, and will
     * be owned by a future ancestor (or, if never owned, will result in an incompatibly scoped
     * binding error at the root component).
     */
    private boolean isCorrectlyScopedInSubcomponent(ProvisionBinding binding) {
      checkArgument(binding.kind() == INJECTION || binding.kind() == ASSISTED_INJECTION);
      if (!rootComponent().isSubcomponent()
          || !binding.scope().isPresent()
          || binding.scope().get().isReusable()) {
        return true;
      }

      Resolver owningResolver = getOwningResolver(binding).orElse(this);
      ComponentDescriptor owningComponent = owningResolver.componentDescriptor;
      return owningComponent.scopes().contains(binding.scope().get());
    }

    private ComponentDescriptor rootComponent() {
      return parentResolver.map(Resolver::rootComponent).orElse(componentDescriptor);
    }

    /** Returns the resolved members injection bindings for the given {@link Key}. */
    ResolvedBindings lookUpMembersInjectionBinding(Key requestKey) {
      // no explicit deps for members injection, so just look it up
      Optional<MembersInjectionBinding> binding =
          injectBindingRegistry.getOrFindMembersInjectionBinding(requestKey);
      return binding.isPresent()
          ? ResolvedBindings.forMembersInjectionBinding(
              requestKey, componentDescriptor, binding.get())
          : ResolvedBindings.noBindings(requestKey);
    }

    /**
     * When a binding is resolved for a {@link SubcomponentDeclaration}, adds corresponding {@link
     * ComponentDescriptor subcomponent} to a queue in the owning component's resolver. The queue
     * will be used to detect which subcomponents need to be resolved.
     */
    private void addSubcomponentToOwningResolver(ProvisionBinding subcomponentCreatorBinding) {
      checkArgument(subcomponentCreatorBinding.kind().equals(SUBCOMPONENT_CREATOR));
      Resolver owningResolver = getOwningResolver(subcomponentCreatorBinding).get();

      TypeElement builderType = MoreTypes.asTypeElement(subcomponentCreatorBinding.key().type());
      owningResolver.subcomponentsToResolve.add(
          owningResolver.componentDescriptor.getChildComponentWithBuilderType(builderType));
    }

    /**
     * Profiling has determined that computing the keys matching {@code requestKey} has measurable
     * performance impact. It is called repeatedly (at least 3 times per key resolved per {@link
     * BindingGraph}. {@code javac}'s name-checking performance seems suboptimal (converting byte
     * strings to Strings repeatedly), and the matching keys creations relies on that. This also
     * ensures that the resulting keys have their hash codes cached on successive calls to this
     * method.
     *
     * <p>This caching may become obsolete if:
     *
     * <ul>
     *   <li>We decide to intern all {@link Key} instances
     *   <li>We fix javac's name-checking peformance (though we may want to keep this for older
     *       javac users)
     * </ul>
     */
    private ImmutableSet<Key> keysMatchingRequest(Key requestKey) {
      return keysMatchingRequestCache.computeIfAbsent(
          requestKey, this::keysMatchingRequestUncached);
    }

    private ImmutableSet<Key> keysMatchingRequestUncached(Key requestKey) {
      ImmutableSet.Builder<Key> keys = ImmutableSet.builder();
      keys.add(requestKey);
      keyFactory.unwrapSetKey(requestKey, Produced.class).ifPresent(keys::add);
      keyFactory.rewrapMapKey(requestKey, Producer.class, Provider.class).ifPresent(keys::add);
      keyFactory.rewrapMapKey(requestKey, Provider.class, Producer.class).ifPresent(keys::add);
      keys.addAll(keyFactory.implicitFrameworkMapKeys(requestKey));
      return keys.build();
    }

    private ImmutableSet<ContributionBinding> createDelegateBindings(
        ImmutableSet<DelegateDeclaration> delegateDeclarations) {
      ImmutableSet.Builder<ContributionBinding> builder = ImmutableSet.builder();
      for (DelegateDeclaration delegateDeclaration : delegateDeclarations) {
        builder.add(createDelegateBinding(delegateDeclaration));
      }
      return builder.build();
    }

    /**
     * Creates one (and only one) delegate binding for a delegate declaration, based on the resolved
     * bindings of the right-hand-side of a {@link dagger.Binds} method. If there are duplicate
     * bindings for the dependency key, there should still be only one binding for the delegate key.
     */
    private ContributionBinding createDelegateBinding(DelegateDeclaration delegateDeclaration) {
      Key delegateKey = delegateDeclaration.delegateRequest().key();
      if (cycleStack.contains(delegateKey)) {
        return bindingFactory.unresolvedDelegateBinding(delegateDeclaration);
      }

      ResolvedBindings resolvedDelegate;
      try {
        cycleStack.push(delegateKey);
        resolvedDelegate = lookUpBindings(delegateKey);
      } finally {
        cycleStack.pop();
      }
      if (resolvedDelegate.contributionBindings().isEmpty()) {
        // This is guaranteed to result in a missing binding error, so it doesn't matter if the
        // binding is a Provision or Production, except if it is a @IntoMap method, in which
        // case the key will be of type Map<K, Provider<V>>, which will be "upgraded" into a
        // Map<K, Producer<V>> if it's requested in a ProductionComponent. This may result in a
        // strange error, that the RHS needs to be provided with an @Inject or @Provides
        // annotated method, but a user should be able to figure out if a @Produces annotation
        // is needed.
        // TODO(gak): revisit how we model missing delegates if/when we clean up how we model
        // binding declarations
        return bindingFactory.unresolvedDelegateBinding(delegateDeclaration);
      }
      // It doesn't matter which of these is selected, since they will later on produce a
      // duplicate binding error.
      ContributionBinding explicitDelegate =
          resolvedDelegate.contributionBindings().iterator().next();
      return bindingFactory.delegateBinding(delegateDeclaration, explicitDelegate);
    }

    /**
     * Returns the component that should contain the framework field for {@code binding}.
     *
     * <p>If {@code binding} is either not bound in an ancestor component or depends transitively on
     * bindings in this component, returns this component.
     *
     * <p>Otherwise, resolves {@code request} in this component's parent in order to resolve any
     * multibinding contributions in the parent, and returns the parent-resolved {@link
     * ResolvedBindings#owningComponent(ContributionBinding)}.
     */
    private TypeElement getOwningComponent(Key requestKey, ContributionBinding binding) {
      if (isResolvedInParent(requestKey, binding)
          && !new LocalDependencyChecker().dependsOnLocalBindings(binding)) {
        ResolvedBindings parentResolvedBindings =
            parentResolver.get().resolvedContributionBindings.get(requestKey);
        return parentResolvedBindings.owningComponent(binding);
      } else {
        return componentDescriptor.typeElement();
      }
    }

    /**
     * Returns {@code true} if {@code binding} is owned by an ancestor. If so, {@linkplain #resolve
     * resolves} the {@link Key} in this component's parent. Don't resolve directly in the owning
     * component in case it depends on multibindings in any of its descendants.
     */
    private boolean isResolvedInParent(Key requestKey, ContributionBinding binding) {
      Optional<Resolver> owningResolver = getOwningResolver(binding);
      if (owningResolver.isPresent() && !owningResolver.get().equals(this)) {
        parentResolver.get().resolve(requestKey);
        return true;
      } else {
        return false;
      }
    }

    private Optional<Resolver> getOwningResolver(ContributionBinding binding) {
      // TODO(ronshapiro): extract the different pieces of this method into their own methods
      if ((binding.scope().isPresent() && binding.scope().get().isProductionScope())
          || binding.bindingType().equals(BindingType.PRODUCTION)) {
        for (Resolver requestResolver : getResolverLineage()) {
          // Resolve @Inject @ProductionScope bindings at the highest production component.
          if (binding.kind().equals(INJECTION)
              && requestResolver.componentDescriptor.isProduction()) {
            return Optional.of(requestResolver);
          }

          // Resolve explicit @Produces and @ProductionScope bindings at the highest component that
          // installs the binding.
          if (requestResolver.containsExplicitBinding(binding)) {
            return Optional.of(requestResolver);
          }
        }
      }

      if (binding.scope().isPresent() && binding.scope().get().isReusable()) {
        for (Resolver requestResolver : getResolverLineage().reverse()) {
          // If a @Reusable binding was resolved in an ancestor, use that component.
          ResolvedBindings resolvedBindings =
              requestResolver.resolvedContributionBindings.get(binding.key());
          if (resolvedBindings != null
              && resolvedBindings.contributionBindings().contains(binding)) {
            return Optional.of(requestResolver);
          }
        }
        // If a @Reusable binding was not resolved in any ancestor, resolve it here.
        return Optional.empty();
      }

      for (Resolver requestResolver : getResolverLineage().reverse()) {
        if (requestResolver.containsExplicitBinding(binding)) {
          return Optional.of(requestResolver);
        }
      }

      // look for scope separately.  we do this for the case where @Singleton can appear twice
      // in the † compatibility mode
      Optional<Scope> bindingScope = binding.scope();
      if (bindingScope.isPresent()) {
        for (Resolver requestResolver : getResolverLineage().reverse()) {
          if (requestResolver.componentDescriptor.scopes().contains(bindingScope.get())) {
            return Optional.of(requestResolver);
          }
        }
      }
      return Optional.empty();
    }

    private boolean containsExplicitBinding(ContributionBinding binding) {
      return explicitBindingsSet.contains(binding)
          || resolverContainsDelegateDeclarationForBinding(binding)
          || subcomponentDeclarations.containsKey(binding.key());
    }

    /** Returns true if {@code binding} was installed in a module in this resolver's component. */
    private boolean resolverContainsDelegateDeclarationForBinding(ContributionBinding binding) {
      if (!binding.kind().equals(DELEGATE)) {
        return false;
      }

      // Map multibinding key values are wrapped with a framework type. This needs to be undone
      // to look it up in the delegate declarations map.
      // TODO(erichang): See if we can standardize the way map keys are used in these data
      // structures, either always wrapped or unwrapped to be consistent and less errorprone.
      Key bindingKey = binding.key();
      if (compilerOptions.strictMultibindingValidation()
          && binding.contributionType().equals(ContributionType.MAP)) {
        bindingKey = keyFactory.unwrapMapValueType(bindingKey);
      }

      return delegateDeclarations.get(bindingKey).stream()
          .anyMatch(
              declaration ->
                  declaration.contributingModule().equals(binding.contributingModule())
                  && declaration.bindingElement().equals(binding.bindingElement()));
    }

    /** Returns the resolver lineage from parent to child. */
    private ImmutableList<Resolver> getResolverLineage() {
      ImmutableList.Builder<Resolver> resolverList = ImmutableList.builder();
      for (Optional<Resolver> currentResolver = Optional.of(this);
          currentResolver.isPresent();
          currentResolver = currentResolver.get().parentResolver) {
        resolverList.add(currentResolver.get());
      }
      return resolverList.build().reverse();
    }

    /**
     * Returns the explicit {@link ContributionBinding}s that match the {@code key} from this
     * resolver.
     */
    private ImmutableSet<ContributionBinding> getLocalExplicitBindings(Key key) {
      return new ImmutableSet.Builder<ContributionBinding>()
          .addAll(explicitBindings.get(key))
          // @Binds @IntoMap declarations have key Map<K, V>, unlike @Provides @IntoMap or @Produces
          // @IntoMap, which have Map<K, Provider/Producer<V>> keys. So unwrap the key's type's
          // value type if it's a Map<K, Provider/Producer<V>> before looking in
          // delegateDeclarations. createDelegateBindings() will create bindings with the properly
          // wrapped key type.
          .addAll(
              createDelegateBindings(delegateDeclarations.get(keyFactory.unwrapMapValueType(key))))
          .build();
    }

    /**
     * Returns the explicit multibinding contributions that contribute to the map or set requested
     * by {@code key} from this resolver.
     */
    private ImmutableSet<ContributionBinding> getLocalExplicitMultibindings(Key key) {
      ImmutableSet.Builder<ContributionBinding> multibindings = ImmutableSet.builder();
      multibindings.addAll(explicitMultibindings.get(key));
      if (!MapType.isMap(key)
          || MapType.from(key).isRawType()
          || MapType.from(key).valuesAreFrameworkType()) {
        // @Binds @IntoMap declarations have key Map<K, V>, unlike @Provides @IntoMap or @Produces
        // @IntoMap, which have Map<K, Provider/Producer<V>> keys. So unwrap the key's type's
        // value type if it's a Map<K, Provider/Producer<V>> before looking in
        // delegateMultibindingDeclarations. createDelegateBindings() will create bindings with the
        // properly wrapped key type.
        multibindings.addAll(
            createDelegateBindings(
                delegateMultibindingDeclarations.get(keyFactory.unwrapMapValueType(key))));
      }
      return multibindings.build();
    }

    /**
     * Returns the {@link OptionalBindingDeclaration}s that match the {@code key} from this and all
     * ancestor resolvers.
     */
    private ImmutableSet<OptionalBindingDeclaration> getOptionalBindingDeclarations(Key key) {
      Optional<Key> unwrapped = keyFactory.unwrapOptional(key);
      if (!unwrapped.isPresent()) {
        return ImmutableSet.of();
      }
      ImmutableSet.Builder<OptionalBindingDeclaration> declarations = ImmutableSet.builder();
      for (Resolver resolver : getResolverLineage()) {
        declarations.addAll(resolver.optionalBindingDeclarations.get(unwrapped.get()));
      }
      return declarations.build();
    }

    /**
     * Returns the {@link ResolvedBindings} for {@code key} that was resolved in this resolver or an
     * ancestor resolver. Only checks for {@link ContributionBinding}s as {@link
     * MembersInjectionBinding}s are not inherited.
     */
    private Optional<ResolvedBindings> getPreviouslyResolvedBindings(Key key) {
      Optional<ResolvedBindings> result =
          Optional.ofNullable(resolvedContributionBindings.get(key));
      if (result.isPresent()) {
        return result;
      } else if (parentResolver.isPresent()) {
        return parentResolver.get().getPreviouslyResolvedBindings(key);
      } else {
        return Optional.empty();
      }
    }

    private void resolveMembersInjection(Key key) {
      ResolvedBindings bindings = lookUpMembersInjectionBinding(key);
      resolveDependencies(bindings);
      resolvedMembersInjectionBindings.put(key, bindings);
    }

    void resolve(Key key) {
      // If we find a cycle, stop resolving. The original request will add it with all of the
      // other resolved deps.
      if (cycleStack.contains(key)) {
        return;
      }

      // If the binding was previously resolved in this (sub)component, don't resolve it again.
      if (resolvedContributionBindings.containsKey(key)) {
        return;
      }

      /*
       * If the binding was previously resolved in an ancestor component, then we may be able to
       * avoid resolving it here and just depend on the ancestor component resolution.
       *
       * 1. If it depends transitively on multibinding contributions or optional bindings with
       *    bindings from this subcomponent, then we have to resolve it in this subcomponent so
       *    that it sees the local bindings.
       *
       * 2. If there are any explicit bindings in this component, they may conflict with those in
       *    the ancestor component, so resolve them here so that conflicts can be caught.
       */
      if (getPreviouslyResolvedBindings(key).isPresent()) {
        /* Resolve in the parent in case there are multibinding contributions or conflicts in some
         * component between this one and the previously-resolved one. */
        parentResolver.get().resolve(key);
        if (!new LocalDependencyChecker().dependsOnLocalBindings(key)
            && getLocalExplicitBindings(key).isEmpty()) {
          /* Cache the inherited parent component's bindings in case resolving at the parent found
           * bindings in some component between this one and the previously-resolved one. */
          resolvedContributionBindings.put(key, getPreviouslyResolvedBindings(key).get());
          return;
        }
      }

      cycleStack.push(key);
      try {
        ResolvedBindings bindings = lookUpBindings(key);
        resolvedContributionBindings.put(key, bindings);
        resolveDependencies(bindings);
      } finally {
        cycleStack.pop();
      }
    }

    /**
     * {@link #resolve(Key) Resolves} each of the dependencies of the bindings owned by this
     * component.
     */
    private void resolveDependencies(ResolvedBindings resolvedBindings) {
      for (Binding binding : resolvedBindings.bindingsOwnedBy(componentDescriptor)) {
        for (DependencyRequest dependency : binding.dependencies()) {
          resolve(dependency.key());
        }
      }
    }

    /**
     * Returns all of the {@link ResolvedBindings} for {@link ContributionBinding}s from this and
     * all ancestor resolvers, indexed by {@link ResolvedBindings#key()}.
     */
    Map<Key, ResolvedBindings> getResolvedContributionBindings() {
      Map<Key, ResolvedBindings> bindings = new LinkedHashMap<>();
      parentResolver.ifPresent(parent -> bindings.putAll(parent.getResolvedContributionBindings()));
      bindings.putAll(resolvedContributionBindings);
      return bindings;
    }

    /**
     * Returns all of the {@link ResolvedBindings} for {@link MembersInjectionBinding} from this
     * resolvers, indexed by {@link ResolvedBindings#key()}.
     */
    ImmutableMap<Key, ResolvedBindings> getResolvedMembersInjectionBindings() {
      return ImmutableMap.copyOf(resolvedMembersInjectionBindings);
    }

    private final class LocalDependencyChecker {
      private final Set<Object> cycleChecker = new HashSet<>();

      /**
       * Returns {@code true} if any of the bindings resolved for {@code key} are multibindings with
       * contributions declared within this component's modules or optional bindings with present
       * values declared within this component's modules, or if any of its unscoped dependencies
       * depend on such bindings.
       *
       * <p>We don't care about scoped dependencies because they will never depend on bindings from
       * subcomponents.
       *
       * @throws IllegalArgumentException if {@link #getPreviouslyResolvedBindings(Key)} is empty
       */
      private boolean dependsOnLocalBindings(Key key) {
        // Don't recur infinitely if there are valid cycles in the dependency graph.
        // http://b/23032377
        if (!cycleChecker.add(key)) {
          return false;
        }
        return reentrantComputeIfAbsent(
            keyDependsOnLocalBindingsCache, key, this::dependsOnLocalBindingsUncached);
      }

      /**
       * Returns {@code true} if {@code binding} is unscoped (or has {@link Reusable @Reusable}
       * scope) and depends on multibindings with contributions declared within this component's
       * modules, or if any of its unscoped or {@link Reusable @Reusable} scoped dependencies depend
       * on such local multibindings.
       *
       * <p>We don't care about non-reusable scoped dependencies because they will never depend on
       * multibindings with contributions from subcomponents.
       */
      private boolean dependsOnLocalBindings(Binding binding) {
        if (!cycleChecker.add(binding)) {
          return false;
        }
        return reentrantComputeIfAbsent(
            bindingDependsOnLocalBindingsCache, binding, this::dependsOnLocalBindingsUncached);
      }

      private boolean dependsOnLocalBindingsUncached(Key key) {
        checkArgument(
            getPreviouslyResolvedBindings(key).isPresent(),
            "no previously resolved bindings in %s for %s",
            Resolver.this,
            key);
        ResolvedBindings previouslyResolvedBindings = getPreviouslyResolvedBindings(key).get();
        if (hasLocalMultibindingContributions(key)
            || hasLocalOptionalBindingContribution(previouslyResolvedBindings)) {
          return true;
        }

        for (Binding binding : previouslyResolvedBindings.bindings()) {
          if (dependsOnLocalBindings(binding)) {
            return true;
          }
        }
        return false;
      }

      private boolean dependsOnLocalBindingsUncached(Binding binding) {
        if ((!binding.scope().isPresent() || binding.scope().get().isReusable())
            // TODO(beder): Figure out what happens with production subcomponents.
            && !binding.bindingType().equals(BindingType.PRODUCTION)) {
          for (DependencyRequest dependency : binding.dependencies()) {
            if (dependsOnLocalBindings(dependency.key())) {
              return true;
            }
          }
        }
        return false;
      }

      /**
       * Returns {@code true} if there is at least one multibinding contribution declared within
       * this component's modules that matches the key.
       */
      private boolean hasLocalMultibindingContributions(Key requestKey) {
        return keysMatchingRequest(requestKey)
            .stream()
            .anyMatch(key -> !getLocalExplicitMultibindings(key).isEmpty());
      }

      /**
       * Returns {@code true} if there is a contribution in this component for an {@code
       * Optional<Foo>} key that has not been contributed in a parent.
       */
      private boolean hasLocalOptionalBindingContribution(ResolvedBindings resolvedBindings) {
        if (resolvedBindings
            .contributionBindings()
            .stream()
            .map(ContributionBinding::kind)
            .anyMatch(isEqual(OPTIONAL))) {
          return !getLocalExplicitBindings(keyFactory.unwrapOptional(resolvedBindings.key()).get())
              .isEmpty();
        } else {
          // If a parent contributes a @Provides Optional<Foo> binding and a child has a
          // @BindsOptionalOf Foo method, the two should conflict, even if there is no binding for
          // Foo on its own
          return !getOptionalBindingDeclarations(resolvedBindings.key()).isEmpty();
        }
      }
    }
  }

  /**
   * A multimap of those {@code declarations} that are multibinding contribution declarations,
   * indexed by the key of the set or map to which they contribute.
   */
  static <T extends BindingDeclaration>
      ImmutableSetMultimap<Key, T> multibindingContributionsByMultibindingKey(
          Iterable<T> declarations) {
    ImmutableSetMultimap.Builder<Key, T> builder = ImmutableSetMultimap.builder();
    for (T declaration : declarations) {
      if (declaration.key().multibindingContributionIdentifier().isPresent()) {
        builder.put(
            declaration
                .key()
                .toBuilder()
                .multibindingContributionIdentifier(Optional.empty())
                .build(),
            declaration);
      }
    }
    return builder.build();
  }
}

/*
 * Copyright (C) 2016 The Dagger Authors.
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

package dagger.internal.codegen.writing;

import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.base.Preconditions.checkNotNull;
import static com.google.common.base.Verify.verify;
import static dagger.internal.codegen.binding.BindingRequest.bindingRequest;
import static dagger.internal.codegen.extension.DaggerCollectors.toOptional;
import static dagger.internal.codegen.javapoet.CodeBlocks.makeParametersCodeBlock;
import static dagger.internal.codegen.javapoet.TypeNames.DOUBLE_CHECK;
import static dagger.internal.codegen.javapoet.TypeNames.SINGLE_CHECK;
import static dagger.internal.codegen.langmodel.Accessibility.isRawTypeAccessible;
import static dagger.internal.codegen.langmodel.Accessibility.isTypeAccessibleFrom;
import static dagger.internal.codegen.writing.DelegateBindingExpression.isBindsScopeStrongerThanDependencyScope;
import static dagger.internal.codegen.writing.MemberSelect.staticFactoryCreation;
import static dagger.model.BindingKind.DELEGATE;
import static dagger.model.BindingKind.MULTIBOUND_MAP;
import static dagger.model.BindingKind.MULTIBOUND_SET;

import com.google.auto.common.MoreTypes;
import com.google.common.collect.ImmutableList;
import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.CodeBlock;
import com.squareup.javapoet.MethodSpec;
import dagger.internal.codegen.binding.Binding;
import dagger.internal.codegen.binding.BindingGraph;
import dagger.internal.codegen.binding.BindingNode;
import dagger.internal.codegen.binding.BindingRequest;
import dagger.internal.codegen.binding.BindingType;
import dagger.internal.codegen.binding.ComponentDescriptor.ComponentMethodDescriptor;
import dagger.internal.codegen.binding.ComponentRequirement;
import dagger.internal.codegen.binding.ContributionBinding;
import dagger.internal.codegen.binding.FrameworkType;
import dagger.internal.codegen.binding.FrameworkTypeMapper;
import dagger.internal.codegen.binding.MembersInjectionBinding;
import dagger.internal.codegen.binding.ProvisionBinding;
import dagger.internal.codegen.compileroption.CompilerOptions;
import dagger.internal.codegen.javapoet.Expression;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.internal.codegen.writing.FrameworkFieldInitializer.FrameworkInstanceCreationExpression;
import dagger.internal.codegen.writing.MethodBindingExpression.MethodImplementationStrategy;
import dagger.model.BindingKind;
import dagger.model.DependencyRequest;
import dagger.model.Key;
import dagger.model.RequestKind;
import java.util.HashMap;
import java.util.Map;
import java.util.Optional;
import javax.inject.Inject;
import javax.inject.Provider;
import javax.lang.model.SourceVersion;
import javax.lang.model.type.TypeMirror;

/** A central repository of code expressions used to access any binding available to a component. */
@PerComponentImplementation
public final class ComponentBindingExpressions {
  // TODO(dpb,ronshapiro): refactor this and ComponentRequirementExpressions into a
  // HierarchicalComponentMap<K, V>, or perhaps this use a flattened ImmutableMap, built from its
  // parents? If so, maybe make BindingExpression.Factory create it.

  private final Optional<ComponentBindingExpressions> parent;
  private final BindingGraph graph;
  private final ComponentImplementation componentImplementation;
  private final ComponentImplementation topLevelComponentImplementation;
  private final ComponentRequirementExpressions componentRequirementExpressions;
  private final OptionalFactories optionalFactories;
  private final DaggerTypes types;
  private final DaggerElements elements;
  private final SourceVersion sourceVersion;
  private final CompilerOptions compilerOptions;
  private final MembersInjectionMethods membersInjectionMethods;
  private final InnerSwitchingProviders innerSwitchingProviders;
  private final Map<BindingRequest, BindingExpression> expressions = new HashMap<>();
  private final KotlinMetadataUtil metadataUtil;

  @Inject
  ComponentBindingExpressions(
      @ParentComponent Optional<ComponentBindingExpressions> parent,
      BindingGraph graph,
      ComponentImplementation componentImplementation,
      @TopLevel ComponentImplementation topLevelComponentImplementation,
      ComponentRequirementExpressions componentRequirementExpressions,
      OptionalFactories optionalFactories,
      DaggerTypes types,
      DaggerElements elements,
      SourceVersion sourceVersion,
      CompilerOptions compilerOptions,
      KotlinMetadataUtil metadataUtil) {
    this.parent = parent;
    this.graph = graph;
    this.componentImplementation = componentImplementation;
    this.topLevelComponentImplementation = topLevelComponentImplementation;
    this.componentRequirementExpressions = checkNotNull(componentRequirementExpressions);
    this.optionalFactories = checkNotNull(optionalFactories);
    this.types = checkNotNull(types);
    this.elements = checkNotNull(elements);
    this.sourceVersion = checkNotNull(sourceVersion);
    this.compilerOptions = checkNotNull(compilerOptions);
    this.membersInjectionMethods =
        new MembersInjectionMethods(
            componentImplementation, this, graph, elements, types, metadataUtil);
    this.innerSwitchingProviders =
        new InnerSwitchingProviders(componentImplementation, this, types);
    this.metadataUtil = metadataUtil;
  }

  /**
   * Returns an expression that evaluates to the value of a binding request for a binding owned by
   * this component or an ancestor.
   *
   * @param requestingClass the class that will contain the expression
   * @throws IllegalStateException if there is no binding expression that satisfies the request
   */
  public Expression getDependencyExpression(BindingRequest request, ClassName requestingClass) {
    return getBindingExpression(request).getDependencyExpression(requestingClass);
  }

  /**
   * Equivalent to {@link #getDependencyExpression(BindingRequest, ClassName)} that is used only
   * when the request is for implementation of a component method.
   *
   * @throws IllegalStateException if there is no binding expression that satisfies the request
   */
  Expression getDependencyExpressionForComponentMethod(
      BindingRequest request,
      ComponentMethodDescriptor componentMethod,
      ComponentImplementation componentImplementation) {
    return getBindingExpression(request)
        .getDependencyExpressionForComponentMethod(componentMethod, componentImplementation);
  }

  /**
   * Returns the {@link CodeBlock} for the method arguments used with the factory {@code create()}
   * method for the given {@link ContributionBinding binding}.
   */
  CodeBlock getCreateMethodArgumentsCodeBlock(ContributionBinding binding) {
    return makeParametersCodeBlock(getCreateMethodArgumentsCodeBlocks(binding));
  }

  private ImmutableList<CodeBlock> getCreateMethodArgumentsCodeBlocks(ContributionBinding binding) {
    ImmutableList.Builder<CodeBlock> arguments = ImmutableList.builder();

    if (binding.requiresModuleInstance()) {
      arguments.add(
          componentRequirementExpressions.getExpressionDuringInitialization(
              ComponentRequirement.forModule(binding.contributingModule().get().asType()),
              componentImplementation.name()));
    }

    binding.dependencies().stream()
        .map(dependency -> frameworkRequest(binding, dependency))
        .map(request -> getDependencyExpression(request, componentImplementation.name()))
        .map(Expression::codeBlock)
        .forEach(arguments::add);

    return arguments.build();
  }

  private static BindingRequest frameworkRequest(
      ContributionBinding binding, DependencyRequest dependency) {
    // TODO(bcorso): See if we can get rid of FrameworkTypeMatcher
    FrameworkType frameworkType =
        FrameworkTypeMapper.forBindingType(binding.bindingType())
            .getFrameworkType(dependency.kind());
    return BindingRequest.bindingRequest(dependency.key(), frameworkType);
  }

  /**
   * Returns an expression that evaluates to the value of a dependency request, for passing to a
   * binding method, an {@code @Inject}-annotated constructor or member, or a proxy for one.
   *
   * <p>If the method is a generated static {@link InjectionMethods injection method}, each
   * parameter will be {@link Object} if the dependency's raw type is inaccessible. If that is the
   * case for this dependency, the returned expression will use a cast to evaluate to the raw type.
   *
   * @param requestingClass the class that will contain the expression
   */
  Expression getDependencyArgumentExpression(
      DependencyRequest dependencyRequest, ClassName requestingClass) {

    TypeMirror dependencyType = dependencyRequest.key().type();
    BindingRequest bindingRequest = bindingRequest(dependencyRequest);
    Expression dependencyExpression = getDependencyExpression(bindingRequest, requestingClass);

    if (dependencyRequest.kind().equals(RequestKind.INSTANCE)
        && !isTypeAccessibleFrom(dependencyType, requestingClass.packageName())
        && isRawTypeAccessible(dependencyType, requestingClass.packageName())) {
      return dependencyExpression.castTo(types.erasure(dependencyType));
    }

    return dependencyExpression;
  }

  /** Returns the implementation of a component method. */
  public MethodSpec getComponentMethod(ComponentMethodDescriptor componentMethod) {
    checkArgument(componentMethod.dependencyRequest().isPresent());
    BindingRequest request = bindingRequest(componentMethod.dependencyRequest().get());
    MethodSpec.Builder method =
        MethodSpec.overriding(
            componentMethod.methodElement(),
            MoreTypes.asDeclared(graph.componentTypeElement().asType()),
            types);
    // Even though this is not used if the method is abstract, we need to invoke the binding
    // expression in order for the side of effect of the method being added to the
    // ComponentImplementation
    CodeBlock methodBody =
        getBindingExpression(request)
            .getComponentMethodImplementation(componentMethod, componentImplementation);

    return method.addCode(methodBody).build();
  }

  /** Returns the {@link BindingExpression} for the given {@link BindingRequest}. */
  BindingExpression getBindingExpression(BindingRequest request) {
    if (expressions.containsKey(request)) {
      return expressions.get(request);
    }

    Optional<Binding> optionalBinding =
        graph.bindingNodes(request.key()).stream()
            // Filter out nodes we don't own.
            .filter(bindingNode -> bindingNode.componentPath().equals(graph.componentPath()))
            // Filter out nodes that don't match the request kind
            .filter(
                bindingNode ->
                    // The binding used for the binding expression depends on the request:
                    //   1. MembersInjectionBinding: satisfies MEMBERS_INJECTION requests
                    //   2. ContributionBindings: satisfies all other requests.
                    request.isRequestKind(RequestKind.MEMBERS_INJECTION)
                        ? bindingNode.delegate().bindingType() == BindingType.MEMBERS_INJECTION
                        : bindingNode.delegate().bindingType() == BindingType.PROVISION
                            || bindingNode.delegate().bindingType() == BindingType.PRODUCTION)
            .map(BindingNode::delegate)
            // We expect at most one binding to match since this graph is already validated.
            .collect(toOptional());

    if (optionalBinding.isPresent()) {
      BindingExpression expression = createBindingExpression(optionalBinding.get(), request);
      expressions.put(request, expression);
      return expression;
    }

    checkArgument(parent.isPresent(), "no expression found for %s", request);
    return parent.get().getBindingExpression(request);
  }

  /** Creates a binding expression. */
  private BindingExpression createBindingExpression(Binding binding, BindingRequest request) {
    switch (binding.bindingType()) {
      case MEMBERS_INJECTION:
        checkArgument(request.isRequestKind(RequestKind.MEMBERS_INJECTION));
        return new MembersInjectionBindingExpression(
            (MembersInjectionBinding) binding, membersInjectionMethods);

      case PROVISION:
        return provisionBindingExpression((ContributionBinding) binding, request);

      case PRODUCTION:
        return productionBindingExpression((ContributionBinding) binding, request);
    }
    throw new AssertionError(binding);
  }

  /**
   * Returns a binding expression that uses a {@link javax.inject.Provider} for provision bindings
   * or a {@link dagger.producers.Producer} for production bindings.
   */
  private BindingExpression frameworkInstanceBindingExpression(ContributionBinding binding) {
    // TODO(bcorso): Consider merging the static factory creation logic into CreationExpressions?
    Optional<MemberSelect> staticMethod =
        useStaticFactoryCreation(binding) ? staticFactoryCreation(binding) : Optional.empty();
    FrameworkInstanceSupplier frameworkInstanceSupplier =
        staticMethod.isPresent()
            ? staticMethod::get
            : new FrameworkFieldInitializer(
                  componentImplementation,
                  binding,
                  binding.scope().isPresent()
                      ? scope(binding, frameworkInstanceCreationExpression(binding))
                      : frameworkInstanceCreationExpression(binding));

    switch (binding.bindingType()) {
      case PROVISION:
        return new ProviderInstanceBindingExpression(
            binding, frameworkInstanceSupplier, types, elements);
      case PRODUCTION:
        return new ProducerNodeInstanceBindingExpression(
            binding, frameworkInstanceSupplier, types, elements, componentImplementation);
      default:
        throw new AssertionError("invalid binding type: " + binding.bindingType());
    }
  }

  private FrameworkInstanceCreationExpression scope(
      ContributionBinding binding, FrameworkInstanceCreationExpression unscoped) {
    return () ->
        CodeBlock.of(
            "$T.provider($L)",
            binding.scope().get().isReusable() ? SINGLE_CHECK : DOUBLE_CHECK,
            unscoped.creationExpression());
  }

  /**
   * Returns a creation expression for a {@link javax.inject.Provider} for provision bindings or a
   * {@link dagger.producers.Producer} for production bindings.
   */
  private FrameworkInstanceCreationExpression frameworkInstanceCreationExpression(
      ContributionBinding binding) {
    switch (binding.kind()) {
      case COMPONENT:
        // The cast can be removed when we drop java 7 source support
        return new InstanceFactoryCreationExpression(
            () -> CodeBlock.of("($T) this", binding.key().type()));

      case BOUND_INSTANCE:
        return instanceFactoryCreationExpression(
            binding, ComponentRequirement.forBoundInstance(binding));

      case COMPONENT_DEPENDENCY:
        return instanceFactoryCreationExpression(
            binding, ComponentRequirement.forDependency(binding.key().type()));

      case COMPONENT_PROVISION:
        return new DependencyMethodProviderCreationExpression(
            binding,
            componentImplementation,
            componentRequirementExpressions,
            compilerOptions,
            graph);

      case SUBCOMPONENT_CREATOR:
        return new AnonymousProviderCreationExpression(
            binding, this, componentImplementation.name());

      case ASSISTED_FACTORY:
      case ASSISTED_INJECTION:
      case INJECTION:
      case PROVISION:
        return new InjectionOrProvisionProviderCreationExpression(binding, this);

      case COMPONENT_PRODUCTION:
        return new DependencyMethodProducerCreationExpression(
            binding, componentImplementation, componentRequirementExpressions, graph);

      case PRODUCTION:
        return new ProducerCreationExpression(binding, this);

      case MULTIBOUND_SET:
        return new SetFactoryCreationExpression(binding, componentImplementation, this, graph);

      case MULTIBOUND_MAP:
        return new MapFactoryCreationExpression(
            binding, componentImplementation, this, graph, elements);

      case DELEGATE:
        return new DelegatingFrameworkInstanceCreationExpression(
            binding, componentImplementation, this);

      case OPTIONAL:
        return new OptionalFactoryInstanceCreationExpression(
            optionalFactories, binding, componentImplementation, this);

      case MEMBERS_INJECTOR:
        return new MembersInjectorProviderCreationExpression((ProvisionBinding) binding, this);

      default:
        throw new AssertionError(binding);
    }
  }

  private InstanceFactoryCreationExpression instanceFactoryCreationExpression(
      ContributionBinding binding, ComponentRequirement componentRequirement) {
    return new InstanceFactoryCreationExpression(
        binding.nullableType().isPresent(),
        () ->
            componentRequirementExpressions.getExpressionDuringInitialization(
                componentRequirement, componentImplementation.name()));
  }

  /** Returns a binding expression for a provision binding. */
  private BindingExpression provisionBindingExpression(
      ContributionBinding binding, BindingRequest request) {
    if (!request.requestKind().isPresent()) {
      verify(
          request.frameworkType().get().equals(FrameworkType.PRODUCER_NODE),
          "expected a PRODUCER_NODE: %s",
          request);
      return producerFromProviderBindingExpression(binding);
    }
    RequestKind requestKind = request.requestKind().get();
    Key key = request.key();
    switch (requestKind) {
      case INSTANCE:
        return instanceBindingExpression(binding);

      case PROVIDER:
        return providerBindingExpression(binding);

      case LAZY:
      case PRODUCED:
      case PROVIDER_OF_LAZY:
        return new DerivedFromFrameworkInstanceBindingExpression(
            key, FrameworkType.PROVIDER, requestKind, this, types);

      case PRODUCER:
        return producerFromProviderBindingExpression(binding);

      case FUTURE:
        return new ImmediateFutureBindingExpression(key, this, types, sourceVersion);

      case MEMBERS_INJECTION:
        throw new IllegalArgumentException();
    }

    throw new AssertionError();
  }

  /** Returns a binding expression for a production binding. */
  private BindingExpression productionBindingExpression(
      ContributionBinding binding, BindingRequest request) {
    if (request.frameworkType().isPresent()) {
      return frameworkInstanceBindingExpression(binding);
    } else {
      // If no FrameworkType is present, a RequestKind is guaranteed to be present.
      RequestKind requestKind = request.requestKind().get();
      return new DerivedFromFrameworkInstanceBindingExpression(
          request.key(), FrameworkType.PRODUCER_NODE, requestKind, this, types);
    }
  }

  /**
   * Returns a binding expression for {@link RequestKind#PROVIDER} requests.
   *
   * <p>{@code @Binds} bindings that don't {@linkplain #needsCaching(ContributionBinding) need to be
   * cached} can use a {@link DelegateBindingExpression}.
   *
   * <p>In fastInit mode, use an {@link InnerSwitchingProviders inner switching provider} unless
   * that provider's case statement will simply call {@code get()} on another {@link Provider} (in
   * which case, just use that Provider directly).
   *
   * <p>Otherwise, return a {@link FrameworkInstanceBindingExpression}.
   */
  private BindingExpression providerBindingExpression(ContributionBinding binding) {
    if (binding.kind().equals(DELEGATE) && !needsCaching(binding)) {
      return new DelegateBindingExpression(binding, RequestKind.PROVIDER, this, types, elements);
    } else if (compilerOptions.fastInit(
            topLevelComponentImplementation.componentDescriptor().typeElement())
        && frameworkInstanceCreationExpression(binding).useInnerSwitchingProvider()
        && !(instanceBindingExpression(binding)
            instanceof DerivedFromFrameworkInstanceBindingExpression)) {
      return wrapInMethod(
          binding,
          bindingRequest(binding.key(), RequestKind.PROVIDER),
          innerSwitchingProviders.newBindingExpression(binding));
    }
    return frameworkInstanceBindingExpression(binding);
  }

  /**
   * Returns a binding expression that uses a {@link dagger.producers.Producer} field for a
   * provision binding.
   */
  private FrameworkInstanceBindingExpression producerFromProviderBindingExpression(
      ContributionBinding binding) {
    checkArgument(binding.bindingType().equals(BindingType.PROVISION));
    return new ProducerNodeInstanceBindingExpression(
        binding,
        new FrameworkFieldInitializer(
            componentImplementation,
            binding,
            new ProducerFromProviderCreationExpression(binding, componentImplementation, this)),
        types,
        elements,
        componentImplementation);
  }

  /**
   * Returns a binding expression for {@link RequestKind#INSTANCE} requests.
   *
   * <p>If there is a direct expression (not calling {@link Provider#get()}) we can use for an
   * instance of this binding, return it, wrapped in a method if the binding {@linkplain
   * #needsCaching(ContributionBinding) needs to be cached} or the expression has dependencies.
   *
   * <p>In fastInit mode, we can use direct expressions unless the binding needs to be cached.
   */
  private BindingExpression instanceBindingExpression(ContributionBinding binding) {
    Optional<BindingExpression> maybeDirectInstanceExpression =
        unscopedDirectInstanceExpression(binding);
    if (canUseDirectInstanceExpression(binding) && maybeDirectInstanceExpression.isPresent()) {
      BindingExpression directInstanceExpression = maybeDirectInstanceExpression.get();
      return directInstanceExpression.requiresMethodEncapsulation() || needsCaching(binding)
          ? wrapInMethod(
              binding,
              bindingRequest(binding.key(), RequestKind.INSTANCE),
              directInstanceExpression)
          : directInstanceExpression;
    }
    return new DerivedFromFrameworkInstanceBindingExpression(
        binding.key(), FrameworkType.PROVIDER, RequestKind.INSTANCE, this, types);
  }

  /**
   * Returns an unscoped binding expression for an {@link RequestKind#INSTANCE} that does not call
   * {@code get()} on its provider, if there is one.
   */
  private Optional<BindingExpression> unscopedDirectInstanceExpression(
      ContributionBinding binding) {
    switch (binding.kind()) {
      case DELEGATE:
        return Optional.of(
            new DelegateBindingExpression(binding, RequestKind.INSTANCE, this, types, elements));

      case COMPONENT:
        return Optional.of(
            new ComponentInstanceBindingExpression(binding, componentImplementation.name()));

      case COMPONENT_DEPENDENCY:
        return Optional.of(
            new ComponentRequirementBindingExpression(
                binding,
                ComponentRequirement.forDependency(binding.key().type()),
                componentRequirementExpressions));

      case COMPONENT_PROVISION:
        return Optional.of(
            new ComponentProvisionBindingExpression(
                (ProvisionBinding) binding,
                graph,
                componentRequirementExpressions,
                compilerOptions));

      case SUBCOMPONENT_CREATOR:
        return Optional.of(
            new SubcomponentCreatorBindingExpression(
                binding, componentImplementation.getSubcomponentCreatorSimpleName(binding.key())));

      case MULTIBOUND_SET:
        return Optional.of(
            new SetBindingExpression((ProvisionBinding) binding, graph, this, types, elements));

      case MULTIBOUND_MAP:
        return Optional.of(
            new MapBindingExpression((ProvisionBinding) binding, graph, this, types, elements));

      case OPTIONAL:
        return Optional.of(
            new OptionalBindingExpression((ProvisionBinding) binding, this, types, sourceVersion));

      case BOUND_INSTANCE:
        return Optional.of(
            new ComponentRequirementBindingExpression(
                binding,
                ComponentRequirement.forBoundInstance(binding),
                componentRequirementExpressions));

      case ASSISTED_FACTORY:
        return Optional.of(
            new AssistedFactoryBindingExpression(
                (ProvisionBinding) binding, this, types, elements));

      case ASSISTED_INJECTION:
      case INJECTION:
      case PROVISION:
        return Optional.of(
            new SimpleMethodBindingExpression(
                (ProvisionBinding) binding,
                compilerOptions,
                this,
                membersInjectionMethods,
                componentRequirementExpressions,
                elements,
                sourceVersion,
                metadataUtil));

      case MEMBERS_INJECTOR:
        return Optional.empty();

      case MEMBERS_INJECTION:
      case COMPONENT_PRODUCTION:
      case PRODUCTION:
        throw new IllegalArgumentException(binding.kind().toString());
      default:
        throw new AssertionError("Unexpected binding kind: " + binding.kind());
    }
  }

  /**
   * Returns {@code true} if the binding should use the static factory creation strategy.
   *
   * <p>In default mode, we always use the static factory creation strategy. In fastInit mode, we
   * prefer to use a SwitchingProvider instead of static factories in order to reduce class loading;
   * however, we allow static factories that can reused across multiple bindings, e.g. {@code
   * MapFactory} or {@code SetFactory}.
   */
  private boolean useStaticFactoryCreation(ContributionBinding binding) {
    return !compilerOptions.fastInit(
            topLevelComponentImplementation.componentDescriptor().typeElement())
        || binding.kind().equals(MULTIBOUND_MAP)
        || binding.kind().equals(MULTIBOUND_SET);
  }

  /**
   * Returns {@code true} if we can use a direct (not {@code Provider.get()}) expression for this
   * binding. If the binding doesn't {@linkplain #needsCaching(ContributionBinding) need to be
   * cached} and the binding is not an {@link BindingKind.ASSISTED_FACTORY}, we can.
   *
   * <p>In fastInit mode, we can use a direct expression even if the binding {@linkplain
   * #needsCaching(ContributionBinding) needs to be cached}.
   */
  private boolean canUseDirectInstanceExpression(ContributionBinding binding) {
    return (!needsCaching(binding) && binding.kind() != BindingKind.ASSISTED_FACTORY)
        || compilerOptions.fastInit(
            topLevelComponentImplementation.componentDescriptor().typeElement());
  }

  /**
   * Returns a binding expression that uses a given one as the body of a method that users call. If
   * a component provision method matches it, it will be the method implemented. If it does not
   * match a component provision method and the binding is modifiable, then a new public modifiable
   * binding method will be written. If the binding doesn't match a component method and is not
   * modifiable, then a new private method will be written.
   */
  BindingExpression wrapInMethod(
      ContributionBinding binding, BindingRequest request, BindingExpression bindingExpression) {
    // If we've already wrapped the expression, then use the delegate.
    if (bindingExpression instanceof MethodBindingExpression) {
      return bindingExpression;
    }

    MethodImplementationStrategy methodImplementationStrategy =
        methodImplementationStrategy(binding, request);
    Optional<ComponentMethodDescriptor> matchingComponentMethod =
        graph.componentDescriptor().firstMatchingComponentMethod(request);

    ComponentImplementation shard = componentImplementation.shardImplementation(binding.key());

    // Consider the case of a request from a component method like:
    //
    //   DaggerMyComponent extends MyComponent {
    //     @Overrides
    //     Foo getFoo() {
    //       <FOO_BINDING_REQUEST>
    //     }
    //   }
    //
    // Normally, in this case we would return a ComponentMethodBindingExpression rather than a
    // PrivateMethodBindingExpression so that #getFoo() can inline the implementation rather than
    // create an unnecessary private method and return that. However, with sharding we don't want to
    // inline the implementation because that would defeat some of the class pool savings if those
    // fields had to communicate across shards. Thus, when a key belongs to a separate shard use a
    // PrivateMethodBindingExpression and put the private method in the shard.
    if (matchingComponentMethod.isPresent() && componentImplementation == shard) {
      ComponentMethodDescriptor componentMethod = matchingComponentMethod.get();
      return new ComponentMethodBindingExpression(
          request,
          binding,
          methodImplementationStrategy,
          bindingExpression,
          componentImplementation,
          componentMethod,
          types);
    } else {
      return new PrivateMethodBindingExpression(
          request,
          binding,
          methodImplementationStrategy,
          bindingExpression,
          shard,
          types,
          compilerOptions);
    }
  }

  private MethodImplementationStrategy methodImplementationStrategy(
      ContributionBinding binding, BindingRequest request) {
    if (compilerOptions.fastInit(
        topLevelComponentImplementation.componentDescriptor().typeElement())) {
      if (request.isRequestKind(RequestKind.PROVIDER)) {
        return MethodImplementationStrategy.SINGLE_CHECK;
      } else if (request.isRequestKind(RequestKind.INSTANCE) && needsCaching(binding)) {
        return binding.scope().get().isReusable()
            ? MethodImplementationStrategy.SINGLE_CHECK
            : MethodImplementationStrategy.DOUBLE_CHECK;
      }
    }
    return MethodImplementationStrategy.SIMPLE;
  }

  /**
   * Returns {@code true} if the component needs to make sure the provided value is cached.
   *
   * <p>The component needs to cache the value for scoped bindings except for {@code @Binds}
   * bindings whose scope is no stronger than their delegate's.
   */
  private boolean needsCaching(ContributionBinding binding) {
    if (!binding.scope().isPresent()) {
      return false;
    }
    if (binding.kind().equals(DELEGATE)) {
      return isBindsScopeStrongerThanDependencyScope(binding, graph);
    }
    return true;
  }
}

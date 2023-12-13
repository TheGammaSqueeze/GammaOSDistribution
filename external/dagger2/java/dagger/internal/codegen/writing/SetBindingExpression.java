/*
 * Copyright (C) 2017 The Dagger Authors.
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

import static com.google.common.collect.Iterables.getOnlyElement;
import static dagger.internal.codegen.binding.BindingRequest.bindingRequest;
import static dagger.internal.codegen.javapoet.CodeBlocks.toParametersCodeBlock;
import static dagger.internal.codegen.langmodel.Accessibility.isTypeAccessibleFrom;
import static javax.lang.model.util.ElementFilter.methodsIn;

import com.google.common.collect.ImmutableSet;
import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.CodeBlock;
import dagger.internal.SetBuilder;
import dagger.internal.codegen.base.ContributionType;
import dagger.internal.codegen.base.SetType;
import dagger.internal.codegen.binding.BindingGraph;
import dagger.internal.codegen.binding.ProvisionBinding;
import dagger.internal.codegen.javapoet.Expression;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.model.DependencyRequest;
import java.util.Collections;
import javax.lang.model.type.DeclaredType;
import javax.lang.model.type.TypeMirror;

/** A binding expression for multibound sets. */
final class SetBindingExpression extends SimpleInvocationBindingExpression {
  private final ProvisionBinding binding;
  private final BindingGraph graph;
  private final ComponentBindingExpressions componentBindingExpressions;
  private final DaggerTypes types;
  private final DaggerElements elements;

  SetBindingExpression(
      ProvisionBinding binding,
      BindingGraph graph,
      ComponentBindingExpressions componentBindingExpressions,
      DaggerTypes types,
      DaggerElements elements) {
    super(binding);
    this.binding = binding;
    this.graph = graph;
    this.componentBindingExpressions = componentBindingExpressions;
    this.types = types;
    this.elements = elements;
  }

  @Override
  Expression getDependencyExpression(ClassName requestingClass) {
    // TODO(ronshapiro): We should also make an ImmutableSet version of SetFactory
    boolean isImmutableSetAvailable = isImmutableSetAvailable();
    // TODO(ronshapiro, gak): Use Sets.immutableEnumSet() if it's available?
    if (isImmutableSetAvailable && binding.dependencies().stream().allMatch(this::isSingleValue)) {
      return Expression.create(
          immutableSetType(),
          CodeBlock.builder()
              .add("$T.", ImmutableSet.class)
              .add(maybeTypeParameter(requestingClass))
              .add(
                  "of($L)",
                  binding
                      .dependencies()
                      .stream()
                      .map(dependency -> getContributionExpression(dependency, requestingClass))
                      .collect(toParametersCodeBlock()))
              .build());
    }
    switch (binding.dependencies().size()) {
      case 0:
        return collectionsStaticFactoryInvocation(requestingClass, CodeBlock.of("emptySet()"));
      case 1:
        {
          DependencyRequest dependency = getOnlyElement(binding.dependencies());
          CodeBlock contributionExpression = getContributionExpression(dependency, requestingClass);
          if (isSingleValue(dependency)) {
            return collectionsStaticFactoryInvocation(
                requestingClass, CodeBlock.of("singleton($L)", contributionExpression));
          } else if (isImmutableSetAvailable) {
            return Expression.create(
                immutableSetType(),
                CodeBlock.builder()
                    .add("$T.", ImmutableSet.class)
                    .add(maybeTypeParameter(requestingClass))
                    .add("copyOf($L)", contributionExpression)
                    .build());
          }
        }
        // fall through
      default:
        CodeBlock.Builder instantiation = CodeBlock.builder();
        instantiation
            .add("$T.", isImmutableSetAvailable ? ImmutableSet.class : SetBuilder.class)
            .add(maybeTypeParameter(requestingClass));
        if (isImmutableSetBuilderWithExpectedSizeAvailable()) {
          instantiation.add("builderWithExpectedSize($L)", binding.dependencies().size());
        } else if (isImmutableSetAvailable) {
          instantiation.add("builder()");
        } else {
          instantiation.add("newSetBuilder($L)", binding.dependencies().size());
        }
        for (DependencyRequest dependency : binding.dependencies()) {
          String builderMethod = isSingleValue(dependency) ? "add" : "addAll";
          instantiation.add(
              ".$L($L)", builderMethod, getContributionExpression(dependency, requestingClass));
        }
        instantiation.add(".build()");
        return Expression.create(
            isImmutableSetAvailable ? immutableSetType() : binding.key().type(),
            instantiation.build());
    }
  }

  private DeclaredType immutableSetType() {
    return types.getDeclaredType(
        elements.getTypeElement(ImmutableSet.class), SetType.from(binding.key()).elementType());
  }

  private CodeBlock getContributionExpression(
      DependencyRequest dependency, ClassName requestingClass) {
    return componentBindingExpressions
        .getDependencyExpression(bindingRequest(dependency), requestingClass)
        .codeBlock();
  }

  private Expression collectionsStaticFactoryInvocation(
      ClassName requestingClass, CodeBlock methodInvocation) {
    return Expression.create(
        binding.key().type(),
        CodeBlock.builder()
            .add("$T.", Collections.class)
            .add(maybeTypeParameter(requestingClass))
            .add(methodInvocation)
            .build());
  }

  private CodeBlock maybeTypeParameter(ClassName requestingClass) {
    TypeMirror elementType = SetType.from(binding.key()).elementType();
    return isTypeAccessibleFrom(elementType, requestingClass.packageName())
        ? CodeBlock.of("<$T>", elementType)
        : CodeBlock.of("");
  }

  private boolean isSingleValue(DependencyRequest dependency) {
    return graph.contributionBinding(dependency.key())
        .contributionType()
        .equals(ContributionType.SET);
  }

  private boolean isImmutableSetBuilderWithExpectedSizeAvailable() {
    if (isImmutableSetAvailable()) {
      return methodsIn(elements.getTypeElement(ImmutableSet.class).getEnclosedElements())
          .stream()
          .anyMatch(method -> method.getSimpleName().contentEquals("builderWithExpectedSize"));
    }
    return false;
  }

  private boolean isImmutableSetAvailable() {
    return elements.getTypeElement(ImmutableSet.class) != null;
  }
}

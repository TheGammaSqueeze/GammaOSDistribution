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

package dagger.internal.codegen.validation;

import static dagger.internal.codegen.validation.BindingElementValidator.AllowsMultibindings.ALLOWS_MULTIBINDINGS;
import static dagger.internal.codegen.validation.BindingElementValidator.AllowsScoping.ALLOWS_SCOPING;
import static dagger.internal.codegen.validation.BindingMethodValidator.Abstractness.MUST_BE_ABSTRACT;
import static dagger.internal.codegen.validation.BindingMethodValidator.ExceptionSuperclass.NO_EXCEPTIONS;
import static dagger.internal.codegen.validation.TypeHierarchyValidator.validateTypeHierarchy;

import com.google.auto.common.MoreTypes;
import com.google.common.collect.ImmutableSet;
import dagger.Binds;
import dagger.Module;
import dagger.internal.codegen.base.ContributionType;
import dagger.internal.codegen.base.SetType;
import dagger.internal.codegen.binding.BindsTypeChecker;
import dagger.internal.codegen.binding.InjectionAnnotations;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.producers.ProducerModule;
import javax.inject.Inject;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.VariableElement;
import javax.lang.model.type.TypeMirror;

/** A validator for {@link Binds} methods. */
final class BindsMethodValidator extends BindingMethodValidator {
  private final DaggerTypes types;
  private final BindsTypeChecker bindsTypeChecker;

  @Inject
  BindsMethodValidator(
      DaggerElements elements,
      DaggerTypes types,
      KotlinMetadataUtil kotlinMetadataUtil,
      BindsTypeChecker bindsTypeChecker,
      DependencyRequestValidator dependencyRequestValidator,
      InjectionAnnotations injectionAnnotations) {
    super(
        elements,
        types,
        kotlinMetadataUtil,
        Binds.class,
        ImmutableSet.of(Module.class, ProducerModule.class),
        dependencyRequestValidator,
        MUST_BE_ABSTRACT,
        NO_EXCEPTIONS,
        ALLOWS_MULTIBINDINGS,
        ALLOWS_SCOPING,
        injectionAnnotations);
    this.types = types;
    this.bindsTypeChecker = bindsTypeChecker;
  }

  @Override
  protected ElementValidator elementValidator(ExecutableElement element) {
    return new Validator(element);
  }

  private class Validator extends MethodValidator {
    Validator(ExecutableElement element) {
      super(element);
    }

    @Override
    protected void checkParameters() {
      if (element.getParameters().size() != 1) {
        report.addError(
            bindingMethods(
                "must have exactly one parameter, whose type is assignable to the return type"));
      } else {
        super.checkParameters();
      }
    }

    @Override
    protected void checkParameter(VariableElement parameter) {
      super.checkParameter(parameter);
      TypeMirror leftHandSide = boxIfNecessary(element.getReturnType());
      TypeMirror rightHandSide = parameter.asType();
      ContributionType contributionType = ContributionType.fromBindingElement(element);
      if (contributionType.equals(ContributionType.SET_VALUES) && !SetType.isSet(leftHandSide)) {
        report.addError(
            "@Binds @ElementsIntoSet methods must return a Set and take a Set parameter");
      }

      if (!bindsTypeChecker.isAssignable(rightHandSide, leftHandSide, contributionType)) {
        // Validate the type hierarchy of both sides to make sure they're both valid.
        // If one of the types isn't valid it means we need to delay validation to the next round.
        // Note: BasicAnnotationProcessor only performs superficial validation on the referenced
        // types within the module. Thus, we're guaranteed that the types in the @Binds method are
        // valid, but it says nothing about their supertypes, which are needed for isAssignable.
        validateTypeHierarchy(leftHandSide, types);
        validateTypeHierarchy(rightHandSide, types);
        // TODO(ronshapiro): clarify this error message for @ElementsIntoSet cases, where the
        // right-hand-side might not be assignable to the left-hand-side, but still compatible with
        // Set.addAll(Collection<? extends E>)
        report.addError("@Binds methods' parameter type must be assignable to the return type");
      }
    }

    private TypeMirror boxIfNecessary(TypeMirror maybePrimitive) {
      if (maybePrimitive.getKind().isPrimitive()) {
        return types.boxedClass(MoreTypes.asPrimitiveType(maybePrimitive)).asType();
      }
      return maybePrimitive;
    }
  }
}

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

import static com.google.auto.common.MoreTypes.asTypeElement;
import static dagger.internal.codegen.base.Keys.isValidImplicitProvisionKey;
import static dagger.internal.codegen.binding.InjectionAnnotations.injectedConstructors;
import static dagger.internal.codegen.validation.BindingElementValidator.AllowsMultibindings.NO_MULTIBINDINGS;
import static dagger.internal.codegen.validation.BindingElementValidator.AllowsScoping.NO_SCOPING;
import static dagger.internal.codegen.validation.BindingMethodValidator.Abstractness.MUST_BE_ABSTRACT;
import static dagger.internal.codegen.validation.BindingMethodValidator.ExceptionSuperclass.NO_EXCEPTIONS;

import com.google.common.collect.ImmutableSet;
import dagger.BindsOptionalOf;
import dagger.Module;
import dagger.internal.codegen.binding.InjectionAnnotations;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.producers.ProducerModule;
import javax.inject.Inject;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.type.TypeMirror;

/** A validator for {@link BindsOptionalOf} methods. */
final class BindsOptionalOfMethodValidator extends BindingMethodValidator {

  private final DaggerTypes types;
  private final InjectionAnnotations injectionAnnotations;

  @Inject
  BindsOptionalOfMethodValidator(
      DaggerElements elements,
      DaggerTypes types,
      KotlinMetadataUtil kotlinMetadataUtil,
      DependencyRequestValidator dependencyRequestValidator,
      InjectionAnnotations injectionAnnotations) {
    super(
        elements,
        types,
        kotlinMetadataUtil,
        BindsOptionalOf.class,
        ImmutableSet.of(Module.class, ProducerModule.class),
        dependencyRequestValidator,
        MUST_BE_ABSTRACT,
        NO_EXCEPTIONS,
        NO_MULTIBINDINGS,
        NO_SCOPING,
        injectionAnnotations);
    this.types = types;
    this.injectionAnnotations = injectionAnnotations;
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
    protected void checkKeyType(TypeMirror keyType) {
      super.checkKeyType(keyType);
      if (isValidImplicitProvisionKey(
              injectionAnnotations.getQualifiers(element).stream().findFirst(), keyType, types)
          && !injectedConstructors(asTypeElement(keyType)).isEmpty()) {
        report.addError(
            "@BindsOptionalOf methods cannot return unqualified types that have an @Inject-"
                + "annotated constructor because those are always present");
      }
    }

    @Override
    protected void checkParameters() {
      if (!element.getParameters().isEmpty()) {
        report.addError("@BindsOptionalOf methods cannot have parameters");
      }
    }
  }
}

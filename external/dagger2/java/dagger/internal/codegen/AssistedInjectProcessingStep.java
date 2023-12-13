/*
 * Copyright (C) 2021 The Dagger Authors.
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

package dagger.internal.codegen;

import static com.google.auto.common.MoreTypes.asDeclared;
import static com.google.common.base.Preconditions.checkState;
import static dagger.internal.codegen.langmodel.DaggerElements.closestEnclosingTypeElement;

import com.google.auto.common.MoreElements;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import dagger.assisted.AssistedInject;
import dagger.internal.codegen.binding.AssistedInjectionAnnotations;
import dagger.internal.codegen.binding.AssistedInjectionAnnotations.AssistedParameter;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.internal.codegen.validation.TypeCheckingProcessingStep;
import dagger.internal.codegen.validation.ValidationReport;
import java.lang.annotation.Annotation;
import java.util.HashSet;
import java.util.Set;
import javax.annotation.processing.Messager;
import javax.inject.Inject;
import javax.lang.model.element.ElementKind;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.type.DeclaredType;

/** An annotation processor for {@link dagger.assisted.AssistedInject}-annotated elements. */
final class AssistedInjectProcessingStep extends TypeCheckingProcessingStep<ExecutableElement> {
  private final DaggerTypes types;
  private final Messager messager;

  @Inject
  AssistedInjectProcessingStep(DaggerTypes types, Messager messager) {
    super(MoreElements::asExecutable);
    this.types = types;
    this.messager = messager;
  }

  @Override
  public ImmutableSet<Class<? extends Annotation>> annotations() {
    return ImmutableSet.of(AssistedInject.class);
  }

  @Override
  protected void process(
      ExecutableElement assistedInjectElement,
      ImmutableSet<Class<? extends Annotation>> annotations) {
    new AssistedInjectValidator().validate(assistedInjectElement).printMessagesTo(messager);
  }

  private final class AssistedInjectValidator {
    ValidationReport<ExecutableElement> validate(ExecutableElement constructor) {
      checkState(constructor.getKind() == ElementKind.CONSTRUCTOR);
      ValidationReport.Builder<ExecutableElement> report = ValidationReport.about(constructor);

      DeclaredType assistedInjectType =
          asDeclared(closestEnclosingTypeElement(constructor).asType());
      ImmutableList<AssistedParameter> assistedParameters =
          AssistedInjectionAnnotations.assistedInjectAssistedParameters(assistedInjectType, types);

      Set<AssistedParameter> uniqueAssistedParameters = new HashSet<>();
      for (AssistedParameter assistedParameter : assistedParameters) {
        if (!uniqueAssistedParameters.add(assistedParameter)) {
          report.addError(
              "@AssistedInject constructor has duplicate @Assisted type: " + assistedParameter,
              assistedParameter.variableElement());
        }
      }

      return report.build();
    }
  }
}

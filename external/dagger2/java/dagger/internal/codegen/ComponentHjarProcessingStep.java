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

package dagger.internal.codegen;

import static com.google.auto.common.MoreElements.asType;
import static com.google.common.collect.Sets.union;
import static dagger.internal.codegen.base.ComponentAnnotation.rootComponentAnnotations;
import static dagger.internal.codegen.binding.ComponentCreatorAnnotation.rootComponentCreatorAnnotations;
import static java.util.Collections.disjoint;

import com.google.auto.common.MoreElements;
import com.google.common.collect.ImmutableSet;
import dagger.internal.codegen.base.SourceFileGenerator;
import dagger.internal.codegen.binding.BindingGraph;
import dagger.internal.codegen.binding.ComponentDescriptor;
import dagger.internal.codegen.binding.ComponentDescriptorFactory;
import dagger.internal.codegen.validation.ComponentCreatorValidator;
import dagger.internal.codegen.validation.ComponentValidator;
import dagger.internal.codegen.validation.TypeCheckingProcessingStep;
import dagger.internal.codegen.validation.ValidationReport;
import java.lang.annotation.Annotation;
import java.util.Set;
import javax.annotation.processing.Messager;
import javax.inject.Inject;
import javax.lang.model.element.TypeElement;

/**
 * A processing step that emits the API of a generated component, without any actual implementation.
 *
 * <p>When compiling a header jar (hjar), Bazel needs to run annotation processors that generate
 * API, like Dagger, to see what code they might output. Full {@link BindingGraph} analysis is
 * costly and unnecessary from the perspective of the header compiler; it's sole goal is to pass
 * along a slimmed down version of what will be the jar for a particular compilation, whether or not
 * that compilation succeeds. If it does not, the compilation pipeline will fail, even if header
 * compilation succeeded.
 *
 * <p>The components emitted by this processing step include all of the API elements exposed by the
 * normal step. Method bodies are omitted as Turbine ignores them entirely.
 */
final class ComponentHjarProcessingStep extends TypeCheckingProcessingStep<TypeElement> {
  private final Messager messager;
  private final ComponentValidator componentValidator;
  private final ComponentCreatorValidator creatorValidator;
  private final ComponentDescriptorFactory componentDescriptorFactory;
  private final SourceFileGenerator<ComponentDescriptor> componentGenerator;

  @Inject
  ComponentHjarProcessingStep(
      Messager messager,
      ComponentValidator componentValidator,
      ComponentCreatorValidator creatorValidator,
      ComponentDescriptorFactory componentDescriptorFactory,
      SourceFileGenerator<ComponentDescriptor> componentGenerator) {
    super(MoreElements::asType);
    this.messager = messager;
    this.componentValidator = componentValidator;
    this.creatorValidator = creatorValidator;
    this.componentDescriptorFactory = componentDescriptorFactory;
    this.componentGenerator = componentGenerator;
  }

  @Override
  public Set<Class<? extends Annotation>> annotations() {
    return union(rootComponentAnnotations(), rootComponentCreatorAnnotations());
  }

  // TODO(ronshapiro): Validation might not even be necessary. We should measure it and figure out
  // if it's worth seeing if removing it will still work. We could potentially add a new catch
  // clause for any exception that's not TypeNotPresentException and ignore the component entirely
  // in that case.
  @Override
  protected void process(
      TypeElement element, ImmutableSet<Class<? extends Annotation>> annotations) {
    if (!disjoint(annotations, rootComponentAnnotations())) {
      processRootComponent(element);
    }
    if (!disjoint(annotations, rootComponentCreatorAnnotations())) {
      processRootCreator(element);
    }
  }

  private void processRootComponent(TypeElement element) {
    ValidationReport<TypeElement> validationReport = componentValidator.validate(element);
    validationReport.printMessagesTo(messager);
    if (validationReport.isClean()) {
      componentGenerator.generate(
          componentDescriptorFactory.rootComponentDescriptor(element), messager);
    }
  }

  private void processRootCreator(TypeElement creator) {
    creatorValidator.validate(asType(creator)).printMessagesTo(messager);
  }
}

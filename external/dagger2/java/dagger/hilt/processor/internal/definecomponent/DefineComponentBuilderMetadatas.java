/*
 * Copyright (C) 2019 The Dagger Authors.
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

package dagger.hilt.processor.internal.definecomponent;

import static javax.lang.model.element.Modifier.STATIC;

import com.google.auto.common.MoreElements;
import com.google.auto.common.MoreTypes;
import com.google.auto.value.AutoValue;
import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.TypeName;
import dagger.hilt.processor.internal.ClassNames;
import dagger.hilt.processor.internal.ProcessorErrors;
import dagger.hilt.processor.internal.Processors;
import dagger.hilt.processor.internal.definecomponent.DefineComponentMetadatas.DefineComponentMetadata;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import javax.lang.model.element.Element;
import javax.lang.model.element.ElementKind;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;
import javax.lang.model.element.VariableElement;
import javax.lang.model.type.TypeKind;
import javax.lang.model.type.TypeMirror;
import javax.lang.model.util.ElementFilter;

/** Metadata for types annotated with {@link dagger.hilt.DefineComponent.Builder}. */
final class DefineComponentBuilderMetadatas {
  static DefineComponentBuilderMetadatas create(DefineComponentMetadatas componentMetadatas) {
    return new DefineComponentBuilderMetadatas(componentMetadatas);
  }

  private final Map<Element, DefineComponentBuilderMetadata> builderMetadatas = new HashMap<>();
  private final DefineComponentMetadatas componentMetadatas;

  private DefineComponentBuilderMetadatas(DefineComponentMetadatas componentMetadatas) {
    this.componentMetadatas = componentMetadatas;
  }

  DefineComponentBuilderMetadata get(Element element) {
    if (!builderMetadatas.containsKey(element)) {
      builderMetadatas.put(element, getUncached(element));
    }
    return builderMetadatas.get(element);
  }

  private DefineComponentBuilderMetadata getUncached(Element element) {
    ProcessorErrors.checkState(
        Processors.hasAnnotation(element, ClassNames.DEFINE_COMPONENT_BUILDER),
        element,
        "%s, expected to be annotated with @DefineComponent.Builder. Found: %s",
        element,
        element.getAnnotationMirrors());

    // TODO(bcorso): Allow abstract classes?
    ProcessorErrors.checkState(
        element.getKind().equals(ElementKind.INTERFACE),
        element,
        "@DefineComponent.Builder is only allowed on interfaces. Found: %s",
        element);
    TypeElement builder = MoreElements.asType(element);

    // TODO(bcorso): Allow extending interfaces?
    ProcessorErrors.checkState(
        builder.getInterfaces().isEmpty(),
        builder,
        "@DefineComponent.Builder %s, cannot extend a super class or interface. Found: %s",
        builder,
        builder.getInterfaces());

    // TODO(bcorso): Allow type parameters?
    ProcessorErrors.checkState(
        builder.getTypeParameters().isEmpty(),
        builder,
        "@DefineComponent.Builder %s, cannot have type parameters.",
        builder.asType());

    List<VariableElement> nonStaticFields =
        ElementFilter.fieldsIn(builder.getEnclosedElements()).stream()
            .filter(method -> !method.getModifiers().contains(STATIC))
            .collect(Collectors.toList());
    ProcessorErrors.checkState(
        nonStaticFields.isEmpty(),
        builder,
        "@DefineComponent.Builder %s, cannot have non-static fields. Found: %s",
        builder,
        nonStaticFields);

    List<ExecutableElement> buildMethods =
        ElementFilter.methodsIn(builder.getEnclosedElements()).stream()
            .filter(method -> !method.getModifiers().contains(STATIC))
            .filter(method -> method.getParameters().isEmpty())
            .collect(Collectors.toList());

    ProcessorErrors.checkState(
        buildMethods.size() == 1,
        builder,
        "@DefineComponent.Builder %s, must have exactly 1 build method that takes no parameters. "
            + "Found: %s",
        builder,
        buildMethods);

    ExecutableElement buildMethod = buildMethods.get(0);
    TypeMirror component = buildMethod.getReturnType();
    ProcessorErrors.checkState(
        buildMethod.getReturnType().getKind().equals(TypeKind.DECLARED)
            && Processors.hasAnnotation(
                MoreTypes.asTypeElement(component), ClassNames.DEFINE_COMPONENT),
        builder,
        "@DefineComponent.Builder method, %s#%s, must return a @DefineComponent type. Found: %s",
        builder,
        buildMethod,
        component);

    List<ExecutableElement> nonStaticNonBuilderMethods =
        ElementFilter.methodsIn(builder.getEnclosedElements()).stream()
            .filter(method -> !method.getModifiers().contains(STATIC))
            .filter(method -> !method.equals(buildMethod))
            .filter(method -> !TypeName.get(method.getReturnType()).equals(ClassName.get(builder)))
            .collect(Collectors.toList());

    ProcessorErrors.checkState(
        nonStaticNonBuilderMethods.isEmpty(),
        nonStaticNonBuilderMethods,
        "@DefineComponent.Builder %s, all non-static methods must return %s or %s. Found: %s",
        builder,
        builder,
        component,
        nonStaticNonBuilderMethods);

    return new AutoValue_DefineComponentBuilderMetadatas_DefineComponentBuilderMetadata(
        builder,
        buildMethod,
        componentMetadatas.get(MoreTypes.asTypeElement(component)));
  }

  @AutoValue
  abstract static class DefineComponentBuilderMetadata {
    abstract TypeElement builder();

    abstract ExecutableElement buildMethod();

    abstract DefineComponentMetadata componentMetadata();
  }
}

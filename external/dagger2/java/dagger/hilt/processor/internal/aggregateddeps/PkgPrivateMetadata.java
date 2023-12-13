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

package dagger.hilt.processor.internal.aggregateddeps;

import static com.google.auto.common.Visibility.effectiveVisibilityOfElement;

import com.google.auto.common.MoreElements;
import com.google.auto.common.Visibility;
import com.google.auto.value.AutoValue;
import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.TypeName;
import dagger.hilt.processor.internal.ClassNames;
import dagger.hilt.processor.internal.Processors;
import java.util.Optional;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.lang.model.util.Elements;

/** PkgPrivateModuleMetadata contains a set of utilities for processing package private modules. */
@AutoValue
abstract class PkgPrivateMetadata {
  private static final String PREFIX = "HiltWrapper_";

  /** Returns the base class name of the elemenet. */
  TypeName baseClassName() {
    return TypeName.get(getTypeElement().asType());
  }

  /** Returns TypeElement for the module element the metadata object represents */
  abstract TypeElement getTypeElement();

  /**
   * Returns an optional @InstallIn AnnotationMirror for the module element the metadata object
   * represents
   */
  abstract Optional<AnnotationMirror> getOptionalInstallInAnnotationMirror();

  /** Return the Type of this package private element. */
  abstract ClassName getAnnotation();

  /** Returns the expected genenerated classname for the element the metadata object represents */
  final ClassName generatedClassName() {
    return Processors.prepend(
        Processors.getEnclosedClassName(ClassName.get(getTypeElement())), PREFIX);
  }

  /**
   * Returns an Optional PkgPrivateMetadata requiring Hilt processing, otherwise returns an empty
   * Optional.
   */
  static Optional<PkgPrivateMetadata> of(Elements elements, Element element, ClassName annotation) {
    // If this is a public element no wrapping is needed
    if (effectiveVisibilityOfElement(element) == Visibility.PUBLIC) {
      return Optional.empty();
    }

    Optional<AnnotationMirror> installIn;
    if (Processors.hasAnnotation(element, ClassNames.INSTALL_IN)) {
      installIn = Optional.of(Processors.getAnnotationMirror(element, ClassNames.INSTALL_IN));
    } else if (Processors.hasAnnotation(element, ClassNames.TEST_INSTALL_IN)) {
      installIn = Optional.of(Processors.getAnnotationMirror(element, ClassNames.TEST_INSTALL_IN));
    } else {
      throw new IllegalStateException(
          "Expected element to be annotated with @InstallIn: " + element);
    }

    if (annotation.equals(ClassNames.MODULE)
        ) {
      // Skip modules that require a module instance. Required by
      // dagger (b/31489617)
      if (Processors.requiresModuleInstance(elements, MoreElements.asType(element))) {
        return Optional.empty();
      }
    }
    return Optional.of(
        new AutoValue_PkgPrivateMetadata(MoreElements.asType(element), installIn, annotation));
  }
}

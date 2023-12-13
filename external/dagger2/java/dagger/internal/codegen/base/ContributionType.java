/*
 * Copyright (C) 2015 The Dagger Authors.
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

package dagger.internal.codegen.base;

import static com.google.auto.common.MoreElements.isAnnotationPresent;

import dagger.multibindings.ElementsIntoSet;
import dagger.multibindings.IntoMap;
import dagger.multibindings.IntoSet;
import javax.lang.model.element.Element;

/** Whether a binding or declaration is for a unique contribution or a map or set multibinding. */
public enum ContributionType {
  /** Represents map bindings. */
  MAP,
  /** Represents set bindings. */
  SET,
  /** Represents set values bindings. */
  SET_VALUES,
  /** Represents a valid non-collection binding. */
  UNIQUE,
  ;

  /** An object that is associated with a {@link ContributionType}. */
  public interface HasContributionType {

    /** The contribution type of this object. */
    ContributionType contributionType();
  }

  /** {@code true} if this is for a multibinding. */
  public boolean isMultibinding() {
    return !this.equals(UNIQUE);
  }

  /**
   * The contribution type from a binding element's annotations. Presumes a well-formed binding
   * element (at most one of @IntoSet, @IntoMap, @ElementsIntoSet and @Provides.type). {@link
   * dagger.internal.codegen.validation.BindingMethodValidator} and {@link
   * dagger.internal.codegen.validation.BindsInstanceProcessingStep} validate correctness on their
   * own.
   */
  public static ContributionType fromBindingElement(Element element) {
    // TODO(bcorso): Replace these class references with ClassName.
    if (isAnnotationPresent(element, IntoMap.class)) {
      return ContributionType.MAP;
    } else if (isAnnotationPresent(element, IntoSet.class)) {
      return ContributionType.SET;
    } else if (isAnnotationPresent(element, ElementsIntoSet.class)) {
      return ContributionType.SET_VALUES;
    }
    return ContributionType.UNIQUE;
  }
}

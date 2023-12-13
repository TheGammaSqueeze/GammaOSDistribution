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

import com.google.auto.value.AutoValue;
import com.google.common.collect.ImmutableMap;
import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.FieldSpec;
import com.squareup.javapoet.TypeSpec;
import dagger.internal.codegen.binding.ComponentRequirement;

/** The implementation of a component creator type. */
@AutoValue
public abstract class ComponentCreatorImplementation {

  /** Creates a new {@link ComponentCreatorImplementation}. */
  public static ComponentCreatorImplementation create(
      TypeSpec spec, ClassName name, ImmutableMap<ComponentRequirement, FieldSpec> fields) {
    return new AutoValue_ComponentCreatorImplementation(spec, name, fields);
  }

  /** The type spec for the creator implementation. */
  public abstract TypeSpec spec();

  /** The name of the creator implementation class. */
  public abstract ClassName name();

  /** All fields that are present in this implementation. */
  abstract ImmutableMap<ComponentRequirement, FieldSpec> fields();
}

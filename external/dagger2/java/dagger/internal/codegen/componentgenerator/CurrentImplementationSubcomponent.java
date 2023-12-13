/*
 * Copyright (C) 2018 The Dagger Authors.
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

package dagger.internal.codegen.componentgenerator;

import dagger.BindsInstance;
import dagger.Subcomponent;
import dagger.internal.codegen.binding.BindingGraph;
import dagger.internal.codegen.writing.ComponentBindingExpressions;
import dagger.internal.codegen.writing.ComponentImplementation;
import dagger.internal.codegen.writing.ComponentRequirementExpressions;
import dagger.internal.codegen.writing.ParentComponent;
import dagger.internal.codegen.writing.PerComponentImplementation;
import java.util.Optional;

/**
 * A subcomponent that injects all objects that are responsible for creating a single {@link
 * ComponentImplementation} instance. Each child {@link ComponentImplementation} will have its own
 * instance of {@link CurrentImplementationSubcomponent}.
 */
@Subcomponent
@PerComponentImplementation
// This only needs to be public because the type is referenced by generated component.
public interface CurrentImplementationSubcomponent {
  ComponentImplementationBuilder componentImplementationBuilder();

  /** Returns the builder for {@link CurrentImplementationSubcomponent}. */
  @Subcomponent.Builder
  interface Builder {
    @BindsInstance
    Builder componentImplementation(ComponentImplementation componentImplementation);

    @BindsInstance
    Builder bindingGraph(BindingGraph bindingGraph);

    @BindsInstance
    Builder parentBuilder(@ParentComponent Optional<ComponentImplementationBuilder> parentBuilder);

    @BindsInstance
    Builder parentBindingExpressions(
        @ParentComponent Optional<ComponentBindingExpressions> parentBindingExpressions);

    @BindsInstance
    Builder parentRequirementExpressions(
        @ParentComponent Optional<ComponentRequirementExpressions> parentRequirementExpressions);

    CurrentImplementationSubcomponent build();
  }
}

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

package dagger.hilt.processor.internal;

import static dagger.internal.codegen.extension.DaggerStreams.toImmutableList;

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.Iterables;
import com.google.common.graph.GraphBuilder;
import com.google.common.graph.Graphs;
import com.google.common.graph.ImmutableGraph;
import com.google.common.graph.MutableGraph;
import com.squareup.javapoet.ClassName;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/** A representation of the full tree of scopes. */
public final class ComponentTree {
  private final ImmutableGraph<ComponentDescriptor> graph;
  private final ComponentDescriptor root;

  /** Creates a new tree from a set of descriptors. */
  public static ComponentTree from(Set<ComponentDescriptor> descriptors) {
    MutableGraph<ComponentDescriptor> graph =
        GraphBuilder.directed().allowsSelfLoops(false).build();

    descriptors.forEach(
        descriptor -> {
          graph.addNode(descriptor);
          descriptor.parent().ifPresent(parent -> graph.putEdge(parent, descriptor));
        });

    return new ComponentTree(ImmutableGraph.copyOf(graph));
  }

  private ComponentTree(ImmutableGraph<ComponentDescriptor> graph) {
    this.graph = Preconditions.checkNotNull(graph);
    Preconditions.checkState(
        !Graphs.hasCycle(graph),
        "Component graph has cycles: %s",
        graph.nodes());

    // Check that each component has a unique descriptor
    Map<ClassName, ComponentDescriptor> descriptors = new HashMap<>();
    for (ComponentDescriptor descriptor : graph.nodes()) {
      if (descriptors.containsKey(descriptor.component())) {
        ComponentDescriptor prevDescriptor = descriptors.get(descriptor.component());
        Preconditions.checkState(
            // TODO(b/144939893): Use "==" instead of ".equals()"?
            descriptor.equals(prevDescriptor),
            "%s has mismatching descriptors:\n"
            + "    %s\n\n"
            + "    %s\n\n",
            prevDescriptor.component(),
            prevDescriptor,
            descriptor);
      }
      descriptors.put(descriptor.component(), descriptor);
    }

    ImmutableList<ComponentDescriptor> roots =
        graph.nodes().stream()
            .filter(node -> graph.inDegree(node) == 0)
            .collect(toImmutableList());

    Preconditions.checkState(
        roots.size() == 1,
        "Component graph must have exactly 1 root. Found: %s",
        roots.stream().map(ComponentDescriptor::component).collect(toImmutableList()));

    root = Iterables.getOnlyElement(roots);
  }

  public ImmutableSet<ComponentDescriptor> getComponentDescriptors() {
    return ImmutableSet.copyOf(graph.nodes());
  }

  public ImmutableSet<ComponentDescriptor> childrenOf(ComponentDescriptor componentDescriptor) {
    return ImmutableSet.copyOf(graph.successors(componentDescriptor));
  }

  public ImmutableGraph<ComponentDescriptor> graph() {
    return graph;
  }

  public ComponentDescriptor root() {
    return root;
  }
}

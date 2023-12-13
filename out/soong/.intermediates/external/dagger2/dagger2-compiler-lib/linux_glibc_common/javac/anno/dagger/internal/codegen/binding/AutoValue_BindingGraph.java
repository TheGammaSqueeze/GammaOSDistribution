package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_BindingGraph extends $AutoValue_BindingGraph {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSet<ComponentRequirement> componentRequirements;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<BindingGraph> subgraphs;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSet<BindingNode> bindingNodes;

  AutoValue_BindingGraph(dagger.model.BindingGraph.ComponentNode componentNode$,
      BindingGraph.TopLevelBindingGraph topLevelBindingGraph$) {
    super(componentNode$, topLevelBindingGraph$);
  }

  @Override
  public ImmutableSet<ComponentRequirement> componentRequirements() {
    if (componentRequirements == null) {
      synchronized (this) {
        if (componentRequirements == null) {
          componentRequirements = super.componentRequirements();
          if (componentRequirements == null) {
            throw new NullPointerException("componentRequirements() cannot return null");
          }
        }
      }
    }
    return componentRequirements;
  }

  @Override
  public ImmutableList<BindingGraph> subgraphs() {
    if (subgraphs == null) {
      synchronized (this) {
        if (subgraphs == null) {
          subgraphs = super.subgraphs();
          if (subgraphs == null) {
            throw new NullPointerException("subgraphs() cannot return null");
          }
        }
      }
    }
    return subgraphs;
  }

  @Override
  public ImmutableSet<BindingNode> bindingNodes() {
    if (bindingNodes == null) {
      synchronized (this) {
        if (bindingNodes == null) {
          bindingNodes = super.bindingNodes();
          if (bindingNodes == null) {
            throw new NullPointerException("bindingNodes() cannot return null");
          }
        }
      }
    }
    return bindingNodes;
  }
}

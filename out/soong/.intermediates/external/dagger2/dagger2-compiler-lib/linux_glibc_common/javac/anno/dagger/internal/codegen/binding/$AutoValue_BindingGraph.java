package dagger.internal.codegen.binding;

import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_BindingGraph extends BindingGraph {

  private final dagger.model.BindingGraph.ComponentNode componentNode;

  private final dagger.internal.codegen.binding.BindingGraph.TopLevelBindingGraph topLevelBindingGraph;

  $AutoValue_BindingGraph(
      dagger.model.BindingGraph.ComponentNode componentNode,
      dagger.internal.codegen.binding.BindingGraph.TopLevelBindingGraph topLevelBindingGraph) {
    if (componentNode == null) {
      throw new NullPointerException("Null componentNode");
    }
    this.componentNode = componentNode;
    if (topLevelBindingGraph == null) {
      throw new NullPointerException("Null topLevelBindingGraph");
    }
    this.topLevelBindingGraph = topLevelBindingGraph;
  }

  @Override
  public dagger.model.BindingGraph.ComponentNode componentNode() {
    return componentNode;
  }

  @Override
  public dagger.internal.codegen.binding.BindingGraph.TopLevelBindingGraph topLevelBindingGraph() {
    return topLevelBindingGraph;
  }

  @Override
  public String toString() {
    return "BindingGraph{"
        + "componentNode=" + componentNode + ", "
        + "topLevelBindingGraph=" + topLevelBindingGraph
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof BindingGraph) {
      BindingGraph that = (BindingGraph) o;
      return this.componentNode.equals(that.componentNode())
          && this.topLevelBindingGraph.equals(that.topLevelBindingGraph());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= componentNode.hashCode();
    h$ *= 1000003;
    h$ ^= topLevelBindingGraph.hashCode();
    return h$;
  }

}

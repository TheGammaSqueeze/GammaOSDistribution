package dagger.internal.codegen.binding;

import com.google.common.graph.ImmutableNetwork;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_BindingGraph_TopLevelBindingGraph extends BindingGraph.TopLevelBindingGraph {

  private final ImmutableNetwork<dagger.model.BindingGraph.Node, dagger.model.BindingGraph.Edge> network;

  private final boolean isFullBindingGraph;

  $AutoValue_BindingGraph_TopLevelBindingGraph(
      ImmutableNetwork<dagger.model.BindingGraph.Node, dagger.model.BindingGraph.Edge> network,
      boolean isFullBindingGraph) {
    if (network == null) {
      throw new NullPointerException("Null network");
    }
    this.network = network;
    this.isFullBindingGraph = isFullBindingGraph;
  }

  @Override
  public ImmutableNetwork<dagger.model.BindingGraph.Node, dagger.model.BindingGraph.Edge> network() {
    return network;
  }

  @Override
  public boolean isFullBindingGraph() {
    return isFullBindingGraph;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof BindingGraph.TopLevelBindingGraph) {
      BindingGraph.TopLevelBindingGraph that = (BindingGraph.TopLevelBindingGraph) o;
      return this.network.equals(that.network())
          && this.isFullBindingGraph == that.isFullBindingGraph();
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= network.hashCode();
    h$ *= 1000003;
    h$ ^= isFullBindingGraph ? 1231 : 1237;
    return h$;
  }

}

package dagger.model;

import com.google.common.graph.ImmutableNetwork;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_BindingGraphProxies_BindingGraphImpl extends BindingGraphProxies.BindingGraphImpl {

  private final ImmutableNetwork<BindingGraph.Node, BindingGraph.Edge> network;

  private final boolean isFullBindingGraph;

  $AutoValue_BindingGraphProxies_BindingGraphImpl(
      ImmutableNetwork<BindingGraph.Node, BindingGraph.Edge> network,
      boolean isFullBindingGraph) {
    if (network == null) {
      throw new NullPointerException("Null network");
    }
    this.network = network;
    this.isFullBindingGraph = isFullBindingGraph;
  }

  @Override
  public ImmutableNetwork<BindingGraph.Node, BindingGraph.Edge> network() {
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
    if (o instanceof BindingGraphProxies.BindingGraphImpl) {
      BindingGraphProxies.BindingGraphImpl that = (BindingGraphProxies.BindingGraphImpl) o;
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

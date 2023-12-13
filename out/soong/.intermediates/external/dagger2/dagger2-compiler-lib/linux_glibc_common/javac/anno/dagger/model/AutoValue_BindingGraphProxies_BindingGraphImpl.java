package dagger.model;

import com.google.common.collect.ImmutableSetMultimap;
import com.google.common.graph.ImmutableNetwork;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Class;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_BindingGraphProxies_BindingGraphImpl extends $AutoValue_BindingGraphProxies_BindingGraphImpl {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSetMultimap<Class<? extends BindingGraph.Node>, ? extends BindingGraph.Node> nodesByClass;

  AutoValue_BindingGraphProxies_BindingGraphImpl(
      ImmutableNetwork<BindingGraph.Node, BindingGraph.Edge> network$,
      boolean isFullBindingGraph$) {
    super(network$, isFullBindingGraph$);
  }

  @Override
  public ImmutableSetMultimap<Class<? extends BindingGraph.Node>, ? extends BindingGraph.Node> nodesByClass(
      ) {
    if (nodesByClass == null) {
      synchronized (this) {
        if (nodesByClass == null) {
          nodesByClass = super.nodesByClass();
          if (nodesByClass == null) {
            throw new NullPointerException("nodesByClass() cannot return null");
          }
        }
      }
    }
    return nodesByClass;
  }
}

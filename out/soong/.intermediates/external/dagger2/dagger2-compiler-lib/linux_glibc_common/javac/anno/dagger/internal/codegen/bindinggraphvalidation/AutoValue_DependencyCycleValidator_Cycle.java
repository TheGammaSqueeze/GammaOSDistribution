package dagger.internal.codegen.bindinggraphvalidation;

import com.google.common.collect.ImmutableSet;
import com.google.common.graph.EndpointPair;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_DependencyCycleValidator_Cycle<N> extends DependencyCycleValidator.Cycle<N> {

  private final ImmutableSet<EndpointPair<N>> endpointPairs;

  AutoValue_DependencyCycleValidator_Cycle(
      ImmutableSet<EndpointPair<N>> endpointPairs) {
    if (endpointPairs == null) {
      throw new NullPointerException("Null endpointPairs");
    }
    this.endpointPairs = endpointPairs;
  }

  @Override
  ImmutableSet<EndpointPair<N>> endpointPairs() {
    return endpointPairs;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof DependencyCycleValidator.Cycle) {
      DependencyCycleValidator.Cycle<?> that = (DependencyCycleValidator.Cycle<?>) o;
      return this.endpointPairs.equals(that.endpointPairs());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= endpointPairs.hashCode();
    return h$;
  }

}

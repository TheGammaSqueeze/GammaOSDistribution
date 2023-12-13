package dagger.internal.codegen.binding;

import dagger.model.ComponentPath;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_BindingGraphConverter_ResolvedBindingsWithPath extends BindingGraphConverter.ResolvedBindingsWithPath {

  private final ResolvedBindings resolvedBindings;

  private final ComponentPath componentPath;

  AutoValue_BindingGraphConverter_ResolvedBindingsWithPath(
      ResolvedBindings resolvedBindings,
      ComponentPath componentPath) {
    if (resolvedBindings == null) {
      throw new NullPointerException("Null resolvedBindings");
    }
    this.resolvedBindings = resolvedBindings;
    if (componentPath == null) {
      throw new NullPointerException("Null componentPath");
    }
    this.componentPath = componentPath;
  }

  @Override
  ResolvedBindings resolvedBindings() {
    return resolvedBindings;
  }

  @Override
  ComponentPath componentPath() {
    return componentPath;
  }

  @Override
  public String toString() {
    return "ResolvedBindingsWithPath{"
        + "resolvedBindings=" + resolvedBindings + ", "
        + "componentPath=" + componentPath
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof BindingGraphConverter.ResolvedBindingsWithPath) {
      BindingGraphConverter.ResolvedBindingsWithPath that = (BindingGraphConverter.ResolvedBindingsWithPath) o;
      return this.resolvedBindings.equals(that.resolvedBindings())
          && this.componentPath.equals(that.componentPath());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= resolvedBindings.hashCode();
    h$ *= 1000003;
    h$ ^= componentPath.hashCode();
    return h$;
  }

}

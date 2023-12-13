package dagger.internal.codegen.binding;

import dagger.model.ComponentPath;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ComponentNodeImpl extends ComponentNodeImpl {

  private final ComponentPath componentPath;

  private final ComponentDescriptor componentDescriptor;

  AutoValue_ComponentNodeImpl(
      ComponentPath componentPath,
      ComponentDescriptor componentDescriptor) {
    if (componentPath == null) {
      throw new NullPointerException("Null componentPath");
    }
    this.componentPath = componentPath;
    if (componentDescriptor == null) {
      throw new NullPointerException("Null componentDescriptor");
    }
    this.componentDescriptor = componentDescriptor;
  }

  @Override
  public ComponentPath componentPath() {
    return componentPath;
  }

  @Override
  public ComponentDescriptor componentDescriptor() {
    return componentDescriptor;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ComponentNodeImpl) {
      ComponentNodeImpl that = (ComponentNodeImpl) o;
      return this.componentPath.equals(that.componentPath())
          && this.componentDescriptor.equals(that.componentDescriptor());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= componentPath.hashCode();
    h$ *= 1000003;
    h$ ^= componentDescriptor.hashCode();
    return h$;
  }

}

package dagger.model;

import com.google.common.collect.ImmutableList;
import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ComponentPath extends ComponentPath {

  private final ImmutableList<TypeElement> components;

  $AutoValue_ComponentPath(
      ImmutableList<TypeElement> components) {
    if (components == null) {
      throw new NullPointerException("Null components");
    }
    this.components = components;
  }

  @Override
  public ImmutableList<TypeElement> components() {
    return components;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ComponentPath) {
      ComponentPath that = (ComponentPath) o;
      return this.components.equals(that.components());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= components.hashCode();
    return h$;
  }

}

package dagger.internal.codegen.binding;

import dagger.model.ComponentPath;
import dagger.model.Key;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_BindingGraphConverter_MissingBindingImpl extends BindingGraphConverter.MissingBindingImpl {

  private final ComponentPath componentPath;

  private final Key key;

  $AutoValue_BindingGraphConverter_MissingBindingImpl(
      ComponentPath componentPath,
      Key key) {
    if (componentPath == null) {
      throw new NullPointerException("Null componentPath");
    }
    this.componentPath = componentPath;
    if (key == null) {
      throw new NullPointerException("Null key");
    }
    this.key = key;
  }

  @Override
  public ComponentPath componentPath() {
    return componentPath;
  }

  @Override
  public Key key() {
    return key;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof BindingGraphConverter.MissingBindingImpl) {
      BindingGraphConverter.MissingBindingImpl that = (BindingGraphConverter.MissingBindingImpl) o;
      return this.componentPath.equals(that.componentPath())
          && this.key.equals(that.key());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= componentPath.hashCode();
    h$ *= 1000003;
    h$ ^= key.hashCode();
    return h$;
  }

}

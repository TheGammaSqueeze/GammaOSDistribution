package dagger.internal.codegen.componentgenerator;

import com.google.common.base.Equivalence;
import com.google.common.collect.ImmutableList;
import javax.annotation.Generated;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_MethodSignature extends MethodSignature {

  private final String name;

  private final ImmutableList<? extends Equivalence.Wrapper<? extends TypeMirror>> parameterTypes;

  private final ImmutableList<? extends Equivalence.Wrapper<? extends TypeMirror>> thrownTypes;

  AutoValue_MethodSignature(
      String name,
      ImmutableList<? extends Equivalence.Wrapper<? extends TypeMirror>> parameterTypes,
      ImmutableList<? extends Equivalence.Wrapper<? extends TypeMirror>> thrownTypes) {
    if (name == null) {
      throw new NullPointerException("Null name");
    }
    this.name = name;
    if (parameterTypes == null) {
      throw new NullPointerException("Null parameterTypes");
    }
    this.parameterTypes = parameterTypes;
    if (thrownTypes == null) {
      throw new NullPointerException("Null thrownTypes");
    }
    this.thrownTypes = thrownTypes;
  }

  @Override
  String name() {
    return name;
  }

  @Override
  ImmutableList<? extends Equivalence.Wrapper<? extends TypeMirror>> parameterTypes() {
    return parameterTypes;
  }

  @Override
  ImmutableList<? extends Equivalence.Wrapper<? extends TypeMirror>> thrownTypes() {
    return thrownTypes;
  }

  @Override
  public String toString() {
    return "MethodSignature{"
        + "name=" + name + ", "
        + "parameterTypes=" + parameterTypes + ", "
        + "thrownTypes=" + thrownTypes
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof MethodSignature) {
      MethodSignature that = (MethodSignature) o;
      return this.name.equals(that.name())
          && this.parameterTypes.equals(that.parameterTypes())
          && this.thrownTypes.equals(that.thrownTypes());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= name.hashCode();
    h$ *= 1000003;
    h$ ^= parameterTypes.hashCode();
    h$ *= 1000003;
    h$ ^= thrownTypes.hashCode();
    return h$;
  }

}

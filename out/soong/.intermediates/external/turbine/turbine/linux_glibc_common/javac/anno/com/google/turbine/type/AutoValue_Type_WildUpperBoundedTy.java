package com.google.turbine.type;

import com.google.common.collect.ImmutableList;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Type_WildUpperBoundedTy extends Type.WildUpperBoundedTy {

  private final ImmutableList<AnnoInfo> annotations;

  private final Type bound;

  AutoValue_Type_WildUpperBoundedTy(
      ImmutableList<AnnoInfo> annotations,
      Type bound) {
    if (annotations == null) {
      throw new NullPointerException("Null annotations");
    }
    this.annotations = annotations;
    if (bound == null) {
      throw new NullPointerException("Null bound");
    }
    this.bound = bound;
  }

  @Override
  public ImmutableList<AnnoInfo> annotations() {
    return annotations;
  }

  @Override
  public Type bound() {
    return bound;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Type.WildUpperBoundedTy) {
      Type.WildUpperBoundedTy that = (Type.WildUpperBoundedTy) o;
      return this.annotations.equals(that.annotations())
          && this.bound.equals(that.bound());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= annotations.hashCode();
    h$ *= 1000003;
    h$ ^= bound.hashCode();
    return h$;
  }

}

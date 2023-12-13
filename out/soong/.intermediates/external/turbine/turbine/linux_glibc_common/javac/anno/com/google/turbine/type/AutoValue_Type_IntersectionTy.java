package com.google.turbine.type;

import com.google.common.collect.ImmutableList;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Type_IntersectionTy extends Type.IntersectionTy {

  private final ImmutableList<Type> bounds;

  AutoValue_Type_IntersectionTy(
      ImmutableList<Type> bounds) {
    if (bounds == null) {
      throw new NullPointerException("Null bounds");
    }
    this.bounds = bounds;
  }

  @Override
  public ImmutableList<Type> bounds() {
    return bounds;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Type.IntersectionTy) {
      Type.IntersectionTy that = (Type.IntersectionTy) o;
      return this.bounds.equals(that.bounds());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= bounds.hashCode();
    return h$;
  }

}

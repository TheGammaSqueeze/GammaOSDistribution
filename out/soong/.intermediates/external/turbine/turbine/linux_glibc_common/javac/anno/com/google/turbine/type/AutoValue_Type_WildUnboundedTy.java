package com.google.turbine.type;

import com.google.common.collect.ImmutableList;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Type_WildUnboundedTy extends Type.WildUnboundedTy {

  private final ImmutableList<AnnoInfo> annotations;

  AutoValue_Type_WildUnboundedTy(
      ImmutableList<AnnoInfo> annotations) {
    if (annotations == null) {
      throw new NullPointerException("Null annotations");
    }
    this.annotations = annotations;
  }

  @Override
  public ImmutableList<AnnoInfo> annotations() {
    return annotations;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Type.WildUnboundedTy) {
      Type.WildUnboundedTy that = (Type.WildUnboundedTy) o;
      return this.annotations.equals(that.annotations());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= annotations.hashCode();
    return h$;
  }

}

package com.google.turbine.type;

import com.google.common.collect.ImmutableList;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Type_ArrayTy extends Type.ArrayTy {

  private final Type elementType;

  private final ImmutableList<AnnoInfo> annos;

  AutoValue_Type_ArrayTy(
      Type elementType,
      ImmutableList<AnnoInfo> annos) {
    if (elementType == null) {
      throw new NullPointerException("Null elementType");
    }
    this.elementType = elementType;
    if (annos == null) {
      throw new NullPointerException("Null annos");
    }
    this.annos = annos;
  }

  @Override
  public Type elementType() {
    return elementType;
  }

  @Override
  public ImmutableList<AnnoInfo> annos() {
    return annos;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Type.ArrayTy) {
      Type.ArrayTy that = (Type.ArrayTy) o;
      return this.elementType.equals(that.elementType())
          && this.annos.equals(that.annos());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= elementType.hashCode();
    h$ *= 1000003;
    h$ ^= annos.hashCode();
    return h$;
  }

}

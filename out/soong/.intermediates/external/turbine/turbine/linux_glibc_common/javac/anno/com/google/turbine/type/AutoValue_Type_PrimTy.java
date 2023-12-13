package com.google.turbine.type;

import com.google.common.collect.ImmutableList;
import com.google.turbine.model.TurbineConstantTypeKind;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Type_PrimTy extends Type.PrimTy {

  private final TurbineConstantTypeKind primkind;

  private final ImmutableList<AnnoInfo> annos;

  AutoValue_Type_PrimTy(
      TurbineConstantTypeKind primkind,
      ImmutableList<AnnoInfo> annos) {
    if (primkind == null) {
      throw new NullPointerException("Null primkind");
    }
    this.primkind = primkind;
    if (annos == null) {
      throw new NullPointerException("Null annos");
    }
    this.annos = annos;
  }

  @Override
  public TurbineConstantTypeKind primkind() {
    return primkind;
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
    if (o instanceof Type.PrimTy) {
      Type.PrimTy that = (Type.PrimTy) o;
      return this.primkind.equals(that.primkind())
          && this.annos.equals(that.annos());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= primkind.hashCode();
    h$ *= 1000003;
    h$ ^= annos.hashCode();
    return h$;
  }

}

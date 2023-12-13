package com.google.turbine.type;

import com.google.common.collect.ImmutableList;
import com.google.turbine.binder.sym.TyVarSymbol;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Type_TyVar extends Type.TyVar {

  private final TyVarSymbol sym;

  private final ImmutableList<AnnoInfo> annos;

  AutoValue_Type_TyVar(
      TyVarSymbol sym,
      ImmutableList<AnnoInfo> annos) {
    if (sym == null) {
      throw new NullPointerException("Null sym");
    }
    this.sym = sym;
    if (annos == null) {
      throw new NullPointerException("Null annos");
    }
    this.annos = annos;
  }

  @Override
  public TyVarSymbol sym() {
    return sym;
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
    if (o instanceof Type.TyVar) {
      Type.TyVar that = (Type.TyVar) o;
      return this.sym.equals(that.sym())
          && this.annos.equals(that.annos());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= sym.hashCode();
    h$ *= 1000003;
    h$ ^= annos.hashCode();
    return h$;
  }

}

package com.google.turbine.type;

import com.google.common.collect.ImmutableList;
import com.google.turbine.binder.sym.ClassSymbol;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Type_ClassTy_SimpleClassTy extends Type.ClassTy.SimpleClassTy {

  private final ClassSymbol sym;

  private final ImmutableList<Type> targs;

  private final ImmutableList<AnnoInfo> annos;

  AutoValue_Type_ClassTy_SimpleClassTy(
      ClassSymbol sym,
      ImmutableList<Type> targs,
      ImmutableList<AnnoInfo> annos) {
    if (sym == null) {
      throw new NullPointerException("Null sym");
    }
    this.sym = sym;
    if (targs == null) {
      throw new NullPointerException("Null targs");
    }
    this.targs = targs;
    if (annos == null) {
      throw new NullPointerException("Null annos");
    }
    this.annos = annos;
  }

  @Override
  public ClassSymbol sym() {
    return sym;
  }

  @Override
  public ImmutableList<Type> targs() {
    return targs;
  }

  @Override
  public ImmutableList<AnnoInfo> annos() {
    return annos;
  }

  @Override
  public String toString() {
    return "SimpleClassTy{"
        + "sym=" + sym + ", "
        + "targs=" + targs + ", "
        + "annos=" + annos
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Type.ClassTy.SimpleClassTy) {
      Type.ClassTy.SimpleClassTy that = (Type.ClassTy.SimpleClassTy) o;
      return this.sym.equals(that.sym())
          && this.targs.equals(that.targs())
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
    h$ ^= targs.hashCode();
    h$ *= 1000003;
    h$ ^= annos.hashCode();
    return h$;
  }

}

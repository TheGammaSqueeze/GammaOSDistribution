package com.google.turbine.type;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.turbine.binder.sym.TyVarSymbol;
import javax.annotation.processing.Generated;
import org.checkerframework.checker.nullness.qual.Nullable;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Type_MethodTy extends Type.MethodTy {

  private final ImmutableSet<TyVarSymbol> tyParams;

  private final Type returnType;

  private final @Nullable Type receiverType;

  private final ImmutableList<Type> parameters;

  private final ImmutableList<Type> thrown;

  AutoValue_Type_MethodTy(
      ImmutableSet<TyVarSymbol> tyParams,
      Type returnType,
      @Nullable Type receiverType,
      ImmutableList<Type> parameters,
      ImmutableList<Type> thrown) {
    if (tyParams == null) {
      throw new NullPointerException("Null tyParams");
    }
    this.tyParams = tyParams;
    if (returnType == null) {
      throw new NullPointerException("Null returnType");
    }
    this.returnType = returnType;
    this.receiverType = receiverType;
    if (parameters == null) {
      throw new NullPointerException("Null parameters");
    }
    this.parameters = parameters;
    if (thrown == null) {
      throw new NullPointerException("Null thrown");
    }
    this.thrown = thrown;
  }

  @Override
  public ImmutableSet<TyVarSymbol> tyParams() {
    return tyParams;
  }

  @Override
  public Type returnType() {
    return returnType;
  }

  @Override
  public @Nullable Type receiverType() {
    return receiverType;
  }

  @Override
  public ImmutableList<Type> parameters() {
    return parameters;
  }

  @Override
  public ImmutableList<Type> thrown() {
    return thrown;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Type.MethodTy) {
      Type.MethodTy that = (Type.MethodTy) o;
      return this.tyParams.equals(that.tyParams())
          && this.returnType.equals(that.returnType())
          && (this.receiverType == null ? that.receiverType() == null : this.receiverType.equals(that.receiverType()))
          && this.parameters.equals(that.parameters())
          && this.thrown.equals(that.thrown());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= tyParams.hashCode();
    h$ *= 1000003;
    h$ ^= returnType.hashCode();
    h$ *= 1000003;
    h$ ^= (receiverType == null) ? 0 : receiverType.hashCode();
    h$ *= 1000003;
    h$ ^= parameters.hashCode();
    h$ *= 1000003;
    h$ ^= thrown.hashCode();
    return h$;
  }

}

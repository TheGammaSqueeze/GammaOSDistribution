package com.google.turbine.type;

import com.google.common.collect.ImmutableList;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Type_ClassTy extends Type.ClassTy {

  private final ImmutableList<Type.ClassTy.SimpleClassTy> classes;

  AutoValue_Type_ClassTy(
      ImmutableList<Type.ClassTy.SimpleClassTy> classes) {
    if (classes == null) {
      throw new NullPointerException("Null classes");
    }
    this.classes = classes;
  }

  @Override
  public ImmutableList<Type.ClassTy.SimpleClassTy> classes() {
    return classes;
  }

}

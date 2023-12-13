package com.google.auto.factory.processor;

import com.google.common.collect.ImmutableSet;
import javax.annotation.processing.Generated;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ImplementationMethodDescriptor extends ImplementationMethodDescriptor {

  private final String name;

  private final TypeMirror returnType;

  private final boolean publicMethod;

  private final ImmutableSet<Parameter> passedParameters;

  private final boolean isVarArgs;

  private AutoValue_ImplementationMethodDescriptor(
      String name,
      TypeMirror returnType,
      boolean publicMethod,
      ImmutableSet<Parameter> passedParameters,
      boolean isVarArgs) {
    this.name = name;
    this.returnType = returnType;
    this.publicMethod = publicMethod;
    this.passedParameters = passedParameters;
    this.isVarArgs = isVarArgs;
  }

  @Override
  String name() {
    return name;
  }

  @Override
  TypeMirror returnType() {
    return returnType;
  }

  @Override
  boolean publicMethod() {
    return publicMethod;
  }

  @Override
  ImmutableSet<Parameter> passedParameters() {
    return passedParameters;
  }

  @Override
  boolean isVarArgs() {
    return isVarArgs;
  }

  @Override
  public String toString() {
    return "ImplementationMethodDescriptor{"
        + "name=" + name + ", "
        + "returnType=" + returnType + ", "
        + "publicMethod=" + publicMethod + ", "
        + "passedParameters=" + passedParameters + ", "
        + "isVarArgs=" + isVarArgs
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ImplementationMethodDescriptor) {
      ImplementationMethodDescriptor that = (ImplementationMethodDescriptor) o;
      return this.name.equals(that.name())
          && this.returnType.equals(that.returnType())
          && this.publicMethod == that.publicMethod()
          && this.passedParameters.equals(that.passedParameters())
          && this.isVarArgs == that.isVarArgs();
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= name.hashCode();
    h$ *= 1000003;
    h$ ^= returnType.hashCode();
    h$ *= 1000003;
    h$ ^= publicMethod ? 1231 : 1237;
    h$ *= 1000003;
    h$ ^= passedParameters.hashCode();
    h$ *= 1000003;
    h$ ^= isVarArgs ? 1231 : 1237;
    return h$;
  }

  static final class Builder extends ImplementationMethodDescriptor.Builder {
    private String name;
    private TypeMirror returnType;
    private Boolean publicMethod;
    private ImmutableSet<Parameter> passedParameters;
    private Boolean isVarArgs;
    Builder() {
    }
    @Override
    ImplementationMethodDescriptor.Builder name(String name) {
      if (name == null) {
        throw new NullPointerException("Null name");
      }
      this.name = name;
      return this;
    }
    @Override
    ImplementationMethodDescriptor.Builder returnType(TypeMirror returnType) {
      if (returnType == null) {
        throw new NullPointerException("Null returnType");
      }
      this.returnType = returnType;
      return this;
    }
    @Override
    ImplementationMethodDescriptor.Builder publicMethod(boolean publicMethod) {
      this.publicMethod = publicMethod;
      return this;
    }
    @Override
    ImplementationMethodDescriptor.Builder passedParameters(Iterable<Parameter> passedParameters) {
      this.passedParameters = ImmutableSet.copyOf(passedParameters);
      return this;
    }
    @Override
    ImplementationMethodDescriptor.Builder isVarArgs(boolean isVarArgs) {
      this.isVarArgs = isVarArgs;
      return this;
    }
    @Override
    ImplementationMethodDescriptor build() {
      String missing = "";
      if (this.name == null) {
        missing += " name";
      }
      if (this.returnType == null) {
        missing += " returnType";
      }
      if (this.publicMethod == null) {
        missing += " publicMethod";
      }
      if (this.passedParameters == null) {
        missing += " passedParameters";
      }
      if (this.isVarArgs == null) {
        missing += " isVarArgs";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_ImplementationMethodDescriptor(
          this.name,
          this.returnType,
          this.publicMethod,
          this.passedParameters,
          this.isVarArgs);
    }
  }

}

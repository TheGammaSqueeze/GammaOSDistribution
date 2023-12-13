package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableList;
import javax.annotation.Generated;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.DeclaredType;
import javax.lang.model.type.ExecutableType;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_AssistedInjectionAnnotations_AssistedFactoryMetadata extends AssistedInjectionAnnotations.AssistedFactoryMetadata {

  private final TypeElement factory;

  private final DeclaredType factoryType;

  private final ExecutableElement factoryMethod;

  private final ExecutableType factoryMethodType;

  private final TypeElement assistedInjectElement;

  private final DeclaredType assistedInjectType;

  private final ImmutableList<AssistedInjectionAnnotations.AssistedParameter> assistedInjectAssistedParameters;

  private final ImmutableList<AssistedInjectionAnnotations.AssistedParameter> assistedFactoryAssistedParameters;

  $AutoValue_AssistedInjectionAnnotations_AssistedFactoryMetadata(
      TypeElement factory,
      DeclaredType factoryType,
      ExecutableElement factoryMethod,
      ExecutableType factoryMethodType,
      TypeElement assistedInjectElement,
      DeclaredType assistedInjectType,
      ImmutableList<AssistedInjectionAnnotations.AssistedParameter> assistedInjectAssistedParameters,
      ImmutableList<AssistedInjectionAnnotations.AssistedParameter> assistedFactoryAssistedParameters) {
    if (factory == null) {
      throw new NullPointerException("Null factory");
    }
    this.factory = factory;
    if (factoryType == null) {
      throw new NullPointerException("Null factoryType");
    }
    this.factoryType = factoryType;
    if (factoryMethod == null) {
      throw new NullPointerException("Null factoryMethod");
    }
    this.factoryMethod = factoryMethod;
    if (factoryMethodType == null) {
      throw new NullPointerException("Null factoryMethodType");
    }
    this.factoryMethodType = factoryMethodType;
    if (assistedInjectElement == null) {
      throw new NullPointerException("Null assistedInjectElement");
    }
    this.assistedInjectElement = assistedInjectElement;
    if (assistedInjectType == null) {
      throw new NullPointerException("Null assistedInjectType");
    }
    this.assistedInjectType = assistedInjectType;
    if (assistedInjectAssistedParameters == null) {
      throw new NullPointerException("Null assistedInjectAssistedParameters");
    }
    this.assistedInjectAssistedParameters = assistedInjectAssistedParameters;
    if (assistedFactoryAssistedParameters == null) {
      throw new NullPointerException("Null assistedFactoryAssistedParameters");
    }
    this.assistedFactoryAssistedParameters = assistedFactoryAssistedParameters;
  }

  @Override
  public TypeElement factory() {
    return factory;
  }

  @Override
  public DeclaredType factoryType() {
    return factoryType;
  }

  @Override
  public ExecutableElement factoryMethod() {
    return factoryMethod;
  }

  @Override
  public ExecutableType factoryMethodType() {
    return factoryMethodType;
  }

  @Override
  public TypeElement assistedInjectElement() {
    return assistedInjectElement;
  }

  @Override
  public DeclaredType assistedInjectType() {
    return assistedInjectType;
  }

  @Override
  public ImmutableList<AssistedInjectionAnnotations.AssistedParameter> assistedInjectAssistedParameters() {
    return assistedInjectAssistedParameters;
  }

  @Override
  public ImmutableList<AssistedInjectionAnnotations.AssistedParameter> assistedFactoryAssistedParameters() {
    return assistedFactoryAssistedParameters;
  }

  @Override
  public String toString() {
    return "AssistedFactoryMetadata{"
        + "factory=" + factory + ", "
        + "factoryType=" + factoryType + ", "
        + "factoryMethod=" + factoryMethod + ", "
        + "factoryMethodType=" + factoryMethodType + ", "
        + "assistedInjectElement=" + assistedInjectElement + ", "
        + "assistedInjectType=" + assistedInjectType + ", "
        + "assistedInjectAssistedParameters=" + assistedInjectAssistedParameters + ", "
        + "assistedFactoryAssistedParameters=" + assistedFactoryAssistedParameters
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof AssistedInjectionAnnotations.AssistedFactoryMetadata) {
      AssistedInjectionAnnotations.AssistedFactoryMetadata that = (AssistedInjectionAnnotations.AssistedFactoryMetadata) o;
      return this.factory.equals(that.factory())
          && this.factoryType.equals(that.factoryType())
          && this.factoryMethod.equals(that.factoryMethod())
          && this.factoryMethodType.equals(that.factoryMethodType())
          && this.assistedInjectElement.equals(that.assistedInjectElement())
          && this.assistedInjectType.equals(that.assistedInjectType())
          && this.assistedInjectAssistedParameters.equals(that.assistedInjectAssistedParameters())
          && this.assistedFactoryAssistedParameters.equals(that.assistedFactoryAssistedParameters());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= factory.hashCode();
    h$ *= 1000003;
    h$ ^= factoryType.hashCode();
    h$ *= 1000003;
    h$ ^= factoryMethod.hashCode();
    h$ *= 1000003;
    h$ ^= factoryMethodType.hashCode();
    h$ *= 1000003;
    h$ ^= assistedInjectElement.hashCode();
    h$ *= 1000003;
    h$ ^= assistedInjectType.hashCode();
    h$ *= 1000003;
    h$ ^= assistedInjectAssistedParameters.hashCode();
    h$ *= 1000003;
    h$ ^= assistedFactoryAssistedParameters.hashCode();
    return h$;
  }

}

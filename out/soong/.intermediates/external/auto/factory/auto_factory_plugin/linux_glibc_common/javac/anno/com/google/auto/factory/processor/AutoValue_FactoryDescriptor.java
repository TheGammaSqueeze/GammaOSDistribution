package com.google.auto.factory.processor;

import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import javax.annotation.processing.Generated;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_FactoryDescriptor extends FactoryDescriptor {

  private final PackageAndClass name;

  private final TypeMirror extendingType;

  private final ImmutableSet<TypeMirror> implementingTypes;

  private final boolean publicType;

  private final ImmutableSet<FactoryMethodDescriptor> methodDescriptors;

  private final ImmutableSet<ImplementationMethodDescriptor> implementationMethodDescriptors;

  private final boolean allowSubclasses;

  private final ImmutableMap<Key, ProviderField> providers;

  AutoValue_FactoryDescriptor(
      PackageAndClass name,
      TypeMirror extendingType,
      ImmutableSet<TypeMirror> implementingTypes,
      boolean publicType,
      ImmutableSet<FactoryMethodDescriptor> methodDescriptors,
      ImmutableSet<ImplementationMethodDescriptor> implementationMethodDescriptors,
      boolean allowSubclasses,
      ImmutableMap<Key, ProviderField> providers) {
    if (name == null) {
      throw new NullPointerException("Null name");
    }
    this.name = name;
    if (extendingType == null) {
      throw new NullPointerException("Null extendingType");
    }
    this.extendingType = extendingType;
    if (implementingTypes == null) {
      throw new NullPointerException("Null implementingTypes");
    }
    this.implementingTypes = implementingTypes;
    this.publicType = publicType;
    if (methodDescriptors == null) {
      throw new NullPointerException("Null methodDescriptors");
    }
    this.methodDescriptors = methodDescriptors;
    if (implementationMethodDescriptors == null) {
      throw new NullPointerException("Null implementationMethodDescriptors");
    }
    this.implementationMethodDescriptors = implementationMethodDescriptors;
    this.allowSubclasses = allowSubclasses;
    if (providers == null) {
      throw new NullPointerException("Null providers");
    }
    this.providers = providers;
  }

  @Override
  PackageAndClass name() {
    return name;
  }

  @Override
  TypeMirror extendingType() {
    return extendingType;
  }

  @Override
  ImmutableSet<TypeMirror> implementingTypes() {
    return implementingTypes;
  }

  @Override
  boolean publicType() {
    return publicType;
  }

  @Override
  ImmutableSet<FactoryMethodDescriptor> methodDescriptors() {
    return methodDescriptors;
  }

  @Override
  ImmutableSet<ImplementationMethodDescriptor> implementationMethodDescriptors() {
    return implementationMethodDescriptors;
  }

  @Override
  boolean allowSubclasses() {
    return allowSubclasses;
  }

  @Override
  ImmutableMap<Key, ProviderField> providers() {
    return providers;
  }

  @Override
  public String toString() {
    return "FactoryDescriptor{"
        + "name=" + name + ", "
        + "extendingType=" + extendingType + ", "
        + "implementingTypes=" + implementingTypes + ", "
        + "publicType=" + publicType + ", "
        + "methodDescriptors=" + methodDescriptors + ", "
        + "implementationMethodDescriptors=" + implementationMethodDescriptors + ", "
        + "allowSubclasses=" + allowSubclasses + ", "
        + "providers=" + providers
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof FactoryDescriptor) {
      FactoryDescriptor that = (FactoryDescriptor) o;
      return this.name.equals(that.name())
          && this.extendingType.equals(that.extendingType())
          && this.implementingTypes.equals(that.implementingTypes())
          && this.publicType == that.publicType()
          && this.methodDescriptors.equals(that.methodDescriptors())
          && this.implementationMethodDescriptors.equals(that.implementationMethodDescriptors())
          && this.allowSubclasses == that.allowSubclasses()
          && this.providers.equals(that.providers());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= name.hashCode();
    h$ *= 1000003;
    h$ ^= extendingType.hashCode();
    h$ *= 1000003;
    h$ ^= implementingTypes.hashCode();
    h$ *= 1000003;
    h$ ^= publicType ? 1231 : 1237;
    h$ *= 1000003;
    h$ ^= methodDescriptors.hashCode();
    h$ *= 1000003;
    h$ ^= implementationMethodDescriptors.hashCode();
    h$ *= 1000003;
    h$ ^= allowSubclasses ? 1231 : 1237;
    h$ *= 1000003;
    h$ ^= providers.hashCode();
    return h$;
  }

}

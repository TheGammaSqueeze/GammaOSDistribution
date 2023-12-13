package com.google.auto.factory.processor;

import com.google.common.base.Optional;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import javax.annotation.processing.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.AnnotationValue;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_AutoFactoryDeclaration extends AutoFactoryDeclaration {

  private final TypeElement targetType;

  private final Element target;

  private final Optional<String> className;

  private final TypeElement extendingType;

  private final ImmutableSet<TypeElement> implementingTypes;

  private final boolean allowSubclasses;

  private final AnnotationMirror mirror;

  private final ImmutableMap<String, AnnotationValue> valuesMap;

  AutoValue_AutoFactoryDeclaration(
      TypeElement targetType,
      Element target,
      Optional<String> className,
      TypeElement extendingType,
      ImmutableSet<TypeElement> implementingTypes,
      boolean allowSubclasses,
      AnnotationMirror mirror,
      ImmutableMap<String, AnnotationValue> valuesMap) {
    if (targetType == null) {
      throw new NullPointerException("Null targetType");
    }
    this.targetType = targetType;
    if (target == null) {
      throw new NullPointerException("Null target");
    }
    this.target = target;
    if (className == null) {
      throw new NullPointerException("Null className");
    }
    this.className = className;
    if (extendingType == null) {
      throw new NullPointerException("Null extendingType");
    }
    this.extendingType = extendingType;
    if (implementingTypes == null) {
      throw new NullPointerException("Null implementingTypes");
    }
    this.implementingTypes = implementingTypes;
    this.allowSubclasses = allowSubclasses;
    if (mirror == null) {
      throw new NullPointerException("Null mirror");
    }
    this.mirror = mirror;
    if (valuesMap == null) {
      throw new NullPointerException("Null valuesMap");
    }
    this.valuesMap = valuesMap;
  }

  @Override
  TypeElement targetType() {
    return targetType;
  }

  @Override
  Element target() {
    return target;
  }

  @Override
  Optional<String> className() {
    return className;
  }

  @Override
  TypeElement extendingType() {
    return extendingType;
  }

  @Override
  ImmutableSet<TypeElement> implementingTypes() {
    return implementingTypes;
  }

  @Override
  boolean allowSubclasses() {
    return allowSubclasses;
  }

  @Override
  AnnotationMirror mirror() {
    return mirror;
  }

  @Override
  ImmutableMap<String, AnnotationValue> valuesMap() {
    return valuesMap;
  }

  @Override
  public String toString() {
    return "AutoFactoryDeclaration{"
        + "targetType=" + targetType + ", "
        + "target=" + target + ", "
        + "className=" + className + ", "
        + "extendingType=" + extendingType + ", "
        + "implementingTypes=" + implementingTypes + ", "
        + "allowSubclasses=" + allowSubclasses + ", "
        + "mirror=" + mirror + ", "
        + "valuesMap=" + valuesMap
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof AutoFactoryDeclaration) {
      AutoFactoryDeclaration that = (AutoFactoryDeclaration) o;
      return this.targetType.equals(that.targetType())
          && this.target.equals(that.target())
          && this.className.equals(that.className())
          && this.extendingType.equals(that.extendingType())
          && this.implementingTypes.equals(that.implementingTypes())
          && this.allowSubclasses == that.allowSubclasses()
          && this.mirror.equals(that.mirror())
          && this.valuesMap.equals(that.valuesMap());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= targetType.hashCode();
    h$ *= 1000003;
    h$ ^= target.hashCode();
    h$ *= 1000003;
    h$ ^= className.hashCode();
    h$ *= 1000003;
    h$ ^= extendingType.hashCode();
    h$ *= 1000003;
    h$ ^= implementingTypes.hashCode();
    h$ *= 1000003;
    h$ ^= allowSubclasses ? 1231 : 1237;
    h$ *= 1000003;
    h$ ^= mirror.hashCode();
    h$ *= 1000003;
    h$ ^= valuesMap.hashCode();
    return h$;
  }

}

package com.google.auto.factory.processor;

import com.google.common.base.Equivalence;
import com.google.common.base.Optional;
import javax.annotation.processing.Generated;
import javax.lang.model.element.AnnotationMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ProviderField extends ProviderField {

  private final String name;

  private final Key key;

  private final Optional<Equivalence.Wrapper<AnnotationMirror>> nullableWrapper;

  AutoValue_ProviderField(
      String name,
      Key key,
      Optional<Equivalence.Wrapper<AnnotationMirror>> nullableWrapper) {
    if (name == null) {
      throw new NullPointerException("Null name");
    }
    this.name = name;
    if (key == null) {
      throw new NullPointerException("Null key");
    }
    this.key = key;
    if (nullableWrapper == null) {
      throw new NullPointerException("Null nullableWrapper");
    }
    this.nullableWrapper = nullableWrapper;
  }

  @Override
  String name() {
    return name;
  }

  @Override
  Key key() {
    return key;
  }

  @Override
  Optional<Equivalence.Wrapper<AnnotationMirror>> nullableWrapper() {
    return nullableWrapper;
  }

  @Override
  public String toString() {
    return "ProviderField{"
        + "name=" + name + ", "
        + "key=" + key + ", "
        + "nullableWrapper=" + nullableWrapper
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ProviderField) {
      ProviderField that = (ProviderField) o;
      return this.name.equals(that.name())
          && this.key.equals(that.key())
          && this.nullableWrapper.equals(that.nullableWrapper());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= name.hashCode();
    h$ *= 1000003;
    h$ ^= key.hashCode();
    h$ *= 1000003;
    h$ ^= nullableWrapper.hashCode();
    return h$;
  }

}

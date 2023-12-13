package com.google.auto.factory.processor;

import com.google.common.base.Equivalence;
import com.google.common.base.Optional;
import javax.annotation.processing.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Key extends Key {

  private final Equivalence.Wrapper<TypeMirror> type;

  private final Optional<Equivalence.Wrapper<AnnotationMirror>> qualifierWrapper;

  AutoValue_Key(
      Equivalence.Wrapper<TypeMirror> type,
      Optional<Equivalence.Wrapper<AnnotationMirror>> qualifierWrapper) {
    if (type == null) {
      throw new NullPointerException("Null type");
    }
    this.type = type;
    if (qualifierWrapper == null) {
      throw new NullPointerException("Null qualifierWrapper");
    }
    this.qualifierWrapper = qualifierWrapper;
  }

  @Override
  Equivalence.Wrapper<TypeMirror> type() {
    return type;
  }

  @Override
  Optional<Equivalence.Wrapper<AnnotationMirror>> qualifierWrapper() {
    return qualifierWrapper;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Key) {
      Key that = (Key) o;
      return this.type.equals(that.type())
          && this.qualifierWrapper.equals(that.qualifierWrapper());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= type.hashCode();
    h$ *= 1000003;
    h$ ^= qualifierWrapper.hashCode();
    return h$;
  }

}

package dagger.internal.codegen.binding;

import com.google.common.base.Equivalence;
import javax.annotation.Generated;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_AssistedInjectionAnnotations_AssistedParameter extends AssistedInjectionAnnotations.AssistedParameter {

  private final String qualifier;

  private final Equivalence.Wrapper<TypeMirror> wrappedType;

  AutoValue_AssistedInjectionAnnotations_AssistedParameter(
      String qualifier,
      Equivalence.Wrapper<TypeMirror> wrappedType) {
    if (qualifier == null) {
      throw new NullPointerException("Null qualifier");
    }
    this.qualifier = qualifier;
    if (wrappedType == null) {
      throw new NullPointerException("Null wrappedType");
    }
    this.wrappedType = wrappedType;
  }

  @Override
  public String qualifier() {
    return qualifier;
  }

  @Override
  public Equivalence.Wrapper<TypeMirror> wrappedType() {
    return wrappedType;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof AssistedInjectionAnnotations.AssistedParameter) {
      AssistedInjectionAnnotations.AssistedParameter that = (AssistedInjectionAnnotations.AssistedParameter) o;
      return this.qualifier.equals(that.qualifier())
          && this.wrappedType.equals(that.wrappedType());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= qualifier.hashCode();
    h$ *= 1000003;
    h$ ^= wrappedType.hashCode();
    return h$;
  }

}

package dagger.internal.codegen.base;

import com.google.common.base.Equivalence;
import javax.annotation.Generated;
import javax.lang.model.type.DeclaredType;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_OptionalType extends OptionalType {

  private final Equivalence.Wrapper<DeclaredType> wrappedDeclaredOptionalType;

  AutoValue_OptionalType(
      Equivalence.Wrapper<DeclaredType> wrappedDeclaredOptionalType) {
    if (wrappedDeclaredOptionalType == null) {
      throw new NullPointerException("Null wrappedDeclaredOptionalType");
    }
    this.wrappedDeclaredOptionalType = wrappedDeclaredOptionalType;
  }

  @Deprecated
  @Override
  protected Equivalence.Wrapper<DeclaredType> wrappedDeclaredOptionalType() {
    return wrappedDeclaredOptionalType;
  }

  @Override
  public String toString() {
    return "OptionalType{"
        + "wrappedDeclaredOptionalType=" + wrappedDeclaredOptionalType
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof OptionalType) {
      OptionalType that = (OptionalType) o;
      return this.wrappedDeclaredOptionalType.equals(that.wrappedDeclaredOptionalType());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= wrappedDeclaredOptionalType.hashCode();
    return h$;
  }

}

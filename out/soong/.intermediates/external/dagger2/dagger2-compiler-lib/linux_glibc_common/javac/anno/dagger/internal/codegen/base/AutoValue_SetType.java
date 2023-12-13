package dagger.internal.codegen.base;

import com.google.common.base.Equivalence;
import javax.annotation.Generated;
import javax.lang.model.type.DeclaredType;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_SetType extends SetType {

  private final Equivalence.Wrapper<DeclaredType> wrappedDeclaredSetType;

  AutoValue_SetType(
      Equivalence.Wrapper<DeclaredType> wrappedDeclaredSetType) {
    if (wrappedDeclaredSetType == null) {
      throw new NullPointerException("Null wrappedDeclaredSetType");
    }
    this.wrappedDeclaredSetType = wrappedDeclaredSetType;
  }

  @Override
  protected Equivalence.Wrapper<DeclaredType> wrappedDeclaredSetType() {
    return wrappedDeclaredSetType;
  }

  @Override
  public String toString() {
    return "SetType{"
        + "wrappedDeclaredSetType=" + wrappedDeclaredSetType
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof SetType) {
      SetType that = (SetType) o;
      return this.wrappedDeclaredSetType.equals(that.wrappedDeclaredSetType());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= wrappedDeclaredSetType.hashCode();
    return h$;
  }

}

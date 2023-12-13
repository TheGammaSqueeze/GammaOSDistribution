package dagger.internal.codegen.base;

import com.google.common.base.Equivalence;
import javax.annotation.Generated;
import javax.lang.model.type.DeclaredType;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_MapType extends MapType {

  private final Equivalence.Wrapper<DeclaredType> wrappedDeclaredMapType;

  AutoValue_MapType(
      Equivalence.Wrapper<DeclaredType> wrappedDeclaredMapType) {
    if (wrappedDeclaredMapType == null) {
      throw new NullPointerException("Null wrappedDeclaredMapType");
    }
    this.wrappedDeclaredMapType = wrappedDeclaredMapType;
  }

  @Override
  protected Equivalence.Wrapper<DeclaredType> wrappedDeclaredMapType() {
    return wrappedDeclaredMapType;
  }

  @Override
  public String toString() {
    return "MapType{"
        + "wrappedDeclaredMapType=" + wrappedDeclaredMapType
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof MapType) {
      MapType that = (MapType) o;
      return this.wrappedDeclaredMapType.equals(that.wrappedDeclaredMapType());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= wrappedDeclaredMapType.hashCode();
    return h$;
  }

}

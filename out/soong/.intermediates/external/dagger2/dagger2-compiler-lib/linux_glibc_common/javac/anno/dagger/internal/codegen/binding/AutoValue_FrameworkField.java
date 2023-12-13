package dagger.internal.codegen.binding;

import com.squareup.javapoet.ParameterizedTypeName;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_FrameworkField extends FrameworkField {

  private final ParameterizedTypeName type;

  private final String name;

  AutoValue_FrameworkField(
      ParameterizedTypeName type,
      String name) {
    if (type == null) {
      throw new NullPointerException("Null type");
    }
    this.type = type;
    if (name == null) {
      throw new NullPointerException("Null name");
    }
    this.name = name;
  }

  @Override
  public ParameterizedTypeName type() {
    return type;
  }

  @Override
  public String name() {
    return name;
  }

  @Override
  public String toString() {
    return "FrameworkField{"
        + "type=" + type + ", "
        + "name=" + name
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof FrameworkField) {
      FrameworkField that = (FrameworkField) o;
      return this.type.equals(that.type())
          && this.name.equals(that.name());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= type.hashCode();
    h$ *= 1000003;
    h$ ^= name.hashCode();
    return h$;
  }

}

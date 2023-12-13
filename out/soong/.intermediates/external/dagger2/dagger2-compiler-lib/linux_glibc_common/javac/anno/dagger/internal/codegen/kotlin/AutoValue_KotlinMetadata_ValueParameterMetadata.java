package dagger.internal.codegen.kotlin;

import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_KotlinMetadata_ValueParameterMetadata extends KotlinMetadata.ValueParameterMetadata {

  private final int flags;

  private final String name;

  AutoValue_KotlinMetadata_ValueParameterMetadata(
      int flags,
      String name) {
    this.flags = flags;
    if (name == null) {
      throw new NullPointerException("Null name");
    }
    this.name = name;
  }

  @Override
  int flags() {
    return flags;
  }

  @Override
  String name() {
    return name;
  }

  @Override
  public String toString() {
    return "ValueParameterMetadata{"
        + "flags=" + flags + ", "
        + "name=" + name
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof KotlinMetadata.ValueParameterMetadata) {
      KotlinMetadata.ValueParameterMetadata that = (KotlinMetadata.ValueParameterMetadata) o;
      return this.flags == that.flags()
          && this.name.equals(that.name());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= flags;
    h$ *= 1000003;
    h$ ^= name.hashCode();
    return h$;
  }

}

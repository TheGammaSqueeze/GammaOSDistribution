package dagger.internal.codegen.kotlin;

import java.util.Optional;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_KotlinMetadata_PropertyMetadata extends KotlinMetadata.PropertyMetadata {

  private final int flags;

  private final String name;

  private final Optional<String> fieldSignature;

  private final Optional<String> getterSignature;

  private final Optional<String> methodForAnnotationsSignature;

  private AutoValue_KotlinMetadata_PropertyMetadata(
      int flags,
      String name,
      Optional<String> fieldSignature,
      Optional<String> getterSignature,
      Optional<String> methodForAnnotationsSignature) {
    this.flags = flags;
    this.name = name;
    this.fieldSignature = fieldSignature;
    this.getterSignature = getterSignature;
    this.methodForAnnotationsSignature = methodForAnnotationsSignature;
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
  Optional<String> fieldSignature() {
    return fieldSignature;
  }

  @Override
  Optional<String> getterSignature() {
    return getterSignature;
  }

  @Override
  Optional<String> methodForAnnotationsSignature() {
    return methodForAnnotationsSignature;
  }

  @Override
  public String toString() {
    return "PropertyMetadata{"
        + "flags=" + flags + ", "
        + "name=" + name + ", "
        + "fieldSignature=" + fieldSignature + ", "
        + "getterSignature=" + getterSignature + ", "
        + "methodForAnnotationsSignature=" + methodForAnnotationsSignature
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof KotlinMetadata.PropertyMetadata) {
      KotlinMetadata.PropertyMetadata that = (KotlinMetadata.PropertyMetadata) o;
      return this.flags == that.flags()
          && this.name.equals(that.name())
          && this.fieldSignature.equals(that.fieldSignature())
          && this.getterSignature.equals(that.getterSignature())
          && this.methodForAnnotationsSignature.equals(that.methodForAnnotationsSignature());
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
    h$ *= 1000003;
    h$ ^= fieldSignature.hashCode();
    h$ *= 1000003;
    h$ ^= getterSignature.hashCode();
    h$ *= 1000003;
    h$ ^= methodForAnnotationsSignature.hashCode();
    return h$;
  }

  static final class Builder implements KotlinMetadata.PropertyMetadata.Builder {
    private Integer flags;
    private String name;
    private Optional<String> fieldSignature = Optional.empty();
    private Optional<String> getterSignature = Optional.empty();
    private Optional<String> methodForAnnotationsSignature = Optional.empty();
    Builder() {
    }
    @Override
    public KotlinMetadata.PropertyMetadata.Builder flags(int flags) {
      this.flags = flags;
      return this;
    }
    @Override
    public KotlinMetadata.PropertyMetadata.Builder name(String name) {
      if (name == null) {
        throw new NullPointerException("Null name");
      }
      this.name = name;
      return this;
    }
    @Override
    public KotlinMetadata.PropertyMetadata.Builder fieldSignature(Optional<String> fieldSignature) {
      if (fieldSignature == null) {
        throw new NullPointerException("Null fieldSignature");
      }
      this.fieldSignature = fieldSignature;
      return this;
    }
    @Override
    public KotlinMetadata.PropertyMetadata.Builder getterSignature(Optional<String> getterSignature) {
      if (getterSignature == null) {
        throw new NullPointerException("Null getterSignature");
      }
      this.getterSignature = getterSignature;
      return this;
    }
    @Override
    public KotlinMetadata.PropertyMetadata.Builder methodForAnnotationsSignature(Optional<String> methodForAnnotationsSignature) {
      if (methodForAnnotationsSignature == null) {
        throw new NullPointerException("Null methodForAnnotationsSignature");
      }
      this.methodForAnnotationsSignature = methodForAnnotationsSignature;
      return this;
    }
    @Override
    public KotlinMetadata.PropertyMetadata build() {
      String missing = "";
      if (this.flags == null) {
        missing += " flags";
      }
      if (this.name == null) {
        missing += " name";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_KotlinMetadata_PropertyMetadata(
          this.flags,
          this.name,
          this.fieldSignature,
          this.getterSignature,
          this.methodForAnnotationsSignature);
    }
  }

}

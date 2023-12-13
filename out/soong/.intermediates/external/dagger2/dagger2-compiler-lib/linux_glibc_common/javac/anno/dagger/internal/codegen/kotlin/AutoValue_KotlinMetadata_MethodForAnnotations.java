package dagger.internal.codegen.kotlin;

import javax.annotation.Generated;
import javax.annotation.Nullable;
import javax.lang.model.element.ExecutableElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_KotlinMetadata_MethodForAnnotations extends KotlinMetadata.MethodForAnnotations {

  private final ExecutableElement method;

  AutoValue_KotlinMetadata_MethodForAnnotations(
      @Nullable ExecutableElement method) {
    this.method = method;
  }

  @Nullable
  @Override
  ExecutableElement method() {
    return method;
  }

  @Override
  public String toString() {
    return "MethodForAnnotations{"
        + "method=" + method
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof KotlinMetadata.MethodForAnnotations) {
      KotlinMetadata.MethodForAnnotations that = (KotlinMetadata.MethodForAnnotations) o;
      return (this.method == null ? that.method() == null : this.method.equals(that.method()));
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= (method == null) ? 0 : method.hashCode();
    return h$;
  }

}

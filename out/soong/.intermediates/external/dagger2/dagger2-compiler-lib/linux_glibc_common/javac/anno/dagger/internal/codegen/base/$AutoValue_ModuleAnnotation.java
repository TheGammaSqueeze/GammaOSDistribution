package dagger.internal.codegen.base;

import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ModuleAnnotation extends ModuleAnnotation {

  private final AnnotationMirror annotation;

  $AutoValue_ModuleAnnotation(
      AnnotationMirror annotation) {
    if (annotation == null) {
      throw new NullPointerException("Null annotation");
    }
    this.annotation = annotation;
  }

  @Override
  public AnnotationMirror annotation() {
    return annotation;
  }

  @Override
  public String toString() {
    return "ModuleAnnotation{"
        + "annotation=" + annotation
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ModuleAnnotation) {
      ModuleAnnotation that = (ModuleAnnotation) o;
      return this.annotation.equals(that.annotation());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= annotation.hashCode();
    return h$;
  }

}

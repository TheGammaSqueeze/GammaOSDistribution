package dagger.internal.codegen.base;

import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ComponentAnnotation_RealComponentAnnotation extends ComponentAnnotation.RealComponentAnnotation {

  private final AnnotationMirror annotation;

  private final boolean isSubcomponent;

  private final boolean isProduction;

  $AutoValue_ComponentAnnotation_RealComponentAnnotation(
      AnnotationMirror annotation,
      boolean isSubcomponent,
      boolean isProduction) {
    if (annotation == null) {
      throw new NullPointerException("Null annotation");
    }
    this.annotation = annotation;
    this.isSubcomponent = isSubcomponent;
    this.isProduction = isProduction;
  }

  @Override
  public AnnotationMirror annotation() {
    return annotation;
  }

  @Override
  public boolean isSubcomponent() {
    return isSubcomponent;
  }

  @Override
  public boolean isProduction() {
    return isProduction;
  }

  @Override
  public String toString() {
    return "RealComponentAnnotation{"
        + "annotation=" + annotation + ", "
        + "isSubcomponent=" + isSubcomponent + ", "
        + "isProduction=" + isProduction
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ComponentAnnotation.RealComponentAnnotation) {
      ComponentAnnotation.RealComponentAnnotation that = (ComponentAnnotation.RealComponentAnnotation) o;
      return this.annotation.equals(that.annotation())
          && this.isSubcomponent == that.isSubcomponent()
          && this.isProduction == that.isProduction();
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= annotation.hashCode();
    h$ *= 1000003;
    h$ ^= isSubcomponent ? 1231 : 1237;
    h$ *= 1000003;
    h$ ^= isProduction ? 1231 : 1237;
    return h$;
  }

  static class Builder implements ComponentAnnotation.RealComponentAnnotation.Builder {
    private AnnotationMirror annotation;
    private Boolean isSubcomponent;
    private Boolean isProduction;
    Builder() {
    }
    @Override
    public ComponentAnnotation.RealComponentAnnotation.Builder annotation(AnnotationMirror annotation) {
      if (annotation == null) {
        throw new NullPointerException("Null annotation");
      }
      this.annotation = annotation;
      return this;
    }
    @Override
    public ComponentAnnotation.RealComponentAnnotation.Builder isSubcomponent(boolean isSubcomponent) {
      this.isSubcomponent = isSubcomponent;
      return this;
    }
    @Override
    public ComponentAnnotation.RealComponentAnnotation.Builder isProduction(boolean isProduction) {
      this.isProduction = isProduction;
      return this;
    }
    @Override
    public ComponentAnnotation.RealComponentAnnotation build() {
      String missing = "";
      if (this.annotation == null) {
        missing += " annotation";
      }
      if (this.isSubcomponent == null) {
        missing += " isSubcomponent";
      }
      if (this.isProduction == null) {
        missing += " isProduction";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_ComponentAnnotation_RealComponentAnnotation(
          this.annotation,
          this.isSubcomponent,
          this.isProduction);
    }
  }

}

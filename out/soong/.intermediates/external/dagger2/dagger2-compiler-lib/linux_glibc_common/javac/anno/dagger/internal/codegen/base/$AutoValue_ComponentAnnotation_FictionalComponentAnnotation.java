package dagger.internal.codegen.base;

import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ComponentAnnotation_FictionalComponentAnnotation extends ComponentAnnotation.FictionalComponentAnnotation {

  private final ModuleAnnotation moduleAnnotation;

  $AutoValue_ComponentAnnotation_FictionalComponentAnnotation(
      ModuleAnnotation moduleAnnotation) {
    if (moduleAnnotation == null) {
      throw new NullPointerException("Null moduleAnnotation");
    }
    this.moduleAnnotation = moduleAnnotation;
  }

  @Override
  public ModuleAnnotation moduleAnnotation() {
    return moduleAnnotation;
  }

  @Override
  public String toString() {
    return "FictionalComponentAnnotation{"
        + "moduleAnnotation=" + moduleAnnotation
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ComponentAnnotation.FictionalComponentAnnotation) {
      ComponentAnnotation.FictionalComponentAnnotation that = (ComponentAnnotation.FictionalComponentAnnotation) o;
      return this.moduleAnnotation.equals(that.moduleAnnotation());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= moduleAnnotation.hashCode();
    return h$;
  }

}

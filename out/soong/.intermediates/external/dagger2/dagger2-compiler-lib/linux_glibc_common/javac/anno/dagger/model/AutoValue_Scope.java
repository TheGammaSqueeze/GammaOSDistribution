package dagger.model;

import com.google.common.base.Equivalence;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Scope extends Scope {

  private final Equivalence.Wrapper<AnnotationMirror> wrappedScopeAnnotation;

  AutoValue_Scope(
      Equivalence.Wrapper<AnnotationMirror> wrappedScopeAnnotation) {
    if (wrappedScopeAnnotation == null) {
      throw new NullPointerException("Null wrappedScopeAnnotation");
    }
    this.wrappedScopeAnnotation = wrappedScopeAnnotation;
  }

  @Override
  Equivalence.Wrapper<AnnotationMirror> wrappedScopeAnnotation() {
    return wrappedScopeAnnotation;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Scope) {
      Scope that = (Scope) o;
      return this.wrappedScopeAnnotation.equals(that.wrappedScopeAnnotation());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= wrappedScopeAnnotation.hashCode();
    return h$;
  }

}

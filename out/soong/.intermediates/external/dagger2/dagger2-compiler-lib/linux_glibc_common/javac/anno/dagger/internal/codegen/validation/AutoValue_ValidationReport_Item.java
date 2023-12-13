package dagger.internal.codegen.validation;

import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.AnnotationValue;
import javax.lang.model.element.Element;
import javax.tools.Diagnostic;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ValidationReport_Item extends ValidationReport.Item {

  private final String message;

  private final Diagnostic.Kind kind;

  private final Element element;

  private final Optional<AnnotationMirror> annotation;

  private final Optional<AnnotationValue> annotationValue;

  AutoValue_ValidationReport_Item(
      String message,
      Diagnostic.Kind kind,
      Element element,
      Optional<AnnotationMirror> annotation,
      Optional<AnnotationValue> annotationValue) {
    if (message == null) {
      throw new NullPointerException("Null message");
    }
    this.message = message;
    if (kind == null) {
      throw new NullPointerException("Null kind");
    }
    this.kind = kind;
    if (element == null) {
      throw new NullPointerException("Null element");
    }
    this.element = element;
    if (annotation == null) {
      throw new NullPointerException("Null annotation");
    }
    this.annotation = annotation;
    if (annotationValue == null) {
      throw new NullPointerException("Null annotationValue");
    }
    this.annotationValue = annotationValue;
  }

  @Override
  public String message() {
    return message;
  }

  @Override
  public Diagnostic.Kind kind() {
    return kind;
  }

  @Override
  public Element element() {
    return element;
  }

  @Override
  public Optional<AnnotationMirror> annotation() {
    return annotation;
  }

  @Override
  Optional<AnnotationValue> annotationValue() {
    return annotationValue;
  }

  @Override
  public String toString() {
    return "Item{"
        + "message=" + message + ", "
        + "kind=" + kind + ", "
        + "element=" + element + ", "
        + "annotation=" + annotation + ", "
        + "annotationValue=" + annotationValue
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ValidationReport.Item) {
      ValidationReport.Item that = (ValidationReport.Item) o;
      return this.message.equals(that.message())
          && this.kind.equals(that.kind())
          && this.element.equals(that.element())
          && this.annotation.equals(that.annotation())
          && this.annotationValue.equals(that.annotationValue());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= message.hashCode();
    h$ *= 1000003;
    h$ ^= kind.hashCode();
    h$ *= 1000003;
    h$ ^= element.hashCode();
    h$ *= 1000003;
    h$ ^= annotation.hashCode();
    h$ *= 1000003;
    h$ ^= annotationValue.hashCode();
    return h$;
  }

}

package dagger.internal.codegen.base;

import com.google.common.collect.ImmutableList;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.AnnotationValue;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ModuleAnnotation extends $AutoValue_ModuleAnnotation {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<TypeElement> includes;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<AnnotationValue> includesAsAnnotationValues;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<TypeElement> subcomponents;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<AnnotationValue> subcomponentsAsAnnotationValues;

  AutoValue_ModuleAnnotation(AnnotationMirror annotation$) {
    super(annotation$);
  }

  @Override
  public ImmutableList<TypeElement> includes() {
    if (includes == null) {
      synchronized (this) {
        if (includes == null) {
          includes = super.includes();
          if (includes == null) {
            throw new NullPointerException("includes() cannot return null");
          }
        }
      }
    }
    return includes;
  }

  @Override
  public ImmutableList<AnnotationValue> includesAsAnnotationValues() {
    if (includesAsAnnotationValues == null) {
      synchronized (this) {
        if (includesAsAnnotationValues == null) {
          includesAsAnnotationValues = super.includesAsAnnotationValues();
          if (includesAsAnnotationValues == null) {
            throw new NullPointerException("includesAsAnnotationValues() cannot return null");
          }
        }
      }
    }
    return includesAsAnnotationValues;
  }

  @Override
  public ImmutableList<TypeElement> subcomponents() {
    if (subcomponents == null) {
      synchronized (this) {
        if (subcomponents == null) {
          subcomponents = super.subcomponents();
          if (subcomponents == null) {
            throw new NullPointerException("subcomponents() cannot return null");
          }
        }
      }
    }
    return subcomponents;
  }

  @Override
  public ImmutableList<AnnotationValue> subcomponentsAsAnnotationValues() {
    if (subcomponentsAsAnnotationValues == null) {
      synchronized (this) {
        if (subcomponentsAsAnnotationValues == null) {
          subcomponentsAsAnnotationValues = super.subcomponentsAsAnnotationValues();
          if (subcomponentsAsAnnotationValues == null) {
            throw new NullPointerException("subcomponentsAsAnnotationValues() cannot return null");
          }
        }
      }
    }
    return subcomponentsAsAnnotationValues;
  }
}

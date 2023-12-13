package dagger.internal.codegen.base;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.AnnotationValue;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ComponentAnnotation_RealComponentAnnotation extends $AutoValue_ComponentAnnotation_RealComponentAnnotation {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<AnnotationValue> dependencyValues;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<TypeMirror> dependencyTypes;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<TypeElement> dependencies;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<AnnotationValue> moduleValues;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<TypeMirror> moduleTypes;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSet<TypeElement> modules;

  AutoValue_ComponentAnnotation_RealComponentAnnotation(AnnotationMirror annotation$,
      boolean isSubcomponent$, boolean isProduction$) {
    super(annotation$, isSubcomponent$, isProduction$);
  }

  @Override
  public ImmutableList<AnnotationValue> dependencyValues() {
    if (dependencyValues == null) {
      synchronized (this) {
        if (dependencyValues == null) {
          dependencyValues = super.dependencyValues();
          if (dependencyValues == null) {
            throw new NullPointerException("dependencyValues() cannot return null");
          }
        }
      }
    }
    return dependencyValues;
  }

  @Override
  public ImmutableList<TypeMirror> dependencyTypes() {
    if (dependencyTypes == null) {
      synchronized (this) {
        if (dependencyTypes == null) {
          dependencyTypes = super.dependencyTypes();
          if (dependencyTypes == null) {
            throw new NullPointerException("dependencyTypes() cannot return null");
          }
        }
      }
    }
    return dependencyTypes;
  }

  @Override
  public ImmutableList<TypeElement> dependencies() {
    if (dependencies == null) {
      synchronized (this) {
        if (dependencies == null) {
          dependencies = super.dependencies();
          if (dependencies == null) {
            throw new NullPointerException("dependencies() cannot return null");
          }
        }
      }
    }
    return dependencies;
  }

  @Override
  public ImmutableList<AnnotationValue> moduleValues() {
    if (moduleValues == null) {
      synchronized (this) {
        if (moduleValues == null) {
          moduleValues = super.moduleValues();
          if (moduleValues == null) {
            throw new NullPointerException("moduleValues() cannot return null");
          }
        }
      }
    }
    return moduleValues;
  }

  @Override
  public ImmutableList<TypeMirror> moduleTypes() {
    if (moduleTypes == null) {
      synchronized (this) {
        if (moduleTypes == null) {
          moduleTypes = super.moduleTypes();
          if (moduleTypes == null) {
            throw new NullPointerException("moduleTypes() cannot return null");
          }
        }
      }
    }
    return moduleTypes;
  }

  @Override
  public ImmutableSet<TypeElement> modules() {
    if (modules == null) {
      synchronized (this) {
        if (modules == null) {
          modules = super.modules();
          if (modules == null) {
            throw new NullPointerException("modules() cannot return null");
          }
        }
      }
    }
    return modules;
  }
}

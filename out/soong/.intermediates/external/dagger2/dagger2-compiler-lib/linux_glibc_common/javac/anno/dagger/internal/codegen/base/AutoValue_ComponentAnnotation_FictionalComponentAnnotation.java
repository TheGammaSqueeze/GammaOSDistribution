package dagger.internal.codegen.base;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ComponentAnnotation_FictionalComponentAnnotation extends $AutoValue_ComponentAnnotation_FictionalComponentAnnotation {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableList<TypeMirror> moduleTypes;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSet<TypeElement> modules;

  AutoValue_ComponentAnnotation_FictionalComponentAnnotation(ModuleAnnotation moduleAnnotation$) {
    super(moduleAnnotation$);
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

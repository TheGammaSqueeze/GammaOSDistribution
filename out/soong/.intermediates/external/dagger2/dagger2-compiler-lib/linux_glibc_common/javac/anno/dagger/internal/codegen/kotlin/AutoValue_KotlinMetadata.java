package dagger.internal.codegen.kotlin;

import com.google.common.collect.ImmutableMap;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_KotlinMetadata extends $AutoValue_KotlinMetadata {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableMap<String, ExecutableElement> methodDescriptors;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean containsConstructorWithDefaultParam;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean containsConstructorWithDefaultParam$Memoized;

  AutoValue_KotlinMetadata(TypeElement typeElement$, KotlinMetadata.ClassMetadata classMetadata$) {
    super(typeElement$, classMetadata$);
  }

  @Override
  ImmutableMap<String, ExecutableElement> methodDescriptors() {
    if (methodDescriptors == null) {
      synchronized (this) {
        if (methodDescriptors == null) {
          methodDescriptors = super.methodDescriptors();
          if (methodDescriptors == null) {
            throw new NullPointerException("methodDescriptors() cannot return null");
          }
        }
      }
    }
    return methodDescriptors;
  }

  @Override
  boolean containsConstructorWithDefaultParam() {
    if (!containsConstructorWithDefaultParam$Memoized) {
      synchronized (this) {
        if (!containsConstructorWithDefaultParam$Memoized) {
          containsConstructorWithDefaultParam = super.containsConstructorWithDefaultParam();
          containsConstructorWithDefaultParam$Memoized = true;
        }
      }
    }
    return containsConstructorWithDefaultParam;
  }
}

package dagger.model;

import com.google.common.collect.ImmutableList;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ComponentPath extends $AutoValue_ComponentPath {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile TypeElement currentComponent;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  AutoValue_ComponentPath(ImmutableList<TypeElement> components$) {
    super(components$);
  }

  @Override
  public TypeElement currentComponent() {
    if (currentComponent == null) {
      synchronized (this) {
        if (currentComponent == null) {
          currentComponent = super.currentComponent();
          if (currentComponent == null) {
            throw new NullPointerException("currentComponent() cannot return null");
          }
        }
      }
    }
    return currentComponent;
  }

  @Override
  public int hashCode() {
    if (!hashCode$Memoized) {
      synchronized (this) {
        if (!hashCode$Memoized) {
          hashCode = super.hashCode();
          hashCode$Memoized = true;
        }
      }
    }
    return hashCode;
  }

  @Override
  public boolean equals(Object that) {
    if (this == that) {
      return true;
    }
    return that instanceof AutoValue_ComponentPath && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

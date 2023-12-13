package dagger.internal.codegen.binding;

import com.google.errorprone.annotations.concurrent.LazyInit;
import dagger.internal.codegen.base.ModuleAnnotation;
import dagger.model.Key;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_SubcomponentDeclaration extends $AutoValue_SubcomponentDeclaration {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  AutoValue_SubcomponentDeclaration(Optional<Element> bindingElement$,
      Optional<TypeElement> contributingModule$, Key key$, TypeElement subcomponentType$,
      ModuleAnnotation moduleAnnotation$) {
    super(bindingElement$, contributingModule$, key$, subcomponentType$, moduleAnnotation$);
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
    return that instanceof AutoValue_SubcomponentDeclaration && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

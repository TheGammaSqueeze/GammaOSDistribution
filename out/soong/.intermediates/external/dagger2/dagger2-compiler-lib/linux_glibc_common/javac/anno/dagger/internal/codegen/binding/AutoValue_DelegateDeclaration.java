package dagger.internal.codegen.binding;

import com.google.common.base.Equivalence;
import com.google.errorprone.annotations.concurrent.LazyInit;
import dagger.internal.codegen.base.ContributionType;
import dagger.model.DependencyRequest;
import dagger.model.Key;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_DelegateDeclaration extends $AutoValue_DelegateDeclaration {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  AutoValue_DelegateDeclaration(ContributionType contributionType$, Key key$,
      Optional<Element> bindingElement$, Optional<TypeElement> contributingModule$,
      DependencyRequest delegateRequest$,
      Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKey$) {
    super(contributionType$, key$, bindingElement$, contributingModule$, delegateRequest$, wrappedMapKey$);
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
    return that instanceof AutoValue_DelegateDeclaration && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

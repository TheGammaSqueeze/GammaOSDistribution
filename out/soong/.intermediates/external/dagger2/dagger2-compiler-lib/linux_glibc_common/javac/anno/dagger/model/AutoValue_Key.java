package dagger.model;

import com.google.common.base.Equivalence;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_Key extends $AutoValue_Key {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  AutoValue_Key(Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedQualifier$,
      Equivalence.Wrapper<TypeMirror> wrappedType$,
      Optional<Key.MultibindingContributionIdentifier> multibindingContributionIdentifier$) {
    super(wrappedQualifier$, wrappedType$, multibindingContributionIdentifier$);
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
    return that instanceof AutoValue_Key && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

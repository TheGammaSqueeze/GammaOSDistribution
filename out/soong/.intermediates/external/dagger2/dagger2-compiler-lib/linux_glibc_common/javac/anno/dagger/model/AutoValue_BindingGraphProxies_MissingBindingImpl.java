package dagger.model;

import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_BindingGraphProxies_MissingBindingImpl extends $AutoValue_BindingGraphProxies_MissingBindingImpl {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  AutoValue_BindingGraphProxies_MissingBindingImpl(ComponentPath componentPath$, Key key$) {
    super(componentPath$, key$);
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
    return that instanceof AutoValue_BindingGraphProxies_MissingBindingImpl && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

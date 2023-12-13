package dagger.internal.codegen.binding;

import com.google.errorprone.annotations.concurrent.LazyInit;
import dagger.model.ComponentPath;
import dagger.model.Key;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_BindingGraphConverter_MissingBindingImpl extends $AutoValue_BindingGraphConverter_MissingBindingImpl {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  AutoValue_BindingGraphConverter_MissingBindingImpl(ComponentPath componentPath$, Key key$) {
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
    return that instanceof AutoValue_BindingGraphConverter_MissingBindingImpl && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

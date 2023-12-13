package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableSet;
import com.google.common.collect.ImmutableSortedSet;
import com.google.errorprone.annotations.concurrent.LazyInit;
import dagger.model.DependencyRequest;
import dagger.model.Key;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_MembersInjectionBinding extends $AutoValue_MembersInjectionBinding {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  AutoValue_MembersInjectionBinding(Key key$, ImmutableSet<DependencyRequest> explicitDependencies$,
      TypeElement membersInjectedType$, Optional<MembersInjectionBinding> unresolved$,
      ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites$) {
    super(key$, explicitDependencies$, membersInjectedType$, unresolved$, injectionSites$);
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
    return that instanceof AutoValue_MembersInjectionBinding && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableSet;
import com.google.errorprone.annotations.concurrent.LazyInit;
import dagger.model.DependencyRequest;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.Element;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_MembersInjectionBinding_InjectionSite extends $AutoValue_MembersInjectionBinding_InjectionSite {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int indexAmongAtInjectMembersWithSameSimpleName;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean indexAmongAtInjectMembersWithSameSimpleName$Memoized;

  AutoValue_MembersInjectionBinding_InjectionSite(MembersInjectionBinding.InjectionSite.Kind kind$,
      Element element$, ImmutableSet<DependencyRequest> dependencies$) {
    super(kind$, element$, dependencies$);
  }

  @Override
  public int indexAmongAtInjectMembersWithSameSimpleName() {
    if (!indexAmongAtInjectMembersWithSameSimpleName$Memoized) {
      synchronized (this) {
        if (!indexAmongAtInjectMembersWithSameSimpleName$Memoized) {
          indexAmongAtInjectMembersWithSameSimpleName = super.indexAmongAtInjectMembersWithSameSimpleName();
          indexAmongAtInjectMembersWithSameSimpleName$Memoized = true;
        }
      }
    }
    return indexAmongAtInjectMembersWithSameSimpleName;
  }
}

package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.ImmutableSetMultimap;
import com.google.errorprone.annotations.concurrent.LazyInit;
import dagger.model.Key;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ResolvedBindings extends $AutoValue_ResolvedBindings {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSet<ContributionBinding> contributionBindings;

  AutoValue_ResolvedBindings(Key key$,
      ImmutableSetMultimap<TypeElement, ContributionBinding> allContributionBindings$,
      ImmutableMap<TypeElement, MembersInjectionBinding> allMembersInjectionBindings$,
      ImmutableSet<MultibindingDeclaration> multibindingDeclarations$,
      ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations$,
      ImmutableSet<OptionalBindingDeclaration> optionalBindingDeclarations$) {
    super(key$, allContributionBindings$, allMembersInjectionBindings$, multibindingDeclarations$, subcomponentDeclarations$, optionalBindingDeclarations$);
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
  ImmutableSet<ContributionBinding> contributionBindings() {
    if (contributionBindings == null) {
      synchronized (this) {
        if (contributionBindings == null) {
          contributionBindings = super.contributionBindings();
          if (contributionBindings == null) {
            throw new NullPointerException("contributionBindings() cannot return null");
          }
        }
      }
    }
    return contributionBindings;
  }

  @Override
  public boolean equals(Object that) {
    if (this == that) {
      return true;
    }
    return that instanceof AutoValue_ResolvedBindings && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

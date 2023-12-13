package dagger.internal.codegen.binding;

import com.google.common.base.Equivalence;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.ImmutableSortedSet;
import com.google.errorprone.annotations.concurrent.LazyInit;
import dagger.internal.codegen.base.ContributionType;
import dagger.model.BindingKind;
import dagger.model.DependencyRequest;
import dagger.model.Key;
import dagger.model.Scope;
import java.lang.Boolean;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.DeclaredType;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ProvisionBinding extends $AutoValue_ProvisionBinding {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSet<DependencyRequest> explicitDependencies;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSet<DependencyRequest> membersInjectionDependencies;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean requiresModuleInstance;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean requiresModuleInstance$Memoized;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  AutoValue_ProvisionBinding(ContributionType contributionType$, Key key$,
      Optional<Element> bindingElement$, Optional<TypeElement> contributingModule$,
      BindingKind kind$, Optional<DeclaredType> nullableType$,
      Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation$,
      Optional<Boolean> isContributingModuleKotlinObject$,
      ImmutableSet<DependencyRequest> provisionDependencies$,
      ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites$,
      Optional<ProvisionBinding> unresolved$, Optional<Scope> scope$) {
    super(contributionType$, key$, bindingElement$, contributingModule$, kind$, nullableType$, wrappedMapKeyAnnotation$, isContributingModuleKotlinObject$, provisionDependencies$, injectionSites$, unresolved$, scope$);
  }

  @Override
  public ImmutableSet<DependencyRequest> explicitDependencies() {
    if (explicitDependencies == null) {
      synchronized (this) {
        if (explicitDependencies == null) {
          explicitDependencies = super.explicitDependencies();
          if (explicitDependencies == null) {
            throw new NullPointerException("explicitDependencies() cannot return null");
          }
        }
      }
    }
    return explicitDependencies;
  }

  @Override
  ImmutableSet<DependencyRequest> membersInjectionDependencies() {
    if (membersInjectionDependencies == null) {
      synchronized (this) {
        if (membersInjectionDependencies == null) {
          membersInjectionDependencies = super.membersInjectionDependencies();
          if (membersInjectionDependencies == null) {
            throw new NullPointerException("membersInjectionDependencies() cannot return null");
          }
        }
      }
    }
    return membersInjectionDependencies;
  }

  @Override
  public boolean requiresModuleInstance() {
    if (!requiresModuleInstance$Memoized) {
      synchronized (this) {
        if (!requiresModuleInstance$Memoized) {
          requiresModuleInstance = super.requiresModuleInstance();
          requiresModuleInstance$Memoized = true;
        }
      }
    }
    return requiresModuleInstance;
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
    return that instanceof AutoValue_ProvisionBinding && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

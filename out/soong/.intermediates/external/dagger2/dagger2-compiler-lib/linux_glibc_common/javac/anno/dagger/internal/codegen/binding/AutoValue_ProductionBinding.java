package dagger.internal.codegen.binding;

import com.google.common.base.Equivalence;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.errorprone.annotations.concurrent.LazyInit;
import dagger.internal.codegen.base.ContributionType;
import dagger.model.BindingKind;
import dagger.model.DependencyRequest;
import dagger.model.Key;
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
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ProductionBinding extends $AutoValue_ProductionBinding {
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

  AutoValue_ProductionBinding(ContributionType contributionType$, Key key$,
      Optional<Element> bindingElement$, Optional<TypeElement> contributingModule$,
      BindingKind kind$, ImmutableSet<DependencyRequest> explicitDependencies$,
      Optional<DeclaredType> nullableType$,
      Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation$,
      Optional<Boolean> isContributingModuleKotlinObject$, Optional<ProductionBinding> unresolved$,
      Optional<ProductionBinding.ProductionKind> productionKind$,
      ImmutableList<? extends TypeMirror> thrownTypes$,
      Optional<DependencyRequest> executorRequest$, Optional<DependencyRequest> monitorRequest$) {
    super(contributionType$, key$, bindingElement$, contributingModule$, kind$, explicitDependencies$, nullableType$, wrappedMapKeyAnnotation$, isContributingModuleKotlinObject$, unresolved$, productionKind$, thrownTypes$, executorRequest$, monitorRequest$);
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
    return that instanceof AutoValue_ProductionBinding && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

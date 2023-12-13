package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableSet;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ModuleDescriptor extends $AutoValue_ModuleDescriptor {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSet<BindingDeclaration> allBindingDeclarations;

  AutoValue_ModuleDescriptor(TypeElement moduleElement$, ImmutableSet<TypeElement> includedModules$,
      ImmutableSet<ContributionBinding> bindings$,
      ImmutableSet<MultibindingDeclaration> multibindingDeclarations$,
      ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations$,
      ImmutableSet<DelegateDeclaration> delegateDeclarations$,
      ImmutableSet<OptionalBindingDeclaration> optionalDeclarations$, ModuleKind kind$) {
    super(moduleElement$, includedModules$, bindings$, multibindingDeclarations$, subcomponentDeclarations$, delegateDeclarations$, optionalDeclarations$, kind$);
  }

  @Override
  public ImmutableSet<BindingDeclaration> allBindingDeclarations() {
    if (allBindingDeclarations == null) {
      synchronized (this) {
        if (allBindingDeclarations == null) {
          allBindingDeclarations = super.allBindingDeclarations();
          if (allBindingDeclarations == null) {
            throw new NullPointerException("allBindingDeclarations() cannot return null");
          }
        }
      }
    }
    return allBindingDeclarations;
  }
}

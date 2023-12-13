package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableSet;
import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ModuleDescriptor extends ModuleDescriptor {

  private final TypeElement moduleElement;

  private final ImmutableSet<TypeElement> includedModules;

  private final ImmutableSet<ContributionBinding> bindings;

  private final ImmutableSet<MultibindingDeclaration> multibindingDeclarations;

  private final ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations;

  private final ImmutableSet<DelegateDeclaration> delegateDeclarations;

  private final ImmutableSet<OptionalBindingDeclaration> optionalDeclarations;

  private final ModuleKind kind;

  $AutoValue_ModuleDescriptor(
      TypeElement moduleElement,
      ImmutableSet<TypeElement> includedModules,
      ImmutableSet<ContributionBinding> bindings,
      ImmutableSet<MultibindingDeclaration> multibindingDeclarations,
      ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations,
      ImmutableSet<DelegateDeclaration> delegateDeclarations,
      ImmutableSet<OptionalBindingDeclaration> optionalDeclarations,
      ModuleKind kind) {
    if (moduleElement == null) {
      throw new NullPointerException("Null moduleElement");
    }
    this.moduleElement = moduleElement;
    if (includedModules == null) {
      throw new NullPointerException("Null includedModules");
    }
    this.includedModules = includedModules;
    if (bindings == null) {
      throw new NullPointerException("Null bindings");
    }
    this.bindings = bindings;
    if (multibindingDeclarations == null) {
      throw new NullPointerException("Null multibindingDeclarations");
    }
    this.multibindingDeclarations = multibindingDeclarations;
    if (subcomponentDeclarations == null) {
      throw new NullPointerException("Null subcomponentDeclarations");
    }
    this.subcomponentDeclarations = subcomponentDeclarations;
    if (delegateDeclarations == null) {
      throw new NullPointerException("Null delegateDeclarations");
    }
    this.delegateDeclarations = delegateDeclarations;
    if (optionalDeclarations == null) {
      throw new NullPointerException("Null optionalDeclarations");
    }
    this.optionalDeclarations = optionalDeclarations;
    if (kind == null) {
      throw new NullPointerException("Null kind");
    }
    this.kind = kind;
  }

  @Override
  public TypeElement moduleElement() {
    return moduleElement;
  }

  @Override
  ImmutableSet<TypeElement> includedModules() {
    return includedModules;
  }

  @Override
  public ImmutableSet<ContributionBinding> bindings() {
    return bindings;
  }

  @Override
  ImmutableSet<MultibindingDeclaration> multibindingDeclarations() {
    return multibindingDeclarations;
  }

  @Override
  ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations() {
    return subcomponentDeclarations;
  }

  @Override
  ImmutableSet<DelegateDeclaration> delegateDeclarations() {
    return delegateDeclarations;
  }

  @Override
  ImmutableSet<OptionalBindingDeclaration> optionalDeclarations() {
    return optionalDeclarations;
  }

  @Override
  public ModuleKind kind() {
    return kind;
  }

  @Override
  public String toString() {
    return "ModuleDescriptor{"
        + "moduleElement=" + moduleElement + ", "
        + "includedModules=" + includedModules + ", "
        + "bindings=" + bindings + ", "
        + "multibindingDeclarations=" + multibindingDeclarations + ", "
        + "subcomponentDeclarations=" + subcomponentDeclarations + ", "
        + "delegateDeclarations=" + delegateDeclarations + ", "
        + "optionalDeclarations=" + optionalDeclarations + ", "
        + "kind=" + kind
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ModuleDescriptor) {
      ModuleDescriptor that = (ModuleDescriptor) o;
      return this.moduleElement.equals(that.moduleElement())
          && this.includedModules.equals(that.includedModules())
          && this.bindings.equals(that.bindings())
          && this.multibindingDeclarations.equals(that.multibindingDeclarations())
          && this.subcomponentDeclarations.equals(that.subcomponentDeclarations())
          && this.delegateDeclarations.equals(that.delegateDeclarations())
          && this.optionalDeclarations.equals(that.optionalDeclarations())
          && this.kind.equals(that.kind());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= moduleElement.hashCode();
    h$ *= 1000003;
    h$ ^= includedModules.hashCode();
    h$ *= 1000003;
    h$ ^= bindings.hashCode();
    h$ *= 1000003;
    h$ ^= multibindingDeclarations.hashCode();
    h$ *= 1000003;
    h$ ^= subcomponentDeclarations.hashCode();
    h$ *= 1000003;
    h$ ^= delegateDeclarations.hashCode();
    h$ *= 1000003;
    h$ ^= optionalDeclarations.hashCode();
    h$ *= 1000003;
    h$ ^= kind.hashCode();
    return h$;
  }

}

package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableSet;
import dagger.model.ComponentPath;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_BindingNode extends BindingNode {

  private final ComponentPath componentPath;

  private final dagger.internal.codegen.binding.Binding delegate;

  private final ImmutableSet<MultibindingDeclaration> multibindingDeclarations;

  private final ImmutableSet<OptionalBindingDeclaration> optionalBindingDeclarations;

  private final ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations;

  AutoValue_BindingNode(
      ComponentPath componentPath,
      dagger.internal.codegen.binding.Binding delegate,
      ImmutableSet<MultibindingDeclaration> multibindingDeclarations,
      ImmutableSet<OptionalBindingDeclaration> optionalBindingDeclarations,
      ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations) {
    if (componentPath == null) {
      throw new NullPointerException("Null componentPath");
    }
    this.componentPath = componentPath;
    if (delegate == null) {
      throw new NullPointerException("Null delegate");
    }
    this.delegate = delegate;
    if (multibindingDeclarations == null) {
      throw new NullPointerException("Null multibindingDeclarations");
    }
    this.multibindingDeclarations = multibindingDeclarations;
    if (optionalBindingDeclarations == null) {
      throw new NullPointerException("Null optionalBindingDeclarations");
    }
    this.optionalBindingDeclarations = optionalBindingDeclarations;
    if (subcomponentDeclarations == null) {
      throw new NullPointerException("Null subcomponentDeclarations");
    }
    this.subcomponentDeclarations = subcomponentDeclarations;
  }

  @Override
  public ComponentPath componentPath() {
    return componentPath;
  }

  @Override
  public dagger.internal.codegen.binding.Binding delegate() {
    return delegate;
  }

  @Override
  public ImmutableSet<MultibindingDeclaration> multibindingDeclarations() {
    return multibindingDeclarations;
  }

  @Override
  public ImmutableSet<OptionalBindingDeclaration> optionalBindingDeclarations() {
    return optionalBindingDeclarations;
  }

  @Override
  public ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations() {
    return subcomponentDeclarations;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof BindingNode) {
      BindingNode that = (BindingNode) o;
      return this.componentPath.equals(that.componentPath())
          && this.delegate.equals(that.delegate())
          && this.multibindingDeclarations.equals(that.multibindingDeclarations())
          && this.optionalBindingDeclarations.equals(that.optionalBindingDeclarations())
          && this.subcomponentDeclarations.equals(that.subcomponentDeclarations());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= componentPath.hashCode();
    h$ *= 1000003;
    h$ ^= delegate.hashCode();
    h$ *= 1000003;
    h$ ^= multibindingDeclarations.hashCode();
    h$ *= 1000003;
    h$ ^= optionalBindingDeclarations.hashCode();
    h$ *= 1000003;
    h$ ^= subcomponentDeclarations.hashCode();
    return h$;
  }

}

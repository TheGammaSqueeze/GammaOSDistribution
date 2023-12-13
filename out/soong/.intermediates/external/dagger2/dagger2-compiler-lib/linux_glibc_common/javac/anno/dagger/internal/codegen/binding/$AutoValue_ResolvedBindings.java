package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.ImmutableSetMultimap;
import dagger.model.Key;
import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ResolvedBindings extends ResolvedBindings {

  private final Key key;

  private final ImmutableSetMultimap<TypeElement, ContributionBinding> allContributionBindings;

  private final ImmutableMap<TypeElement, MembersInjectionBinding> allMembersInjectionBindings;

  private final ImmutableSet<MultibindingDeclaration> multibindingDeclarations;

  private final ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations;

  private final ImmutableSet<OptionalBindingDeclaration> optionalBindingDeclarations;

  $AutoValue_ResolvedBindings(
      Key key,
      ImmutableSetMultimap<TypeElement, ContributionBinding> allContributionBindings,
      ImmutableMap<TypeElement, MembersInjectionBinding> allMembersInjectionBindings,
      ImmutableSet<MultibindingDeclaration> multibindingDeclarations,
      ImmutableSet<SubcomponentDeclaration> subcomponentDeclarations,
      ImmutableSet<OptionalBindingDeclaration> optionalBindingDeclarations) {
    if (key == null) {
      throw new NullPointerException("Null key");
    }
    this.key = key;
    if (allContributionBindings == null) {
      throw new NullPointerException("Null allContributionBindings");
    }
    this.allContributionBindings = allContributionBindings;
    if (allMembersInjectionBindings == null) {
      throw new NullPointerException("Null allMembersInjectionBindings");
    }
    this.allMembersInjectionBindings = allMembersInjectionBindings;
    if (multibindingDeclarations == null) {
      throw new NullPointerException("Null multibindingDeclarations");
    }
    this.multibindingDeclarations = multibindingDeclarations;
    if (subcomponentDeclarations == null) {
      throw new NullPointerException("Null subcomponentDeclarations");
    }
    this.subcomponentDeclarations = subcomponentDeclarations;
    if (optionalBindingDeclarations == null) {
      throw new NullPointerException("Null optionalBindingDeclarations");
    }
    this.optionalBindingDeclarations = optionalBindingDeclarations;
  }

  @Override
  Key key() {
    return key;
  }

  @Override
  ImmutableSetMultimap<TypeElement, ContributionBinding> allContributionBindings() {
    return allContributionBindings;
  }

  @Override
  ImmutableMap<TypeElement, MembersInjectionBinding> allMembersInjectionBindings() {
    return allMembersInjectionBindings;
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
  ImmutableSet<OptionalBindingDeclaration> optionalBindingDeclarations() {
    return optionalBindingDeclarations;
  }

  @Override
  public String toString() {
    return "ResolvedBindings{"
        + "key=" + key + ", "
        + "allContributionBindings=" + allContributionBindings + ", "
        + "allMembersInjectionBindings=" + allMembersInjectionBindings + ", "
        + "multibindingDeclarations=" + multibindingDeclarations + ", "
        + "subcomponentDeclarations=" + subcomponentDeclarations + ", "
        + "optionalBindingDeclarations=" + optionalBindingDeclarations
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ResolvedBindings) {
      ResolvedBindings that = (ResolvedBindings) o;
      return this.key.equals(that.key())
          && this.allContributionBindings.equals(that.allContributionBindings())
          && this.allMembersInjectionBindings.equals(that.allMembersInjectionBindings())
          && this.multibindingDeclarations.equals(that.multibindingDeclarations())
          && this.subcomponentDeclarations.equals(that.subcomponentDeclarations())
          && this.optionalBindingDeclarations.equals(that.optionalBindingDeclarations());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= key.hashCode();
    h$ *= 1000003;
    h$ ^= allContributionBindings.hashCode();
    h$ *= 1000003;
    h$ ^= allMembersInjectionBindings.hashCode();
    h$ *= 1000003;
    h$ ^= multibindingDeclarations.hashCode();
    h$ *= 1000003;
    h$ ^= subcomponentDeclarations.hashCode();
    h$ *= 1000003;
    h$ ^= optionalBindingDeclarations.hashCode();
    return h$;
  }

}

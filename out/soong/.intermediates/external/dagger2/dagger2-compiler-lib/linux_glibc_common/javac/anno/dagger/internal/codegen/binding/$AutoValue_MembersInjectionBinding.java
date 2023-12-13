package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableSet;
import com.google.common.collect.ImmutableSortedSet;
import dagger.model.DependencyRequest;
import dagger.model.Key;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_MembersInjectionBinding extends MembersInjectionBinding {

  private final Key key;

  private final ImmutableSet<DependencyRequest> explicitDependencies;

  private final TypeElement membersInjectedType;

  private final Optional<MembersInjectionBinding> unresolved;

  private final ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites;

  $AutoValue_MembersInjectionBinding(
      Key key,
      ImmutableSet<DependencyRequest> explicitDependencies,
      TypeElement membersInjectedType,
      Optional<MembersInjectionBinding> unresolved,
      ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites) {
    if (key == null) {
      throw new NullPointerException("Null key");
    }
    this.key = key;
    if (explicitDependencies == null) {
      throw new NullPointerException("Null explicitDependencies");
    }
    this.explicitDependencies = explicitDependencies;
    if (membersInjectedType == null) {
      throw new NullPointerException("Null membersInjectedType");
    }
    this.membersInjectedType = membersInjectedType;
    if (unresolved == null) {
      throw new NullPointerException("Null unresolved");
    }
    this.unresolved = unresolved;
    if (injectionSites == null) {
      throw new NullPointerException("Null injectionSites");
    }
    this.injectionSites = injectionSites;
  }

  @Override
  public Key key() {
    return key;
  }

  @Override
  public ImmutableSet<DependencyRequest> explicitDependencies() {
    return explicitDependencies;
  }

  @Override
  public TypeElement membersInjectedType() {
    return membersInjectedType;
  }

  @Override
  public Optional<MembersInjectionBinding> unresolved() {
    return unresolved;
  }

  @Override
  public ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites() {
    return injectionSites;
  }

  @Override
  public String toString() {
    return "MembersInjectionBinding{"
        + "key=" + key + ", "
        + "explicitDependencies=" + explicitDependencies + ", "
        + "membersInjectedType=" + membersInjectedType + ", "
        + "unresolved=" + unresolved + ", "
        + "injectionSites=" + injectionSites
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof MembersInjectionBinding) {
      MembersInjectionBinding that = (MembersInjectionBinding) o;
      return this.key.equals(that.key())
          && this.explicitDependencies.equals(that.explicitDependencies())
          && this.membersInjectedType.equals(that.membersInjectedType())
          && this.unresolved.equals(that.unresolved())
          && this.injectionSites.equals(that.injectionSites());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= key.hashCode();
    h$ *= 1000003;
    h$ ^= explicitDependencies.hashCode();
    h$ *= 1000003;
    h$ ^= membersInjectedType.hashCode();
    h$ *= 1000003;
    h$ ^= unresolved.hashCode();
    h$ *= 1000003;
    h$ ^= injectionSites.hashCode();
    return h$;
  }

}

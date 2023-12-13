package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableSet;
import dagger.model.DependencyRequest;
import javax.annotation.Generated;
import javax.lang.model.element.Element;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_MembersInjectionBinding_InjectionSite extends MembersInjectionBinding.InjectionSite {

  private final MembersInjectionBinding.InjectionSite.Kind kind;

  private final Element element;

  private final ImmutableSet<DependencyRequest> dependencies;

  $AutoValue_MembersInjectionBinding_InjectionSite(
      MembersInjectionBinding.InjectionSite.Kind kind,
      Element element,
      ImmutableSet<DependencyRequest> dependencies) {
    if (kind == null) {
      throw new NullPointerException("Null kind");
    }
    this.kind = kind;
    if (element == null) {
      throw new NullPointerException("Null element");
    }
    this.element = element;
    if (dependencies == null) {
      throw new NullPointerException("Null dependencies");
    }
    this.dependencies = dependencies;
  }

  @Override
  public MembersInjectionBinding.InjectionSite.Kind kind() {
    return kind;
  }

  @Override
  public Element element() {
    return element;
  }

  @Override
  public ImmutableSet<DependencyRequest> dependencies() {
    return dependencies;
  }

  @Override
  public String toString() {
    return "InjectionSite{"
        + "kind=" + kind + ", "
        + "element=" + element + ", "
        + "dependencies=" + dependencies
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof MembersInjectionBinding.InjectionSite) {
      MembersInjectionBinding.InjectionSite that = (MembersInjectionBinding.InjectionSite) o;
      return this.kind.equals(that.kind())
          && this.element.equals(that.element())
          && this.dependencies.equals(that.dependencies());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= kind.hashCode();
    h$ *= 1000003;
    h$ ^= element.hashCode();
    h$ *= 1000003;
    h$ ^= dependencies.hashCode();
    return h$;
  }

}

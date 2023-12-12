package dagger.internal.codegen.binding;

import com.google.common.base.Equivalence;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.ImmutableSortedSet;
import dagger.internal.codegen.base.ContributionType;
import dagger.model.BindingKind;
import dagger.model.DependencyRequest;
import dagger.model.Key;
import dagger.model.Scope;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.DeclaredType;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ProvisionBinding extends ProvisionBinding {

  private final ContributionType contributionType;

  private final Key key;

  private final Optional<Element> bindingElement;

  private final Optional<TypeElement> contributingModule;

  private final BindingKind kind;

  private final Optional<DeclaredType> nullableType;

  private final Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation;

  private final Optional<Boolean> isContributingModuleKotlinObject;

  private final ImmutableSet<DependencyRequest> provisionDependencies;

  private final ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites;

  private final Optional<ProvisionBinding> unresolved;

  private final Optional<Scope> scope;

  $AutoValue_ProvisionBinding(
      ContributionType contributionType,
      Key key,
      Optional<Element> bindingElement,
      Optional<TypeElement> contributingModule,
      BindingKind kind,
      Optional<DeclaredType> nullableType,
      Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation,
      Optional<Boolean> isContributingModuleKotlinObject,
      ImmutableSet<DependencyRequest> provisionDependencies,
      ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites,
      Optional<ProvisionBinding> unresolved,
      Optional<Scope> scope) {
    if (contributionType == null) {
      throw new NullPointerException("Null contributionType");
    }
    this.contributionType = contributionType;
    if (key == null) {
      throw new NullPointerException("Null key");
    }
    this.key = key;
    if (bindingElement == null) {
      throw new NullPointerException("Null bindingElement");
    }
    this.bindingElement = bindingElement;
    if (contributingModule == null) {
      throw new NullPointerException("Null contributingModule");
    }
    this.contributingModule = contributingModule;
    if (kind == null) {
      throw new NullPointerException("Null kind");
    }
    this.kind = kind;
    if (nullableType == null) {
      throw new NullPointerException("Null nullableType");
    }
    this.nullableType = nullableType;
    if (wrappedMapKeyAnnotation == null) {
      throw new NullPointerException("Null wrappedMapKeyAnnotation");
    }
    this.wrappedMapKeyAnnotation = wrappedMapKeyAnnotation;
    if (isContributingModuleKotlinObject == null) {
      throw new NullPointerException("Null isContributingModuleKotlinObject");
    }
    this.isContributingModuleKotlinObject = isContributingModuleKotlinObject;
    if (provisionDependencies == null) {
      throw new NullPointerException("Null provisionDependencies");
    }
    this.provisionDependencies = provisionDependencies;
    if (injectionSites == null) {
      throw new NullPointerException("Null injectionSites");
    }
    this.injectionSites = injectionSites;
    if (unresolved == null) {
      throw new NullPointerException("Null unresolved");
    }
    this.unresolved = unresolved;
    if (scope == null) {
      throw new NullPointerException("Null scope");
    }
    this.scope = scope;
  }

  @Override
  public ContributionType contributionType() {
    return contributionType;
  }

  @Override
  public Key key() {
    return key;
  }

  @Override
  public Optional<Element> bindingElement() {
    return bindingElement;
  }

  @Override
  public Optional<TypeElement> contributingModule() {
    return contributingModule;
  }

  @Override
  public BindingKind kind() {
    return kind;
  }

  @Override
  public Optional<DeclaredType> nullableType() {
    return nullableType;
  }

  @Override
  public Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation() {
    return wrappedMapKeyAnnotation;
  }

  @Override
  Optional<Boolean> isContributingModuleKotlinObject() {
    return isContributingModuleKotlinObject;
  }

  @Override
  public ImmutableSet<DependencyRequest> provisionDependencies() {
    return provisionDependencies;
  }

  @Override
  public ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites() {
    return injectionSites;
  }

  @Override
  public Optional<ProvisionBinding> unresolved() {
    return unresolved;
  }

  @Override
  public Optional<Scope> scope() {
    return scope;
  }

  @Override
  public String toString() {
    return "ProvisionBinding{"
        + "contributionType=" + contributionType + ", "
        + "key=" + key + ", "
        + "bindingElement=" + bindingElement + ", "
        + "contributingModule=" + contributingModule + ", "
        + "kind=" + kind + ", "
        + "nullableType=" + nullableType + ", "
        + "wrappedMapKeyAnnotation=" + wrappedMapKeyAnnotation + ", "
        + "isContributingModuleKotlinObject=" + isContributingModuleKotlinObject + ", "
        + "provisionDependencies=" + provisionDependencies + ", "
        + "injectionSites=" + injectionSites + ", "
        + "unresolved=" + unresolved + ", "
        + "scope=" + scope
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ProvisionBinding) {
      ProvisionBinding that = (ProvisionBinding) o;
      return this.contributionType.equals(that.contributionType())
          && this.key.equals(that.key())
          && this.bindingElement.equals(that.bindingElement())
          && this.contributingModule.equals(that.contributingModule())
          && this.kind.equals(that.kind())
          && this.nullableType.equals(that.nullableType())
          && this.wrappedMapKeyAnnotation.equals(that.wrappedMapKeyAnnotation())
          && this.isContributingModuleKotlinObject.equals(that.isContributingModuleKotlinObject())
          && this.provisionDependencies.equals(that.provisionDependencies())
          && this.injectionSites.equals(that.injectionSites())
          && this.unresolved.equals(that.unresolved())
          && this.scope.equals(that.scope());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= contributionType.hashCode();
    h$ *= 1000003;
    h$ ^= key.hashCode();
    h$ *= 1000003;
    h$ ^= bindingElement.hashCode();
    h$ *= 1000003;
    h$ ^= contributingModule.hashCode();
    h$ *= 1000003;
    h$ ^= kind.hashCode();
    h$ *= 1000003;
    h$ ^= nullableType.hashCode();
    h$ *= 1000003;
    h$ ^= wrappedMapKeyAnnotation.hashCode();
    h$ *= 1000003;
    h$ ^= isContributingModuleKotlinObject.hashCode();
    h$ *= 1000003;
    h$ ^= provisionDependencies.hashCode();
    h$ *= 1000003;
    h$ ^= injectionSites.hashCode();
    h$ *= 1000003;
    h$ ^= unresolved.hashCode();
    h$ *= 1000003;
    h$ ^= scope.hashCode();
    return h$;
  }

  @Override
  public ProvisionBinding.Builder toBuilder() {
    return new Builder(this);
  }

  static class Builder extends ProvisionBinding.Builder {
    private ContributionType contributionType;
    private Key key;
    private Optional<Element> bindingElement = Optional.empty();
    private Optional<TypeElement> contributingModule = Optional.empty();
    private BindingKind kind;
    private Optional<DeclaredType> nullableType = Optional.empty();
    private Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation = Optional.empty();
    private Optional<Boolean> isContributingModuleKotlinObject = Optional.empty();
    private ImmutableSet<DependencyRequest> provisionDependencies;
    private ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites;
    private Optional<ProvisionBinding> unresolved = Optional.empty();
    private Optional<Scope> scope = Optional.empty();
    Builder() {
    }
    private Builder(ProvisionBinding source) {
      this.contributionType = source.contributionType();
      this.key = source.key();
      this.bindingElement = source.bindingElement();
      this.contributingModule = source.contributingModule();
      this.kind = source.kind();
      this.nullableType = source.nullableType();
      this.wrappedMapKeyAnnotation = source.wrappedMapKeyAnnotation();
      this.isContributingModuleKotlinObject = source.isContributingModuleKotlinObject();
      this.provisionDependencies = source.provisionDependencies();
      this.injectionSites = source.injectionSites();
      this.unresolved = source.unresolved();
      this.scope = source.scope();
    }
    @Override
    public ProvisionBinding.Builder contributionType(ContributionType contributionType) {
      if (contributionType == null) {
        throw new NullPointerException("Null contributionType");
      }
      this.contributionType = contributionType;
      return this;
    }
    @Override
    public ProvisionBinding.Builder key(Key key) {
      if (key == null) {
        throw new NullPointerException("Null key");
      }
      this.key = key;
      return this;
    }
    @Override
    public ProvisionBinding.Builder bindingElement(Element bindingElement) {
      this.bindingElement = Optional.of(bindingElement);
      return this;
    }
    @Override
    ProvisionBinding.Builder bindingElement(Optional<Element> bindingElement) {
      if (bindingElement == null) {
        throw new NullPointerException("Null bindingElement");
      }
      this.bindingElement = bindingElement;
      return this;
    }
    @Override
    ProvisionBinding.Builder contributingModule(TypeElement contributingModule) {
      this.contributingModule = Optional.of(contributingModule);
      return this;
    }
    @Override
    public ProvisionBinding.Builder kind(BindingKind kind) {
      if (kind == null) {
        throw new NullPointerException("Null kind");
      }
      this.kind = kind;
      return this;
    }
    @Override
    public ProvisionBinding.Builder nullableType(Optional<DeclaredType> nullableType) {
      if (nullableType == null) {
        throw new NullPointerException("Null nullableType");
      }
      this.nullableType = nullableType;
      return this;
    }
    @Override
    ProvisionBinding.Builder wrappedMapKeyAnnotation(Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation) {
      if (wrappedMapKeyAnnotation == null) {
        throw new NullPointerException("Null wrappedMapKeyAnnotation");
      }
      this.wrappedMapKeyAnnotation = wrappedMapKeyAnnotation;
      return this;
    }
    @Override
    ProvisionBinding.Builder isContributingModuleKotlinObject(boolean isContributingModuleKotlinObject) {
      this.isContributingModuleKotlinObject = Optional.of(isContributingModuleKotlinObject);
      return this;
    }
    @Override
    ProvisionBinding.Builder provisionDependencies(Iterable<DependencyRequest> provisionDependencies) {
      this.provisionDependencies = ImmutableSet.copyOf(provisionDependencies);
      return this;
    }
    @Override
    public ProvisionBinding.Builder injectionSites(ImmutableSortedSet<MembersInjectionBinding.InjectionSite> injectionSites) {
      if (injectionSites == null) {
        throw new NullPointerException("Null injectionSites");
      }
      this.injectionSites = injectionSites;
      return this;
    }
    @Override
    public ProvisionBinding.Builder unresolved(ProvisionBinding unresolved) {
      this.unresolved = Optional.of(unresolved);
      return this;
    }
    @Override
    public ProvisionBinding.Builder scope(Optional<Scope> scope) {
      if (scope == null) {
        throw new NullPointerException("Null scope");
      }
      this.scope = scope;
      return this;
    }
    @Override
    ProvisionBinding autoBuild() {
      String missing = "";
      if (this.contributionType == null) {
        missing += " contributionType";
      }
      if (this.key == null) {
        missing += " key";
      }
      if (this.kind == null) {
        missing += " kind";
      }
      if (this.provisionDependencies == null) {
        missing += " provisionDependencies";
      }
      if (this.injectionSites == null) {
        missing += " injectionSites";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_ProvisionBinding(
          this.contributionType,
          this.key,
          this.bindingElement,
          this.contributingModule,
          this.kind,
          this.nullableType,
          this.wrappedMapKeyAnnotation,
          this.isContributingModuleKotlinObject,
          this.provisionDependencies,
          this.injectionSites,
          this.unresolved,
          this.scope);
    }
  }

}

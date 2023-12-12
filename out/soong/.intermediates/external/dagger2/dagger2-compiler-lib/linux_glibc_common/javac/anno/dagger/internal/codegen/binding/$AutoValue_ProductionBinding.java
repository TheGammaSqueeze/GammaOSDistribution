package dagger.internal.codegen.binding;

import com.google.common.base.Equivalence;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import dagger.internal.codegen.base.ContributionType;
import dagger.model.BindingKind;
import dagger.model.DependencyRequest;
import dagger.model.Key;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.DeclaredType;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ProductionBinding extends ProductionBinding {

  private final ContributionType contributionType;

  private final Key key;

  private final Optional<Element> bindingElement;

  private final Optional<TypeElement> contributingModule;

  private final BindingKind kind;

  private final ImmutableSet<DependencyRequest> explicitDependencies;

  private final Optional<DeclaredType> nullableType;

  private final Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation;

  private final Optional<Boolean> isContributingModuleKotlinObject;

  private final Optional<ProductionBinding> unresolved;

  private final Optional<ProductionBinding.ProductionKind> productionKind;

  private final ImmutableList<? extends TypeMirror> thrownTypes;

  private final Optional<DependencyRequest> executorRequest;

  private final Optional<DependencyRequest> monitorRequest;

  $AutoValue_ProductionBinding(
      ContributionType contributionType,
      Key key,
      Optional<Element> bindingElement,
      Optional<TypeElement> contributingModule,
      BindingKind kind,
      ImmutableSet<DependencyRequest> explicitDependencies,
      Optional<DeclaredType> nullableType,
      Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation,
      Optional<Boolean> isContributingModuleKotlinObject,
      Optional<ProductionBinding> unresolved,
      Optional<ProductionBinding.ProductionKind> productionKind,
      ImmutableList<? extends TypeMirror> thrownTypes,
      Optional<DependencyRequest> executorRequest,
      Optional<DependencyRequest> monitorRequest) {
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
    if (explicitDependencies == null) {
      throw new NullPointerException("Null explicitDependencies");
    }
    this.explicitDependencies = explicitDependencies;
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
    if (unresolved == null) {
      throw new NullPointerException("Null unresolved");
    }
    this.unresolved = unresolved;
    if (productionKind == null) {
      throw new NullPointerException("Null productionKind");
    }
    this.productionKind = productionKind;
    if (thrownTypes == null) {
      throw new NullPointerException("Null thrownTypes");
    }
    this.thrownTypes = thrownTypes;
    if (executorRequest == null) {
      throw new NullPointerException("Null executorRequest");
    }
    this.executorRequest = executorRequest;
    if (monitorRequest == null) {
      throw new NullPointerException("Null monitorRequest");
    }
    this.monitorRequest = monitorRequest;
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
  public ImmutableSet<DependencyRequest> explicitDependencies() {
    return explicitDependencies;
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
  public Optional<ProductionBinding> unresolved() {
    return unresolved;
  }

  @Override
  public Optional<ProductionBinding.ProductionKind> productionKind() {
    return productionKind;
  }

  @Override
  public ImmutableList<? extends TypeMirror> thrownTypes() {
    return thrownTypes;
  }

  @Override
  Optional<DependencyRequest> executorRequest() {
    return executorRequest;
  }

  @Override
  Optional<DependencyRequest> monitorRequest() {
    return monitorRequest;
  }

  @Override
  public String toString() {
    return "ProductionBinding{"
        + "contributionType=" + contributionType + ", "
        + "key=" + key + ", "
        + "bindingElement=" + bindingElement + ", "
        + "contributingModule=" + contributingModule + ", "
        + "kind=" + kind + ", "
        + "explicitDependencies=" + explicitDependencies + ", "
        + "nullableType=" + nullableType + ", "
        + "wrappedMapKeyAnnotation=" + wrappedMapKeyAnnotation + ", "
        + "isContributingModuleKotlinObject=" + isContributingModuleKotlinObject + ", "
        + "unresolved=" + unresolved + ", "
        + "productionKind=" + productionKind + ", "
        + "thrownTypes=" + thrownTypes + ", "
        + "executorRequest=" + executorRequest + ", "
        + "monitorRequest=" + monitorRequest
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ProductionBinding) {
      ProductionBinding that = (ProductionBinding) o;
      return this.contributionType.equals(that.contributionType())
          && this.key.equals(that.key())
          && this.bindingElement.equals(that.bindingElement())
          && this.contributingModule.equals(that.contributingModule())
          && this.kind.equals(that.kind())
          && this.explicitDependencies.equals(that.explicitDependencies())
          && this.nullableType.equals(that.nullableType())
          && this.wrappedMapKeyAnnotation.equals(that.wrappedMapKeyAnnotation())
          && this.isContributingModuleKotlinObject.equals(that.isContributingModuleKotlinObject())
          && this.unresolved.equals(that.unresolved())
          && this.productionKind.equals(that.productionKind())
          && this.thrownTypes.equals(that.thrownTypes())
          && this.executorRequest.equals(that.executorRequest())
          && this.monitorRequest.equals(that.monitorRequest());
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
    h$ ^= explicitDependencies.hashCode();
    h$ *= 1000003;
    h$ ^= nullableType.hashCode();
    h$ *= 1000003;
    h$ ^= wrappedMapKeyAnnotation.hashCode();
    h$ *= 1000003;
    h$ ^= isContributingModuleKotlinObject.hashCode();
    h$ *= 1000003;
    h$ ^= unresolved.hashCode();
    h$ *= 1000003;
    h$ ^= productionKind.hashCode();
    h$ *= 1000003;
    h$ ^= thrownTypes.hashCode();
    h$ *= 1000003;
    h$ ^= executorRequest.hashCode();
    h$ *= 1000003;
    h$ ^= monitorRequest.hashCode();
    return h$;
  }

  @Override
  public ProductionBinding.Builder toBuilder() {
    return new Builder(this);
  }

  static class Builder extends ProductionBinding.Builder {
    private ContributionType contributionType;
    private Key key;
    private Optional<Element> bindingElement = Optional.empty();
    private Optional<TypeElement> contributingModule = Optional.empty();
    private BindingKind kind;
    private ImmutableSet<DependencyRequest> explicitDependencies;
    private Optional<DeclaredType> nullableType = Optional.empty();
    private Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation = Optional.empty();
    private Optional<Boolean> isContributingModuleKotlinObject = Optional.empty();
    private Optional<ProductionBinding> unresolved = Optional.empty();
    private Optional<ProductionBinding.ProductionKind> productionKind = Optional.empty();
    private ImmutableList<? extends TypeMirror> thrownTypes;
    private Optional<DependencyRequest> executorRequest = Optional.empty();
    private Optional<DependencyRequest> monitorRequest = Optional.empty();
    Builder() {
    }
    private Builder(ProductionBinding source) {
      this.contributionType = source.contributionType();
      this.key = source.key();
      this.bindingElement = source.bindingElement();
      this.contributingModule = source.contributingModule();
      this.kind = source.kind();
      this.explicitDependencies = source.explicitDependencies();
      this.nullableType = source.nullableType();
      this.wrappedMapKeyAnnotation = source.wrappedMapKeyAnnotation();
      this.isContributingModuleKotlinObject = source.isContributingModuleKotlinObject();
      this.unresolved = source.unresolved();
      this.productionKind = source.productionKind();
      this.thrownTypes = source.thrownTypes();
      this.executorRequest = source.executorRequest();
      this.monitorRequest = source.monitorRequest();
    }
    @Override
    public ProductionBinding.Builder contributionType(ContributionType contributionType) {
      if (contributionType == null) {
        throw new NullPointerException("Null contributionType");
      }
      this.contributionType = contributionType;
      return this;
    }
    @Override
    public ProductionBinding.Builder key(Key key) {
      if (key == null) {
        throw new NullPointerException("Null key");
      }
      this.key = key;
      return this;
    }
    @Override
    public ProductionBinding.Builder bindingElement(Element bindingElement) {
      this.bindingElement = Optional.of(bindingElement);
      return this;
    }
    @Override
    ProductionBinding.Builder bindingElement(Optional<Element> bindingElement) {
      if (bindingElement == null) {
        throw new NullPointerException("Null bindingElement");
      }
      this.bindingElement = bindingElement;
      return this;
    }
    @Override
    ProductionBinding.Builder contributingModule(TypeElement contributingModule) {
      this.contributingModule = Optional.of(contributingModule);
      return this;
    }
    @Override
    public ProductionBinding.Builder kind(BindingKind kind) {
      if (kind == null) {
        throw new NullPointerException("Null kind");
      }
      this.kind = kind;
      return this;
    }
    @Override
    ProductionBinding.Builder explicitDependencies(Iterable<DependencyRequest> explicitDependencies) {
      this.explicitDependencies = ImmutableSet.copyOf(explicitDependencies);
      return this;
    }
    @Override
    public ProductionBinding.Builder nullableType(Optional<DeclaredType> nullableType) {
      if (nullableType == null) {
        throw new NullPointerException("Null nullableType");
      }
      this.nullableType = nullableType;
      return this;
    }
    @Override
    ProductionBinding.Builder wrappedMapKeyAnnotation(Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKeyAnnotation) {
      if (wrappedMapKeyAnnotation == null) {
        throw new NullPointerException("Null wrappedMapKeyAnnotation");
      }
      this.wrappedMapKeyAnnotation = wrappedMapKeyAnnotation;
      return this;
    }
    @Override
    ProductionBinding.Builder isContributingModuleKotlinObject(boolean isContributingModuleKotlinObject) {
      this.isContributingModuleKotlinObject = Optional.of(isContributingModuleKotlinObject);
      return this;
    }
    @Override
    public ProductionBinding.Builder unresolved(ProductionBinding unresolved) {
      this.unresolved = Optional.of(unresolved);
      return this;
    }
    @Override
    ProductionBinding.Builder productionKind(ProductionBinding.ProductionKind productionKind) {
      this.productionKind = Optional.of(productionKind);
      return this;
    }
    @Override
    ProductionBinding.Builder thrownTypes(Iterable<? extends TypeMirror> thrownTypes) {
      this.thrownTypes = ImmutableList.copyOf(thrownTypes);
      return this;
    }
    @Override
    ProductionBinding.Builder executorRequest(DependencyRequest executorRequest) {
      this.executorRequest = Optional.of(executorRequest);
      return this;
    }
    @Override
    ProductionBinding.Builder monitorRequest(DependencyRequest monitorRequest) {
      this.monitorRequest = Optional.of(monitorRequest);
      return this;
    }
    @Override
    ProductionBinding autoBuild() {
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
      if (this.explicitDependencies == null) {
        missing += " explicitDependencies";
      }
      if (this.thrownTypes == null) {
        missing += " thrownTypes";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_ProductionBinding(
          this.contributionType,
          this.key,
          this.bindingElement,
          this.contributingModule,
          this.kind,
          this.explicitDependencies,
          this.nullableType,
          this.wrappedMapKeyAnnotation,
          this.isContributingModuleKotlinObject,
          this.unresolved,
          this.productionKind,
          this.thrownTypes,
          this.executorRequest,
          this.monitorRequest);
    }
  }

}

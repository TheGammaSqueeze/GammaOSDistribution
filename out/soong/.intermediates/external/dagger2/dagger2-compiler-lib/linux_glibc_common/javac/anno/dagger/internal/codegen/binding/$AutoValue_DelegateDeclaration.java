package dagger.internal.codegen.binding;

import com.google.common.base.Equivalence;
import dagger.internal.codegen.base.ContributionType;
import dagger.model.DependencyRequest;
import dagger.model.Key;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_DelegateDeclaration extends DelegateDeclaration {

  private final ContributionType contributionType;

  private final Key key;

  private final Optional<Element> bindingElement;

  private final Optional<TypeElement> contributingModule;

  private final DependencyRequest delegateRequest;

  private final Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKey;

  $AutoValue_DelegateDeclaration(
      ContributionType contributionType,
      Key key,
      Optional<Element> bindingElement,
      Optional<TypeElement> contributingModule,
      DependencyRequest delegateRequest,
      Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKey) {
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
    if (delegateRequest == null) {
      throw new NullPointerException("Null delegateRequest");
    }
    this.delegateRequest = delegateRequest;
    if (wrappedMapKey == null) {
      throw new NullPointerException("Null wrappedMapKey");
    }
    this.wrappedMapKey = wrappedMapKey;
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
  DependencyRequest delegateRequest() {
    return delegateRequest;
  }

  @Override
  Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedMapKey() {
    return wrappedMapKey;
  }

  @Override
  public String toString() {
    return "DelegateDeclaration{"
        + "contributionType=" + contributionType + ", "
        + "key=" + key + ", "
        + "bindingElement=" + bindingElement + ", "
        + "contributingModule=" + contributingModule + ", "
        + "delegateRequest=" + delegateRequest + ", "
        + "wrappedMapKey=" + wrappedMapKey
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof DelegateDeclaration) {
      DelegateDeclaration that = (DelegateDeclaration) o;
      return this.contributionType.equals(that.contributionType())
          && this.key.equals(that.key())
          && this.bindingElement.equals(that.bindingElement())
          && this.contributingModule.equals(that.contributingModule())
          && this.delegateRequest.equals(that.delegateRequest())
          && this.wrappedMapKey.equals(that.wrappedMapKey());
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
    h$ ^= delegateRequest.hashCode();
    h$ *= 1000003;
    h$ ^= wrappedMapKey.hashCode();
    return h$;
  }

}

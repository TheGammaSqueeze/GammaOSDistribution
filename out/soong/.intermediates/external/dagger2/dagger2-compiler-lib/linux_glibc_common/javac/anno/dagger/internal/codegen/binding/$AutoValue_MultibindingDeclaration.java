package dagger.internal.codegen.binding;

import dagger.internal.codegen.base.ContributionType;
import dagger.model.Key;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_MultibindingDeclaration extends MultibindingDeclaration {

  private final Optional<Element> bindingElement;

  private final Optional<TypeElement> contributingModule;

  private final Key key;

  private final ContributionType contributionType;

  $AutoValue_MultibindingDeclaration(
      Optional<Element> bindingElement,
      Optional<TypeElement> contributingModule,
      Key key,
      ContributionType contributionType) {
    if (bindingElement == null) {
      throw new NullPointerException("Null bindingElement");
    }
    this.bindingElement = bindingElement;
    if (contributingModule == null) {
      throw new NullPointerException("Null contributingModule");
    }
    this.contributingModule = contributingModule;
    if (key == null) {
      throw new NullPointerException("Null key");
    }
    this.key = key;
    if (contributionType == null) {
      throw new NullPointerException("Null contributionType");
    }
    this.contributionType = contributionType;
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
  public Key key() {
    return key;
  }

  @Override
  public ContributionType contributionType() {
    return contributionType;
  }

  @Override
  public String toString() {
    return "MultibindingDeclaration{"
        + "bindingElement=" + bindingElement + ", "
        + "contributingModule=" + contributingModule + ", "
        + "key=" + key + ", "
        + "contributionType=" + contributionType
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof MultibindingDeclaration) {
      MultibindingDeclaration that = (MultibindingDeclaration) o;
      return this.bindingElement.equals(that.bindingElement())
          && this.contributingModule.equals(that.contributingModule())
          && this.key.equals(that.key())
          && this.contributionType.equals(that.contributionType());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= bindingElement.hashCode();
    h$ *= 1000003;
    h$ ^= contributingModule.hashCode();
    h$ *= 1000003;
    h$ ^= key.hashCode();
    h$ *= 1000003;
    h$ ^= contributionType.hashCode();
    return h$;
  }

}

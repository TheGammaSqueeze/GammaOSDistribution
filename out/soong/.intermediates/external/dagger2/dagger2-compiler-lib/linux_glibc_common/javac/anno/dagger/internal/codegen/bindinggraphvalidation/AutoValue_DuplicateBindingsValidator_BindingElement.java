package dagger.internal.codegen.bindinggraphvalidation;

import dagger.model.BindingKind;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_DuplicateBindingsValidator_BindingElement extends DuplicateBindingsValidator.BindingElement {

  private final BindingKind bindingKind;

  private final Optional<Element> bindingElement;

  private final Optional<TypeElement> contributingModule;

  AutoValue_DuplicateBindingsValidator_BindingElement(
      BindingKind bindingKind,
      Optional<Element> bindingElement,
      Optional<TypeElement> contributingModule) {
    if (bindingKind == null) {
      throw new NullPointerException("Null bindingKind");
    }
    this.bindingKind = bindingKind;
    if (bindingElement == null) {
      throw new NullPointerException("Null bindingElement");
    }
    this.bindingElement = bindingElement;
    if (contributingModule == null) {
      throw new NullPointerException("Null contributingModule");
    }
    this.contributingModule = contributingModule;
  }

  @Override
  BindingKind bindingKind() {
    return bindingKind;
  }

  @Override
  Optional<Element> bindingElement() {
    return bindingElement;
  }

  @Override
  Optional<TypeElement> contributingModule() {
    return contributingModule;
  }

  @Override
  public String toString() {
    return "BindingElement{"
        + "bindingKind=" + bindingKind + ", "
        + "bindingElement=" + bindingElement + ", "
        + "contributingModule=" + contributingModule
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof DuplicateBindingsValidator.BindingElement) {
      DuplicateBindingsValidator.BindingElement that = (DuplicateBindingsValidator.BindingElement) o;
      return this.bindingKind.equals(that.bindingKind())
          && this.bindingElement.equals(that.bindingElement())
          && this.contributingModule.equals(that.contributingModule());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= bindingKind.hashCode();
    h$ *= 1000003;
    h$ ^= bindingElement.hashCode();
    h$ *= 1000003;
    h$ ^= contributingModule.hashCode();
    return h$;
  }

}

package dagger.internal.codegen.binding;

import dagger.model.Key;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_OptionalBindingDeclaration extends OptionalBindingDeclaration {

  private final Optional<Element> bindingElement;

  private final Optional<TypeElement> contributingModule;

  private final Key key;

  $AutoValue_OptionalBindingDeclaration(
      Optional<Element> bindingElement,
      Optional<TypeElement> contributingModule,
      Key key) {
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
  public String toString() {
    return "OptionalBindingDeclaration{"
        + "bindingElement=" + bindingElement + ", "
        + "contributingModule=" + contributingModule + ", "
        + "key=" + key
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof OptionalBindingDeclaration) {
      OptionalBindingDeclaration that = (OptionalBindingDeclaration) o;
      return this.bindingElement.equals(that.bindingElement())
          && this.contributingModule.equals(that.contributingModule())
          && this.key.equals(that.key());
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
    return h$;
  }

}

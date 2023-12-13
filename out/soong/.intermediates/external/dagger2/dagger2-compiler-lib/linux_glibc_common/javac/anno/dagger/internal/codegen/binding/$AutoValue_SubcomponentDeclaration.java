package dagger.internal.codegen.binding;

import dagger.internal.codegen.base.ModuleAnnotation;
import dagger.model.Key;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_SubcomponentDeclaration extends SubcomponentDeclaration {

  private final Optional<Element> bindingElement;

  private final Optional<TypeElement> contributingModule;

  private final Key key;

  private final TypeElement subcomponentType;

  private final ModuleAnnotation moduleAnnotation;

  $AutoValue_SubcomponentDeclaration(
      Optional<Element> bindingElement,
      Optional<TypeElement> contributingModule,
      Key key,
      TypeElement subcomponentType,
      ModuleAnnotation moduleAnnotation) {
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
    if (subcomponentType == null) {
      throw new NullPointerException("Null subcomponentType");
    }
    this.subcomponentType = subcomponentType;
    if (moduleAnnotation == null) {
      throw new NullPointerException("Null moduleAnnotation");
    }
    this.moduleAnnotation = moduleAnnotation;
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
  TypeElement subcomponentType() {
    return subcomponentType;
  }

  @Override
  public ModuleAnnotation moduleAnnotation() {
    return moduleAnnotation;
  }

  @Override
  public String toString() {
    return "SubcomponentDeclaration{"
        + "bindingElement=" + bindingElement + ", "
        + "contributingModule=" + contributingModule + ", "
        + "key=" + key + ", "
        + "subcomponentType=" + subcomponentType + ", "
        + "moduleAnnotation=" + moduleAnnotation
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof SubcomponentDeclaration) {
      SubcomponentDeclaration that = (SubcomponentDeclaration) o;
      return this.bindingElement.equals(that.bindingElement())
          && this.contributingModule.equals(that.contributingModule())
          && this.key.equals(that.key())
          && this.subcomponentType.equals(that.subcomponentType())
          && this.moduleAnnotation.equals(that.moduleAnnotation());
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
    h$ ^= subcomponentType.hashCode();
    h$ *= 1000003;
    h$ ^= moduleAnnotation.hashCode();
    return h$;
  }

}

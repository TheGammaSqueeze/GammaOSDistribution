package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableSetMultimap;
import javax.annotation.Generated;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;
import javax.lang.model.element.VariableElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ComponentCreatorDescriptor extends ComponentCreatorDescriptor {

  private final ComponentCreatorAnnotation annotation;

  private final TypeElement typeElement;

  private final ExecutableElement factoryMethod;

  private final ImmutableSetMultimap<ComponentRequirement, ExecutableElement> unvalidatedSetterMethods;

  private final ImmutableSetMultimap<ComponentRequirement, VariableElement> unvalidatedFactoryParameters;

  $AutoValue_ComponentCreatorDescriptor(
      ComponentCreatorAnnotation annotation,
      TypeElement typeElement,
      ExecutableElement factoryMethod,
      ImmutableSetMultimap<ComponentRequirement, ExecutableElement> unvalidatedSetterMethods,
      ImmutableSetMultimap<ComponentRequirement, VariableElement> unvalidatedFactoryParameters) {
    if (annotation == null) {
      throw new NullPointerException("Null annotation");
    }
    this.annotation = annotation;
    if (typeElement == null) {
      throw new NullPointerException("Null typeElement");
    }
    this.typeElement = typeElement;
    if (factoryMethod == null) {
      throw new NullPointerException("Null factoryMethod");
    }
    this.factoryMethod = factoryMethod;
    if (unvalidatedSetterMethods == null) {
      throw new NullPointerException("Null unvalidatedSetterMethods");
    }
    this.unvalidatedSetterMethods = unvalidatedSetterMethods;
    if (unvalidatedFactoryParameters == null) {
      throw new NullPointerException("Null unvalidatedFactoryParameters");
    }
    this.unvalidatedFactoryParameters = unvalidatedFactoryParameters;
  }

  @Override
  public ComponentCreatorAnnotation annotation() {
    return annotation;
  }

  @Override
  public TypeElement typeElement() {
    return typeElement;
  }

  @Override
  public ExecutableElement factoryMethod() {
    return factoryMethod;
  }

  @Override
  ImmutableSetMultimap<ComponentRequirement, ExecutableElement> unvalidatedSetterMethods() {
    return unvalidatedSetterMethods;
  }

  @Override
  ImmutableSetMultimap<ComponentRequirement, VariableElement> unvalidatedFactoryParameters() {
    return unvalidatedFactoryParameters;
  }

  @Override
  public String toString() {
    return "ComponentCreatorDescriptor{"
        + "annotation=" + annotation + ", "
        + "typeElement=" + typeElement + ", "
        + "factoryMethod=" + factoryMethod + ", "
        + "unvalidatedSetterMethods=" + unvalidatedSetterMethods + ", "
        + "unvalidatedFactoryParameters=" + unvalidatedFactoryParameters
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ComponentCreatorDescriptor) {
      ComponentCreatorDescriptor that = (ComponentCreatorDescriptor) o;
      return this.annotation.equals(that.annotation())
          && this.typeElement.equals(that.typeElement())
          && this.factoryMethod.equals(that.factoryMethod())
          && this.unvalidatedSetterMethods.equals(that.unvalidatedSetterMethods())
          && this.unvalidatedFactoryParameters.equals(that.unvalidatedFactoryParameters());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= annotation.hashCode();
    h$ *= 1000003;
    h$ ^= typeElement.hashCode();
    h$ *= 1000003;
    h$ ^= factoryMethod.hashCode();
    h$ *= 1000003;
    h$ ^= unvalidatedSetterMethods.hashCode();
    h$ *= 1000003;
    h$ ^= unvalidatedFactoryParameters.hashCode();
    return h$;
  }

}

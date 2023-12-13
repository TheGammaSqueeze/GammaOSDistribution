package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableBiMap;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import dagger.internal.codegen.base.ComponentAnnotation;
import dagger.model.Scope;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_ComponentDescriptor extends ComponentDescriptor {

  private final ComponentAnnotation annotation;

  private final TypeElement typeElement;

  private final ImmutableSet<ComponentRequirement> dependencies;

  private final ImmutableSet<ModuleDescriptor> modules;

  private final ImmutableMap<ExecutableElement, ComponentRequirement> dependenciesByDependencyMethod;

  private final ImmutableSet<Scope> scopes;

  private final ImmutableSet<ComponentDescriptor> childComponentsDeclaredByModules;

  private final ImmutableBiMap<ComponentDescriptor.ComponentMethodDescriptor, ComponentDescriptor> childComponentsDeclaredByFactoryMethods;

  private final ImmutableBiMap<ComponentDescriptor.ComponentMethodDescriptor, ComponentDescriptor> childComponentsDeclaredByBuilderEntryPoints;

  private final ImmutableSet<ComponentDescriptor.ComponentMethodDescriptor> componentMethods;

  private final Optional<ComponentCreatorDescriptor> creatorDescriptor;

  $AutoValue_ComponentDescriptor(
      ComponentAnnotation annotation,
      TypeElement typeElement,
      ImmutableSet<ComponentRequirement> dependencies,
      ImmutableSet<ModuleDescriptor> modules,
      ImmutableMap<ExecutableElement, ComponentRequirement> dependenciesByDependencyMethod,
      ImmutableSet<Scope> scopes,
      ImmutableSet<ComponentDescriptor> childComponentsDeclaredByModules,
      ImmutableBiMap<ComponentDescriptor.ComponentMethodDescriptor, ComponentDescriptor> childComponentsDeclaredByFactoryMethods,
      ImmutableBiMap<ComponentDescriptor.ComponentMethodDescriptor, ComponentDescriptor> childComponentsDeclaredByBuilderEntryPoints,
      ImmutableSet<ComponentDescriptor.ComponentMethodDescriptor> componentMethods,
      Optional<ComponentCreatorDescriptor> creatorDescriptor) {
    if (annotation == null) {
      throw new NullPointerException("Null annotation");
    }
    this.annotation = annotation;
    if (typeElement == null) {
      throw new NullPointerException("Null typeElement");
    }
    this.typeElement = typeElement;
    if (dependencies == null) {
      throw new NullPointerException("Null dependencies");
    }
    this.dependencies = dependencies;
    if (modules == null) {
      throw new NullPointerException("Null modules");
    }
    this.modules = modules;
    if (dependenciesByDependencyMethod == null) {
      throw new NullPointerException("Null dependenciesByDependencyMethod");
    }
    this.dependenciesByDependencyMethod = dependenciesByDependencyMethod;
    if (scopes == null) {
      throw new NullPointerException("Null scopes");
    }
    this.scopes = scopes;
    if (childComponentsDeclaredByModules == null) {
      throw new NullPointerException("Null childComponentsDeclaredByModules");
    }
    this.childComponentsDeclaredByModules = childComponentsDeclaredByModules;
    if (childComponentsDeclaredByFactoryMethods == null) {
      throw new NullPointerException("Null childComponentsDeclaredByFactoryMethods");
    }
    this.childComponentsDeclaredByFactoryMethods = childComponentsDeclaredByFactoryMethods;
    if (childComponentsDeclaredByBuilderEntryPoints == null) {
      throw new NullPointerException("Null childComponentsDeclaredByBuilderEntryPoints");
    }
    this.childComponentsDeclaredByBuilderEntryPoints = childComponentsDeclaredByBuilderEntryPoints;
    if (componentMethods == null) {
      throw new NullPointerException("Null componentMethods");
    }
    this.componentMethods = componentMethods;
    if (creatorDescriptor == null) {
      throw new NullPointerException("Null creatorDescriptor");
    }
    this.creatorDescriptor = creatorDescriptor;
  }

  @Override
  public ComponentAnnotation annotation() {
    return annotation;
  }

  @Override
  public TypeElement typeElement() {
    return typeElement;
  }

  @Override
  public ImmutableSet<ComponentRequirement> dependencies() {
    return dependencies;
  }

  @Override
  public ImmutableSet<ModuleDescriptor> modules() {
    return modules;
  }

  @Override
  public ImmutableMap<ExecutableElement, ComponentRequirement> dependenciesByDependencyMethod() {
    return dependenciesByDependencyMethod;
  }

  @Override
  public ImmutableSet<Scope> scopes() {
    return scopes;
  }

  @Override
  ImmutableSet<ComponentDescriptor> childComponentsDeclaredByModules() {
    return childComponentsDeclaredByModules;
  }

  @Override
  public ImmutableBiMap<ComponentDescriptor.ComponentMethodDescriptor, ComponentDescriptor> childComponentsDeclaredByFactoryMethods() {
    return childComponentsDeclaredByFactoryMethods;
  }

  @Override
  ImmutableBiMap<ComponentDescriptor.ComponentMethodDescriptor, ComponentDescriptor> childComponentsDeclaredByBuilderEntryPoints() {
    return childComponentsDeclaredByBuilderEntryPoints;
  }

  @Override
  public ImmutableSet<ComponentDescriptor.ComponentMethodDescriptor> componentMethods() {
    return componentMethods;
  }

  @Override
  public Optional<ComponentCreatorDescriptor> creatorDescriptor() {
    return creatorDescriptor;
  }

  @Override
  public String toString() {
    return "ComponentDescriptor{"
        + "annotation=" + annotation + ", "
        + "typeElement=" + typeElement + ", "
        + "dependencies=" + dependencies + ", "
        + "modules=" + modules + ", "
        + "dependenciesByDependencyMethod=" + dependenciesByDependencyMethod + ", "
        + "scopes=" + scopes + ", "
        + "childComponentsDeclaredByModules=" + childComponentsDeclaredByModules + ", "
        + "childComponentsDeclaredByFactoryMethods=" + childComponentsDeclaredByFactoryMethods + ", "
        + "childComponentsDeclaredByBuilderEntryPoints=" + childComponentsDeclaredByBuilderEntryPoints + ", "
        + "componentMethods=" + componentMethods + ", "
        + "creatorDescriptor=" + creatorDescriptor
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ComponentDescriptor) {
      ComponentDescriptor that = (ComponentDescriptor) o;
      return this.annotation.equals(that.annotation())
          && this.typeElement.equals(that.typeElement())
          && this.dependencies.equals(that.dependencies())
          && this.modules.equals(that.modules())
          && this.dependenciesByDependencyMethod.equals(that.dependenciesByDependencyMethod())
          && this.scopes.equals(that.scopes())
          && this.childComponentsDeclaredByModules.equals(that.childComponentsDeclaredByModules())
          && this.childComponentsDeclaredByFactoryMethods.equals(that.childComponentsDeclaredByFactoryMethods())
          && this.childComponentsDeclaredByBuilderEntryPoints.equals(that.childComponentsDeclaredByBuilderEntryPoints())
          && this.componentMethods.equals(that.componentMethods())
          && this.creatorDescriptor.equals(that.creatorDescriptor());
    }
    return false;
  }

}

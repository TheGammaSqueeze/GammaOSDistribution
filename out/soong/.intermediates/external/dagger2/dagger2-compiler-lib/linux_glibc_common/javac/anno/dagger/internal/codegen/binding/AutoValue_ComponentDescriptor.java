package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableBiMap;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import com.google.errorprone.annotations.concurrent.LazyInit;
import dagger.internal.codegen.base.ComponentAnnotation;
import dagger.model.Scope;
import java.lang.Object;
import java.lang.Override;
import java.lang.SuppressWarnings;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ComponentDescriptor extends $AutoValue_ComponentDescriptor {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableSet<ComponentRequirement> requirements;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableMap<TypeElement, ComponentDescriptor> childComponentsByElement;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile int hashCode;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile boolean hashCode$Memoized;

  AutoValue_ComponentDescriptor(ComponentAnnotation annotation$, TypeElement typeElement$,
      ImmutableSet<ComponentRequirement> dependencies$, ImmutableSet<ModuleDescriptor> modules$,
      ImmutableMap<ExecutableElement, ComponentRequirement> dependenciesByDependencyMethod$,
      ImmutableSet<Scope> scopes$,
      ImmutableSet<ComponentDescriptor> childComponentsDeclaredByModules$,
      ImmutableBiMap<ComponentDescriptor.ComponentMethodDescriptor, ComponentDescriptor> childComponentsDeclaredByFactoryMethods$,
      ImmutableBiMap<ComponentDescriptor.ComponentMethodDescriptor, ComponentDescriptor> childComponentsDeclaredByBuilderEntryPoints$,
      ImmutableSet<ComponentDescriptor.ComponentMethodDescriptor> componentMethods$,
      Optional<ComponentCreatorDescriptor> creatorDescriptor$) {
    super(annotation$, typeElement$, dependencies$, modules$, dependenciesByDependencyMethod$, scopes$, childComponentsDeclaredByModules$, childComponentsDeclaredByFactoryMethods$, childComponentsDeclaredByBuilderEntryPoints$, componentMethods$, creatorDescriptor$);
  }

  @Override
  ImmutableSet<ComponentRequirement> requirements() {
    if (requirements == null) {
      synchronized (this) {
        if (requirements == null) {
          requirements = super.requirements();
          if (requirements == null) {
            throw new NullPointerException("requirements() cannot return null");
          }
        }
      }
    }
    return requirements;
  }

  @Override
  public ImmutableMap<TypeElement, ComponentDescriptor> childComponentsByElement() {
    if (childComponentsByElement == null) {
      synchronized (this) {
        if (childComponentsByElement == null) {
          childComponentsByElement = super.childComponentsByElement();
          if (childComponentsByElement == null) {
            throw new NullPointerException("childComponentsByElement() cannot return null");
          }
        }
      }
    }
    return childComponentsByElement;
  }

  @Override
  public int hashCode() {
    if (!hashCode$Memoized) {
      synchronized (this) {
        if (!hashCode$Memoized) {
          hashCode = super.hashCode();
          hashCode$Memoized = true;
        }
      }
    }
    return hashCode;
  }

  @Override
  public boolean equals(Object that) {
    if (this == that) {
      return true;
    }
    return that instanceof AutoValue_ComponentDescriptor && this.hashCode() == that.hashCode() && super.equals(that);
  }
}

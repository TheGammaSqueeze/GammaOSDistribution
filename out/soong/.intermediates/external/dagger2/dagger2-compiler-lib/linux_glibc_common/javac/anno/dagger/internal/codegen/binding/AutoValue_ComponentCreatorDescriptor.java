package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSetMultimap;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.Element;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;
import javax.lang.model.element.VariableElement;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_ComponentCreatorDescriptor extends $AutoValue_ComponentCreatorDescriptor {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableMap<ComponentRequirement, Element> requirementElements;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableMap<ComponentRequirement, ExecutableElement> setterMethods;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableMap<ComponentRequirement, VariableElement> factoryParameters;

  AutoValue_ComponentCreatorDescriptor(ComponentCreatorAnnotation annotation$,
      TypeElement typeElement$, ExecutableElement factoryMethod$,
      ImmutableSetMultimap<ComponentRequirement, ExecutableElement> unvalidatedSetterMethods$,
      ImmutableSetMultimap<ComponentRequirement, VariableElement> unvalidatedFactoryParameters$) {
    super(annotation$, typeElement$, factoryMethod$, unvalidatedSetterMethods$, unvalidatedFactoryParameters$);
  }

  @Override
  ImmutableMap<ComponentRequirement, Element> requirementElements() {
    if (requirementElements == null) {
      synchronized (this) {
        if (requirementElements == null) {
          requirementElements = super.requirementElements();
          if (requirementElements == null) {
            throw new NullPointerException("requirementElements() cannot return null");
          }
        }
      }
    }
    return requirementElements;
  }

  @Override
  public ImmutableMap<ComponentRequirement, ExecutableElement> setterMethods() {
    if (setterMethods == null) {
      synchronized (this) {
        if (setterMethods == null) {
          setterMethods = super.setterMethods();
          if (setterMethods == null) {
            throw new NullPointerException("setterMethods() cannot return null");
          }
        }
      }
    }
    return setterMethods;
  }

  @Override
  public ImmutableMap<ComponentRequirement, VariableElement> factoryParameters() {
    if (factoryParameters == null) {
      synchronized (this) {
        if (factoryParameters == null) {
          factoryParameters = super.factoryParameters();
          if (factoryParameters == null) {
            throw new NullPointerException("factoryParameters() cannot return null");
          }
        }
      }
    }
    return factoryParameters;
  }
}

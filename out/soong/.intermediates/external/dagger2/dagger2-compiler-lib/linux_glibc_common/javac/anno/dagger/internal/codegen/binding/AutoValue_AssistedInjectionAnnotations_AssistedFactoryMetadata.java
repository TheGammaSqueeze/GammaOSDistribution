package dagger.internal.codegen.binding;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.errorprone.annotations.concurrent.LazyInit;
import java.lang.Override;
import java.lang.SuppressWarnings;
import javax.annotation.Generated;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;
import javax.lang.model.element.VariableElement;
import javax.lang.model.type.DeclaredType;
import javax.lang.model.type.ExecutableType;

@Generated("com.google.auto.value.extension.memoized.processor.MemoizeExtension")
final class AutoValue_AssistedInjectionAnnotations_AssistedFactoryMetadata extends $AutoValue_AssistedInjectionAnnotations_AssistedFactoryMetadata {
  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableMap<AssistedInjectionAnnotations.AssistedParameter, VariableElement> assistedInjectAssistedParametersMap;

  @LazyInit
  @SuppressWarnings("Immutable")
  private transient volatile ImmutableMap<AssistedInjectionAnnotations.AssistedParameter, VariableElement> assistedFactoryAssistedParametersMap;

  AutoValue_AssistedInjectionAnnotations_AssistedFactoryMetadata(TypeElement factory$,
      DeclaredType factoryType$, ExecutableElement factoryMethod$,
      ExecutableType factoryMethodType$, TypeElement assistedInjectElement$,
      DeclaredType assistedInjectType$,
      ImmutableList<AssistedInjectionAnnotations.AssistedParameter> assistedInjectAssistedParameters$,
      ImmutableList<AssistedInjectionAnnotations.AssistedParameter> assistedFactoryAssistedParameters$) {
    super(factory$, factoryType$, factoryMethod$, factoryMethodType$, assistedInjectElement$, assistedInjectType$, assistedInjectAssistedParameters$, assistedFactoryAssistedParameters$);
  }

  @Override
  public ImmutableMap<AssistedInjectionAnnotations.AssistedParameter, VariableElement> assistedInjectAssistedParametersMap(
      ) {
    if (assistedInjectAssistedParametersMap == null) {
      synchronized (this) {
        if (assistedInjectAssistedParametersMap == null) {
          assistedInjectAssistedParametersMap = super.assistedInjectAssistedParametersMap();
          if (assistedInjectAssistedParametersMap == null) {
            throw new NullPointerException("assistedInjectAssistedParametersMap() cannot return null");
          }
        }
      }
    }
    return assistedInjectAssistedParametersMap;
  }

  @Override
  public ImmutableMap<AssistedInjectionAnnotations.AssistedParameter, VariableElement> assistedFactoryAssistedParametersMap(
      ) {
    if (assistedFactoryAssistedParametersMap == null) {
      synchronized (this) {
        if (assistedFactoryAssistedParametersMap == null) {
          assistedFactoryAssistedParametersMap = super.assistedFactoryAssistedParametersMap();
          if (assistedFactoryAssistedParametersMap == null) {
            throw new NullPointerException("assistedFactoryAssistedParametersMap() cannot return null");
          }
        }
      }
    }
    return assistedFactoryAssistedParametersMap;
  }
}

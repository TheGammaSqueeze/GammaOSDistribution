package com.android.systemui.classifier;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Set;
import javax.annotation.processing.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class FalsingModule_ProvidesBrightLineGestureClassifiersFactory implements Factory<Set<FalsingClassifier>> {
  private final Provider<DistanceClassifier> distanceClassifierProvider;

  private final Provider<ProximityClassifier> proximityClassifierProvider;

  private final Provider<PointerCountClassifier> pointerCountClassifierProvider;

  private final Provider<TypeClassifier> typeClassifierProvider;

  private final Provider<DiagonalClassifier> diagonalClassifierProvider;

  private final Provider<ZigZagClassifier> zigZagClassifierProvider;

  public FalsingModule_ProvidesBrightLineGestureClassifiersFactory(
      Provider<DistanceClassifier> distanceClassifierProvider,
      Provider<ProximityClassifier> proximityClassifierProvider,
      Provider<PointerCountClassifier> pointerCountClassifierProvider,
      Provider<TypeClassifier> typeClassifierProvider,
      Provider<DiagonalClassifier> diagonalClassifierProvider,
      Provider<ZigZagClassifier> zigZagClassifierProvider) {
    this.distanceClassifierProvider = distanceClassifierProvider;
    this.proximityClassifierProvider = proximityClassifierProvider;
    this.pointerCountClassifierProvider = pointerCountClassifierProvider;
    this.typeClassifierProvider = typeClassifierProvider;
    this.diagonalClassifierProvider = diagonalClassifierProvider;
    this.zigZagClassifierProvider = zigZagClassifierProvider;
  }

  @Override
  public Set<FalsingClassifier> get() {
    return providesBrightLineGestureClassifiers(distanceClassifierProvider.get(), proximityClassifierProvider.get(), pointerCountClassifierProvider.get(), typeClassifierProvider.get(), diagonalClassifierProvider.get(), zigZagClassifierProvider.get());
  }

  public static FalsingModule_ProvidesBrightLineGestureClassifiersFactory create(
      Provider<DistanceClassifier> distanceClassifierProvider,
      Provider<ProximityClassifier> proximityClassifierProvider,
      Provider<PointerCountClassifier> pointerCountClassifierProvider,
      Provider<TypeClassifier> typeClassifierProvider,
      Provider<DiagonalClassifier> diagonalClassifierProvider,
      Provider<ZigZagClassifier> zigZagClassifierProvider) {
    return new FalsingModule_ProvidesBrightLineGestureClassifiersFactory(distanceClassifierProvider, proximityClassifierProvider, pointerCountClassifierProvider, typeClassifierProvider, diagonalClassifierProvider, zigZagClassifierProvider);
  }

  public static Set<FalsingClassifier> providesBrightLineGestureClassifiers(
      Object distanceClassifier, Object proximityClassifier, Object pointerCountClassifier,
      TypeClassifier typeClassifier, Object diagonalClassifier, Object zigZagClassifier) {
    return Preconditions.checkNotNullFromProvides(FalsingModule.providesBrightLineGestureClassifiers((DistanceClassifier) distanceClassifier, (ProximityClassifier) proximityClassifier, (PointerCountClassifier) pointerCountClassifier, typeClassifier, (DiagonalClassifier) diagonalClassifier, (ZigZagClassifier) zigZagClassifier));
  }
}

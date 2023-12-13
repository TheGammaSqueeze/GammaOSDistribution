package com.android.systemui.classifier;

import dagger.internal.Factory;
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
public final class DoubleTapClassifier_Factory implements Factory<DoubleTapClassifier> {
  private final Provider<FalsingDataProvider> dataProvider;

  private final Provider<SingleTapClassifier> singleTapClassifierProvider;

  private final Provider<Float> doubleTapSlopProvider;

  private final Provider<Long> doubleTapTimeMsProvider;

  public DoubleTapClassifier_Factory(Provider<FalsingDataProvider> dataProvider,
      Provider<SingleTapClassifier> singleTapClassifierProvider,
      Provider<Float> doubleTapSlopProvider, Provider<Long> doubleTapTimeMsProvider) {
    this.dataProvider = dataProvider;
    this.singleTapClassifierProvider = singleTapClassifierProvider;
    this.doubleTapSlopProvider = doubleTapSlopProvider;
    this.doubleTapTimeMsProvider = doubleTapTimeMsProvider;
  }

  @Override
  public DoubleTapClassifier get() {
    return newInstance(dataProvider.get(), singleTapClassifierProvider.get(), doubleTapSlopProvider.get(), doubleTapTimeMsProvider.get());
  }

  public static DoubleTapClassifier_Factory create(Provider<FalsingDataProvider> dataProvider,
      Provider<SingleTapClassifier> singleTapClassifierProvider,
      Provider<Float> doubleTapSlopProvider, Provider<Long> doubleTapTimeMsProvider) {
    return new DoubleTapClassifier_Factory(dataProvider, singleTapClassifierProvider, doubleTapSlopProvider, doubleTapTimeMsProvider);
  }

  public static DoubleTapClassifier newInstance(FalsingDataProvider dataProvider,
      SingleTapClassifier singleTapClassifier, float doubleTapSlop, long doubleTapTimeMs) {
    return new DoubleTapClassifier(dataProvider, singleTapClassifier, doubleTapSlop, doubleTapTimeMs);
  }
}

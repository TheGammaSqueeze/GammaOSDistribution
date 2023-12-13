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
public final class SingleTapClassifier_Factory implements Factory<SingleTapClassifier> {
  private final Provider<FalsingDataProvider> dataProvider;

  private final Provider<Float> touchSlopProvider;

  public SingleTapClassifier_Factory(Provider<FalsingDataProvider> dataProvider,
      Provider<Float> touchSlopProvider) {
    this.dataProvider = dataProvider;
    this.touchSlopProvider = touchSlopProvider;
  }

  @Override
  public SingleTapClassifier get() {
    return newInstance(dataProvider.get(), touchSlopProvider.get());
  }

  public static SingleTapClassifier_Factory create(Provider<FalsingDataProvider> dataProvider,
      Provider<Float> touchSlopProvider) {
    return new SingleTapClassifier_Factory(dataProvider, touchSlopProvider);
  }

  public static SingleTapClassifier newInstance(FalsingDataProvider dataProvider, float touchSlop) {
    return new SingleTapClassifier(dataProvider, touchSlop);
  }
}

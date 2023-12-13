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
public final class PointerCountClassifier_Factory implements Factory<PointerCountClassifier> {
  private final Provider<FalsingDataProvider> dataProvider;

  public PointerCountClassifier_Factory(Provider<FalsingDataProvider> dataProvider) {
    this.dataProvider = dataProvider;
  }

  @Override
  public PointerCountClassifier get() {
    return newInstance(dataProvider.get());
  }

  public static PointerCountClassifier_Factory create(Provider<FalsingDataProvider> dataProvider) {
    return new PointerCountClassifier_Factory(dataProvider);
  }

  public static PointerCountClassifier newInstance(FalsingDataProvider dataProvider) {
    return new PointerCountClassifier(dataProvider);
  }
}

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
public final class TypeClassifier_Factory implements Factory<TypeClassifier> {
  private final Provider<FalsingDataProvider> dataProvider;

  public TypeClassifier_Factory(Provider<FalsingDataProvider> dataProvider) {
    this.dataProvider = dataProvider;
  }

  @Override
  public TypeClassifier get() {
    return newInstance(dataProvider.get());
  }

  public static TypeClassifier_Factory create(Provider<FalsingDataProvider> dataProvider) {
    return new TypeClassifier_Factory(dataProvider);
  }

  public static TypeClassifier newInstance(FalsingDataProvider dataProvider) {
    return new TypeClassifier(dataProvider);
  }
}

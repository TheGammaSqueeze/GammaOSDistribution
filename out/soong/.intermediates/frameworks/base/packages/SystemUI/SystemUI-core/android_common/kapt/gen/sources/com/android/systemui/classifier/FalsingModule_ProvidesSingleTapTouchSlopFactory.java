package com.android.systemui.classifier;

import android.view.ViewConfiguration;
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
public final class FalsingModule_ProvidesSingleTapTouchSlopFactory implements Factory<Float> {
  private final Provider<ViewConfiguration> viewConfigurationProvider;

  public FalsingModule_ProvidesSingleTapTouchSlopFactory(
      Provider<ViewConfiguration> viewConfigurationProvider) {
    this.viewConfigurationProvider = viewConfigurationProvider;
  }

  @Override
  public Float get() {
    return providesSingleTapTouchSlop(viewConfigurationProvider.get());
  }

  public static FalsingModule_ProvidesSingleTapTouchSlopFactory create(
      Provider<ViewConfiguration> viewConfigurationProvider) {
    return new FalsingModule_ProvidesSingleTapTouchSlopFactory(viewConfigurationProvider);
  }

  public static float providesSingleTapTouchSlop(ViewConfiguration viewConfiguration) {
    return FalsingModule.providesSingleTapTouchSlop(viewConfiguration);
  }
}

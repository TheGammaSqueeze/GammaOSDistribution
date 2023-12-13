package com.android.systemui.classifier;

import android.content.res.Resources;
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
public final class FalsingModule_ProvidesDoubleTapTouchSlopFactory implements Factory<Float> {
  private final Provider<Resources> resourcesProvider;

  public FalsingModule_ProvidesDoubleTapTouchSlopFactory(Provider<Resources> resourcesProvider) {
    this.resourcesProvider = resourcesProvider;
  }

  @Override
  public Float get() {
    return providesDoubleTapTouchSlop(resourcesProvider.get());
  }

  public static FalsingModule_ProvidesDoubleTapTouchSlopFactory create(
      Provider<Resources> resourcesProvider) {
    return new FalsingModule_ProvidesDoubleTapTouchSlopFactory(resourcesProvider);
  }

  public static float providesDoubleTapTouchSlop(Resources resources) {
    return FalsingModule.providesDoubleTapTouchSlop(resources);
  }
}

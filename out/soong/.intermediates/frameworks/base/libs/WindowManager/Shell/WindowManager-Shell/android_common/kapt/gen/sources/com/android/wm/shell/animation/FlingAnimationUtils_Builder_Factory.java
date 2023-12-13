package com.android.wm.shell.animation;

import android.util.DisplayMetrics;
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
public final class FlingAnimationUtils_Builder_Factory implements Factory<FlingAnimationUtils.Builder> {
  private final Provider<DisplayMetrics> displayMetricsProvider;

  public FlingAnimationUtils_Builder_Factory(Provider<DisplayMetrics> displayMetricsProvider) {
    this.displayMetricsProvider = displayMetricsProvider;
  }

  @Override
  public FlingAnimationUtils.Builder get() {
    return newInstance(displayMetricsProvider.get());
  }

  public static FlingAnimationUtils_Builder_Factory create(
      Provider<DisplayMetrics> displayMetricsProvider) {
    return new FlingAnimationUtils_Builder_Factory(displayMetricsProvider);
  }

  public static FlingAnimationUtils.Builder newInstance(DisplayMetrics displayMetrics) {
    return new FlingAnimationUtils.Builder(displayMetrics);
  }
}

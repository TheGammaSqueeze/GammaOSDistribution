package com.android.systemui.statusbar.phone;

import android.view.WindowManager;
import com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider;
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
public final class StatusBarMoveFromCenterAnimationController_Factory implements Factory<StatusBarMoveFromCenterAnimationController> {
  private final Provider<ScopedUnfoldTransitionProgressProvider> progressProvider;

  private final Provider<WindowManager> windowManagerProvider;

  public StatusBarMoveFromCenterAnimationController_Factory(
      Provider<ScopedUnfoldTransitionProgressProvider> progressProvider,
      Provider<WindowManager> windowManagerProvider) {
    this.progressProvider = progressProvider;
    this.windowManagerProvider = windowManagerProvider;
  }

  @Override
  public StatusBarMoveFromCenterAnimationController get() {
    return newInstance(progressProvider.get(), windowManagerProvider.get());
  }

  public static StatusBarMoveFromCenterAnimationController_Factory create(
      Provider<ScopedUnfoldTransitionProgressProvider> progressProvider,
      Provider<WindowManager> windowManagerProvider) {
    return new StatusBarMoveFromCenterAnimationController_Factory(progressProvider, windowManagerProvider);
  }

  public static StatusBarMoveFromCenterAnimationController newInstance(
      ScopedUnfoldTransitionProgressProvider progressProvider, WindowManager windowManager) {
    return new StatusBarMoveFromCenterAnimationController(progressProvider, windowManager);
  }
}

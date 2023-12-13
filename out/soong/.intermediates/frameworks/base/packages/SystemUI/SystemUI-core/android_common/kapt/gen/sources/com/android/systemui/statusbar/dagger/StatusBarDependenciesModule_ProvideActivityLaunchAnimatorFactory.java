package com.android.systemui.statusbar.dagger;

import com.android.systemui.animation.ActivityLaunchAnimator;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class StatusBarDependenciesModule_ProvideActivityLaunchAnimatorFactory implements Factory<ActivityLaunchAnimator> {
  @Override
  public ActivityLaunchAnimator get() {
    return provideActivityLaunchAnimator();
  }

  public static StatusBarDependenciesModule_ProvideActivityLaunchAnimatorFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ActivityLaunchAnimator provideActivityLaunchAnimator() {
    return Preconditions.checkNotNullFromProvides(StatusBarDependenciesModule.provideActivityLaunchAnimator());
  }

  private static final class InstanceHolder {
    private static final StatusBarDependenciesModule_ProvideActivityLaunchAnimatorFactory INSTANCE = new StatusBarDependenciesModule_ProvideActivityLaunchAnimatorFactory();
  }
}

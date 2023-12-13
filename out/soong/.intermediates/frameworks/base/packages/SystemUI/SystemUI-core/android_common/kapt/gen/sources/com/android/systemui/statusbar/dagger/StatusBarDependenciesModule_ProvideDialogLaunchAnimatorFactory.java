package com.android.systemui.statusbar.dagger;

import android.service.dreams.IDreamManager;
import com.android.systemui.animation.DialogLaunchAnimator;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class StatusBarDependenciesModule_ProvideDialogLaunchAnimatorFactory implements Factory<DialogLaunchAnimator> {
  private final Provider<IDreamManager> dreamManagerProvider;

  public StatusBarDependenciesModule_ProvideDialogLaunchAnimatorFactory(
      Provider<IDreamManager> dreamManagerProvider) {
    this.dreamManagerProvider = dreamManagerProvider;
  }

  @Override
  public DialogLaunchAnimator get() {
    return provideDialogLaunchAnimator(dreamManagerProvider.get());
  }

  public static StatusBarDependenciesModule_ProvideDialogLaunchAnimatorFactory create(
      Provider<IDreamManager> dreamManagerProvider) {
    return new StatusBarDependenciesModule_ProvideDialogLaunchAnimatorFactory(dreamManagerProvider);
  }

  public static DialogLaunchAnimator provideDialogLaunchAnimator(IDreamManager dreamManager) {
    return Preconditions.checkNotNullFromProvides(StatusBarDependenciesModule.provideDialogLaunchAnimator(dreamManager));
  }
}

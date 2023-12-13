package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class VisualStabilityCoordinator_Factory implements Factory<VisualStabilityCoordinator> {
  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  public VisualStabilityCoordinator_Factory(Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<DelayableExecutor> delayableExecutorProvider) {
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
  }

  @Override
  public VisualStabilityCoordinator get() {
    return newInstance(headsUpManagerProvider.get(), wakefulnessLifecycleProvider.get(), statusBarStateControllerProvider.get(), delayableExecutorProvider.get());
  }

  public static VisualStabilityCoordinator_Factory create(
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<DelayableExecutor> delayableExecutorProvider) {
    return new VisualStabilityCoordinator_Factory(headsUpManagerProvider, wakefulnessLifecycleProvider, statusBarStateControllerProvider, delayableExecutorProvider);
  }

  public static VisualStabilityCoordinator newInstance(HeadsUpManager headsUpManager,
      WakefulnessLifecycle wakefulnessLifecycle, StatusBarStateController statusBarStateController,
      DelayableExecutor delayableExecutor) {
    return new VisualStabilityCoordinator(headsUpManager, wakefulnessLifecycle, statusBarStateController, delayableExecutor);
  }
}

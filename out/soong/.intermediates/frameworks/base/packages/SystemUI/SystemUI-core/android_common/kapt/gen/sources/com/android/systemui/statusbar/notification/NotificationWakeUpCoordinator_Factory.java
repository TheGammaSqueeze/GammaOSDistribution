package com.android.systemui.statusbar.notification;

import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
import com.android.systemui.statusbar.policy.HeadsUpManager;
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
public final class NotificationWakeUpCoordinator_Factory implements Factory<NotificationWakeUpCoordinator> {
  private final Provider<HeadsUpManager> mHeadsUpManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  public NotificationWakeUpCoordinator_Factory(Provider<HeadsUpManager> mHeadsUpManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    this.mHeadsUpManagerProvider = mHeadsUpManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
  }

  @Override
  public NotificationWakeUpCoordinator get() {
    return newInstance(mHeadsUpManagerProvider.get(), statusBarStateControllerProvider.get(), bypassControllerProvider.get(), dozeParametersProvider.get(), unlockedScreenOffAnimationControllerProvider.get());
  }

  public static NotificationWakeUpCoordinator_Factory create(
      Provider<HeadsUpManager> mHeadsUpManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    return new NotificationWakeUpCoordinator_Factory(mHeadsUpManagerProvider, statusBarStateControllerProvider, bypassControllerProvider, dozeParametersProvider, unlockedScreenOffAnimationControllerProvider);
  }

  public static NotificationWakeUpCoordinator newInstance(HeadsUpManager mHeadsUpManager,
      StatusBarStateController statusBarStateController, KeyguardBypassController bypassController,
      DozeParameters dozeParameters,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController) {
    return new NotificationWakeUpCoordinator(mHeadsUpManager, statusBarStateController, bypassController, dozeParameters, unlockedScreenOffAnimationController);
  }
}

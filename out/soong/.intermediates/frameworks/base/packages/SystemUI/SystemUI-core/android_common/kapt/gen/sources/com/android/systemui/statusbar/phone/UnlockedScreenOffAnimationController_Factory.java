package com.android.systemui.statusbar.phone;

import android.content.Context;
import android.os.Handler;
import android.os.PowerManager;
import com.android.systemui.keyguard.KeyguardViewMediator;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.statusbar.StatusBarStateControllerImpl;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.settings.GlobalSettings;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class UnlockedScreenOffAnimationController_Factory implements Factory<UnlockedScreenOffAnimationController> {
  private final Provider<Context> contextProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<StatusBarStateControllerImpl> statusBarStateControllerImplProvider;

  private final Provider<KeyguardViewMediator> keyguardViewMediatorLazyProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<GlobalSettings> globalSettingsProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<Handler> handlerProvider;

  public UnlockedScreenOffAnimationController_Factory(Provider<Context> contextProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<StatusBarStateControllerImpl> statusBarStateControllerImplProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorLazyProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<GlobalSettings> globalSettingsProvider, Provider<PowerManager> powerManagerProvider,
      Provider<Handler> handlerProvider) {
    this.contextProvider = contextProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.statusBarStateControllerImplProvider = statusBarStateControllerImplProvider;
    this.keyguardViewMediatorLazyProvider = keyguardViewMediatorLazyProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.globalSettingsProvider = globalSettingsProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.handlerProvider = handlerProvider;
  }

  @Override
  public UnlockedScreenOffAnimationController get() {
    return newInstance(contextProvider.get(), wakefulnessLifecycleProvider.get(), statusBarStateControllerImplProvider.get(), DoubleCheck.lazy(keyguardViewMediatorLazyProvider), keyguardStateControllerProvider.get(), DoubleCheck.lazy(dozeParametersProvider), globalSettingsProvider.get(), powerManagerProvider.get(), handlerProvider.get());
  }

  public static UnlockedScreenOffAnimationController_Factory create(
      Provider<Context> contextProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<StatusBarStateControllerImpl> statusBarStateControllerImplProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorLazyProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<GlobalSettings> globalSettingsProvider, Provider<PowerManager> powerManagerProvider,
      Provider<Handler> handlerProvider) {
    return new UnlockedScreenOffAnimationController_Factory(contextProvider, wakefulnessLifecycleProvider, statusBarStateControllerImplProvider, keyguardViewMediatorLazyProvider, keyguardStateControllerProvider, dozeParametersProvider, globalSettingsProvider, powerManagerProvider, handlerProvider);
  }

  public static UnlockedScreenOffAnimationController newInstance(Context context,
      WakefulnessLifecycle wakefulnessLifecycle,
      StatusBarStateControllerImpl statusBarStateControllerImpl,
      Lazy<KeyguardViewMediator> keyguardViewMediatorLazy,
      KeyguardStateController keyguardStateController, Lazy<DozeParameters> dozeParameters,
      GlobalSettings globalSettings, PowerManager powerManager, Handler handler) {
    return new UnlockedScreenOffAnimationController(context, wakefulnessLifecycle, statusBarStateControllerImpl, keyguardViewMediatorLazy, keyguardStateController, dozeParameters, globalSettings, powerManager, handler);
  }
}

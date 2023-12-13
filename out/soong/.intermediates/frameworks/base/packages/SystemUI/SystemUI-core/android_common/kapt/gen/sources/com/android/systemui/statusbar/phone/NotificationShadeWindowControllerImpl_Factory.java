package com.android.systemui.statusbar.phone;

import android.app.IActivityManager;
import android.content.Context;
import android.view.WindowManager;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.colorextraction.SysuiColorExtractor;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.keyguard.KeyguardViewMediator;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class NotificationShadeWindowControllerImpl_Factory implements Factory<NotificationShadeWindowControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<IActivityManager> activityManagerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<KeyguardViewMediator> keyguardViewMediatorProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<SysuiColorExtractor> colorExtractorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  private final Provider<AuthController> authControllerProvider;

  public NotificationShadeWindowControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<IActivityManager> activityManagerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<AuthController> authControllerProvider) {
    this.contextProvider = contextProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.activityManagerProvider = activityManagerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.keyguardViewMediatorProvider = keyguardViewMediatorProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.colorExtractorProvider = colorExtractorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
    this.authControllerProvider = authControllerProvider;
  }

  @Override
  public NotificationShadeWindowControllerImpl get() {
    return newInstance(contextProvider.get(), windowManagerProvider.get(), activityManagerProvider.get(), dozeParametersProvider.get(), statusBarStateControllerProvider.get(), configurationControllerProvider.get(), keyguardViewMediatorProvider.get(), keyguardBypassControllerProvider.get(), colorExtractorProvider.get(), dumpManagerProvider.get(), keyguardStateControllerProvider.get(), unlockedScreenOffAnimationControllerProvider.get(), authControllerProvider.get());
  }

  public static NotificationShadeWindowControllerImpl_Factory create(
      Provider<Context> contextProvider, Provider<WindowManager> windowManagerProvider,
      Provider<IActivityManager> activityManagerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<AuthController> authControllerProvider) {
    return new NotificationShadeWindowControllerImpl_Factory(contextProvider, windowManagerProvider, activityManagerProvider, dozeParametersProvider, statusBarStateControllerProvider, configurationControllerProvider, keyguardViewMediatorProvider, keyguardBypassControllerProvider, colorExtractorProvider, dumpManagerProvider, keyguardStateControllerProvider, unlockedScreenOffAnimationControllerProvider, authControllerProvider);
  }

  public static NotificationShadeWindowControllerImpl newInstance(Context context,
      WindowManager windowManager, IActivityManager activityManager, DozeParameters dozeParameters,
      StatusBarStateController statusBarStateController,
      ConfigurationController configurationController, KeyguardViewMediator keyguardViewMediator,
      KeyguardBypassController keyguardBypassController, SysuiColorExtractor colorExtractor,
      DumpManager dumpManager, KeyguardStateController keyguardStateController,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController,
      AuthController authController) {
    return new NotificationShadeWindowControllerImpl(context, windowManager, activityManager, dozeParameters, statusBarStateController, configurationController, keyguardViewMediator, keyguardBypassController, colorExtractor, dumpManager, keyguardStateController, unlockedScreenOffAnimationController, authController);
  }
}

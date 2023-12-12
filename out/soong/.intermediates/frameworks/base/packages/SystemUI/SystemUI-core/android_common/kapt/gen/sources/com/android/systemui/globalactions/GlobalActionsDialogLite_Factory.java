package com.android.systemui.globalactions;

import android.app.IActivityManager;
import android.app.admin.DevicePolicyManager;
import android.app.trust.TrustManager;
import android.content.Context;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.media.AudioManager;
import android.os.Handler;
import android.os.UserManager;
import android.os.Vibrator;
import android.service.dreams.IDreamManager;
import android.telecom.TelecomManager;
import android.view.IWindowManager;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.statusbar.IStatusBarService;
import com.android.internal.widget.LockPatternUtils;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.colorextraction.SysuiColorExtractor;
import com.android.systemui.controls.dagger.ControlsComponent;
import com.android.systemui.model.SysUiState;
import com.android.systemui.plugins.GlobalActions;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.phone.SystemUIDialogManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.RingerModeTracker;
import com.android.systemui.util.settings.GlobalSettings;
import com.android.systemui.util.settings.SecureSettings;
import dagger.internal.Factory;
import java.util.Optional;
import java.util.concurrent.Executor;
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
public final class GlobalActionsDialogLite_Factory implements Factory<GlobalActionsDialogLite> {
  private final Provider<Context> contextProvider;

  private final Provider<GlobalActions.GlobalActionsManager> windowManagerFuncsProvider;

  private final Provider<AudioManager> audioManagerProvider;

  private final Provider<IDreamManager> iDreamManagerProvider;

  private final Provider<DevicePolicyManager> devicePolicyManagerProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<GlobalSettings> globalSettingsProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<Vibrator> vibratorProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<TrustManager> trustManagerProvider;

  private final Provider<IActivityManager> iActivityManagerProvider;

  private final Provider<TelecomManager> telecomManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<SysuiColorExtractor> colorExtractorProvider;

  private final Provider<IStatusBarService> statusBarServiceProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<IWindowManager> iWindowManagerProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<RingerModeTracker> ringerModeTrackerProvider;

  private final Provider<SysUiState> sysUiStateProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<PackageManager> packageManagerProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider;

  private final Provider<SystemUIDialogManager> dialogManagerProvider;

  private final Provider<ControlsComponent> controlsComponentProvider;

  public GlobalActionsDialogLite_Factory(Provider<Context> contextProvider,
      Provider<GlobalActions.GlobalActionsManager> windowManagerFuncsProvider,
      Provider<AudioManager> audioManagerProvider, Provider<IDreamManager> iDreamManagerProvider,
      Provider<DevicePolicyManager> devicePolicyManagerProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<GlobalSettings> globalSettingsProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<Vibrator> vibratorProvider,
      Provider<Resources> resourcesProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<UserManager> userManagerProvider, Provider<TrustManager> trustManagerProvider,
      Provider<IActivityManager> iActivityManagerProvider,
      Provider<TelecomManager> telecomManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<IWindowManager> iWindowManagerProvider,
      Provider<Executor> backgroundExecutorProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<RingerModeTracker> ringerModeTrackerProvider,
      Provider<SysUiState> sysUiStateProvider, Provider<Handler> handlerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<Optional<StatusBar>> statusBarOptionalProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider,
      Provider<SystemUIDialogManager> dialogManagerProvider,
      Provider<ControlsComponent> controlsComponentProvider) {
    this.contextProvider = contextProvider;
    this.windowManagerFuncsProvider = windowManagerFuncsProvider;
    this.audioManagerProvider = audioManagerProvider;
    this.iDreamManagerProvider = iDreamManagerProvider;
    this.devicePolicyManagerProvider = devicePolicyManagerProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.globalSettingsProvider = globalSettingsProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.vibratorProvider = vibratorProvider;
    this.resourcesProvider = resourcesProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.userManagerProvider = userManagerProvider;
    this.trustManagerProvider = trustManagerProvider;
    this.iActivityManagerProvider = iActivityManagerProvider;
    this.telecomManagerProvider = telecomManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.colorExtractorProvider = colorExtractorProvider;
    this.statusBarServiceProvider = statusBarServiceProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.iWindowManagerProvider = iWindowManagerProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.ringerModeTrackerProvider = ringerModeTrackerProvider;
    this.sysUiStateProvider = sysUiStateProvider;
    this.handlerProvider = handlerProvider;
    this.packageManagerProvider = packageManagerProvider;
    this.statusBarOptionalProvider = statusBarOptionalProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.dialogLaunchAnimatorProvider = dialogLaunchAnimatorProvider;
    this.dialogManagerProvider = dialogManagerProvider;
    this.controlsComponentProvider = controlsComponentProvider;
  }

  @Override
  public GlobalActionsDialogLite get() {
    return newInstance(contextProvider.get(), windowManagerFuncsProvider.get(), audioManagerProvider.get(), iDreamManagerProvider.get(), devicePolicyManagerProvider.get(), lockPatternUtilsProvider.get(), broadcastDispatcherProvider.get(), globalSettingsProvider.get(), secureSettingsProvider.get(), vibratorProvider.get(), resourcesProvider.get(), configurationControllerProvider.get(), keyguardStateControllerProvider.get(), userManagerProvider.get(), trustManagerProvider.get(), iActivityManagerProvider.get(), telecomManagerProvider.get(), metricsLoggerProvider.get(), colorExtractorProvider.get(), statusBarServiceProvider.get(), notificationShadeWindowControllerProvider.get(), iWindowManagerProvider.get(), backgroundExecutorProvider.get(), uiEventLoggerProvider.get(), ringerModeTrackerProvider.get(), sysUiStateProvider.get(), handlerProvider.get(), packageManagerProvider.get(), statusBarOptionalProvider.get(), keyguardUpdateMonitorProvider.get(), dialogLaunchAnimatorProvider.get(), dialogManagerProvider.get(), controlsComponentProvider.get());
  }

  public static GlobalActionsDialogLite_Factory create(Provider<Context> contextProvider,
      Provider<GlobalActions.GlobalActionsManager> windowManagerFuncsProvider,
      Provider<AudioManager> audioManagerProvider, Provider<IDreamManager> iDreamManagerProvider,
      Provider<DevicePolicyManager> devicePolicyManagerProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<GlobalSettings> globalSettingsProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<Vibrator> vibratorProvider,
      Provider<Resources> resourcesProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<UserManager> userManagerProvider, Provider<TrustManager> trustManagerProvider,
      Provider<IActivityManager> iActivityManagerProvider,
      Provider<TelecomManager> telecomManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<IWindowManager> iWindowManagerProvider,
      Provider<Executor> backgroundExecutorProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<RingerModeTracker> ringerModeTrackerProvider,
      Provider<SysUiState> sysUiStateProvider, Provider<Handler> handlerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<Optional<StatusBar>> statusBarOptionalProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider,
      Provider<SystemUIDialogManager> dialogManagerProvider,
      Provider<ControlsComponent> controlsComponentProvider) {
    return new GlobalActionsDialogLite_Factory(contextProvider, windowManagerFuncsProvider, audioManagerProvider, iDreamManagerProvider, devicePolicyManagerProvider, lockPatternUtilsProvider, broadcastDispatcherProvider, globalSettingsProvider, secureSettingsProvider, vibratorProvider, resourcesProvider, configurationControllerProvider, keyguardStateControllerProvider, userManagerProvider, trustManagerProvider, iActivityManagerProvider, telecomManagerProvider, metricsLoggerProvider, colorExtractorProvider, statusBarServiceProvider, notificationShadeWindowControllerProvider, iWindowManagerProvider, backgroundExecutorProvider, uiEventLoggerProvider, ringerModeTrackerProvider, sysUiStateProvider, handlerProvider, packageManagerProvider, statusBarOptionalProvider, keyguardUpdateMonitorProvider, dialogLaunchAnimatorProvider, dialogManagerProvider, controlsComponentProvider);
  }

  public static GlobalActionsDialogLite newInstance(Context context,
      GlobalActions.GlobalActionsManager windowManagerFuncs, AudioManager audioManager,
      IDreamManager iDreamManager, DevicePolicyManager devicePolicyManager,
      LockPatternUtils lockPatternUtils, BroadcastDispatcher broadcastDispatcher,
      GlobalSettings globalSettings, SecureSettings secureSettings, Vibrator vibrator,
      Resources resources, ConfigurationController configurationController,
      KeyguardStateController keyguardStateController, UserManager userManager,
      TrustManager trustManager, IActivityManager iActivityManager, TelecomManager telecomManager,
      MetricsLogger metricsLogger, SysuiColorExtractor colorExtractor,
      IStatusBarService statusBarService,
      NotificationShadeWindowController notificationShadeWindowController,
      IWindowManager iWindowManager, Executor backgroundExecutor, UiEventLogger uiEventLogger,
      RingerModeTracker ringerModeTracker, SysUiState sysUiState, Handler handler,
      PackageManager packageManager, Optional<StatusBar> statusBarOptional,
      KeyguardUpdateMonitor keyguardUpdateMonitor, DialogLaunchAnimator dialogLaunchAnimator,
      SystemUIDialogManager dialogManager, ControlsComponent controlsComponent) {
    return new GlobalActionsDialogLite(context, windowManagerFuncs, audioManager, iDreamManager, devicePolicyManager, lockPatternUtils, broadcastDispatcher, globalSettings, secureSettings, vibrator, resources, configurationController, keyguardStateController, userManager, trustManager, iActivityManager, telecomManager, metricsLogger, colorExtractor, statusBarService, notificationShadeWindowController, iWindowManager, backgroundExecutor, uiEventLogger, ringerModeTracker, sysUiState, handler, packageManager, statusBarOptional, keyguardUpdateMonitor, dialogLaunchAnimator, dialogManager, controlsComponent);
  }
}

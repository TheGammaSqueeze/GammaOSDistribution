package com.android.systemui.statusbar.phone;

import android.app.AlarmManager;
import android.os.Handler;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dock.DockManager;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionStateManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.wakelock.DelayedWakeLock;
import dagger.internal.Factory;
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
public final class ScrimController_Factory implements Factory<ScrimController> {
  private final Provider<LightBarController> lightBarControllerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<AlarmManager> alarmManagerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<DelayedWakeLock.Builder> delayedWakeLockBuilderProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<DockManager> dockManagerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  private final Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider;

  public ScrimController_Factory(Provider<LightBarController> lightBarControllerProvider,
      Provider<DozeParameters> dozeParametersProvider, Provider<AlarmManager> alarmManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DelayedWakeLock.Builder> delayedWakeLockBuilderProvider,
      Provider<Handler> handlerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DockManager> dockManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<Executor> mainExecutorProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider) {
    this.lightBarControllerProvider = lightBarControllerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.alarmManagerProvider = alarmManagerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.delayedWakeLockBuilderProvider = delayedWakeLockBuilderProvider;
    this.handlerProvider = handlerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.dockManagerProvider = dockManagerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
    this.panelExpansionStateManagerProvider = panelExpansionStateManagerProvider;
  }

  @Override
  public ScrimController get() {
    return newInstance(lightBarControllerProvider.get(), dozeParametersProvider.get(), alarmManagerProvider.get(), keyguardStateControllerProvider.get(), delayedWakeLockBuilderProvider.get(), handlerProvider.get(), keyguardUpdateMonitorProvider.get(), dockManagerProvider.get(), configurationControllerProvider.get(), mainExecutorProvider.get(), unlockedScreenOffAnimationControllerProvider.get(), panelExpansionStateManagerProvider.get());
  }

  public static ScrimController_Factory create(
      Provider<LightBarController> lightBarControllerProvider,
      Provider<DozeParameters> dozeParametersProvider, Provider<AlarmManager> alarmManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DelayedWakeLock.Builder> delayedWakeLockBuilderProvider,
      Provider<Handler> handlerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DockManager> dockManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<Executor> mainExecutorProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider) {
    return new ScrimController_Factory(lightBarControllerProvider, dozeParametersProvider, alarmManagerProvider, keyguardStateControllerProvider, delayedWakeLockBuilderProvider, handlerProvider, keyguardUpdateMonitorProvider, dockManagerProvider, configurationControllerProvider, mainExecutorProvider, unlockedScreenOffAnimationControllerProvider, panelExpansionStateManagerProvider);
  }

  public static ScrimController newInstance(LightBarController lightBarController,
      DozeParameters dozeParameters, AlarmManager alarmManager,
      KeyguardStateController keyguardStateController,
      DelayedWakeLock.Builder delayedWakeLockBuilder, Handler handler,
      KeyguardUpdateMonitor keyguardUpdateMonitor, DockManager dockManager,
      ConfigurationController configurationController, Executor mainExecutor,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController,
      PanelExpansionStateManager panelExpansionStateManager) {
    return new ScrimController(lightBarController, dozeParameters, alarmManager, keyguardStateController, delayedWakeLockBuilder, handler, keyguardUpdateMonitor, dockManager, configurationController, mainExecutor, unlockedScreenOffAnimationController, panelExpansionStateManager);
  }
}

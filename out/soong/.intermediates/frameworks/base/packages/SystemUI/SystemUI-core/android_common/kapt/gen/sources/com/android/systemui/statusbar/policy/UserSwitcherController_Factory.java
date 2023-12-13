package com.android.systemui.statusbar.policy;

import android.app.IActivityManager;
import android.app.IActivityTaskManager;
import android.app.admin.DevicePolicyManager;
import android.content.Context;
import android.os.Handler;
import android.os.UserManager;
import com.android.internal.jank.InteractionJankMonitor;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.util.LatencyTracker;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.telephony.TelephonyListenerManager;
import com.android.systemui.util.settings.SecureSettings;
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
public final class UserSwitcherController_Factory implements Factory<UserSwitcherController> {
  private final Provider<Context> contextProvider;

  private final Provider<IActivityManager> activityManagerProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<DevicePolicyManager> devicePolicyManagerProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<TelephonyListenerManager> telephonyListenerManagerProvider;

  private final Provider<IActivityTaskManager> activityTaskManagerProvider;

  private final Provider<UserSwitcherController.UserDetailAdapter> userDetailAdapterProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<InteractionJankMonitor> interactionJankMonitorProvider;

  private final Provider<LatencyTracker> latencyTrackerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider;

  public UserSwitcherController_Factory(Provider<Context> contextProvider,
      Provider<IActivityManager> activityManagerProvider, Provider<UserManager> userManagerProvider,
      Provider<UserTracker> userTrackerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<DevicePolicyManager> devicePolicyManagerProvider, Provider<Handler> handlerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<TelephonyListenerManager> telephonyListenerManagerProvider,
      Provider<IActivityTaskManager> activityTaskManagerProvider,
      Provider<UserSwitcherController.UserDetailAdapter> userDetailAdapterProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<Executor> bgExecutorProvider,
      Provider<InteractionJankMonitor> interactionJankMonitorProvider,
      Provider<LatencyTracker> latencyTrackerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    this.contextProvider = contextProvider;
    this.activityManagerProvider = activityManagerProvider;
    this.userManagerProvider = userManagerProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.devicePolicyManagerProvider = devicePolicyManagerProvider;
    this.handlerProvider = handlerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.telephonyListenerManagerProvider = telephonyListenerManagerProvider;
    this.activityTaskManagerProvider = activityTaskManagerProvider;
    this.userDetailAdapterProvider = userDetailAdapterProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.interactionJankMonitorProvider = interactionJankMonitorProvider;
    this.latencyTrackerProvider = latencyTrackerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.dialogLaunchAnimatorProvider = dialogLaunchAnimatorProvider;
  }

  @Override
  public UserSwitcherController get() {
    return newInstance(contextProvider.get(), activityManagerProvider.get(), userManagerProvider.get(), userTrackerProvider.get(), keyguardStateControllerProvider.get(), deviceProvisionedControllerProvider.get(), devicePolicyManagerProvider.get(), handlerProvider.get(), activityStarterProvider.get(), broadcastDispatcherProvider.get(), uiEventLoggerProvider.get(), falsingManagerProvider.get(), telephonyListenerManagerProvider.get(), activityTaskManagerProvider.get(), userDetailAdapterProvider.get(), secureSettingsProvider.get(), bgExecutorProvider.get(), interactionJankMonitorProvider.get(), latencyTrackerProvider.get(), dumpManagerProvider.get(), dialogLaunchAnimatorProvider.get());
  }

  public static UserSwitcherController_Factory create(Provider<Context> contextProvider,
      Provider<IActivityManager> activityManagerProvider, Provider<UserManager> userManagerProvider,
      Provider<UserTracker> userTrackerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<DevicePolicyManager> devicePolicyManagerProvider, Provider<Handler> handlerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<TelephonyListenerManager> telephonyListenerManagerProvider,
      Provider<IActivityTaskManager> activityTaskManagerProvider,
      Provider<UserSwitcherController.UserDetailAdapter> userDetailAdapterProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<Executor> bgExecutorProvider,
      Provider<InteractionJankMonitor> interactionJankMonitorProvider,
      Provider<LatencyTracker> latencyTrackerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    return new UserSwitcherController_Factory(contextProvider, activityManagerProvider, userManagerProvider, userTrackerProvider, keyguardStateControllerProvider, deviceProvisionedControllerProvider, devicePolicyManagerProvider, handlerProvider, activityStarterProvider, broadcastDispatcherProvider, uiEventLoggerProvider, falsingManagerProvider, telephonyListenerManagerProvider, activityTaskManagerProvider, userDetailAdapterProvider, secureSettingsProvider, bgExecutorProvider, interactionJankMonitorProvider, latencyTrackerProvider, dumpManagerProvider, dialogLaunchAnimatorProvider);
  }

  public static UserSwitcherController newInstance(Context context,
      IActivityManager activityManager, UserManager userManager, UserTracker userTracker,
      KeyguardStateController keyguardStateController,
      DeviceProvisionedController deviceProvisionedController,
      DevicePolicyManager devicePolicyManager, Handler handler, ActivityStarter activityStarter,
      BroadcastDispatcher broadcastDispatcher, UiEventLogger uiEventLogger,
      FalsingManager falsingManager, TelephonyListenerManager telephonyListenerManager,
      IActivityTaskManager activityTaskManager,
      UserSwitcherController.UserDetailAdapter userDetailAdapter, SecureSettings secureSettings,
      Executor bgExecutor, InteractionJankMonitor interactionJankMonitor,
      LatencyTracker latencyTracker, DumpManager dumpManager,
      DialogLaunchAnimator dialogLaunchAnimator) {
    return new UserSwitcherController(context, activityManager, userManager, userTracker, keyguardStateController, deviceProvisionedController, devicePolicyManager, handler, activityStarter, broadcastDispatcher, uiEventLogger, falsingManager, telephonyListenerManager, activityTaskManager, userDetailAdapter, secureSettings, bgExecutor, interactionJankMonitor, latencyTracker, dumpManager, dialogLaunchAnimator);
  }
}

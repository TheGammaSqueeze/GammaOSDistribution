package com.android.systemui.qs.tiles.dialog;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.wifi.WifiManager;
import android.os.Handler;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import android.view.WindowManager;
import com.android.internal.logging.UiEventLogger;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.connectivity.AccessPointController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.statusbar.policy.LocationController;
import com.android.systemui.toast.ToastFactory;
import com.android.systemui.util.CarrierConfigTracker;
import com.android.systemui.util.settings.GlobalSettings;
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
public final class InternetDialogController_Factory implements Factory<InternetDialogController> {
  private final Provider<Context> contextProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<ActivityStarter> starterProvider;

  private final Provider<AccessPointController> accessPointControllerProvider;

  private final Provider<SubscriptionManager> subscriptionManagerProvider;

  private final Provider<TelephonyManager> telephonyManagerProvider;

  private final Provider<WifiManager> wifiManagerProvider;

  private final Provider<ConnectivityManager> connectivityManagerProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<GlobalSettings> globalSettingsProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<ToastFactory> toastFactoryProvider;

  private final Provider<Handler> workerHandlerProvider;

  private final Provider<CarrierConfigTracker> carrierConfigTrackerProvider;

  private final Provider<LocationController> locationControllerProvider;

  private final Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider;

  public InternetDialogController_Factory(Provider<Context> contextProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<ActivityStarter> starterProvider,
      Provider<AccessPointController> accessPointControllerProvider,
      Provider<SubscriptionManager> subscriptionManagerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<WifiManager> wifiManagerProvider,
      Provider<ConnectivityManager> connectivityManagerProvider, Provider<Handler> handlerProvider,
      Provider<Executor> mainExecutorProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<GlobalSettings> globalSettingsProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<WindowManager> windowManagerProvider, Provider<ToastFactory> toastFactoryProvider,
      Provider<Handler> workerHandlerProvider,
      Provider<CarrierConfigTracker> carrierConfigTrackerProvider,
      Provider<LocationController> locationControllerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    this.contextProvider = contextProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.starterProvider = starterProvider;
    this.accessPointControllerProvider = accessPointControllerProvider;
    this.subscriptionManagerProvider = subscriptionManagerProvider;
    this.telephonyManagerProvider = telephonyManagerProvider;
    this.wifiManagerProvider = wifiManagerProvider;
    this.connectivityManagerProvider = connectivityManagerProvider;
    this.handlerProvider = handlerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.globalSettingsProvider = globalSettingsProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.toastFactoryProvider = toastFactoryProvider;
    this.workerHandlerProvider = workerHandlerProvider;
    this.carrierConfigTrackerProvider = carrierConfigTrackerProvider;
    this.locationControllerProvider = locationControllerProvider;
    this.dialogLaunchAnimatorProvider = dialogLaunchAnimatorProvider;
  }

  @Override
  public InternetDialogController get() {
    return newInstance(contextProvider.get(), uiEventLoggerProvider.get(), starterProvider.get(), accessPointControllerProvider.get(), subscriptionManagerProvider.get(), telephonyManagerProvider.get(), wifiManagerProvider.get(), connectivityManagerProvider.get(), handlerProvider.get(), mainExecutorProvider.get(), broadcastDispatcherProvider.get(), keyguardUpdateMonitorProvider.get(), globalSettingsProvider.get(), keyguardStateControllerProvider.get(), windowManagerProvider.get(), toastFactoryProvider.get(), workerHandlerProvider.get(), carrierConfigTrackerProvider.get(), locationControllerProvider.get(), dialogLaunchAnimatorProvider.get());
  }

  public static InternetDialogController_Factory create(Provider<Context> contextProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<ActivityStarter> starterProvider,
      Provider<AccessPointController> accessPointControllerProvider,
      Provider<SubscriptionManager> subscriptionManagerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<WifiManager> wifiManagerProvider,
      Provider<ConnectivityManager> connectivityManagerProvider, Provider<Handler> handlerProvider,
      Provider<Executor> mainExecutorProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<GlobalSettings> globalSettingsProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<WindowManager> windowManagerProvider, Provider<ToastFactory> toastFactoryProvider,
      Provider<Handler> workerHandlerProvider,
      Provider<CarrierConfigTracker> carrierConfigTrackerProvider,
      Provider<LocationController> locationControllerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    return new InternetDialogController_Factory(contextProvider, uiEventLoggerProvider, starterProvider, accessPointControllerProvider, subscriptionManagerProvider, telephonyManagerProvider, wifiManagerProvider, connectivityManagerProvider, handlerProvider, mainExecutorProvider, broadcastDispatcherProvider, keyguardUpdateMonitorProvider, globalSettingsProvider, keyguardStateControllerProvider, windowManagerProvider, toastFactoryProvider, workerHandlerProvider, carrierConfigTrackerProvider, locationControllerProvider, dialogLaunchAnimatorProvider);
  }

  public static InternetDialogController newInstance(Context context, UiEventLogger uiEventLogger,
      ActivityStarter starter, AccessPointController accessPointController,
      SubscriptionManager subscriptionManager, TelephonyManager telephonyManager,
      WifiManager wifiManager, ConnectivityManager connectivityManager, Handler handler,
      Executor mainExecutor, BroadcastDispatcher broadcastDispatcher,
      KeyguardUpdateMonitor keyguardUpdateMonitor, GlobalSettings globalSettings,
      KeyguardStateController keyguardStateController, WindowManager windowManager,
      ToastFactory toastFactory, Handler workerHandler, CarrierConfigTracker carrierConfigTracker,
      LocationController locationController, DialogLaunchAnimator dialogLaunchAnimator) {
    return new InternetDialogController(context, uiEventLogger, starter, accessPointController, subscriptionManager, telephonyManager, wifiManager, connectivityManager, handler, mainExecutor, broadcastDispatcher, keyguardUpdateMonitor, globalSettings, keyguardStateController, windowManager, toastFactory, workerHandler, carrierConfigTracker, locationController, dialogLaunchAnimator);
  }
}

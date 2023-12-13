package com.android.systemui.statusbar.connectivity;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkScoreManager;
import android.net.wifi.WifiManager;
import android.os.Handler;
import android.os.Looper;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.qs.tiles.dialog.InternetDialogFactory;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.telephony.TelephonyListenerManager;
import com.android.systemui.util.CarrierConfigTracker;
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
public final class NetworkControllerImpl_Factory implements Factory<NetworkControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<Looper> bgLooperProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<SubscriptionManager> subscriptionManagerProvider;

  private final Provider<CallbackHandler> callbackHandlerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<ConnectivityManager> connectivityManagerProvider;

  private final Provider<TelephonyManager> telephonyManagerProvider;

  private final Provider<TelephonyListenerManager> telephonyListenerManagerProvider;

  private final Provider<WifiManager> wifiManagerProvider;

  private final Provider<NetworkScoreManager> networkScoreManagerProvider;

  private final Provider<AccessPointControllerImpl> accessPointControllerProvider;

  private final Provider<DemoModeController> demoModeControllerProvider;

  private final Provider<CarrierConfigTracker> carrierConfigTrackerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<InternetDialogFactory> internetDialogFactoryProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NetworkControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<Looper> bgLooperProvider, Provider<Executor> bgExecutorProvider,
      Provider<SubscriptionManager> subscriptionManagerProvider,
      Provider<CallbackHandler> callbackHandlerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ConnectivityManager> connectivityManagerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<TelephonyListenerManager> telephonyListenerManagerProvider,
      Provider<WifiManager> wifiManagerProvider,
      Provider<NetworkScoreManager> networkScoreManagerProvider,
      Provider<AccessPointControllerImpl> accessPointControllerProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<CarrierConfigTracker> carrierConfigTrackerProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<Handler> handlerProvider,
      Provider<InternetDialogFactory> internetDialogFactoryProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.bgLooperProvider = bgLooperProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.subscriptionManagerProvider = subscriptionManagerProvider;
    this.callbackHandlerProvider = callbackHandlerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.connectivityManagerProvider = connectivityManagerProvider;
    this.telephonyManagerProvider = telephonyManagerProvider;
    this.telephonyListenerManagerProvider = telephonyListenerManagerProvider;
    this.wifiManagerProvider = wifiManagerProvider;
    this.networkScoreManagerProvider = networkScoreManagerProvider;
    this.accessPointControllerProvider = accessPointControllerProvider;
    this.demoModeControllerProvider = demoModeControllerProvider;
    this.carrierConfigTrackerProvider = carrierConfigTrackerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.handlerProvider = handlerProvider;
    this.internetDialogFactoryProvider = internetDialogFactoryProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NetworkControllerImpl get() {
    return newInstance(contextProvider.get(), bgLooperProvider.get(), bgExecutorProvider.get(), subscriptionManagerProvider.get(), callbackHandlerProvider.get(), deviceProvisionedControllerProvider.get(), broadcastDispatcherProvider.get(), connectivityManagerProvider.get(), telephonyManagerProvider.get(), telephonyListenerManagerProvider.get(), wifiManagerProvider.get(), networkScoreManagerProvider.get(), accessPointControllerProvider.get(), demoModeControllerProvider.get(), carrierConfigTrackerProvider.get(), featureFlagsProvider.get(), handlerProvider.get(), internetDialogFactoryProvider.get(), dumpManagerProvider.get());
  }

  public static NetworkControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<Looper> bgLooperProvider, Provider<Executor> bgExecutorProvider,
      Provider<SubscriptionManager> subscriptionManagerProvider,
      Provider<CallbackHandler> callbackHandlerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ConnectivityManager> connectivityManagerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<TelephonyListenerManager> telephonyListenerManagerProvider,
      Provider<WifiManager> wifiManagerProvider,
      Provider<NetworkScoreManager> networkScoreManagerProvider,
      Provider<AccessPointControllerImpl> accessPointControllerProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<CarrierConfigTracker> carrierConfigTrackerProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<Handler> handlerProvider,
      Provider<InternetDialogFactory> internetDialogFactoryProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new NetworkControllerImpl_Factory(contextProvider, bgLooperProvider, bgExecutorProvider, subscriptionManagerProvider, callbackHandlerProvider, deviceProvisionedControllerProvider, broadcastDispatcherProvider, connectivityManagerProvider, telephonyManagerProvider, telephonyListenerManagerProvider, wifiManagerProvider, networkScoreManagerProvider, accessPointControllerProvider, demoModeControllerProvider, carrierConfigTrackerProvider, featureFlagsProvider, handlerProvider, internetDialogFactoryProvider, dumpManagerProvider);
  }

  public static NetworkControllerImpl newInstance(Context context, Looper bgLooper,
      Executor bgExecutor, SubscriptionManager subscriptionManager, CallbackHandler callbackHandler,
      DeviceProvisionedController deviceProvisionedController,
      BroadcastDispatcher broadcastDispatcher, ConnectivityManager connectivityManager,
      TelephonyManager telephonyManager, TelephonyListenerManager telephonyListenerManager,
      WifiManager wifiManager, NetworkScoreManager networkScoreManager,
      AccessPointControllerImpl accessPointController, DemoModeController demoModeController,
      CarrierConfigTracker carrierConfigTracker, FeatureFlags featureFlags, Handler handler,
      InternetDialogFactory internetDialogFactory, DumpManager dumpManager) {
    return new NetworkControllerImpl(context, bgLooper, bgExecutor, subscriptionManager, callbackHandler, deviceProvisionedController, broadcastDispatcher, connectivityManager, telephonyManager, telephonyListenerManager, wifiManager, networkScoreManager, accessPointController, demoModeController, carrierConfigTracker, featureFlags, handler, internetDialogFactory, dumpManager);
  }
}

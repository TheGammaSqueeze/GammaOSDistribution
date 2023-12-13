package com.android.systemui.statusbar.connectivity;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkScoreManager;
import android.net.wifi.WifiManager;
import android.os.Handler;
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
public final class AccessPointControllerImpl_WifiPickerTrackerFactory_Factory implements Factory<AccessPointControllerImpl.WifiPickerTrackerFactory> {
  private final Provider<Context> contextProvider;

  private final Provider<WifiManager> wifiManagerProvider;

  private final Provider<ConnectivityManager> connectivityManagerProvider;

  private final Provider<NetworkScoreManager> networkScoreManagerProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<Handler> workerHandlerProvider;

  public AccessPointControllerImpl_WifiPickerTrackerFactory_Factory(
      Provider<Context> contextProvider, Provider<WifiManager> wifiManagerProvider,
      Provider<ConnectivityManager> connectivityManagerProvider,
      Provider<NetworkScoreManager> networkScoreManagerProvider,
      Provider<Handler> mainHandlerProvider, Provider<Handler> workerHandlerProvider) {
    this.contextProvider = contextProvider;
    this.wifiManagerProvider = wifiManagerProvider;
    this.connectivityManagerProvider = connectivityManagerProvider;
    this.networkScoreManagerProvider = networkScoreManagerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.workerHandlerProvider = workerHandlerProvider;
  }

  @Override
  public AccessPointControllerImpl.WifiPickerTrackerFactory get() {
    return newInstance(contextProvider.get(), wifiManagerProvider.get(), connectivityManagerProvider.get(), networkScoreManagerProvider.get(), mainHandlerProvider.get(), workerHandlerProvider.get());
  }

  public static AccessPointControllerImpl_WifiPickerTrackerFactory_Factory create(
      Provider<Context> contextProvider, Provider<WifiManager> wifiManagerProvider,
      Provider<ConnectivityManager> connectivityManagerProvider,
      Provider<NetworkScoreManager> networkScoreManagerProvider,
      Provider<Handler> mainHandlerProvider, Provider<Handler> workerHandlerProvider) {
    return new AccessPointControllerImpl_WifiPickerTrackerFactory_Factory(contextProvider, wifiManagerProvider, connectivityManagerProvider, networkScoreManagerProvider, mainHandlerProvider, workerHandlerProvider);
  }

  public static AccessPointControllerImpl.WifiPickerTrackerFactory newInstance(Context context,
      WifiManager wifiManager, ConnectivityManager connectivityManager,
      NetworkScoreManager networkScoreManager, Handler mainHandler, Handler workerHandler) {
    return new AccessPointControllerImpl.WifiPickerTrackerFactory(context, wifiManager, connectivityManager, networkScoreManager, mainHandler, workerHandler);
  }
}

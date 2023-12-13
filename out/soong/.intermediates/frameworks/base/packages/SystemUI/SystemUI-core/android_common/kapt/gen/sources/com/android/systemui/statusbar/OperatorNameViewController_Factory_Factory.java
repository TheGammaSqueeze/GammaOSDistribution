package com.android.systemui.statusbar;

import android.telephony.TelephonyManager;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.plugins.DarkIconDispatcher;
import com.android.systemui.statusbar.connectivity.NetworkController;
import com.android.systemui.tuner.TunerService;
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
public final class OperatorNameViewController_Factory_Factory implements Factory<OperatorNameViewController.Factory> {
  private final Provider<DarkIconDispatcher> darkIconDispatcherProvider;

  private final Provider<NetworkController> networkControllerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<TelephonyManager> telephonyManagerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  public OperatorNameViewController_Factory_Factory(
      Provider<DarkIconDispatcher> darkIconDispatcherProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    this.darkIconDispatcherProvider = darkIconDispatcherProvider;
    this.networkControllerProvider = networkControllerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.telephonyManagerProvider = telephonyManagerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
  }

  @Override
  public OperatorNameViewController.Factory get() {
    return newInstance(darkIconDispatcherProvider.get(), networkControllerProvider.get(), tunerServiceProvider.get(), telephonyManagerProvider.get(), keyguardUpdateMonitorProvider.get());
  }

  public static OperatorNameViewController_Factory_Factory create(
      Provider<DarkIconDispatcher> darkIconDispatcherProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    return new OperatorNameViewController_Factory_Factory(darkIconDispatcherProvider, networkControllerProvider, tunerServiceProvider, telephonyManagerProvider, keyguardUpdateMonitorProvider);
  }

  public static OperatorNameViewController.Factory newInstance(
      DarkIconDispatcher darkIconDispatcher, NetworkController networkController,
      TunerService tunerService, TelephonyManager telephonyManager,
      KeyguardUpdateMonitor keyguardUpdateMonitor) {
    return new OperatorNameViewController.Factory(darkIconDispatcher, networkController, tunerService, telephonyManager, keyguardUpdateMonitor);
  }
}

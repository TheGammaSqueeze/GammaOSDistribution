package com.android.keyguard;

import android.content.Context;
import android.content.res.Resources;
import android.net.wifi.WifiManager;
import android.telephony.TelephonyManager;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.telephony.TelephonyListenerManager;
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
public final class CarrierTextManager_Builder_Factory implements Factory<CarrierTextManager.Builder> {
  private final Provider<Context> contextProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<WifiManager> wifiManagerProvider;

  private final Provider<TelephonyManager> telephonyManagerProvider;

  private final Provider<TelephonyListenerManager> telephonyListenerManagerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  public CarrierTextManager_Builder_Factory(Provider<Context> contextProvider,
      Provider<Resources> resourcesProvider, Provider<WifiManager> wifiManagerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<TelephonyListenerManager> telephonyListenerManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<Executor> mainExecutorProvider, Provider<Executor> bgExecutorProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    this.contextProvider = contextProvider;
    this.resourcesProvider = resourcesProvider;
    this.wifiManagerProvider = wifiManagerProvider;
    this.telephonyManagerProvider = telephonyManagerProvider;
    this.telephonyListenerManagerProvider = telephonyListenerManagerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
  }

  @Override
  public CarrierTextManager.Builder get() {
    return newInstance(contextProvider.get(), resourcesProvider.get(), wifiManagerProvider.get(), telephonyManagerProvider.get(), telephonyListenerManagerProvider.get(), wakefulnessLifecycleProvider.get(), mainExecutorProvider.get(), bgExecutorProvider.get(), keyguardUpdateMonitorProvider.get());
  }

  public static CarrierTextManager_Builder_Factory create(Provider<Context> contextProvider,
      Provider<Resources> resourcesProvider, Provider<WifiManager> wifiManagerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<TelephonyListenerManager> telephonyListenerManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<Executor> mainExecutorProvider, Provider<Executor> bgExecutorProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    return new CarrierTextManager_Builder_Factory(contextProvider, resourcesProvider, wifiManagerProvider, telephonyManagerProvider, telephonyListenerManagerProvider, wakefulnessLifecycleProvider, mainExecutorProvider, bgExecutorProvider, keyguardUpdateMonitorProvider);
  }

  public static CarrierTextManager.Builder newInstance(Context context, Resources resources,
      WifiManager wifiManager, TelephonyManager telephonyManager,
      TelephonyListenerManager telephonyListenerManager, WakefulnessLifecycle wakefulnessLifecycle,
      Executor mainExecutor, Executor bgExecutor, KeyguardUpdateMonitor keyguardUpdateMonitor) {
    return new CarrierTextManager.Builder(context, resources, wifiManager, telephonyManager, telephonyListenerManager, wakefulnessLifecycle, mainExecutor, bgExecutor, keyguardUpdateMonitor);
  }
}

package com.android.systemui.telephony;

import android.telephony.TelephonyManager;
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
public final class TelephonyListenerManager_Factory implements Factory<TelephonyListenerManager> {
  private final Provider<TelephonyManager> telephonyManagerProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<TelephonyCallback> telephonyCallbackProvider;

  public TelephonyListenerManager_Factory(Provider<TelephonyManager> telephonyManagerProvider,
      Provider<Executor> executorProvider, Provider<TelephonyCallback> telephonyCallbackProvider) {
    this.telephonyManagerProvider = telephonyManagerProvider;
    this.executorProvider = executorProvider;
    this.telephonyCallbackProvider = telephonyCallbackProvider;
  }

  @Override
  public TelephonyListenerManager get() {
    return newInstance(telephonyManagerProvider.get(), executorProvider.get(), telephonyCallbackProvider.get());
  }

  public static TelephonyListenerManager_Factory create(
      Provider<TelephonyManager> telephonyManagerProvider, Provider<Executor> executorProvider,
      Provider<TelephonyCallback> telephonyCallbackProvider) {
    return new TelephonyListenerManager_Factory(telephonyManagerProvider, executorProvider, telephonyCallbackProvider);
  }

  public static TelephonyListenerManager newInstance(TelephonyManager telephonyManager,
      Executor executor, Object telephonyCallback) {
    return new TelephonyListenerManager(telephonyManager, executor, (TelephonyCallback) telephonyCallback);
  }
}

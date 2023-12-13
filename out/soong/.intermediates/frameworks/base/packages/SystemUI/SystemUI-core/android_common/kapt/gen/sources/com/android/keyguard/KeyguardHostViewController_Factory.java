package com.android.keyguard;

import android.media.AudioManager;
import android.telephony.TelephonyManager;
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
public final class KeyguardHostViewController_Factory implements Factory<KeyguardHostViewController> {
  private final Provider<KeyguardHostView> viewProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<AudioManager> audioManagerProvider;

  private final Provider<TelephonyManager> telephonyManagerProvider;

  private final Provider<ViewMediatorCallback> viewMediatorCallbackProvider;

  private final Provider<KeyguardSecurityContainerController.Factory> keyguardSecurityContainerControllerFactoryProvider;

  public KeyguardHostViewController_Factory(Provider<KeyguardHostView> viewProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<AudioManager> audioManagerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<ViewMediatorCallback> viewMediatorCallbackProvider,
      Provider<KeyguardSecurityContainerController.Factory> keyguardSecurityContainerControllerFactoryProvider) {
    this.viewProvider = viewProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.audioManagerProvider = audioManagerProvider;
    this.telephonyManagerProvider = telephonyManagerProvider;
    this.viewMediatorCallbackProvider = viewMediatorCallbackProvider;
    this.keyguardSecurityContainerControllerFactoryProvider = keyguardSecurityContainerControllerFactoryProvider;
  }

  @Override
  public KeyguardHostViewController get() {
    return newInstance(viewProvider.get(), keyguardUpdateMonitorProvider.get(), audioManagerProvider.get(), telephonyManagerProvider.get(), viewMediatorCallbackProvider.get(), keyguardSecurityContainerControllerFactoryProvider.get());
  }

  public static KeyguardHostViewController_Factory create(Provider<KeyguardHostView> viewProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<AudioManager> audioManagerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<ViewMediatorCallback> viewMediatorCallbackProvider,
      Provider<KeyguardSecurityContainerController.Factory> keyguardSecurityContainerControllerFactoryProvider) {
    return new KeyguardHostViewController_Factory(viewProvider, keyguardUpdateMonitorProvider, audioManagerProvider, telephonyManagerProvider, viewMediatorCallbackProvider, keyguardSecurityContainerControllerFactoryProvider);
  }

  public static KeyguardHostViewController newInstance(KeyguardHostView view,
      KeyguardUpdateMonitor keyguardUpdateMonitor, AudioManager audioManager,
      TelephonyManager telephonyManager, ViewMediatorCallback viewMediatorCallback,
      Object keyguardSecurityContainerControllerFactory) {
    return new KeyguardHostViewController(view, keyguardUpdateMonitor, audioManager, telephonyManager, viewMediatorCallback, (KeyguardSecurityContainerController.Factory) keyguardSecurityContainerControllerFactory);
  }
}

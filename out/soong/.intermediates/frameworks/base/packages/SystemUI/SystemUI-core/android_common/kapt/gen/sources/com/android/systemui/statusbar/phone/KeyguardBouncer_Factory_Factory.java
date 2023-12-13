package com.android.systemui.statusbar.phone;

import android.content.Context;
import android.os.Handler;
import com.android.keyguard.KeyguardSecurityModel;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.keyguard.ViewMediatorCallback;
import com.android.keyguard.dagger.KeyguardBouncerComponent;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.keyguard.DismissCallbackRegistry;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class KeyguardBouncer_Factory_Factory implements Factory<KeyguardBouncer.Factory> {
  private final Provider<Context> contextProvider;

  private final Provider<ViewMediatorCallback> callbackProvider;

  private final Provider<DismissCallbackRegistry> dismissCallbackRegistryProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<KeyguardSecurityModel> keyguardSecurityModelProvider;

  private final Provider<KeyguardBouncerComponent.Factory> keyguardBouncerComponentFactoryProvider;

  public KeyguardBouncer_Factory_Factory(Provider<Context> contextProvider,
      Provider<ViewMediatorCallback> callbackProvider,
      Provider<DismissCallbackRegistry> dismissCallbackRegistryProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<Handler> handlerProvider,
      Provider<KeyguardSecurityModel> keyguardSecurityModelProvider,
      Provider<KeyguardBouncerComponent.Factory> keyguardBouncerComponentFactoryProvider) {
    this.contextProvider = contextProvider;
    this.callbackProvider = callbackProvider;
    this.dismissCallbackRegistryProvider = dismissCallbackRegistryProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.handlerProvider = handlerProvider;
    this.keyguardSecurityModelProvider = keyguardSecurityModelProvider;
    this.keyguardBouncerComponentFactoryProvider = keyguardBouncerComponentFactoryProvider;
  }

  @Override
  public KeyguardBouncer.Factory get() {
    return newInstance(contextProvider.get(), callbackProvider.get(), dismissCallbackRegistryProvider.get(), falsingCollectorProvider.get(), keyguardStateControllerProvider.get(), keyguardUpdateMonitorProvider.get(), keyguardBypassControllerProvider.get(), handlerProvider.get(), keyguardSecurityModelProvider.get(), keyguardBouncerComponentFactoryProvider.get());
  }

  public static KeyguardBouncer_Factory_Factory create(Provider<Context> contextProvider,
      Provider<ViewMediatorCallback> callbackProvider,
      Provider<DismissCallbackRegistry> dismissCallbackRegistryProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<Handler> handlerProvider,
      Provider<KeyguardSecurityModel> keyguardSecurityModelProvider,
      Provider<KeyguardBouncerComponent.Factory> keyguardBouncerComponentFactoryProvider) {
    return new KeyguardBouncer_Factory_Factory(contextProvider, callbackProvider, dismissCallbackRegistryProvider, falsingCollectorProvider, keyguardStateControllerProvider, keyguardUpdateMonitorProvider, keyguardBypassControllerProvider, handlerProvider, keyguardSecurityModelProvider, keyguardBouncerComponentFactoryProvider);
  }

  public static KeyguardBouncer.Factory newInstance(Context context, ViewMediatorCallback callback,
      DismissCallbackRegistry dismissCallbackRegistry, FalsingCollector falsingCollector,
      KeyguardStateController keyguardStateController, KeyguardUpdateMonitor keyguardUpdateMonitor,
      KeyguardBypassController keyguardBypassController, Handler handler,
      KeyguardSecurityModel keyguardSecurityModel,
      KeyguardBouncerComponent.Factory keyguardBouncerComponentFactory) {
    return new KeyguardBouncer.Factory(context, callback, dismissCallbackRegistry, falsingCollector, keyguardStateController, keyguardUpdateMonitor, keyguardBypassController, handler, keyguardSecurityModel, keyguardBouncerComponentFactory);
  }
}

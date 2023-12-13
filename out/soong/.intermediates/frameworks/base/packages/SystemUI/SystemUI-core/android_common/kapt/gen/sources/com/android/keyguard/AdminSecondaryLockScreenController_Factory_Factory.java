package com.android.keyguard;

import android.content.Context;
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
public final class AdminSecondaryLockScreenController_Factory_Factory implements Factory<AdminSecondaryLockScreenController.Factory> {
  private final Provider<Context> contextProvider;

  private final Provider<KeyguardSecurityContainer> parentProvider;

  private final Provider<KeyguardUpdateMonitor> updateMonitorProvider;

  private final Provider<Handler> handlerProvider;

  public AdminSecondaryLockScreenController_Factory_Factory(Provider<Context> contextProvider,
      Provider<KeyguardSecurityContainer> parentProvider,
      Provider<KeyguardUpdateMonitor> updateMonitorProvider, Provider<Handler> handlerProvider) {
    this.contextProvider = contextProvider;
    this.parentProvider = parentProvider;
    this.updateMonitorProvider = updateMonitorProvider;
    this.handlerProvider = handlerProvider;
  }

  @Override
  public AdminSecondaryLockScreenController.Factory get() {
    return newInstance(contextProvider.get(), parentProvider.get(), updateMonitorProvider.get(), handlerProvider.get());
  }

  public static AdminSecondaryLockScreenController_Factory_Factory create(
      Provider<Context> contextProvider, Provider<KeyguardSecurityContainer> parentProvider,
      Provider<KeyguardUpdateMonitor> updateMonitorProvider, Provider<Handler> handlerProvider) {
    return new AdminSecondaryLockScreenController_Factory_Factory(contextProvider, parentProvider, updateMonitorProvider, handlerProvider);
  }

  public static AdminSecondaryLockScreenController.Factory newInstance(Context context,
      KeyguardSecurityContainer parent, KeyguardUpdateMonitor updateMonitor, Handler handler) {
    return new AdminSecondaryLockScreenController.Factory(context, parent, updateMonitor, handler);
  }
}

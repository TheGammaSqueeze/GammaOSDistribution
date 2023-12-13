package com.android.systemui.doze;

import com.android.keyguard.KeyguardUpdateMonitor;
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
public final class DozeAuthRemover_Factory implements Factory<DozeAuthRemover> {
  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  public DozeAuthRemover_Factory(Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
  }

  @Override
  public DozeAuthRemover get() {
    return newInstance(keyguardUpdateMonitorProvider.get());
  }

  public static DozeAuthRemover_Factory create(
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    return new DozeAuthRemover_Factory(keyguardUpdateMonitorProvider);
  }

  public static DozeAuthRemover newInstance(KeyguardUpdateMonitor keyguardUpdateMonitor) {
    return new DozeAuthRemover(keyguardUpdateMonitor);
  }
}

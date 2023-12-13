package com.android.keyguard;

import android.content.res.Resources;
import com.android.internal.widget.LockPatternUtils;
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
public final class KeyguardSecurityModel_Factory implements Factory<KeyguardSecurityModel> {
  private final Provider<Resources> resourcesProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  public KeyguardSecurityModel_Factory(Provider<Resources> resourcesProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    this.resourcesProvider = resourcesProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
  }

  @Override
  public KeyguardSecurityModel get() {
    return newInstance(resourcesProvider.get(), lockPatternUtilsProvider.get(), keyguardUpdateMonitorProvider.get());
  }

  public static KeyguardSecurityModel_Factory create(Provider<Resources> resourcesProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    return new KeyguardSecurityModel_Factory(resourcesProvider, lockPatternUtilsProvider, keyguardUpdateMonitorProvider);
  }

  public static KeyguardSecurityModel newInstance(Resources resources,
      LockPatternUtils lockPatternUtils, KeyguardUpdateMonitor keyguardUpdateMonitor) {
    return new KeyguardSecurityModel(resources, lockPatternUtils, keyguardUpdateMonitor);
  }
}

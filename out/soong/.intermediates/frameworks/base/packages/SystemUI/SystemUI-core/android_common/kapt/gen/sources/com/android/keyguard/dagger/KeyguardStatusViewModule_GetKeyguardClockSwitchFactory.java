package com.android.keyguard.dagger;

import com.android.keyguard.KeyguardClockSwitch;
import com.android.keyguard.KeyguardStatusView;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class KeyguardStatusViewModule_GetKeyguardClockSwitchFactory implements Factory<KeyguardClockSwitch> {
  private final Provider<KeyguardStatusView> keyguardPresentationProvider;

  public KeyguardStatusViewModule_GetKeyguardClockSwitchFactory(
      Provider<KeyguardStatusView> keyguardPresentationProvider) {
    this.keyguardPresentationProvider = keyguardPresentationProvider;
  }

  @Override
  public KeyguardClockSwitch get() {
    return getKeyguardClockSwitch(keyguardPresentationProvider.get());
  }

  public static KeyguardStatusViewModule_GetKeyguardClockSwitchFactory create(
      Provider<KeyguardStatusView> keyguardPresentationProvider) {
    return new KeyguardStatusViewModule_GetKeyguardClockSwitchFactory(keyguardPresentationProvider);
  }

  public static KeyguardClockSwitch getKeyguardClockSwitch(
      KeyguardStatusView keyguardPresentation) {
    return Preconditions.checkNotNullFromProvides(KeyguardStatusViewModule.getKeyguardClockSwitch(keyguardPresentation));
  }
}

package com.android.keyguard.dagger;

import com.android.keyguard.KeyguardClockSwitch;
import com.android.keyguard.KeyguardSliceView;
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
public final class KeyguardStatusViewModule_GetKeyguardSliceViewFactory implements Factory<KeyguardSliceView> {
  private final Provider<KeyguardClockSwitch> keyguardClockSwitchProvider;

  public KeyguardStatusViewModule_GetKeyguardSliceViewFactory(
      Provider<KeyguardClockSwitch> keyguardClockSwitchProvider) {
    this.keyguardClockSwitchProvider = keyguardClockSwitchProvider;
  }

  @Override
  public KeyguardSliceView get() {
    return getKeyguardSliceView(keyguardClockSwitchProvider.get());
  }

  public static KeyguardStatusViewModule_GetKeyguardSliceViewFactory create(
      Provider<KeyguardClockSwitch> keyguardClockSwitchProvider) {
    return new KeyguardStatusViewModule_GetKeyguardSliceViewFactory(keyguardClockSwitchProvider);
  }

  public static KeyguardSliceView getKeyguardSliceView(KeyguardClockSwitch keyguardClockSwitch) {
    return Preconditions.checkNotNullFromProvides(KeyguardStatusViewModule.getKeyguardSliceView(keyguardClockSwitch));
  }
}

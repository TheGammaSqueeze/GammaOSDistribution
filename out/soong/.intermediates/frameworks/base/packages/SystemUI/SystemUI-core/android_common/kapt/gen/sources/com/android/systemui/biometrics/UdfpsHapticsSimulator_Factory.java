package com.android.systemui.biometrics;

import android.os.Vibrator;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.statusbar.commandline.CommandRegistry;
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
public final class UdfpsHapticsSimulator_Factory implements Factory<UdfpsHapticsSimulator> {
  private final Provider<CommandRegistry> commandRegistryProvider;

  private final Provider<Vibrator> vibratorProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  public UdfpsHapticsSimulator_Factory(Provider<CommandRegistry> commandRegistryProvider,
      Provider<Vibrator> vibratorProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    this.commandRegistryProvider = commandRegistryProvider;
    this.vibratorProvider = vibratorProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
  }

  @Override
  public UdfpsHapticsSimulator get() {
    return newInstance(commandRegistryProvider.get(), vibratorProvider.get(), keyguardUpdateMonitorProvider.get());
  }

  public static UdfpsHapticsSimulator_Factory create(
      Provider<CommandRegistry> commandRegistryProvider, Provider<Vibrator> vibratorProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    return new UdfpsHapticsSimulator_Factory(commandRegistryProvider, vibratorProvider, keyguardUpdateMonitorProvider);
  }

  public static UdfpsHapticsSimulator newInstance(CommandRegistry commandRegistry,
      Vibrator vibrator, KeyguardUpdateMonitor keyguardUpdateMonitor) {
    return new UdfpsHapticsSimulator(commandRegistry, vibrator, keyguardUpdateMonitor);
  }
}

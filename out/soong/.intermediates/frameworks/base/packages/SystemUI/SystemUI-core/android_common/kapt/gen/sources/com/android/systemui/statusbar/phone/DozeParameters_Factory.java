package com.android.systemui.statusbar.phone;

import android.content.res.Resources;
import android.hardware.display.AmbientDisplayConfiguration;
import android.os.PowerManager;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.doze.AlwaysOnDisplayPolicy;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.tuner.TunerService;
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
public final class DozeParameters_Factory implements Factory<DozeParameters> {
  private final Provider<Resources> resourcesProvider;

  private final Provider<AmbientDisplayConfiguration> ambientDisplayConfigurationProvider;

  private final Provider<AlwaysOnDisplayPolicy> alwaysOnDisplayPolicyProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  public DozeParameters_Factory(Provider<Resources> resourcesProvider,
      Provider<AmbientDisplayConfiguration> ambientDisplayConfigurationProvider,
      Provider<AlwaysOnDisplayPolicy> alwaysOnDisplayPolicyProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    this.resourcesProvider = resourcesProvider;
    this.ambientDisplayConfigurationProvider = ambientDisplayConfigurationProvider;
    this.alwaysOnDisplayPolicyProvider = alwaysOnDisplayPolicyProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
  }

  @Override
  public DozeParameters get() {
    return newInstance(resourcesProvider.get(), ambientDisplayConfigurationProvider.get(), alwaysOnDisplayPolicyProvider.get(), powerManagerProvider.get(), batteryControllerProvider.get(), tunerServiceProvider.get(), dumpManagerProvider.get(), featureFlagsProvider.get(), unlockedScreenOffAnimationControllerProvider.get(), keyguardUpdateMonitorProvider.get(), configurationControllerProvider.get(), statusBarStateControllerProvider.get());
  }

  public static DozeParameters_Factory create(Provider<Resources> resourcesProvider,
      Provider<AmbientDisplayConfiguration> ambientDisplayConfigurationProvider,
      Provider<AlwaysOnDisplayPolicy> alwaysOnDisplayPolicyProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    return new DozeParameters_Factory(resourcesProvider, ambientDisplayConfigurationProvider, alwaysOnDisplayPolicyProvider, powerManagerProvider, batteryControllerProvider, tunerServiceProvider, dumpManagerProvider, featureFlagsProvider, unlockedScreenOffAnimationControllerProvider, keyguardUpdateMonitorProvider, configurationControllerProvider, statusBarStateControllerProvider);
  }

  public static DozeParameters newInstance(Resources resources,
      AmbientDisplayConfiguration ambientDisplayConfiguration,
      AlwaysOnDisplayPolicy alwaysOnDisplayPolicy, PowerManager powerManager,
      BatteryController batteryController, TunerService tunerService, DumpManager dumpManager,
      FeatureFlags featureFlags,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController,
      KeyguardUpdateMonitor keyguardUpdateMonitor, ConfigurationController configurationController,
      StatusBarStateController statusBarStateController) {
    return new DozeParameters(resources, ambientDisplayConfiguration, alwaysOnDisplayPolicy, powerManager, batteryController, tunerService, dumpManager, featureFlags, unlockedScreenOffAnimationController, keyguardUpdateMonitor, configurationController, statusBarStateController);
  }
}

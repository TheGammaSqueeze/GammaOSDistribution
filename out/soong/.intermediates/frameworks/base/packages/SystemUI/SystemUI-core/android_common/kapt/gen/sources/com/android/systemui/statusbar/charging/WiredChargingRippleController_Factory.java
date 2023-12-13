package com.android.systemui.statusbar.charging;

import android.content.Context;
import android.view.WindowManager;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.commandline.CommandRegistry;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.time.SystemClock;
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
public final class WiredChargingRippleController_Factory implements Factory<WiredChargingRippleController> {
  private final Provider<CommandRegistry> commandRegistryProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<Context> contextProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<SystemClock> systemClockProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  public WiredChargingRippleController_Factory(Provider<CommandRegistry> commandRegistryProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<Context> contextProvider,
      Provider<WindowManager> windowManagerProvider, Provider<SystemClock> systemClockProvider,
      Provider<UiEventLogger> uiEventLoggerProvider) {
    this.commandRegistryProvider = commandRegistryProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.contextProvider = contextProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.systemClockProvider = systemClockProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
  }

  @Override
  public WiredChargingRippleController get() {
    return newInstance(commandRegistryProvider.get(), batteryControllerProvider.get(), configurationControllerProvider.get(), featureFlagsProvider.get(), contextProvider.get(), windowManagerProvider.get(), systemClockProvider.get(), uiEventLoggerProvider.get());
  }

  public static WiredChargingRippleController_Factory create(
      Provider<CommandRegistry> commandRegistryProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<Context> contextProvider,
      Provider<WindowManager> windowManagerProvider, Provider<SystemClock> systemClockProvider,
      Provider<UiEventLogger> uiEventLoggerProvider) {
    return new WiredChargingRippleController_Factory(commandRegistryProvider, batteryControllerProvider, configurationControllerProvider, featureFlagsProvider, contextProvider, windowManagerProvider, systemClockProvider, uiEventLoggerProvider);
  }

  public static WiredChargingRippleController newInstance(CommandRegistry commandRegistry,
      BatteryController batteryController, ConfigurationController configurationController,
      FeatureFlags featureFlags, Context context, WindowManager windowManager,
      SystemClock systemClock, UiEventLogger uiEventLogger) {
    return new WiredChargingRippleController(commandRegistry, batteryController, configurationController, featureFlags, context, windowManager, systemClock, uiEventLogger);
  }
}

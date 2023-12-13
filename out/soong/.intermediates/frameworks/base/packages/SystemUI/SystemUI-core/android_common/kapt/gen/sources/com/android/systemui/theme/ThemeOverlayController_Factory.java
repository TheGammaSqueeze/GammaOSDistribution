package com.android.systemui.theme;

import android.app.WallpaperManager;
import android.content.Context;
import android.os.Handler;
import android.os.UserManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.util.settings.SecureSettings;
import com.android.systemui.util.settings.SystemSettings;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
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
public final class ThemeOverlayController_Factory implements Factory<ThemeOverlayController> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Handler> bgHandlerProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<ThemeOverlayApplier> themeOverlayApplierProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<WallpaperManager> wallpaperManagerProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<SystemSettings> systemSettingsProvider;

  public ThemeOverlayController_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> bgHandlerProvider, Provider<Executor> mainExecutorProvider,
      Provider<Executor> bgExecutorProvider,
      Provider<ThemeOverlayApplier> themeOverlayApplierProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<WallpaperManager> wallpaperManagerProvider,
      Provider<UserManager> userManagerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<UserTracker> userTrackerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SystemSettings> systemSettingsProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.bgHandlerProvider = bgHandlerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.themeOverlayApplierProvider = themeOverlayApplierProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.wallpaperManagerProvider = wallpaperManagerProvider;
    this.userManagerProvider = userManagerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.systemSettingsProvider = systemSettingsProvider;
  }

  @Override
  public ThemeOverlayController get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get(), bgHandlerProvider.get(), mainExecutorProvider.get(), bgExecutorProvider.get(), themeOverlayApplierProvider.get(), secureSettingsProvider.get(), wallpaperManagerProvider.get(), userManagerProvider.get(), deviceProvisionedControllerProvider.get(), userTrackerProvider.get(), dumpManagerProvider.get(), featureFlagsProvider.get(), wakefulnessLifecycleProvider.get(), configurationControllerProvider.get(), systemSettingsProvider.get());
  }

  public static ThemeOverlayController_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Handler> bgHandlerProvider, Provider<Executor> mainExecutorProvider,
      Provider<Executor> bgExecutorProvider,
      Provider<ThemeOverlayApplier> themeOverlayApplierProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<WallpaperManager> wallpaperManagerProvider,
      Provider<UserManager> userManagerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<UserTracker> userTrackerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SystemSettings> systemSettingsProvider) {
    return new ThemeOverlayController_Factory(contextProvider, broadcastDispatcherProvider, bgHandlerProvider, mainExecutorProvider, bgExecutorProvider, themeOverlayApplierProvider, secureSettingsProvider, wallpaperManagerProvider, userManagerProvider, deviceProvisionedControllerProvider, userTrackerProvider, dumpManagerProvider, featureFlagsProvider, wakefulnessLifecycleProvider, configurationControllerProvider, systemSettingsProvider);
  }

  public static ThemeOverlayController newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher, Handler bgHandler, Executor mainExecutor,
      Executor bgExecutor, ThemeOverlayApplier themeOverlayApplier, SecureSettings secureSettings,
      WallpaperManager wallpaperManager, UserManager userManager,
      DeviceProvisionedController deviceProvisionedController, UserTracker userTracker,
      DumpManager dumpManager, FeatureFlags featureFlags, WakefulnessLifecycle wakefulnessLifecycle,
      ConfigurationController configurationController, SystemSettings systemSettings) {
    return new ThemeOverlayController(context, broadcastDispatcher, bgHandler, mainExecutor, bgExecutor, themeOverlayApplier, secureSettings, wallpaperManager, userManager, deviceProvisionedController, userTracker, dumpManager, featureFlags, wakefulnessLifecycle, configurationController, systemSettings);
  }
}

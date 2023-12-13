package com.android.systemui.statusbar.policy;

import android.os.Handler;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.settings.GlobalSettings;
import com.android.systemui.util.settings.SecureSettings;
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
public final class DeviceProvisionedControllerImpl_Factory implements Factory<DeviceProvisionedControllerImpl> {
  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<GlobalSettings> globalSettingsProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<Handler> backgroundHandlerProvider;

  private final Provider<Executor> mainExecutorProvider;

  public DeviceProvisionedControllerImpl_Factory(Provider<SecureSettings> secureSettingsProvider,
      Provider<GlobalSettings> globalSettingsProvider, Provider<UserTracker> userTrackerProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<Handler> backgroundHandlerProvider,
      Provider<Executor> mainExecutorProvider) {
    this.secureSettingsProvider = secureSettingsProvider;
    this.globalSettingsProvider = globalSettingsProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.backgroundHandlerProvider = backgroundHandlerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public DeviceProvisionedControllerImpl get() {
    return newInstance(secureSettingsProvider.get(), globalSettingsProvider.get(), userTrackerProvider.get(), dumpManagerProvider.get(), backgroundHandlerProvider.get(), mainExecutorProvider.get());
  }

  public static DeviceProvisionedControllerImpl_Factory create(
      Provider<SecureSettings> secureSettingsProvider,
      Provider<GlobalSettings> globalSettingsProvider, Provider<UserTracker> userTrackerProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<Handler> backgroundHandlerProvider,
      Provider<Executor> mainExecutorProvider) {
    return new DeviceProvisionedControllerImpl_Factory(secureSettingsProvider, globalSettingsProvider, userTrackerProvider, dumpManagerProvider, backgroundHandlerProvider, mainExecutorProvider);
  }

  public static DeviceProvisionedControllerImpl newInstance(SecureSettings secureSettings,
      GlobalSettings globalSettings, UserTracker userTracker, DumpManager dumpManager,
      Handler backgroundHandler, Executor mainExecutor) {
    return new DeviceProvisionedControllerImpl(secureSettings, globalSettings, userTracker, dumpManager, backgroundHandler, mainExecutor);
  }
}

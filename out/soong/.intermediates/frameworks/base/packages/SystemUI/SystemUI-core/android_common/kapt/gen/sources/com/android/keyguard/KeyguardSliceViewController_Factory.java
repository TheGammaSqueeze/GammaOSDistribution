package com.android.keyguard;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.ActivityStarter;
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
public final class KeyguardSliceViewController_Factory implements Factory<KeyguardSliceViewController> {
  private final Provider<KeyguardSliceView> keyguardSliceViewProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public KeyguardSliceViewController_Factory(Provider<KeyguardSliceView> keyguardSliceViewProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<DumpManager> dumpManagerProvider) {
    this.keyguardSliceViewProvider = keyguardSliceViewProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public KeyguardSliceViewController get() {
    return newInstance(keyguardSliceViewProvider.get(), activityStarterProvider.get(), configurationControllerProvider.get(), tunerServiceProvider.get(), dumpManagerProvider.get());
  }

  public static KeyguardSliceViewController_Factory create(
      Provider<KeyguardSliceView> keyguardSliceViewProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<DumpManager> dumpManagerProvider) {
    return new KeyguardSliceViewController_Factory(keyguardSliceViewProvider, activityStarterProvider, configurationControllerProvider, tunerServiceProvider, dumpManagerProvider);
  }

  public static KeyguardSliceViewController newInstance(KeyguardSliceView keyguardSliceView,
      ActivityStarter activityStarter, ConfigurationController configurationController,
      TunerService tunerService, DumpManager dumpManager) {
    return new KeyguardSliceViewController(keyguardSliceView, activityStarter, configurationController, tunerService, dumpManager);
  }
}
